//
//  main.c
//  Raylib-Core-3DFPP
//
//  Created by phani srikar on 06/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

#define MAX_COLUMNS 10
int main() {
    
    const int screenWidth = 800;
    const int screenHeight = 600;
    
   Camera camera = { 0 };
   camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
   camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
   camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
   camera.fovy = 60.0f;
   camera.type = CAMERA_PERSPECTIVE;
    
    SetCameraMode(camera, CAMERA_FIRST_PERSON);
    
    float heights[MAX_COLUMNS] = {0};
    Vector3 positions[MAX_COLUMNS] = {0};
    Color colors[MAX_COLUMNS] = { 0 };

    for (int i = 0; i < MAX_COLUMNS; i++){
       heights[i] = (float)GetRandomValue(1, 12);
       positions[i] = (Vector3){ GetRandomValue(-15, 15), heights[i]/2, GetRandomValue(-15, 15) };
       colors[i] = (Color){ GetRandomValue(20, 255), GetRandomValue(10, 55), 30, 255 };
   }
    
    InitWindow(screenWidth, screenHeight, "Raylib [Core] : 3D fpp");
    while (!WindowShouldClose()){
        
        //Update stuff
        UpdateCamera(&camera);
        
        //Draw here
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);

        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, GRAY);
        DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);
        DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);
        DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);


        for (int i = 0; i < MAX_COLUMNS; i++)
        {
            DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
        }
        
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
