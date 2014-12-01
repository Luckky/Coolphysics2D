#import <UIKit/UIKit.h>
#import "Particle.h"
#import "GameWorld.h"
#import "CP2DGameWorldRenderer.h"

using namespace CoolPhysics2D;

@interface CP2DGameView : UIView
{
    CP2DGameWorldRenderer* _gameWorldRenderer;
}

@property GameWorld* gameWorld;

@end