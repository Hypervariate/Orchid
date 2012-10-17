//
//  GameObject.cpp
//  Orchid
//
//  Created by Nate on 10/14/12.
//  Copyright (c) 2012 Nate. All rights reserved.
//

#include "GameObject.h"

GameObject::GameObject()
{
    body = NULL;
}
GameObject::~GameObject()
{
    if(body != NULL)
    {
        b2World *world = GlobalData::GetWorldPointer();
        world->DestroyBody(body);
        body = NULL;
    }
    
}
string GameObject::GetClassName()
{
    return "GameObject";
}
void GameObject::Draw()
{
    //pure virtual
}
void GameObject::SetTransform(float x, float y, float angle)
{
    //pure virtual
}