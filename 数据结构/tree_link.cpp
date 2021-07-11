//
// Created by mawenshu on 2021/5/13.
//
#include "cstdio"
#include "cstdlib"
#include "cstring"

#define MAX         100
#define ElementType char
#define isLetter(a) ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a)   (sizeof(a)/sizeof(a[0]))

// 二叉树结点
typedef struct node {
    ElementType data;
    struct node *left;
    struct node *right;
} Node;

typedef struct btree {
    Node *root;
} BiTree;

// 链表结点
typedef struct ListNode {
    ElementType data;
    struct ListNode *next;
} ListNode;

typedef struct LinkedList {
    ListNode *head; // 头结点， 数据域不存数据
} LinkedList;


LinkedList *create_linked_list();


void add_last_linked_list(LinkedList *linkedList, char data);

ListNode *remove_first_linked_list(LinkedList *linkedList);

char read_char();

void iter_linked_list(LinkedList list);

BiTree *create_tree_deserialize(LinkedList *linkedList);

Node *create_tree_deserialize_(LinkedList *linkedList);

void pre_order_traverse(BiTree btree);

void pre_order(Node *root);

void floor_traverse(BiTree btree);

void floor(Node *root);

void pre_order_stack(BiTree btree);

void in_order_stack(BiTree btree);

void post_order_stack(BiTree btree);

void in_order_traverse(BiTree btree);

void post_order_traverse(BiTree btree);

void post_order(Node *root);

void in_order(Node *root);

int main() {
    LinkedList *linkedList = create_linked_list();

    BiTree *biTree = create_tree_deserialize(linkedList);
    pre_order_traverse(*biTree);
    pre_order_stack(*biTree);
    in_order_traverse(*biTree);
    in_order_stack(*biTree);
    post_order_traverse(*biTree);
    post_order_stack(*biTree);
    floor_traverse(*biTree);
    return 0;
}

void post_order_traverse(BiTree btree) {
    printf("后序遍历: \n");
    post_order(btree.root);
    printf("\n");
}

void post_order(Node *root) {
    if (root == NULL) {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    printf("%c ", root->data);

}

void in_order_traverse(BiTree btree) {
    printf("中序遍历: \n");
    in_order(btree.root);
    printf("\n");
}

void in_order(Node *root) {
    if (root == NULL) {
        return;
    }
    in_order(root->left);
    printf("%c ", root->data);
    in_order(root->right);
}

void pre_order_traverse(BiTree btree) {
    printf("先序遍历: \n");
    pre_order(btree.root);
    printf("\n");
}

void pre_order(Node *root) {
    if (root == NULL) {
        return;
    }

    printf("%c ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

/**
 * 借助栈实现后序遍历
 * @param btree
 */
void post_order_stack(BiTree btree) {
    printf("后序遍历(栈):\n");

    Node *stack[MAX]; // 模拟栈
    int top = 0; // 栈顶指针
    Node *current = btree.root;

    printf("\n");
}

/**
 * 借助栈实现中序遍历
 * @param btree
 */
void in_order_stack(BiTree btree) {

    printf("中序遍历(栈):\n");

    Node *stack[MAX]; // 模拟栈
    int top = 0; // 栈顶指针
    Node *current = btree.root;

    while (top > 0 || current != NULL) {
        while (current != NULL) {
            stack[top++] = current;
            current = current->left;
        }
        // current 为最后一个结点的左孩子
        if (top > 0) {
            current = stack[--top];
            printf("%c ", current->data);
            current = current->right;
        }
    }
    printf("\n");

}

/**
 * 借助栈实现先序遍历
 * @param btree 
 */
void pre_order_stack(BiTree btree) {
    printf("先序遍历(栈):\n");
    Node *root = btree.root;

    if (root == NULL) {
        return;
    }

    Node *stack[MAX]; // 模拟栈
    int top = 0; // 栈顶指针
    Node *current = root;

    while (current != NULL || top > 0) {
        // 将所有的根结点压入栈
        while (current != NULL) {
            printf("%c ", current->data); // 先访问即为先序遍历
            stack[top++] = current; // 根结点入栈
            current = current->left;
        }
        // 更新当前结点为其右孩子
        // 如果没有有孩子，当前结点更新为NULL, 继续出栈，
        // 如果有右孩子， 则将右孩子当成一个新的数的根结点进行遍历
        if (top > 0) {
            // 注意先 top - 1
            current = stack[--top]; // 出栈
            current = current->right;
        }
    }
    printf("\n");
}

void floor_traverse(BiTree btree) {
    printf("层序遍历:\n");
    Node *root = btree.root;
    floor(root);
}

void floor(Node *root) {
    if (root == NULL) {
        return;
    }
    // 模拟一个顺序队列
    Node queue[MAX];
    int rear = 0, front = 0, size = 0;
    // 根结点先入队列
    queue[rear++] = *root;
    // 整体的逻辑就是，先入队列根结点， 再入队列孩子结点
    while (rear != front) {
        size = rear - front;
        //分层打印
        for (int i = 0; i < size; ++i) {
            Node node = queue[front++];
            printf("%c ", node.data); //访问数据

            if (node.left != NULL) {
                queue[rear++] = *(node.left);
            }
            if (node.right != NULL) {
                queue[rear++] = *(node.right);
            }
        }
        printf("\n");
    }
}

void iter_linked_list(LinkedList list) {
    printf("\nlist data:\n");
    ListNode *temp = list.head;
    while (temp->next != NULL) {
        temp = temp->next;
        printf("%c ", temp->data);
    }
    printf("\n");
}

char read_char() {
    char ch;
    do {
        ch = (char) getchar();
    } while (!isLetter(ch));

    return ch;
}

ListNode *remove_first_linked_list(LinkedList *linkedList) {
    ListNode *head = linkedList->head;
    if (head->next == NULL) {
        return NULL;
    }
    ListNode *node = head->next;
    //      head->next = node->next;
    head->next = head->next->next;

    return node;
}

void add_last_linked_list(LinkedList *linkedList, char data) {
    ListNode *temp = linkedList->head;

    // 为数据data构造结点
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;

    // 将node 连接到链表的末尾
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // temp就是最后一个结点
    temp->next = node;
}


LinkedList *create_linked_list() {
    // 头结点不存储任何东西
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->data = ' ';
    node->next = NULL;

    LinkedList *linkedList = (LinkedList *) malloc(sizeof(ListNode));
    linkedList->head = node;

    return linkedList;
}

// 先序顺序的 结点数组， '#' 表示空节点
char nodes[] = {'a', 'b', '#', 'd', '#', '#', 'c', '#', '#'};
//char nodes[] = {'C', 'A', 'D', '#', '#', 'E', 'F', '#', '#', 'G', '#', '#', 'B', '#', 'H', '#', 'I', '#', '#'};

/*
 * 序列化指定好的序列
 */
BiTree *create_tree_deserialize(LinkedList *linkedList) {
    int size = LENGTH(nodes);
    // 将结点信息先存到链表
    for (int i = 0; i < size; ++i) {
        add_last_linked_list(linkedList, nodes[i]);
    }
    iter_linked_list(*linkedList);
    ListNode *listNode;

    BiTree *biTree = (BiTree *) malloc(sizeof(BiTree));
    biTree->root = create_tree_deserialize_(linkedList);
    return biTree;
}

Node *create_tree_deserialize_(LinkedList *linkedList) {
//    return NULL;
    ListNode *head = linkedList->head; // 链表头结点

    // 链表空， 直接返回
    if (head->next == NULL) {
        printf("...NULL\n");
        return NULL;
    }
    // 一次从序列头移除一个
    ListNode *listNode = remove_first_linked_list(linkedList);
    // 链表的第一个要 反序列化的结点为 #, 表示空， 返回空
    if (listNode->data == '#') {
        free(listNode);
        return NULL;
    }
    Node *root = (Node *) malloc(sizeof(Node));

    root->data = listNode->data;
    free(listNode); //释放资源

    // 按照先序遍历顺序反序列化
    root->left = create_tree_deserialize_(linkedList);
    root->right = create_tree_deserialize_(linkedList);

    return root;
}


