#include "raylib.h"
#include <iostream>

using namespace std;

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
    InitWindow(1200, 800, "PONK");
    SetTargetFPS(60);
    HideCursor();
}

void Start()
{

}

void Update()
{

}

void Draw()
{
    BeginDrawing();
    ClearBackground(BLANK);
    EndDrawing();
}

void Unload()
{
    CloseWindow();
}