//
//  BoxCrate.cpp
//  Orchid
//
//  Created by Nate on 10/15/12.
//  Copyright (c) 2012 Nate. All rights reserved.
//

#include "BoxCrate.h"


BoxCrate::BoxCrate(float x, float y, float angle)
{
    
        // Define the dynamic body. We set its position and call the body factory.
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(x, y);
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
    
        SetTransform(x, y, angle);
    
        polygon = new float[8];

}

BoxCrate::~BoxCrate()
{
    delete[] polygon;

}
void BoxCrate::SetTransform(float x, float y, float angle)
{
    body->SetTransform(b2Vec2(x, y), angle);
}
void BoxCrate::Draw()
{
    
    float boxSize = 1.0f;
    
    renderColor.r = 0;
    renderColor.g = 256;
    renderColor.b = 0;
    
    // Now print the position and angle of the body.
    b2Vec2 position = body->GetPosition();
    
            // hWidth, hHeight = half the rectangle's width & height
            // position.x, position.y = center position of the rectangle
            const b2Transform transform = body->GetTransform();
            float rad = transform.GetAngle();
            
            //top left
            polygon[0] = -(boxSize * cosf(rad) + boxSize * sinf(rad) ) + position.x;
            polygon[1] = -(boxSize * sinf(rad) - boxSize * cosf(rad) ) + position.y;
            
            //bottom left
            polygon[2] = -(boxSize * cosf(rad) - boxSize * sinf(rad) ) + position.x;
            polygon[3] = -(boxSize * sinf(rad) + boxSize * cosf(rad) ) + position.y;
            
            //bottom right
            polygon[4] = (boxSize * cosf(rad) + boxSize * sinf(rad) ) + position.x;
            polygon[5] = (boxSize * sinf(rad) - boxSize * cosf(rad) ) + position.y;
            
            //top right
            polygon[6] = (boxSize * cosf(rad) - boxSize * sinf(rad) ) + position.x;
            polygon[7] = (boxSize * sinf(rad) + boxSize * cosf(rad) ) + position.y;
            
            
            
            for(int i = 0; i < 7; i+=2)
            {
                
                
                polygon[i]   *= PTM_RATIO;  //x
                polygon[i+1] *= PTM_RATIO;  //y
                
                polygon[i]   = ABS(polygon[i]);  //x
                polygon[i+1] = ABS(polygon[i+1]);  //y
            }
            
            for(int i = 0; i < 7; i+=2)
                printf("(%4.f, %4.f) ", polygon[i], polygon[i+1]);
            printf("\n");
            
            //al_draw_polygon(polygon,4,ALLEGRO_LINE_JOIN_NONE,color_purple,1.5,1);	//not in allegro 5.0.7
            al_draw_line(polygon[0], polygon[1], polygon[2], polygon[3], renderColor, 1);
            al_draw_line(polygon[2], polygon[3], polygon[4], polygon[5], renderColor, 1);
            al_draw_line(polygon[4], polygon[5], polygon[6], polygon[7], renderColor, 1);
            al_draw_line(polygon[6], polygon[7], polygon[0], polygon[1], renderColor, 1);
            
            
     


}
string BoxCrate::GetClassName()
{
    return "BoxCrate";
    
}