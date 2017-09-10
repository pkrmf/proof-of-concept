//
//  DummyFrameworkFourProtocols.h
//  DummyFrameworkFour
//
//  Created by Marc Terns on 09/10/2017.
//  Copyright © 2017 com.ternsdevelopment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol DummyFrameworkFourInteractorOutputProtocol;
@protocol DummyFrameworkFourInteractorInputProtocol;
@protocol DummyFrameworkFourViewProtocol;
@protocol DummyFrameworkFourPresenterProtocol;
@protocol DummyFrameworkFourLocalDataManagerInputProtocol;
@protocol DummyFrameworkFourAPIDataManagerInputProtocol;

@class DummyFrameworkFourWireFrame;

// Defines the public interface that something else can use to drive the user interface
@protocol DummyFrameworkFourViewProtocol
@required
@property (nonatomic, strong) id <DummyFrameworkFourPresenterProtocol> presenter;
/**
 * Add here your methods for communication PRESENTER -> VIEWCONTROLLER
 */
@end

@protocol DummyFrameworkFourWireFrameProtocol
@required
+ (void)presentDummyFrameworkFourModuleFrom:(id)fromView;
/**
 * Add here your methods for communication PRESENTER -> WIREFRAME
 */
@end

@protocol DummyFrameworkFourPresenterProtocol
@required
@property (nonatomic, weak) id <DummyFrameworkFourViewProtocol> view;
@property (nonatomic, strong) id <DummyFrameworkFourInteractorInputProtocol> interactor;
@property (nonatomic, strong) id <DummyFrameworkFourWireFrameProtocol> wireFrame;
/**
 * Add here your methods for communication VIEWCONTROLLER -> PRESENTER
 */
@end

@protocol DummyFrameworkFourInteractorOutputProtocol
/**
 * Add here your methods for communication INTERACTOR -> PRESENTER
 */
@end

@protocol DummyFrameworkFourInteractorInputProtocol
@required
@property (nonatomic, weak) id <DummyFrameworkFourInteractorOutputProtocol> presenter;
@property (nonatomic, strong) id <DummyFrameworkFourAPIDataManagerInputProtocol> APIDataManager;
@property (nonatomic, strong) id <DummyFrameworkFourLocalDataManagerInputProtocol> localDataManager;
/**
 * Add here your methods for communication PRESENTER -> INTERACTOR
 */
@end


@protocol DummyFrameworkFourDataManagerInputProtocol
/**
 * Add here your methods for communication INTERACTOR -> DATAMANAGER
 */
@end

@protocol DummyFrameworkFourAPIDataManagerInputProtocol <DummyFrameworkFourDataManagerInputProtocol>
/**
 * Add here your methods for communication INTERACTOR -> APIDATAMANAGER
 */
@end

@protocol DummyFrameworkFourLocalDataManagerInputProtocol <DummyFrameworkFourDataManagerInputProtocol>
/**
 * Add here your methods for communication INTERACTOR -> LOCLDATAMANAGER
 */
@end
