//
//  main.c
//  Raylib-Shapes-BouncingBall
//
//  Created by phani srikar on 14/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

struct Ball {
    Vector2 ballsPosition;
    Vector2 ballVelocity;
    float radius ;
    Color ballColour;
} Ball;

void CollisionCheckAndRebound(bool isGamePaused, struct Ball* ball);
int main() {
    
    const int screenWidth = 800, screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib  [Shapes] : bouncing ball");
    
    struct Ball ball;
    ball.ballsPosition = (Vector2){ GetScreenWidth()/2, GetScreenHeight()/2 };
    ball.ballVelocity = (Vector2){4.0f, 5.0f};
    ball.radius = 20;
    ball.ballColour = (Color)RED;
    
    bool pause = 0;

    
    SetTargetFPS(65);
    while (!WindowShouldClose()) {
        
        if (IsKeyPressed(KEY_SPACE)) pause = !pause;
        CollisionCheckAndRebound(pause, &ball);
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(ball.ballsPosition , ball.radius, ball.ballColour);
        DrawFPS(10, 10);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void CollisionCheckAndRebound(bool isGamePaused, struct Ball* ball){
    if(!isGamePaused){
        ball->ballsPosition.x += ball->ballVelocity.x;
        ball->ballsPosition.y += ball->ballVelocity.y;
        
        // check the bounds and screen walls here
        if((ball->ballsPosition.x >= (GetScreenWidth() - ball->radius)) || (ball->ballsPosition.x <= ball->radius)) ball->ballVelocity.x
            *= -1.0f;
        if((ball->ballsPosition.y >= GetScreenHeight() - ball->radius) || (ball->ballsPosition.y <= ball->radius)) ball->ballVelocity.y
            *= -1.0f;
    }
}
