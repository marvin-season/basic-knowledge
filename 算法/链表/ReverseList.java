package mawenshu.链表;

/**
 * @author 马文澍
 * @date 2021/4/8 20:26
 */
public class ReverseList {

    private static Node successor = null;

    public static void main(String[] args) {
        Node list = Util.createListNoHead(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9});
        Util.forEachNoHead(list);

        Node reverse = reverse(list);
        Util.forEachNoHead(reverse);

        list = Util.createListNoHead(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9});
        Util.forEachNoHead(list);
        //  反转前 5个
        reverse = reverseTo(list, 5);
        Util.forEachNoHead(reverse);

        list = Util.createListNoHead(new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9});
        Util.forEachNoHead(list);
        //  反转 第 2 ~ 5 个
        reverse = reverseInRange(list, 2, 5);
        Util.forEachNoHead(reverse);

    }

    //  1->2->3->4->5         \
    //  1   ->2->3->4->5       \
    //      ->2   ->3->4->5     \  递
    //            ->3   ->4->5   \
    //                  ->4   ->5 \
    //                          head.next = null  =>  last = head
    //                    head.next.next = head;
    //                    head.next = null;
    //                    4<-5    /
    //            <-3<-4<5       / 归
    private static Node reverse(Node head) {
        if (head.next == null) {
            return head;
        }

        //  一直递归到最后面， 找到最后一个结点， 等会儿作为反转后的头结点返回
        Node last = reverse(head.next); // head.next != null --->  reverse(head)  ->head !=null
        head.next.next = head;
        head.next = null;
        return last;
    }

    private static Node reverseTo(Node head, int end) {
        if (end == 1) {
            //  后驱结点
            successor = head.next;
            return head;
        }

        Node last = reverseTo(head.next, end - 1);
        head.next.next = head;
        head.next = successor;
        return last;
    }

    private static Node reverseInRange(Node head, int start, int end) {
        if (start == 1) {
            //  从第一个开始反转
            return reverseTo(head, end);
        }

        //  将 head 索引视为1, 从 start 开始反转
        //  将 head.next 索引视为 1 从 start-1开始反转
        head.next = reverseInRange(head.next, start - 1, end - 1);
        return head;
    }
}
