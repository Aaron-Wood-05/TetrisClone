#include "game.h"
#include <random>


Game::Game()
{
    griddy = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3"); //loads music files
    PlayMusicStream(music); //plays background music
    rotateSound = LoadSound("Sounds/rotate.mp3");
    clearSound = LoadSound("Sounds/clear.mp3");
}

Game::~Game()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music); //before closing needs to unload music file
    CloseAudioDevice(); //need to stop the audio when games over
}

Block Game:: getRandomBlock()
{
    if(blocks.empty())
    {
        blocks  = getAllBlocks();
    }
    int randNum = rand() % blocks.size(); //gets the first block
    Block block = blocks[randNum];
    blocks.erase(blocks.begin() + randNum); //ensures this block can't be picked again until the others are
    return block;
}


vector <Block> Game:: getAllBlocks()
{
    return {IBlock(), JBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    griddy.Draw();
    currentBlock.Draw(11,11);
    switch(nextBlock.id)
    {
        case 3:
            nextBlock.Draw(255,290);
            break;
        case 4:
            nextBlock.Draw(255,280);
            break;
        default: 
            nextBlock.Draw(270, 270);
            break;
    }
}

void Game:: handleInput()
{
    int keyPressed = GetKeyPressed(); // saves the key pressed into an integer
    if(gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch(keyPressed)
    {
        case KEY_LEFT: //checks if the keypressed = the KEY_LEFT constant (they pressed the left key)
            moveBlockLeft();
        break;

        case KEY_RIGHT:
            moveBlockRight();
        break;

        case KEY_DOWN:
            moveBlockDown();
            updateScore(0,1);
        break;

        case KEY_UP:
            RotateBlock(); //if up is pressed it rotates it

        break;
    }
}

void Game:: moveBlockLeft() //moves the current block left
{
    if(!gameOver)
    {
        currentBlock.Move(0,-1); 
        if(isBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0,1);
        }
    }
}

void Game:: moveBlockRight() //moves the current block left
{ 
    if(!gameOver)
    {
        currentBlock.Move(0,1);
        if(isBlockOutside() || BlockFits() == false) //if its out of bounds OR the block would collide with another block
        {
            currentBlock.Move(0,-1);
            LockBlock();
        }
    }
}

void Game:: moveBlockDown() //moves the current block down
{
    if(!gameOver)
    {
        currentBlock.Move(1,0);
        if(isBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(-1,0);
            LockBlock();
        }
    }
}

bool Game::isBlockOutside()
{
    vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item: tiles)
    {
        if(griddy.isCellOutside(item.row, item.column)) //if the any cell is outside, return true
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()  
{
    if(!gameOver)
    {
        currentBlock.Rotate();

        if(isBlockOutside() || BlockFits() == false)
        {
            currentBlock.undoRotation();
        }
        else
        {
            PlaySound(rotateSound);
        }
    }
}

void Game::LockBlock() //will lock the block when it hits the bottom :D
{
    vector <Position> tiles = currentBlock.getCellPositions();
    for (Position item: tiles) //for each position in tiles
    {
        griddy.grid[item.row][item.column] = currentBlock.id; //store the ID of the block in the grid
    }
    currentBlock = nextBlock;
    if (BlockFits() == false)
    {
        gameOver = true;
    }
    nextBlock = getRandomBlock(); //will now pop a new block at the top of the screen! 
    int rowsCleared = griddy.clearFullRows(); //because once a block is locked, it needs to check if the row is full; clearing it if it is. Also stores it so its able to be used to determine the points accrued
    if(rowsCleared > 0) //if more than 0 rows cleared, play the sound for it and update the score accordingly
    {
        PlaySound(clearSound);
        updateScore(rowsCleared, 0); //updates the score by how many rows are cleared
    }
   

}

bool Game::BlockFits()
{ 
    vector <Position> tiles = currentBlock.getCellPositions();
    for(Position item: tiles) //checks if any of the cells are occupied
    {
        if(griddy.isCellEmpty(item.row, item.column) == false)
        {
            return false;
        }
    }

    return true; //if all the cells are empty and the block can move to the specified position
}

void Game::Reset()
{
    griddy.Initialize();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    score = 0;
}

void Game::updateScore(int linesCleared, int moveDownPoints)
{
    switch(linesCleared)
    {
        case 1: 
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        default:
            break;
    }
    
    score += moveDownPoints;
}
