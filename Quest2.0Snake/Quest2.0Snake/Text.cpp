#include "Text.h"
#include "ShaderUtils.h"

CharacterContainer** Text::m_charactersContainer;
Text::Text(char* text, int length, float characterSize, float spacing)
{
	if (m_charactersContainer == nullptr)
	{
		m_charactersContainer = new CharacterContainer * [36];
		for (int i = 0; i < 36; i++)
		{
			m_charactersContainer[i] = nullptr;
		}
	}

	m_text = _strdup(text);
	m_length = length;

	const char* fragmentShaderSource = ShaderUtils::GenereFragmentShaderWithColor(0.0f,
		0.0f,
		0.0f);
	m_spacing = spacing;
	m_shader = new Shader(ShaderUtils::GetDefaultVertesShader(), fragmentShaderSource);
	m_characterSize = characterSize;
	ParseText();
}

CharacterContainer::CharacterContainer(Shape* shape)
{
	m_shape = shape;
}

Shape* CharacterContainer::GetShape() const
{
	return m_shape;
}

Text::~Text()
{
	if(m_text != nullptr)
		delete m_text;

	 m_text = nullptr;
}

void Text::SetText(char* text, int length)
{
	m_text = _strdup(text);
	m_length = length;

	ParseText();
}

void Text::ParseText()
{
	for (int i = 0; i < m_length; i++)
	{
		switch (m_text[i])
		{
			case 'A' :
				if (m_charactersContainer[0] == nullptr)
					m_charactersContainer[0] = new CharacterContainer(ComputeCharacterA());
			break;

			case 'B':
				if (m_charactersContainer[1] == nullptr)
					m_charactersContainer[1] = new CharacterContainer(ComputeCharacterB());
				break;

			case 'C':
				if (m_charactersContainer[2] == nullptr)
					m_charactersContainer[2] = new CharacterContainer(ComputeCharacterC());
				break;

			case 'D':
				if (m_charactersContainer[3] == nullptr)
					m_charactersContainer[3] = new CharacterContainer(ComputeCharacterD());
				break;

			case 'E':
				if (m_charactersContainer[4] == nullptr)
					m_charactersContainer[4] = new CharacterContainer(ComputeCharacterE());
				break;

			case 'F':
				if (m_charactersContainer[5] == nullptr)
					m_charactersContainer[5] = new CharacterContainer(ComputeCharacterF());
				break;

			case 'G':
				if (m_charactersContainer[6] == nullptr)
					m_charactersContainer[6] = new CharacterContainer(ComputeCharacterG());
				break;

			case 'H':
				if (m_charactersContainer[7] == nullptr)
					m_charactersContainer[7] = new CharacterContainer(ComputeCharacterH());
				break;

			case 'I':
				if (m_charactersContainer[8] == nullptr)
					m_charactersContainer[8] = new CharacterContainer(ComputeCharacterI());
				break;

			case 'J':
				if (m_charactersContainer[9] == nullptr)
					m_charactersContainer[9] = new CharacterContainer(ComputeCharacterJ());
				break;

			case 'K':
				if (m_charactersContainer[10] == nullptr)
					m_charactersContainer[10] = new CharacterContainer(ComputeCharacterK());
				break;

			case 'L':
				if (m_charactersContainer[11] == nullptr)
					m_charactersContainer[11] = new CharacterContainer(ComputeCharacterL());
				break;

			case 'M':
				if (m_charactersContainer[12] == nullptr)
					m_charactersContainer[12] = new CharacterContainer(ComputeCharacterM());
				break;

			case 'N':
				if (m_charactersContainer[13] == nullptr)
					m_charactersContainer[13] = new CharacterContainer(ComputeCharacterN());
				break;

			case 'O':
				if (m_charactersContainer[14] == nullptr)
					m_charactersContainer[14] = new CharacterContainer(ComputeCharacterO());
				break;

			case 'P':
				if (m_charactersContainer[15] == nullptr)
					m_charactersContainer[15] = new CharacterContainer(ComputeCharacterP());
				break;
			case 'Q':
				if (m_charactersContainer[16] == nullptr)
					m_charactersContainer[16] = new CharacterContainer(ComputeCharacterQ());
				break;

			case 'R':
				if (m_charactersContainer[17] == nullptr)
					m_charactersContainer[17] = new CharacterContainer(ComputeCharacterR());
				break;

			case 'S':
				if (m_charactersContainer[18] == nullptr)
					m_charactersContainer[18] = new CharacterContainer(ComputeCharacterS());
				break;

			case 'T':
				if (m_charactersContainer[19] == nullptr)
					m_charactersContainer[19] = new CharacterContainer(ComputeCharacterT());
				break;

			case 'U':
				if (m_charactersContainer[20] == nullptr)
					m_charactersContainer[20] = new CharacterContainer(ComputeCharacterU());
				break;

			case 'V':
				if (m_charactersContainer[21] == nullptr)
					m_charactersContainer[21] = new CharacterContainer(ComputeCharacterV());
				break;

			case 'W':
				if (m_charactersContainer[22] == nullptr)
					m_charactersContainer[22] = new CharacterContainer(ComputeCharacterW());
				break;

			case 'X':
				if (m_charactersContainer[23] == nullptr)
					m_charactersContainer[23] = new CharacterContainer(ComputeCharacterX());
				break;


			case 'Y':
				if (m_charactersContainer[24] == nullptr)
					m_charactersContainer[24] = new CharacterContainer(ComputeCharacterY());
				break;

			case 'Z':
				if (m_charactersContainer[25] == nullptr)
					m_charactersContainer[25] = new CharacterContainer(ComputeCharacterZ());
				break;

			case '0':
				if (m_charactersContainer[26] == nullptr)
					m_charactersContainer[26] = new CharacterContainer(ComputeCharacter0());
				break;

			case '1':
				if (m_charactersContainer[27] == nullptr)
					m_charactersContainer[27] = new CharacterContainer(ComputeCharacter1());
				break;

			case '2':
				if (m_charactersContainer[28] == nullptr)
					m_charactersContainer[28] = new CharacterContainer(ComputeCharacter2());
				break;

			case '3':
				if (m_charactersContainer[29] == nullptr)
					m_charactersContainer[29] = new CharacterContainer(ComputeCharacter3());
				break;

			case '4':
				if (m_charactersContainer[30] == nullptr)
					m_charactersContainer[30] = new CharacterContainer(ComputeCharacter4());
				break;

			case '5':
				if (m_charactersContainer[31] == nullptr)
					m_charactersContainer[31] = new CharacterContainer(ComputeCharacter5());
				break;

			case '6':
				if (m_charactersContainer[32] == nullptr)
					m_charactersContainer[32] = new CharacterContainer(ComputeCharacter6());
				break;

			case '7':
				if (m_charactersContainer[33] == nullptr)
					m_charactersContainer[33] = new CharacterContainer(ComputeCharacter7());
				break;

			case '8':
				if (m_charactersContainer[34] == nullptr)
					m_charactersContainer[34] = new CharacterContainer(ComputeCharacter8());
				break;

			case '9':
				if (m_charactersContainer[35] == nullptr)
					m_charactersContainer[35] = new CharacterContainer(ComputeCharacter9());
				break;

			default:
			break;
		}
	}
}


void Text::SetTextPosition(float posX, float posY)
{
	m_posX = posX;
	m_posY = posY;
}

/// <summary>
/// Get x relative position of character tile grid (width : 5 tile and heigh : 5 tile)
/// </summary>
/// <param name="tileX"> relative tile x index</param>
/// <returns></returns>
float Text::GetX(int tileX)
{
	//return -2.5f + tileX * 0.1f;
	return -m_characterSize / 2.0f + tileX * m_characterSize/5.0f;
}
/// <summary>
/// //Get y relative position of character tile grid (width : 5 tile and heigh : 5 tile)
/// </summary>
/// <param name="tileY">relative tile y index</param>
/// <returns></returns>
float Text::GetY(int tileY)
{
	//return -2.5f + tileY * 0.1f;
	return -m_characterSize / 2.0f + tileY * m_characterSize/5.0f;
}

int Text::GetCharacterIndex(char c)
{
	switch (c)
	{
		case 'A':
			return 0;

		case 'B':
			return 1;

		case 'C':
			return 2;

		case 'D':
			return 3;

		case 'E':
			return 4;

		case 'F':
			return 5;

		case 'G':
			return 6;

		case 'H':
			return 7;

		case 'I':
			return 8;

		case 'J':
			return 9;

		case 'K':
			return 10;

		case 'L':
			return 11;

		case 'M':
			return 12;

		case 'N':
			return 13;

		case 'O':
			return 14;

		case 'P':
			return 15;

		case 'Q':
			return 16;

		case 'R':
			return 17;

		case 'S':
			return 18;

		case 'T':
			return 19;

		case 'U':
			return 20;

		case 'V':
			return 21;

		case 'W':
			return 22;

		case 'X':
			return 23;

		case 'Y':
			return 24;

		case 'Z':
			return 25;

		case '0':
			return 26;

		case '1':
			return 27;

		case '2':
			return 28;

		case '3':
			return 29;

		case '4':
			return 30;

		case '5':
			return 31;

		case '6':
			return 32;

		case '7':
			return 33;

		case '8':
			return 34;

		case '9':
			return 35;

		default:
			return -1;
	}
}

/// <summary>
/// To Draw text we use the same character each times and change position when character occurs
/// </summary>
void Text::DrawText()
{
	for (int i = 0; i < m_length; i++)
	{
		float newPosX = m_posX - (m_characterSize * m_length + (m_length-1) * m_spacing) / 2.0f + m_characterSize / 2.0f + i * m_characterSize + i * m_spacing;

		float newPosY = m_posY;
		int characterIndex = GetCharacterIndex(m_text[i]);
		if (characterIndex != -1 && m_charactersContainer[characterIndex] != nullptr && m_charactersContainer[characterIndex]->GetShape() != nullptr)
		{
			m_charactersContainer[characterIndex]->GetShape()->Move(newPosX - m_charactersContainer[characterIndex]->PosX, newPosY - m_charactersContainer[characterIndex]->PosY);
			m_charactersContainer[characterIndex]->GetShape()->Draw();

			m_charactersContainer[characterIndex]->PosX = newPosX;
			m_charactersContainer[characterIndex]->PosY = newPosY;
		}
	}
}

Shape* Text::ComputeCharacterA()
{
	int verticesCount = 14 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	int widthTileRatio = 0.1f;

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //FirstPoint
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9
	vIndex = 9; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10
	vIndex = 10; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11
	vIndex = 11; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12
	vIndex = 12; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 13
	vIndex = 13; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 14

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 8; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 8; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 3; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 11;// Triangle 6


	tIndex = 6; indices[tIndex * 3] = 13; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 12; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 13; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 7;// Triangle 8

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterB()
{
	int verticesCount = 18 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 6 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 
	vIndex = 12; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 13 
	vIndex = 13; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 14 
	vIndex = 14; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 15 
	vIndex = 15; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 16 
	vIndex = 16; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 17 
	vIndex = 17; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 18 


	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 13; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 12; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 13; indices[tIndex * 3 + 1] = 14; indices[tIndex * 3 + 2] = 4; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 10; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 7; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 17; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 17; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 10

	tIndex = 10; indices[tIndex * 3] = 15; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 11
	tIndex = 11; indices[tIndex * 3] = 15; indices[tIndex * 3 + 1] = 16; indices[tIndex * 3 + 2] = 5; // Triangle 12

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterC()
{
	int verticesCount = 8 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 3 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 


	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 3; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 4; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 4; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 6


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterD()
{
	int verticesCount = 10 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 



	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 3; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 4; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 4; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 9; // Triangle 5
	tIndex = 7; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 9; // Triangle 6

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterE()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 

	vIndex = 8; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 


	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 3; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 4; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 4; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 9; // Triangle 5
	tIndex = 7; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 6


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterF()
{
	int verticesCount = 10 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 3 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 9; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 1; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 6; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 6; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 7; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 6


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterG()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 5 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 7; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 1; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 7; // Triangle 5
	tIndex = 7; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 8; // Triangle 6

	tIndex = 8; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 9; // Triangle 5
	tIndex = 9; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 6


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);

}

Shape* Text::ComputeCharacterH()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 3 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 10; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 8; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 6



	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterI()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 3 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 4; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 6


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterJ()
{
	int verticesCount = 10 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	
	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 8; indices[tIndex + 2] = 7; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 8; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 1; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 5; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 8


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterK()
{
	int verticesCount = 20 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 6 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 
	vIndex = 12; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 13 
	vIndex = 13; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 14 
	vIndex = 14; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 15 
	vIndex = 15; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 16 
	vIndex = 16; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 17 
	vIndex = 17; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 18 
	vIndex = 18; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 19 
	vIndex = 19; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 20 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 18; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 19; indices[tIndex * 3 + 2] = 18; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 17; indices[tIndex * 3 + 2] = 10; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 5; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 6; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 5; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 4; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 9; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 7; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 13; indices[tIndex * 3 + 2] = 11; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 12; indices[tIndex * 3 + 2] = 13; // Triangle 10

	tIndex = 10; indices[tIndex * 3] = 13; indices[tIndex * 3 + 1] = 16; indices[tIndex * 3 + 2] = 14; // Triangle 11
	tIndex = 11; indices[tIndex * 3] = 13; indices[tIndex * 3 + 1] = 15; indices[tIndex * 3 + 2] = 16; // Triangle 12


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterL()
{
	int verticesCount = 6 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 2 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 3; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 4


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterM()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 2; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 7; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 9; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 9; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 6; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 8


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterN()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 5 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 10; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 9; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 7; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 8; // Triangle 6

	tIndex = 8; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 9; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 6


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterO()
{
	int verticesCount = 8 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 3; indices[tIndex + 2] = 2; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 1; indices[tIndex * 3 + 2] = 3; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 2; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 4; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 1; // Triangle 5
	tIndex = 7; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 7; // Triangle 6

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterP()
{
	int verticesCount = 10 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 8; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 8; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 6; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 5; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 3; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 5
	tIndex = 7; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 4; // Triangle 6


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);

}

Shape* Text::ComputeCharacterQ()
{
	int verticesCount = 13 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 6 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 
	vIndex = 12; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 13 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 5; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 5; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 5; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 5; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 7; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 8; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 4; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 9; // Triangle 10

	tIndex = 10; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 12; indices[tIndex * 3 + 2] = 6; // Triangle 11
	tIndex = 11; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 12; // Triangle 12


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);

}

Shape* Text::ComputeCharacterR()
{
	int verticesCount = 16 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 6 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 

	vIndex = 10; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11
	vIndex = 11; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 
	vIndex = 12; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 13 
	vIndex = 13; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 14 
	vIndex = 14; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 15 
	vIndex = 15; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 16 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 8; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 8; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 6; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 5; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 3; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 4; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 15; indices[tIndex * 3 + 2] = 14; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 15; // Triangle 10

	tIndex = 10; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 13; indices[tIndex * 3 + 2] = 12; // Triangle 11
	tIndex = 11; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 14; indices[tIndex * 3 + 2] = 13; // Triangle 12


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterS()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 5 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 10; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 9; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 4; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 10

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterT()
{
	int verticesCount = 8 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 2 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(2); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 4

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterU()
{
	int verticesCount = 8 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 3 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 4; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 6

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterV()
{
	int verticesCount = 14 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 5 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(1); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 

	vIndex = 10; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 
	vIndex = 12; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 13 
	vIndex = 13; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 14 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 6; indices[tIndex + 2] = 5; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 8; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 9; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 13; indices[tIndex * 3 + 2] = 7; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 12; indices[tIndex * 3 + 2] = 13; // Triangle 10


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterW()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 4; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 4; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 9; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 8

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterX()
{
	int verticesCount = 28 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 9 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11
	vIndex = 11; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 
	vIndex = 12; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 13
	vIndex = 13; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 14
	vIndex = 14; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 15 
	vIndex = 15; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 16 
	vIndex = 16; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 17 
	vIndex = 17; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 18 
	vIndex = 18; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 19
	vIndex = 19; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 20 
	vIndex = 20; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 21
	vIndex = 21; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 22 
	vIndex = 22; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 23 
	vIndex = 23; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 24 
	vIndex = 24; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 25 
	vIndex = 25; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 26 
	vIndex = 26; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 27 
	vIndex = 27; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 28 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 3; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 3; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 4; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 3; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 6; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 7; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 9; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 12; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 11; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 14; indices[tIndex * 3 + 1] = 13; indices[tIndex * 3 + 2] = 15; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 14; indices[tIndex * 3 + 1] = 12; indices[tIndex * 3 + 2] = 13; // Triangle 10

	tIndex = 10; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 18; indices[tIndex * 3 + 2] = 16; // Triangle 7
	tIndex = 11; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 17; indices[tIndex * 3 + 2] = 18; // Triangle 8

	tIndex = 12; indices[tIndex * 3] = 18; indices[tIndex * 3 + 1] = 21; indices[tIndex * 3 + 2] = 19; // Triangle 9
	tIndex = 13; indices[tIndex * 3] = 18; indices[tIndex * 3 + 1] = 20; indices[tIndex * 3 + 2] = 21; // Triangle 10

	tIndex = 14; indices[tIndex * 3] = 22; indices[tIndex * 3 + 1] = 24; indices[tIndex * 3 + 2] = 8; // Triangle 7
	tIndex = 15; indices[tIndex * 3] = 22; indices[tIndex * 3 + 1] = 23; indices[tIndex * 3 + 2] = 24; // Triangle 8

	tIndex = 16; indices[tIndex * 3] = 25; indices[tIndex * 3 + 1] = 27; indices[tIndex * 3 + 2] = 23; // Triangle 9
	tIndex = 17; indices[tIndex * 3] = 25; indices[tIndex * 3 + 1] = 26; indices[tIndex * 3 + 2] = 27; // Triangle 10

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterY()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 10; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 9; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 8

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacterZ()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 5 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 4; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 6; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 9; // Triangle 7
	tIndex = 9; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 8

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter0()
{
	int verticesCount = 14 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 7 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11
	vIndex = 11; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 
	vIndex = 12; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 13
	vIndex = 13; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 14 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 10; indices[tIndex + 2] = 4; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 4; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 5; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 5; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 5; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 6; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 7; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 2; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 8; // Triangle 7
	tIndex = 9; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 8

	tIndex = 10; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 10; // Triangle 9
	tIndex = 11; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 9; // Triangle 10

	tIndex = 12; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 12; // Triangle 11
	tIndex = 13; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 13; indices[tIndex * 3 + 2] = 7; // Triangle 12


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter1()
{
	int verticesCount = 10 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 7 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(3); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 4; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 7; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 6


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter2()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 5 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 4; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 6; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 9; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 10


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter3()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 10; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 5; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 9; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 8


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter4()
{
	int verticesCount = 10 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 3 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(2); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 8; indices[tIndex + 2] = 7; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 8; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 2; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 4; // Triangle 6

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter5()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 5 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 10; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 10; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 9; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 3; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 4; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 10


	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter6()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	//int indicesCount = 4*3;
	int indicesCount = 6 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 9; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 9; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 10; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 11; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 8; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 4; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 5; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 10

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter7()
{
	int verticesCount = 10 * 3;
	float* vertices = new float[verticesCount];

	int indicesCount = 3 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(4); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(2); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 5; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 5; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 9; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 8; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 6; // Triangle 6

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter8()
{
	int verticesCount = 12 * 3;
	float* vertices = new float[verticesCount];

	int indicesCount = 5 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(0); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(1); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 
	vIndex = 10; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 11 
	vIndex = 11; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 12 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 5; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 4; indices[tIndex * 3 + 2] = 5; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 5; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 1; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 5; indices[tIndex * 3 + 1] = 11; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 11; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 10; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 10; indices[tIndex * 3 + 2] = 4; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 10; // Triangle 8

	tIndex = 8; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 7; // Triangle 9
	tIndex = 9; indices[tIndex * 3] = 6; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 9; // Triangle 10

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);
}

Shape* Text::ComputeCharacter9()
{
	int verticesCount = 10 * 3;
	float* vertices = new float[verticesCount];

	int indicesCount = 4 * 2 * 3;
	unsigned int* indices = new unsigned int[indicesCount];

	//VerticesDefinition
	int vIndex = 0;
	vertices[vIndex] = GetX(4); vertices[vIndex + 1] = GetY(0); vertices[vIndex + 2] = 0.0f; //Vertice 1
	vIndex = 1; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(0); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 2 
	vIndex = 2; vertices[vIndex * 3] = GetX(5); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 3 
	vIndex = 3; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(5); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 4 
	vIndex = 4; vertices[vIndex * 3] = GetX(0); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 5 
	vIndex = 5; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(2); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 6 
	vIndex = 6; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 7 
	vIndex = 7; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(3); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 8 
	vIndex = 8; vertices[vIndex * 3] = GetX(4); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 9 
	vIndex = 9; vertices[vIndex * 3] = GetX(1); vertices[vIndex * 3 + 1] = GetY(4); vertices[vIndex * 3 + 2] = 0.0f; // Vertice 10 

	//IndicesDefinition
	int tIndex = 0;
	indices[tIndex] = 0; indices[tIndex + 1] = 2; indices[tIndex + 2] = 1; // Triangle 1
	tIndex = 1; indices[tIndex * 3] = 0; indices[tIndex * 3 + 1] = 8; indices[tIndex * 3 + 2] = 2; // Triangle 2

	tIndex = 2; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 2; indices[tIndex * 3 + 2] = 8; // Triangle 3
	tIndex = 3; indices[tIndex * 3] = 9; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 2; // Triangle 4

	tIndex = 4; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 9; indices[tIndex * 3 + 2] = 6; // Triangle 5
	tIndex = 5; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 3; indices[tIndex * 3 + 2] = 9; // Triangle 6

	tIndex = 6; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 7; indices[tIndex * 3 + 2] = 5; // Triangle 7
	tIndex = 7; indices[tIndex * 3] = 4; indices[tIndex * 3 + 1] = 6; indices[tIndex * 3 + 2] = 7; // Triangle 8

	return new Shape(m_shader, GLDrawType::GLDYNAMIC_DRAW, verticesCount, vertices, indicesCount, indices);

}