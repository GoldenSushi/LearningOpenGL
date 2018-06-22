#ifndef CAMERA_H
#define CAMERA_H

#include "Error.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"


class Camera
{
private:

	GLFWwindow *window;

	const float sensivity = 0.05f;

	double xpos;
	double ypos;
	double lastX;
	double lastY;
	double offsetX;
	double offsetY;

	double movementX;
	double movementY;
	
	float deltaTime;
	float currentTime;
	float lastTime;

	glm::vec3 cameraPosition;
	glm::vec3 cameraDirection;
	glm::vec3 upDirection;
	
	glm::mat3 rotationMatrix;

public:
	Camera(GLFWwindow *window, glm::vec3 cameraPosition, glm::vec3 cameraDirection, glm::vec3 upDirection);
	~Camera();
	void mouseCallback();
	void walk();
	glm::vec3 getCameraPos() { return cameraPosition; };
	glm::mat4 update();
};

#endif //CAMERA_H