#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = getCellColors();
    rowOffset = 0;
    columnOffset = 0;
}


void Block:: Draw(int offsetX, int offsetY)
{
    vector<Position> tiles = getCellPositions(); //gets current rotation state of the teromino
    for(Position item: tiles)
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block:: Move(int rows, int columns) 
{
    rowOffset += rows;
    columnOffset += columns;
}

vector<Position> Block:: getCellPositions()
{
    vector <Position> tiles = cells[rotationState]; //this allows it to know what state the blocks in
    vector <Position> movedTiles;
    for(Position item: tiles) // within tiles, which has the rotation state.
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset); //adds the offset to the tiles position
        movedTiles.push_back(newPos); //it'll append this cells new coordinates to movedTiles
    }

    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;
    if(rotationState == (int) cells.size()) //it needs to loop back to the original rotation state after rotating enough times
    {
        rotationState = 0;
    }
}

void Block::undoRotation()
{
    rotationState--;
    if(rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}
