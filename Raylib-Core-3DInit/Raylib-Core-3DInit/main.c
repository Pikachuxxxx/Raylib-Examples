//
//  main.c
//  Raylib-Core-3DInit
//
//  Created by phani srikar on 06/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

int main(int argc, const char * argv[]) {
    
    const int screenWidth = 800, screenHeight = 600;

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.type = CAMERA_PERSPECTIVE;
    
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(65);
    InitWindow(screenWidth, screenHeight, "Raylib [Core] : 3D Initialisation");
    while (!WindowShouldClose()) {
        //Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(10, 10);
        BeginMode3D(camera);
            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
            DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, GREEN);
            DrawGrid(10, 1.0f);
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
