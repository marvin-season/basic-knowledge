package mawenshu.动态规划;

import java.util.HashMap;

/**
 * @author 马文澍
 * @date 2021/3/31 19:05
 */
public class Fibs {
    private static final HashMap<Object, Integer> map = new HashMap<>();
    // 1 1 2 3 5 8
    public static void main(String[] args) {
        int f5 = fibs1(5);
        System.out.println("f(5) = " + f5);

        int f6 = fibs2(6);
        System.out.println("f(6) = " + f6);
    }

    public static int fibs1(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        if (map.containsKey(n))
            return map.get(n);

        int val = fibs1(n - 1) + fibs1(n - 2);
        map.put(n, val);

        return val;
    }

    public static int fibs2(int n) {
        int prior = 1, previous = 1;
        int sum = 0;
        for (int i = 0; i < n - 2; i++) {
            sum = previous + prior;
            prior = previous;
            previous = sum;
        }
        return sum;
    }
}
