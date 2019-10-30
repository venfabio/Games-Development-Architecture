#pragma once

// STL
#include <vector>
#include <time.h>
#include <stdlib.h>

// GLM
#include "GL\GLM\GLM.hpp"
#include "GL\GLM\GTC\matrix_transform.hpp"
#include "GL\GLM\GTC\type_ptr.hpp"

// Engine classes
#include "Renderer.h"
#include "Window.h"
#include "SceneManager.h"
#include "Gamepad.h"

// Game classes
#include "Player.h"
#include "Bullet.h"
#include "Explosion.h"
#include "Enemy.h"
#include "ScoreDisplay.h"
#include "Parallax.h"


// Forward declarations
class Renderer;
class Window;

// Simple game state enum for the Asteroids game
enum GameState
{
	Playing,
	Paused,
	Dead,
	Resetting,
	Quit,
	Idle
};


class DanmakuGame
{
	// Constants and statics
public:
	static const int		NUM_ENEMIES = 5;
	static const int		NUM_BULLETS = 5;
	static const int		NUM_STARS = 50;

	// Data
private:
	// Matrices
	glm::mat4				_IM;  // Identity matrix
	glm::mat4				_MVM; // ModelView matrix

	Window*					_window;
	Renderer*				_renderer;

	double					_lastFrameTime;		// Time of last frame
	double					_deltaTime;			// Time since last frame
	bool					_keyStates[256];	// Keyboard status

	// Meshes
	Mesh					_meshPlayer;
	Mesh					_meshEnemy;
	Mesh					_meshBullet;
	Mesh					_meshExplosion;
	Mesh					_meshExplosionEvil; // They just... "splat"
	Mesh					_meshParallax;

	// Game Data
	Player*					_player;
	Player*					_player2;			// 2 players 
	Explosion*				_explosion;
	Explosion*				_evilExplosion;		// 
	std::vector<Bullet*>	_bullets;
	std::vector<Bullet*>	_bullets2;			// 2 players
	std::vector<Enemy*>		_enemies;
	std::vector<Parallax*>	_parallax;
	std::vector<Bullet*>	_evilBullets;

	ScoreDisplay*			_scoreDisplay;
	SceneManager*			_SM;

	int						_score;
	int						_maxEnemies;
	float					_scoreCountdown;
	float					_fader;
	float					_faderInc;
	bool					_godMode;
	GameState				_gameState;
	bool					_multiplayer;
	bool					_hardMode;			// HAHAHAHA

	double temp_time;

	Gamepad					MyGamepad = Gamepad(1);		// Initialize a Gamepad on the first port

	// Structors
public:
	DanmakuGame();
	virtual ~DanmakuGame();

	// Accessors
public:

	GameState GetGameState()				const	{ return _gameState; }

	// Functions
public:

	// Initialise the game
	virtual void Initialise(Window* w);

	// Keyboard input
	virtual void OnKeyboard(int key, bool down);

	// Gamepad input
	virtual void OnGamepad();

	// Render everything
	virtual void Render();

	// Main game loop
	virtual void Run();

	// Reset the game
	void Reset();
};

