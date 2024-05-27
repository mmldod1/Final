#include "timer.h"
#include "../scene/sceneManager.h"
#include <stdbool.h>
// count the time when the game starts
/*
   [Timer function]
*/
Elements *New_Timer(int label)
{
    Timer *pDerivedObj = (Timer *)malloc(sizeof(Timer));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->t = al_create_timer(1.0/60);
    al_start_timer(pDerivedObj->t);
    pDerivedObj->count = 0;
    pDerivedObj->last = 0;
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Timer_update;
    pObj->Interact = Timer_interact;
    pObj->Draw = Timer_draw;
    pObj->Destroy = Timer_destory;
    return pObj;
}
void Timer_update(Elements *self)
{
    Timer *Obj = ((Timer *)(self->pDerivedObj));
    Obj->count = al_get_timer_count(Obj->t);
    int count[1000] = {97, 159, 221, 304, 1111, 1180, 1282};
    for(int i=0; i<1000; i++)
    {
        if(Obj->count==count[i] && Obj->count!=Obj->last)
        {
            Elements *bt = New_Beat(Beat_L, 1000, 580, -4, al_map_rgb(100, 100, 100));
            _Register_elements(scene, bt);
            Obj->last = Obj->count;
        }
    }
}
void Timer_interact(Elements *self, Elements *tar)
{

}
void Timer_draw(Elements *self)
{

}
void Timer_destory(Elements *self)
{
    Timer *Obj = ((Timer *)(self->pDerivedObj));
    al_destroy_timer(Obj->t);
    free(Obj);
    free(self);
}

