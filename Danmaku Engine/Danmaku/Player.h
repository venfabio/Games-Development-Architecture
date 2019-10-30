#pragma once
#include "GameObject.h"

class Player :
	public GameObject
{
	// Constants
public:
	static const float MAX_SPEED;
	static const float ACCELERATION;

	// Data
public:

	// Structors
public:
	Player();
	virtual ~Player();

	// Functions
public:
	void GoLeft(float amt);
	void GoRight(float amt);
	void Accelerate(float amt);
	void Reverse(float amt);

	void Update(double deltaTime);
};

