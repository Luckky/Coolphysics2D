//
//  GameView.h
//  BouncingBall
//
//  Created by JIRENTIANXIANG on 11/21/14.
//  Copyright (c) 2014 JIRENTIANXIANG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Particle.h"
#import "GameWorld.h"

using namespace CoolPhysics2D;

@interface GameView : UIView

@property GameWorld* gameWorld;

@end
