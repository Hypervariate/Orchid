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
    BoxCrate();
    ~BoxCrate();
    virtual void Draw();
    virtual string GetClassName();
};

#endif /* defined(__Orchid__BoxCrate__) */
