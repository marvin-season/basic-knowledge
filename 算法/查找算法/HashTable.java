package mawenshu.查找算法;

import java.util.Scanner;
import java.util.concurrent.TimeUnit;

/**
 * @author 马文澍
 * @date 2021/5/3 16:18
 */
public class HashTable {
    private Integer[] elements; // 用数组存储元素， 数组的索引模拟 hash地址
    private Integer len;

    public static void main(String[] args) throws InterruptedException {
        HashTable hashTable = new HashTable();
        for (int i = 0; i < hashTable.len; i++) {
            hashTable.insert(i + 1);
        }
        int res = -1;
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入您要查找的数据");

        while (scanner.hasNextInt()) {
            if ((res = hashTable.search(scanner.nextInt())) != -1) {
                System.out.printf("数据存储的地址是 %d\n", res);
            }
            TimeUnit.SECONDS.sleep(1);
            System.out.println("请输入您要查找的数据");
        }
    }

    private int search(int n) {
        int addr = this.getAddr(n);
        while (this.elements[addr] != n) {
            addr = (addr + 1) % this.len;
            if (addr == this.getAddr(n) || this.elements[addr] == null) {
                System.out.println("数据不存在");
                return -1;
            }
        }
        return addr;
    }

    public HashTable() {
        // 默认哈希表的长度是 12
        this(12);
    }

    public HashTable(Integer len) {
        this.len = len;
        elements = new Integer[len];
    }

    private void insert(int n) {
        int addr = this.getAddr(n);
        while (this.elements[addr] != null) {
            addr = (addr + 1) % this.len; //处理冲突
            if (addr == this.getAddr(n)) {
                System.out.println("数据已满, 更新数据存储");
            }
        }
        this.elements[addr] = n;
    }

    private int getAddr(int n) {
        return Math.abs((n + 1) % this.len);
    }
}
