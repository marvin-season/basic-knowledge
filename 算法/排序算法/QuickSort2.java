package mawenshu.排序算法;

import java.util.concurrent.TimeUnit;

/**
 * @author 马文澍
 * @date 2021/5/9 13:18
 */
public class QuickSort2 {
    public static void main(String[] args) throws InterruptedException {
        int[] nums = Nums.nums;
        quick(nums, 0, nums.length - 1, 1);
        Nums.show(nums);
    }

    private static void quick(int[] nums, int left, int right, int count) throws InterruptedException {
        print(count);
        count ++;

        int tempLeft = left;
        int tempRight = right;

        if (left >= right) return;

        int pivot = nums[left];

        while (left < right) {
            while (nums[right] >= pivot && right > left) {
                right--;
            }
            nums[left] = nums[right];
            nums[right] = pivot;

            while (nums[left] <= pivot && left < right) {
                left++;
            }

            nums[right] = nums[left];
            nums[left] = pivot;
        }

        quick(nums, tempLeft, left - 1, count);
        count --;
        quick(nums, left + 1, tempRight, count);
    }

    //模拟递归栈
    private static void print(int count) {
        for (int i = 0; i < count*2; i++) {
            System.out.print("*");
        }
        System.out.println();
    }
}
