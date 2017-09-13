//
//  TodayViewController.m
//  ProofOfConceptWidget
//
//  Created by Marc Terns on 9/13/17.
//  Copyright © 2017 Marc Terns. All rights reserved.
//

#import "TodayViewController.h"
#import <NotificationCenter/NotificationCenter.h>
@import DummyFrameworkOne;
@import DummyFrameworkThree;
@import DummyFrameworkTwo;
@import DummyFrameworkFour;
@import DummyFrameworkFive;
@import DummyFrameworkSix;


@interface TodayViewController () <NCWidgetProviding>

@end

@implementation TodayViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)widgetPerformUpdateWithCompletionHandler:(void (^)(NCUpdateResult))completionHandler {
    // Perform any setup necessary in order to update the view.
    
    // If an error is encountered, use NCUpdateResultFailed
    // If there's no update required, use NCUpdateResultNoData
    // If there's an update, use NCUpdateResultNewData

    completionHandler(NCUpdateResultNewData);
}

@end
