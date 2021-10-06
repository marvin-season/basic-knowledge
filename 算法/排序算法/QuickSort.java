package mawenshu.排序算法;

/**
 * @author 马文澍
 * @date 2021/1/24 14:17
 */
public class QuickSort {
    public static void main(String[] args) {
        int[] nums = Nums.nums;
        Nums.show(nums);
        System.out.println("=======================");
        quickSort(nums, 0, nums.length - 1);
        System.out.println("=======================");
        Nums.show(nums);
    }

    private static void quickSort(int[] nums, int left, int right) {
        int l = left;
        int r = right;
        int index = (left + right) / 2; //中枢下标
        int temp = 0;

        while (l < r) {
            System.out.println("中枢: " + nums[index] + " 下标: " + index);

            //  从左边遍历 nums[index]左边,没找到的话，l = index
            while (l < index) {
                if (nums[l] > nums[index])
                    break;
                //  从左往右找，直到找到一个大于 nums[index] 的数才退出
                l += 1;
            }

            //  左边找到了
            if (l != index) {
                System.out.print("从左往右搜索: " + nums[l] + ">" + nums[index] + " ");
                temp = nums[l];
                nums[l] = nums[index];
                nums[index] = temp;
                System.out.println(nums[l] + "和" + nums[index] + "交换");

                index = l;
                Nums.show(nums);

            }

            //  从右边遍历 nums[index] 右边, 没找到的话，r = index
            while (r > index) {
                if (nums[r] < nums[index])
                    break;
                //  从右往左找，直到找到一个小于 nums[index] 的数才退出
                r -= 1;
            }

            //  右边找到了
            if (r != index) {
                System.out.print("从右往左搜索: " + nums[r] + "<" + nums[index] + " ");
                temp = nums[r];
                nums[r] = nums[index];
                nums[index] = temp;
                System.out.println(nums[r] + "和" + nums[index] + "交换");

                index = r;
                Nums.show(nums);

            }
            //  pivot左右两边值  按照 ‘小 <= pivot <= 大 ’ 排列好
            //  两边都没有找到 l = r = index
            if (l == r) {
                System.out.println(l + "\t" + r + "\t" + index);
                break;
            }
        }

        //  向左递归
        if (left <= r) {
            quickSort(nums, left, r - 1);
        }
        if (right >= l) {
            quickSort(nums, l + 1, right);
        }
    }
}
