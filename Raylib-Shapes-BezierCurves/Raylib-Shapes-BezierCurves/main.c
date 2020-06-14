//
//  main.c
//  Raylib-Shapes-BezierCurves
//
//  Created by phani srikar on 14/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>
int main() {
    
    const int screenWidth = 800, screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib [Shapes] : Bezier Curves");
    SetTargetFPS(65);
    
    
    Vector2 start = {0,0};
    Vector2 end = {screenWidth,screenHeight};
    
    
    
    while (!WindowShouldClose()) {
        
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) start = GetMousePosition();
        else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) end = GetMousePosition();
        
        
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawLineBezier(start, end, 2.0f, RED);

        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
