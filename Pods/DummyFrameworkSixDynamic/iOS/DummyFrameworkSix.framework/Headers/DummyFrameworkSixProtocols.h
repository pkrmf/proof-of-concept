//
//  DummyFrameworkSixProtocols.h
//  DummyFrameworkSix
//
//  Created by Marc Terns on 09/11/2017.
//  Copyright © 2017 com.ternsdevelopment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol DummyFrameworkSixInteractorOutputProtocol;
@protocol DummyFrameworkSixInteractorInputProtocol;
@protocol DummyFrameworkSixViewProtocol;
@protocol DummyFrameworkSixPresenterProtocol;
@protocol DummyFrameworkSixLocalDataManagerInputProtocol;
@protocol DummyFrameworkSixAPIDataManagerInputProtocol;

@class DummyFrameworkSixWireFrame;

// Defines the public interface that something else can use to drive the user interface
@protocol DummyFrameworkSixViewProtocol
@required
@property (nonatomic, strong) id <DummyFrameworkSixPresenterProtocol> presenter;
/**
 * Add here your methods for communication PRESENTER -> VIEWCONTROLLER
 */
@end

@protocol DummyFrameworkSixWireFrameProtocol
@required
+ (void)presentDummyFrameworkSixModuleFrom:(id)fromView;
/**
 * Add here your methods for communication PRESENTER -> WIREFRAME
 */
@end

@protocol DummyFrameworkSixPresenterProtocol
@required
@property (nonatomic, weak) id <DummyFrameworkSixViewProtocol> view;
@property (nonatomic, strong) id <DummyFrameworkSixInteractorInputProtocol> interactor;
@property (nonatomic, strong) id <DummyFrameworkSixWireFrameProtocol> wireFrame;
/**
 * Add here your methods for communication VIEWCONTROLLER -> PRESENTER
 */
@end

@protocol DummyFrameworkSixInteractorOutputProtocol
/**
 * Add here your methods for communication INTERACTOR -> PRESENTER
 */
@end

@protocol DummyFrameworkSixInteractorInputProtocol
@required
@property (nonatomic, weak) id <DummyFrameworkSixInteractorOutputProtocol> presenter;
@property (nonatomic, strong) id <DummyFrameworkSixAPIDataManagerInputProtocol> APIDataManager;
@property (nonatomic, strong) id <DummyFrameworkSixLocalDataManagerInputProtocol> localDataManager;
/**
 * Add here your methods for communication PRESENTER -> INTERACTOR
 */
@end


@protocol DummyFrameworkSixDataManagerInputProtocol
/**
 * Add here your methods for communication INTERACTOR -> DATAMANAGER
 */
@end

@protocol DummyFrameworkSixAPIDataManagerInputProtocol <DummyFrameworkSixDataManagerInputProtocol>
/**
 * Add here your methods for communication INTERACTOR -> APIDATAMANAGER
 */
@end

@protocol DummyFrameworkSixLocalDataManagerInputProtocol <DummyFrameworkSixDataManagerInputProtocol>
/**
 * Add here your methods for communication INTERACTOR -> LOCLDATAMANAGER
 */
@end
