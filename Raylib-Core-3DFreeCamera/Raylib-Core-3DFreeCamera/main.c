//
//  main.c
//  Raylib-Core-3DFreeCamera
//
//  Created by phani srikar on 06/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

int main(){
    
    const int screenWidht = 800, screenHeight = 600;
    
    Camera3D cam = {0};
    cam.position = (Vector3){10.0f,10.0f,10.0f};
    cam.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    cam.up = (Vector3){0.0f, 1.0f,0.0f};
    cam.fovy = 45;
    cam.type = CAMERA_PERSPECTIVE;
    
    
    Vector3 cubePosiotn = (Vector3){0.0f,0.0f,0.0f};
    SetCameraMode(cam, CAMERA_FREE);
    
    
    InitWindow(screenWidht, screenHeight, "Raylic [Core] : 3D Freelook camera");
    while (!WindowShouldClose()) {
        
        //Update here
        UpdateCamera(&cam);
        
        //Draw here
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(cam);
        
        DrawCube(cubePosiotn, 1, 1, 1, BLUE);
        DrawGrid(10, 1);
        
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
