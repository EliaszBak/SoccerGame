#define OLC_PGE_APPLICATION

#include "soccer.hpp"


SoccerGame::SoccerGame()
{
	sAppName = "SoccerGameGame";
}

bool SoccerGame::OnUserCreate() 
{        

    return true;
}

bool SoccerGame::OnUserUpdate(float fElapsedTime)
{
    handlePlayerOneMovement(fElapsedTime);
    Clear(olc::DARK_GREEN);
    drawField();
    drawPlayerOne();
	return true;
}

void SoccerGame::drawField()
{
    // upper line
    DrawLine(10, 10, 280, 10, olc::WHITE);
    DrawLine(440, 10, 710, 10, olc::WHITE);

    //left line
    DrawLine(10, 10, 10, 1010, olc::WHITE);
            
    //right line
    DrawLine(710, 1010, 710, 10, olc::WHITE);

    //bottom line
    DrawLine(10, 1010, 280, 1010, olc::WHITE);
    DrawLine(440, 1010, 710, 1010, olc::WHITE);

    //mid line
    DrawLine(10, 505, 710, 505, olc::WHITE);
    DrawCircle({355, 505}, 100);
}

void SoccerGame::handlePlayerOneMovement(float fElapsedTime)
{
    if (GetKey(olc::Key::LEFT).bHeld)
        fPlayerOneStartPosX -= (fPlayerSPeed * fElapsedTime);
    if (GetKey(olc::Key::RIGHT).bHeld)
        fPlayerOneStartPosX += (fPlayerSPeed * fElapsedTime);
    if (GetKey(olc::Key::UP).bHeld)
        fPlayerOneStartPosY -= fPlayerSPeed * fElapsedTime;
	if (GetKey(olc::Key::DOWN).bHeld)
        fPlayerOneStartPosY += fPlayerSPeed * fElapsedTime;

    if (fPlayerOneStartPosX < 11.0f)
        fPlayerOneStartPosX = 11.0f;
    if (fPlayerOneStartPosX + fPlayerSize > 709.0f)
        fPlayerOneStartPosX = 709.0f - fPlayerSize;
    if (fPlayerOneStartPosY < 11.0f) 
        fPlayerOneStartPosY = 11.0f;
    if (fPlayerOneStartPosY + fPlayerSize >1013.0f)
        fPlayerOneStartPosY = 1013.0f - fPlayerSize;


}

void SoccerGame::drawPlayerOne()
{
    FillRect(fPlayerOneStartPosX, fPlayerOneStartPosY, fPlayerSize, fPlayerSize, olc::BLACK);
}

void SoccerGame::drawBall()
{
    FillCircle(vBall, 20, olc::WHITE);
}