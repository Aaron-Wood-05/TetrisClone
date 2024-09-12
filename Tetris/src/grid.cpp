#include "grid.h"
#include <iostream>
#include "colors.h"

using namespace std;

//a grid object that initializes the amount of rows, cols, pixel size of cells, and the value of each cell. 
Grid::Grid()
{
    numRows = 20; 
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = getCellColors();
}

//initializes the values of the grid to 0
void Grid::Initialize()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            grid[i][j] = 0;
        }
    }
}

//will print out the values of the game's grid
void Grid:: Print()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    } 
}

void Grid:: Draw()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column]; // will fill in the color's coresponding number onto this part of the grid. 
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1 , colors[cellValue]);
        }
    }
}

bool Grid:: isCellOutside(int row, int column)
{
    if(row >= 0 && row < numRows && column >= 0 && column < numCols) //if it's in-bounds
    {
        return false;
    }
    else
    {
        return true;
    }
}
int Grid::clearFullRows()
{
    int completed = 0;
    for(int row = numRows - 1; row >= 0; row--) //starts from the bottom going up
    {
        if(isRowFull(row)) //if a row is full it clears and adds to completed rows
        {
            ClearRow(row);
            completed++;
        }
        else if(completed > 0) //if more than 1 row was full, it moves the uncompleted rows down
        {
            MoveRowDown(row,completed);
        }       
    }

    return completed; 
}
bool Grid::isCellEmpty(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }

    return false; //because 1-7 represent a block
}

bool Grid::isRowFull(int row)
{
    for(int col = 0; col < numCols; col++)
    {
        if(grid[row][col] == 0) //checks if value of cell is 0, if it is, that means the row isnt full
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) //will clear the row by making all the values 0
{
    for(int col = 0; col < numCols; col++)
    {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int col = 0; col < numCols; col++)
    {
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}
