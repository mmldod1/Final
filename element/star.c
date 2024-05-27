#include "star.h"
#include "../shapes/Rectangle.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 672
/*
   [star function]
*/
Elements *New_Star(int label)
{
    star *pDerivedObj = (star *)malloc(sizeof(star));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/star.png");
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = -400;
    pDerivedObj->y = -400;
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = star_update;
    pObj->Interact = star_interact;
    pObj->Draw = star_draw;
    pObj->Destroy = star_destory;
    return pObj;
}
void star_update(Elements *self, double dt)
{
    star *Obj = ((star *)(self->pDerivedObj));

    if (key_state[ALLEGRO_KEY_UP]) {
        Obj->x = 240;
        Obj->y = 190;
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }
    else if (key_state[ALLEGRO_KEY_DOWN]) {
        Obj->x = 350;
        Obj->y = 290;
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }
    else if (key_state[ALLEGRO_KEY_LEFT]) {
        Obj->x = 270;
        Obj->y = 230;
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }
    else if (key_state[ALLEGRO_KEY_RIGHT]) {
        Obj->x = 430;
        Obj->y = 190;
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }

    if (Obj->image_switched) {
        Obj->switch_timer -= dt;
        if (Obj->switch_timer <= 0) {
            Obj->x = -500;
            Obj->y = -500;
            Obj->image_switched = false;
        }
    }
}

void star_interact(Elements *self, Elements *tar) {}
void star_draw(Elements *self)
{
    star *Obj = ((star *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void star_destory(Elements *self)
{
    star *Obj = ((star *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
