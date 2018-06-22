#include "Camera.h"



Camera::Camera(GLFWwindow *window, glm::vec3 cameraPosition, glm::vec3 cameraDirection, glm::vec3 upDirection)
	: deltaTime(0.0f), currentTime(0.0f), lastTime(0.0f), cameraPosition(cameraPosition), cameraDirection(cameraDirection),
	upDirection(upDirection), lastX(1280 / 2), lastY(720 / 2),  window(window)
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}


Camera::~Camera()
{
}

void Camera::mouseCallback()
{
	glfwGetCursorPos(window, &xpos, &ypos);
	//std::cout << "XPOSITION : " << xpos << std::endl << "YPOSITION : " << ypos << std::endl;

	offsetX = (xpos - lastX) * sensivity;
	offsetY = (ypos - lastY) * sensivity;

	lastX = xpos;
	lastY = ypos;

	movementX += offsetX;
}

void Camera::walk()
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		cameraPosition += (deltaTime * 4.0f) * cameraDirection;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		cameraPosition -= (deltaTime * 4.0f) * cameraDirection;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		cameraPosition -= (deltaTime * 4.0f) * glm::normalize(glm::cross(cameraDirection, upDirection));
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		cameraPosition += (deltaTime * 4.0f) * glm::normalize(glm::cross(cameraDirection, upDirection));
	}
}

glm::mat4 Camera::update()
{
	currentTime = glfwGetTime();
	deltaTime = currentTime - lastTime;
	lastTime = currentTime;

	mouseCallback();
	walk();
	
	cameraDirection.x = cos(glm::radians(movementX));
	cameraDirection.z = sin(glm::radians(movementX));

	return glm::lookAt(cameraPosition, cameraPosition + (cameraDirection), upDirection);
}
