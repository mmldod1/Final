#include "Beat.h"
#include "../global.h"
#include "../shapes/Circle.h"
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>
//for the first beat
Elements *New_Beat(int label, int x, int y, int v, ALLEGRO_COLOR c)
{
    Beat *pDerivedObj = (Beat *)malloc(sizeof(Beat));
    Elements *pObj = New_Elements(label);
    pDerivedObj->x = x;
    pDerivedObj->y = y;
    pDerivedObj->r = 40;
    pDerivedObj->v = v;         //-4
    pDerivedObj->color = c;     //al_map_rgb(100, 100, 100)
    pDerivedObj->hitbox = New_Circle(pDerivedObj->x, pDerivedObj->y, 5);
    pDerivedObj->ev = false;    //for evaluating bad
    
    // setting the interact object
    pObj->inter_obj[pObj->inter_len++] = Judge_L;
    /*pObj->inter_obj[pObj->inter_len++] = Tree_L;*/

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Draw = Beat_draw;
    pObj->Update = Beat_update;
    pObj->Interact = Beat_interact;
    pObj->Destroy = Beat_destory;
    return pObj;
}

void Beat_update(Elements *self)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    _Beat_update_position(self, Obj->v, 0);
    if(Obj->x <= 5 && Obj->ev==false)
    {
        printf("Bad\n");
        Obj->ev = true;
    }
    if(Obj->x < -100)
    {
        self->dele = true;
    }
}
void _Beat_update_position(Elements *self, int dx, int dy)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    Obj->x += dx;
    Obj->y += dy;
    Shape *hitbox = Obj->hitbox;
    hitbox->update_center_x(hitbox, dx);
    hitbox->update_center_y(hitbox, dy);
}
void Beat_interact(Elements *self, Elements *tar)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    Judge *judge = ((Judge *)(tar->pDerivedObj));
    if(key_state[ALLEGRO_KEY_SPACE] && Obj->ev == false)
    {
        if(judge->hitbox_pf->overlap(judge->hitbox_pf, Obj->hitbox))
        {
            printf("Perfect\n");
            self->dele = true;
        }
        else if(judge->hitbox_pf->overlap(judge->hitbox_gd, Obj->hitbox))
        {
            printf("Good\n");
            self->dele = true;
        }
        else if(judge->hitbox_pf->overlap(judge->hitbox_ok, Obj->hitbox))
        {
            printf("Ok\n");
            self->dele = true;
        }
    }
}
void Beat_draw(Elements *self)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    al_draw_circle(Obj->x, Obj->y, Obj->r, Obj->color, 10);
}
void Beat_destory(Elements *self)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
