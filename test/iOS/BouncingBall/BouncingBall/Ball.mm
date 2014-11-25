//
//  Ball.m
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/22/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import "Ball.h"

@implementation Ball
{
    UIColor* _color;
    Particle* _particle;
}

-(id)initWithParticle:(Particle *)particle color:(UIColor*)color
{
    if (self=[super init]) {
        _color=color;
        _particle=particle;
    }
    return self;
}

-(void)drawInContext:(CGContextRef)context
{
    
    CGPoint thePoint = CGPointMake(_particle->position().x(), _particle->position().y());
    
    CGContextMoveToPoint(context, thePoint.x, thePoint.y);
    CGContextSetFillColor(context, CGColorGetComponents(_color.CGColor));
    CGContextAddArc(context, thePoint.x, thePoint.y, _particle->radius(),  0, 2*M_PI, 0);
    CGContextFillPath(context);
}

@end
