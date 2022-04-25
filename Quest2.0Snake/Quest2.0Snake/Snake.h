#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <QuestEngine/Shader.h>
#include <QuestEngine/Shape.h>
#include "Input.h"
#include "Grid.h"
#include <set>

enum class Direction : short
{
	UP = 0,
	RIGHT = 1,
	LEFT = 2,
	DOWN = 3,
};

struct SnakeCase
{
public:
	int caseIndexX = 0.0f;
	int caseIndexY = 0.0f;
	int rectIndex = 0;

	bool operator<(const SnakeCase& snakeCaseOther) const
	{
		return caseIndexX == snakeCaseOther.caseIndexX ? caseIndexY > snakeCaseOther.caseIndexY: caseIndexX > snakeCaseOther.caseIndexX;	
	}
};

class Snake
{

public : 
	Snake(int caseIndexX, int caseIndexY,float caseSize, float red, float green, float blue, int startSize, int maxSize, float durationToMove, const Grid* const grid, const Input* const input = nullptr);
	~Snake();

	void Update(float deltatime);
	void Draw();
	bool GrowUp();
	int GetCaseIndexX(int caseIndex);
	int GetCaseIndexY(int caseIndex);
	int GetSnakeSize() const;
	bool CaseExist(int indexX, int indexY);
	SnakeCase GetSnakeCaseInEmptyIndex(int index);

	void Reset(int caseIndexX, int caseIndexY);
	typedef void (* OnMove)(Snake*, int, int);
	OnMove OnMoveEvent;
	OnMove OnMovedEvent;

	typedef void (*OnDeath)(Snake*);
	OnDeath OnDeathEvent;

private :
	Shader* m_shaderSnake = nullptr;	
	Shape** m_snakeRectangle = nullptr;
	SnakeCase* m_snakeCase = nullptr;
	const Input* m_input = nullptr;
	const Grid* m_grid;

	std::set<SnakeCase> m_snakeEmptyIndex;
	bool m_stop = false;
	Direction m_direction = Direction::RIGHT;
	float m_timeToMove = 0.0f;
	float m_durationToMove = 0.0f;

	int m_snakeMaxSize = 0;
	int m_firstIndex = 0;
	int m_lastIndex = 0;
	int m_currentSize = 0;

	int m_lastCaseIndexX = 0.0f;
	int m_lastCaseIndexY = 0.0f;
};

#endif _SNAKE_H_