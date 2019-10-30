#pragma once
#include "GameObject.h"
#include <stdlib.h>

class Parallax : 
	public GameObject

{

public:
	Parallax();
	~Parallax();


	static const float _fastSpeed;	// A couple of stars will move faster, because they are "far" from the player
	static const float _slowSpeed;	// Another group of stars will move slower, because thay are "near" 

	void SpawnFast();
	void SpawnSlow();
	void Scroll(double deltaTime);

	bool isFast;
};

