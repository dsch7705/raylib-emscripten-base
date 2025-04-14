#include <stdio.h>

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#ifdef PLATFORM_WEB
#include <emscripten/emscripten.h>
#endif

static const int SCREEN_W = 800;
static const int SCREEN_H = 600;

#define FULLSCREEN 0

void UpdateDrawFrame(void)
{
    BeginDrawing();

    ClearBackground(RED);

    Rectangle r = { SCREEN_W / 2, SCREEN_H / 2, 200, 125 };
    r.x -= r.width / 2;
    r.y -= r.height / 2;

    GuiButton(r, "Hello");

    EndDrawing();
}

int main(int argc, char** argv)
{
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(SCREEN_W, SCREEN_H, "raylib Web Application");
    if (FULLSCREEN)
    {
        int display = GetCurrentMonitor();
        SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
    }

#ifdef PLATFORM_WEB
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
        
    }

#endif

    CloseWindow();
}