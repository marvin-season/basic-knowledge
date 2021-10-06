package mawenshu.liner.linkedlist;

import mawenshu.liner.List;

/**
 * @author 马文澍
 * @date 2021/1/19 13:30
 */
public class DoubleLinkedList implements List {
    private DBNode head;
    private int size;

    public DoubleLinkedList() {
        this.head = new DBNode();
        head.data = null;
        head.next = null;
        head.pre = null;
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
        DBNode newNode = new DBNode();
        newNode.data = object;

        DBNode p = head;
        //  指向要插入的结点的下标的上一个
        for (int i = 0; i < index; i++) {
            p = p.next;
        }

        /*
         *     p:[]   --X-->   nextNode:[]
         *        \\          //
         *          newNode:[]
         */
        DBNode nextNode = p.next;
        if (nextNode != null) {
            newNode.next = nextNode;
            newNode.pre = p;

            p.next = newNode;
            nextNode.pre = newNode;
        } else {
            p.next = newNode;
            newNode.pre = p;
            newNode.next = null;
        }
        this.size += 1;
    }

    @Override
    public void add(Object object) {
        this.add(this.size, object);
    }

    @Override
    public Object removeByIndex(int index) {
        return null;
    }

    @Override
    public Object remove(Object object) {
        return null;
    }

    @Override
    public Object replaceByIndex(int i, Object object) {
        return null;
    }

    @Override
    public Object replace(Object oldObject, Object newObject) {
        return null;
    }

    @Override
    public Object get(int i) {
        DBNode p = head;
        for (int j = 0; j <= i; j++) {
            p = p.next;
        }
        return p.data;
    }
}
