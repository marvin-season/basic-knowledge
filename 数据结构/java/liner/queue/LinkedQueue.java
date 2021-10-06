package mawenshu.liner.queue;

/**
 * @author 马文澍
 * @date 2021/1/19 12:48
 */
public class LinkedQueue {
    private Node front; //  头，出队
    private Node rear;  //  尾，入队

    int size;

    public LinkedQueue() {
        //  初始均指向头结点
        this.front = new Node();
        this.front.data = null;
        this.front.next = null;

        this.rear = front;
        this.size = 0;
    }

    public void add(Object object) {
        Node newNode = new Node();
        newNode.setData(object);
        newNode.setNext(null);

        this.rear.next = newNode;
        this.rear = this.rear.next;
        this.size += 1;
    }

    public Object poll() {
        if (size <= 0) {
            return null;
        }
        Node first = this.front.next;
        this.front.next = first.next;
        first.next = null;
        this.size -= 1;

        if (this.size == 0) {
            this.rear = this.front;
        }
        return first.getData();
    }

    public int size() {
        return this.size;
    }
}
