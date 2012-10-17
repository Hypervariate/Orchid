//
//  Crate.h
//  Orchid
//
//  Created by Nate on 10/15/12.
//  Copyright (c) 2012 Nate. All rights reserved.
//

#ifndef __Orchid__Crate__
#define __Orchid__Crate__

#include "GameObject.h"

class Crate : public GameObject
{
public:
    Crate();
    ~Crate();
    
    virtual void Draw();
    virtual string GetClassName();
    
private:
    
    
};

#endif /* defined(__Orchid__Crate__) */
