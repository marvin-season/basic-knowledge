package mawenshu.动态规划;

/**
 * @author 马文澍
 * @date 2021/4/27 8:04
 */
public class Package0_1 {
    private static int capacities = 80;    //  背包容量
    private static int[] weight = {0, 10, 20, 30, 40};    //  物品i的重量， 顺序排好
    private static int[] value = {0, 20, 35, 55, 75}; //对应的价值
    private static int n = 4;

    public static void main(String[] args) {
        //  背包必然不能够全部背下
        //  所以只能挑选合适的来背
        //  假设背包容量为w, 可以背i个,  背包的价值为最大值   int[i][w]
        //  从 前 n 个中， 顺序选一个， 判断是否背了
        //  假设 第 n个没有背,则第n个物品不影响背包现状 int[n][w] = int[n-1][w]
        //  假设 第n个背了, int[n][w] = int[n-1][w-weight[n]] + value[n] n从0开始
        //                             看做是用一个更小容量的包背

        //  int[w][v]  = res
        //  int [0][w] = base = 0 没有物品
        //  int [n][w] = 没有容量
//        System.out.println("action() = " + action());
        System.out.println("recursion(n, capacities) = " + recursion(n, capacities));

    }

    private static int action() {
        int[][] dp = new int[n + 1][capacities + 1];

        //  可供选择的物品下标
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= capacities; w++) {
                //不背,第i个比背包容量重
                if (w - weight[i] < 0) {
                    dp[i][w] = dp[i - 1][w];
                }
                //背
                else {
                    dp[i][w] = Math.max(dp[i - 1][w - weight[i]] + value[i], dp[i - 1][w]);
                }
            }
        }
        return dp[n][capacities];
    }

    private static int recursion(int num, int max) {
        if (num == 0 || max == 0) {
            return 0;
        }

        //  第 num 个物品的重量超过了当前定义背包的最大容量，则不装取当前物品
        if (max - weight[num] < 0) {
            return recursion(num - 1, max);
        } else {
            //  当前物品 装不装， 要看两个选择价值谁比较大
                                                //选择  : 背包容量减少, 价值增加
            return Math.max(recursion(num - 1, max - weight[num]) + value[num], recursion(num - 1, max));
        }
    }
}
