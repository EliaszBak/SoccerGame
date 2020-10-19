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


        float fPlayerOneStartPosY {850};
        float fPlayerOneStartPosX {325};
        float fPlayerTwoStartPosX {325};
        float fPlayerTwoStartPosY {150};

        float fPlayerSize {60};  // 60x60 as for now player is a square
        float fPlayerSPeed {250.0f}; //pixels per sec

	    olc::vf2d vBall = { 355.0f, 505.0f };
        olc::vf2d vBallCollisionPoints{};
};