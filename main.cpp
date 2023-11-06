#include <bits/stdc++.h>
using namespace std;
using point = std::pair<int, int>;
struct ArcNode
{
    int adjvex;  //邻接点域，存放与vi邻接的点在表头数组中的位置
    int info;    //对于网络，存储权重信息

    ArcNode *nextarc;  // 指针域，指向下一条边或弧
    ArcNode( int adjvex, int info, ArcNode *nextarc ) : adjvex( adjvex ), info( info ), nextarc( nextarc ) {}
};
struct VexNode
{
    char     vexdata;  //存放顶点信息
    int      length;
    ArcNode *firstarc;  //指示第一个邻接点
    VexNode( char c, ArcNode *firstarc ) : vexdata( c ), firstarc( firstarc ) {}
    VexNode() : VexNode( ' ', nullptr ) {}
    void addEdge( int v, int w );  // todo :UNFILISHED
};

void VexNode::addEdge( int v, int w ) {}
struct Graph
{
    vector<VexNode> adj;  //邻接表
    int             V;    //顶点数量
    void            addEdge( int u, int v, int w );
};
void Graph::addEdge( int u, int v, int w )
{
    if ( u > adj.size() || v > adj.size() )
    {
        throw "add edge error";
    }
    adj[u];  // todo :UNFILISHED
}
int main()
{
    //DO
    return 0;
}