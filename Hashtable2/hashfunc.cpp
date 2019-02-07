//
// Created by alexzinin on 09.12.18.
//

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "listz.h"

using namespace std;

int recordind(FILE* fp)
{

}

int hashstring(char * a)
{
    int i = 0, s = 0;
    for (i = 0;; i++)
    {
        if (a[i] == '\n' || a[i] == '\0')
            break;
        if (a[i] >= 48)
        {
            s = s + a[i] * i;
        }

    }
    return (s);
}

int addelement(List_d **p, char * nname, char * ntel)
{
    if((*p) == NULL)
    {

        List_d *list = (List_d*) malloc(sizeof(List_d));
        list->head = NULL;
        list->tail = NULL;
        list->maxsize = 10;
        list->size = 1;
        Node_d *tmp = (Node_d*) malloc(sizeof(Node_d));
        tmp->next = NULL;
        strcpy(tmp->tel, ntel);
        strcpy(tmp->name, nname);
        list->head = tmp;
        list->tail = tmp;
        (*p) = list;
        printf("Телефон добавлен\n");
    }
    else
    {
        if((*p)->size == (*p)->maxsize) // расширение памяти
        {
            int sizel = 4*((*p)->maxsize);
            List_d *pointer =  (List_d*) malloc(2*((*p)->maxsize)*((*p)->maxsize)*sizeof(List_d));
            memcpy(pointer, (*p), sizel);
            free(*p);
            (*p) = pointer;
            (*p)->maxsize = sizel;
        }
        Node_d *tmp = (Node_d*) malloc(sizeof(Node_d));
        (*p)->head->prev = tmp;
        tmp->next = (*p)->head;
        strcpy(tmp->tel, ntel);
        strcpy(tmp->name, nname);
        printf("Телефон добавлен\n");
    }


    return(0);
}

int searchname(List_d *p, char * nname)
{
    int i = 0;
    printf("Ищем\n");
    if(p == NULL)
    {
        printf("Указатель здесь нулевой\n");
        return (0);
    }
    else
    {
        Node_d *pointer = p->head;
        for(i = 0; ; i++)
        {
            if(strcmp(pointer->name, nname) == 0)
            {
                printf("%s", pointer->tel);
                return(1);
            }
            else
            {
                if(pointer->next == NULL)
                {
                    printf("Не найдено");
                    return(0);
                }
                else
                pointer = pointer->next;
            }
        }
    }
}

int readstr(char *telefon)
{
    int i = 0;
    for(i = 0; ; i++)
    {
        scanf("%c", &telefon[i]);
        if(telefon[i] == '\n' || telefon[i] == '\0')
            break;
    }
    return(0);
}
int deleteelement(List_d *p, char * nname)
{
    int i = 0;
    if(p ==0)
    {
        printf("Элемент не найден");
        return(0);
    }
    else
    {
        Node_d *pointer = p->head;
        for(i = 0; ; i++)
        {
            if(strcmp(pointer->name, nname) == 0)
            {
                pointer->prev->next = pointer->next;
                pointer->next->prev = pointer->prev;
                printf("Элемент удален");
                free(pointer);
                return(1);
            }
            else
            {
                if(pointer->next == NULL)
                {
                    printf("Не найдено");
                    return(0);
                }
                else
                    pointer = pointer->next;
            }
        }
    }

}