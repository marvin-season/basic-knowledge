//
// Created by mawenshu on 2021/5/12.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX         100                 // 矩阵最大容量
#define SIZE        10                  // 队列最大容量
#define INF         (~(0x1<<31))        // 最大值(即0X7FFFFFFF)
#define isLetter(a) ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a)   (sizeof(a)/sizeof(a[0]))
#define OK 1
#define NO -1
#define ERROR 0

typedef char VertexType;
typedef int EdgeType;
typedef int Status;

typedef struct edge_node {
    int weight;
    int adjvex_index;
    struct edge_node *next;
} ENode;

typedef struct vertex_node {
    int in_degree;
    int out_degree;
    VertexType data;
    ENode *first_edge_node;
} VNode;

typedef struct graph {
    VNode adj_list[MAX];
    int vertex_num, edge_num;
} Graph;

typedef struct edge {
    VertexType start;
    VertexType end;
    int weight;
} Edge;

char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
Edge edges[] = {
        {'B', 'A', 1},
        {'E', 'C', 1},
        {'E', 'D', 2},
        {'H', 'G', 2},
        {'F', 'E', 3},
        {'G', 'D', 3},
        {'C', 'B', 3},
        {'I', 'H', 4},
        {'H', 'F', 5},
        {'C', 'A', 5},
        {'E', 'B', 5},
        {'G', 'E', 6},
        {'D', 'B', 7},
        {'I', 'G', 7},
        {'F', 'C', 7},
        {'H', 'E', 9}
};

void BFS(Graph G);

void DFS(Graph G);

void DFSTraverse(Graph graph, int i, int *visited);

void prim(Graph graph);

int get_weight(Graph G, int index1, int index2);

void kruskal(Graph G);

Edge *get_edges(Graph G);

void sort_edges(Edge *edges, Graph G);

void print_edges(Edge *edges, Graph G);

void dijkstra(Graph G, int vs);

void floyd(Graph G);

Graph *create_graph_direct();

Status topology(Graph G);

void emphatic_route(Graph G);

char read_char() {
    char ch;
    do {
        ch = (char) getchar();
    } while (!isLetter(ch));

    return ch;
}

int get_position(char ch, Graph G) {
    for (int i = 0; i < G.vertex_num; ++i) {
        if (G.adj_list[i].data == ch) {
            return i;
        }
    }
    return -1;
}

Graph *create_graph() {
    int vertex_num = LENGTH(vexs), edge_num = LENGTH(edges);
    Graph *pG = (Graph *) malloc(sizeof(Graph));
    if (pG == NULL) {
        printf("pG NULL");
        return NULL;
    }
    memset(pG, 0, sizeof(Graph));
    pG->vertex_num = vertex_num;
    pG->edge_num = edge_num;

    // 初始化顶点表结点
    for (int i = 0; i < vertex_num; ++i) {
        pG->adj_list[i].in_degree = 0;
        pG->adj_list[i].out_degree = 0;
        pG->adj_list[i].data = vexs[i];
        pG->adj_list[i].first_edge_node = NULL;
    }

    VertexType c1, c2;
    int index1, index2;
    int weight;
    for (int i = 0; i < edge_num; ++i) {
        c1 = edges[i].start;
        c2 = edges[i].end;
        index1 = get_position(c1, *pG); // c1 在顶点表中的索引
        index2 = get_position(c2, *pG);
        weight = edges[i].weight;

        ENode *node1 = (ENode *) malloc(sizeof(ENode));

        // 将node1连接到node2上,   无向图  node2->node1
        node1->adjvex_index = index1;
        node1->weight = weight; // 到 node1结点的边的权值
        //node1的入度加一， node2的出度加一
        pG->adj_list[index2].out_degree++;
        pG->adj_list[index1].in_degree++;
        //头插法
        node1->next = pG->adj_list[index2].first_edge_node;
        pG->adj_list[index2].first_edge_node = node1;

        ENode *node2 = (ENode *) malloc(sizeof(ENode));
        //同理 node1->node2
        node2->adjvex_index = index2;
        node2->weight = weight;
        // node2的入度 +1, node1的出度+1
        pG->adj_list[index2].in_degree++;
        pG->adj_list[index1].out_degree++;

        node2->next = pG->adj_list[index1].first_edge_node;
        pG->adj_list[index1].first_edge_node = node2;
    }
    return pG;
}

void print_adjvex_list(Graph G) {
    for (int i = 0; i < G.vertex_num; ++i) {
        printf("[%d: %c, (%d, %d)]->",
               i, G.adj_list[i].data, G.adj_list[i].in_degree, G.adj_list[i].out_degree);

        ENode *first_edge = G.adj_list[i].first_edge_node;
        while (first_edge != NULL) {
            printf("[%d, %d]->", first_edge->adjvex_index, first_edge->weight);
            first_edge = first_edge->next;
        }
        printf("\n");
    }
}

void BFS(Graph G) {
    int queue[MAX];
    int rear = 0, front = 0;
    int visited[MAX];
    for (int i = 0; i < G.vertex_num; ++i) {
        visited[i] = 0;
    }

    // 第一个结点0入队列
    queue[rear++] = 0;
    visited[0] = 1;

    printf("BFS:\n");
    while (front != rear) {
        int current_index = queue[front++];
        printf("%c ", G.adj_list[current_index].data);
        ENode *first_edge = G.adj_list[current_index].first_edge_node;
        while (first_edge) {
            if (!visited[first_edge->adjvex_index]) {
                queue[rear++] = first_edge->adjvex_index;
                visited[first_edge->adjvex_index] = 1;
            }
            first_edge = first_edge->next;
        }
    }
    printf("\n");
}

void DFS(Graph G) {
    int visited[MAX];
    for (int i = 0; i < G.vertex_num; ++i) {
        visited[i] = 0; // 全部标记为为访问
    }

    printf("DFS:\n");
    // 默认从第一个结点开始深度优先搜索遍历
    for (int i = 0; i < G.vertex_num; ++i) {
        if (!visited[i]) { // 结点i 未访问过
            DFSTraverse(G, i, visited);
        }
    }
    printf("\n");
}

void DFSTraverse(Graph graph, int i, int *visited) {
    printf("%c ", graph.adj_list[i].data);
    visited[i] = 1;

    ENode *first_edge = graph.adj_list[i].first_edge_node;

    while (first_edge != NULL) {
        if (!visited[first_edge->adjvex_index]) {
            DFSTraverse(graph, first_edge->adjvex_index, visited);
        }
        first_edge = first_edge->next;
    }
}

/**
 *
 * @param index1
 * @param index2
 * @return  index2到index2的权值, 如果不相邻则INF
 */
int get_weight(Graph G, int index1, int index2) {
    if (index2 == index1) {
        return 0;
    }

    ENode *temp = G.adj_list[index1].first_edge_node;
    while (temp != NULL) {
        if (temp->adjvex_index == index2) {
            return temp->weight;
        }
        temp = temp->next;
    }
    return INF;
}

/**
 *
 * @param graph  = U
 * 未选择的集合:S
 * 已经选择加入到最小生成的树的集合:U-S
 */
void prim(Graph graph) {
    // dist[i] 表示 i到集合 U-S的距离
    int dist[MAX];
    // prim假设从0开始最小生成树, 将 0 加入U-S集合
    dist[0] = 0; // 0到U-S的距离 = 0,

    // 初始化其他结点
    for (int i = 1; i < graph.vertex_num; ++i) {
        dist[i] = get_weight(graph, i, 0);
    }
    //剩下N-1个加点依次选择合适的，最后将其全部加入
    int min, k;
    printf("prim\n%c ", graph.adj_list[0].data);
    for (int i = 1; i < graph.vertex_num; ++i) {
        // 第一个作为起点不用管了
        // 从N-i元素中选择一个距离最近的元素
        min = INF;
        // 从 S 中寻找一个可以最短路径的结点
        for (int j = 1; j < graph.vertex_num; ++j) {
            // dist[j] != 0 说明 j已经加入到了 U-S, 
            if (dist[j] != 0 && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        // k 就是找到的那个结点(下标)
        // 将 k 加入U-S集合，
        dist[k] = 0;
        printf("%c ", graph.adj_list[k].data);
        // 更新相关记录信息
        for (int j = 1; j < graph.vertex_num; ++j) {
            int j_k = get_weight(graph, j, k);
            if (dist[j] != 0 && j_k < dist[j]) {
                dist[j] = j_k;
            }
        }
    }
    printf("\n");
}


void sort_edges(Edge *edges, Graph G) {
    Edge temp;
    // 排序, 这里不能用LENGTH(edges)获取数组大小
    int len = G.edge_num;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void print_edges(Edge *edges, Graph G) {
    int len = G.edge_num;
    printf("edges[%d]:\n", len);

    for (int i = 0; i < len; ++i) {
        printf("{'%c', '%c', %d},\n", edges[i].start, edges[i].end, edges[i].weight);
    }
}


Edge *get_edges(Graph G) {
    int len = G.edge_num;
    Edge *edges = (Edge *) malloc(len * sizeof(Edge));
    ENode *temp;
    int index = 0;
    for (int i = 0; i < G.vertex_num; ++i) {
        temp = G.adj_list[i].first_edge_node;
        while (temp) {
            if (temp->adjvex_index > i) {
                edges[index].start = G.adj_list[i].data;
                edges[index].end = G.adj_list[temp->adjvex_index].data;
                edges[index].weight = temp->weight;
                index++;
            }
            temp = temp->next;
        }
    }
    return edges;
}

// 得到 结点i的 根结点
int get_parent(int *parent, int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return parent[i];
}

/**
 * 操作边， 每次选取最短的一个边， 添加到生成树上构成最小生成树
 */
void kruskal(Graph G) {
    // 获取边结点集
    Edge *edges = get_edges(G);
    // 对边集进行排序
    sort_edges(edges, G);
    //定义parent数组， 用来判断两个结点是否已经连接
    int parent[MAX];
    // 初始化
    for (int i = 0; i < G.edge_num; ++i) {
        parent[i] = i; // 初始化每个结点的父节点是他自己
    }

    printf("kruskal:\n");

    for (int i = 0; i < G.edge_num; ++i) {
        // 遍历边集结点
        int p1 = get_parent(parent, get_position(edges[i].start, G));
        int p2 = get_parent(parent, get_position(edges[i].end, G));
        if (p1 != p2) {
            // 连接后不构成环，可以进行连接
            parent[p1] = p2; // 或者 parent[p2] = p1,
            printf(" (%c, %c)  %d\n", edges[i].start, edges[i].end, edges[i].weight);
        }
    }
    printf("\n");
}

/**
 *
 *
 * @param G
 * @param vs ：开始的结点
 * dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度
 */
void dijkstra(Graph G, int vs) {
    // 结点 i 是否被捕获到最短路径当中
    int captured[MAX];
    //初始化
    for (int i = 0; i < G.vertex_num; ++i) {
        captured[i] = 0; //都没有加入最短路径当中
    }
    captured[vs] = 1; // 起点开始就在
    int dist[MAX];
    //初始化
    for (int i = 0; i < G.vertex_num; ++i) {
        dist[i] = get_weight(G, i, vs);
    }
    dist[vs] = 0;

    int min;
    int k, temp;
    //开始从G的结点当中进行选取
    for (int i = 0; i < G.vertex_num; ++i) {
        if (i == vs) {
            continue;
        }

        min = INF;
        for (int j = 0; j < G.vertex_num; ++j) {
            if (!captured[j] && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        // 找到了 k是距离当前 结点最近的一个结点
        captured[k] = 1; // 标记为已捕获
        // 更新节点
        for (int j = 0; j < G.vertex_num; ++j) {
            // 防止溢出,
            temp = (get_weight(G, j, k)) == INF ? INF : (get_weight(G, j, k) + min);
            if (!captured[j] && temp < dist[j]) {
                dist[j] = temp;
            }
        }
    }

    printf("dijkstra(%c): \n", G.adj_list[vs].data);
    for (int i = 0; i < G.vertex_num; i++) {
        printf("shortest(%c, %c)=%d\n", G.adj_list[vs].data, G.adj_list[i].data, dist[i]);
    }
}

void floyd(Graph G) {
    int dp[MAX][MAX];
    for (int i = 0; i < G.vertex_num; ++i) {
        for (int j = 0; j < G.vertex_num; ++j) {
            dp[i][j] = get_weight(G, i, j);
        }
    }

    // 让每个i, j 都尝试借助 第k个结点、第k+1个结点
    for (int k = 0; k < G.vertex_num; ++k) {
        for (int i = 0; i < G.vertex_num; ++i) {
            for (int j = 0; j < G.vertex_num; ++j) {
                if (i == j) continue;
                if (k == i || k == j) continue;

                if (dp[i][k] == INF || dp[k][j] == INF) {
                    continue;
                }

                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    printf("floyd: \n");
    for (int i = 0; i < G.vertex_num; ++i) {
        for (int j = 0; j < G.vertex_num; ++j) {
            if (dp[i][j] >= INF) {
                printf("(%c,%c)=INF ", G.adj_list[i].data, G.adj_list[j].data);
                continue;
            }
            printf("(%c,%c)=%d ", G.adj_list[i].data, G.adj_list[j].data, dp[i][j]);
        }
        printf("\n");
    }
}

Edge edges_direct[] = {
        {'A', 'B', 5},
        {'A', 'C', 6},
        {'D', 'C', 2},
        {'B', 'E', 3},
        {'C', 'E', 4}
};

VertexType vexs_direct[] = {'A', 'B', 'C', 'D', 'E'};

Graph *create_graph_direct() {
    Graph *dG = (Graph *) malloc(sizeof(Graph));
    dG->edge_num = LENGTH(edges_direct);
    dG->vertex_num = LENGTH(vexs_direct);
    for (int i = 0; i < dG->vertex_num; ++i) {
        dG->adj_list[i].data = vexs_direct[i];
        dG->adj_list[i].in_degree = 0;
        dG->adj_list[i].out_degree = 0;
    }

    VertexType c1, c2;
    int weight, start_index, end_index;

    for (int i = 0; i < dG->edge_num; ++i) {
        c1 = edges_direct[i].start;
        c2 = edges_direct[i].end;
        weight = edges_direct[i].weight;

        start_index = get_position(c1, *dG);
        end_index = get_position(c2, *dG);

        ENode *end_node = (ENode *) malloc(sizeof(ENode));


        end_node->weight = weight;
        end_node->adjvex_index = end_index;
        end_node->next = dG->adj_list[start_index].first_edge_node;
        dG->adj_list[start_index].first_edge_node = end_node;
        // 出入度
        dG->adj_list[start_index].out_degree++;
        dG->adj_list[end_index].in_degree++;
    }
    return dG;
}

Status topology(Graph G) {
    ENode *eNode;
    int degree;
    int cur;
    int top = 0, count = 0;
    int *stack = (int *) malloc(sizeof(int) * G.vertex_num);

    for (int i = 0; i < G.vertex_num; ++i) {
        if (G.adj_list[i].in_degree == 0) {
            stack[top++] = i;
        }
    }
    while (top > 0) {
        cur = stack[--top]; // 出栈
        printf("%c ", G.adj_list[cur].data);

        count++;

        for (eNode = G.adj_list[cur].first_edge_node; eNode; eNode = eNode->next) {
            // 将 cur结点的所有后驱结点的度数减一
            degree = --G.adj_list[eNode->adjvex_index].in_degree;
            if (degree == 0) {
                // 度数为0
                stack[top++] = eNode->adjvex_index;
            }
        }
    }
    if (count < G.vertex_num) {
        return ERROR;
    } else {
        return OK;
    }
}

// 有点麻烦不想实现
void emphatic_route(Graph G) {
    /**
     *  结点表示事件
     *  边表示完成某件事所持续的时间(权重)
     *
     *  事件最早开始的时间取决于上个事件最早什么时候开始(活动进行)到结束(活动结束)所占用的时间
     *      即本事件要最早开始，取决于前面一个活动的时间
     */
}

int main() {
    Graph *pG = create_graph(); // 获取无向图
    print_adjvex_list(*pG);
    BFS(*pG);
    DFS(*pG);
    prim(*pG);
    kruskal(*pG);
    dijkstra(*pG, 0);
    floyd(*pG);

    Graph *dG = create_graph_direct(); // 有向图
    // 拓扑排序 AOV
    topology(*dG);
    // 关键路径 AOE
    emphatic_route(*dG);
    return 0;
}

