package mawenshu.动态规划;

/**
 * @author 马文澍
 * @date 2021/5/10 12:49
 */
public class 买股票 {
    public static void main(String[] args) {
        int[] prices = {0, 2, 3, 2, 6, 5, 0, 3};
        int[] prices2 = {2, 1};

        // has no limit of deal count
//        System.out.println("solve(prices) = " + solve(prices));
//        System.out.println("solve(prices, 2) = " + solve(prices, 2));
        System.out.println("maxProfit(1, prices2) = " + maxProfit(1, prices2));
    }

    private static int solve(int[] prices) {
        int len = prices.length;
        // 第六天一定是手里没有股票才能达到 利益最高

        // 状态: 持有股票， 不持股票
        // yes 和 no 代表相应状态的利益
        // no[i] 第 i 天手中没有股票
        int[] no = new int[len];
        // yes[i] 第 i 天手中持有股票
        int[] yes = new int[len];

        // verge: no[6];  > 第六天不持有股票
        // base case: no[1] = 0, yes[1] = -prices[1],

        no[1] = 0;
        yes[1] = -prices[1];

        //  从第二天开始
        for (int i = 2; i < len; i++) {
            // 今天持有股票, 昨天不持有股票,今天才买的股票,  或者昨天就有
            yes[i] = Math.max(no[i - 1] - prices[i], yes[i - 1]);
            // 今天不持有股票， 昨天持有股票， 今天卖了，  或者昨天就不持有
            no[i] = Math.max(yes[i - 1] + prices[i], no[i - 1]);
        }
        return no[len - 1];
    }

    private static int solve(int[] prices, int count) {
        int len = prices.length;
        if (len == 0) return 0;
        int maxCount = (len - 1) / 2;
        count = Math.min(count, maxCount);
        // 限制买卖股票的次数
        // 同上
        // yes[2][1], 表示第二天持有股票，并且做多只能 完成了1次交易
        // no[2][0],  表示第二天不不持有股票，并且进行 0次交易

        // no[i] 第 i 天手中没有股票
        int[][] no = new int[len][count + 1];
        // yes[i] 第 i 天手中持有股票
        int[][] yes = new int[len][count + 1];

        no[1][0] = 0;
        // 第一天持有股票， 交易次数为0
        yes[1][0] = -prices[1];

        for (int i = 1; i <= count; ++i) {
            yes[0][i] = no[0][i] = Integer.MIN_VALUE / 2;
        }

        for (int i = 2; i < len; i++) {
            yes[i][0] = Math.max(yes[i - 1][0], no[i - 1][0] - prices[i]);
        }

        for (int i = 2; i < len; i++) {

            for (int k = 1; k <= count; k++) {
                // 今天持有, 至多完成k笔
                // 昨天就持有，还是第k笔交易,
                // 昨天不持有, 至多完成k笔, 今天才买的，
                yes[i][k] = Math.max(yes[i - 1][k], no[i - 1][k] - prices[i]);
                // 今天不持有,至多完成 k笔
                // 昨天不持有,至多完成 k笔
                // 昨天持有, 至多完成 k-1笔
                no[i][k] = Math.max(no[i - 1][k], yes[i - 1][k - 1] + prices[i]);
            }
        }

        // no[6][count]  第六天不持有股票， 并且至多完成 count 次交易
        return no[len - 1][count];
    }

    public static int maxProfit(int count, int[] prices) {
        int len = prices.length;
        if (len == 0) {
            return 0;
        }

        int maxCount = len / 2;
        count = Math.min(count, maxCount);

        // no[i] 第 i 天手中没有股票
        int[][] no = new int[len][count + 1];
        // yes[i] 第 i 天手中持有股票
        int[][] yes = new int[len][count + 1];

        no[0][0] = 0;
        // 第一天持有股票,
        yes[0][0] = -prices[0];

        // 初始化 不可能的情况，
        for (int i = 1; i <= count; ++i) {
            yes[0][i] = no[0][i] = Integer.MIN_VALUE / 2;
        }

        // 初始化第 i 天 没有完成一次交易的情况
        for (int i = 1; i < len; i++) {
            yes[i][0] = Math.max(yes[i - 1][0], no[i - 1][0] - prices[i]);
        }

        for (int i = 1; i < len; i++) {
            for (int k = 1; k <= count; k++) {
                yes[i][k] = Math.max(yes[i - 1][k], no[i - 1][k] - prices[i]);
                no[i][k] = Math.max(no[i - 1][k], yes[i - 1][k - 1] + prices[i]);
            }
        }

        // no[6][count]  第六天不持有股票， 并且完成了至多 count 次交易
        return no[len - 1][count];
    }
}
