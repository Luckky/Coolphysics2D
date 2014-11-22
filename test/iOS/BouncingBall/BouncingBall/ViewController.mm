//
//  ViewController.m
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/21/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import "ViewController.h"
#import "GameView.h"


@interface ViewController ()

@end

@implementation ViewController
{
    GameView* gameView;
    float updateInterval;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    gameView=[[GameView alloc] initWithFrame:self.view.frame];
    updateInterval=0.01;
    [self.view addSubview:gameView];
    
    [NSTimer scheduledTimerWithTimeInterval:updateInterval target:self selector:@selector(timerCallback) userInfo:nil repeats:YES];
}

-(void)timerCallback
{
    gameView.gameWorld->update(updateInterval);
    [gameView setNeedsDisplay];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
