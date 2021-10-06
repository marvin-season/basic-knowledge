package mawenshu.btree;

import mawenshu.btree.linkdetree.LinkedBinaryTree;
import mawenshu.btree.linkdetree.Node;

/**
 * @author 马文澍
 * @date 2021/1/15 12:32
 */
public class TestLinkedBinaryTree {
    public static void main(String[] args) {
        Node node7 = new Node(7, null, null);
        Node node6 = new Node(6, null, node7);
        Node node3 = new Node(3, null, null);
        Node node5 = new Node(5, null, null);
        Node node2 = new Node(2, node3, node6);
        Node node4 = new Node(4, null, node5);
        Node node1 = new Node(1, node4, node2);

        LinkedBinaryTree tree = new LinkedBinaryTree(node1);

        System.out.println("先序遍历");
        //  先序遍历 1 4 5 2 3 6 7
        tree.preOrderTraverse();
        System.out.println("");
        //  4 5 1 3 2 6 7
        tree.inOrderTraverse();
        //  5 4 3 7 6 2 1
        tree.postOrderTraverse();

        System.out.println(tree.getHeight());
//        tree = new LinkedBinaryTree();
        System.out.println(tree.getSize());

        tree.floorOrderTraverse();
        tree.floorOrderTraverse2();
        tree.inOrderStack();
        tree.inOrderTraverseByStack();
        tree.preOrderStack();
    }
}
