# Uncomment the next line to define a global platform for your project
# platform :ios, '9.0'
use_frameworks!
source 'https://github.com/pkrmf/cocoapods-private-repo.git'

def statics
    pod 'DummyFrameworkTwoStatic'
    pod 'DummyFrameworkOneStatic'
    pod 'DummyFrameworkThreeStatic'
    pod 'DummyFrameworkFourStatic'
    pod 'DummyFrameworkFiveStatic'
    pod 'DummyFrameworkSixStatic'
end

def dynamics
    pod 'DummyFrameworkTwoDynamic'
    pod 'DummyFrameworkOneDynamic'
    pod 'DummyFrameworkThreeDynamic'
    pod 'DummyFrameworkFourDynamic'
    pod 'DummyFrameworkFiveDynamic'
    pod 'DummyFrameworkSixDynamic'
end

target 'ProofOfConcept' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
  
  # ProofOfConcept is consuming the core manually linking the binary from the project settings
  # Pods for ProofOfConcept
  target 'ProofOfConceptWidget' do
      
  end
end



target 'Core' do
    #dynamics
    statics
end
