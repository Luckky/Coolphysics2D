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

@implementation GameView
{
    Entity* _entity0;
    Entity* _entity1;
    Entity* _entity2;
    Ball* _ball0;
    Ball* _ball1;
    Ball* _ball2;
}

-(id)initWithFrame:(CGRect)frame
{
    if (self=[super initWithFrame:frame]) {
        self.frame=frame;
        
        Frame gameWorldFrame;
        gameWorldFrame.left=0;
        gameWorldFrame.top=0;
        gameWorldFrame.right=self.frame.size.width;
        gameWorldFrame.bottom=self.frame.size.height;
        self.gameWorld=new GameWorld(gameWorldFrame,Vector(0, 1000),-0.01);
        
        _entity0=new Entity(50,1,Vector(0,0),Vector(500,0),Vector(0,0),0.95);
        _ball0=[[Ball alloc] initWithEntity:_entity0 color:[UIColor colorWithRed:0 green:0 blue:1 alpha:1]];
        
        _entity1=new Entity(30,0.5,Vector(300,100),Vector(-400,0),Vector(0,0),0.99);
        _ball1=[[Ball alloc] initWithEntity:_entity1 color:[UIColor colorWithRed:1 green:0 blue:0 alpha:1 ]];
        
        _entity2=new Entity(40,0.8,Vector(200,300),Vector(500,0),Vector(0,0),0.98);
        _ball2=[[Ball alloc] initWithEntity:_entity2 color:[UIColor colorWithRed:0 green:1 blue:0 alpha:1]];
        
        
        self.gameWorld->addEntity(_entity0);
        self.gameWorld->addEntity(_entity1);
        self.gameWorld->addEntity(_entity2);
        
    }
    return self;
}

-(void)drawRect:(CGRect)rect
{
    CGContextRef ctx=UIGraphicsGetCurrentContext();
    CGContextClearRect(ctx, self.frame);
    [_ball0 drawInContext:ctx];
    [_ball1 drawInContext:ctx];
    [_ball2 drawInContext:ctx];
}

-(void)dealloc
{
    delete self.gameWorld;
}

@end
