#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <graphics.h>
#include <math.h>
#include "robbers.h"
int cost_horse,cost_sward,cost_diamond,cost_neck,cost_wife;
char* alive(int k)
{
    if (k == 1) return "Да";
    else return "Нет";
}
void col(int k)
{
    int gm;
    int gd = CUSTOM;
    gm = CUSTOM_MODE(1400,1400);
    initgraph(&gd, &gm,"");
    int count = 0;
    for (int i = 0; i<k; i++)
    {

        if(band[i].alive == 1)
        {
            count  = i;
            break;
        }
    }
    rectangle (50, 700, 100, 300);
    int j = 1;
    for (int i = 0; i<k; i++)
    {

        if((band[i].alive == 1)  && (i!= count))
        {
            rectangle(50+100*j,700,100 + 100*j,600-(int)((band[i].wife*300 )/ (band[count].wife)));
            j++;
        }
    }
    readkey();
    closegraph();
}
void sec(int k)
{
    int gm;
    int gd = CUSTOM;
    gm = CUSTOM_MODE(1200,1200);
    initgraph(&gd, &gm,"");
    int start = 0;
    int end = 0;
    int d = 0;
    int s = 0;
    for(int i = 0; i < k; i++)
    {
        if(band[i].alive == 1)
        {
            d += band[i].wife;
        }
    }
    s = d;
    int q = 3;
    setcolor(q);
    for (int i = 0; i<k; i++)
    {

        if(band[i].alive == 1)
        {
            start = end;
            end += (int)(((float)band[i].wife / s)*360);
            sector(300, 200, start, end, 250, 200);
            q++;
            setcolor(q);
        }


    }

    readkey();
    closegraph();
}
void info(char *s1,int k)
{
    int c;

    for(int i = 0; i < k; i++)
    {
        c = strcmp(s1,band[i].name);
        if(c == 0)
        {
            printf("|%10s|%5s|%6d|%5d|%6d|%8d|%4d|%6d|%9d| \n",band[i].name,alive( band[i].alive),band[i].horse, band[i].sward,band[i].diamond,band[i].neck,band[i].wife,band[i].coins,band[i].wealth);
            //printf("%d",band[i].alive);
        }

    }

}
void add(char *s,int *k)
{
    (*k)++;

    strcpy(band[(*k) - 1].name,s);
    band[(*k) - 1].alive = 1;
    scanf("%d%d%d%d%d%d",&band[(*k)-1].horse,&band[(*k) - 1].sward,&band[(*k) - 1].diamond,&band[(*k) - 1].neck,&band[(*k) - 1].wife,&band[(*k) - 1].coins);
}

void kill(char* s1,int k)
{
    int c;
    for(int i = 0; i < k; i++)
    {
        c = strcmp(s1,band[i].name);
        if(c == 0)
        {
            band[i].alive = 0;
            //printf("%d",band[i].alive);
        }

    }

}

void fprint(int k)
{
    int costs_aliv,costs_horse,costs_sward,costs_diamond,costs_neck,costs_wife,costs_wealth,costs_coins;
    costs_aliv = costs_horse = costs_sward = costs_diamond = costs_neck = costs_wife = costs_wealth = costs_coins = 0;
    for(int i = 0; i < k; i++)
    {
        band[i].wealth = band[i].horse * cost_horse + band[i].sward * cost_sward + band[i].diamond * cost_diamond + band[i].neck * cost_neck - band[i].wife * cost_wife + band[i].coins;
    }
    for(int i = 0; i < k; i++)
    {
        if(band[i].alive == 1)
        {
            costs_aliv++;
            costs_horse += band[i].horse;
            costs_sward += band[i].sward;
            costs_diamond += band[i].diamond;
            costs_neck += band[i].neck;
            costs_wife += band[i].wife;
            costs_wealth += band[i].wealth;
            costs_coins += band[i].coins;
        }
    }
    printf("|   Имя    |Живой|Лошади|Сабли|Рубины|Ожерелья|Жены|Монеты|Имущества| \n");
    printf("=====================================================================\n");
    for(int i = 0; i < k; i++)
    {
        printf("|%10s|%5s|%6d|%5d|%6d|%8d|%4d|%6d|%9d| \n",band[i].name,alive( band[i].alive),band[i].horse, band[i].sward,band[i].diamond,band[i].neck,band[i].wife,band[i].coins,band[i].wealth);
    }
    printf("=====================================================================\n");
    printf("|   Итого  |%5d|%6d|%5d|%6d|%8d|%4d|%6d|%9d| \n",costs_aliv,costs_horse,costs_sward,costs_diamond,costs_neck,costs_wife,costs_coins,costs_wealth);

}
void sprint(int k)
{
    int costs_aliv,costs_horse,costs_sward,costs_diamond,costs_neck,costs_wife,costs_wealth,costs_coins;
    costs_aliv = costs_horse = costs_sward = costs_diamond = costs_neck = costs_wife = costs_wealth = costs_coins = 0;
    for(int i = 0; i < k; i++)
    {
        band[i].wealth = band[i].horse * cost_horse + band[i].sward * cost_sward + band[i].diamond * cost_diamond + band[i].neck * cost_neck - band[i].wife * cost_wife + band[i].coins;
    }
    for(int i = 0; i < k; i++)
    {
        if(band[i].alive == 1)
        {
            costs_aliv++;

            costs_horse += band[i].horse;
            costs_sward += band[i].sward;
            costs_diamond += band[i].diamond;
            costs_neck += band[i].neck;
            costs_wife += band[i].wife;
            costs_wealth += band[i].wealth;
            costs_coins += band[i].coins;
        }
    }
    printf("|   Имя    |Живой|Лошади|Сабли|Рубины|Ожерелья|Жены|Монеты|Имущества| \n");
    printf("=====================================================================\n");
    for(int i = 0; i < k; i++)
        if(band[i].alive == 1)
        {

            {
                printf("|%10s|%5s|%6d|%5d|%6d|%8d|%4d|%6d|%9d| \n",band[i].name,alive( band[i].alive),band[i].horse, band[i].sward,band[i].diamond,band[i].neck,band[i].wife,band[i].coins,band[i].wealth);
            }
            printf("=====================================================================\n");
        }
    printf("|   Итого  |%5d|%6d|%5d|%6d|%8d|%4d|%6d|%9d| \n",costs_aliv,costs_horse,costs_sward,costs_diamond,costs_neck,costs_wife,costs_coins,costs_wealth);

}
void find_rich(int k)
{
    int maximw = 0;
    for(int i = 0; i < k; i++)
    {
        if(band[i].alive == 1)
        {
            if(band[i].wealth > maximw)
            {
                maximw = band[i].wealth;
            }
        }

    }
    for(int i = 0;i < k;i++){
        if(band[i].alive == 1 && band[i].wealth == maximw){
            printf("|%10s|%5s|%6d|%5d|%6d|%8d|%4d|%6d|%9d| \n",band[i].name,alive( band[i].alive),band[i].horse, band[i].sward,band[i].diamond,band[i].neck,band[i].wife,band[i].coins,band[i].wealth);
        }
    }
}
