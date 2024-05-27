#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include "element.h"
#include "beat.h"
#include "../scene/gamescene.h" // for element label
#include <stdbool.h>
/*
   [TIMER object]
*/
typedef struct _Timer
{
    ALLEGRO_TIMER *t;
    int count;
    int last;
} Timer;

Elements *New_Timer(int label);
void Timer_update(Elements *self);
void Timer_interact(Elements *self, Elements *tar);
void Timer_draw(Elements *self);
void Timer_destory(Elements *self);


#endif
