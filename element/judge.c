#include "Judge.h"
#include "../global.h"
#include "../shapes/Circle.h"
#include <allegro5/allegro_primitives.h>
Elements *New_Judge(int label)
{
    Judge *pDerivedObj = (Judge *)malloc(sizeof(Judge));
    Elements *pObj = New_Elements(label);
    pDerivedObj->x = 85;
    pDerivedObj->y = 580;
    pDerivedObj->r = 40;
    pDerivedObj->color = al_map_rgb(153, 204, 51);
    pDerivedObj->hitbox_pf = New_Circle(pDerivedObj->x,  pDerivedObj->y, 5);
    pDerivedObj->hitbox_gd = New_Circle(pDerivedObj->x,  pDerivedObj->y, 30);
    pDerivedObj->hitbox_ok = New_Circle(pDerivedObj->x,  pDerivedObj->y, 50);
    
    // setting the interact object
    pObj->inter_obj[pObj->inter_len++] = Beat_L;
    /*pObj->inter_obj[pObj->inter_len++] = Tree_L;*/

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Draw = Judge_draw;
    pObj->Update = Judge_update;
    pObj->Interact = Judge_interact;
    pObj->Destroy = Judge_destory;
    return pObj;
}
void Judge_update(Elements *self)
{
    Judge *Obj = ((Judge *)(self->pDerivedObj));
    if(key_state[ALLEGRO_KEY_SPACE])
    {
        Obj->color = al_map_rgb(0, 0, 0);
    }
    else
    {
        Obj->color = al_map_rgb(153, 204, 51);
    }
}
void Judge_interact(Elements *self, Elements *tar)
{

}
void Judge_draw(Elements *self)
{
    Judge *Obj = ((Judge *)(self->pDerivedObj));
    al_draw_circle(Obj->x, Obj->y, Obj->r, Obj->color, 10);
}
void Judge_destory(Elements *self)
{
    Judge *Obj = ((Judge *)(self->pDerivedObj));
    free(Obj->hitbox_pf);
    free(Obj->hitbox_gd);
    free(Obj);
    free(self);
}