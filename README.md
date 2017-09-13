# proof-of-concept: dyld image loading performance

### Introduction

As a Private Framework developer I distribute Frameworks as source and often develop dynamic Frameworks that have dependencies on other dynamic Frameworks, trying to have the code as modularized as possible. This means that each application that consumes the Dynamic Frameworks will notice an increase of the application loading time, since at the end, it will be importing a load of dynamic Frameworks.

After attending [WWDC 2016 Session 406 Optimizing App Startup Time](https://developer.apple.com/videos/play/wwdc2016/406/) I realized there wasn't much to do in terms of improving app loading performance unless I decided to distribute the dynamic Frameworks as source and taking advantage of ignoring the directive __use_frameworks!__(which would compile the frameworks as static libraries), stop modularizing the Dynamic Frameworks and embed all the source in consuming applications, or start distributing them as __static Libraries__.

The best option, in this scenario, was to distribute the binaries as __static Libraries__ since I wanted to keep consumers from accessing the source. How could I make sure that the binaries weren't added more than once when using extensions or other targets like widgets?

### Original issue

dyld takes too long to load frameworks which makes applications slow at startup.

[rdar://22920190](http://www.openradar.me/radar?id=6332266275930112)

### Solution

The solution to the problem was __simple__ and required version upgrades on each one of the modularized Dynamic Frameworks. 

- I had to convert all the Dynamic Frameworks to static Libraries, the only change I had to make was changing `MACH_O_TYPE = staticlib` in the build settings of the Framework target. Also there are other changes that one might need to make since static Libraries don't have their own bundle, they share the bundle with the consuming application unless you provide a bundle with your resources. Make sure you handle your resources properly when converting from Dynamic Framework to Static Library or you might see missing .xib, images, storyboards, etc... Not always is as straight forward as changing the `MACH_O_TYPE`.
- I had to create a __Core Shared Dynamic Framework__ at the consuming Application level that will consume each of the new static libraries that need to be shared across targets. If you have a consuming Application that uses other targets like today widgets, watch app, etc... you will need to create a __Core Shared Dynamic Framework__ that consumes each of the shared Static Libraries. Why? Well the question is simple: If each target was to consume each shared static library directly you would have duplicate static libraries in your final Application executable. We want to decrease loading time, but we don't want to increase __App size__! It wouldn't be good to trade a faster loading application for a +100MB Application that no one would like to download.

### Proof Of Concept

This is an application that proves static libraries load faster than dynamic libraries on iOS. We will post pre-main loading times, showing how much faster is to load the same static libraries through the core dynamic library instead of loading them as dynamic libraries. In order to pull the times we used the __environment variable__ `DYLD_PRINT_STATISTICS`. The consuming static and dynamic libraries are built with a script that generates classes with code and different prefixes. 
This repository contains a Podfile that points to the static and dynamic libraries which are part of this repository. The libraries are distributed as binaries, half of them static, the other half dynamic. Once the Application is installed and executed, the pre-main loading times will be printed in the console.

Here are the pre-main loading times of __5 static/dynamic libraries__ using an Iphone 7Plus.
#### Dynamic
```
Total pre-main time: 279.60 milliseconds (100.0%)
dylib loading time: 260.86 milliseconds (93.2%)
rebase/binding time:   2.64 milliseconds (0.9%)
ObjC setup time:   6.67 milliseconds (2.3%)
initializer time:   9.34 milliseconds (3.3%)
slowest intializers :
libSystem.B.dylib :   2.76 milliseconds (0.9%)
```
#### Static
```
Total pre-main time:  57.18 milliseconds (100.0%)
dylib loading time:  34.93 milliseconds (61.0%)
rebase/binding time:   3.68 milliseconds (6.4%)
ObjC setup time:   9.34 milliseconds (16.3%)
initializer time:   9.16 milliseconds (16.0%)
slowest intializers :
libSystem.B.dylib :   2.51 milliseconds (4.3%)
libBacktraceRecording.dylib :   5.05 milliseconds (8.8%)
```
Loading the app with the 6 static Libraries + the Core is almost __5 times__ faster to load than the app with 6 dynamic libraries + the Core.
The more Frameworks we add, the higher the difference will be.

__NOTE:__ It is important to clean the workspace and gather the metrics of launch with a real device on the first launch.

### Application Size

I am surprised, in a good way, about the results of the application size. I was expecting before building this proof of concept with an extension that we would see the same size for the binary with dynamic frameworks and the one with static frameworks.

It was a total surprise to me to see that the application with static libraries is only __722kb__, and the one with dynamic libraries is __1.6MB__.

Not only we got to improve the loading time of the application, we also got to shrink the size of the application by half.

__NOTE:__ You can check the size of the binaries by building it yourself or by checking the binaries inside __/App Executables/__ folder.
