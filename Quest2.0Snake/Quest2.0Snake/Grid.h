#ifndef _GRID_H_
#define _GRID_H_
#include <QuestEngine/Shape.h>
class Grid
{
public : 
	Grid(float posX, float posY, float width, float height, int tileXCount, int tileYCount, float red, float green, float blue);
	~Grid();
	
	void Draw();
	float GetPosXAt(int indexX, bool outsideGrid = false) const;
	float GetPosYAt(int indexY, bool outsideGrid = false) const;

	int GetTileXCount() const;
	int GetTileYCount() const;

	float GetTileXSize() const;
	float GetTileYSize() const;
private : 
	Shape* m_gridShape = nullptr;
	Shader* m_gridShader = nullptr;
	float m_posX = 0.0f;
	float m_posY = 0.0f;
	float m_width = 0.0f;
	float m_height = 0.0f;
	int m_tileXCount = 1;
	int m_tileYCount = 1;
	float m_tileXSize = 0.0f;
	float m_tileYSize = 0.0f;
};


#endif // !_GRID_H_



