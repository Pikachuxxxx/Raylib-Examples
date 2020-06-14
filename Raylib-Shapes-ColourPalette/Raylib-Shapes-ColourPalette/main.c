//
//  main.c
//  Raylib-Shapes-ColourPalette
//
//  Created by phani srikar on 14/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

#define MAX_COLORS_COUNT 21

int main() {
    
    const int screenWidth = 800, screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib [Shapes] : Colour palette presentation");
    SetTargetFPS(65);
    
    
    Color colors[MAX_COLORS_COUNT] =
    {
        DARKGRAY, MAROON, ORANGE, DARKGREEN, DARKBLUE, DARKPURPLE, DARKBROWN,
        GRAY, RED, GOLD, LIME, BLUE, VIOLET, BROWN, LIGHTGRAY, PINK, YELLOW,
        GREEN, SKYBLUE, PURPLE, BEIGE
    };
    const char *colorNames[MAX_COLORS_COUNT] =
    {
        "DARKGRAY", "MAROON", "ORANGE", "DARKGREEN", "DARKBLUE", "DARKPURPLE",
        "DARKBROWN", "GRAY", "RED", "GOLD", "LIME", "BLUE", "VIOLET", "BROWN",
        "LIGHTGRAY", "PINK", "YELLOW", "GREEN", "SKYBLUE", "PURPLE", "BEIGE"
    };
    Rectangle colorsRecs[MAX_COLORS_COUNT] = {0};
    for(int i = 0; i < MAX_COLORS_COUNT ;i++){
        colorsRecs[i].x = 20 + 100*(i%7) + 10*(i%7);
        colorsRecs[i].y = 80 + 100*(i/7) + 10*(i/7);
        colorsRecs[i].width = 100;
        colorsRecs[i].height = 100;
    }
    
    int colorState[MAX_COLORS_COUNT] = { 0 };           // Color state: 0-DEFAULT, 1-MOUSE_HOVER
    Vector2 mousePoint = { 0.0f, 0.0f };
    
    while (!WindowShouldClose()) {
        
        mousePoint = GetMousePosition();
        for (int i = 0; i < MAX_COLORS_COUNT; i++)
        {
            if (CheckCollisionPointRec(mousePoint, colorsRecs[i])) colorState[i] = 1;
            else colorState[i] = 0;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("raylib colors palette", 28, 42, 20, BLACK);
        
        for (int i = 0; i < MAX_COLORS_COUNT; i++)    // Draw all rectangles
        {
            DrawRectangleRec(colorsRecs[i], Fade(colors[i], colorState[i]? 0.6f : 1.0f));

            if (colorState[i])
            {
                DrawRectangle(colorsRecs[i].x, colorsRecs[i].y + colorsRecs[i].height - 26, colorsRecs[i].width, 20, BLACK);
                DrawRectangleLinesEx(colorsRecs[i], 6, Fade(BLACK, 0.3f));
                DrawText(colorNames[i], colorsRecs[i].x + colorsRecs[i].width - MeasureText(colorNames[i], 10) - 12,
                         colorsRecs[i].y + colorsRecs[i].height - 20, 10, colors[i]);
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
