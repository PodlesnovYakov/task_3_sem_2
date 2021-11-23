#ifndef ROBBERS_H_INCLUDED
#define ROBBERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <graphics.h>
#include <math.h>
struct R
{
    char name[10];
    int alive,horse,sward,diamond,neck,wife,coins,wealth;

};
struct R band[40];
char* alive(int k);
void col(int k);
void sec(int k);
void info(char *s1,int k);
void add(char *s,int *k);
void kill(char* s1,int k);
void fprint(int k);
void sprint(int k);
void find_rich(int k);

#endif
