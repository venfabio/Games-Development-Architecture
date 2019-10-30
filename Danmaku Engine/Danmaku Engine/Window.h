#pragma once

// Forward declarations
class DanmakuGame;
class Renderer;
class Game;


// Generic window class
// Handles window setup and input
class Window
{
	// Constants and statics
public:
	// Singleton (sort of)
	static Window*							TheWindow;

	// Data
public:
	DanmakuGame*							_game;
	Game*									_myGame;
	Renderer*								_renderer;
	int										_width, _height;


	// Structors
public:
	Window(DanmakuGame* game, int width, int height);
	virtual ~Window();

	Window(Game* game, int width, int height);


	// Gets/sets
public:
	DanmakuGame* GetGame()		const	{ return _game; }
	Renderer* GetRenderer()			const	{ return _renderer; }

	Game* GetMyGame()					const	{ return _myGame; }

	// Functions
public:
	virtual void Initialise() = 0;

};

