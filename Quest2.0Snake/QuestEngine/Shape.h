#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <glad/glad.h>
#include "Shader.h"

enum class GLDrawType
{
	GLSTREAM_DRAW = 0x88E0,
	GLSTATIC_DRAW = 0x88E4,
	GLDYNAMIC_DRAW = 0x88E8
};

enum class ShapeType
{
	TRIANGLE = 0x0004,
	Line = 0x0001
};

class Shape
{
public :
	Shape();
	Shape(Shader* shader, GLDrawType glDrawType, int verticesCount, float* vertices, int indicesCount, unsigned int* indices, ShapeType shapeType = ShapeType::TRIANGLE, bool enableWireframe = false);
	~Shape();
	static Shape* CreateTriangle(Shader* shader, GLDrawType glDrawType,
		float x1, float y1, float z1,
		float x2, float y2, float z2,
		float x3, float y3, float z3, bool enableWireframe = false);

	static Shape* CreateRectangle(float posX, float posY, Shader* shader, GLDrawType glDrawType,
		float width, float height, bool enableWireframe = false);

	static Shape* CreateRegularConvexPolygon(float posX, float posY, Shader* shader, GLDrawType glDrawType, int sideCount, float radius, bool enableWireframe = false);
	static Shape* CreateCircle(float posX, float posY, Shader* shader, GLDrawType glDrawType, float radius, bool enableWireframe = false);
	static Shape* CreateGrid(float posX, float posY, Shader* shader, GLDrawType glDrawType, float width, float height, int widthTileCount, int heightTileCount, bool enableWireframe = false);
	void Draw();
	void Move(float deltaX, float deltaY);


private :
	GLuint m_vbo = 0;
	GLuint m_ebo = 0;
	GLDrawType m_glDrawType = GLDrawType::GLSTATIC_DRAW;
	ShapeType m_shapeType = ShapeType::TRIANGLE;
	Shader* m_shader = nullptr;
	float* m_vertices = nullptr;
	unsigned int* m_indices = nullptr;
	int m_verticesCount = 0;
	int m_indicesCount = 0;
	bool m_enableWireframe = false;
	int m_shapeTypeCount = 1;
	void ConfigureVBO(int verticesSizeof,float vertices[]);
	void ConfigureEBO(int indicesSizeof, unsigned int indices[]);
};

#endif // !_SHAPE_H_



