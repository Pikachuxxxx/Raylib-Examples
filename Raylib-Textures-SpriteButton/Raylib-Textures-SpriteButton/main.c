//
//  main.c
//  Raylib-Textures-SpriteButton
//
//  Created by phani srikar on 17/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [textures] : sprite button");

    
    int btnState = 0;// Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false;// Button action should be activated

    Vector2 mousePoint = { 0.0f, 0.0f };
    while (!WindowShouldClose()) {
        
        mousePoint = GetMousePosition();
        btnAction = false;
        
        if(CheckCollisionPointRec(mousePoint, btnBouds)){
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) btnState = 2;
            else btnState = 1;
            
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) btnAction = true;
        }
        else btnState = 0;
        
        if(btnAction){
            // Do some action here
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawTextureRec(buttonTex, (Rectangle){}, (Vector2){}, WHITE);
        
        EndDrawing();
    }
    CloseWindow();
    SetTargetFPS(60);
    return 0;
}
