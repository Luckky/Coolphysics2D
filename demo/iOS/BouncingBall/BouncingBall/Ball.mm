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
    Entity* _entity;
}

-(id)initWithEntity:(Entity *)entity color:(UIColor*)color
{
    if (self=[super init]) {
        _color=color;
        _entity=entity;
    }
    return self;
}

-(void)drawInContext:(CGContextRef)context
{
    
    CGPoint thePoint = CGPointMake(_entity->position().x(), _entity->position().y());
    
    CGContextMoveToPoint(context, thePoint.x, thePoint.y);
    CGContextSetFillColor(context, CGColorGetComponents(_color.CGColor));
    CGContextAddArc(context, thePoint.x, thePoint.y, _entity->radius(),  0, 2*M_PI, 0);
    CGContextFillPath(context);
}

@end
