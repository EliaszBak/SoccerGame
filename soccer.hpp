#include "olcPixelGameEngine.h"


class SoccerGame : public olc::PixelGameEngine
{
    public:
        SoccerGame();
        bool OnUserUpdate(float fElapsedTime) override;
        bool OnUserCreate() override;
    private: 
        void drawField();
        void handlePlayerOneMovement();
    
        int iPlayerOneStartPosY {850};
        int iPlayerOneStartPosX {325};
        int iPlayerTwoStartPosX {325};
        int iPlayerTwoStartPosY {150};
        int iPlayerSize {60};
        float fPlayerSPeed {3.0f};

	    olc::vf2d vBall = { 355.0f, 505.0f };
};