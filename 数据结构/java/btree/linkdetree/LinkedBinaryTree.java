package mawenshu.btree.linkdetree;


import mawenshu.btree.BinaryTree;
import mawenshu.liner.Queue;
import mawenshu.liner.queue.ArrayQueue;
import mawenshu.liner.stack.ArrayStack;

/**
 * @author 马文澍
 * @date 2021/1/15 12:38
 */
public class LinkedBinaryTree implements BinaryTree {
    private Node root;

    public LinkedBinaryTree() {
    }

    public LinkedBinaryTree(Node root) {
        this.root = root;
    }

    @Override
    public boolean isEmpty() {
        return this.root == null;
    }

    /**
     * 二叉树的结点数量
     *
     * @return 0
     */
    @Override
    public int getSize() {
        System.out.println("二叉树的结点数目");
        return getSize(this.root);
    }

    private int getSize(Node node) {
        if (node == null) {
            return 0;
        } else {
            int leftTreeSize = getSize(node.leftChild);
            int rightTreeSize = getSize(node.rightChild);

            return leftTreeSize + rightTreeSize + 1;
        }
    }

    @Override
    public int getHeight() {
        //  二叉树的高度
        System.out.println("二叉树的高度");
        return getHeight(this.root);
    }

    private int getHeight(Node node) {
        if (node == null) {
            return 0;
        } else {
            //  左子树的高度
            int leftTreeHeight = getHeight(node.leftChild);
            //  右子树的高度
            int rightTreeHeight = getHeight(node.rightChild);

            //  取高度较高的一个加一:父结点高度占一个
            return leftTreeHeight > rightTreeHeight ? leftTreeHeight + 1 : rightTreeHeight + 1;
        }
    }

    //  非递归先序遍历
    public void preOrderStack() {
        System.out.println("\n非递归先序遍历");
        ArrayStack stack = new ArrayStack();
        Node current = this.root;

        while (!stack.isEmpty() || current != null) {
            while (current != null) {
                System.out.print(current.data + " ");

                stack.push(current);
                current = current.leftChild;
            }
            //  此时 current = null, 已经为最左下角的左子树啦
            if (!stack.isEmpty()) {
                current = (Node) stack.pop();
                current = current.rightChild;
            }
        }
    }

    @Override
    public void preOrderTraverse() {
        if (this.root != null) {
            //  输出根
            System.out.print(this.root.data + " ");
            //  左子树递归遍历
            new LinkedBinaryTree(this.root.leftChild).preOrderTraverse();

            //  右子树递归遍历
            new LinkedBinaryTree(this.root.rightChild).preOrderTraverse();
        }
    }

    @Override
    public void inOrderTraverse() {
        System.out.println("中序遍历");
        inOrderTraverse(this.root);
        System.out.println();
    }

    /**
     * 我自己的理解 使用非递归的方式实现中序遍历
     */
    public void inOrderStack() {
        System.out.println("非递归中序遍历");
        ArrayStack stack = new ArrayStack(7);

        Node current = this.root;
        while (current != null || !stack.isEmpty()) {
            //  1、将某一个结点的所有不为空的左孩子入栈
            if (current != null) {
                stack.push(current);
                current = current.leftChild;
            } else {
                // 2、某一个结点所有的左孩子入栈成功，将最后一个入栈的左孩子弹出，再看看其右孩子，将右孩子当做根结点，循环操作 1、2
                current = (Node) stack.pop();
                System.out.print(current.data + " ");
                current = current.rightChild;
            }
        }
        System.out.println();
    }

    //  使用非递归的方式实现中序遍历
    @Override
    public void inOrderTraverseByStack() {
        System.out.println("非递归中序遍历");
        ArrayStack stack = new ArrayStack(7);
        //  遍历每一个结点，从根结点开始
        Node current = this.root;
        //  改变当前的结点，是的每个结点都作为根结点来遍历
        //  根结点不为空  栈不为空
        while (current != null || !stack.isEmpty()) {
            //  将所有的左子树存入栈
            while (current != null) {
                stack.push(current);
                current = current.leftChild;
            }

            if (!stack.isEmpty()) {
                //  通过这个弹出栈的操作，实现了回退功能
                current = (Node) stack.pop();
                System.out.print(current.data + " ");
                current = current.rightChild;
            }
        }
    }

    //  递归遍历
    private void inOrderTraverse(Node node) {
        if (node != null) {
            //  遍历左子树
            inOrderTraverse(node.leftChild);

            System.out.print(node.data + " ");

            //  遍历右子树
            inOrderTraverse(node.rightChild);
        }
    }

    @Override
    public void postOrderTraverse() {
        System.out.println("后序遍历");
        postOrderTraverse(this.root);
        System.out.println();
    }

    //  使用队列,先进先出
    @Override
    public void floorOrderTraverse() {
        System.out.println("层序遍历");
        if (this.root == null) {
            return;
        }

        ArrayQueue queue = new ArrayQueue(20);
        //  先将根结点放进去
        queue.add(this.root);
        //  队列不是空的，开始循环
        while (!queue.isEmpty()) {
            //  得到当前队列的长度(上一个状态结束时，队列的长度，实际上就是每一层的结点的个数)
            int len = queue.size();
            //  遍历这一层
            for (int i = 0; i < len; i++) {
                Node node = (Node) queue.poll();
                System.out.print(node.data + " ");
                /*
                 *   取出第 k层的第 i个结点，判断这个结点有无子结点(实际上这些子结点就是第k+1层的结点),
                 *   如果!=null,则将这个k+1层的结点加入队列(等到第k层的结点出队列后才能轮到刚刚加入的这个第k+1层的结点)
                 */
                if (node.leftChild != null) {
                    queue.add(node.leftChild);
                }
                if (node.rightChild != null) {
                    queue.add(node.rightChild);
                }
            }
            System.out.println();
        }
    }

    public void floorOrderTraverse2() {
        System.out.println("层序遍历");
        if (this.root == null) {
            return;
        }
        Queue queue = new ArrayQueue();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node root = (Node) queue.poll();
            System.out.print(root.data + " ");
            if (root.leftChild != null) {
                queue.add(root.leftChild);
            }
            if (root.rightChild != null) {
                queue.add(root.rightChild);
            }
            System.out.println();
        }
    }

    private void postOrderTraverse(Node node) {
        if (node != null) {
            postOrderTraverse(node.leftChild);

            postOrderTraverse(node.rightChild);

            System.out.print(node.data + " ");
        }
    }
}
