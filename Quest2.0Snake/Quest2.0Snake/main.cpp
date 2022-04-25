/*
This project was make in the channel "Les quete d'un programmeur" context. 
The explanation video (in french) is avaible in this youtube channel and here is code name : Quest #2.0
*/


/* Include */
#include <iostream>
#include "QuestEngine/Window.h"
#include "QuestEngine/Shape.h"
#include "QuestEngine/Shader.h"
#include "ShaderUtils.h"
#include "Input.h"
#include "Snake.h"
#include "Grid.h"
#include <chrono>
#include <algorithm>
#include "Collectible.h"
#include "SnakeConfig.h"
#include "Text.h"

/*-------------------------------------------------Typedef-------------------------------------------*/
typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<float> fsec;

/*-------------------------------------------Global variable-------------------------------------------*/

Collectible* collectible;
Snake* snake;
Grid* grid;
Text* scoreText;
int score = 0;

#include <iomanip>
#include <sstream>

/*-------------------------------------------Global method-------------------------------------------*/

void ComputeCollectibleRandomPosition()
{
	int emptyCaseCount = grid->GetTileXCount() * grid->GetTileYCount() - snake->GetSnakeSize();
	int randomGridIndex = std::rand() % emptyCaseCount;

	SnakeCase s = snake->GetSnakeCaseInEmptyIndex(randomGridIndex);
	collectible->SetCaseIndex(s.caseIndexX, s.caseIndexY);
}

void OnSnakeMove(Snake* snake, int newCaseIndexX, int newCaseIndexY)
{	


}

void UpdateScoreText()
{
	std::stringstream stream;
	stream << std::setfill('0') << std::setw(5) << score;

	const std::string str = stream.str();
	const char* cstr = str.c_str();
	scoreText->SetText((char*)cstr, strlen(cstr));
}

void ResetGame()
{
	snake->Reset((int)(grid->GetTileXCount() / 2.0f), (int)(grid->GetTileYCount() / 2.0f));
	score = 0;
	UpdateScoreText();
}

void OnSnakeDeath(Snake* snake)
{
	ResetGame();
	ComputeCollectibleRandomPosition();
}

void OnSnakeMoved(Snake* snake, int newCaseIndexX, int newCaseIndexY)
{
	//Check if headSnake is above collectible
	if (newCaseIndexX == collectible->GetCaseIndexX() && newCaseIndexY == collectible->GetCaseIndexY())
	{
		score += SnakeConfig::PointByCollectible;

		UpdateScoreText();

		if (!snake->GrowUp())
			ResetGame();
		else
			ComputeCollectibleRandomPosition();
	}
}

/*------------------------------------------------Main Method---------------------------------------------*/
int main()
{
	/*-------------------------------------------Create Window---------------------------------------------*/
	Window* window = new Window(500, 500, new char[] {"Snake"});

	/*--------------------------------------------Create Input--------------------------------------------*/
	Input* m_input = new Input();

	/*------------------------------------------Initialise Grid -------------------------------------------*/
	int gridTileCountY = SnakeConfig::GridTileXCount * SnakeConfig::GridTileYCountRatio;
	float gridWidth = 2.0f;
	float gridHeight = gridWidth / SnakeConfig::GridTileXCount * gridTileCountY;
	float gridTileSize = gridWidth / SnakeConfig::GridTileXCount;
	float gridPosX = 0.0f;
	float gridPosY = -1.0f + gridHeight / 2.0f;
	grid = new Grid(gridPosX, gridPosY, gridWidth - gridTileSize*2.0f, gridHeight- gridTileSize * 2.0f, SnakeConfig::GridTileXCount-2, gridTileCountY-2, SnakeConfig::GridRColor, SnakeConfig::GridGColor, SnakeConfig::GridBColor);

	/*------------------------------------------Initialise Snake ------------------------------------------*/
	int snakeSize = 4;
	int maxSnakeSize = 100;
	float durationToMoveSnake = 0.25f;
	snake = new Snake((int)(grid->GetTileXCount() / 2.0f), (int)(grid->GetTileYCount() / 2.0f), grid->GetTileXSize(),
		SnakeConfig::SnakeRColor, SnakeConfig::SnakeGColor, SnakeConfig::SnakeBColor, 
		snakeSize, maxSnakeSize, durationToMoveSnake, grid, m_input);

	snake->OnMoveEvent = &OnSnakeMove;
	snake->OnMovedEvent = &OnSnakeMoved;
	snake->OnDeathEvent = &OnSnakeDeath;

	/*-----------------------------------------Initialise Wall --------------------------------------------*/
	const char* WallfragmentShaderSource = ShaderUtils::GenereFragmentShaderWithColor(SnakeConfig::WallRColor,
		SnakeConfig::WallGColor,
		SnakeConfig::WallBColor);

	Shader* shaderWall = new Shader(ShaderUtils::GetDefaultVertesShader(), WallfragmentShaderSource);

	float firstCaseX = grid->GetPosXAt(0) - grid->GetTileXSize();
	float firstCaseY = grid->GetPosYAt(0) - grid->GetTileYSize();

	float endCaseX = grid->GetPosXAt(grid->GetTileXCount() - 1) + grid->GetTileXSize();
	float endCaseY = grid->GetPosYAt(grid->GetTileYCount() - 1) + grid->GetTileYSize();

	Shape* rightWall = Shape::CreateRectangle(endCaseX, gridPosY, shaderWall, GLDrawType::GLSTATIC_DRAW, grid->GetTileXSize(), gridHeight);
	Shape* leftWall = Shape::CreateRectangle(firstCaseX, gridPosY, shaderWall, GLDrawType::GLSTATIC_DRAW, grid->GetTileXSize(), gridHeight);
	Shape* downWall = Shape::CreateRectangle(gridPosX, firstCaseY, shaderWall, GLDrawType::GLSTATIC_DRAW, gridWidth, grid->GetTileXSize());
	Shape* topWall = Shape::CreateRectangle(gridPosX, endCaseY, shaderWall, GLDrawType::GLSTATIC_DRAW, gridWidth, grid->GetTileXSize());

	/*-------------------------------------------Initialise Score-------------------------------------------*/
	char* textChar = (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789";
	//textChar = (char*)"AB";
	scoreText = new Text(textChar, strlen(textChar), 0.05f, 0.015f);
	scoreText->SetTextPosition(0.0f, 0.7f);
	UpdateScoreText();

	/*--------------------------------------------Initialise Collectible-------------------------------------*/
	collectible = new Collectible(0, 0, SnakeConfig::CollectibleRColor, SnakeConfig::CollectibleGColor, SnakeConfig::CollectibleBColor, grid->GetTileXSize() / 2.0f * SnakeConfig::CollectibleTileRatio, grid);
	collectible->SetCaseIndex((int)(grid->GetTileXCount() / 2.0f) + 1, (int)(grid->GetTileYCount() / 2.0f));
	srand(time(NULL));
	ComputeCollectibleRandomPosition();

	/*-------------------------------------------Initialise TIme-------------------------------------------*/
	auto t0 = Time::now();
	auto t1 = Time::now();

	/*------------------------------------------Game Engine Loop-------------------------------------------*/
	while (!glfwWindowShouldClose(window->GetWindow()))
	{
		//Compute timeand deltatime
		auto t2 = Time::now();
		fsec delta = t2 - t1;
		fsec fs = t2 - t0;
		t1 = t2;		

		//Check input and Update snake (move and event call)
		m_input->CheckInput(window);
		snake->Update(delta.count());
		
		//Clear screen
		glClearColor(SnakeConfig::BackgroundRColor, SnakeConfig::BackgroundGColor , SnakeConfig::BackgroundBColor, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		//Draw all Element on sreen
		scoreText->DrawText();
		grid->Draw();
		snake->Draw();
		collectible->Draw();
		rightWall->Draw();
		leftWall->Draw();
		downWall->Draw();
		topWall->Draw();
		
		//Glfw frame end method
		glfwSwapBuffers(window->GetWindow());
		glfwPollEvents();
	}

	/*------------------------------------Memory Deallocation----------------------------------------------*/
	delete grid;
	grid = nullptr;

	delete rightWall;
	rightWall = nullptr;

	delete leftWall;
	leftWall = nullptr;

	delete topWall;
	topWall = nullptr;

	delete downWall;
	downWall = nullptr;

	delete snake;
	snake = nullptr;

	delete shaderWall;
	shaderWall = nullptr;

	delete collectible;
	collectible = nullptr;

	delete window;
	window = nullptr;

	delete scoreText;
	scoreText = nullptr;

	return 0;
}