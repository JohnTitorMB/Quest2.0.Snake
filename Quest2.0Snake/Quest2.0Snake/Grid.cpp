#include "Grid.h"
#include "ShaderUtils.h"
#include <assert.h>    

Grid::Grid(float posX, float posY, float width, float height, int tileXCount, int tileYCount, float red, float green, float blue)
{
	if (tileXCount == 0)
		tileXCount = 1;

	if (tileYCount == 0)
		tileYCount = 1;

	const char* GridfragmentShaderSource = ShaderUtils::GenereFragmentShaderWithColor(red, green, blue);

	m_gridShader = new Shader(ShaderUtils::GetDefaultVertesShader(), GridfragmentShaderSource);
	m_gridShape = Shape::CreateGrid(posX, posY, m_gridShader, GLDrawType::GLSTATIC_DRAW, width, height, tileXCount, tileYCount);
	
	m_posX = posX;
	m_posY = posY;
	m_height = height;
	m_width = width;
	m_tileXCount = tileXCount;
	m_tileYCount = tileYCount;	

	m_tileXSize = m_width / m_tileXCount;
	m_tileYSize = m_height / m_tileYCount;
}

Grid::~Grid()
{
	if (m_gridShader != nullptr)
	{
		delete m_gridShader;
		m_gridShader = nullptr;
	}

	if (m_gridShape != nullptr)
	{
		delete m_gridShape;
		m_gridShape = nullptr;
	}
}

float Grid::GetPosXAt(int indexX, bool outsideGrid) const
{
	if (!outsideGrid && (indexX < 0 || indexX >= m_tileXCount))
	{
		assert("indeX is outside of grid");
	}
	float firstCaseX = m_posX - m_width / 2.0f + m_tileXSize / 2.0f;
	return firstCaseX + m_tileXSize * indexX;
}

float Grid::GetPosYAt(int indexY, bool outsideGrid) const
{
	if (!outsideGrid && (indexY < 0 || indexY >= m_tileYCount))
	{
		assert("indeX is outside of grid");
	}
	float firstCaseY = m_posY - m_height / 2.0f + m_tileYSize / 2.0f;
	return firstCaseY + m_tileXSize * indexY;
}

int Grid::GetTileXCount() const
{
	return m_tileXCount;
}

int Grid::GetTileYCount() const
{
	return m_tileYCount;
}

float Grid::GetTileXSize() const
{
	return m_tileXSize;
}

float Grid::GetTileYSize() const
{
	return m_tileYSize;
}

void Grid::Draw()
{
	m_gridShape->Draw();
}