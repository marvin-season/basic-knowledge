package mawenshu.btree;

public interface BinaryTree {

    boolean isEmpty();

    int getSize();

    int getHeight();

    //  先序遍历
    void preOrderTraverse();

    //  中序遍历
    void inOrderTraverse();

    //  非递归中序遍历
    void inOrderTraverseByStack();

    //  后序遍历
    void postOrderTraverse();

    //  层序遍历
    void floorOrderTraverse();
}
