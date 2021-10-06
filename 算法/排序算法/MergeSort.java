package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/1/25 14:49
 */
public class MergeSort {
    public static void main(String[] args) {
        int[] nums = Nums.nums;
        Nums.show(nums);
        mSort(nums);
        Nums.show(nums);

//        int[] arr = {1, 3, 5, 2, 4, 6};
//        int[] arr = {1, 7, 9, 0, 2, 3};
//        int[] temp = new int[arr.length];
//        merge(arr, temp, 0, 3, arr.length);
    }

    private static void mSort(int[] nums) {
        int right = nums.length;
        int left = 0;
        mergeSort(nums, nums, left, right);
    }

    /**
     * @param nums  需要归并的 source
     * @param temp  归并的 target
     * @param left  起始
     * @param right 末尾
     */
    private static void mergeSort(int[] nums, int[] temp, int left, int right) {
        int mid;
        int[] temp2 = new int[nums.length];

        if (Math.abs(right - left) == 1) {
            temp[left] = nums[left];
        } else {
            //  将 nums 二分，归并到 temp2
            mid = (left + right) / 2;
            //  左分nums,递归将nums归并到temp2,
            mergeSort(nums, temp2, left, mid);
            //  右分nums
            mergeSort(nums, temp2, mid, right);
            //  将 temp2[left...mid] temp2[mid+1...right]归并到 temp,即当前的数组中，此事当前数组为有序
            merge(temp2, temp, left, mid, right);
            Nums.show(temp);
        }
    }

    /**
     * @param temp2 temp2[left...mid]有序
     * @param temp  temp2[mid+1...right]
     * @param left  left - mid 有序
     * @param mid   mid -right 有序
     */
    public static void merge(int[] temp2, int[] temp, int left, int mid, int right) {
        //  遍历  temp2[left...mid]有序，temp2[mid+1...right]有序,归并到temp
        int j, k;   //  两个临时变量分别从 开始、中间部分向右滑、移动
        for (j = mid, k = left; left < mid && j < right; k++) {
            if (temp2[left] < temp2[j]) {
                System.out.println(temp2[left] + "<" + temp2[j]);
                temp[k] = temp2[left++];
            } else {
                System.out.println(temp2[left] + ">" + temp2[j]);
                temp[k] = temp2[j++];
            }
//            Nums.show(temp);
//            System.out.println("left " + left);
        }

        //  看看谁剩余
        //  temp2[left...mid]剩余
        while (left < mid) {
            temp[k++] = temp2[left++];
        }
        while (j < right) {
            temp[k++] = temp2[j++];
        }
//        Nums.show(temp);
    }
}
