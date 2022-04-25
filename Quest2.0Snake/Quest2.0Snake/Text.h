#ifndef _TEXT_H_
#define _TEXT_H_
#include <QuestEngine/Shape.h>
#include <QuestEngine/Shader.h>
class CharacterContainer
{
	Shape* m_shape = nullptr;
	public :
		CharacterContainer(Shape* shape);
		Shape* GetShape()const;
		float PosX = 0.0f;
		float PosY = 0.0f;
		
};

class Text
{
public :
	Text(char* text, int length, float characterSize, float spacing);	
	~Text();
	void DrawText();
	void SetTextPosition(float posX, float posY);
	void SetText(char* text, int length);

private : 
	static CharacterContainer** m_charactersContainer;
	char* m_text;
	int m_length;
	Shader* m_shader;
	float m_posX = 0.0f;
	float m_posY = 0.0f;
	float m_spacing = 0.0f;	
	float m_characterSize = 0.1f;
	
	float GetX(int tileX);
	float GetY(int tileY);
	void ParseText();
	int GetCharacterIndex(char c);

	Shape* ComputeCharacterA();
	Shape* ComputeCharacterB();
	Shape* ComputeCharacterC();
	Shape* ComputeCharacterD();
	Shape* ComputeCharacterE();
	Shape* ComputeCharacterF();
	Shape* ComputeCharacterG();
	Shape* ComputeCharacterH();
	Shape* ComputeCharacterI();
	Shape* ComputeCharacterJ();
	Shape* ComputeCharacterK();
	Shape* ComputeCharacterL();
	Shape* ComputeCharacterM();
	Shape* ComputeCharacterN();
	Shape* ComputeCharacterO();
	Shape* ComputeCharacterP();
	Shape* ComputeCharacterQ();
	Shape* ComputeCharacterR();
	Shape* ComputeCharacterS();
	Shape* ComputeCharacterT();
	Shape* ComputeCharacterU();
	Shape* ComputeCharacterV();
	Shape* ComputeCharacterW();
	Shape* ComputeCharacterX();
	Shape* ComputeCharacterY();
	Shape* ComputeCharacterZ();
	Shape* ComputeCharacter0();
	Shape* ComputeCharacter1();
	Shape* ComputeCharacter2();
	Shape* ComputeCharacter3();
	Shape* ComputeCharacter4();
	Shape* ComputeCharacter5();
	Shape* ComputeCharacter6();
	Shape* ComputeCharacter7();
	Shape* ComputeCharacter8();
	Shape* ComputeCharacter9();
};

#endif

