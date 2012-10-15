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
    
}
GameObject::~GameObject()
{
    
}
string GameObject::GetClassName()
{
    return "GameObject";
}
void GameObject::Draw()
{
    //pure virtual
}