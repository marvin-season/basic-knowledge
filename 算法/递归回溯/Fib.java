package mawenshu.递归回溯;

/**
 * @author 马文澍
 * @date 2021/1/23 10:56
 */
public class Fib {
    public static void main(String[] args) {
        //  1 1 2 3 5 8 13
        int fib = fib(7);
        System.out.println("fib = " + fib);
    }

    private static int fib(int i) {
        if (i <= 2) {
            return 1;
        }
        return fib(i - 2) + fib(i - 1);
    }
}
