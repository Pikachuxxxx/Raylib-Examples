//
//  main.c
//  Raylib-Core-2DCamera
//
//  Created by phani srikar on 05/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

#define MAX_BUILDINGS   100

int main(int argc, const char * argv[]) {

    const int screenWidht = 800, screenHeight = 600;
    
    Rectangle player = { 400, 280, 40, 40 };
    Rectangle buildings[MAX_BUILDINGS] = { 0 };
    Color buildingColors[MAX_BUILDINGS] = { 0 };
    
    InitWindow(screenWidht, screenHeight, "Raylib [Core] : 2D Camera");
    while (!WindowShouldClose()) {
        
        
        
    }
    CloseWindow();
    
return 0;
}
