#pragma once
#include "GameObject.h"
#include <stdlib.h>

class Enemy :
	public GameObject
{
	// Constants
public:
	static const float MAX_DRIFT;

	// Structors
public:
	Enemy();
	virtual ~Enemy();

	// Functions
public:
	// Reset the Enemy to a random velocity somewhere along the edge
	void Reset();
	void Update(double deltaTime);

	// I vari pattern per le ondate
	void WaveTypeOne();	

	bool IsCharged(double deltaTime);

};

