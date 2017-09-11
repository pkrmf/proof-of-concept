//
//  DummyFrameworkFiveProtocols.h
//  DummyFrameworkFive
//
//  Created by Marc Terns on 09/10/2017.
//  Copyright © 2017 com.ternsdevelopment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol DummyFrameworkFiveInteractorOutputProtocol;
@protocol DummyFrameworkFiveInteractorInputProtocol;
@protocol DummyFrameworkFiveViewProtocol;
@protocol DummyFrameworkFivePresenterProtocol;
@protocol DummyFrameworkFiveLocalDataManagerInputProtocol;
@protocol DummyFrameworkFiveAPIDataManagerInputProtocol;

@class DummyFrameworkFiveWireFrame;

// Defines the public interface that something else can use to drive the user interface
@protocol DummyFrameworkFiveViewProtocol
@required
@property (nonatomic, strong) id <DummyFrameworkFivePresenterProtocol> presenter;
/**
 * Add here your methods for communication PRESENTER -> VIEWCONTROLLER
 */
@end

@protocol DummyFrameworkFiveWireFrameProtocol
@required
+ (void)presentDummyFrameworkFiveModuleFrom:(id)fromView;
/**
 * Add here your methods for communication PRESENTER -> WIREFRAME
 */
@end

@protocol DummyFrameworkFivePresenterProtocol
@required
@property (nonatomic, weak) id <DummyFrameworkFiveViewProtocol> view;
@property (nonatomic, strong) id <DummyFrameworkFiveInteractorInputProtocol> interactor;
@property (nonatomic, strong) id <DummyFrameworkFiveWireFrameProtocol> wireFrame;
/**
 * Add here your methods for communication VIEWCONTROLLER -> PRESENTER
 */
@end

@protocol DummyFrameworkFiveInteractorOutputProtocol
/**
 * Add here your methods for communication INTERACTOR -> PRESENTER
 */
@end

@protocol DummyFrameworkFiveInteractorInputProtocol
@required
@property (nonatomic, weak) id <DummyFrameworkFiveInteractorOutputProtocol> presenter;
@property (nonatomic, strong) id <DummyFrameworkFiveAPIDataManagerInputProtocol> APIDataManager;
@property (nonatomic, strong) id <DummyFrameworkFiveLocalDataManagerInputProtocol> localDataManager;
/**
 * Add here your methods for communication PRESENTER -> INTERACTOR
 */
@end


@protocol DummyFrameworkFiveDataManagerInputProtocol
/**
 * Add here your methods for communication INTERACTOR -> DATAMANAGER
 */
@end

@protocol DummyFrameworkFiveAPIDataManagerInputProtocol <DummyFrameworkFiveDataManagerInputProtocol>
/**
 * Add here your methods for communication INTERACTOR -> APIDATAMANAGER
 */
@end

@protocol DummyFrameworkFiveLocalDataManagerInputProtocol <DummyFrameworkFiveDataManagerInputProtocol>
/**
 * Add here your methods for communication INTERACTOR -> LOCLDATAMANAGER
 */
@end
