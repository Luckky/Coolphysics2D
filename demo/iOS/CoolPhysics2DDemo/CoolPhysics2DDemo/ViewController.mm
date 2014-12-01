//
//  ViewController.m
//  CoolPhysics2DDemo
//
//  Created by JIRENTIANXIANG on 11/28/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import "ViewController.h"
#import "BouncingBallViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 1;
}

-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *MyIdentifier = @"MyIdentifier";
    UITableViewCell* cell=[tableView dequeueReusableCellWithIdentifier:MyIdentifier];
    if (!cell) {
        cell=[[UITableViewCell alloc] init];
    }
    switch (indexPath.row) {
        case 0:
            cell.textLabel.text=@"Bouncing Balls";
            break;
            
        default:
            break;
    }
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    switch (indexPath.row) {
        case 0:
        {
            BouncingBallViewController* viewController=[[BouncingBallViewController alloc] init];
            [self.navigationController pushViewController:viewController animated:YES];
            break;
        }
            
        default:
        {
            break;
        }
    }
}

@end
