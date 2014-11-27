//
//  GameView.m
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/21/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import "GameView.h"

#include "Vector.h"
#include "Ball.h"
#include "Field.h"
#include "DampingField.h"
#include "GravityField.h"
#include "BuoyancyField.h"

@implementation GameView
{
    Particle* _particle0;
    Particle* _particle1;
    Particle* _particle2;
    Ball* _ball0;
    Ball* _ball1;
    Ball* _ball2;
}

-(id)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]) {
        self.frame=frame;
        
        Rectangle gameWorldRange(0,0,self.frame.size.width,self.frame.size.height);
        self.gameWorld=new GameWorld(gameWorldRange);
        Rectangle water(0,400,self.frame.size.width,self.frame.size.height-400);
        Field* dampingField=new DampingField(water,-1.5);
        self.gameWorld->addField(dampingField);
        GravityField* gravityField=new GravityField(gameWorldRange,Vector(0, 1000));
        self.gameWorld->addField(gravityField);
        Field* buoyancyField=new BuoyancyField(water,*gravityField,0.0002);
        self.gameWorld->addField(buoyancyField);
        
        _particle0=new Particle(50,1,Vector(0,0),Vector(500,0),Vector(0,0),0.95);
        _ball0=[[Ball alloc] initWithParticle:_particle0 color:[UIColor colorWithRed:0 green:0 blue:1 alpha:1]];
        
        _particle1=new Particle(30,0.5,Vector(300,100),Vector(-400,0),Vector(0,0),0.99);
        _ball1=[[Ball alloc] initWithParticle:_particle1 color:[UIColor colorWithRed:1 green:0 blue:0 alpha:1 ]];
        
        _particle2=new Particle(40,0.8,Vector(200,300),Vector(500,0),Vector(0,0),0.98);
        _ball2=[[Ball alloc] initWithParticle:_particle2 color:[UIColor colorWithRed:0 green:1 blue:0 alpha:1]];
        
        
        self.gameWorld->addParticle(_particle0);
        self.gameWorld->addParticle(_particle1);
        self.gameWorld->addParticle(_particle2);
        
    }
    return self;
}

-(void)drawRect:(CGRect)rect
{
    CGContextRef ctx=UIGraphicsGetCurrentContext();
    CGContextClearRect(ctx, self.frame);
    UIBezierPath *square = [UIBezierPath bezierPathWithRect:CGRectMake(0, 400, self.frame.size.width, self.frame.size.height-400)];
    CGContextSetRGBFillColor(ctx, 0, 0, 1, 0.4);
    [square fill];
    [square stroke];
    
    [_ball0 drawInContext:ctx];
    [_ball1 drawInContext:ctx];
    [_ball2 drawInContext:ctx];
}

-(void)dealloc
{
    delete self.gameWorld;
}

@end
