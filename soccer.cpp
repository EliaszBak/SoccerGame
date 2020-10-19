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
    FillRect(iPlayerOneStartPosX, iPlayerOneStartPosY, iPlayerSize, iPlayerSize, olc::BLACK);
    FillCircle(vBall, 20, olc::WHITE);
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
    {
        std::cout << "fPlayer speed equals: " << fPlayerSPeed << std::endl;
        std::cout <<"Current elapsedTime is: "<< fElapsedTime << std::endl;
        std::cout << "Speed times time equals: "<<fPlayerSPeed * fElapsedTime << std::endl;
        iPlayerOneStartPosX -= (fPlayerSPeed * fElapsedTime);
    }
    if (GetKey(olc::Key::RIGHT).bHeld) 
    {
        std::cout << "fPlayer speed equals: " << fPlayerSPeed << std::endl;
        std::cout <<"Current elapsedTime is: "<< fElapsedTime << std::endl;
        std::cout << "Speed times time equals: "<<fPlayerSPeed * fElapsedTime << std::endl;
        iPlayerOneStartPosX = iPlayerOneStartPosX + (fPlayerSPeed * fElapsedTime);
    }
    if (GetKey(olc::Key::UP).bHeld) iPlayerOneStartPosY -= fPlayerSPeed;
	if (GetKey(olc::Key::DOWN).bHeld) iPlayerOneStartPosY += fPlayerSPeed;

    if (iPlayerOneStartPosX < 11.0f) iPlayerOneStartPosX = 11.0f;
    if (iPlayerOneStartPosX + iPlayerSize > 709.0f) iPlayerOneStartPosX = 709.0f - iPlayerSize;
}