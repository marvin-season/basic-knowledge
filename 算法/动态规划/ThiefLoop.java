package mawenshu.动态规划;

/**
 * @author 马文澍
 * @date 2021/3/31 20:04
 */
// 题在 ThiefLine的基础上约束,环形排列的房间
public class ThiefLoop {
    //        int[] nums = {1, 2, 3, 4, 5, 6, 7};
    // 1， 7不能同时偷
    public static void main(String[] args) {
        int[] nums = {8, 2, 3, 4, 5, 6, 7};
        int solve = rob(nums);
        System.out.println(solve);
    }

    private static int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        // [0...n -2]  [1...n -1]
        return Math.max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

    private static int robRange(int[] nums, int start, int end) {
        // dp dp_1 dp_2
        int dp_1 = 0;
        int dp_2 = 0;
        int dp = 0;

        //  从最后一个开始偷, 闭区间
        for (int i = end; i >= start; i--) {
            dp = Math.max(nums[i] + dp_2, dp_1);
            dp_2 = dp_1;
            dp_1 = dp;
        }
        return dp;
    }
}
