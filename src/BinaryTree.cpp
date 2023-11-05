#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Bintree
{
    char     data;
    Bintree *lchild = NULL, *rchild = NULL;
    Bintree() {}
    Bintree( char c )
    {
        data = c;
    }
    //能直接处理字符串使之构建成一个二叉树的代码
    static Bintree *creat( const char *str, int &idx )
    {
        char ch = str[idx];
        idx++;
        if ( ch == '#' )
        {
            return NULL;
        }
        Bintree *node = new Bintree( ch );
        node->lchild = creat( str, idx );
        node->rchild = creat( str, idx );
        return node;
    }
    //后序遍历输出
    void RearPut()
    {
        if ( lchild != NULL )
        {
            lchild->RearPut();
        }
        if ( rchild != NULL )
        {
            rchild->RearPut();
        }
        if ( data != '#' )
        {
            cout << data;
        }
    }
    void SRearPut()
    {
        if ( lchild != NULL )
        {
            lchild->SRearPut();
        }
        if ( rchild != NULL )
        {
            rchild->SRearPut();
        }
        cout << data;
    }

    //根据先序和中序，输出后序
    static Bintree *creat( const char *pre, const char *mid, int len )
    {
        if ( len == 0 )
        {
            return NULL;
        }
        char     ch = pre[0];
        Bintree *node = new Bintree( ch );

        //查找根节点在中序遍历出现的位置
        int pos = 0;
        while ( mid[pos] != ch )
        {
            pos++;
        }
        node->lchild = creat( pre + 1, mid, pos );
        node->rchild = creat( pre + pos + 1, mid + pos + 1, len - pos - 1 );
        return node;
    }
};
int main()
{
    int  idx = 0;
    char s1[200], s2[200];
    cin >> s1;
    cin >> s2;
    int len = strlen( s1 );
    if ( s1[len - 2] != '#' )
    {
        fgets( s2, sizeof( s2 ), stdin );
        Bintree *tree = Bintree::creat( s1, s2, len );
        tree->SRearPut();
    }
    else if ( s1[len - 2] == '#' )
    {
        Bintree *tree = Bintree::creat( s1, idx );
        tree->RearPut();
    }
    return 0;
}