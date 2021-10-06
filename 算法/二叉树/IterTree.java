package mawenshu.二叉树;

import java.util.LinkedList;

/**
 * @author 马文澍
 * @date 2021/3/30 20:16
 */
public class IterTree {
    public static void PreTraversTree(Node root) {
        System.out.println("先序遍历结果");
        preTraverse(root);
    }

    private static void preTraverse(Node root) {
        if (root == null)
            return;
        System.out.print(root.value + " ");
        preTraverse(root.left);
        preTraverse(root.right);
    }

    public static void LayerTraverseTree(Node root) {
        System.out.println("层序遍历");
        LayerTraverse(root);
    }

    private static void LayerTraverse(Node root) {
        LinkedList<Node> queue = new LinkedList<>();
        queue.addLast(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                Node node = queue.removeFirst();
                System.out.print(node.value + " ");

                if (node.left != null)
                    queue.addLast(node.left);
                if (node.right != null)
                    queue.addLast(node.right);
            }
        }
    }
}
