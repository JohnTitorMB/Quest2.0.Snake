#include "Input.h"
void Input::ResetInput()
{
	m_upArrowKeyDown = false;
	m_downArrowKeyDown = false;
	m_leftArrowKeyDown = false;
	m_rightArrowKeyDown = false;
}

void Input::CheckInput(Window* window)
{
	ResetInput();
	if (glfwGetKey(window->GetWindow(), GLFW_KEY_UP) == GLFW_PRESS)
	{
		if (m_upArrow == false)
			m_upArrowKeyDown = true;
		m_upArrow = true;
	}
	else
		m_upArrow = false;

	if (glfwGetKey(window->GetWindow(), GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		if (m_downArrow == false)
			m_downArrowKeyDown = true;
		m_downArrow = true;
	}
	else
		m_downArrow = false;

	if (glfwGetKey(window->GetWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		if (m_leftArrow == false)
			m_leftArrowKeyDown = true;
		m_leftArrow = true;
	}
	else
		m_leftArrow = false;

	if (glfwGetKey(window->GetWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		if (m_rightArrow == false)
			m_rightArrowKeyDown = true;
		m_rightArrow = true;
	}
	else
		m_rightArrow = false;
}