#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VertexType; // �������� --> ���

typedef int EdgeType; //  ������  -->Ȩֵ

#define MAX_VERTEX 100 //��󶥵���

#define INFINITY 65535

int visited[MAX_VERTEX];

typedef struct MGraph
{
    VertexType vertex[MAX_VERTEX];           //��������
    EdgeType matrix[MAX_VERTEX][MAX_VERTEX]; // ��ʾ�ߵľ���
    int num_vertex, num_edge;                //   ������   ����
} MGraph;

void CreateMGraph(MGraph *G)
{
    int vertex, edge;
    //  ���붥������� �ߵĸ���
    cout << "���붥������� �ߵĸ���" << endl;
    cin >> G->num_vertex >> G->num_edge;
    cout << "���붥�������" << endl;
    //  ��ʼ������
    for (int i = 0; i < G->num_vertex; i++)
    {
        cin >> G->vertex[i];
    }

    // ��ʼ��������
    for (int i = 0; i < G->num_vertex; i++)
    {
        for (int j = 0; j < G->num_vertex; j++)
        {
            G->matrix[i][j] = INFINITY;
        }
    }

    //  �����    ��������ȷ��һ����
    for (int i = 0; i < G->num_edge; i++)
    {
        int x, y, w;
        cout << "�����(x,y)���±�";
        cout << "����x, y < " << G->num_vertex << "���������Ӧ��Ȩֵ" << endl;
        cin >> x >> y >> w;
        G->matrix[x][y] = w;
        G->matrix[y][x] = w; //����ͼ�� �������Խ��߶Գ�
    }

    cout << "FINISH" << endl;
}

void DFS(MGraph G, int i)
{
    cout << G.vertex[i] << ends;
    visited[i] = 1; //��־Ϊ���ʹ�
    for (int j; j < G.num_vertex; j++)
    {
        //  i��j ����
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
        visited[i] = 0; //   ��ʼ�����еĶ���δ����
    }
    //  �ӵ�һ���ڵ㿪ʼ
    for (int i = 0; i < G.num_vertex; i++)
    {
        //  ��i�����δ���ʹ�
        if (!visited[i])
        {
            //  ���������������
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