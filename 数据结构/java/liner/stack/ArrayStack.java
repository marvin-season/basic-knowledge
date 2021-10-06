package mawenshu.liner.stack;

import mawenshu.liner.Stack;

/**
 * @author 马文澍
 * @date 2021/1/16 10:19
 */
public class ArrayStack implements Stack {
    private Object[] elementData;
    private int top;    //  栈顶指针,栈的容量

    public ArrayStack() {
        this(10);
    }

    public ArrayStack(int initCapacity) {
        this.elementData = new Object[initCapacity];
    }

    @Override
    public void push(Object object) {
        if (isFull()) {
            System.out.println("栈满");
            return;
        }
        elementData[top] = object;
        top += 1;
    }

    @Override
    public Object pop() {
        if(isEmpty()){
            System.out.println("栈空");
            return null;
        }
        return elementData[--top];
    }

    @Override
    public Object peek() {
        if(isEmpty()){
            System.out.println("栈空");
            return null;
        }
        return elementData[top - 1];
    }

    @Override
    public boolean isEmpty() {
        return this.top == 0;
    }

    @Override
    public boolean isFull() {
        return this.top >= elementData.length;
    }


}
