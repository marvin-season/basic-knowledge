package mawenshu.链表;

/**
 * @author 马文澍
 * @date 2021/4/7 20:25
 */
public class MergeList {
    public static void main(String[] args) {
        Node list1 = Util.createList(new int[]{1, 2, 4});
        Node list2 = Util.createList(new int[]{1, 3, 4});
        Util.forEach(list1);
        Util.forEach(list2);

        Node merge = merge(list1, list2);
        Util.forEach(merge);

        Node l1 = Util.createListNoHead(new int[]{1, 2, 4});
        Node l2 = Util.createListNoHead(new int[]{1, 3, 4});
        Util.forEachNoHead(l1);
        Util.forEachNoHead(l2);
        Node merge1 = mergeByRecursion(l1, l2);
        Util.forEachNoHead(merge1);
    }

    private static Node mergeByRecursion(Node list1, Node list2) {

        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }
        if (list1.val < list2.val) {
            list1.next = mergeByRecursion(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeByRecursion(list1, list2.next);
            return list2;
        }
    }

    private static Node merge(Node head1, Node head2) {
        if (head1 == null || head1.next == null) {
            return head2;
        }
        if (head2 == null || head2.next == null) {
            return head1;
        }
        Node p1 = head1.next;
        Node p2 = head2.next;
        Node neck = head1.next;
        //  始终让 p1 的第一个元素比p2的第一个元素小，
        if (head1.next.val > head2.next.val) {
            p1 = head2.next;
            p2 = head1.next;
            neck = head2.next;
        }

        Node temp = p1;
        while (p2 != null) {
            while (p2.val >= p1.val) {
                // 保持
                // p1.val > p2.val
                // temp.val <= p2.val
                temp = p1;
                if (p1.next != null) {
                    p1 = p1.next;
                }
                if (p1 == temp) {
                    break;
                }
            }
            if (p1 == temp) {
                p1.next = p2;
                break;
            }
            Node temp2 = p2;
            p2 = p2.next;

            temp.next = temp2;
            temp = temp.next;
            temp.next = p1;
        }
        head1.next = neck;
        return head1;
    }
}
