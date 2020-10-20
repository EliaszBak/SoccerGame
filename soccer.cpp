#define OLC_PGE_APPLICATION

#include "soccer.hpp"


SoccerGame::SoccerGame()
{
	sAppName = "SoccerGameGame";
}

bool SoccerGame::OnUserCreate() 
{        
	fPlayerSize = { ScreenWidth() / 10.0f };  // 60x60 as for now player is a square
	fPlayerSPeed = { ScreenHeight()/ 2.5f }; //pixels per sec
	fBallSize = { ScreenWidth() / 20.0f };

	vPlayerOnePos = { ScreenWidth() / 2.0f, ScreenHeight() - (ScreenHeight() / 10.0f) };
	vPlayerTwoPos = { 325.0f, 150.0f };
	vBall = { ScreenWidth()/2.0f, ScreenHeight()/2.0f };
	
    return true;
}

bool SoccerGame::OnUserUpdate(float fElapsedTime)
{
    handlePlayerOneMovement(fElapsedTime);
    Clear(olc::DARK_GREEN);
    drawField();
    drawPlayerOne();
	drawBall();
	ScreenHeight();
	return true;
}

void SoccerGame::drawField()
{
    // upper line
    DrawLine(10, 10, (ScreenWidth()/2 - ScreenWidth()/10), 10, olc::WHITE);
    DrawLine((ScreenWidth() / 2 + ScreenWidth() / 10),
		10, ScreenWidth() - 10, 10, olc::WHITE);

    //left line
    DrawLine(10, 10, 10, ScreenHeight() - 10, olc::WHITE);
            
    //right line
    DrawLine(ScreenWidth() - 10, ScreenHeight() - 10, ScreenWidth() -10, 10, olc::WHITE);

    //bottom line
    DrawLine(10, ScreenHeight() - 10, (ScreenWidth() / 2 - ScreenWidth() / 10), ScreenHeight() - 10, olc::WHITE);
    DrawLine((ScreenWidth() / 2 + ScreenWidth() / 10), ScreenHeight() - 10, ScreenWidth() -10,
		ScreenHeight() - 10, olc::WHITE);

    //mid line
    DrawLine(10, ScreenHeight()/2, ScreenWidth() -10, ScreenHeight()/2, olc::WHITE);
    DrawCircle({ScreenWidth()/2, ScreenHeight()/2}, 100);
}

void SoccerGame::handlePlayerOneMovement(float fElapsedTime)
{
    if (GetKey(olc::Key::LEFT).bHeld)
		vPlayerOnePos.x -= (fPlayerSPeed * fElapsedTime);
    if (GetKey(olc::Key::RIGHT).bHeld)
        vPlayerOnePos.x += (fPlayerSPeed * fElapsedTime);
    if (GetKey(olc::Key::UP).bHeld)
        vPlayerOnePos.y -= fPlayerSPeed * fElapsedTime;
	if (GetKey(olc::Key::DOWN).bHeld)
        vPlayerOnePos.y += fPlayerSPeed * fElapsedTime;

    if (vPlayerOnePos.x - fPlayerSize < 11.0f)
        vPlayerOnePos.x = 11.0f + fPlayerSize;
    if (vPlayerOnePos.x + fPlayerSize > ScreenWidth() - 11.0f)
        vPlayerOnePos.x = ScreenWidth() - 11.0f - fPlayerSize;

    if (vPlayerOnePos.y - fPlayerSize < 11.0f)
        vPlayerOnePos.y = 11.0f + fPlayerSize;
    if (vPlayerOnePos.y + fPlayerSize > ScreenHeight() -11.0f)
        vPlayerOnePos.y = ScreenHeight() - 11.0f - fPlayerSize;


}

void SoccerGame::drawPlayerOne()
{
    FillCircle(vPlayerOnePos, fPlayerSize, olc::BLACK);
}

void SoccerGame::drawBall()
{
    FillCircle(vBall, fBallSize, olc::WHITE);
}