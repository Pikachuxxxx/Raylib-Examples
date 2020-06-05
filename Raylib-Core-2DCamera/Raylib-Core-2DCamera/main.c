//
//  main.c
//  Raylib-Core-2DCamera
//
//  Created by phani srikar on 05/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

#define MAX_BUILDINGS   100

int main(int argc, const char * argv[]) {

    const int screenWidth = 800, screenHeight = 600;
    
    Rectangle player = { 400, 280, 40, 40 };
    Rectangle buildings[MAX_BUILDINGS] = { 0 };
    Color buildingColors[MAX_BUILDINGS] = { 0 };
    
    float spacing = 0;
    
    for(int i = 0; i < MAX_BUILDINGS; i++){
        buildings[i].width = GetRandomValue(50, 200);
        buildings[i].height = GetRandomValue(100,500);
        buildings[i].y = screenHeight - buildings[i].height;
        buildings[i].x = -6000 + spacing;
         
        spacing += buildings[i].width;
        
        buildingColors[i] = (Color){GetRandomValue(200, 240),GetRandomValue(200, 240),GetRandomValue(200, 240),255};
    }
    
    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.x + 20, player.y + 20 };// focus at center mass of the player and not the top left tip
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
    InitWindow(screenWidth, screenHeight, "Raylib [Core] : 2D Camera");
    while (!WindowShouldClose()) {
        
        if(IsKeyDown(KEY_RIGHT)) player.x += 2 * 100 * GetFrameTime();
        if(IsKeyDown(KEY_LEFT)) player.x -= 2 * 100 * GetFrameTime();

        camera.target = (Vector2){ player.x + 20, player.y + 20 };
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);
        //Drawing some random building rectangles
        for (int i = 0; i < MAX_BUILDINGS; i++) DrawRectangleRec(buildings[i], buildingColors[i]);
        DrawRectangleRec(player, RED);
        
        EndMode2D();
        EndDrawing();
    }
    CloseWindow();
    
return 0;
}
