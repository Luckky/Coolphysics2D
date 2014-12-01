#import "CP2DGameView.h"
#include "Vector.h"
#import "CP2DParticleRenderer.h"
#include "Field.h"
#include "DampingField.h"
#include "GravityField.h"
#include "BuoyancyField.h"

@implementation CP2DGameView

-(id)initWithFrame:(CGRect)frame
{
    if(self=[super initWithFrame:frame])
    {
        Rectangle gameWorldRange(0,0,self.frame.size.width,self.frame.size.height);
        self.gameWorld=new GameWorld(gameWorldRange);
    }
    return self;
}

-(void)drawRect:(CGRect)rect
{
    CGContextRef ctx=UIGraphicsGetCurrentContext();
    
    [_gameWorldRenderer renderInContext:ctx];
}

-(void)dealloc
{
    delete self.gameWorld;
}

@end