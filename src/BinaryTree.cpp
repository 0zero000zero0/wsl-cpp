#include <iostream>
#include <vector>
using namespace std;
#include <cstring>
char screen[10][100];
struct TreeNode
{
    char      val;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode *parent;
    TreeNode( char x ) : val( x ), lchild( NULL ), rchild( NULL ), parent( NULL ) {}

    int draw( int x, int y, TreeNode *t )
    {
        // x为开始坐标
        int endX = x;
        if ( this->lchild )
        {
            endX = this->lchild->draw( x, y + 2, this ) + 1;
        }
        int centerx = endX;
        screen[y][endX++] = this->val;
        if ( this->rchild )
        {
            endX = this->rchild->draw( endX, y + 2, this ) + 1;
        }
        if ( this->parent )
        {
            if ( this->parent->lchild == this )
            {
                for ( int i = centerx; i <= endX; i++ )
                {
                    screen[y - 1][centerx] = '/';
                }
            }
            else
            {
                for ( int i = x; i <= centerx; i++ )
                {
                    screen[y - 1][centerx] = '\\';
                }
            }
        }

        return endX;
    }
};

class BinaryTree
{
public:
    static int index;
    // 先序字符串构建二叉树
    static TreeNode *create_pre( const string &preorder )
    {
        if ( index >= preorder.length() )
            return nullptr;

        if ( preorder[index] == '#' )
        {
            index++;
            return nullptr;
        }

        TreeNode *root = new TreeNode( preorder[index++] );
        root->lchild = create_pre( preorder );
        root->rchild = create_pre( preorder );

        return root;
    }
    // 通过先序和中序字符串构建二叉树
    static TreeNode *create_pre_mid( const char *pre, const char *mid, int len )
    {
        if ( len <= 0 )
        {
            return nullptr;
        }

        char      ch = pre[0];
        TreeNode *tree = new TreeNode( ch );
        int       pos = 0;

        while ( mid[pos] != ch )
        {
            pos++;
        }
        tree->lchild = create_pre_mid( pre + 1, mid, pos );
        pos++;
        tree->rchild = create_pre_mid( pre + pos, mid + pos, len - pos );
        return tree;
    }
    // 中序遍历
    static void inOrderTraversal( TreeNode *root )
    {
        if ( root == NULL )
        {
            cout << "#"
                 << " ";
            return;
        }
        inOrderTraversal( root->lchild );  // 遍历左子树
        cout << root->val << " ";          // 访问当前节点
        inOrderTraversal( root->rchild );  // 遍历右子树
    }
    // 后序遍历
    static void postOrderTraversal( TreeNode *root )
    {
        if ( root == NULL )
        {
            // cout << "#"
            //      << " ";
            return;
        }
        postOrderTraversal( root->lchild );  // 遍历左子树
        postOrderTraversal( root->rchild );  // 遍历右子树
        // cout << root->val << " ";         // 访问当前节点
        cout << root->val;  // 访问当前节点
    }
    static void preOrderTraversal( TreeNode *root )
    {
        if ( root == NULL )
        {
            cout << "#"
                 << " ";
            return;
        }
        cout << root->val << " ";
        preOrderTraversal( root->lchild );
        preOrderTraversal( root->rchild );
    }
    static int count( TreeNode *root, char e )
    {
        if ( root != NULL )
        {
            int lc = 0;
            int rc = 0;
            if ( root->lchild && root->rchild )
            {
                lc = count( root->lchild, e );
                rc = count( root->rchild, e );
            }
            return lc + rc + ( root->val == e ? 1 : 0 );
        }
        return 0;
    }
    static void visualOutput( TreeNode *t )
    {
        for ( int i = 0; i < 10; i++ )
        {
            strcpy( screen[i], "                  " );
        }
        t->draw( 0, 0, NULL );
        for ( int i = 0; i < 10; i++ )
        {
            cout << screen[i] << endl;
        }
    }
};
int  BinaryTree::index = 0;
void visualOutput( TreeNode *t )
{
    for ( int i = 0; i < 10; i++ )
    {
        strcpy( screen[i], "                  " );
    }
    t->draw( 0, 0, NULL );
    for ( int i = 0; i < 10; i++ )
    {
        cout << screen[i] << endl;
    }
}
struct HuffmanNode
{
    char  data;            // 字符
    float weight;          // 权重
    int   lchild, rchild;  // 左右孩子
    int   parent;          // 父结点
};

class HuffmanTree
{
public:
    HuffmanTree( const vector<pair<char, float>> &data )
    {
        int n = data.size();
        nodes.resize( 2 * n - 1 );

        for ( int i = 0; i < n; i++ )
        {
            nodes[i].data = data[i].first;
            nodes[i].weight = data[i].second;
            nodes[i].lchild = nodes[i].rchild = nodes[i].parent = -1;
        }

        for ( int i = n; i < 2 * n - 1; i++ )
        {
            // 寻找权值最小的两个节点
            int s1 = -1, s2 = -1;
            for ( int j = 0; j < i; j++ )
            {
                if ( nodes[j].parent == -1 )
                {
                    if ( s1 == -1 )
                    {
                        s1 = j;
                    }
                    else if ( s2 == -1 )
                    {
                        s2 = j;
                    }
                    else
                    {
                        if ( nodes[j].weight < nodes[s1].weight )
                        {
                            s2 = s1;
                            s1 = j;
                        }
                        else if ( nodes[j].weight < nodes[s2].weight )
                        {
                            s2 = j;
                        }
                    }
                }
            }
            nodes[i].weight = nodes[s1].weight + nodes[s2].weight;
            nodes[i].lchild = s1;
            nodes[i].rchild = s2;
            nodes[s1].parent = i;
            nodes[s2].parent = i;
        }
    }

    void printTree()
    {
        printTree( 2 * nodes.size() / 2 - 1, "" );
    }

private:
    vector<HuffmanNode> nodes;

    void printTree( int index, const string &prefix )
    {
        if ( index == -1 )
            return;

        if ( nodes[index].lchild == -1 && nodes[index].rchild == -1 )
        {
            cout << prefix << nodes[index].data << "(" << nodes[index].weight << ")" << endl;
        }
        else
        {
            cout << prefix << nodes[index].weight << endl;
            printTree( nodes[index].lchild, prefix + "  L- " );
            printTree( nodes[index].rchild, prefix + "  R- " );
        }
    }
};

int main()
{
    string s1, s2;
    getline( cin, s1 );
    getline( cin, s2 );
    if ( s1.find( '#' ) != string::npos )
    {
        TreeNode *root = BinaryTree::create_pre( s1 );
        BinaryTree::postOrderTraversal( root );
    }
    else
    {
        int         size = s1.size();
        const char *c_s1 = s1.c_str();
        const char *c_s2 = s2.c_str();
        TreeNode   *root = BinaryTree::create_pre_mid( c_s1, c_s2, size );
        BinaryTree::postOrderTraversal( root );
    }

    return 0;
}
