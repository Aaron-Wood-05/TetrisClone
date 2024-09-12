#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0; //keeps track of the time at which the last update of the game occurs

bool eventTriggered(double interval) //takes an interval in seconds
{
    double currentTime = GetTime(); 
    if(currentTime - lastUpdateTime >= interval) // the interval has passed since the last update
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500,620, "raylib Tetris"); //initializes window and takes 3 arguements, width, height, title ; needs to be big so it can fit the UI
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();
    
    while(WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.handleInput();
        if(eventTriggered(0.2)) //if true, the interval has passed and it moves down 1
        {
            game.moveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE); // takes the font to use, string of text to draw, vector for its position, the size of text, the spacing between letters, an the color
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); // takes in the font, the text to measure, the font size, and the space between the letters; returns the height and width of text in pixels
        
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2 , 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);//takes rect with a pos and size, the roundness, the number of line segments in the rounded corner, and color)
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
} 