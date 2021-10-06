package mawenshu.链表;

/**
 * @author 马文澍
 * @date 2021/5/5 8:33
 */
public class Reverse {
    public static void main(String[] args) {
        Node head = Util.createList(new int[]{1, 2, 3, 4, 5});
        Util.forEach(head);
        head = reverseIter(head);
        Util.forEach(head);

        head = reverseRecursion(head);
        Util.forEach(head);
    }

    private static Node reverseRecursion(Node head) {
        if (head == null || head.next == null) {
            return null;
        }
        head.next = reverse(head.next);
        return head;
    }

    private static Node reverse(Node node) {
        if (node.next == null) { // 只有一个结点
            return node;
        }
        Node last = reverse(node.next);
        node.next.next = node;
        node.next = null;

        return last;
    }

    private static Node reverseIter(Node head) {
        if (head.next == null || head.next.next == null) {
            return head;
        }
        //  新的头结点
        Node tempHead = new Node();

        Node node = head;
        Node post = node.next;
        while (post != null) {
            node = post; // 第一个结点
            post = node.next; //第一个结点的后驱结点

            //  头插法
            node.next = tempHead.next;
            tempHead.next = node;
        }
        return tempHead;
    }
}
