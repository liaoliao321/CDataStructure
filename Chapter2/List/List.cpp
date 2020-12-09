#include <cstdlib>
#include "stdio.h"
#include "./List.h"
#define size 10

int main()
{
    List *list;
    initList(list);
    char array[size] = {'b', 'a', 'x', 'q', 'w', 't', 'k'};

    createList(list, array, size);
    add(list, 5, 'O');
    ElemType e;
    remove(list, 5, e);
    printList(list);
    return 0;
}

void createList(List *&l, ElemType a[], int n)
{
    int i = 0, k = 0;
    l = (List *)malloc(sizeof(List));
    while (i < n)
    {
        l->data[k] = a[i];
        i++;
        k++;
    }
    l->length = k;
}
void initList(List *&l)
{
    l = (List *)malloc(sizeof(List));
    l->length = 0;
}
void destroyList(List *&l) { free(l); }
bool isEmpty(List *&l) { return l->length == 0; }
int length(List *&l) { return l->length; }
void printList(List *&l)
{
    int i;
    for (i = 0; i < l->length; i++)
        printf("%c -> ", l->data[i]);
    printf("NULL\n");
}
bool contains(List *&l, int i, ElemType &e)
{
    if (i < 1 || i > l->length)
        return false;
    e = l->data[i - 1];
    return true;
}
int locateElem(List *l, ElemType e)
{
    int i = 0;
    while (i < l->length && l->data[i] != e)
        i++;
    if (i >= l->length)
        return 0;
    else
        return i + 1;
}

bool add(List *&l, int i, ElemType e)
{
    int j;
    if (i < 1 || i > l->length + 1 || l->length == MaxSize)
        return false;
    i--;
    // (j,length) 右移
    for (j = l->length; j > i; j--)
        l->data[j] = l->data[j - 1];

    l->data[i] = e;
    l->length++;
    return true;
}
bool remove(List *&l, int i, ElemType &e)
{
    int j;
    if (i < 1 || i > l->length)
        return false;
    i--;
    e = l->data[i];
    // (j,l->length-1)
    for (j = i; j < l->length - 1; j++)
        l->data[j] = l->data[j + 1];
    l->length--;
    return true;
}