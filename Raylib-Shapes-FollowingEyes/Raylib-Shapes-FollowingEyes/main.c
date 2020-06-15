//
//  main.c
//  Raylib-Shapes-FollowingEyes
//
//  Created by phani srikar on 14/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <raylib.h>
int main() {
    
    
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [shapes] : following eyes");
    SetTargetFPS(65);
    
    Vector2 scleraLeftPosition = { GetScreenWidth()/2 - 100, GetScreenHeight()/2 };
    Vector2 scleraRightPosition = { GetScreenWidth()/2 + 100, GetScreenHeight()/2 };
    float scleraRadius = 80;

    Vector2 irisLeftPosition = { GetScreenWidth()/2 - 100, GetScreenHeight()/2 };
    Vector2 irisRightPosition = { GetScreenWidth()/2 + 100, GetScreenHeight()/2};
    float irisRadius = 24;
    
    float angle = 0.0f;
    float dx = 0.0f, dy = 0.0f, dxx = 0.0f, dyy = 0.0f;
    
    while (!WindowShouldClose()) {
        
        //Update stuff here
        irisLeftPosition = GetMousePosition();
        irisRightPosition = GetMousePosition();
        
        if(!CheckCollisionPointCircle(irisLeftPosition, scleraLeftPosition, scleraRadius - irisRadius)){
            
            dx = irisLeftPosition.x - scleraLeftPosition.x;
            dy = irisLeftPosition.y - scleraLeftPosition.y;

            angle = atan2f(dy, dx);

            dxx = (scleraRadius - irisRadius)*cosf(angle);
            dyy = (scleraRadius - irisRadius)*sinf(angle);

            irisLeftPosition.x = scleraLeftPosition.x + dxx;
            irisLeftPosition.y = scleraLeftPosition.y + dyy;
        }
        if(!CheckCollisionPointCircle(irisRightPosition, scleraRightPosition, scleraRadius - irisRadius)){
            
            dx = irisRightPosition.x - scleraRightPosition.x;
            dy = irisRightPosition.y - scleraRightPosition.y;

            angle = atan2f(dy, dx);

            dxx = (scleraRadius - irisRadius)*cosf(angle);
            dyy = (scleraRadius - irisRadius)*sinf(angle);

            irisRightPosition.x = scleraRightPosition.x + dxx;
            irisRightPosition.y = scleraRightPosition.y + dyy;
        }
        
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("Move the mouse around and see the eyes follow you", screenWidth/2 - MeasureText("Move to mouse around and see the eyes follow you", 20)/2, 50, 20, LIGHTGRAY);
        
        DrawCircleV(scleraLeftPosition, scleraRadius, LIGHTGRAY);
        DrawCircleV(irisLeftPosition, irisRadius, BROWN);
        DrawCircleV(irisLeftPosition, 10, BLACK);

        DrawCircleV(scleraRightPosition, scleraRadius, LIGHTGRAY);
        DrawCircleV(irisRightPosition, irisRadius, DARKGREEN);
        DrawCircleV(irisRightPosition, 10, BLACK);
        
        DrawFPS(20, 10);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
