#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

using namespace std;

class Block
{
    public:
        Block();
        void Draw(int offsetX, int offsetY);
        void Move(int rows, int columns);
        vector<Position> getCellPositions();
        void Rotate();
        void undoRotation();
        int id;
        map<int,vector<Position>> cells; //the int is the key, the value it gives is vector with the orientation/position

        
    private:
        int cellSize;
        int rotationState;
        vector<Color> colors;
        int rowOffset;
        int columnOffset;
        

};