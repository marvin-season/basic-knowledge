package mawenshu.二叉树;

/**
 * @author 马文澍
 * @date 2021/3/30 19:59
 * 序列化二叉树
 */
public class LC654 {
    public static void main(String[] args) {
        int[] nums = {3, 2, 1, 6, 0, 5};
        solve(nums);
    }

    public static void solve(int[] nums) {
        // [] 闭区间
        Node root = build(nums, 0, nums.length - 1);
        IterTree.LayerTraverseTree(root);
    }

    private static Node build(int[] nums, int start, int end) {

        System.out.println(start + " " + end);
        if (start > end) {
            return null;
        }

        int maxVal = Integer.MIN_VALUE;
        int tempIndex = 0;
        for (int i = start; i <= end; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                tempIndex = i;
            }
        }

        Node node = new Node(maxVal);
        node.left = build(nums, start, tempIndex - 1);
        node.right = build(nums, tempIndex + 1, end);
        return node;
    }
}
