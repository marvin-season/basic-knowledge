package mawenshu.liner.test;

import mawenshu.liner.stack.ArrayStack;

import java.util.LinkedList;
import java.util.Stack;

/**
 * @author 马文澍
 * @date 2021/1/14 17:48
 */
public class TestArrayStack {
    public static void main(String[] args) {
        ArrayStack stack = new ArrayStack(4);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(3);
        stack.push(3);
        System.out.println(stack.peek());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
    }
}
