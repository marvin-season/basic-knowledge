package mawenshu.动态规划;

/**
 * @author 马文澍
 * @date 2021/3/31 19:25
 */
//  小偷偷东西  1 2 3 4 5 6
public class ThiefLine {

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 6, 7};
        int solve = solve(nums);
        System.out.println(solve);

        int recursion = recursion(nums, 0);
        System.out.println(recursion);
    }

    //  小偷不能偷相邻的房间， 求偷到的东西最多是多少
    private static int solve(int[] nums) {
        //  房间号就是数组nums的下标
        //  小偷经过每个房间，可以选择偷， 或者不偷
        //  如果偷，则下一个可以偷的房间至少是 下下个房间，
        //  如果不偷当前房间，则去下家

        //  小偷如果都没有选择偷， 那么小偷最终所得到的东西 数量为 0
        //  dp[n] = 0   房间号： 0 ~ n-1, n 表示从房间号n(第n + 1个房间号: 实际上不存在)开始偷(前面 n 个房都没偷)
        //  * 注意下标从0开始
        int n = nums.length;
        int[] dp = new int[n + 2];
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            //  dp数组含义， 表示 当从第i家起， 小偷所能偷到的最大的 数量
            int do_it = nums[i] + dp[i + 2];  /* 偷第 i 家*/
            int not_do = dp[i + 1];   /*没偷第 i 家*/
            dp[i] = Math.max(do_it, not_do);
        }

        return dp[0];
    }

    //  递归回溯， 从第一个开始偷
    public static int recursion(int[] nums, int start) {
        if (start >= nums.length) {
            return 0;
        }
        int do_it = nums[start] + recursion(nums, start + 2);
        int not_do = recursion(nums, start + 1);

        return Math.max(do_it, not_do);
    }
}
