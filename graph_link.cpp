//
// Created by mawenshu on 2021/5/12.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX         100                 // �����������
#define SIZE        10                  // �����������
#define INF         (~(0x1<<31))        // ���ֵ(��0X7FFFFFFF)
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

    // ��ʼ���������
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
        index1 = get_position(c1, *pG); // c1 �ڶ�����е�����
        index2 = get_position(c2, *pG);
        weight = edges[i].weight;

        ENode *node1 = (ENode *) malloc(sizeof(ENode));

        // ��node1���ӵ�node2��,   ����ͼ  node2->node1
        node1->adjvex_index = index1;
        node1->weight = weight; // �� node1���ıߵ�Ȩֵ
        //node1����ȼ�һ�� node2�ĳ��ȼ�һ
        pG->adj_list[index2].out_degree++;
        pG->adj_list[index1].in_degree++;
        //ͷ�巨
        node1->next = pG->adj_list[index2].first_edge_node;
        pG->adj_list[index2].first_edge_node = node1;

        ENode *node2 = (ENode *) malloc(sizeof(ENode));
        //ͬ�� node1->node2
        node2->adjvex_index = index2;
        node2->weight = weight;
        // node2����� +1, node1�ĳ���+1
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

    // ��һ�����0�����
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
        visited[i] = 0; // ȫ�����ΪΪ����
    }

    printf("DFS:\n");
    // Ĭ�ϴӵ�һ����㿪ʼ���������������
    for (int i = 0; i < G.vertex_num; ++i) {
        if (!visited[i]) { // ���i δ���ʹ�
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
 * @return  index2��index2��Ȩֵ, �����������INF
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
 * δѡ��ļ���:S
 * �Ѿ�ѡ����뵽��С���ɵ����ļ���:U-S
 */
void prim(Graph graph) {
    // dist[i] ��ʾ i������ U-S�ľ���
    int dist[MAX];
    // prim�����0��ʼ��С������, �� 0 ����U-S����
    dist[0] = 0; // 0��U-S�ľ��� = 0,

    // ��ʼ���������
    for (int i = 1; i < graph.vertex_num; ++i) {
        dist[i] = get_weight(graph, i, 0);
    }
    //ʣ��N-1���ӵ�����ѡ����ʵģ������ȫ������
    int min, k;
    printf("prim\n%c ", graph.adj_list[0].data);
    for (int i = 1; i < graph.vertex_num; ++i) {
        // ��һ����Ϊ��㲻�ù���
        // ��N-iԪ����ѡ��һ�����������Ԫ��
        min = INF;
        // �� S ��Ѱ��һ���������·���Ľ��
        for (int j = 1; j < graph.vertex_num; ++j) {
            // dist[j] != 0 ˵�� j�Ѿ����뵽�� U-S, 
            if (dist[j] != 0 && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        // k �����ҵ����Ǹ����(�±�)
        // �� k ����U-S���ϣ�
        dist[k] = 0;
        printf("%c ", graph.adj_list[k].data);
        // ������ؼ�¼��Ϣ
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
    // ����, ���ﲻ����LENGTH(edges)��ȡ�����С
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

// �õ� ���i�� �����
int get_parent(int *parent, int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return parent[i];
}

/**
 * �����ߣ� ÿ��ѡȡ��̵�һ���ߣ� ��ӵ��������Ϲ�����С������
 */
void kruskal(Graph G) {
    // ��ȡ�߽�㼯
    Edge *edges = get_edges(G);
    // �Ա߼���������
    sort_edges(edges, G);
    //����parent���飬 �����ж���������Ƿ��Ѿ�����
    int parent[MAX];
    // ��ʼ��
    for (int i = 0; i < G.edge_num; ++i) {
        parent[i] = i; // ��ʼ��ÿ�����ĸ��ڵ������Լ�
    }

    printf("kruskal:\n");

    for (int i = 0; i < G.edge_num; ++i) {
        // �����߼����
        int p1 = get_parent(parent, get_position(edges[i].start, G));
        int p2 = get_parent(parent, get_position(edges[i].end, G));
        if (p1 != p2) {
            // ���Ӻ󲻹��ɻ������Խ�������
            parent[p1] = p2; // ���� parent[p2] = p1,
            printf(" (%c, %c)  %d\n", edges[i].start, edges[i].end, edges[i].weight);
        }
    }
    printf("\n");
}

/**
 *
 *
 * @param G
 * @param vs ����ʼ�Ľ��
 * dist -- �������顣����dist[i]��"����vs"��"����i"�����·���ĳ���
 */
void dijkstra(Graph G, int vs) {
    // ��� i �Ƿ񱻲������·������
    int captured[MAX];
    //��ʼ��
    for (int i = 0; i < G.vertex_num; ++i) {
        captured[i] = 0; //��û�м������·������
    }
    captured[vs] = 1; // ��㿪ʼ����
    int dist[MAX];
    //��ʼ��
    for (int i = 0; i < G.vertex_num; ++i) {
        dist[i] = get_weight(G, i, vs);
    }
    dist[vs] = 0;

    int min;
    int k, temp;
    //��ʼ��G�Ľ�㵱�н���ѡȡ
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
        // �ҵ��� k�Ǿ��뵱ǰ ��������һ�����
        captured[k] = 1; // ���Ϊ�Ѳ���
        // ���½ڵ�
        for (int j = 0; j < G.vertex_num; ++j) {
            // ��ֹ���,
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

    // ��ÿ��i, j �����Խ��� ��k����㡢��k+1�����
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
        // �����
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
        cur = stack[--top]; // ��ջ
        printf("%c ", G.adj_list[cur].data);

        count++;

        for (eNode = G.adj_list[cur].first_edge_node; eNode; eNode = eNode->next) {
            // �� cur�������к������Ķ�����һ
            degree = --G.adj_list[eNode->adjvex_index].in_degree;
            if (degree == 0) {
                // ����Ϊ0
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

// �е��鷳����ʵ��
void emphatic_route(Graph G) {
    /**
     *  ����ʾ�¼�
     *  �߱�ʾ���ĳ������������ʱ��(Ȩ��)
     *
     *  �¼����翪ʼ��ʱ��ȡ�����ϸ��¼�����ʲôʱ��ʼ(�����)������(�����)��ռ�õ�ʱ��
     *      �����¼�Ҫ���翪ʼ��ȡ����ǰ��һ�����ʱ��
     */
}

int main() {
    Graph *pG = create_graph(); // ��ȡ����ͼ
    print_adjvex_list(*pG);
    BFS(*pG);
    DFS(*pG);
    prim(*pG);
    kruskal(*pG);
    dijkstra(*pG, 0);
    floyd(*pG);

    Graph *dG = create_graph_direct(); // ����ͼ
    // �������� AOV
    topology(*dG);
    // �ؼ�·�� AOE
    emphatic_route(*dG);
    return 0;
}

