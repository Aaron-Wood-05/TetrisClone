#pragma once
#include <vector>
#include <raylib.h> //the vector needs to store colors

using namespace std;

class Grid
{
    public:
        Grid();
        void Initialize();
        void Print();
        void Draw();
        bool isCellOutside(int row, int column);
        int clearFullRows();
        int grid[20][10];
        bool isCellEmpty(int row, int column);
        

    private:
        
        bool isRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
        int numRows;
        int numCols;
        int cellSize;
        vector<Color> colors;

};