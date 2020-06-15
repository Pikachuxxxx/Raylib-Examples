//
//  main.c
//  Raylib-Textures-Painting
//
//  Created by phani srikar on 15/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <raylib.h>
#define MAX_COLORS_COUNT    23          // Number of colors available


int main() {
     
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib [textures] : painting");
    SetTargetFPS(60);
    
    Color colors[MAX_COLORS_COUNT] = {
    RAYWHITE, YELLOW, GOLD, ORANGE, PINK, RED, MAROON, GREEN, LIME, DARKGREEN,
    SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE, BEIGE, BROWN, DARKBROWN,
    LIGHTGRAY, GRAY, DARKGRAY, BLACK };
    Rectangle colorsRecs[MAX_COLORS_COUNT] = { 0 };

    for (int i = 0; i < MAX_COLORS_COUNT; i++)
    {
        colorsRecs[i].x = 10 + 30*i + 2*i;
        colorsRecs[i].y = 10;
        colorsRecs[i].width = 30;
        colorsRecs[i].height = 30;
    }
    
    int colorMouseHover = 0;
    int brushSize = 20;
    int colorSelected = 0;
    
    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);
    
    Rectangle btnSaveRec = { 750, 10, 40, 30 };
    bool btnSaveMouseHover = false;
    bool showSaveMessage = false;
    int saveMessageCounter = 0;
    
    
    
    while(!WindowShouldClose()){
        
        
        Vector2 mousePosition = GetMousePosition();
        
        for (int i = 0; i < MAX_COLORS_COUNT; i++)
        {
            if (CheckCollisionPointRec(mousePosition, colorsRecs[i]))
            {
                colorMouseHover = i;
                break;
            }
            else colorMouseHover = -1;
        }
        if ((colorMouseHover >= 0) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) colorSelected = colorMouseHover;
        
        brushSize += GetMouseWheelMove()*5 * -1;
        if (brushSize < 2) brushSize = 2;
        if (brushSize > 50) brushSize = 50;
        
       if (IsKeyPressed(KEY_C))
       {
           // Clear render texture to clear color
           BeginTextureMode(target);
           ClearBackground(colors[0]);
           EndTextureMode();
       }
        
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) || (GetGestureDetected() == GESTURE_DRAG))
        {
            BeginTextureMode(target);
            if (mousePosition.y > 50) DrawCircle(mousePosition.x, mousePosition.y, brushSize, colors[colorSelected]);
            EndTextureMode();
        }
        
        
        if (CheckCollisionPointRec(mousePosition, btnSaveRec)) btnSaveMouseHover = true;
        else btnSaveMouseHover = false;

        if ((btnSaveMouseHover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) || IsKeyPressed(KEY_S))
        {
            Image image = GetTextureData(target.texture);
            ImageFlipVertical(&image);
            ExportImage(image, "my_amazing_texture_painting.png");
            UnloadImage(image);
            showSaveMessage = true;
        }
        
        if (showSaveMessage)
        {
            saveMessageCounter++;
            if (saveMessageCounter > 240)
            {
                showSaveMessage = false;
                saveMessageCounter = 0;
            }
        }
        
        // NOTE: Render texture must be y-flipped due to default OpenGL coordinates (left-bottom)
        DrawTextureRec(target.texture, (Rectangle){ 0, 0, target.texture.width, -target.texture.height }, (Vector2){ 0, 0 }, WHITE);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        for (int i = 0; i < MAX_COLORS_COUNT; i++) DrawRectangleRec(colorsRecs[i], colors[i]);
        DrawRectangleLines(10, 10, 30, 30, LIGHTGRAY); // To highlight the white colour rectangle with a border
        
            if (colorMouseHover >= 0) DrawRectangleRec(colorsRecs[colorMouseHover], Fade(WHITE, 0.6f));
            DrawRectangleLinesEx((Rectangle){ colorsRecs[colorSelected].x - 2, colorsRecs[colorSelected].y - 2, colorsRecs[colorSelected].width + 4, colorsRecs[colorSelected].height + 4 }, 2, BLACK);
        
        //Save your drawing!!!
        DrawRectangleLinesEx(btnSaveRec, 2, btnSaveMouseHover? RED : BLACK);
        DrawText("SAVE!", 755, 20, 10, btnSaveMouseHover? RED : BLACK);
        
        if (showSaveMessage)
        {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(RAYWHITE, 0.8f));
            DrawRectangle(0, 150, GetScreenWidth(), 80, BLACK);
            DrawText("IMAGE SAVED:  my_amazing_texture_painting.png at Xcode derived data folder", 150, 180, 20, RAYWHITE);
        }
        EndDrawing();

    }
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}
