#include "Player.h"

const float Player::ACCELERATION = 40.0f;
const float Player::MAX_SPEED = 4.0f;

/******************************************************************************************************************/

Player::Player()
{
}

/******************************************************************************************************************/

Player::~Player()
{
}

/******************************************************************************************************************/

void Player::Accelerate(float amt)
{
	Vector4 thrust(0, amt);
	_velocity += thrust;
}

/******************************************************************************************************************/

void Player::Update(double deltaTime)
{
	Vector4 vel = _velocity;
	vel *= (float)deltaTime;
	_position += vel;

	// Boundaries on X and Y axes
	if (_position.x() < -1)
		_position.x(-1);
	else if (_position.x() > 1)
		_position.x(1);
	if (_position.y() < -1)
		_position.y(-1);
	else if (_position.y() > 1)
		_position.y(1);

	// Cap speed
	_velocity.limitTo(MAX_SPEED);
}

/******************************************************************************************************************/

void Player::GoLeft(float amt)
{
	Vector4 thrust(-amt, 0);
	_velocity += thrust;
}

/******************************************************************************************************************/

void Player::GoRight(float amt)
{
	Vector4 thrust(amt, 0);
	_velocity += thrust;
}

/******************************************************************************************************************/

void Player::Reverse(float amt)
{
	Vector4 thrust(0, -amt);
	_velocity += thrust;
}