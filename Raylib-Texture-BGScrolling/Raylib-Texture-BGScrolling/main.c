//
//  main.c
//  Raylib-Texture-BGScrolling
//
//  Created by phani srikar on 16/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>
int main() {
    const int screenWidth = 800, screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib [Textures] : BG Scrolling");
    SetTargetFPS(62);
    
    Texture2D bg = LoadTexture("/Users/phanisrikar/Desktop/cyberpunk_street_background.png");
    Texture2D fg = LoadTexture("/Users/phanisrikar/Desktop/cyberpunk_street_foreground.png");
    Texture2D mg = LoadTexture("/Users/phanisrikar/Desktop/cyberpunk_street_midground.png");
    
    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;
    
    while (!WindowShouldClose()) {
        
        scrollingBack -= 0.01f;
        scrollingMid -= 0.5f;
        scrollingFore -= 0.8f;
        
        BeginDrawing();
        ClearBackground(GetColor(0x052c46ff));
        
        DrawTextureEx(bg, (Vector2){ scrollingBack, 20 }, 0.0f, 2.0f, WHITE);
        DrawTextureEx(mg, (Vector2){ scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
        DrawTextureEx(fg, (Vector2){ scrollingFore, 20 }, 0.0f, 2.0f, WHITE);

        EndDrawing();
        
    }
    CloseWindow();

    return 0;
}
