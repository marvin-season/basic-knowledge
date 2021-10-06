#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data = 0;
    struct Node *next;

} Node;

void add(Node *head, int data)
{
    Node *p = head;
    // while (p->next)
    // {
    //     p = p->next;
    // }
    for (int i = 0; i < head->data; i++)
    {
        p = p->next;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    p->next = temp;

    head->data++;
    printf("add successfully and total size = %d\n", head->data);
}
void show(Node *head)
{
    if (head->data == 0)
    {
        printf("NULL");
        return;
    }
    Node *p = head->next;

    // while (p)
    // {
    //     printf("%d ", p->data);
    //     p = p->next;
    // }
    for (int i = 0; i < head->data; i++)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    add(head, 22);
    add(head, 33);
    add(head, 44);
    show(head);
    return 0;
}