package mawenshu.动态规划;

/**
 * @author 马文澍
 * @date 2021/4/1 23:40
 */
public class MaxProfit2 {
    public static int solve(int[] prices) {
        int n = prices.length;

        int dp_i_0 = 0, dp_i_1 = Integer.MIN_VALUE;
        int temp;

        for (int price : prices) {
            temp = dp_i_0;
            dp_i_0 = Math.max(dp_i_0, dp_i_1 + price);
            dp_i_1 = Math.max(dp_i_1, temp - price);
        }

        return dp_i_0;
    }
}
