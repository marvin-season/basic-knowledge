package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/5/8 11:28
 */
public class MergeSort2 {
    public static void main(String[] args) {
        int[] nums = Nums.nums;
        mergerSort(nums);
    }

    private static void mergerSort(int[] nums) {
        mSort(nums, nums, 0, nums.length);
        // 4 13 27 38 49 49 55 65 76 97
    }

    // 将 序列放入 target进行分治排序
    private static void mSort(int[] nums, int[] target, int left, int right) {
        if (right - left == 1) {
            // only one,it is not necessary to mSort for target
            target[0] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        int[] leftTemp = new int[mid - left];
        int[] rightTemp = new int[right - mid];
        mSort(nums, leftTemp, left, mid);

        mSort(nums, rightTemp, mid, right);

        //  将 leftTemp rightTemp 归并到 target -->target 有序
        merge(leftTemp, rightTemp, target);
        Nums.show(target);
    }


    private static void merge(int[] arr1, int[] arr2, int[] target) {
        int i = 0, j = 0;
        while (i < arr1.length && j < arr2.length) {
            target[i + j] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
        }

        while (i < arr1.length) {
            target[i + j] = arr1[i++];
        }

        while (j < arr2.length) {
            target[i + j] = arr2[j++];
        }
    }
}
