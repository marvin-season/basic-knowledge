package mawenshu.btree.linkdetree;

/**
 * @author 马文澍
 * @date 2021/1/15 12:31
 */
public class Node {
    Object data;
    Node leftChild;
    Node rightChild;

    public Node() {
    }

    public Node(Object data, Node leftChild, Node rightChild) {
        this.data = data;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
    }
}
