#ifndef Boss_H_INCLUDED
#define Boss_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [Boss object]
*/
typedef enum {
    NORMAL,
    UP,
    DOWN,
    LEFT,
    RIGHT
} BossState;

typedef struct {
    ALLEGRO_BITMAP *img;
    ALLEGRO_BITMAP *img_up;
    ALLEGRO_BITMAP *img_down;
    ALLEGRO_BITMAP *img_left;
    ALLEGRO_BITMAP *img_right;
    ALLEGRO_BITMAP *current_img;
    int width;
    int height;
    float x, y;
    Shape *hitbox;
    double switch_timer;
    bool image_switched;
} Boss;

Elements *New_Boss(int label);
void Boss_update(Elements *self, double dt);
void Boss_interact(Elements *self, Elements *tar);
void Boss_draw(Elements *self);
void Boss_destroy(Elements *self);
void handle_key_down(Elements *boss, int keycode);
#endif