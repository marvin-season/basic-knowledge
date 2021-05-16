//
// Created by marvin on 2021/5/10.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef char VertexType;
typedef int EdgeType;

#define MAX         100                 // 矩阵最大容量
#define SIZE        10                  // 队列最大容量
#define INF         (~(0x1<<31))        // 最大值(即0X7FFFFFFF)
#define isLetter(a) ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a)   (sizeof(a)/sizeof((a)[0]))

// 邻接矩阵
// 邻接矩阵
typedef struct graph {
    VertexType vertex_s[MAX];       // 顶点集合
    EdgeType matrix[MAX][MAX]; // 邻接矩阵

    int vertex_num;           // 顶点数
    int edge_num;           // 边数
} Graph, *PGraph;

// 边的结构体
typedef struct edge_data {
    VertexType start;
    VertexType end;
    EdgeType weight;
} EData;

// 循环队列
typedef struct Queue {
    int size;
    int prior;
    int rear;
    int elements[SIZE];
} Queue;

Queue *init_queue();

int isEmpty(Queue q);

int isFull(Queue q);

void add_last(Queue *q, int data);

int remove_first(Queue *q);

int get_position(char ch, Graph g);

/*
 * 读取一个输入字符
 */
char read_char();

/*
 * 创建图(自己输入)
 */
Graph *create_graph();

Graph *create_graph_example();

/*
 * 创建图(用已提供的矩阵)
 */
Graph *create_example_graph();

/*
 * 返回顶点v的第一个邻接顶点的索引，失败则返回-1
 */
int first_vertex(Graph G, int v);

/*
 * 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
 */
int next_vertex(Graph G, int v, int w);

void DFS(Graph G, int i, int *visited);

void DFSTraverse(Graph G);

void BFS(Graph G);

void print_graph(Graph G);

void prim(Graph G, int start);

EData *get_edges(Graph G);

void sorted_edges(EData *edges, int elen);

void show_edges(EData *edges, Graph G);

void kruskal(Graph G);

void dijkstra(Graph G, int vs);

void floyd(Graph G);

int main() {
    Graph *pG = create_graph_example();
    DFSTraverse(*pG);
    BFS(*pG);
    print_graph(*pG);
    prim(*pG, 0);
    kruskal(*pG);
    dijkstra(*pG, 0);

    floyd(*pG);
    system("pause");
    return 0;
}

char read_char() {
    char ch;
    do {
        ch = getchar();
    } while (!isLetter(ch));

    return ch;
}

/*
 * 返回ch在matrix顶点集中的位置
 */
int get_position(char ch, Graph g) {
    for (int i = 0; i < g.edge_num; ++i) {
        if (ch == g.vertex_s[i]) {
            return i;
        }
    }
    return -1;
}

Graph *create_graph() {
    char c1, c2;
    int index1, index2;
    int weight;
    int vertex_num = 0; // 顶点数
    int edge_num = 0; //边数

    // 输入"顶点数"和"边数"
    printf("input vertex's number: ");
    scanf("%d", &vertex_num);
    printf("input edges' number: ");
    scanf("%d", &edge_num);
    if (vertex_num < 1 || edge_num < 1 || edge_num > (vertex_num) * (vertex_num - 1)) {
        printf("input error: invalid parameters!\n");
        return NULL;
    }
    PGraph pG = (PGraph) malloc(sizeof(Graph));
    if (pG == NULL) {
        return NULL;
    }
    // 将某一块内存中的内容全部设置为指定的值
    memset(pG, 0, sizeof(Graph));
    // 初始化"顶点数"和"边数"
    pG->vertex_num = vertex_num;
    pG->edge_num = edge_num;
    //  初始化顶点
    for (int i = 0; i < pG->vertex_num; i++) {
        printf("vertex(%d): ", i);
        pG->vertex_s[i] = read_char();
    }
    // 1. 初始化"边"的权值
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            if (i == j) {
                pG->matrix[i][j] = 0;
            } else {
                pG->matrix[i][j] = INF;
            }
        }
    }
    // 2. 初始化"边"的权值: 根据用户的输入进行初始化
    for (int i = 0; i < edge_num; ++i) {
        // 读取边的起始顶点，结束顶点，权值
        printf("edge(%d):", i);
        c1 = read_char();
        c2 = read_char();
        scanf("%d", &weight);
        index1 = get_position(c1, *pG);
        index2 = get_position(c2, *pG);

        if (index1 == -1 || index2 == -1) {
            printf("input error: invalid edge!\n");
            free(pG);
            return NULL;
        }
        pG->matrix[index1][index2] = pG->matrix[index2][index1] = weight;
    }

    return pG;
}

Graph *create_graph_example() {
    char vertex_s[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    int matrix[][9] = {
            {0,   1,   5,   INF, INF, INF, INF, INF, INF},
            {1,   0,   3,   7,   5,   INF, INF, INF, INF},
            {5,   3,   0,   INF, 1, 7,     INF, INF, INF},
            {INF, 7,   INF, 0,   2,   INF, 3,   INF, INF},
            {INF, 5,   1,   2,   0, 3,     6,   9,   INF},
            {INF, INF, 7,   INF, 3, 0,     INF, 5,   INF},
            {INF, INF, INF, 3,   6,   INF, 0,   2, 7},
            {INF, INF, INF, INF, 9, 5,     2,   0, 4},
            {INF, INF, INF, INF, INF, INF, 7,   4, 0}
    };
    int size = LENGTH(vertex_s);
    int i, j;
    Graph *pG;

    // 输入"顶点数"和"边数"
    if ((pG = (Graph *) malloc(sizeof(Graph))) == NULL)
        return NULL;
    memset(pG, 0, sizeof(Graph));

    // 初始化"顶点数"
    pG->vertex_num = size;
    // 初始化"顶点"
    for (i = 0; i < pG->vertex_num; i++)
        pG->vertex_s[i] = vertex_s[i];

    // 初始化"边"
    for (i = 0; i < pG->vertex_num; i++)
        for (j = 0; j < pG->vertex_num; j++)
            pG->matrix[i][j] = matrix[i][j];

    // 统计边的数目
    for (i = 0; i < pG->vertex_num; i++)
        for (j = 0; j < pG->vertex_num; j++)
            if (i != j && pG->matrix[i][j] != INF)
                pG->edge_num++;
    pG->edge_num /= 2;

    return pG;
}

int first_vertex(Graph G, int v) {
    if (v < 0 || v > (G.vertex_num - 1))
        return -1;

    for (int i = 0; i < G.vertex_num; i++)
        if (G.matrix[v][i] != 0 && G.matrix[v][i] != INF)
            return i;

    return -1;
}

int next_vertex(Graph G, int v, int w) {
    if (v < 0 || v > (G.vertex_num - 1) || w < 0 || w > (G.vertex_num - 1))
        return -1;

    for (int i = w + 1; i < G.vertex_num; i++)
        if (G.matrix[v][i] != 0 && G.matrix[v][i] != INF)
            return i;

    return -1;
}

/*
 * 深度优先搜索遍历图的递归实现
 */
void DFS(Graph G, int i, int *visited) {
    printf("%c ", G.vertex_s[i]);
    // 标志 i 已经被访问过了
    visited[i] = 1;

    // 遍历所有的相邻结点
    for (int neb = first_vertex(G, i); neb >= 0; neb = next_vertex(G, i, neb)) {
        if (!visited[neb]) {
            DFS(G, neb, visited);
        }
    }
}


/*
* 深度优先搜索遍历图
*/
void DFSTraverse(Graph G) {
    int visited[G.vertex_num];
    for (int i = 0; i < G.vertex_num; ++i) {
        visited[i] = 0;
    }
    printf("DFS:\n");
    for (int i = 0; i < G.vertex_num; ++i) {
        if (visited[i])continue;
        else DFS(G, i, visited);
    }
    printf("\n");
}

/*
 * 广度优先搜索（类似于树的层次遍历）
 */
//void BFS(Graph G) {
//    int queue[MAX];
//    int prior = 0, rear = 0;
//    int visited[G.vertex_num];
//    for (int i = 0; i < G.vertex_num; ++i) {
//        visited[i] = 0;
//    }
//    printf("BFS: \n");
//    for (int i = 0; i < G.vertex_num; ++i) {
//        if (!visited[i]) {
//            printf("%c ", G.vertex_s[i]);
//            visited[i] = 1;
//            queue[rear++] = i;
//        }
//        while (prior != rear) {
//            int j = queue[prior++];
//            // 遍历邻结点
//            for (int k = first_vertex(G, j); k >= 0; k = next_vertex(G, j, k)) {
//                if (!visited[k]) {
//                    visited[k] = 1;
//                    printf("%c ", G.vertex_s[k]);
//                    queue[rear++] = k;
//                }
//            }
//        }
//    }
//    printf("\n");
//}
void BFS(Graph G) {
    Queue *pQ = init_queue();
    int visited[G.vertex_num];

    for (int i = 0; i < G.vertex_num; ++i) {
        visited[i] = 0;
    }
    printf("BFS: \n");
    add_last(pQ, 0);
    visited[0] = 1;

    while (!isEmpty(*pQ)) {
        int current_index = remove_first(pQ);
        printf("%c", G.vertex_s[current_index]);

        for (int j = 0; j < G.vertex_num; ++j) {
            if (G.matrix[current_index][j] != 0 && G.matrix[current_index][j] != INF && !visited[j]) {
                add_last(pQ, j);
                visited[j] = 1;
            }
        }

    }
    printf("\n");
}


/*
 * 打印矩阵队列图
 */
void print_graph(Graph G) {
    for (int i = 0; i < G.vertex_num; ++i) {
        for (int j = 0; j < G.vertex_num; ++j) {
            if (G.matrix[i][j] == INF) {
                printf("-  ");
            } else {
                printf("%d  ", G.matrix[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * 初始化一个循环队列
 * @return 循环队列
 */
Queue *init_queue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->rear = 0;
    queue->prior = 0;
    queue->size = 0;
    for (int i = 0; i < SIZE; ++i) {
        queue->elements[i] = -1;
    }
    return queue;
}

int isEmpty(Queue q) {
    if (q.prior == q.rear) {
        return 1;
    }
    return 0;
}

int isFull(Queue q) {
    if ((q.rear + 1) % SIZE == q.prior) {
        return 1;
    }
    return 0;
}

/**
 * 入队
 * @param q
 * @param data
 */
void add_last(Queue *q, int data) {
    if (isFull(*q)) {
        return;
    }
    q->elements[q->rear] = data;
    q->rear = (q->rear + 1) % SIZE;
    q->size++;
}

/*
 *
 * 出队
 */
int remove_first(Queue *q) {
    if (isEmpty(*q)) {
        return -1;
    }
    int res = q->elements[q->prior];
    q->prior = (q->prior + 1) % SIZE;
    q->size--;
    return res;
}

/*
 * prims最小生成树
 *
 * 参数说明：
 *       G -- 邻接矩阵图
 *   start -- 从图中的第start个元素开始，生成最小树
 */
/**
 *
 *   全结点集 U: G
 *   V: 表示已纳入生成树的集合
 *   U-V, 剩下的带纳入结点集
 *   dist[a]: 表示 a到结合V的距离
 *
 *   1、从U-V中找一个 与 V 距离最近的结点 a，
 *   2、将 a 加入到 V，并修改 a 到 V的距离为 0, 表示已经加入a结点
 *   3、更新相关节点记录信息，
 *   --> 原因是 设有这样的连接关系 V-a-b ,
 *   --> a 未加入时, min = dist[a] < dist[b] = INF,
 *   --> 加入 a, 链接关系变为 V-b, 此时 dist[b] = G.matrix[a][b], 为原来b到a的距离
 */
void prim(Graph G, int start) {
    int seq[MAX];
    int index = 0;
    int adjvex[MAX]; // prims[i] = k,  i的上一个添加到 prims序列的结点是 k
    int min;
    int distance[MAX]; // 结点 i 到起始点集合的距离

    // 初始化第一个结点， 第一个结点到起始节点的距离 为 0,
    distance[start] = 0;
    adjvex[start] = start;
    seq[index++] = start;


    for (int i = 0; i < G.vertex_num; ++i) {
        if (i == start) {
            continue;
        }
        // 初始化i结点到 起点 0的距离
        distance[i] = G.matrix[i][start];
        adjvex[i] = start;
    }

    printf("%c ", G.vertex_s[start]);
    for (int i = 0; i < G.vertex_num; ++i) {
        if (i == start) {
            continue;
        }
        for (int k = 0; k < G.vertex_num; ++k) {
            printf("\t %c->%c ", G.vertex_s[k], G.vertex_s[adjvex[k]]);
        }
        printf("\n");

        min = INF;

        int j = 0, k = 0;
        // 遍历查找其他结点 到 起始节点距离最短的结点
        while (j < G.vertex_num) {
            // j 到 起始点的距离 为 0说明 结点 j已经加入到了 prims 序列，
            if (distance[j] != 0 && distance[j] < min) {
                min = distance[j];
                k = j;
            }
            j++;
        }

        // k就是我们要寻找的那个 距离起始位置最近的结点
        // 将结点k 标志为遍历过
        distance[k] = 0;
        seq[index++] = k;
        printf("%c ", G.vertex_s[k]);
        // 更新 距离 状态
        for (int m = 0; m < G.vertex_num; ++m) {
            // m 到 start 结点 的距离
            if (distance[m] != 0 && G.matrix[m][k] < distance[m]) {
                distance[m] = G.matrix[m][k];
                adjvex[m] = k; // 结点 m 的上一个距离最近的点就是 k
            }
        }
    }
    printf("\nsequence:\n");
    for (int i = 0; i < G.vertex_num; ++i) {
        printf("%c ", G.vertex_s[seq[i]]);
    }
    printf("\n");

}

/*
 * 获取图中的边
 */
EData *get_edges(Graph G) {
    EData *eData = (EData *) malloc(G.edge_num * sizeof(EData));
    int index = 0;
    int weight;
    for (int i = 0; i < G.vertex_num; ++i) {
        for (int j = 0; j < G.vertex_num; ++j) {
            if (i > j && (weight = G.matrix[i][j]) != INF) {
                eData[index].start = G.vertex_s[i];
                eData[index].end = G.vertex_s[j];
                eData[index].weight = weight;
                index++;
            }
        }
    }

    sorted_edges(eData, G.edge_num);
    show_edges(eData, G);
    return eData;
}

/*
 * 对边按照权值大小进行排序(由小到大)
 */
void sorted_edges(EData *edges, int elen) {
    EData min = {-1, -1, INF};
    EData temp;
    // 选择排序
    for (int i = 0; i < elen - 1; ++i) {
        for (int j = i; j < elen; ++j) {
            if (edges[j].weight < min.weight) {
                temp = edges[j];
                edges[j] = min;
                min = temp;
            }
        }

        temp = min;
        min = edges[i];
        edges[i] = temp;
    }
}

void show_edges(EData *edges, Graph G) {
    for (int i = 0; i < G.edge_num; ++i) {
        printf("{'%c', '%c', %d},\n", edges[i].start, edges[i].end, edges[i].weight);
    }
}

int find_root(int *parent, int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

/*
 * 克鲁斯卡尔（Kruskal)最小生成树
 */
void kruskal(Graph G) {
    // 边集数组
    EData *edges = get_edges(G);

    // 和并查集中的parent数组作用类似
    int parent[MAX];

    for (int i = 0; i < G.vertex_num; ++i) {
        // 初始化每个结点单独存在， 父节点是他自己
        parent[i] = i;
    }

    int n, m;
    printf("Kruskal:\n");
    for (int i = 0; i < G.edge_num; ++i) {
        n = find_root(parent, get_position(edges[i].start, G));  // 过去第i条边的起点的起点
        m = find_root(parent, get_position(edges[i].end, G));    // 过去第i条边的终点的起点
        // 如果 m和n结点 原来不相连， 则可以连接m n,并加入最小生成树
        if (m != n) {
            parent[m] = n;
            printf(" (%c, %c)  %d\n", edges[i].start, edges[i].end, edges[i].weight);
        }
    }
}

/*
 * Dijkstra最短路径。
 * 即，统计图(G)中"顶点vs"到其它各个顶点的最短路径。
 *
 * 参数说明：
 *        G -- 图
 *       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
 *     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
 *     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 */
void dijkstra(Graph G, int vs) {
    int prev[MAX];
    int dist[MAX];

    // 将 左右结点分为两部分: 集合V,  集合S     全集 U = S+V
    // V集合中的结点已经算出最短路径， S 结点为待测结点
    // 每次从 S 中扫描一个最佳结点， 加入到 V中
    // 更新 相关结点的记录

    int min, k, temp;
    int find[MAX]; // find[i] = 1; 标记结点i加入了V集合

    // 初始化
    for (int i = 0; i < G.vertex_num; ++i) {
        //  初始化 i到起始点vs的距离  i=vs时， dist[i] = G.matrix[vs][vs] = 0;
        dist[i] = G.matrix[i][vs];
        prev[i] = vs; // 从vs开始的， 所有结点的前驱初始化为vs
        find[i] = 0;
    }

    find[vs] = 1;
    dist[vs] = 0;


    //  遍历 n-1 次
    for (int i = 0; i < G.vertex_num; ++i) {
        if (i == vs) {
            continue;
        }
        min = INF;
        // 找到一个距离 起始结点最近的结点
        // 同 prim最大的不同是:  dist[w], 地杰斯特拉中 表示到起点的最短路径
        // prim dist[w],表示的是到集合 V中的距离
        // 同时， 将结点纳入到V后， prim: dist[w] = 0,结课表示这个纳入的状态，
        // dijkstra： dist[w] = len, 无法表示是否纳入 V， 故额外引入find数组， 来记录每个结点的纳入状态
        for (int w = 0; w < G.vertex_num; w++) {
            if (!find[w] && dist[w] < min) {
                min = dist[w];
                k = w;
            }
        }
        // 找到了结点 k 是当前距离 vs最近的
        find[k] = 1;
        // 更新 记录信息
        for (int w = 0; w < G.vertex_num; ++w) {
            temp = (G.matrix[w][k] == INF) ? INF : (G.matrix[w][k] + min);
            if (!find[w] && temp < dist[w]) {
                dist[w] = temp;
                prev[w] = k;
            }
        }
    }
    // 打印dijkstra最短路径的结果
    printf("dijkstra(%c): \n", G.vertex_s[vs]);
    for (int i = 0; i < G.vertex_num; i++) {
        printf("shortest(%c, %c)=%d\n", G.vertex_s[vs], G.vertex_s[i], dist[i]);
    }
}

/**
 * A 到 B 的是不是最短路径， 判断A->k  k->B 的距离是 更小， 如果是， 则让 A->B = A->k + k>B,
 * 同理 亦可能还有一个结点 m  使得 A->k + k->m + m->B  < A->B
 * 定义一个三维数组    dp[k][i][j], 表示 从 i-j 有 k个结点可以绕，使得 i到j 为最短路径
 * if :
 *      dp[k][i][j] < dp[k-1][i][m] + dp[k-1][m][j]
 * 通过m结点， 使得 i到j 距离更近，即i->m-j
 * @param G 邻接矩阵
 */
void floyd(Graph G) {
    int temp;
    int dp[MAX][MAX]; // dp[i][j]表示  i到 j 的最短路径
    // 只有一个结点 , 返回
    // 只有两个结点, 则没有第三者，k=0, dp[i][j] = G.matrix[i][j]

    for (int i = 0; i < G.vertex_num; ++i) {
        for (int j = 0; j < G.vertex_num; ++j) {
            dp[i][j] = G.matrix[i][j];
        }
    }

    // 可以借助 k结点绕路
    // 始终将所有结点看做是三个结点，
    // i、k、j, 如果 i->k->j 小于 i->j,则将 i->j 的值改为 i->k->j, 并且抹除k 相对于 i和 j的存在
    // 再去串其他的辅助 结点， 循环上述过程
    for (int k = 0; k < G.vertex_num; ++k) {
        for (int i = 0; i < G.vertex_num; ++i) {
            for (int j = 0; j < G.vertex_num; ++j) {
                if (i == j) continue;
                if (k == i || k == j) continue;

                if (dp[i][k] == INF || dp[k][j] == INF) {
                    temp = INF;
                    continue;
                }

                temp = dp[i][k] + dp[k][j];

                // 动态断开原来的链接， 建立新的路径，
                if (temp < dp[i][j]) {
                    dp[i][j] = temp;
                }
            }
        }
    }

    printf("floyd: \n");
    for (int i = 0; i < G.vertex_num; ++i) {
        for (int j = 0; j < G.vertex_num; ++j) {
            if (dp[i][j] >= INF) {
                printf("(%c,%c)=INF ", G.vertex_s[i], G.vertex_s[j]);
                continue;
            }
            printf("(%c,%c)=%d ", G.vertex_s[i], G.vertex_s[j], dp[i][j]);
        }
        printf("\n");
    }
}