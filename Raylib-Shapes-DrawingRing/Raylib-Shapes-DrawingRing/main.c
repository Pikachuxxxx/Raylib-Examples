//
//  main.c
//  Raylib-Shapes-DrawingRing
//
//  Created by phani srikar on 15/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main() {
    
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib [shapes] : draw ring");
    SetTargetFPS(60);
    
    Vector2 center = {(GetScreenWidth() - 300)/2, GetScreenHeight()/2 };

    float innerRadius = 80.0f;
    float outerRadius = 190.0f;

    int startAngle = 0;
    int endAngle = 360;
    int segments = 0;

    bool drawRing = true;
    bool drawRingLines = false;
    bool drawCircleLines = false;

    
    while (!WindowShouldClose()){
        
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("GUI Controls", 650 - MeasureText("GUI Controls", 20) / 2, 25, 20, BLACK);
        DrawLine(500, 0, 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
        DrawRectangle(500, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));
        
        if (drawRing) DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(MAROON, 0.3));
        if (drawRingLines) DrawRingLines(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(BLACK, 0.4));
        if (drawCircleLines) DrawCircleSectorLines(center, outerRadius, startAngle, endAngle, segments, Fade(BLACK, 0.4));

        drawRing = GuiCheckBox((Rectangle){550,100,20,20}, "Draw Ring", drawRing);
        drawRingLines = GuiCheckBox((Rectangle){550,120,20,20}, "Draw Ring Lines", drawRingLines);
        drawCircleLines = GuiCheckBox((Rectangle){550,140,20,20}, "Draw Circle Lines", drawCircleLines);

        startAngle = GuiSliderBar((Rectangle){600,180,120,20}, "Start Angle ", "", startAngle, 0, 360);
        endAngle = GuiSliderBar((Rectangle){600,200,120,20}, "End Angle ", "", endAngle, 0, 360);
        
        innerRadius = GuiSliderBar((Rectangle){600,240,120,20}, "Inner Radius ", "", innerRadius, 0, 100);
        outerRadius = GuiSliderBar((Rectangle){600,260,120,20}, "Outer Radius ", "", outerRadius, 0, 200);
        
        segments = GuiSliderBar((Rectangle){600,300,120,20}, "Segments ", "", segments, 0, 20);
        
        DrawText(FormatText("MODE: %s", (segments >= 4)? "MANUAL" : "AUTO"), 550, 330, 10, (segments >= 4)? MAROON : DARKGRAY);

        DrawFPS(10, 10);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
