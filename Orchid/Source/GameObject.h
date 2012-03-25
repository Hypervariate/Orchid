#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

class GameObject{

public:
	GameObject();
	~GameObject();

	virtual void Draw();

private:
	int x;
	int y;

};

#endif