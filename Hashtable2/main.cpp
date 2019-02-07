#include <stdio.h>
#include "listz.h"

using namespace std;

int main() {


    char telefon[15], nname[25];
    int i = 0, h = 0;
    List_d *num[10000] = {};
    FILE* fp = fopen("tut.txt", "a+");

    fclose(fp);

    printf("Наберите имя и телефон");
    readstr(nname);
    readstr(telefon);
    h = hashstring( nname);
    //printf("%s%s\n", nname, telefon);
   //printf("Хэш элемента = %d\n", h);

    addelement(&num[h], nname,  telefon);
    searchname(num[h],nname);


    return 0;
}