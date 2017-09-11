//
//  DummyFrameworkThreeProtocols.h
//  DummyFrameworkThree
//
//  Created by Marc Terns on 09/10/2017.
//  Copyright © 2017 com.ternsdevelopment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol DummyFrameworkThreeInteractorOutputProtocol;
@protocol DummyFrameworkThreeInteractorInputProtocol;
@protocol DummyFrameworkThreeViewProtocol;
@protocol DummyFrameworkThreePresenterProtocol;
@protocol DummyFrameworkThreeLocalDataManagerInputProtocol;
@protocol DummyFrameworkThreeAPIDataManagerInputProtocol;

@class DummyFrameworkThreeWireFrame;

// Defines the public interface that something else can use to drive the user interface
@protocol DummyFrameworkThreeViewProtocol
@required
@property (nonatomic, strong) id <DummyFrameworkThreePresenterProtocol> presenter;
/**
 * Add here your methods for communication PRESENTER -> VIEWCONTROLLER
 */
@end

@protocol DummyFrameworkThreeWireFrameProtocol
@required
+ (void)presentDummyFrameworkThreeModuleFrom:(id)fromView;
/**
 * Add here your methods for communication PRESENTER -> WIREFRAME
 */
@end

@protocol DummyFrameworkThreePresenterProtocol
@required
@property (nonatomic, weak) id <DummyFrameworkThreeViewProtocol> view;
@property (nonatomic, strong) id <DummyFrameworkThreeInteractorInputProtocol> interactor;
@property (nonatomic, strong) id <DummyFrameworkThreeWireFrameProtocol> wireFrame;
/**
 * Add here your methods for communication VIEWCONTROLLER -> PRESENTER
 */
@end

@protocol DummyFrameworkThreeInteractorOutputProtocol
/**
 * Add here your methods for communication INTERACTOR -> PRESENTER
 */
@end

@protocol DummyFrameworkThreeInteractorInputProtocol
@required
@property (nonatomic, weak) id <DummyFrameworkThreeInteractorOutputProtocol> presenter;
@property (nonatomic, strong) id <DummyFrameworkThreeAPIDataManagerInputProtocol> APIDataManager;
@property (nonatomic, strong) id <DummyFrameworkThreeLocalDataManagerInputProtocol> localDataManager;
/**
 * Add here your methods for communication PRESENTER -> INTERACTOR
 */
@end


@protocol DummyFrameworkThreeDataManagerInputProtocol
/**
 * Add here your methods for communication INTERACTOR -> DATAMANAGER
 */
@end

@protocol DummyFrameworkThreeAPIDataManagerInputProtocol <DummyFrameworkThreeDataManagerInputProtocol>
/**
 * Add here your methods for communication INTERACTOR -> APIDATAMANAGER
 */
@end

@protocol DummyFrameworkThreeLocalDataManagerInputProtocol <DummyFrameworkThreeDataManagerInputProtocol>
/**
 * Add here your methods for communication INTERACTOR -> LOCLDATAMANAGER
 */
@end
