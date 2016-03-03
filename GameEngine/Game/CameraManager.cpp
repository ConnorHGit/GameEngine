#include "CameraManager.h"

glm::vec3 Game::Camera::Camera::forward()
{
	return glm::vec3(0, 0, 1) * orientation;
}

glm::vec3 Game::Camera::Camera::backward()
{
	return glm::vec3(0, 0, -1) * orientation;
}

glm::vec3 Game::Camera::Camera::right()
{
	return glm::vec3(1, 0, 0) * orientation;
}

glm::vec3 Game::Camera::Camera::left()
{
	return glm::vec3(-1,0,0) * orientation;
}

glm::vec3 Game::Camera::Camera::up()
{
	return glm::vec3(0,1,0) * orientation;
}

glm::vec3 Game::Camera::Camera::down()
{
	return glm::vec3(0,-1,0) * orientation;
}

glm::quat Game::Camera::Camera::getOrientation()
{
	return orientation;
}

void Game::Camera::Camera::setOrientation(glm::quat newQuat)
{
	orientation = newQuat;
	changed = true;
}

void Game::Camera::Camera::setOrientation(float yaw, float pitch, float roll)
{
	orientation = glm::quat(glm::vec3(pitch,yaw,roll));
	changed = true;
}

void Game::Camera::Camera::updateOrientation(glm::quat change)
{
	orientation = orientation * change;
}

void Game::Camera::Camera::updateOrientation(float yaw, float pitch, float roll)
{
	orientation = orientation * glm::quat(glm::vec3(pitch, yaw, roll));
}

glm::vec3 Game::Camera::Camera::getPosition()
{
	return glm::vec3();
}

void Game::Camera::Camera::setPosition(glm::vec3 newPos)
{
}

void Game::Camera::Camera::updatePosition(glm::vec3 change)
{
}

glm::mat4 Game::Camera::Camera::getTransformMatrix()
{
	return glm::mat4();
}
