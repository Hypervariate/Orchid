//
//  BoxCrate.h
//  Orchid
//
//  Created by Nate on 10/15/12.
//  Copyright (c) 2012 Nate. All rights reserved.
//

#ifndef __Orchid__BoxCrate__
#define __Orchid__BoxCrate__

#include "GameObject.h"


class BoxCrate : public GameObject
{
public:
    BoxCrate(float x = 10.0f, float y = 10.0f);
    ~BoxCrate();
    virtual void Draw();
    virtual string GetClassName();
    virtual void SetPosition(float x, float y);
private:
    float *polygon;
    ALLEGRO_COLOR renderColor;
};

#endif /* defined(__Orchid__BoxCrate__) */
