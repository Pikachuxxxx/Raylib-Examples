//
//  main.c
//  Raylib-Core-BasicWindow
//
//  Created by phani srikar on 04/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

const int screenWidth = 800, screenHeight = 600;

int main() {
    
    InitWindow(screenWidth, screenHeight, "raylib [core] - basic window");
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello Raylib", screenWidth/2, screenHeight/2, 36, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
