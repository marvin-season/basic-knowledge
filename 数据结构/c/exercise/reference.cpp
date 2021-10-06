//
// Created by mawenshu on 2021/4/14.
//

#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkNode;


void update(LinkNode pNode);

int main() {
    LNode node = {1, NULL};

    LinkNode p = (LinkNode) malloc(sizeof(LNode));
    p->data = 11;
    p->next = NULL;
    cout << "before" << p->data << endl;
    update(p);
    cout << "after" << p->data << endl;
    return 0;
}

void update(LinkNode pNode) {
    pNode->data = 22;
}

