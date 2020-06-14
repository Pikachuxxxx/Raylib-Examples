//
//  main.c
//  Raylib-Shapes-Basicshapes
//
//  Created by phani srikar on 14/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>
int main(int argc, const char * argv[]) {

    const int screenWidth = 800, screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib [Shapes] : basic shapes");
    
    while (!WindowShouldClose()) {
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Lines
        DrawLine(50, 60, 750, 60, BLACK);
        DrawCircleLines(screenWidth / 4, 200, 20, PINK);
        DrawRectangleLines(screenWidth / 2, 200, 20, 40, PINK);
        
        // Solid shapes
        DrawTriangle((Vector2){screenWidth/4*3, 80},
        (Vector2){screenWidth/4*3 - 60, 150},
        (Vector2){screenWidth/4*3 + 60, 150}, VIOLET);
        DrawRectangle(screenWidth / 2, 100, 20, 40, RED);
        DrawCircle(screenWidth / 4, 100, 20, RED);
        DrawCircleSector((Vector2){screenWidth / 4, 500}, 20, 00, 270, 0, BLUE);
        DrawPoly((Vector2){screenWidth/4*3, 320}, 7, 80, 0, BROWN);

        // Gradients
        DrawCircleGradient(screenWidth / 4, 300, 20, PINK, YELLOW);
        DrawRectangleGradientH(screenWidth / 2, 300, 20, 40, GREEN, GRAY);

        // UI/Text items
        DrawText("Some basic shapes in raylib", 80, 30, 22, BLACK);
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

