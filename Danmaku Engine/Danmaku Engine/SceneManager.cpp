#include "SceneManager.h"


SceneManager::SceneManager(Renderer* renderer)
{
	// A
	_letters[0].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[0].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[0].AddVertex({ 0.00f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[0].AddVertex({ 0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[0].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[0].AddVertex({ 0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[0].AddVertex({ 0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[0].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });

	// B
	_letters[1].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[1].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[1].AddVertex({ 0.0f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[1].AddVertex({ 0.04f, -0.02f, 0, 1, 1, 1, 1 });
	_letters[1].AddVertex({ 0.0f, -0.04f, 0, 1, 1, 1, 1 });
	_letters[1].AddVertex({ -0.04f, -0.04f, 0, 1, 1, 1, 1 });
	_letters[1].AddVertex({ 0.0f, -0.06f, 0, 1, 1, 1, 1 });
	_letters[1].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[1].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// C
	_letters[2].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[2].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[2].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[2].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// D
	_letters[3].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[3].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[3].AddVertex({ 0.0f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[3].AddVertex({ 0.04f, -0.02f, 0, 1, 1, 1, 1 });
	_letters[3].AddVertex({ 0.04f, -0.07f, 0, 1, 1, 1, 1 });
	_letters[3].AddVertex({ 0.0f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[3].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// E

	_letters[4].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[4].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[4].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[4].AddVertex({ 0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[4].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[4].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[4].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// F
	_letters[5].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[5].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[5].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[5].AddVertex({ 0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[5].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[5].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// G
	_letters[6].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[6].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[6].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[6].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[6].AddVertex({ 0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[6].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });

	// H
	_letters[7].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[7].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[7].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[7].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[7].AddVertex({ 0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[7].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[7].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// I
	_letters[8].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[8].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[8].AddVertex({ 0.0f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[8].AddVertex({ 0.0f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[8].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[8].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// J
	_letters[9].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[9].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[9].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[9].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });

	// K
	_letters[10].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[10].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[10].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[10].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[10].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[10].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[10].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// L
	_letters[11].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[11].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[11].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// M
	_letters[12].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[12].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[12].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[12].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[12].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// N
	_letters[13].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[13].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[13].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[13].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });

	// O
	_letters[14].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[14].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[14].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[14].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[14].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// P
	_letters[15].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[15].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[15].AddVertex({ 0.0f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[15].AddVertex({ 0.04f, -0.02f, 0, 1, 1, 1, 1 });
	_letters[15].AddVertex({ 0.0f, -0.04f, 0, 1, 1, 1, 1 });
	_letters[15].AddVertex({ -0.04f, -0.04f, 0, 1, 1, 1, 1 });

	// Q
	_letters[16].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[16].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[16].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[16].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[16].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[16].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[16].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });

	// R
	_letters[17].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[17].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[17].AddVertex({ 0.0f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[17].AddVertex({ 0.04f, -0.02f, 0, 1, 1, 1, 1 });
	_letters[17].AddVertex({ 0.0f, -0.04f, 0, 1, 1, 1, 1 });
	_letters[17].AddVertex({ -0.04f, -0.04f, 0, 1, 1, 1, 1 });
	_letters[17].AddVertex({ 0.0f, -0.06f, 0, 1, 1, 1, 1 });
	_letters[17].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// S
	_letters[18].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[18].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[18].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[18].AddVertex({ 0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[18].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[18].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });

	// T
	_letters[19].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[19].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[19].AddVertex({ 0.00f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[19].AddVertex({ 0.00f, -0.09f, 0, 1, 1, 1, 1 });

	// U
	_letters[20].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[20].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[20].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[20].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[20].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	
	// V
	_letters[21].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[21].AddVertex({ -0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[21].AddVertex({ 0.0f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[21].AddVertex({ 0.04f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[21].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });

	// W
	_letters[22].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[22].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[22].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[22].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[22].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });

	// X
	_letters[23].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[23].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[23].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[23].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[23].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[23].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[23].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });

	// Y
	_letters[24].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[24].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[24].AddVertex({ 0.0f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[24].AddVertex({ 0.0f, -0.05f, 0, 1, 1, 1, 1 });
	_letters[24].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });

	// Z
	_letters[25].AddVertex({ -0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[25].AddVertex({ 0.04f, 0.0f, 0, 1, 1, 1, 1 });
	_letters[25].AddVertex({ -0.04f, -0.09f, 0, 1, 1, 1, 1 });
	_letters[25].AddVertex({ 0.04f, -0.09f, 0, 1, 1, 1, 1 });

	for (int i = 0; i < 26; i++)
	{

		_letters[i].CreateVBO(renderer);

	}

}


SceneManager::~SceneManager()
{
}

void SceneManager::DrawMain(Renderer* renderer, glm::mat4 MVM)
{
	Colour colour = Colour::Green();

		MVM = glm::translate(MVM, glm::vec3(-0.5f, 0.5f, 0));
		renderer->Draw(&_letters[4], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[21], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[8], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[11], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0)); // ^ Evil 
		renderer->Draw(&_letters[12], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[20], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[19], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[0], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[13], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[19], MVM, colour);

		MVM = glm::translate(MVM, glm::vec3(-1.05f, -0.2f, 0));	// 

		renderer->Draw(&_letters[13], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[8], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[13], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[9], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[0], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));
		renderer->Draw(&_letters[25], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[14], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[12], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[1], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[8], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[4], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));

		MVM = glm::translate(MVM, glm::vec3(-1.05f, -0.2f, 0));	// 

		renderer->Draw(&_letters[19], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[17], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[8], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[0], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[13], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[6], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[11], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[4], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[18], MVM, colour);
		
		// Super lazy instructions

		MVM = glm::translate(MVM, glm::vec3(-0.75f, -0.2f, 0));
		MVM = glm::scale(MVM, glm::vec3(0.3f, 0.3f, 1));

		colour = Colour::Blueish();

		renderer->Draw(&_letters[15], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[17], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[4], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[18], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[18], MVM, colour);

		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));
		renderer->Draw(&_letters[17], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));

		renderer->Draw(&_letters[5], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[14], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[17], MVM, colour);

		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));

		renderer->Draw(&_letters[18], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0)); 
		renderer->Draw(&_letters[8], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[13], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[6], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[11], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[4], MVM, colour);

		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));

		renderer->Draw(&_letters[15], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[11], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[0], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[24], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[4], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[17], MVM, colour);

		MVM = glm::translate(MVM, glm::vec3(-2.3f, -0.2f, 0));

		colour = Colour::Orange();

		renderer->Draw(&_letters[15], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[17], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[4], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[18], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[18], MVM, colour);

		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));
		renderer->Draw(&_letters[19], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));

		renderer->Draw(&_letters[5], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[14], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[17], MVM, colour);

		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));

		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[2], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[14], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));
		renderer->Draw(&_letters[14], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[15], MVM, colour);

		MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0));

		renderer->Draw(&_letters[6], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[0], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[12], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
		renderer->Draw(&_letters[4], MVM, colour);
		MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
}

void SceneManager::Scoreboard(Renderer* renderer, glm::mat4 MVM, int score)

{
	Colour colour = Colour::Red();
	MVM = glm::translate(MVM, glm::vec3(-0.6f, 0.5f, 0));
	renderer->Draw(&_letters[24], MVM, colour);
	MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
	renderer->Draw(&_letters[14], MVM, colour);
	MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
	renderer->Draw(&_letters[20], MVM, colour);
	MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
	renderer->Draw(&_letters[17], MVM, colour);

	MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0)); // Space
	
	renderer->Draw(&_letters[18], MVM, colour);
	MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
	renderer->Draw(&_letters[2], MVM, colour);
	MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
	renderer->Draw(&_letters[14], MVM, colour);
	MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
	renderer->Draw(&_letters[17], MVM, colour);
	MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
	renderer->Draw(&_letters[4], MVM, colour);

	MVM = glm::translate(MVM, glm::vec3(0.2f, 0, 0)); // Space

	renderer->Draw(&_letters[8], MVM, colour);
	MVM = glm::translate(MVM, glm::vec3(0.1f, 0, 0));
	renderer->Draw(&_letters[18], MVM, colour);

}