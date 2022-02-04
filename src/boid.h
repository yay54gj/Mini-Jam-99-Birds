#ifndef _boid_h
#define _boid_h
#include "../include/raylib.h"
#include "../include/raymath.h"
typedef struct {
    Vector2 pos;
    Vector2 vel;
    Vector2 acc;
}Boid;
#endif