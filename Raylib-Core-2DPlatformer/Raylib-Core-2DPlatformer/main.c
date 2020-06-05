//
//  main.c
//  Raylib-Core-2DPlatformer
//
//  Created by phani srikar on 05/06/20.
//  Copyright © 2020 phani srikar. All rights reserved.
//

#include <stdio.h>
#include <raylib.h>

#define G 400

typedef struct Player {
    Vector2 position;
    float speed;
    bool canJump;
} Player;

typedef struct EnvItem {
    Rectangle rect;
    Color color;
}EnvItem;

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta);

int main(int argc, const char * argv[]) {
    
    const int screenWidth = 800, screenHeight = 600;
        
    //Define the player
    Player player = { 0 };
    player.position = (Vector2){ 400, 280 };
    player.speed = 2;
    player.canJump = false;
    //Define the camera
    Camera2D camera = {};
    camera.target = (Vector2){player.position.x + 20, player.position.y + 20};
    camera.offset = (Vector2){screenWidth/2, screenHeight/2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    //Define the environment
    EnvItem envItems[] = {
           {{ 0, 0, 1000, 400 }, LIGHTGRAY },
           {{ 0, 400, 1000, 200 }, GRAY },
           {{ 300, 200, 400, 10 }, GRAY },
           {{ 250, 300, 100, 10 }, GRAY },
           {{ 650, 300, 100, 10 }, GRAY }
       };
       int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);

    InitWindow(screenWidth, screenHeight, "Raylib [Core] - Simple 2D platformer");
    while (!WindowShouldClose()) {
        
        //Update here
        float deltaTime = GetFrameTime();
        UpdatePlayer(&player, envItems, envItemsLength, deltaTime);
        
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);
        camera.target = (Vector2){player.position.x + 20, player.position.y + 20};

        //Draw =here
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);
                
        //Let's draw the environment here
        for (int i = 0; i < envItemsLength; i++) DrawRectangleRec(envItems[i].rect, envItems[i].color);
        
        Rectangle playerRect = {player.position.x,player.position.y,40,40};
        DrawRectangleRec(playerRect, RED);

        EndMode2D();
        EndDrawing();
        //End Drawing
    }
    CloseWindow();
    return 0;
}

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta){
    if(IsKeyDown(KEY_RIGHT)) player->position.x += 100 * player->speed * GetFrameTime();
    if(IsKeyDown(KEY_LEFT)) player->position.x -= 100 * player->speed * GetFrameTime();
    if (IsKeyDown(KEY_SPACE) && player->canJump){
        player->speed = -player->speed;
        player->canJump = false;
    }
    
    //CheckForCollisionsHere and update his posiotn to avoid walking through stuff
    for(int i = 0; i < envItemsLength;i++){
        
    }
}
    
    
