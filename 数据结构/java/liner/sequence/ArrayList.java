package mawenshu.liner.sequence;

import mawenshu.liner.List;
import mawenshu.liner.exception.MyArrayIndexOutOfBoundsException;

import java.util.Arrays;

/**
 * @author 马文澍
 * @date 2021/1/12 15:33
 */
public class ArrayList implements List {
    private int size;   //  元素的个数
    private Object[] elementData;   //  采用数组实现可扩容顺序表

    public ArrayList() {
        this(4);
    }

    public ArrayList(int initCapacity) {
        elementData = new Object[initCapacity];
    }

    @Override
    public int size() {
        return this.size;
    }

    @Override
    public boolean isEmpty() {
        return this.size == 0;
    }

    @Override
    public void add(int index, Object object) {
        //  判断是否满了，需要扩容
        if (isFull()) {
            grow();
        }
        //index后面的每个元素后移一位，从最后一个开始移动
        for (int i = size; i > index; i--) {
            this.elementData[i] = this.elementData[i - 1];
        }
        this.elementData[index] = object;
        this.size += 1;    //  元素个数加一
    }


    @Override
    public void add(Object object) {
        this.add(this.size, object);
    }


    @Override
    public Object removeByIndex(int index) {
        //  index后面的元素前移一位,从index开始
        Object object = this.elementData[index];
        for (int i = index; i < this.size - 1; i++) {
            this.elementData[i] = this.elementData[i + 1];
        }
        this.elementData[size - 1] = null;
        this.size--;
        return object;
    }

    @Override
    public Object remove(Object object) {
        for (int i = 0; i < this.size; i++) {
            if (this.elementData[i].equals(object)) {
                removeByIndex(i);
                i--;//后面一位新的元素前移到了刚刚比较的那个位置, 遍历应该应当回退到刚刚比较的那个位置
            }
        }
        return object;
    }

    @Override
    public Object replaceByIndex(int i, Object object) {
        if (IllegalIndex(i)) {
            throw new MyArrayIndexOutOfBoundsException("数组下标越界:" + i);
        }
        return this.elementData[i] = object;
    }

    @Override
    public Object replace(Object oldObject, Object newObject) {
        for (int i = 0; i < this.size; i++) {
            if (this.elementData[i].equals(oldObject)) {
                this.replaceByIndex(i, newObject);
            }
        }
        return newObject;
    }

    @Override
    public Object get(int i) {
        if (IllegalIndex(i)) {
            throw new MyArrayIndexOutOfBoundsException("数组越界异常" + i);
        }
        return this.elementData[i];
    }

    private boolean isFull() {
        return this.size == this.elementData.length;
    }

    /**
     * 扩容后的临时数组 newObject
     * 扩容策略，增加原来容量的一半
     * Object[] newObject = new Object[newLength];
     * for (int i = 0; i < this.size; i++) {
     * newObject[i] = this.elementData[i];
     * }
     * this.elementData = newObject;
     */
    private void grow() {
        int newLength = this.elementData.length + (this.elementData.length >> 1);
        this.elementData = Arrays.copyOf(this.elementData, newLength);
    }

    private boolean IllegalIndex(int index) {
        return index >= this.size;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder("[");
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                stringBuilder.append(this.elementData[i]);
            } else {
                stringBuilder.append(this.elementData[i]).append(" ,");
            }
        }
        stringBuilder.append("]");
        return stringBuilder.toString();
    }
}
