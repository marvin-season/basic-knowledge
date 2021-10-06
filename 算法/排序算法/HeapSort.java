package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/5/9 7:49
 */
public class HeapSort {
    public static void main(String[] args) {
        int[] nums = Nums.nums;
        Nums.show(nums);
        // init  heap
        create(nums, nums.length);
        Nums.show(nums);
        fetch(nums);
    }

    private static void fetch(int[] nums) {

        int len = nums.length;
        while (len > 0) {
            System.out.print(nums[0] + " ");
            nums[0] = nums[--len];
            create(nums, len);
        }
    }

    // 构造小顶堆
    private static void create(int[] nums, int len) {
        for (int i = (len - 1) / 2; i >= 0; i--) {
            heapAdjust(nums, i, len);
        }
    }

    /**
     * @param nums  数组存储元素
     * @param start 开始堆排序的某个元素
     * @param len   当前需要堆排序的元素个数
     */
    private static void heapAdjust(int[] nums, int start, int len) {
        int temp;
        for (int i = start; i <= (len - 1) / 2; i = i * 2 + 1) {

            //  如果当前结点的右孩子值小于左孩子， 则交换左右孩子
            if (2 * i + 2 < len && nums[2 * i + 2] < nums[2 * i + 1]) {

                temp = nums[2 * i + 1];
                nums[2 * i + 1] = nums[2 * i + 2];
                nums[2 * i + 2] = temp;
//                System.out.printf("== %d 与交换位置 %d ==\n", nums[2 * i + 2], nums[2 * i + 1]);
            }

            //  保持根结点是最小的
            if (2 * i + 1 < len && nums[2 * i + 1] < nums[i]) {

                temp = nums[i];
                nums[i] = nums[2 * i + 1];
                nums[2 * i + 1] = temp;
//                System.out.printf("%d 与交换位置 %d\n", nums[2 * i + 1], nums[i]);

            }
        }
    }
}
