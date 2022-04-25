#ifndef _INPUT_H_
#define _INPUT_H_
#include <QuestEngine/Window.h>

class Input
{
public :
	bool m_upArrow = false;
	bool m_downArrow = false;
	bool m_leftArrow = false;
	bool m_rightArrow = false;
	
	bool m_upArrowKeyDown = false;
	bool m_downArrowKeyDown = false;
	bool m_leftArrowKeyDown = false;
	bool m_rightArrowKeyDown = false;

	void ResetInput();
	void CheckInput(Window* window);
};

#endif // !_INPUT_H_


