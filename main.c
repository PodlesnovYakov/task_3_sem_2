#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <graphics.h>
#include <math.h>
#include "robbers.h"
int cost_horse,cost_sward,cost_diamond,cost_neck,cost_wife;
int main()
{

    int  r = 1;

    int k = 7;
    int s = 0;
    setlocale(LC_ALL, "Rus");
    int num;
    char name0[10] = "�������";
    char name1[10] = "������";
    char name2[10] = "������";
    char name3[10] = "�������";
    char name4[10] = "������";
    char name5[10] = "������";
    char name6[10] = "�����";
    cost_horse = 1000;
    cost_sward = 50;
    cost_diamond = 100;
    cost_neck = 30;
    cost_wife = 30;
    strcpy(band[0].name,name0);
    strcpy(band[1].name,name1);
    strcpy(band[2].name,name2);
    strcpy(band[3].name,name3);
    strcpy(band[4].name,name4);
    strcpy(band[5].name,name5);
    strcpy(band[6].name,name6);
    for(int i = 0; i < k; i++)
    {
        band[i].alive = rand() % 2;
        band[i].horse = rand() % 13;
        band[i].sward = rand () % 13;
        band[i].diamond = rand () % 13;
        band[i].neck = rand () % 13;
        band[i].wife = rand () % 13;
        band[i].coins = rand () % 13;
    }
    while(r)
    {
        printf("������� 1,����� ������� ������ ������ ����� � ���������� (����� � �������).\n");
        printf("������� 2,����� ������� ���������� ������ ����� � ���������� (������ �����).\n");
        printf("������� 3,����� ������� ������ ��������.\n");
        printf("������� 4,����� ����� ����-������.\n");
        printf("������� 5,����� �������� ����-������.\n");
        printf("������� 6,����� ������� ���������� ��� ����������.\n");
        printf("������� 7,����� ������� �������� ��������.\n");
        printf("������� 8,����� ������� ���������� ��������.\n");
        printf("������� 0,����� ��������� ������.\n");
        scanf("%d",&num);
        switch(num)
        {

        case 1:
            fprint(k);
            break;
        case 2:
            sprint(k);
            break;
        case 3:
            find_rich(k);
            break;
        case 4:
            printf("������� ���� ����� �����.\n");
            char s1[11];
            scanf("%s",s1);
            kill(s1,k);
            break;
        case 5:
            printf("������� ���� ����� ��������.\n");
            char s2[11];
            scanf("%s",s2);
            add(s2,&k);
            break;
        case 6:
            printf("������� � ��� ����� ������ ����������.\n");
            char s3[11];
            scanf("%s",s3);
            info(s3,k);
            break;
        case 7:
            sec(k);
            break;
        case 8:
            col(k);
            break;
        case 0:
            r = 0;
            break;
        }
    }
    return 0;
}

