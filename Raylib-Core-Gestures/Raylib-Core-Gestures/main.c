//
//  main.c
//  Raylib-Core-Gestures
//
//  Created by phani srikar on 05/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

int main() {

    const int screenWidth = 800, screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Raylib [Core] : Gesture");
   
    Vector2 touchPosition = { 0, 0 };

    int currentGesture = GESTURE_NONE;

    while (!WindowShouldClose()) {
        
        currentGesture = GetGestureDetected();
        touchPosition = GetTouchPosition(0);

        switch (currentGesture)
        {
            case GESTURE_TAP:DrawText("GESTURE TAP", 300, 10, 24, GRAY);break;
            case GESTURE_DOUBLETAP:DrawText("GESTURE_DOUBLETAP ", 300, 10, 24,GRAY);break;
            case GESTURE_HOLD:DrawText(" GESTURE_HOLD", 300, 10, 24, GRAY);break;
            case GESTURE_DRAG:DrawText(" GESTURE_DRAG", 300, 10, 24, GRAY);break;
            case GESTURE_SWIPE_RIGHT:DrawText(" GESTURE_SWIPE_RIGHT", 300, 10, 24, GRAY);break;
            case GESTURE_SWIPE_LEFT:DrawText(" GESTURE_SWIPE_LEFT", 300, 10, 24, GRAY);break;
            case GESTURE_SWIPE_UP:DrawText(" GESTURE_SWIPE_UP", 300, 10, 24, GRAY);break;
            case GESTURE_SWIPE_DOWN:DrawText(" GESTURE_SWIPE_DOWN", 300, 10, 24, GRAY);break;
            case GESTURE_PINCH_IN:DrawText(" GESTURE_PINCH_IN", 300, 10, 24, GRAY);break;
            case GESTURE_PINCH_OUT:DrawText(" GESTURE_PINCH_OUT", 300, 10, 24, GRAY);break;
            default: break;
        }
    
        
        DrawText("CurrentGesture is : ", 10, 10, 24, GRAY);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        EndDrawing();
    }
    
    CloseWindow();

return 0;
}


