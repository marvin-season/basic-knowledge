package mawenshu.链表;

/**
 * @author 马文澍
 * @date 2021/4/7 20:25
 */
public class Util {
    //  有头指针
    public static Node createList(int[] nums) {
        Node head = new Node();
        Node p = head;
        for (int val : nums) {
            p.next = new Node(val);
            p = p.next;
        }
        return head;
    }
    // 无头指针
    public static Node createListNoHead(int[] ints) {
        Node head = new Node();
        Node p = head;
        for (int num : ints) {
            p.next = new Node(num);
            p = p.next;
        }
        return head.next;
    }

    public static void forEach(Node head) {
        Node p = head;
        if (p == null) return;
        else p = p.next;

        while (p != null) {
            System.out.print(p.val + " ");
            p = p.next;
        }
        System.out.println();
    }

    public static void forEachNoHead(Node node) {
        if (node == null) {
            return;
        }
        while (node != null) {
            System.out.print(node.val + " ");
            node = node.next;
        }
        System.out.println();
    }
}
