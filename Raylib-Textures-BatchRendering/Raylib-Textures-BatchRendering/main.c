//
//  main.c
//  Raylib-Textures-BatchRendering
//
//  Created by phani srikar on 17/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdlib.h>
#include <raylib.h>

#define MAX_BUNNIES 50000
#define MAX_BATCH_ELEMENTS  8192

typedef struct Bunny{
    Vector2 position;
    Vector2 speed;
    Color color;
}Bunny;
int main() {
    
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [textures] : Batch Redering");
    SetTargetFPS(65);
    
    
    Texture2D bunnyTex = LoadTexture("/Users/phanisrikar/Desktop/wabbit_alpha.png");
    
    Bunny *bunnies = (Bunny *) malloc(MAX_BUNNIES * sizeof(bunnyTex));
    int bunniesCount = 0;
    
    while (!WindowShouldClose()) {
        
        
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            for (int i = 0; i < 100; i ++){
                if(bunniesCount < MAX_BUNNIES){
                    bunnies[bunniesCount].position = GetMousePosition();
                    bunnies[bunniesCount].speed.x = (float)GetRandomValue(-250, 250)/60.0f;
                    bunnies[bunniesCount].speed.y = (float)GetRandomValue(-250, 250)/60.0f;
                    bunnies[bunniesCount].color = (Color){ GetRandomValue(50, 240),
                                                       GetRandomValue(80, 240),
                                                       GetRandomValue(100, 240), 255 };
                    bunniesCount++;
                }
            }
        }
        // Move and bounds collision here
        for (int i = 0; i < bunniesCount; i++)
          {
              bunnies[i].position.x += bunnies[i].speed.x;
              bunnies[i].position.y += bunnies[i].speed.y;

              if (((bunnies[i].position.x + bunnyTex.width/2) > GetScreenWidth()) ||
                  ((bunnies[i].position.x + bunnyTex.width/2) < 0)) bunnies[i].speed.x *= -1;
              if (((bunnies[i].position.y + bunnyTex.height/2) > GetScreenHeight()) ||
                  ((bunnies[i].position.y + bunnyTex.height/2 - 40) < 0)) bunnies[i].speed.y *= -1;
          }
        
        // Draw here
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        for (int i = 0; i < bunniesCount; i ++) {
            DrawTexture(bunnyTex, bunnies[i].position.x, bunnies[i].position.y, bunnies[i].color);
        }
        
        DrawRectangle(0, 0, screenWidth, 40, BLACK);
        DrawText(FormatText("bunnies: %i", bunniesCount), 120, 10, 20, GREEN);
        DrawText(FormatText("batched draw calls: %i", 1 + bunniesCount/MAX_BATCH_ELEMENTS), 320, 10, 20, MAROON);

        DrawFPS(10, 10);
        EndDrawing();
    }
    
    free(bunnies);
    UnloadTexture(bunnyTex);
    CloseWindow();
    
    return 0;
}
