package mawenshu.tree;

import java.io.Serializable;

/**
 * @author 马文澍
 * @date 2021/3/28 8:18
 */
public class Node {
    int value;
    Node left;
    Node right;
    public Node(int value){
        this.value = value;
        this.left = null;
        this.right = null;
    }
}
