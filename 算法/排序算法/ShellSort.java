package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/1/24 17:22
 */
public class ShellSort {
    public static void main(String[] args) {
        int[] nums = Nums.nums;
        Nums.show(nums);
        shellSort(nums);
    }

    /**
     * nums[0] = nums[i];
     * int j;
     * for (j = i - increment; j > 0 && nums[0] < nums[j]; j -= increment) {
     * nums[j + increment] = nums[j];
     * }
     * nums[j + increment] = nums[0];
     * Nums.show(nums);
     */
    private static void shellSort(int[] nums) {
        int increment = nums.length;
        int temp = 0;

        do {
            //  increment = 4
            increment = increment / 3 + 1;
            for (int i = increment; i < nums.length; i++) {
                if (nums[i] < nums[i - increment]) {
                    temp = nums[i];
                    int j;
                    //  再直接插入排序，temp:当前要进行插入的数据,nums[j] 前一个数据
                    for (j = i - increment; j >= 0 && temp < nums[j]; j -= increment) {
                        //  当前这个数据(nums[i])的位置存放前面一个增量的数
                        nums[j + increment] = nums[j];
                    }
                    //  退出循环，最前面的一个增量值处的数 = 当前位置的数 nums[i]
                    nums[j + increment] = temp;
                    Nums.show(nums);
                }
            }

        } while (increment > 1);
    }
}
