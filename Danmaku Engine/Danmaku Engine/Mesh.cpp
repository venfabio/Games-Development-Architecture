#include "Mesh.h"
#include "VBO_DX.h"


/******************************************************************************************************************/

Mesh::Mesh()
	:	_locked(false),
		_vbo(NULL)
	
{
}

/******************************************************************************************************************/

Mesh::~Mesh()
{
	delete _vbo;
	_vbo = NULL;
}

/******************************************************************************************************************/

bool Mesh::AddVertex(Vertex v)
{
	if (!_locked)
	{
		_vertices.push_back(v);
		return true;
	}
	else
	{
		return false;
	}
}

/******************************************************************************************************************/

bool Mesh::DeleteVertex(int i)
{
	if (!_locked)
	{
		_vertices.erase(_vertices.begin() + i);
		return true;
	}
	else
	{
		return false;
	}
}

/******************************************************************************************************************/

bool Mesh::Clear()
{
	if (!_locked)
	{
		_vertices.clear();
		return true;
	}
	return false;
}

/******************************************************************************************************************/

void Mesh::Reset()
{
	delete _vbo;
	_vbo = NULL;
	_locked = false;
}

/******************************************************************************************************************/


VBO* Mesh::CreateVBO(Renderer* renderer)
{
	_locked = true;

	_vbo = new VBO_DX();

	_vbo->Create(renderer, _vertices.data(), NumVertices());

	return _vbo;
}