#include <iostream>
#include "stdio.h"
#include "stdlib.h"

using namespace std;

#define MAX_SIZE 10
typedef int ElementData;

typedef struct ArrayList
{
    int size;
    ElementData elements[MAX_SIZE];

} ArrayList;

void init(ArrayList *list)
{
    list->size = 0;
    cout << "init successfully" << ends
         << "size = " << list->size << endl;
}

//	给点下标添加元素
void add(ArrayList *list, int index, ElementData data)
{
    if (index > list->size)
    {
        cout << "插入下标越界" << endl;
        return;
    }
    else if (index == list->size)
    {
        list->elements[index] = data;
        list->size++;
    }
    else
    {
        //	将所有index的元素向后移一位
        for (int i = list->size; i > index; i--)
        {
            list->elements[i] = list->elements[i - 1];
        }
        //	新元素插入
        list->elements[index] = data;
        //	元素个数 +1
        list->size++;
    }
}

void add(ArrayList *list, ElementData data)
{
    add(list, list->size, data);
}

int get(ArrayList *list, int index)
{
    if (index >= list->size)
    {
        cout << "index out of bound" << endl;
        system("exit");
    }
    return list->elements[index];
}
ElementData remove(ArrayList *list, int index)
{
    if (index < 0)
    {
        return -1;
    }
    if (index >= list->size)
    {
        return -1;
    }
    ElementData temp = list->elements[index];

    list->size--;
    for (int i = index; i < list->size; i++)
    {
        list->elements[i] = list->elements[i + 1];
    }
    return temp;
}

void show(ArrayList *list)
{
    for (int i = 0; i < list->size; i++)
    {
        cout << list->elements[i] << ends;
    }
    cout << endl;
}
int main()
{
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    init(list);
    add(list, 10);
    add(list, 9);
    add(list, 8);
    add(list, 7);

    show(list);
    remove(list, 0);
    show(list);
    add(list, 2, 100);
    show(list);
    return 0;
}