//
//  Ball.h
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/22/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import "Particle.h"
#import <UIKit/UIKit.h>

using namespace CoolPhysics2D;

@interface Ball : UIView

-(id)initWithParticle:(Particle*)particle color:(UIColor*)color ;

-(void)drawInContext:(CGContextRef)context;

@end
