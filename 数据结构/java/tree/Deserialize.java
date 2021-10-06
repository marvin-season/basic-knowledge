package mawenshu.tree;

import java.util.LinkedList;

/**
 * @author 马文澍
 * @date 2021/3/28 8:50
 */
public class Deserialize {
    private static final String NULL = "#";
    private static LinkedList<String> nodes = new LinkedList<>();

    public static void main(String[] args) {
        String data = "1,2,#,4,#,#,3,#,#";
        Node root = deserialize(data);
        int height = getHeight(root);
        System.out.println("height = " + height);

        int size = getSize(root);
        System.out.println("size = " + size);
    }
    // 递归计算二叉树的高度
    public static int getHeight(Node root) {
        return getHeightRecursion(root);
    }
    //  计算结点个数
    public static int getSize(Node root) {
        return getSizeRecursion(root);
    }

    private static int getSizeRecursion(Node root) {
        if (root == null) {
            return 0;
        }

        int leftSize = getSizeRecursion(root.left);
        int rightSize = getSizeRecursion(root.right);
        return leftSize + rightSize + 1;
    }

    private static int getHeightRecursion(Node root) {
        if (root == null) {
            return 0;
        }

        int leftChildHeight = getHeightRecursion(root.left);
        int rightChildHeight = getHeightRecursion(root.right);
        return leftChildHeight > rightChildHeight ? leftChildHeight + 1 : rightChildHeight + 1;
    }

    public static Node deserialize(String data) {
        System.out.println("开始反序列化(先序)");
        for (String s : data.split(",")) {
            nodes.addLast(s);
        }
        return deserialize(nodes);
    }

    private static Node deserialize(LinkedList<String> nodes) {
        if (nodes.isEmpty()) {
            return null;
        }
        String s = nodes.removeFirst();
        if (s.equals(NULL))
            return null;
        int value = Integer.parseInt(s);
        Node node = new Node(value);
        node.left = deserialize(nodes);
        node.right = deserialize(nodes);
        return node;
    }

}
