#ifndef _kdt_h
#define _kdt_h
#include "../include/raylib.h"
#include "./boid.h"

#define XAXIS 0
#define YAXIS 1

struct _node;

typedef struct _node{
  int cBoids;
  Boid **boids;
  struct _node *l, *r;
}node;

typedef node kdtree;

kdtree *createkdtree(Boid* boids, int cBoids){

}

#endif