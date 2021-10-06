package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/1/22 16:57
 */
public class Nums {
    static int[] nums = {49, 38, 65, 97, 76, 13, 27, 49};

    public static void main(String[] args) {
        int[] ns = {1, 2, 5, 7, 3};
        Nums.show(ns);
        Nums.insert(ns, 4);
        Nums.show(ns);
    }

    //    static int[] nums = {6, 1, 8, 2, 7, 5, 0, 4, 3, 9,-1};
    public static void show(int[] nums) {
        for (int i : nums) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void insert(int[] ns, int index) {
        int temp = ns[index];

        int i;
        for (i = index; i > 0 && ns[i] >= ns[index]; i--) {
            ns[i] = ns[i - 1];
        }
        ns[i] = temp;
    }
}
