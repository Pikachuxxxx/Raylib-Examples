//
//  main.c
//  Raylib-Core-MouseInput
//
//  Created by phani srikar on 05/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>


int main(int argc, const char * argv[]) {
    
    const int screenWidht = 800, screenHeight = 600;
    InitWindow(screenWidht, screenHeight, "Raylib - [Core] : mouse Input");
    int scrollSpeed = 20;
        
    // Game Lo0p
    while(!WindowShouldClose()){
        
       // Input Hanlding here
        
        Vector2 ballPos = {300,(GetMouseWheelMove()*scrollSpeed)};
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ballPos, 20, PINK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
