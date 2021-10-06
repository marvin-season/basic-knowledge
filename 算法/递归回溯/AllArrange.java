package mawenshu.递归回溯;

import java.util.LinkedList;

/**
 * @author 马文澍
 * @date 2021/4/27 7:34
 */
public class AllArrange {
    //  用于保存每条路径上的值
    private static LinkedList<Integer> list = new LinkedList<>();

    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        arrange(nums, list);
    }

    //
    private static void arrange(int[] nums, LinkedList<Integer> list) {
        if (list.size() == nums.length) {
            list.forEach(System.out::print);
            System.out.println();
            return;
        }

        //  从nums中选择一个作为路径
        /**
         *                  〇
         *              1/  |3  \2
         *             〇
         *           2/  \3
         *          〇
         *          |3
         */
        for (int num : nums) {
            if (list.contains(num)) {
                continue;
            }
            //  执行操作
            list.addLast(num);
            arrange(nums, list);
            //  撤销操作
            list.removeLast();
        }
    }
}
