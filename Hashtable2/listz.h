//
// Created by alexzinin on 09.12.18.
//

#ifndef UNTITLED6_LISTZ_H
#define UNTITLED6_LISTZ_H

#endif //UNTITLED6_LISTZ_H

#include "struc.h"

List_d* creature_dlist ();
void pushfront(List_d **list, int data); // push on the top
int popfront(List_d **list); // pop on the top
void push(List_d **list, int n, int data);  // push on n position
int printfront(List_d **list); // print last element
int hashstring(char * a);
int addelement(List_d **p, char * name, char * telef);
int searchname(List_d *p, char * nname);
int readstr(char *telefon);
int deleteelement(List_d *p, char * nname);