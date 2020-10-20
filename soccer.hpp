#include "olcPixelGameEngine.h"

struct Ball
{
    Ball(){};
    Ball(float x, float y, float size)
    {
        centerPos.x = x;
        centerPos.y = y;
        fBallRadius = size;
    }

	olc::vf2d centerPos{};
	olc::vf2d velocity{};
	olc::vf2d acceleration{};
    float fBallRadius{};
};

class SoccerGame : public olc::PixelGameEngine
{
    public:
        SoccerGame();
        bool OnUserUpdate(float fElapsedTime) override;
        bool OnUserCreate() override;
    private: 
        void drawField();
        void handlePlayerOneMovement(float fElapsedTime);
        void handleBallMovement(Ball& player, Ball& ball);
        void drawPlayerOne();
        void drawBall();
        
        
        bool ballsCollides(
            olc::vf2d player, olc::vf2d ball, float playerRadius, float ballRadius);
        float calculateCollisionPoint(
            olc::vf2d player, olc::vf2d ball, float playerRadius, float ballRadius);
        float calculateOverlappedDistance(float distance, float playerRadius, float ballRadius);
        float calculateDistanceBetweenBallsCenters(olc::vf2d player, olc::vf2d ball);

        float fPlayerSize;  //radius 
        float fPlayerSpeed; //pixels per sec
		float fBallSize;
        float fBallSpeed;
        float fBallAcceleration;

		olc::vf2d vPlayerOnePos;
		olc::vf2d vPlayerTwoPos;
	    olc::vf2d vBall;
        olc::vf2d vBallCollisionPoints{};

        Ball playerOne_;
        Ball ball_;
};


