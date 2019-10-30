#include "Parallax.h"

// DEVE ESSERE RIVISTO

const float Parallax::_fastSpeed = 0.50f;		
const float Parallax::_slowSpeed = 0.05f;

Parallax::Parallax()
{
}


Parallax::~Parallax()
{
}

void Parallax::SpawnFast()
{
	float r = 0;
	r = rand() * 1.0f / RAND_MAX * 2 - 1;
	_position.x(r);
	_velocity.x(0);

	r = rand() * 1.0f / RAND_MAX * 2 - 1;
	if (r > 0)
		r = r * (-1);
	_position.y(r);

	/*r = rand() % 3 + 1;
	if (r > 0)
		r = r * (-1);*/
	_velocity.y(_fastSpeed * r);

	_scale = 0.2f;

	isFast = true;
}

void Parallax::SpawnSlow()
{
	float r = 0;

	r = rand() * 1.0f / RAND_MAX * 2 - 1;
	_position.x(r);
	_velocity.x(0);

	r = rand() * 1.0f / RAND_MAX * 2 - 1;
	/*if (r > 0)
		r = r * (-1);*/
	_position.y(r);

	/*r = rand() % 3 + 1;
	if (r > 0)
		r = r * (-1);*/
	_velocity.y(_slowSpeed * (-1));

	_scale = 0.4f;

	isFast = false;
}

void Parallax::Scroll(double deltaTime)
{
	GameObject::Update(deltaTime);

	// Wrap around
	if (_position.x() < -1) _position.x(_position.x() + 2);
	else if (_position.x() > 1) _position.x(_position.x() - 2);
	if (_position.y() < -1) _position.y(_position.y() + 2);
	else if (_position.y() > 1) _position.y(_position.y() - 2);

	if (isFast)

		_velocity.limitTo(0.50f);

	else

		_velocity.limitTo(0.10f);


}