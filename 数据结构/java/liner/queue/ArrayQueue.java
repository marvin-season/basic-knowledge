package mawenshu.liner.queue;

import mawenshu.liner.Queue;

/**
 * @author 马文澍
 * @date 2021/1/15 19:58
 */
public class ArrayQueue implements Queue {
    private Object[] elementData;
    private int rear;
    private int front;

    public ArrayQueue() {
        this(10);
    }

    public ArrayQueue(int initCapacity) {
        this.elementData = new Object[initCapacity + 1];
    }

    @Override
    public void add(Object object) {
        if (isFull()) {
            System.out.println("队列已满");
            return;
        }
        this.elementData[rear % this.elementData.length] = object;
        this.rear += 1;
    }

    @Override
    public Object poll() {
        if (isEmpty()) {
            System.out.println("队列为空");
            return null;
        }
        Object frontData = elementData[this.front % this.elementData.length];
        this.front += 1;
        return frontData;
    }

    @Override
    public boolean isEmpty() {
        return this.rear == this.front;
    }

    //  空出一个元素的位置，让rear指向，来判断循环队列是否已满
    @Override
    public boolean isFull() {
        return (this.rear + 1) % this.elementData.length == this.front % this.elementData.length;
    }

    @Override
    public int size() {
        return this.rear - this.front;
    }
}
