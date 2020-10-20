#include "olcPixelGameEngine.h"


class SoccerGame : public olc::PixelGameEngine
{
    public:
        SoccerGame();
        bool OnUserUpdate(float fElapsedTime) override;
        bool OnUserCreate() override;
    private: 
        void drawField();
        void handlePlayerOneMovement(float fElapsedTime);
        void drawPlayerOne();
        void drawBall();

        float fPlayerSize;  // 60x60 as for now player is a square
        float fPlayerSPeed; //pixels per sec
		float fBallSize;

		olc::vf2d vPlayerOnePos;
		olc::vf2d vPlayerTwoPos;
	    olc::vf2d vBall;
        olc::vf2d vBallCollisionPoints{};
};