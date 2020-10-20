#define OLC_PGE_APPLICATION

#include "soccer.hpp"


SoccerGame::SoccerGame()
{
	sAppName = "SoccerGameGame";
}

bool SoccerGame::OnUserCreate() 
{
    playerOne_ = Ball(ScreenWidth() / 2.0f, ScreenHeight() - (ScreenHeight() / 10.0f),
        ScreenWidth() / 10.0f);        
	fPlayerSpeed = { ScreenHeight()/ 2.5f }; //pixels per sec
    ball_ = Ball(ScreenWidth()/2.0f, ScreenHeight()/2.0f, ScreenWidth()/20.0f);

    return true;
}

bool SoccerGame::OnUserUpdate(float fElapsedTime)
{
    handlePlayerOneMovement(fElapsedTime);
    if (ballsCollides(playerOne_.centerPos, ball_.centerPos, playerOne_.fBallRadius, ball_.fBallRadius))
    {
        handleBallMovement(playerOne_, ball_);
    }
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
		playerOne_.centerPos.x -= (fPlayerSpeed * fElapsedTime);
    if (GetKey(olc::Key::RIGHT).bHeld)
        playerOne_.centerPos.x += (fPlayerSpeed * fElapsedTime);
    if (GetKey(olc::Key::UP).bHeld)
        playerOne_.centerPos.y -= fPlayerSpeed * fElapsedTime;
	if (GetKey(olc::Key::DOWN).bHeld)
        playerOne_.centerPos.y += fPlayerSpeed * fElapsedTime;

    if (playerOne_.centerPos.x - playerOne_.fBallRadius < 11.0f)
        playerOne_.centerPos.x = 11.0f + playerOne_.fBallRadius;
    if (playerOne_.centerPos.x + playerOne_.fBallRadius > ScreenWidth() - 11.0f)
        playerOne_.centerPos.x = ScreenWidth() - 11.0f - playerOne_.fBallRadius;

    if (playerOne_.centerPos.y - playerOne_.fBallRadius < 11.0f)
        playerOne_.centerPos.y = 11.0f + playerOne_.fBallRadius;
    if (playerOne_.centerPos.y + playerOne_.fBallRadius > ScreenHeight() -11.0f)
        playerOne_.centerPos.y = ScreenHeight() - 11.0f - playerOne_.fBallRadius;
}

void SoccerGame::drawPlayerOne()
{
    FillCircle(playerOne_.centerPos, playerOne_.fBallRadius, olc::BLACK);
}

void SoccerGame::drawBall()
{
    FillCircle(ball_.centerPos, ball_.fBallRadius, olc::WHITE);
}

bool SoccerGame::ballsCollides(olc::vf2d player, olc::vf2d ball, float playerRadius, float ballRadius)
{
    auto distanceBetweenBalls = calculateDistanceBetweenBallsCenters(player, ball);
    
    if ((playerRadius + ballRadius) >= distanceBetweenBalls)
        return true;
    
    return false;
}

float SoccerGame::calculateDistanceBetweenBallsCenters(olc::vf2d player, olc::vf2d ball)
{
    return sqrt(pow(player.x - ball.x, 2.0f)
        + pow(player.y - ball.y, 2.0f));
}

float SoccerGame::calculateOverlappedDistance(float distance, float playerRadius, float ballRadius)
{
    return 0.5f * (distance - playerRadius - ballRadius);
}

float SoccerGame::calculateCollisionPoint(olc::vf2d player, olc::vf2d ball, float playerRadius, float ballRadius)
{
    auto Dx = player.x - ball.x;
    auto Dy = player.y - ball.y;

    auto ABx = (ball.y - player.y) / (ball.x - player.y);
    auto ABy = player.y - ABx * player.x;

    return 0.0f;
}

void SoccerGame::handleBallMovement(Ball& player, Ball& ball)
{
    auto distance = calculateDistanceBetweenBallsCenters(player.centerPos, ball.centerPos);
    auto overLapped = calculateOverlappedDistance(distance, player.fBallRadius, ball.fBallRadius);
    
    player.centerPos.x -= overLapped * (player.centerPos.x - ball.centerPos.x) / distance;
    player.centerPos.y -= overLapped * (player.centerPos.y - ball.centerPos.y) / distance;

    ball.centerPos.x += overLapped * (player.centerPos.x - ball.centerPos.x) / distance;
    ball.centerPos.y += overLapped * (player.centerPos.y - ball.centerPos.y) / distance;
}
