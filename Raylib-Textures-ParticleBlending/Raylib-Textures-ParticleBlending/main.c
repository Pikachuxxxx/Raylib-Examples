//
//  main.c
//  Raylib-Textures-ParticleBlending
//
//  Created by phani srikar on 16/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

#define MAX_PARTICLES 200


typedef struct {
    Vector2 position;
    Color color;
    float alpha;
    float size;
    float rotation;
    bool active;
} Particle;

int main() {
    
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [textures] : particles blending");
    SetTargetFPS(62);
    
    Particle mouseTail[MAX_PARTICLES] = {0};
    
    for (int i = 0; i < MAX_PARTICLES; i++){
        mouseTail[i].position = (Vector2){ 0, 0 };
        mouseTail[i].color = (Color){ GetRandomValue(0, 255), GetRandomValue(0, 255), GetRandomValue(0, 255), 255 };
        mouseTail[i].alpha = 1.0f;
        mouseTail[i].size = (float)GetRandomValue(1, 30)/20.0f;
        mouseTail[i].rotation = (float)GetRandomValue(0, 360);
        mouseTail[i].active = false;
    }

    float gravity = 3.0f;
    Texture2D particleTexture = LoadTexture("/Users/phanisrikar/Desktop/spark_flame.png");
    int blending = BLEND_ALPHA;
    
    
    while (!WindowShouldClose()) {
        
        for (int i = 0; i < MAX_PARTICLES; i++)
        {
            if (!mouseTail[i].active)
            {
                mouseTail[i].active = true;
                mouseTail[i].alpha = 1.0f;
                mouseTail[i].position = GetMousePosition();
                i = MAX_PARTICLES;
            }
        }
        
        for (int i = 0; i < MAX_PARTICLES; i++)
        {
            if (mouseTail[i].active)
            {
                mouseTail[i].position.y += gravity/2;
                mouseTail[i].alpha -= 0.005f;

                if (mouseTail[i].alpha <= 0.0f) mouseTail[i].active = false;

                mouseTail[i].rotation += 2.0f;
            }
        }
        
        if (IsKeyPressed(KEY_SPACE))
        {
            if (blending == BLEND_ALPHA) blending = BLEND_ADDITIVE;
            else blending = BLEND_ALPHA;
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        
        BeginBlendMode(blending);
            
        for (int i = 0; i < MAX_PARTICLES; i++){
            if(mouseTail[i].active) DrawTexturePro(particleTexture, (Rectangle){0,0,(float)particleTexture.width,(float)particleTexture.height}, (Rectangle){mouseTail[i].position.x, mouseTail[i].position.y, particleTexture.width*mouseTail[i].size, particleTexture.height*mouseTail[i].size} , (Vector2){ (float)(particleTexture.width*mouseTail[i].size/2.0f), (float)(particleTexture.height*mouseTail[i].size/2.0f) }, mouseTail[i].rotation, Fade(mouseTail[i].color, mouseTail[i].alpha));
        }
        
        EndBlendMode();
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
