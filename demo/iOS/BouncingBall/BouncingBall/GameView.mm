//
//  GameView.m
//  BouncingCP2DParticleRenderer
//
//  Created by JIRENTIANXIANG on 11/21/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import "GameView.h"

#include "Vector.h"
#import "CP2DParticleRenderer.h"
#include "Field.h"
#include "DampingField.h"
#include "GravityField.h"
#include "BuoyancyField.h"
#include "CP2DGameWorldRenderer.h"

@implementation GameView
{
    CP2DGameWorldRenderer* _gameWorldRenderer;
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
        
        Particle* _particle0=new Particle(50,1,0.95,Vector(0,0),Vector(500,0),Vector(0,0));
        
//        _particle0=new Particle(*self.gameWorld,50,1,0.95,Vector(0,0),Vector(500,0),Vector(0,0));
//        ParticleRenderer0=[[CP2DParticleRenderer alloc] initWithParticle:_particle0 color:[UIColor colorWithRed:0 green:0 blue:1 alpha:1]];
        
        Particle* _particle1=new Particle(30,0.5,0.99,Vector(300,100),Vector(-400,0),Vector(0,0));
        
//        _particle1=new Particle(*self.gameWorld,30,0.5,0.99,Vector(300,100),Vector(-400,0),Vector(0,0));
//        ParticleRenderer1=[[CP2DParticleRenderer alloc] initWithParticle:_particle1 color:[UIColor colorWithRed:1 green:0 blue:0 alpha:1 ]];
        
        Particle* _particle2=new Particle(40,0.8,0.98,Vector(200,300),Vector(500,0),Vector(0,0));
        
//        _particle2=new Particle(*self.gameWorld,40,0.8,0.98,Vector(200,300),Vector(500,0),Vector(0,0));
//        ParticleRenderer2=[[CP2DParticleRenderer alloc] initWithParticle:_particle2 color:[UIColor colorWithRed:0 green:1 blue:0 alpha:1]];
        
        
        self.gameWorld->addParticle(_particle0);
        self.gameWorld->addParticle(_particle1);
        self.gameWorld->addParticle(_particle2);
        
        _gameWorldRenderer=[[CP2DGameWorldRenderer alloc] initWithGameWorld:self.gameWorld];
        
        
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
    
    [_gameWorldRenderer renderInContext:ctx];
}

-(void)dealloc
{
    delete self.gameWorld;
}

@end
