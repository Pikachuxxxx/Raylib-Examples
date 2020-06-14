//
//  main.c
//  Raylib-Shapes-CollisionArea
//
//  Created by phani srikar on 14/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>


int main() {
   
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - collision area");
    SetTargetFPS(65);
    
    Rectangle boxA = { 10, GetScreenHeight()/2 - 50, 200, 100 };
    int boxASpeedX = 4;
    Rectangle boxB = { GetScreenWidth()/2 - 30, GetScreenHeight()/2 - 30, 60, 60 };
    Rectangle boxCollision = { 0 };
    
    bool collision = false;

    while (!WindowShouldClose()) {
        
        boxA.x += boxASpeedX;
        if (((boxA.x + boxA.width) >= GetScreenWidth()) || (boxA.x <= 0)) boxASpeedX *= -1;
        
        boxB.x = GetMouseX() - boxB.width/2;
        boxB.y = GetMouseY() - boxB.height/2;
        
        collision = CheckCollisionRecs(boxA, boxB);

        // Get collision rectangle (only on collision)
        if (collision) boxCollision = GetCollisionRec(boxA, boxB);
        
        BeginDrawing();

                   ClearBackground(collision? RED : RAYWHITE);

                   DrawRectangleRec(boxA, GOLD);
                   DrawRectangleRec(boxB, BLUE);

                   if (collision)
                   {
                       DrawRectangleRec(boxCollision, LIME);

                       DrawText("COLLISION!", GetScreenWidth()/2 - MeasureText("COLLISION!", 20)/2, 50, 20, BLACK);
                       DrawText(FormatText("Collision Area: %i", (int)boxCollision.width*(int)boxCollision.height), GetScreenWidth()/2 - 100, 10, 20, BLACK);
                   }

                   DrawFPS(10, 10);

               EndDrawing();
    }
    CloseWindow();
    return 0;
}
