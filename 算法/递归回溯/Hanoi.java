package mawenshu.递归回溯;

/**
 * @author 马文澍
 * @date 2021/2/1 13:53
 */
public class Hanoi {
    public static void main(String[] args) {
        hanoi(2, "a", "b", "c");
    }

    //  将 a 移动到 c, b 为辅助
    private static void hanoi(int n, String a, String b, String c) {
        if (n != 1) {

            //  上面的 n-1个从 a->b
            hanoi(n - 1, a, c, b);
            System.out.format("%s=====>%s\n", a, c);

            hanoi(n - 1, b, a, c);

        } else {
            System.out.format("%s=====>%s\n", a, c);
        }
    }
}
