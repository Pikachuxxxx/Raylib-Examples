//
//  main.c
//  Eaylib-Core-ScreenScaling
//
//  Created by phani srikar on 06/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

#define max(a, b) ((a)>(b)? (a) : (b))
#define min(a, b) ((a)<(b)? (a) : (b))

int main(int argc, const char * argv[]) {
    
    const int windowWidth = 800;
    const int windowHeight = 450;

   SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
   InitWindow(windowWidth, windowHeight, "raylib [core] : window scale ");
   SetWindowMinSize(320, 240);
    
    int gameScreenWidth = 640;
    int gameScreenHeight = 480;
    
    RenderTexture2D target = LoadRenderTexture(gameScreenWidth, gameScreenHeight);
    SetTextureFilter(target.texture, FILTER_BILINEAR);
    
    Color colors[10] = { 0 };
       for (int i = 0; i < 10; i++) colors[i] = (Color){ GetRandomValue(100, 250), GetRandomValue(50, 150), GetRandomValue(10, 100), 255 };

    while(!WindowShouldClose())
    {
        //Update here
        float scale = min((float)GetScreenWidth()/gameScreenWidth, (float)GetScreenHeight()/gameScreenHeight);

        
        //DRwe here
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginTextureMode(target);
        
        ClearBackground(RAYWHITE);
        for (int i = 0; i < 10; i++) DrawRectangle(0, (gameScreenHeight/10)*i, gameScreenWidth, gameScreenHeight/10, colors[i]);

        EndTextureMode();
        DrawTexturePro(target.texture,
                       (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
                                  (Rectangle){ (GetScreenWidth() - ((float)gameScreenWidth*scale))*0.5, (GetScreenHeight() - ((float)gameScreenHeight*scale))*0.5,
                                  (float)gameScreenWidth*scale, (float)gameScreenHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
