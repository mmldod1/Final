#ifndef Star_H_INCLUDED
#define Star_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [star object]
*/
typedef struct _star
{
    int x, y;          // the position of image
    int width, height; // the width and height of image
    ALLEGRO_BITMAP *img;
    double switch_timer;
    bool image_switched;
} star;
Elements *New_star(int label);
void star_update(Elements *self, double dt);
void star_interact(Elements *self, Elements *tar);
void star_draw(Elements *self);
void star_destory(Elements *self);

#endif
