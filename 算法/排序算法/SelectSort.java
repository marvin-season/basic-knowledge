package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/1/23 11:14
 */
public class SelectSort {
    public static void main(String[] args) {
        int[] nums = Nums.nums;
        Nums.show(nums);
        select(nums);
        Nums.show(nums);
    }

    /**
     * 直接选择排序
     * @param nums 排序数
     */
    private static void select(int[] nums) {
        int index;
        //  选择的次数
        for (int i = 0; i < nums.length; i++) {
            index = i;
            //  找到最小的数的下标
            for (int j = i; j < nums.length - 1; j++) {
                index = nums[j + 1] < nums[j] ? (j + 1) : j;
            }
            if (nums[index] < nums[i]) {
                int temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
            }
            Nums.show(nums);
        }
    }
}
