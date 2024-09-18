#include "raylib.h"
#include "GameManager.h"
#include <iostream>

using namespace std;

GameManager gameManager = GameManager();

void Load();
void Start();
void Update();
void Draw();
void Unload();

int main() {
    Load();
    Start();
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    Unload();
    return 0;
}
void Load()
{
    InitWindow(1080, 720, "PONK");
    SetTargetFPS(60);
    HideCursor();
    gameManager.Load();
}

void Start()
{

}

void Update()
{
    gameManager.Update();
}

void Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    gameManager.Draw();
    EndDrawing();
}

void Unload()
{
    CloseWindow();
}