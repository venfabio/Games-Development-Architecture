#include "Gamepad.h"
#pragma comment(lib, "Xinput.lib")

XButtonIDs XButtons;

// 'XButtonIDs' - Default constructor
XButtonIDs::XButtonIDs()
{
	// These values are used to index the XINPUT_Buttons array,
	// accessing the matching XINPUT button value

	A = 0;
	B = 1;
	X = 2;
	Y = 3;

	DPad_Up = 4;
	DPad_Down = 5;
	DPad_Left = 6;
	DPad_Right = 7;

	L_Shoulder = 8;
	R_Shoulder = 9;

	Start = 12;
	Back = 13;
}

Gamepad::Gamepad()
{
}


Gamepad::~Gamepad()
{
}

// Overloaded constructor
Gamepad::Gamepad(int a_iIndex)
{
	// Set gamepad index
	m_iGamepadIndex = a_iIndex - 1;

	// Iterate through all gamepad buttons
	for (int i = 0; i < ButtonCount; i++)
	{
		bPrev_ButtonStates[i] = false;
		bButtonStates[i] = false;
		bGamepad_ButtonsDown[i] = false;
	}

}

// Return gamepad state
XINPUT_STATE Gamepad::GetState()
{
	// Temporary XINPUT_STATE to return
	XINPUT_STATE GamepadState;

	// Zero memory
	ZeroMemory(&GamepadState, sizeof(XINPUT_STATE));

	// Get the state of the gamepad
	XInputGetState(m_iGamepadIndex, &GamepadState);

	// Return the gamepad state
	return GamepadState;
}

void Gamepad::Update()
{
	m_State = GetState(); // Obtain current gamepad state

	// Iterate through all gamepad buttons
	for (int i = 0; i < ButtonCount; i++)
	{
		// Set button state for current frame
		bButtonStates[i] = (m_State.Gamepad.wButtons &
			XINPUT_Buttons[i]) == XINPUT_Buttons[i];

		// Set 'DOWN' state for current frame
		bGamepad_ButtonsDown[i] = !bPrev_ButtonStates[i] &&
			bButtonStates[i];
	}

}

bool Gamepad::GetButtonPressed(int a_iButton)	// Get the button pressed
{
	if (m_State.Gamepad.wButtons & XINPUT_Buttons[a_iButton])
	{
		return true; // The button is pressed
	}

	return false; // The button is not pressed
}

// Update button states for next frame
void Gamepad::RefreshState()
{
	memcpy(bPrev_ButtonStates, bButtonStates,
		sizeof(bPrev_ButtonStates));
}

// Frame-specific version of 'GetButtonPressed' function
bool Gamepad::GetButtonDown(int a_iButton)
{
	return bGamepad_ButtonsDown[a_iButton];
}
