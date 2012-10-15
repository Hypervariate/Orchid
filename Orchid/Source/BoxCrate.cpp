//
//  BoxCrate.cpp
//  Orchid
//
//  Created by Nate on 10/15/12.
//  Copyright (c) 2012 Nate. All rights reserved.
//

#include "BoxCrate.h"

BoxCrate::BoxCrate()
{
    
        // Define the dynamic body. We set its position and call the body factory.
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(SCREEN_WIDTH/2/PTM_RATIO, 1.0f);
        b2World *world = GlobalData::GetWorldPointer();
        body = world->CreateBody(&bodyDef);
    
        // Define another box shape for our dynamic body.
        b2PolygonShape dynamicBox;
        float boxSize = 1.0f;
        dynamicBox.SetAsBox(boxSize, boxSize);
    
        // Define the dynamic body fixture.
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
    
        // Set the box density to be non-zero, so it will be dynamic.
        fixtureDef.density = 1.0f;
    
        // Override the default friction.
        fixtureDef.friction = 0.3f;
    
        // Add the shape to the body.
        body->CreateFixture(&fixtureDef);
    
    

}
BoxCrate::~BoxCrate()
{

}
void BoxCrate::Draw()
{
    

}
string BoxCrate::GetClassName()
{
    return "BoxCrate";
    
}