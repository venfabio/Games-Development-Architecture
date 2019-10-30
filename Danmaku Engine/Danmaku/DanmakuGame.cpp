#include "DanmakuGame.h"
#include "Window.h"
#include "Renderer.h"

/******************************************************************************************************************/

DanmakuGame::DanmakuGame()
{
	// Setup RNG and timer
	srand(time(NULL));
	_lastFrameTime = clock();
}

/******************************************************************************************************************/

DanmakuGame::~DanmakuGame()
{
}

/******************************************************************************************************************/

void DanmakuGame::Initialise(Window* w)
{
	// Initialise parent
	_window = w;
	_renderer = w->GetRenderer();

	// Vars
	_score = 0;
	_fader = 0;
	_faderInc = 1;
	_godMode = false;
	_multiplayer = true;
	_hardMode = false;
	_maxEnemies = 5;

	// Setup Meshes

	_meshPlayer.AddVertex({ -0.03f, 0.03f, 0, 1, 1, 1, 1 });
	_meshPlayer.AddVertex({ -0.06f, -0.05f, 0, 1, 1, 1, 1 });
	_meshPlayer.AddVertex({ 0.06f, -0.05f, 0, 1, 1, 1, 1 });
	_meshPlayer.AddVertex({ 0.03f, 0.03f, 0, 1, 1, 1, 1 });
	_meshPlayer.AddVertex({ 0.03f, -0.05f, 0, 1, 1, 1, 1 });
	_meshPlayer.AddVertex({ 0, 0.07f, 0, 1, 1, 1, 1 });
	_meshPlayer.AddVertex({ -0.03f, -0.05f, 0, 1, 1, 1, 1 });
	_meshPlayer.AddVertex({ -0.03f, 0.03f, 0, 1, 1, 1, 1 });

	_meshBullet.AddVertex({ 0.0f, 0.03f, 0, 1, 1, 1, 1 });
	_meshBullet.AddVertex({ 0.01f, 0.0f, 0, 1, 1, 1, 1 });
	_meshBullet.AddVertex({ -0.01f, 0.0f, 0, 1, 1, 1, 1 });
	_meshBullet.AddVertex({ 0.0f, 0.03f, 0, 1, 1, 1, 1 });

	// EVIL MUTANT NINJA ZOMBIES TRIANGLES
	_meshEnemy.AddVertex({ 0, -0.05f, 0, 1, 1, 1, 1 });
	_meshEnemy.AddVertex({ 0.03f, 0.05f, 0, 1, 1, 1, 1 });
	_meshEnemy.AddVertex({ -0.03f, 0.05f, 0, 1, 1, 1, 1 });
	_meshEnemy.AddVertex({ 0, -0.05f, 0, 1, 1, 1, 1 });

	// Twinkle twinkle little star...
	for (int a = 0; a <= 360; a += 45)
	{
		float x = sinDeg(a) * 0.01f;
		float y = cosDeg(a) * 0.01f;
		_meshParallax.AddVertex({ x, y, 0, 0.5f, 0.5f, 0.5f, 1 });
	}

	_meshExplosion.AddVertex({ 0.0f, 0.25f, 0, 1, 1, 0, 1 });
	_meshExplosion.AddVertex({ 0.05f, 0.10f, 0, 1, 0, 0, 1 });
	_meshExplosion.AddVertex({ 0.20f, 0.20f, 0, 1, 1, 0, 1 });
	_meshExplosion.AddVertex({ 0.10f, 0.05f, 0, 1, 0, 0, 1 });
	_meshExplosion.AddVertex({ 0.25f, 0.0f, 0, 1, 1, 0, 1 });
	_meshExplosion.AddVertex({ 0.10f, -0.05f, 0, 1, 0, 0, 1 });
	_meshExplosion.AddVertex({ 0.20f, -0.20f, 0, 1, 1, 0, 1 });
	_meshExplosion.AddVertex({ 0.05f, -0.10f, 0, 1, 0, 0, 1 });
	_meshExplosion.AddVertex({ 0.0f, -0.25f, 0, 1, 1, 0, 1 });
	_meshExplosion.AddVertex({ -0.05f, -0.10f, 0, 1, 0, 0, 1 });
	_meshExplosion.AddVertex({ -0.20f, -0.20f, 0, 1, 1, 0, 1 });
	_meshExplosion.AddVertex({ -0.10f, -0.05f, 0, 1, 0, 0, 1 });
	_meshExplosion.AddVertex({ -0.25f, -0.0f, 0, 1, 1, 0, 1 });
	_meshExplosion.AddVertex({ -0.10f, 0.05f, 0, 1, 0, 0, 1 });
	_meshExplosion.AddVertex({ -0.20f, 0.20f, 0, 1, 1, 0, 1 });
	_meshExplosion.AddVertex({ -0.05f, 0.10f, 0, 1, 0, 0, 1 });
	_meshExplosion.AddVertex({ 0.0f, 0.25f, 0, 1, 1, 0, 1 });

	for (int a = 0; a <= 360; a += 30)
	{
		float x = sinDeg(a) * 0.05f;
		float y = cosDeg(a) * 0.05f;
		_meshExplosionEvil.AddVertex({ x, y, 0, 1.5f, 0.0f, 1.0f, 1 });
	}

	// Create all the  VBOs
	_meshPlayer.CreateVBO(_renderer);
	_meshBullet.CreateVBO(_renderer);
	_meshEnemy.CreateVBO(_renderer);
	_meshExplosion.CreateVBO(_renderer);
	_meshParallax.CreateVBO(_renderer);
	_meshExplosionEvil.CreateVBO(_renderer);

	// Setup Objects
	_player = new Player();
	_player->SetMesh(&_meshPlayer);
	_player->SetColour(Colour(0.5f, 0.5f, 1.0f, 1.0f));

	if (_multiplayer) {

		_player2 = new Player();
		_player2->SetMesh(&_meshPlayer);
		_player2->SetColour(Colour(1.0f, 0.5f, 0.0f, 1.0f));
		for (int i = 0; i < NUM_BULLETS; i++)
		{
			Bullet* b = new Bullet();
			b->SetMesh(&_meshBullet);
			b->SetColour(Colour(1.0f, 0.5f, 0.0f, 1.0f));
			_bullets2.push_back(b);
		}
	}

	// Create bullets
	for (int i = 0; i < NUM_BULLETS; i++)
	{
		Bullet* b = new Bullet();
		b->SetMesh(&_meshBullet);
		b->SetColour(Colour(0.5f, 0.5f, 1.0f, 1.0f));
		_bullets.push_back(b);
	}

	for (int i = 0; i < NUM_BULLETS; i++)
	{
		Bullet* b = new Bullet();
		b->SetMesh(&_meshBullet);
		b->SetColour(Colour(1.5f, 0.0f, 1.0f, 1.0f));
		_evilBullets.push_back(b);
	}

	// Create enemies
	for (int i = 0; i < NUM_ENEMIES; i++)
	{
		Enemy* enemy = new Enemy();
		enemy->SetMesh(&_meshEnemy);
		enemy->SetColour(Colour(0.0f, 1.0f, 0.0f, 1.0f));
		enemy->Reset();
		_enemies.push_back(enemy);
	}

	// ... how I wonder what you are! (Create two types of stars: faster stars and slower stars)

	for (int i = 0; i < NUM_STARS; i++)
	{
		Parallax* fastStars = new Parallax();
		fastStars->SetMesh(&_meshParallax);
		fastStars->SpawnFast();
		fastStars->SetColour(Colour(1.0f, 1.0f, 1.0f, 1.0f));
		_parallax.push_back(fastStars);

		Parallax* slowStars = new Parallax();
		slowStars->SetMesh(&_meshParallax);
		slowStars->SpawnSlow();
		slowStars->SetColour(Colour(1.0f, 1.0f, 1.0f, 1.0f));
		_parallax.push_back(slowStars);
	}

	_explosion = new Explosion();
	_explosion->SetMesh(&_meshExplosion);

	_evilExplosion = new Explosion();
	_evilExplosion->SetMesh(&_meshExplosionEvil);

	// Setup Score Display
	_scoreDisplay = new ScoreDisplay(_renderer);
	
	// Setup Letters
	_SM = new SceneManager(_renderer);

	_gameState = Idle;
}

/******************************************************************************************************************/

void DanmakuGame::OnKeyboard(int key, bool down)
{
	_keyStates[key] = down;

	if (down) return; // Ignore key down events

	// Switch key presses
	switch (key)
	{
	case 27: // Esc
		_gameState = Quit;
		break;
	case 17: // Ctrl
		if (_player->IsAlive() &&
			_gameState == Playing)
		{
			for (int i = 0; i < (int)_bullets.size(); i++)
			{
				if (!_bullets[i]->IsAlive())
				{
					_bullets[i]->Reset(_player->GetPosition(), _player->GetAngle());
					break;
				}
			}
		}
		break;
	case 32: // Space
		if (_player2->IsAlive() &&
			_gameState == Playing)
		{
			for (int i = 0; i < (int)_bullets2.size(); i++)
			{
				if (!_bullets2[i]->IsAlive())
				{
					_bullets2[i]->Reset(_player2->GetPosition(), _player2->GetAngle());
					break;
				}
			}
		}
		break;
	case 71: // G
		_godMode = !_godMode;
		break;
	case 80: // P
		if (_gameState == Playing)
		{
			_gameState = Paused;
		}
		else if (_gameState = Paused)
		{
			_gameState = Playing;
		}
		break;
	case 82: // R
		_multiplayer = false;
		Reset();
		break;
	case 84: // T
		_multiplayer = true;
		Reset();
	}
}

/******************************************************************************************************************/

void DanmakuGame::Render()
{
	// Clear screen
	_renderer->ClearScreen();

	// Update MVM
	_MVM = _IM;
	_MVM = glm::translate(_MVM, glm::vec3(0, 0, 0));

	if (_gameState == Idle)

	{

		_SM->DrawMain(_renderer, _MVM);

	}

	else
	{

		// Switch colour if the god mode has been activated (only player 1 changes colour)
		if (!_godMode)
		{
			_player->SetColour(Colour(0.5f, 0.5f, 1.00f, 1.00f));
		}
		else
		{
			_player->SetColour(Colour::Red());
		}

		// Draw things
		if (_player->IsAlive())
		{
			_renderer->Draw(_player, _MVM);
		}

	
		if (_multiplayer == true && _player2->IsAlive())
			{
				_renderer->Draw(_player2, _MVM);
			}

		for (int i = 0; i < (int)_bullets.size(); i++)
		{
			if (_bullets[i]->IsAlive())
			{
				_renderer->Draw(_bullets[i], _MVM);
			}
		}

		if (_multiplayer)
		{
			for (int i = 0; i < (int)_bullets2.size(); i++)
			{
				if (_bullets2[i]->IsAlive())
				{
					_renderer->Draw(_bullets2[i], _MVM);
				}
			}
		}

		for (int i = 0; i < (int)_evilBullets.size(); i++)
		{
			if (_evilBullets[i]->IsAlive())
			{
				_renderer->Draw(_evilBullets[i], _MVM);
			}
		}

		for (int i = 0; i < (int)_enemies.size(); i++)
		{
			_renderer->Draw(_enemies[i], _MVM);
		}

		for (int i = 0; i < (int)_parallax.size(); i++)
		{
			if (_parallax[i]->IsAlive())
			{
				_renderer->Draw(_parallax[i], _MVM);
			}
		}

		if (_explosion->IsAlive())
		{
			_renderer->Draw(_explosion, _MVM);
		}

			if (_evilExplosion->IsAlive())
			{
				_renderer->Draw(_evilExplosion, _MVM);
			}

		_MVM = glm::translate(_MVM, glm::vec3(-0.95f, 0.90f, 0));
		_scoreDisplay->Draw(_renderer, _score, _MVM);
	}
	// Swap buffers
	_renderer->SwapBuffers();
}

/******************************************************************************************************************/

void DanmakuGame::Reset()
{
	if (_multiplayer)
	{
		_player->SetPosition(Vector4(0.3f, -0.7f, 0.0f, 1));
		_player->SetVelocity(Vector4());
		_player2->SetPosition(Vector4(-0.3f, -0.7f, 0.0f, 1));
		_player2->SetVelocity(Vector4());
		for (int i = 0; i < (int)_bullets2.size(); i++)
		{
			_bullets2[i]->SetAlive(false);
		}
		_player2->SetAlive(true);
	}
	else
	{
		_player->SetPosition(Vector4(0.0f, -0.7f, 0.0f, 1));
		_player->SetVelocity(Vector4());
		_player2->SetAlive(false);
	}

	_player->SetAlive(true);

	for (int i = 0; i < (int)_enemies.size(); i++)
	{
		_enemies[i]->Reset();
		if (i >= 5)
		{
			delete _enemies[i];
			_enemies.erase(_enemies.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < (int)_bullets.size(); i++)
	{
		_bullets[i]->SetAlive(false);
	}

	for (int i = 0; i < (int)_evilBullets.size(); i++)
	{
		_evilBullets[i]->SetAlive(false);
	}

	_explosion->SetAlive(false);

	_score = 0;
	_hardMode = false;
	_maxEnemies = 5;
	_gameState = Playing;
}

/******************************************************************************************************************/

void DanmakuGame::Run()
{
	// Get delta time
	temp_time = clock();
	_deltaTime = (temp_time - _lastFrameTime) / CLOCKS_PER_SEC;
	_lastFrameTime = temp_time;

	// The game won't run until prompted
	if (_gameState != Idle && _gameState != Paused) 
	{
		// Update Player
		if (_player->IsAlive())
		{
			_player->SetVelocity(Vector4());
			// Move Player
			OnGamepad();		// Calls the gamepad, if plugged in, the player can choose to use either the gamepad or the keyboard
			if (_keyStates[37])	// Left
			{
				_player->GoLeft(Player::ACCELERATION * _deltaTime);
			}
			if (_keyStates[39])	// Right
			{
				_player->GoRight(Player::ACCELERATION * _deltaTime);
			}
			if (_keyStates[38])	// Up
			{
				_player->Accelerate(Player::ACCELERATION * _deltaTime);
			}
			if (_keyStates[40])	// Down
			{
				_player->Reverse(Player::ACCELERATION * _deltaTime);
			}
			_player->Update(_deltaTime);
		}

		if (_multiplayer)	// 2P controls
		{
			_player2->SetVelocity(Vector4());
			// Move Player
			if (_keyStates[65])	// Left
			{
				_player2->GoLeft(Player::ACCELERATION * _deltaTime);
			}
			if (_keyStates[68])	// Right
			{
				_player2->GoRight(Player::ACCELERATION * _deltaTime);
			}
			if (_keyStates[87])	// Up
			{
				_player2->Accelerate(Player::ACCELERATION * _deltaTime);
			}
			if (_keyStates[83])	// Down
			{
				_player2->Reverse(Player::ACCELERATION * _deltaTime);
			}
			_player2->Update(_deltaTime);
		}
		// Update bullets
		for (int i = 0; i < (int)_bullets.size(); i++)
		{
			if (_bullets[i]->IsAlive())
			{
				_bullets[i]->Update(_deltaTime);
			}
		}

		if (_multiplayer)
		{
			for (int i = 0; i < (int)_bullets2.size(); i++)
			{
				if (_bullets2[i]->IsAlive())
				{
					_bullets2[i]->Update(_deltaTime);
				}
			}
		}

		// Update bullets
		for (int i = 0; i < (int)_evilBullets.size(); i++)
		{
			if (_evilBullets[i]->IsAlive())
			{
				if (_hardMode)
					_evilBullets[i]->UpdateV2(_deltaTime);
				else
					_evilBullets[i]->Update(_deltaTime);
			}
		}

		// Up above the world so high. Like a diamond in the sky! (Update Stars)
		for (int i = 0; i < (int)_parallax.size(); i++)
		{
			for (int j = 0; j < (int)_enemies.size(); j++)
			{
				// Do not draw a star if it is behind an object
				if (_parallax[i]->IsAlive() && _enemies[j]->CollideWith(_parallax[i], 0.03f * _enemies[j]->GetScale()))
				{
					//
					_parallax[i]->SetAlive(false);

				}
				_parallax[i]->SetAlive(true);
				_parallax[i]->Scroll(_deltaTime);
			}
		}

		// Update Enemys
		for (int i = 0; i < (int)_enemies.size(); i++)
		{
			_enemies[i]->Update(_deltaTime);

			// Shooting Zombies. (Because they are also both ninjas and mutants, but mostly evil.) 
		
			for (int j = 0; j < (int)_evilBullets.size(); j++)
			{
				if (!_evilBullets[j]->IsAlive() && _enemies[i]->IsCharged(_deltaTime))
				{
					_evilBullets[j]->Reset(_enemies[i]->GetPosition(), -180.0f);
					break;
				}
				// Collision detections with enemy bullets
				if (!_godMode &&
					_player->IsAlive() &&
					_evilBullets[j]->CollideWith(_player, 0.04f * _evilBullets[j]->GetScale()))
				{
					// DIE
					_player->SetAlive(false);
					_explosion->Reset(_player->GetPosition());
					if (_multiplayer == false && _player2->IsAlive() == false ) // In multiplayer mode, the game should continue if 1P dies but 2P is alive
					_gameState = Dead;
				}
				if (!_godMode &&
					_multiplayer &&
					_player2->IsAlive() &&
					_evilBullets[j]->CollideWith(_player2, 0.04f * _evilBullets[j]->GetScale()))
				{
					// YOUR FRIEND DIES.
					_player2->SetAlive(false);
					_explosion->Reset(_player2->GetPosition());
					if (_player->IsAlive() == false)
					_gameState = Dead;
				}
			}
			
			// Collision detections with MNZ Triangles (they eat your brain, zombie stuff).
			if (!_godMode &&
				_player->IsAlive() &&
				_enemies[i]->CollideWith(_player, 0.04f * _enemies[i]->GetScale()))
			{
				// DIE EVEN MORE
				_player->SetAlive(false);
				_explosion->Reset(_player->GetPosition());
				if (_multiplayer == false && _player2->IsAlive() == false) // In multiplayer mode, the game should continue if 1P dies but 2P is alive
				_gameState = Dead;
			}
			if (!_godMode &&
				_multiplayer &&
				_player2->IsAlive() &&
				_enemies[i]->CollideWith(_player2, 0.04f * _enemies[i]->GetScale()))
			{
				// DIE EVEN MORE
				_player2->SetAlive(false);
				_explosion->Reset(_player2->GetPosition());
				if (_player->IsAlive() == false)
				_gameState = Dead;
			}

			//else
			//{ //
				for (int j = 0; j < (int)_bullets.size(); j++)
				{
					if (_bullets[j]->IsAlive())
					{
						if (_enemies[i]->CollideWith(_bullets[j], 0.05f * _enemies[i]->GetScale()))
						{
							_score++;

							if (_score > 20)
							{
								_hardMode = true; // No more Mr. Nice Guy
								if (_score > 30)
								{
									_maxEnemies = 7;	// You deserve this.
									if (_score > 40)
										_maxEnemies = 10;	// You won't last long.
								}
							}
							// Kill an enemy. Well played.
							_evilExplosion->Reset(_enemies[i]->GetPosition());
							delete _enemies[i];
							_enemies.erase(_enemies.begin() + i);
							i--;
							if (i < 0) // During multiplayer games, i oftenly goes < 0 which causes exception.
								i = 0;
							_bullets[j]->SetAlive(false);
							break;
						}
					}
				}
				if (_multiplayer)
				{
					for (int k = 0; k < (int)_bullets2.size(); k++)
					{
						if (_bullets2[k]->IsAlive())
						{
							if (_enemies[i]->CollideWith(_bullets2[k], 0.05f * _enemies[i]->GetScale()))
							{
								_score++;

								if (_score > 20)
								{
									_hardMode = true; // No more Mr. Nice Guy
									if (_score > 30)
									{
										_maxEnemies = 7;	// You deserve this.
										if (_score > 40)
											_maxEnemies = 10;	// You won't last long.
									}		
								}

								// Kill an enemy. Well played.
								_evilExplosion->Reset(_enemies[i]->GetPosition());
								delete _enemies[i];
								_enemies.erase(_enemies.begin() + i);
								i--;
								if (i < 0)
									i = 0;
								_bullets2[k]->SetAlive(false);
								break;
							}
						}
					}
				}
			//} //
		}

		// Add more Enemies
		while (_enemies.size() < _maxEnemies)
		{
			Enemy* a = new Enemy();
			a->SetMesh(&_meshEnemy);
			a->SetColour(Colour(0.0f, 1.0f, 0.0f, 1.0f));
			a->Reset();
			_enemies.push_back(a);
		}

		// Update explosion
		if (_explosion->IsAlive())
		{
			_explosion->Update(_deltaTime);
		}

		if (_evilExplosion->IsAlive())
		{
			_evilExplosion->Update(_deltaTime);
		}

		_fader += _faderInc * _deltaTime;
		if (_fader < 0)
		{
			_faderInc = -_faderInc;
		}
		else if (_fader > 1)
		{
			_faderInc = -_faderInc;
		}

		// Change game state if necessary
		if (_gameState == Dead &&
			!_explosion->IsAlive())
		{
			_gameState = Resetting;
			_scoreCountdown = _score;
		}

		/* Force reset. Not in use because is too mean.
		if (_multiplayer && _gameState == Dead)
		{
			_gameState = Resetting;
			_scoreCountdown = _score;
		}
		*/

		else if (_gameState == Resetting)
		{
			_scoreCountdown -= 60 * _deltaTime;
			_score = (int)_scoreCountdown;
			if (_score < 0)
			{
				Reset();
			}
		}
	}

	// Draw
	Render();

}

void DanmakuGame::OnGamepad()

{
	MyGamepad.Update();

	if (MyGamepad.GetButtonPressed(XButtons.DPad_Left))
		_player->GoLeft(Player::ACCELERATION * _deltaTime);

	if (MyGamepad.GetButtonPressed(XButtons.DPad_Right))
		_player->GoRight(Player::ACCELERATION * _deltaTime);

	if (MyGamepad.GetButtonPressed(XButtons.DPad_Up))
		_player->Accelerate(Player::ACCELERATION * _deltaTime);

	if (MyGamepad.GetButtonPressed(XButtons.DPad_Down))
		_player->Reverse(Player::ACCELERATION * _deltaTime);

	if (MyGamepad.GetButtonPressed(XButtons.A))
		for (int i = 0; i < (int)_bullets.size(); i++)
		{
			if (!_bullets[i]->IsAlive())
			{
				_bullets[i]->Reset(_player->GetPosition(), _player->GetAngle());
				break;
			}
		}
	_player->Update(_deltaTime);
	MyGamepad.RefreshState();
}