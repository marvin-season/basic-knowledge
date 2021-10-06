package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/1/22 16:31
 */
public class BubbleSort {

    public static void main(String[] args) {
        int[] nums = Nums.nums;
        bubbleToBig(nums);
        Nums.show(nums);
        bubbleToSmall(nums);
        Nums.show(nums);
    }

    private static void bubbleToSmall(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            //  从后往前遍历
            for (int j = nums.length - 1; j > i; j--) {
                if (nums[j] > nums[j - 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j - 1];
                    nums[j - 1] = temp;
                }
            }
        }
    }


    private static void bubbleToBig(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            //  从前往后遍历
            for (int j = 0; j < nums.length - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
}
