#pragma once


#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <mutex>

namespace Game
{
	namespace Input
	{
		/*
		enum KeyState
		Flag defines state a key is in (or trigger conditions for callback),

		KeyDown - Key is currently held down
		KeyPressed - Key was pressed after last time InputManager was updated (Happens once when key is initally pressed)
		KeyReleased - Key was released after last time InputManager was updated (Happens once when key is initally released)
		ShiftDown,AltDown,CtrlDown,SuperDown - Respective key modifiers are currently held down
		*/

		enum KeyState{ShiftDown = 0b1,CtrlDown = 0b10,AltDown = 0b100,SuperDown = 0b1000,KeyDown = 0b10000,KeyPressed = 0b100000,KeyReleased = 0b1000000, BlankMask = 0b0};

		/*
		Bitwise or,and,xor,not operators for KeyState Enum
		*/
		inline KeyState operator~ (KeyState a) 
		{
			return static_cast<KeyState>(~static_cast<int>(a));
		}
		inline KeyState operator|(KeyState a, KeyState b)
		{
			return static_cast<KeyState>(static_cast<int>(a) | static_cast<int>(b));
		}

		inline KeyState operator&(KeyState a, KeyState b)
		{
			return static_cast<KeyState>(static_cast<int>(a) & static_cast<int>(b));
		}

		inline KeyState operator^(KeyState a, KeyState b)
		{
			return static_cast<KeyState>(static_cast<int>(a) ^ static_cast<int>(b));
		}
		
		 inline KeyState& operator|= (KeyState& a, KeyState b) { return reinterpret_cast<KeyState&>(reinterpret_cast<int&>(a) |= static_cast<int>(b)); }
		 inline KeyState& operator&= (KeyState& a, KeyState b) { return reinterpret_cast<KeyState&>(reinterpret_cast<int&>(a) &= static_cast<int>(b)); }
		 inline KeyState& operator^= (KeyState& a, KeyState b) { return reinterpret_cast<KeyState&>(reinterpret_cast<int&>(a) ^= static_cast<int>(b)); }

		/*
		Function called during InputManager update if trigger conditions are met

		state - KeyState of key function is set to trigger on
		*/
		typedef void(*KeyCallback) (KeyState state);

		/*
		key - index of key to trigger on
		trigger - func is called during InputManager::Update() if trigger and KeyState of key match
		*/
		struct Callback
		{
			unsigned key;

			KeyState trigger;
			KeyCallback func;
		};

		/*
		Holds information about key
		*/
		struct Key
		{
			KeyState state;
		};




		class InputManager
		{
			/*
			KeyState that applies to all keys(Modifiers)
			*/
			KeyState globalKeyState = BlankMask;

			/*
			Array holding information about state of keys on keyboard
			*/


			Key keys[350];

		public:
			/*
			GLFW callback to get information about keys 
			*/
			void KeyHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
			void Update(float delta);
		};
	}
}