#ifndef BEAT_H_INCLUDED
#define BEAT_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [Beat1 object]
*/
typedef struct _Beat
{
    int x, y; // the position of image
    int r;    // the radius
    double v;             // the velocity of projectile
    Shape *hitbox; // the hitbox of object
    ALLEGRO_COLOR color;
    bool ev;
} Beat;

Elements *New_Beat(int label, int x, int y, int v, ALLEGRO_COLOR c);
void Beat_update(Elements *self);
void _Beat_update_position(Elements *self, int dx, int dy);
void Beat_interact(Elements *self, Elements *tar);
void Beat_draw(Elements *self);
void Beat_destory(Elements *self);

#endif

