# proof-of-concept: Dyld image loading performance

### Introduction

As a Private Framework developer I distribute my Frameworks as source and often develop Dynamic Frameworks that have dependencies on other Dynamic Frameworks, trying to have my code as modularized as possible. This means that each application that consumes the Dynamic Frameworks will notice and increase of the application loading time, since at the end, it will be importing a load of my Dynamic Frameworks.

After attending [WWDC 2016 Session 406 Optimizing App Startup Time](https://developer.apple.com/videos/play/wwdc2016/406/) I realized there wasn't much to do in terms of improving app loading performance unless I decided to distribute the dynamic Frameworks as source instead of as source and taking advantage of ignoring  the directive __use_frameworks!__(which would compile the frameworks as static libraries), stop modularizing the Dynamic Frameworks, or start distributing them as __static Libraries__.

The best option, in my scenario, was to distribute the binaries as __static Libraries__, but, how could I make sure that my binaries weren't added more than once when using extensions or other targets like widgets?

### Original issue

__tl;dr:__ _dyld takes too long to load frameworks, which makes apps slow to open_

[rdar://22920190](http://www.openradar.me/radar?id=6332266275930112)

### Solution

The solution to the problem was __simple__ and required version upgrades on each one of my Dynamic Frameworks. 

- I had to convert all the Dynamic Frameworks to static Libraries, the only change I had to make was `MACH_O_TYPE = staticlib` in the build settings of my target. Also there are other changes that one might need to make since static Libraries don't have their own bundle, they share the bundle with the consuming application unless you provide a bundle with your resources. Make sure you handle your resources properly when converting from Dynamic Framework to Static Library or you might see missing .xib, images, storyboards, etc...
- I had to create a __Core Shared Dynamic Framework__ at the consuming Application level that will consume each of the new static libraries that need to be shared across targets. If you have a consuming Application that uses other targets like today widgets, watch app, etc... you will need to create a __Core Shared Dynamic Framework__ that consumes each of the shared Static Libraries. Why? Well the question is simple: If each target was to consume each shared static library directly you would have duplicate static libraries in your final Application executable. We want to decrease loading time, but we don't want to increase __App size__! It wouldn't be good to trade a faster loading application for a +100MB Application that no one would like to download.

### Proof Of Concept

This is an application that proves static libraries load faster than dynamic libraries on iOS. We will post pre-main loading times, showing how much faster is to load the same static libraries through the core dynamic library instead of loading them as dynamic libraries. In order to pull the times we used the __environment variable__ `DYLD_PRINT_STATISTICS`.
