#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
    public:
        Game();
        ~Game();
        void Draw();
        void handleInput();
        void moveBlockDown();
        bool gameOver;
        int score;
        Music music;
        

    private:
        Block getRandomBlock();
        vector<Block> getAllBlocks();
        void moveBlockLeft();
        void moveBlockRight();
        bool isBlockOutside();
        void RotateBlock();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void updateScore(int linesCleared, int moveDownPoints);
        vector <Block> blocks;
        Grid griddy;
        Block currentBlock;
        Block nextBlock;
        Sound rotateSound;
        Sound clearSound;
};