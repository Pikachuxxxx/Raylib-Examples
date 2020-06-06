//
//  main.c
//  Raylib-Core-Scissor
//
//  Created by phani srikar on 06/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

int main() {
    
    const int screenWidth = 800, screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib [Core] : Scissor effect");
    
    Rectangle scissorArea = { 0, 0, 300, 300 };
    
    
    while (!WindowShouldClose()) {
        scissorArea.x = GetMouseX() - scissorArea.width/2;
        scissorArea.y = GetMouseY() - scissorArea.height/2;
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        BeginScissorMode(scissorArea.x, scissorArea.y, scissorArea.width, scissorArea.height);
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), RED);
        DrawText("Move the mouse around to reveal this text!", 190, 200, 20, BLUE);
        EndScissorMode();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
