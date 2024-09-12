#include "block.h"
#include "position.h"

class LBlock: public Block //inheretes the block class
{
    public:
        LBlock()
        {
            id = 1; //the ID for this type of block
            //for each position, imagine it in a mini-grid so you can orient the block however you need.
            cells[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)}; //the key is 0, gives access to the position of the LBlock's cells
            cells[1] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};
            cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};
            cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
            Move(0,3); //tetris starts with the blocks in the middle of the top row
        }

};

class JBlock: public Block
{
    public:
        JBlock()
        {
            id = 2;
            cells[0] = {Position{0,0}, Position{1,0}, Position{1,1}, Position{1,2}};
            cells[1] = {Position{0,1}, Position{0,2}, Position{1,1}, Position{2,1}};
            cells[2] = {Position{1,0}, Position{1,1}, Position{1,2}, Position{2,2}};
            cells[3] = {Position{0,1}, Position{1,1}, Position{2,0}, Position{2,1}};
            Move(0,3);
        }
};

class IBlock: public Block
{
    public:
        IBlock()
        {
            id = 3;
            cells[0] = {Position{1,0}, Position{1,1}, Position{1,2}, Position{1,3}};
            cells[1] = {Position{0,2}, Position{1,2}, Position{2,2}, Position{3,2}};
            cells[2] = {Position{2,0}, Position{2,1}, Position{2,2}, Position{2,3}};
            cells[3] = {Position{0,1}, Position{1,1}, Position{2,1}, Position{3,1}};
            Move(-1,3);
        }
};

class OBlock: public Block
{
    public:
        OBlock()
        {
            id = 4;
            cells[0] = {Position{0,0}, Position{0,1}, Position{1,0}, Position{1,1}};
            Move(0,4);
        }
};

class SBlock: public Block
{
    public:
        SBlock()
        {
            id = 5;
            cells[0] = {Position{0,1}, Position{0,2}, Position{1,0}, Position{1,1}};
            cells[1] = {Position{0,1}, Position{1,1}, Position{1,2}, Position{2,2}};
            cells[2] = {Position{1,1}, Position{1,2}, Position{2,0}, Position{2,1}};
            cells[3] = {Position{0,0}, Position{1,0}, Position{1,1}, Position{2,1}};
            Move(0,3);
        }
};

class TBlock: public Block
{
    public:
        TBlock()
        {
            id = 6;
            cells[0] = {Position{0,1}, Position{1,0}, Position{1,1}, Position{1,2}};
            cells[1] = {Position{0,1}, Position{1,1}, Position{1,2}, Position{2,1}};
            cells[2] = {Position{1,0}, Position{1,1}, Position{1,2}, Position{2,1}};
            cells[3] = {Position{0,1}, Position{1,0}, Position{1,1}, Position{2,1}};
            Move(0,3);
        }
};

class ZBlock: public Block
{
    public:
        ZBlock()
        {
            id = 7;
            cells[0] = {Position{0,0}, Position{0,1}, Position{1,1}, Position{1,2}};
            cells[1] = {Position{0,2}, Position{1,1}, Position{1,2}, Position{2,1}};
            cells[2] = {Position{1,0}, Position{1,1}, Position{2,1}, Position{2,2}};
            cells[3] = {Position{0,1}, Position{1,0}, Position{1,1}, Position{2,0}};
            Move(0,3);
        }
};