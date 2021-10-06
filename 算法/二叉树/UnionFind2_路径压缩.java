package mawenshu.二叉树;

/**
 * @author 马文澍
 * @date 2021/5/1 21:56
 */
public class UnionFind2_路径压缩 {
    private Integer[] parent;
    private Integer count;

    public Integer getSize(int n) {
        return size[n];
    }

    private Integer[] size; //树的大小， 结点个数

    public UnionFind2_路径压缩(int n) {
        this.parent = new Integer[n];
        this.size = new Integer[n];
        this.count = n;
        for (int i = 0; i < n; i++) {
            this.parent[i] = i;
            size[i] = 1;
        }
    }

    public static void main(String[] args) {
        UnionFind2_路径压缩 uf = new UnionFind2_路径压缩(10);

        System.out.println(uf.count);
        uf.union(0, 1);
        uf.union(1, 2);
        uf.union(2, 3);
        uf.union(3, 4);
        System.out.println("uf.getSize(4) = " + uf.getSize(4));
    }

    public int find(int a) {
        while (parent[a] != a) {
            a = parent[a];
        }
        return parent[a];
    }

    public boolean isConnected(int a, int b) {
        return find(a) == find(b);
    }

    public void union(int a, int b) {
        if (isConnected(a, b)) {
            return;
        }
        //  进行路径压缩
        while (parent[a] != a) {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }

        while (parent[b] != b) {
            parent[b] = parent[parent[b]];
            b = parent[b];
        }

        if (size[a] < size[b]) {
            parent[a] = b;
            System.out.println(a + "---" + b);
        } else {
            parent[b] = a;
            System.out.println(b + "---" + a);
        }
        this.count--;
    }
}
