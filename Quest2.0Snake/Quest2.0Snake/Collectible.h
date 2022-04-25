#ifndef _COLLECTIBLE_H_
#define _COLLECTIBLE_H_
#include <QuestEngine/Shape.h>
#include "Grid.h"
class Collectible
{
public:
	Collectible(int caseIndexX, int caseIndexY, float red, float green, float blue, float halfSize, const Grid* const grid);
	void Draw();
	void SetCaseIndex(int caseIndexX, int caseIndexY);
	int GetCaseIndexX();
	int GetCaseIndexY();

private:
	Shader* m_collectibleShader;
	Shape* m_collectibleShape;
	int m_lastIndexCaseX = 0.0f;
	int m_lastIndexCaseY = 0.0f;

	int m_indexCaseX = 0.0f;
	int m_indexCaseY = 0.0f;
	const Grid* m_grid;
};


#endif // !_COLLECTIBLE_H_


