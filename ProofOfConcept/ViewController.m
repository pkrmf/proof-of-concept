//
//  ViewController.m
//  ProofOfConcept
//
//  Created by Marc Terns on 9/9/17.
//  Copyright © 2017 Marc Terns. All rights reserved.
//

#import "ViewController.h"
@import DummyFrameworkOne;
@import DummyFrameworkThree;
@import DummyFrameworkTwo;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    DONESample *doneSample = [[DONESample alloc] init];
    [doneSample print];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
