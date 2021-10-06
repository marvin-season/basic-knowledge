package mawenshu.动态规划;

/**
 * @author 马文澍
 * @date 2021/4/1 21:51
 */
public class MaxProfit1 {
    public static void main(String[] args) {
        int[] prices = {7, 1, 5, 3, 6, 4};
        System.out.println("violent(prices) = " + violent(prices));
        violent2(prices);
        solve(prices);
    }

    //  常规遍历暴力
    public static int violent(int[] prices) {
        int maxProfit = -prices[0];
        //  选择某一天买  i
        //  固定 买,找最大的卖
        for (int buy = 0; buy < prices.length; buy++) {
            //  遍历后面哪几天卖， i + 1  ---  n
            for (int sell = buy + 1; sell < prices.length; sell++) {
                maxProfit = Math.max(maxProfit, prices[sell] - prices[buy]);
            }
        }
        return maxProfit;

    }

    //  稍微进阶的暴力破解法
    public static int violent2(int[] prices) {
        //  最大利润
        int maxProfit = 0;
        //  买的股票价格， 且当前选择是最低收购
        int minBuy = Integer.MAX_VALUE;
        for (int sell = 1; sell < prices.length; sell++) {
            minBuy = Math.min(prices[sell - 1], minBuy);
            maxProfit = Math.max(maxProfit, prices[sell] - minBuy);
        }

        return maxProfit;
    }

    public static int solve(int[] prices) {

        /* dp[i][0]  第 i天卖出股票 最高 利润值, 0 表示不持有股票
         * dp[i][0]     =   max(dp[i-1][0],    dp[i-1][1] + prices[i])
         * 第 i天不持有股票   第 i-1天不持有股票   或者   第i-1天持有股票, 今天卖了
         * 最终  dp[n-1][0]
         * base case  dp[0][0] = 0;
         */
        int n = prices.length;
        int[][] dp = new int[n][2];

        for (int day = 0; day < n; day++) {
            if (day - 1 == -1) {
                dp[day][0] = 0;
                dp[day][1] = -prices[day];
                continue;
            }
            dp[day][0] = Math.max(dp[day - 1][0], dp[day - 1][1] + prices[day]);
            //  dp[day][1] = Math.max(dp[day - 1][1], dp[day - 1][0] - prices[day]);
            //                                      昨天不持有股票，今天才买的
            //                                      况且题目中只能买卖一次， 所以今天之前的天数获得的利润为0
            dp[day][1] = Math.max(dp[day - 1][1], -prices[day]);
        }

        return dp[n - 1][0];
    }


}
