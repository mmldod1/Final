#include "boss.h"
#include "../shapes/Circle.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 672

/*
   [Boss function]
*/
Elements *New_Boss(int label)
{
    Boss *pDerivedObj = (Boss *)malloc(sizeof(Boss));
    Elements *pObj = New_Elements(label);

    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/boss_normal.png");
    pDerivedObj->img_up = al_load_bitmap("assets/image/boss_top.png");
    pDerivedObj->img_down = al_load_bitmap("assets/image/boss_buttom.png");
    pDerivedObj->img_left = al_load_bitmap("assets/image/boss_left.png");
    pDerivedObj->img_right = al_load_bitmap("assets/image/boss_right.png");
    pDerivedObj->current_img = pDerivedObj->img;
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->current_img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->current_img);
    pDerivedObj->image_switched = false;
    pDerivedObj->switch_timer = 0;

    // Specify the scale factors
    float scale_x = 0.25; // Scale width to 50%
    float scale_y = 0.25; // Scale height to 50%

    // Set initial position to center the image
    pDerivedObj->x = (SCREEN_WIDTH - pDerivedObj->width * scale_x) / 2 - 30; //-10 normally
    pDerivedObj->y = (SCREEN_HEIGHT - pDerivedObj->height * scale_y) / 2 + 10; //+10 normally
    // setting the interact object

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Boss_update;
    pObj->Interact = Boss_interact;
    pObj->Draw = Boss_draw;
    pObj->Destroy = Boss_destroy;

    return pObj;
}

void Boss_update(Elements *self, double dt)
{
    Boss *Obj = ((Boss *)(self->pDerivedObj));

    if (key_state[ALLEGRO_KEY_UP]) {
        Obj->current_img = Obj->img_up;
        Obj->width = al_get_bitmap_width(Obj->current_img);
        Obj->height = al_get_bitmap_height(Obj->current_img);
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }
    else if (key_state[ALLEGRO_KEY_DOWN]) {
        Obj->current_img = Obj->img_down;
        Obj->width = al_get_bitmap_width(Obj->current_img);
        Obj->height = al_get_bitmap_height(Obj->current_img);
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }
    else if (key_state[ALLEGRO_KEY_LEFT]) {
        Obj->current_img = Obj->img_left;
        Obj->width = al_get_bitmap_width(Obj->current_img);
        Obj->height = al_get_bitmap_height(Obj->current_img);
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }
    else if (key_state[ALLEGRO_KEY_RIGHT]) {
        Obj->current_img = Obj->img_right;
        Obj->width = al_get_bitmap_width(Obj->current_img);
        Obj->height = al_get_bitmap_height(Obj->current_img);
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }

    if (Obj->image_switched) {
        Obj->switch_timer -= dt;
        if (Obj->switch_timer <= 0) {
            Obj->current_img = Obj->img;
            Obj->width = al_get_bitmap_width(Obj->current_img);
            Obj->height = al_get_bitmap_height(Obj->current_img);
            Obj->image_switched = false;
        }
    }
}

void _Boss_update_position(Elements *self, int dx, int dy)
{
}

void Boss_interact(Elements *self, Elements *tar)
{
}

void Boss_draw(Elements *self)
{
    Boss *Obj = ((Boss *)(self->pDerivedObj));

    // Specify the scale factors
    float scale_x = 0.25; // Scale width to 50%
    float scale_y = 0.25; // Scale height to 50%

    // Calculate new width and height
    float new_width = Obj->width * scale_x;
    float new_height = Obj->height * scale_y;

    al_draw_scaled_bitmap(Obj->current_img,
                          0, 0, Obj->width, Obj->height, // Source bitmap coordinates
                          Obj->x, Obj->y, // Destination coordinates
                          new_width, new_height, // Scaled width and height
                          0); // Flags
}

void Boss_destroy(Elements *self)
{
    Boss *Obj = ((Boss *)(self->pDerivedObj));
    if (Obj) {
        if (Obj->current_img) {
            al_destroy_bitmap(Obj->current_img);
        }
        if (Obj->hitbox) {
            free(Obj->hitbox);
        }
        free(Obj);
    }
    if (self) 
        free(self);
    }

