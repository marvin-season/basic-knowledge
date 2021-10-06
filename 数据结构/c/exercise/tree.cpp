#include "iostream"
#include "stdlib.h"

using namespace std;

#define MAX_SIZE 18
int START = 0;

typedef struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
} BiTNode, *BiTNodeP;


typedef struct BiTree {
    BiTNode *root;
} BiTree, *BiTreeP;

BiTreeP createBiTree(int preOrder[18]);

BiTNodeP preOderCreate(int *nums);

//  前序遍历
void preOrderTraverse(BiTreeP treeP);

void preOrderTraverseNode(BiTNode *root);

//  中序遍历
void inOrderTraverse(BiTree *tree);

void inOrderTraverseNode(BiTNode *node);


int main() {
    int preOrder[MAX_SIZE] = {1, 2, 4, -1, 5, -1, -1, 3, -1, 6, 7, -1, 8, 9, -1, -1, -1, -1};
    BiTreeP treeP = createBiTree(preOrder);
    preOrderTraverse(treeP);

    inOrderTraverse(treeP);
    system("pause");
}

void inOrderTraverse(BiTree *tree) {
    if (tree == NULL) {
        cout << "The Tree is not exist" << endl;
        return;
    }
    cout << "\nInOrder Traverse" << endl;

    BiTNode *root = tree->root;
    inOrderTraverseNode(root);
}

void inOrderTraverseNode(BiTNode *node) {
    if (node == NULL) {
        return;
    }
    inOrderTraverseNode(node->left);
    cout << node->data << ends;
    inOrderTraverseNode(node->right);

}

void preOrderTraverse(BiTreeP treeP) {
    if (treeP == NULL) {
        cout << "The BiTree not exist" << endl;
        return;
    }
    BiTNodeP node = treeP->root;
    cout << "\nPreOrder Traverse" << endl;
    preOrderTraverseNode(node);
}

void preOrderTraverseNode(BiTNodeP root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << ends;
    preOrderTraverseNode(root->left);
    preOrderTraverseNode(root->right);
}

BiTreeP createBiTree(int preOrder[18]) {
    BiTree *treeP = (BiTreeP) malloc(sizeof(BiTNode));
    treeP->root = preOderCreate(preOrder);
    return treeP;
}

BiTNodeP preOderCreate(int *nums) {
    if (START >= MAX_SIZE) {
        return NULL;
    }
    if (nums[START] == -1) {
        START++;
        return NULL;
    }
    BiTNode *root = (BiTNode *) malloc(sizeof(BiTNode));
    root->data = nums[START];
    START++;
    root->left = preOderCreate(nums);
    root->right = preOderCreate(nums);
    return root;
}
