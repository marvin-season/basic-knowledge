package mawenshu.动态规划;

/**
 * @author 马文澍
 * @date 2021/4/1 21:51
 */
public class MaxProfit4 {
    public static void main(String[] args) {
        int[] prices = {3,3,5,0,0,3,1,4};
        int k = 2;
        int solve = solve(k, prices);
        System.out.println(solve);
    }

    public static int solve(int maxK, int[] prices) {
        int n = prices.length;

        if (maxK > n / 2) {
            return MaxProfit2.solve(prices);
        }

//        int[][][] dp = new int[n][maxK + 1][2];
        // dp[i][k][0]
        // verge:   dp[n-1][k][0]  最后一天， 完成了k笔交易， 手中不持有股票
        //  base case:  dp[0][0][0] = 0  dp[0][0][1] = -prices[0]

        int dp_i_k_0 = 0;
        int dp_i_k_1 = Integer.MIN_VALUE;
        int temp;

        for (int price : prices) {
            for (int k = 1; k <= maxK; k++) {
                temp = dp_i_k_0;
                //  第 i天 至多能完成k笔交易， 不持有股票
                dp_i_k_0 = Math.max(dp_i_k_0, dp_i_k_1 + price);
                dp_i_k_1 = Math.max(dp_i_k_1, temp - price);
            }
        }

        return dp_i_k_0;
    }
}
