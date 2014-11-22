//
//  Ball.h
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/22/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import "Entity.h"
#import <UIKit/UIKit.h>

@interface Ball : UIView

-(id)initWithRadius:(float)radius color:(UIColor*)color entity:(Entity*)entity;

-(void)drawInContext:(CGContextRef)context;

@end
