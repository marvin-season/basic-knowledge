package mawenshu.graph;

/**
 * @author 马文澍
 * @date 2021/4/2 12:11
 */
public class Node {
    Integer val;
    Node[] neighborNodes;

    public Node(Integer val) {
        this.val = val;
        this.neighborNodes = null;
    }
}
