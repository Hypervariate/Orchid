#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "GraphicsCore.h"
#include "Shape2DRect.h"

#include "Vector2DF.h"
#include "GlobalData.h"

#include <list>


class GameObject{

public:
	GameObject(int x, int y);
	~GameObject();

	

	//update the object's position and other properties
	virtual void Update();

	//let the object draw itself
	virtual void Draw();

	//let the object destroy itself
	virtual void Destroy();

	//destroy all objects in the world
	//this is typically called before loading a new level or ending the game
	static void DestroyAll();

	//update all objects. Typically this is called once per frame
	static void UpdateAll();

	//let the object determine how it will decide to move digitally
	//it will continue to move until its controller tells it to stop
	virtual void StartMovingUp();
	virtual void StartMovingDown();
	virtual void StartMovingLeft();
	virtual void StartMovingRight();

	virtual void StopMovingUp();
	virtual void StopMovingDown();
	virtual void StopMovingLeft();
	virtual void StopMovingRight();

	//make the object move in an analogue direction at its predefined speed
	virtual void Move(float dirX, float dirY);

	//set the object's position
	virtual void MoveTo(int x, int y);

	virtual void ResumeMovement();

	bool DetectCollision(GameObject* target);
	
	//objects can change shapes so their shapes are defined at runtime
	//declare a new shape on the heap in the object's constructor and
	//assign it to this pointer. Don't forget to clean up in the destructor!
	Shape2D* GetShape();

	//wrappers for the object's shape
	virtual int GetX();
	virtual int GetY();
	virtual void SetX(float x);
	virtual void SetY(float y);
	virtual int GetW();
	virtual int GetH();
	virtual int GetHalfOfWidth();
    virtual int GetHalfOfHeight();

	//get the current velocity of the object
	virtual float GetVelocityX();
	virtual float GetVelocityY();

	//objects must be added to the world in order to become "physical" and interact-able
	static void AddToWorld(GameObject* g);

	//return the game object as it is ordered in the list
	//if index is out of bounds, return the last game object to be added
	static GameObject* GetGameObject(int number = -1);

	//return an object's life property
	int GetLife();
	void SetLife(int life);

	virtual char* GetObjectType(){ return "GameObject";}



protected:

	static std::list<GameObject *> objects;
	static std::list<GameObject *>::iterator iter1;
	static std::list<GameObject *>::iterator iter2;
	
	
	Shape2D* shape;
	 int speed;
	float maxSpeed;
	float minSpeed;

	Vector2DF position;		//current location in the world
	Vector2DF velocity;		//speed and direction of the game object
	Vector2DF drag;			//friction coefficents
	Vector2DF inertia;		//current rate of propulsion. This decreases over time.
	Vector2DF baseInertia;	//The base value given to inertia (rate of propulsion) at the moment the object begins to move

	
	//properties used to keep track of the object's moving state
	bool moveUp;
	bool moveDown;
	bool moveLeft;
	bool moveRight;

	//allow the object to inspect the target of its collision and react based on what that target might be
	//(example: if(target == spikes) I should die)
	virtual void HandleCollisionWithTarget(GameObject* target);
public:
	bool alive;

private:
	
	int life;


};

#endif