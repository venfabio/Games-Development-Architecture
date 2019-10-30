#pragma once

// GLM
#include "GL\GLM\GLM.hpp"
#include "GL\GLM\GTC\matrix_transform.hpp"
#include "GL\GLM\GTC\type_ptr.hpp"

// Engine classes
#include "Mesh.h"
#include "Vector4.h"
#include "Colour.h"
#include "MathsHelper.h"
#include "Renderer.h"

class SceneManager
{

	// Data
private:
	Mesh _letters[26];



public:
	SceneManager(Renderer* renderer);
	~SceneManager();

public:
	void DrawMain(Renderer* renderer, glm::mat4 MVM);
	void Scoreboard(Renderer* renderer, glm::mat4 MVM, int score);

};

