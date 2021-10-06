package mawenshu.tree;


import java.util.ArrayList;

/**
 * @author 马文澍
 * @date 2021/3/28 8:20
 */
public class Serialize {
    private static final String NULL = "#";
    private static final String SEP = ",";
    public static void main(String[] args) {
//        Node root = getTree();
        String data = "1,2,#,4,#,#,3,#,#";

        Node root = Deserialize.deserialize(data);
        //  先序遍历序列化  根 左 右
        StringBuilder pre = preSerialize(root);
        System.out.println(pre.toString());
        //  后序遍历
        StringBuilder post = postSerialize(root);
        System.out.println(post);
    }

    private static StringBuilder postSerialize(Node root) {
        StringBuilder sb = new StringBuilder();
        System.out.println("后序遍历序列化");
        postTraverse(root, sb);
        return sb;
    }

    private static void postTraverse(Node root, StringBuilder sb) {
        if(root == null){
            sb.append(NULL).append(SEP);
            return;
        }
        postTraverse(root.left, sb);
        postTraverse(root.right, sb);

        sb.append(root.value).append(SEP);

    }

    private static StringBuilder preSerialize(Node root) {
        StringBuilder sb = new StringBuilder();
        System.out.println("先序遍历序列化");
        preTraverse(root, sb);
        return sb;
    }

    private static void preTraverse(Node root, StringBuilder sb) {
        /*  先序遍历代码 */
        if(root == null){
            sb.append(NULL).append(SEP);
            return;
        }
        sb.append(root.value).append(SEP);
        preTraverse(root.left, sb);
        preTraverse(root.right, sb);
    }

//    public static Node getTree() {
//        Node node = new Node(1);
//        Node node1 = new Node(2);
//        Node node2 = new Node(3);
//        Node node3 = new Node(4);
//        node.left = node1;
//        node.right = node2;
//        node1.right = node3;
//        return node;
//    }
}
