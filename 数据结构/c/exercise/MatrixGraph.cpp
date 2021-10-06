#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VertexType; // 顶点类型 --> 序号

typedef int EdgeType; //  边类型  -->权值

#define MAX_VERTEX 100 //最大顶点数

#define INFINITY 65535

int visited[MAX_VERTEX];

typedef struct MGraph
{
    VertexType vertex[MAX_VERTEX];           //顶点数组
    EdgeType matrix[MAX_VERTEX][MAX_VERTEX]; // 表示边的矩阵
    int num_vertex, num_edge;                //   顶点数   边数
} MGraph;

void CreateMGraph(MGraph *G)
{
    int vertex, edge;
    //  输入顶点个数， 边的个数
    cout << "输入顶点个数， 边的个数" << endl;
    cin >> G->num_vertex >> G->num_edge;
    cout << "输入顶点的数据" << endl;
    //  初始化顶点
    for (int i = 0; i < G->num_vertex; i++)
    {
        cin >> G->vertex[i];
    }

    // 初始化各个边
    for (int i = 0; i < G->num_vertex; i++)
    {
        for (int j = 0; j < G->num_vertex; j++)
        {
            G->matrix[i][j] = INFINITY;
        }
    }

    //  构造边    两个顶点确定一个边
    for (int i = 0; i < G->num_edge; i++)
    {
        int x, y, w;
        cout << "输入边(x,y)的下标";
        cout << "其中x, y < " << G->num_vertex << "及其边所对应的权值" << endl;
        cin >> x >> y >> w;
        G->matrix[x][y] = w;
        G->matrix[y][x] = w; //无向图， 关于正对角线对称
    }

    cout << "FINISH" << endl;
}

void DFS(MGraph G, int i)
{
    cout << G.vertex[i] << ends;
    visited[i] = 1; //标志为访问过
    for (int j; j < G.num_vertex; j++)
    {
        //  i，j 相邻
        if (!G.matrix[i][j] == INFINITY && !visited[j])
        {
            DFS(G, j);
        }
    }
}

void DFSTraverse(MGraph G)
{
    for (int i = 0; i < G.num_vertex; i++)
    {
        visited[i] = 0; //   初始化所有的顶点未访问
    }
    //  从第一个节点开始
    for (int i = 0; i < G.num_vertex; i++)
    {
        //  第i个结点未访问过
        if (!visited[i])
        {
            //  深度优先搜索访问
            DFS(G, i);
        }
    }
}

int main()
{
    MGraph *G = (MGraph *)malloc(sizeof(MGraph));
    CreateMGraph(G);
    DFSTraverse(*G);
    system("pause");
    return 0;
}