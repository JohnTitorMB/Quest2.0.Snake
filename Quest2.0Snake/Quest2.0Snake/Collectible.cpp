#include "Collectible.h"
#include "ShaderUtils.h"

Collectible::Collectible(int caseIndexX, int caseIndexY, float red, float green, float blue, float halfSize, const Grid* const grid)
{
	const char* CollectiblefragmentShaderSource = ShaderUtils::GenereFragmentShaderWithColor(red, green, blue);
	m_collectibleShader = new Shader(ShaderUtils::GetDefaultVertesShader(), CollectiblefragmentShaderSource);
	m_collectibleShape = Shape::CreateCircle(grid->GetPosXAt(caseIndexX,true), grid->GetPosYAt(caseIndexY, true), m_collectibleShader, GLDrawType::GLDYNAMIC_DRAW, halfSize);
	m_grid = grid;

	m_lastIndexCaseX = caseIndexX;
	m_lastIndexCaseY = caseIndexY;

	m_indexCaseX = m_lastIndexCaseX;
	m_indexCaseY = m_lastIndexCaseY;
}

void Collectible::Draw()
{
	if(m_indexCaseX != m_lastIndexCaseX || m_indexCaseY != m_lastIndexCaseY)
		m_collectibleShape->Move((m_indexCaseX - m_lastIndexCaseX) * m_grid->GetTileXSize()
							   , (m_indexCaseY - m_lastIndexCaseY)* m_grid->GetTileYSize());

	m_lastIndexCaseX = m_indexCaseX;
	m_lastIndexCaseY = m_indexCaseY;

	m_collectibleShape->Draw();
}

void Collectible::SetCaseIndex(int caseIndexX, int caseIndexY)
{
	m_indexCaseX = caseIndexX;
	m_indexCaseY = caseIndexY;
}

int Collectible::GetCaseIndexX()
{
	return m_indexCaseX;
}

int Collectible::GetCaseIndexY()
{
	return m_indexCaseY;
}

void SetRandomPosition()
{

}