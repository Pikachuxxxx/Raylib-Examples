//
//  main.c
//  Raylib-Textures-SpriteAnimation
//
//  Created by phani srikar on 15/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

int main(){
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib [texture]  : Sprite Animation");
    SetTargetFPS(62);
    
    Texture2D scarfy = LoadTexture("/Users/phanisrikar/Desktop/scarfy.png");
    
    Vector2 position = { 350.0f, 280.0f };
    Rectangle frameRec = { 0.0f, 0.0f, (float)scarfy.width/6, (float)scarfy.height };
    int currentFrame = 0;

    int framesCounter = 0;
    int framesSpeed = 8;
    
    
    while (!WindowShouldClose()) {
        
        framesCounter++;

        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 5) currentFrame = 0;

            frameRec.x = (float)currentFrame*(float)scarfy.width/6;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        
        DrawTexture(scarfy, 25, 25, WHITE);
        DrawRectangleLines(25, 25, scarfy.width, scarfy.height, LIME);
        DrawRectangleLines(25 + frameRec.x, 25 + frameRec.y, frameRec.width, frameRec.height, RED);
        
        DrawTextureRec(scarfy, frameRec, position, WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
