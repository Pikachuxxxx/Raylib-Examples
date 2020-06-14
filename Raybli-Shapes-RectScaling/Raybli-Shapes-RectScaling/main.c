//
//  main.c
//  Raybli-Shapes-RectScaling
//
//  Created by phani srikar on 14/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

#define MOUSE_SCALE_MARK_SIZE   12

int main() {
    const int screenWidth = 800, screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "Raylib [Shapes] : Rectangle Scaling");
    SetTargetFPS(65);
    
    Rectangle rec = { 100, 100, 200, 80 };
    Vector2 mousePosition = { 0 };

    bool mouseScaleReady = false;
    bool mouseScaleMode = false;

    
    while (!WindowShouldClose()) {

        mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, rec))
           {
               mouseScaleReady = true;
               if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) mouseScaleMode = true;
           }
           else mouseScaleReady = false;
        
        if (mouseScaleMode)
        {
            mouseScaleReady = true;

            rec.width = (mousePosition.x - rec.x);
            rec.height = (mousePosition.y - rec.y);

            if (rec.width < MOUSE_SCALE_MARK_SIZE) rec.width = MOUSE_SCALE_MARK_SIZE;
            if (rec.height < MOUSE_SCALE_MARK_SIZE) rec.height = MOUSE_SCALE_MARK_SIZE;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) mouseScaleMode = false;
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleRec(rec, Fade(GREEN, 0.5f));
        
        if (mouseScaleReady)
        {
            DrawRectangleLinesEx(rec, 1, RED);
            DrawTriangle((Vector2){ rec.x + rec.width - MOUSE_SCALE_MARK_SIZE, rec.y + rec.height },
                         (Vector2){ rec.x + rec.width, rec.y + rec.height },
                         (Vector2){ rec.x + rec.width, rec.y + rec.height - MOUSE_SCALE_MARK_SIZE }, RED);
        }
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
