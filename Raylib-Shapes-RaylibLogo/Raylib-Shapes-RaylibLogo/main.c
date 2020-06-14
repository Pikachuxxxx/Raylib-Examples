//
//  main.c
//  Raylib-Shapes-RaylibLogo
//
//  Created by phani srikar on 14/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>
int main() {
    const int screenHeight = 600, screenWidth = 600;
    InitWindow(screenWidth, screenHeight, "Raylib [Shapes] : Raylib Logo");
    SetTargetFPS(65);
    
//    Rectangle raylibBox = (Rectangle){screenWidth / 2 - 125, screenHeight / 2 - 125, 250, 250}; //Static logo rect
    
    int logoPositionX = screenWidth/2 - 128;
    int logoPositionY = screenHeight/2 - 128;

    int framesCounter = 0;
    int lettersCount = 0;

    int topSideRecWidth = 16;
    int leftSideRecHeight = 16;

    int bottomSideRecWidth = 16;
    int rightSideRecHeight = 16;

    int state = 0;// State Machine
    float alpha = 1.0f;
    
    while (!WindowShouldClose()) {
        
        
        if (state == 0){
            framesCounter ++;
            if(framesCounter == 60){
                framesCounter = 0;
                state = 1;
            }
        }
        else if(state == 1){
            topSideRecWidth += 4;
            leftSideRecHeight += 4;
            if(topSideRecWidth == 256){
                state = 2;
            }
        }
        else if(state == 2){
            rightSideRecHeight += 4;
            bottomSideRecWidth += 4;
            if(bottomSideRecWidth == 256){
                state = 3;
            }
        }
        else if(state == 3){
            framesCounter ++;
            if(framesCounter / 12){
                lettersCount ++;
                framesCounter = 0;
            }
            if(lettersCount >= 6 + 10){
                alpha -= 0.02f;
            }
        }
        
        // Optional Resetting
    
        if (IsKeyPressed(KEY_R))
        {
            framesCounter = 0;
            lettersCount = 0;

            topSideRecWidth = 16;
            leftSideRecHeight = 16;

            bottomSideRecWidth = 16;
            rightSideRecHeight = 16;

            alpha = 1.0f;
            state = 0;
        }
        
        
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // To draw static logo
//        DrawRectangleLinesEx(raylibBox, 20, BLACK);
//        DrawText("raylib", screenWidth/2 - 24, screenHeight/2 + 48, 40, BLACK);
        DrawText("Press 'R' to replay", 250, 50, 12, BLACK);
        
        if(state == 0){
            if ((framesCounter/15)%2) DrawRectangle(logoPositionX, logoPositionY, 16, 16, BLACK);
        }
        else if(state == 1){
            DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
            DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
        }
        else if(state == 2){
            DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
            DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
            
            DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
            DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
        }
        else if(state == 3){
            DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
            DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
            
            DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
            DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
        
            DrawText(TextSubtext("raylib", 0, lettersCount), 300, 360, 32, BLACK);
        }

        EndDrawing();
        
    }
    CloseWindow();
    return 0;
}
