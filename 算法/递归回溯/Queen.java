package mawenshu.递归回溯;

/**
 * @author 马文澍
 * @date 2021/1/21 12:54
 */

/**
 * 经典递归问题
 * 八个皇后占领棋盘，条件是不能在同一行，同一列，同(正反)一对角线
 * 以下按照行遍历每一列(行号可以当做皇后的编号)，递归，为皇后占领位置，自然，不用考虑在同一行的约束条件(一定满足)
 */
public class Queen {
    static int count = 0;
    static int max = 8; // 皇后的个数、棋盘的大小
    static int[] locations = new int[max]; // 皇后n 所在的列的位置

    public static void main(String[] args) {
        findCheck(0);   //从第一个皇后(下标为0，即二维数组的第0行)
    }

    private static void showLocation() {
        System.out.println("方法" + count + " ");
        for (int i = 0; i < max; i++) {
            System.out.print(locations[i] + " ");
        }
        System.out.println();
    }

    private static void showCheckerBoard() {
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                if (locations[i] == j) {
                    System.out.print("√ ");
                } else {
                    System.out.print("# ");
                }
            }
            System.out.println();
        }

    }

    private static void findCheck(int n) {
        if (n == max) {
            count += 1;
            //  最后一个皇后(下标为n-1)已经放置完成
            showLocation();
            showCheckerBoard();
            return;
        }

        //  遍历每一行的每一列 max --> col
        for (int i = 0; i < max; i++) {
            locations[n] = i;   //  第 n个皇后就放在 i列
            //回溯
            if (right(n)) {
                //  判断下一个皇后，即遍历下一行
                findCheck(n + 1);
            }
            //如果i = max -1,并且还不符合要求，那么本次递归的一个函数结束，回溯到上一个皇后的后一种情况
        }
    }

    private static boolean right(int n) {
        //不在同一列
        for (int i = 0; i < n; i++) {
            //  是否在同一列
            //  是否在同一对角线、反对角线
            if (locations[i] == locations[n] || Math.abs(locations[n] - locations[i]) == Math.abs(n - i)) {
                return false;
            }
        }
        return true;
    }
}
