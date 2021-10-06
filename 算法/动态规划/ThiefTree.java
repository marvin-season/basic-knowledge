package mawenshu.动态规划;

import mawenshu.二叉树.Node;

import java.util.HashMap;
import java.util.LinkedList;

/**
 * @author 马文澍
 * @date 2021/3/31 20:40
 */
public class ThiefTree {
    private static HashMap<Object, Integer> map = new HashMap<>();

    //同Thief，只不过房间结构又变成的树
    public static void main(String[] args) {
        int[] nums = {3, 4, 1, 4, 5, 1};

        LinkedList<Integer> list = new LinkedList<>();
        for (int num : nums) {
            list.addLast(num);
        }
        System.out.println(list);
        Node root = getTree(list);

        int traverse = traverse(root);
        System.out.println(traverse);
    }

    private static int traverse(Node root) {
        if (root == null) {
            return 0;
        }

        if (map.containsKey(root)) {
            return map.get(root);
        }

        //偷当前结点
        int do_it = root.value;

        //  孙子节点如果不为空都可以偷
        if (root.left != null) {
            do_it += traverse(root.left.left) + traverse(root.left.right);
        }
        if (root.right != null) {
            do_it += traverse(root.right.left) + traverse(root.right.left);
        }

        // 不偷当前结点
        int not_do = traverse(root.left) + traverse(root.right);

        int max = Math.max(do_it, not_do);
        map.put(root, max);
        return max;
    }

    //先序
    private static Node getTree(LinkedList<Integer> list) {
        if (list.isEmpty()) {
            return null;
        }
        Integer val = list.removeFirst();

        Node root = new Node(val);
        root.left = getTree(list);
        root.right = getTree(list);

        return root;
    }

}
