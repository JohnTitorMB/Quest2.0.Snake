#include "Snake.h"
#include "ShaderUtils.h"
#include <assert.h>
Snake::Snake(int caseIndexX, int caseIndexY, float caseSize, float red, float green, float blue, int startSize, int maxSize, float durationToMove, const Grid* const grid, const Input* const input)
{
	const char* SnakefragmentShaderSource = ShaderUtils::GenereFragmentShaderWithColor(red, green, blue);
	m_shaderSnake = new Shader(ShaderUtils::GetDefaultVertesShader(), SnakefragmentShaderSource);

	m_snakeMaxSize = maxSize;
	m_snakeRectangle = new Shape * [maxSize];

	m_snakeCase = new SnakeCase[maxSize];
	// Create shape and set position

	int mult = grid->GetTileXCount() * grid->GetTileYCount();
	for (int i = 0; i < mult; i++)
	{
		SnakeCase s = SnakeCase();

		s.caseIndexY = i / grid->GetTileXCount();
		s.caseIndexX = i - s.caseIndexY* grid->GetTileXCount();

		m_snakeEmptyIndex.insert(s);

	}
	for (int i = 0; i < maxSize; i++)
	{
		if (i < startSize)
		{
			SnakeCase s = m_snakeCase[i];
			s.caseIndexX = caseIndexX - i;
			s.caseIndexY = caseIndexY;
	
		
			s.rectIndex = i;
			m_snakeRectangle[i] = Shape::CreateRectangle(grid->GetPosXAt(s.caseIndexX, true), grid->GetPosXAt(s.caseIndexY, true), m_shaderSnake, GLDrawType::GLSTATIC_DRAW, caseSize, caseSize);

			m_snakeCase[i] = s;

			m_snakeEmptyIndex.erase(s);

		}
		else
		{
			m_snakeRectangle[i] = Shape::CreateRectangle(grid->GetPosXAt(0, true), grid->GetPosYAt(0, true), m_shaderSnake, GLDrawType::GLSTATIC_DRAW, caseSize, caseSize);
			SnakeCase s = m_snakeCase[i];
			s.caseIndexX = 0;
			s.caseIndexY = 0;
			s.rectIndex = -1;
			m_snakeCase[i] = s;
		}
	}

	m_input = input;

	m_durationToMove = durationToMove;
	m_timeToMove = m_durationToMove;
	m_grid = grid;

	m_lastIndex = startSize - 1;
	m_currentSize = startSize;

	OnMoveEvent = nullptr;
	OnMovedEvent = nullptr;
}

void Snake::Reset(int caseIndexX, int caseIndexY)
{
	int mult = m_grid->GetTileXCount() * m_grid->GetTileYCount();
	m_snakeEmptyIndex.clear();

	m_stop = false;
	
	for (int i = 0; i < m_currentSize; i++)
	{
		int index = m_firstIndex + i;
		if (index >= m_snakeMaxSize)
			index = index - m_snakeMaxSize;

		int x = GetCaseIndexX(i);
		int y = GetCaseIndexY(i);

		if (i < m_currentSize)
		{
			m_snakeRectangle[m_snakeCase[index].rectIndex]->Move(-x * m_grid->GetTileXSize(), -y * m_grid->GetTileYSize());
		}
	}

	for (int i = 0; i < mult; i++)
	{	
		SnakeCase s = SnakeCase();

		s.caseIndexY = i / m_grid->GetTileXCount();
		s.caseIndexX = i - s.caseIndexY * m_grid->GetTileXCount();

		m_snakeEmptyIndex.insert(s);

	}
	
	int startSize = 4;
	for (int i = 0; i < m_snakeMaxSize; i++)
	{
		if (i < startSize)
		{
			SnakeCase s = m_snakeCase[i];
			s.caseIndexX = caseIndexX - i;
			s.caseIndexY = caseIndexY;

			s.rectIndex = i;
			m_snakeCase[i] = s;
			m_snakeRectangle[i]->Move(s.caseIndexX * m_grid->GetTileXSize(), s.caseIndexY * m_grid->GetTileYSize());


			m_snakeEmptyIndex.erase(s);
		}
		else
		{
			SnakeCase s = m_snakeCase[i];
			s.caseIndexX = 0;
			s.caseIndexY = 0;
			s.rectIndex = -1;
			m_snakeCase[i] = s;
		}
	}

	m_firstIndex = 0;
	m_lastIndex = startSize - 1;
	m_currentSize = startSize;

	m_timeToMove = 0.0f;

	m_lastCaseIndexX = 0;
	m_lastCaseIndexY = 0;

	m_direction = Direction::RIGHT;

//	stop = true;
}
bool Snake::CaseExist(int indexX, int indexY)
{
	SnakeCase s = SnakeCase();
	s.caseIndexX = indexX;
	s.caseIndexY = indexY;
	
	return (m_snakeEmptyIndex.find(s) == m_snakeEmptyIndex.end());
}

SnakeCase Snake::GetSnakeCaseInEmptyIndex(int index)
{
	std::set<SnakeCase>::iterator it;

	int value = 0;
	for (auto f : m_snakeEmptyIndex) 
	{
		if (value == index)
		{
			return f;
		}
		value++;
	}

	SnakeCase s = SnakeCase();
	
	return s;
}

void Snake::Update(float deltatime)
{
	if (m_grid == nullptr)
		return;

	m_timeToMove += deltatime;

	//Change snake movement direction
	if (m_input->m_upArrowKeyDown)
		m_direction = Direction::UP;
	if (m_input->m_downArrowKeyDown)
		m_direction = Direction::DOWN;
	if (m_input->m_leftArrowKeyDown)
		m_direction = Direction::LEFT;
	if (m_input->m_rightArrowKeyDown)
		m_direction = Direction::RIGHT;
	bool death = false;

	if (m_timeToMove >= m_durationToMove)
	{
		if (!m_stop)
		{
			//cache index
			int firstCaseIndexX = GetCaseIndexX(0);
			int firstCaseIndexY = GetCaseIndexY(0);


			m_lastCaseIndexX = m_snakeCase[m_lastIndex].caseIndexX;
			m_lastCaseIndexY = m_snakeCase[m_lastIndex].caseIndexY;

			//m_lastCaseIndexX = GetCaseIndexX(m_currentSize - 1);
			//m_lastCaseIndexY = GetCaseIndexY(m_currentSize - 1);
			int lastRectIndex = m_snakeCase[m_lastIndex].rectIndex;

			int deltaX = 0;
			int deltaY = 0;

			//compute delta movement with direction
			int movedCaseCount = 1;
			switch (m_direction)
			{
			case Direction::UP:
				deltaY = movedCaseCount;
				break;
			case Direction::RIGHT:
				deltaX = movedCaseCount;
				break;
			case Direction::LEFT:
				deltaX = -movedCaseCount;
				break;
			case Direction::DOWN:
				deltaY = -movedCaseCount;
				break;
			default:
				break;

			}

			//Compute newPosition with snakefirstCase and delta
			int newCaseIndexX = firstCaseIndexX + deltaX;
			int newCaseIndexY = firstCaseIndexY + deltaY;

			if (CaseExist(newCaseIndexX, newCaseIndexY))
			{
				death = true;
			}
			else if (newCaseIndexX < 0 || newCaseIndexX >= m_grid->GetTileXCount()
				|| newCaseIndexY < 0 || newCaseIndexY >= m_grid->GetTileYCount())
			{
				death = true;
			}

			if (!death)
			{
				(this->OnMoveEvent)(this, newCaseIndexX, newCaseIndexY);

				m_snakeEmptyIndex.insert(m_snakeCase[m_lastIndex]);

				//Reset lastIndexSnakeCase
				SnakeCase s = m_snakeCase[m_lastIndex];
				s.caseIndexX = 0;
				s.caseIndexY = 0;
				s.rectIndex = -1;
				m_snakeCase[m_lastIndex] = s;

				//Reduce firstIndex by one and loop on maxSnakeSize
				m_firstIndex -= 1;
				if (m_firstIndex < 0)
					m_firstIndex = m_snakeMaxSize - 1;

				//Reduce lastIndex by one and loop on maxSnakeSize
				m_lastIndex -= 1;
				if (m_lastIndex < 0)
					m_lastIndex = m_snakeMaxSize - 1;


				//Move LastCase To newPosition
				m_snakeRectangle[lastRectIndex]->Move((newCaseIndexX - m_lastCaseIndexX) * m_grid->GetTileXSize()
					, (newCaseIndexY - m_lastCaseIndexY) * m_grid->GetTileYSize());

				//Display lastCase to firstCase
				s = m_snakeCase[m_firstIndex];
				s.caseIndexX = newCaseIndexX;
				s.caseIndexY = newCaseIndexY;
				s.rectIndex = lastRectIndex;
				m_snakeCase[m_firstIndex] = s;

				m_snakeEmptyIndex.erase(m_snakeCase[m_firstIndex]);

				(this->OnMovedEvent)(this, newCaseIndexX, newCaseIndexY);

			}
			else
				(this->OnDeathEvent)(this);
		}
		
		m_timeToMove = 0.0f;	
	}
}

Snake::~Snake()
{
	if (m_shaderSnake != nullptr)
	{
		delete m_shaderSnake;
		m_shaderSnake = nullptr;
	}

	if (m_snakeRectangle != nullptr)
	{
		delete[] m_snakeRectangle;
		m_snakeRectangle = nullptr;
	}

	if (m_snakeCase != nullptr)
		delete m_snakeCase;
}

void Snake::Draw()
{
	for (int i = 0; i < m_currentSize; i++)
		m_snakeRectangle[i]->Draw();
}

int Snake::GetCaseIndexX(int caseIndex)
{
	if (caseIndex < 0 || caseIndex > m_snakeMaxSize)
	{
		assert("caseIndex cannot less 0 or less m_snakeMaxSize");
		return 0.0f;
	}

	int index = m_firstIndex + caseIndex;
	if (index >= m_snakeMaxSize)
		index = index - m_snakeMaxSize;

	return m_snakeCase[index].caseIndexX;
}

int Snake::GetCaseIndexY(int caseIndex)
{
	if (caseIndex < 0 || caseIndex > m_snakeMaxSize)
	{
		assert("caseIndex cannot less 0 or less m_snakeMaxSize");
		return 0.0f;
	}

	int index = m_firstIndex + caseIndex;
	if (index >= m_snakeMaxSize)
		index = index - m_snakeMaxSize;

	return m_snakeCase[index].caseIndexY;
}

bool Snake::GrowUp()
{
	if (m_currentSize == m_snakeMaxSize)
		return false;

	int newIndex = m_lastIndex + 1;
	if (newIndex >= m_snakeMaxSize)
		newIndex = 0;

	int beforeLastIndex = m_lastIndex - 1;
	if (beforeLastIndex < 0)
		beforeLastIndex = m_snakeMaxSize - 1;

	SnakeCase s = m_snakeCase[newIndex];
	s.caseIndexX = m_lastCaseIndexX;
	s.caseIndexY = m_lastCaseIndexY;
	s.rectIndex = m_currentSize;

	m_snakeRectangle[s.rectIndex]->Move(s.caseIndexX * m_grid->GetTileXSize(), s.caseIndexY * m_grid->GetTileYSize());
	m_snakeCase[newIndex] = s;

	m_snakeEmptyIndex.erase(m_snakeCase[newIndex]);

	m_lastIndex = newIndex;
	m_currentSize++;

	return true;
}

int Snake::GetSnakeSize() const
{
	return m_currentSize;
}