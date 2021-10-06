package mawenshu.liner.linkedlist;

import mawenshu.liner.List;
import mawenshu.liner.stack.ArrayStack;

/**
 * @author 马文澍
 * @date 2021/1/13 16:43
 */
public class SingleLinkedList implements List {
    private int size;
    private Node head;

    public SingleLinkedList() {
        this.head = new Node();
        this.head.data = null;
        this.head.next = null;
        this.size = 0;
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
        //  临时结点，初始指向头结点
        Node p = head;

        //  遍历链表，查询到要插入的节点的上一个结点
        for (int i = 0; i < index; i++) {
            p = p.next;
        }

        Node newNode = new Node();
        newNode.data = object;

        newNode.next = p.next;
        p.next = newNode;

        size += 1;
    }

    @Override
    public void add(Object object) {
        this.add(size, object);
    }

    @Override
    public Object removeByIndex(int index) {
        Node p = head;
        //  找到要删除的结点的前一个结点
        for (int i = 0; i < index; i++) {
            p = p.next;
        }

        Node currentPoint = p.next;
        //  前一个结点的后继指针置为当前指针的后一个
        p.next = currentPoint.next;
        //  当前指针所指向的数据被丢弃，不指向任何结点，等待GC
        currentPoint.next = null;
        size--;
        return currentPoint.data;
    }

    @Override
    public Object remove(Object object) {
        Node p = head;
        for (int i = 0; i < size; i++) {
            if (p.next.data.equals(object)) {
                removeByIndex(i);
                //  链表数据自动前移，下标不变，size-1
                i--;
            } else {
                //  开始移动指针
                p = p.next;
            }
        }
        return object;
    }

    @Override
    public Object replaceByIndex(int i, Object object) {
        //  指向头结点(空)
        Node p = head;
        for (int j = 0; j <= i; j++) {
            p = p.next;
        }
        p.data = object;

        return object;
    }

    @Override
    public Object replace(Object oldObject, Object newObject) {

        Node p = head;
        for (int i = 0; i < size; i++) {
            p = p.next;
            if (p.data.equals(oldObject)) {
                replaceByIndex(i, newObject);
            }
        }
        return newObject;
    }

    @Override
    public Object get(int i) {
        Node p = head;
        for (int j = 0; j <= i; j++) {
            p = p.next;
        }
        return p.data;
    }

    public void reverse1() {
        Node current = head.next;
        //  记录当前指针的下一个元素
        Node next = null;

        Node newHead = new Node();
        while (current != null) {
            next = current.next;

            current.next = newHead.next;
            newHead.next = current;
            current = next;
        }

        this.head.next = newHead.next;
    }

    public void reverse2() {
        Node current = head.next;

        ArrayStack stack = new ArrayStack(this.size);
        while (current != null) {
            stack.push(current);
            current = current.next;
        }
        Node newHead = new Node();
        current = newHead;

        while (stack.peek() != null) {
            current.next = (Node) stack.pop();
            current = current.next;
        }
        this.head.next = newHead.next;
    }

    @Override
    public String toString() {
        Node p = head.next;
        StringBuilder stringBuilder = new StringBuilder("[");
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                stringBuilder.append(p.data);
            } else {
                stringBuilder.append(p.data).append(" ,");
            }
            p = p.next;
        }
        stringBuilder.append("]");
        return stringBuilder.toString();
    }
}
