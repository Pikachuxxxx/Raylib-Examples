//
//  main.c
//  Eaylib-Core-Input
//
//  Created by phani srikar on 05/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

int main() {
    const int screeWidth =800, screenHeight = 600;
    InitWindow(screeWidth, screenHeight, "Raylib[Core] : Input Handling");
    SetTargetFPS(90);
    
    Vector2 playerPos;
    float playerSpeed = 2.0;
    
    playerPos = (Vector2){screeWidth/2,screenHeight/2};

    while(!WindowShouldClose()){
        
        
        if(IsKeyDown(KEY_RIGHT)) playerPos.x += GetFrameTime() * 100 * playerSpeed;
        if(IsKeyDown(KEY_LEFT)) playerPos.x -= GetFrameTime() * 100 * playerSpeed;
        if(IsKeyDown(KEY_UP)) playerPos.y -= GetFrameTime() * 100 * playerSpeed;
        if(IsKeyDown(KEY_DOWN)) playerPos.y += GetFrameTime() * 100 * playerSpeed;
        

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Use Arrow keys to control the player", 10, 20, 12, DARKGRAY);
        DrawCircleV(playerPos, 20, SKYBLUE);
        
        EndDrawing();

    }
    
    CloseWindow();
    return 0;
}
