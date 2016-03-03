#include "InputManager.h"

void Game::Input::InputManager::KeyHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key >= sizeof(keys) - 1)return;

	globalKeyState &= BlankMask; //Sets all flags of global key state to false
	globalKeyState |= static_cast<KeyState>(mods); //Sets value of Shift,Ctrl,Alt,Super to right values

	switch(action)
	{
	case GLFW_PRESS:
		keys[key].state |= KeyPressed | KeyDown; //Sets KeyPressed and KeyDown to true
		keys[key].state &= ~KeyReleased;//Sets KeyReleased to false
		break;
	case GLFW_RELEASE:
		keys[key].state |= KeyReleased; //Sets KeyReleased to true
		keys[key].state &= ~(KeyPressed | KeyDown); //Sets KeyPressed and KeyDown to false
		break;
	}
}

void Game::Input::InputManager::Update(float delta)
{
	for each(Callback c in callbacks)
	{
		KeyState trigger = globalKeyState | keys[c.key].state;

		if (c.trigger & trigger == trigger) 
		{
			c.func(trigger);
		}
	}

	for each(Key k in keys)
	{
		k.state &= ~(KeyPressed | KeyReleased);
	}
}
