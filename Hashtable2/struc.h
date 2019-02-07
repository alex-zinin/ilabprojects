//
// Created by alexzinin on 09.12.18.
//
#include<iostream>
#ifndef UNTITLED6_STRUC_H
#define UNTITLED6_STRUC_H

#endif //UNTITLED6_STRUC_H
using namespace std;

class List_d;
class Node_d
{
    friend int addelement(List_d **p, char * nname, char * ntel);
    friend int searchname(List_d *p, char * nname);
    friend int deleteelement(List_d *p, char * nname);
private:
    int value;
    struct Node_d *next;
    struct Node_d *prev;

    char name[50], tel[20];
};


class List_d
{
    friend int addelement(List_d **p, char * nname, char * ntel);
    friend int searchname(List_d *p, char * nname);
    friend int deleteelement(List_d *p, char * nname);
private:
    int size = 0;
    int maxsize = 0;
    Node_d *head;
    Node_d *tail;
};

class base: public Node_d, public List_d
{
private:
    string name;
};

