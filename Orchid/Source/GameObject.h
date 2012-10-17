//
//  GameObject.h
//  Orchid
//
//  Created by Nate on 10/14/12.
//  Copyright (c) 2012 Nate. All rights reserved.
//

#ifndef __Orchid__GameObject__
#define __Orchid__GameObject__



#include "GlobalData.h"


class GameObject{
public:
    GameObject();
    ~GameObject();
    
    virtual void Draw();
    virtual string GetClassName();
    virtual void SetTransform(float x, float y, float angle);
    
protected:
    b2Body* body;
    
};

#endif /* defined(__Orchid__GameObject__) */
