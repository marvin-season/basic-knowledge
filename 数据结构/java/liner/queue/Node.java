package mawenshu.liner.queue;

/**
 * @author 马文澍
 * @date 2021/1/19 12:47
 */
public class Node {
    Object data;
    Node next;

    public Object getData() {
        return data;
    }

    public void setData(Object data) {
        this.data = data;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
