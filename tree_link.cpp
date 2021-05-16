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

// ���������
typedef struct node {
    ElementType data;
    struct node *left;
    struct node *right;
} Node;

typedef struct btree {
    Node *root;
} BiTree;

// ������
typedef struct ListNode {
    ElementType data;
    struct ListNode *next;
} ListNode;

typedef struct LinkedList {
    ListNode *head; // ͷ��㣬 �����򲻴�����
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
    printf("�������: \n");
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
    printf("�������: \n");
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
    printf("�������: \n");
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
 * ����ջʵ�ֺ������
 * @param btree
 */
void post_order_stack(BiTree btree) {
    printf("�������(ջ):\n");

    Node *stack[MAX]; // ģ��ջ
    int top = 0; // ջ��ָ��
    Node *current = btree.root;

    printf("\n");
}

/**
 * ����ջʵ���������
 * @param btree
 */
void in_order_stack(BiTree btree) {

    printf("�������(ջ):\n");

    Node *stack[MAX]; // ģ��ջ
    int top = 0; // ջ��ָ��
    Node *current = btree.root;

    while (top > 0 || current != NULL) {
        while (current != NULL) {
            stack[top++] = current;
            current = current->left;
        }
        // current Ϊ���һ����������
        if (top > 0) {
            current = stack[--top];
            printf("%c ", current->data);
            current = current->right;
        }
    }
    printf("\n");

}

/**
 * ����ջʵ���������
 * @param btree 
 */
void pre_order_stack(BiTree btree) {
    printf("�������(ջ):\n");
    Node *root = btree.root;

    if (root == NULL) {
        return;
    }

    Node *stack[MAX]; // ģ��ջ
    int top = 0; // ջ��ָ��
    Node *current = root;

    while (current != NULL || top > 0) {
        // �����еĸ����ѹ��ջ
        while (current != NULL) {
            printf("%c ", current->data); // �ȷ��ʼ�Ϊ�������
            stack[top++] = current; // �������ջ
            current = current->left;
        }
        // ���µ�ǰ���Ϊ���Һ���
        // ���û���к��ӣ���ǰ������ΪNULL, ������ջ��
        // ������Һ��ӣ� ���Һ��ӵ���һ���µ����ĸ������б���
        if (top > 0) {
            // ע���� top - 1
            current = stack[--top]; // ��ջ
            current = current->right;
        }
    }
    printf("\n");
}

void floor_traverse(BiTree btree) {
    printf("�������:\n");
    Node *root = btree.root;
    floor(root);
}

void floor(Node *root) {
    if (root == NULL) {
        return;
    }
    // ģ��һ��˳�����
    Node queue[MAX];
    int rear = 0, front = 0, size = 0;
    // ������������
    queue[rear++] = *root;
    // ������߼����ǣ�������и���㣬 ������к��ӽ��
    while (rear != front) {
        size = rear - front;
        //�ֲ��ӡ
        for (int i = 0; i < size; ++i) {
            Node node = queue[front++];
            printf("%c ", node.data); //��������

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

    // Ϊ����data������
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;

    // ��node ���ӵ������ĩβ
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // temp�������һ�����
    temp->next = node;
}


LinkedList *create_linked_list() {
    // ͷ��㲻�洢�κζ���
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->data = ' ';
    node->next = NULL;

    LinkedList *linkedList = (LinkedList *) malloc(sizeof(ListNode));
    linkedList->head = node;

    return linkedList;
}

// ����˳��� ������飬 '#' ��ʾ�սڵ�
char nodes[] = {'a', 'b', '#', 'd', '#', '#', 'c', '#', '#'};
//char nodes[] = {'C', 'A', 'D', '#', '#', 'E', 'F', '#', '#', 'G', '#', '#', 'B', '#', 'H', '#', 'I', '#', '#'};

/*
 * ���л�ָ���õ�����
 */
BiTree *create_tree_deserialize(LinkedList *linkedList) {
    int size = LENGTH(nodes);
    // �������Ϣ�ȴ浽����
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
    ListNode *head = linkedList->head; // ����ͷ���

    // ����գ� ֱ�ӷ���
    if (head->next == NULL) {
        printf("...NULL\n");
        return NULL;
    }
    // һ�δ�����ͷ�Ƴ�һ��
    ListNode *listNode = remove_first_linked_list(linkedList);
    // ����ĵ�һ��Ҫ �����л��Ľ��Ϊ #, ��ʾ�գ� ���ؿ�
    if (listNode->data == '#') {
        free(listNode);
        return NULL;
    }
    Node *root = (Node *) malloc(sizeof(Node));

    root->data = listNode->data;
    free(listNode); //�ͷ���Դ

    // �����������˳�����л�
    root->left = create_tree_deserialize_(linkedList);
    root->right = create_tree_deserialize_(linkedList);

    return root;
}


