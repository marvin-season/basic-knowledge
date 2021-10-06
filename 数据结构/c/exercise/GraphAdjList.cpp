#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char VertexType; // ???????? --> ???

typedef int EdgeType; //  ??????  -->??

#define MAX_VERTEX 100 //???????

int visited[MAX_VERTEX];

//  ??????
typedef struct EdgeNode
{
    int index;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;

//  ????
typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstEdge;
} VertexNode, AdjList[MAX_VERTEX];

typedef struct
{
    AdjList adjList;
    int num_vertex, num_edge;
} GraphAdjList;

void CreateGraphAdjList(GraphAdjList *G)
{
    //  ??????????? ??????
    cout << "??????????? ??????" << endl;
    cin >> G->num_vertex >> G->num_edge;
    cout << "??????????" << endl;
    for (int i = 0; i < G->num_vertex; i++)
    {
        cin >> G->adjList[i].data;
        G->adjList[i].firstEdge = NULL;
    }
    for (int i = 0; i < G->num_edge; i++)
    {
        cout << "????? (x, y) ??????" << endl;
        int x, y, w;
        cin >> x >> y >> w;
        EdgeNode *e = (EdgeNode *)malloc(sizeof(EdgeNode));

        //  ?????????
        e->index = x;
        e->next = G->adjList[y].firstEdge;
        G->adjList[y].firstEdge = e;
        e->weight = w;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->index = y;
        e->next = G->adjList[x].firstEdge;
        G->adjList[x].firstEdge = e;

        e->weight = w;
    }
}

//  DFS ???? ??i?????
void DFS(GraphAdjList GL, int i)
{
    cout << GL.adjList[i].data << ends;
    visited[i] = 1;

    EdgeNode *p = GL.adjList[i].firstEdge;

    while (p != NULL)
    {
        if (!visited[p->index])
        {
            DFS(GL, p->index);
        }
        p = p->next;
    }

    visited[i] = 1;
}

void DFSTraverse(GraphAdjList GL)
{
    for (int i = 0; i < GL.num_vertex; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < GL.num_vertex; i++)
    {
        if (!visited[i])
        {
            DFS(GL, i);
        }
    }
}
int main()
{
    GraphAdjList *G = (GraphAdjList *)malloc(sizeof(GraphAdjList));
    CreateGraphAdjList(G);
    DFSTraverse(*G);
    system("pause");
    return 0;
}