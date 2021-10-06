package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/5/9 10:31
 */
public class SelectSort2 {
    public static void main(String[] args) {
        int[] nums = {3,2,1};
        select(nums);
        Nums.show(nums);
    }

    private static void select(int[] nums) {
        int min = 9999;
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] < min) {
                    min ^= nums[j];
                    nums[j] ^= min;
                    min ^= nums[j];
                }
            }
            min ^= nums[i];
            nums[i] ^= min;
            min ^= nums[i];
        }
    }
}
