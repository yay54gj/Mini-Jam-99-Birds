#include "../include/raylib.h"
#include "../include/raymath.h"

#include "./boid.h"

#define CBOIDS 10
#define FPS    60.0
#define IFPS   (1.0 / 60.0)

int main(void)
{
    SetRandomSeed(GetTime());
    Boid* boids = MemAlloc(sizeof(Boid) * CBOIDS);
    for (int i = 0; i < CBOIDS; i++){
        boids[i].pos = (Vector2){.x = GetRandomValue(0, 600),
                                 .y = GetRandomValue(0, 480) };
        boids[i].vel = (Vector2){.x = (float) GetRandomValue(0, 1000) / 100.0,
                                 .y = (float) GetRandomValue(0, 1000) / 100.0};
        boids[i].acc = (Vector2){.x = (float) GetRandomValue(0, 1000) / 500.0,
                                 .y = (float) GetRandomValue(0, 1000) / 500.0};
    }

    InitWindow(600, 480, "Boid");
    HideCursor();
    SetTargetFPS(FPS);

    Vector2 mousepos;

    while (!WindowShouldClose())
    {
        mousepos = GetMousePosition();
        for (int i = 0; i < CBOIDS; i++){
            boids[i].pos = Vector2Add(boids[i].pos, boids[i].vel);

            boids[i].vel.x = Clamp(boids[i].vel.x + boids[i].acc.x, -60 * IFPS, 60 * IFPS);
            boids[i].vel.y = Clamp(boids[i].vel.y + boids[i].acc.y, -60 * IFPS, 60 * IFPS);

            //                // boid should move right?
            boids[i].acc.x = boids[i].pos.x - mousepos.x > 0 ? 
                                Clamp(boids[i].acc.x - 1 * IFPS, -10 * IFPS, 10 * IFPS) : 
                                Clamp(boids[i].pos.x + 1 * IFPS, -10 * IFPS, 10 * IFPS);
            boids[i].acc.y = boids[i].pos.y - mousepos.y > 0 ? 
                                Clamp(boids[i].acc.y - 1 * IFPS, -10 * IFPS, 10 * IFPS) : 
                                Clamp(boids[i].pos.y + 1 * IFPS, -10 * IFPS, 10 * IFPS);
        }
        BeginDrawing();
            ClearBackground(BLUE);
            DrawCircleV(mousepos, 3, BLACK);
            for (int i = 0; i < CBOIDS; i++){
                DrawCircleV(boids[i].pos, 3, RED);
            }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}