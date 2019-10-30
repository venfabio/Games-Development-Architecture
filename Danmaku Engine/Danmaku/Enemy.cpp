#include "Enemy.h"

const float Enemy::MAX_DRIFT = 0.25f;

/******************************************************************************************************************/

Enemy::Enemy()
{
}

/******************************************************************************************************************/

Enemy::~Enemy()
{
}

/******************************************************************************************************************/

void Enemy::Reset()
{
	float r = 0;
	r = rand() * 1.0f / RAND_MAX * 2 - 1;
	_velocity.x(MAX_DRIFT * r * 1.5f);

	r = rand() * 1.0f / RAND_MAX * 2 - 1;

		_position.x(r);

	r = rand() * 1.0f / RAND_MAX * 2 - 1;
	if (r > 0)
		r = r * (-1);
	_velocity.y(MAX_DRIFT * r * 2.5f);

	_position.y(1);

	_scale = 2;
}

/******************************************************************************************************************/

bool Enemy::IsCharged(double deltaTime)

{
	_charge = GetCharge();

	if (_charge == 0)
	{
		_charge = rand() % 1000 + 1;
		SetCharge(_charge);
		return true;
	}
	else
	{
		_charge -= (float)deltaTime;
		SetCharge(_charge);
		return false;
	}
}
void Enemy::WaveTypeOne()

{
	_position.y(1.0f);
	_position.x(1.0f);
	_velocity.y(-1.0f);
	_velocity.x(0.0f);
	for (int i = 0; i < 5; i++)
		switch (i) {

		case 0: 
			_position.x(0.0f);
			break;
		case 1:
			_position.x(-0.5f);
			break;
		case 2:
			_position.x(0.5f);
			break;
		case 3:
			_position.x(0.8f);
			break;
		case 4:
			_position.x(-0.8f);

	}
}

void Enemy::Update(double deltaTime)
{
	GameObject::Update(deltaTime);

	// Boundaries on thx X axes
	if (_position.x() < -1) {
		_position.x(-1);
		float r = rand() * 1.0f / RAND_MAX * 2 - 1;
		_velocity.x(MAX_DRIFT * r * 1.5f);
	}
	else if (_position.x() > 1) {
		_position.x(1);
		float r = rand() * 1.0f / RAND_MAX * 2 - 1;
		_velocity.x(MAX_DRIFT * r * -1.5f);
	}
	if (_position.y() < -1)
		_position.y(_position.y() + 2);
	else if (_position.y() > 1)
		_position.y(_position.y() - 2);
}