//
//  main.c
//  Raylib-Core-3DPicking
//
//  Created by phani srikar on 06/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>


int main() {
    
    const int screenWidth = 800, screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib [Core] : 3D Picking");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f};
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.type = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = { 0.0f, 1.0f, 0.0f };
    Vector3 cubeSize = { 2.0f, 2.0f, 2.0f };
    
    bool collision = false;
    
    Ray ray = {0};
    SetCameraMode(camera, CAMERA_FREE);
    
    SetTargetFPS(66);
    while (!WindowShouldClose()) {
       
        //Update here
        UpdateCamera(&camera);
        
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if(!collision){
                ray = GetMouseRay(GetMousePosition(), camera);
                BoundingBox boxBB = (BoundingBox){(Vector3){ cubePosition.x - cubeSize.x/2, cubePosition.y - cubeSize.y/2, cubePosition.z - cubeSize.z/2 },
                                              (Vector3){ cubePosition.x + cubeSize.x/2, cubePosition.y + cubeSize.y/2, cubePosition.z + cubeSize.z/2 }};
            collision = CheckCollisionRayBox(ray, boxBB);
            }
            else collision = false;
        }
        //Draw here
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        
        if (collision) DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, RED);
        else DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z, GRAY);
               
        DrawRay(ray, BLUE);
        DrawGrid(10, 1.0f);
        
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
