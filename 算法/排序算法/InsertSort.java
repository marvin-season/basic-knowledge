package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/1/23 19:30
 */
public class InsertSort {
    public static void main(String[] args) {
        int[] nums = Nums.nums;
        Nums.show(nums);
        insert1(nums);
        Nums.show(nums);
//
//        insert2(nums);
//        Nums.show(nums);


    }

    /**
     * 遍历插入
     */
    private static void insert1(int[] nums) {
        for (int i = 1; i < nums.length; i++) {

            //  有序数据部分， 长度为 i
            //  将 nums[i]插入到 nums[j]之前，从左向右遍历有序数列
            for (int j = 0; j < i; j++) {
                if(nums[j] > nums[i]){
                    insertBefore(i, j, nums);
                    break;
                }
            }
        }
    }
    /**
     * @param i    要插入的数的下标
     * @param j    插入到哪个数之前
     * @param nums 整个数组
     */
    private static void insertBefore(int i, int j, int[] nums) {
        int temp = nums[i];
//        System.out.println("\n第" + (i + 1) + "个数插在第" + (j + 1) + "个数之前");
        //  插入后，有序部分长度变为 i + 1;
        //  k = i, 表示插入下标 i 的数
        for (int k = i; k > j; k--) {
            nums[k] = nums[k - 1];
        }
        nums[j] = temp;
    }

    /**
     * 采用二分查找应该插入到哪里
     */
    private static void insert2(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            int index = searchBi(i, nums);
            System.out.println("要插入到下标 " + index + " 之前");
            insertBefore(i, index, nums);
            Nums.show(nums);
        }
    }

    /**
     * 二分搜索 nums[i]的位置,待定
     */
    private static int searchBi(int i, int[] nums) {
        int low = 0;
        int high = i - 1;
        int mid = 0;
        boolean flag = true;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[i] < mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
                flag = false;
            }
        }
        return mid;
    }
}
