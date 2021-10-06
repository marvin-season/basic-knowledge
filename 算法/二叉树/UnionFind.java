package mawenshu.二叉树;

/**
 * @author 马文澍
 * @date 2021/5/1 20:13
 */
public class UnionFind {
    //  连通分量
    private int count;
    //  结点指向的父亲结点， parent[i] 表示i的父节点
    private int[] parent;
    //  某个连通分量的根的平衡因子
    private int[] size;

    public UnionFind(int count) {
        //  初始化连通分量的个数为结点的个数
        this.count = count;

        parent = new int[count];
        size = new int[count];

        //  初始化每个结点没有父亲结点， 指向自己
        for (int i = 0; i < count; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int getSize(int i) {
        return this.size[i];
    }

    private void union(int p, int q) {
        //  找到p的根结点
        int rootP = findRoot(p);
        int rootQ = findRoot(q);

        //  随便一个根结点连接到另一个根结点的话会导致这棵树严重的失去平衡

        //  优化： 平衡因子小的那个树接在 平衡因子高的那棵树上
        if (size[rootP] <= size[rootQ]) {
            parent[rootP] = rootQ;
            System.out.println(rootP + "--连接到-->" + rootQ);

            if (size[rootP] + 1 > size[rootQ]) {
                size[rootQ] = size[rootP] + 1;
            }
        } else {
            System.out.println(rootQ + "--连接到-->" + rootP);

            parent[rootQ] = rootP;
            if (size[rootQ] + 1 > size[rootP]) {
                size[rootP] = size[rootQ] + 1;
            }
        }
        //  连通分量 - 1
        this.count -= 1;
    }

    private boolean isConnected(int p, int q) {
        int root1 = findRoot(p);
        int root2 = findRoot(q);
        return root1 == root2;
    }

    private int findRoot(int p) {
        while (parent[p] != p) {
            p = parent[p];
        }

        return p;
    }

    public static void main(String[] args) {
        /**
         *       1     3
         *     /     /   \
         *   0     2      4
         */
        UnionFind uf = new UnionFind(10);

        System.out.println(uf.count);
        uf.union(0, 1);
        System.out.println("uf.getSize(0) = " + uf.getSize(0));
        System.out.println("uf.getSize(1) = " + uf.getSize(1));
        uf.union(2, 3);
        uf.union(2, 4);
        System.out.println("uf.getSize(2) = " + uf.getSize(2));
        System.out.println("uf.getSize(3) = " + uf.getSize(3));
        System.out.println("uf.getSize(4) = " + uf.getSize(4));

        uf.union(0, 2);
        System.out.println("uf.getSize(0) = " + uf.getSize(0));
        System.out.println("uf.getSize(1) = " + uf.getSize(1));
        System.out.println("uf.getSize(2) = " + uf.getSize(2));
        System.out.println("uf.getSize(3) = " + uf.getSize(3));
        System.out.println("uf.getSize(4) = " + uf.getSize(4));
    }
}
