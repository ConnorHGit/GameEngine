#pragma once

#include "glm\glm.hpp"
#include "glm\gtc\quaternion.hpp"

namespace Game 
{
	namespace Camera
	{
		class Camera
		{
		private:
			bool changed;

			glm::quat orientation;
			glm::vec3 position;
			glm::mat4 transformMatrix;

		public:

			glm::vec3 forward();
			glm::vec3 backward();

			glm::vec3 right();
			glm::vec3 left();
			
			glm::vec3 up();
			glm::vec3 down();
			
			glm::quat getOrientation();
			void setOrientation(glm::quat newQuat);
			void setOrientation(float yaw, float pitch, float roll);
			void updateOrientation(glm::quat change);
			void updateOrientation(float yaw, float pitch, float roll);

			glm::vec3 getPosition();
			void setPosition(glm::vec3 newPos);
			void updatePosition(glm::vec3 change);

			glm::mat4 getTransformMatrix();
		};
		class CameraManager 
		{

		};
	}
}