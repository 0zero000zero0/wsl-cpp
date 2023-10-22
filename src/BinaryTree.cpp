#include <iostream>
#include <vector>
using namespace std;
#include <cstring>
char screen[10][100];
struct TreeNode
{
    char      val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode( char x ) : val( x ), left( NULL ), right( NULL ), parent( NULL )
    {
    }

    int draw( int x, int y, TreeNode *t )
    {
        // x为开始坐标
        int endX = x;
        if ( this->left )
        {
            endX = this->left->draw( x, y + 2, this ) + 1;
        }
        int centerx = endX;
        screen[y][endX++] = this->val;
        if ( this->right )
        {
            endX = this->right->draw( endX, y + 2, this ) + 1;
        }
        if ( this->parent )
        {
            if ( this->parent->left == this )
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
TreeNode *creat( const char *pre, const char *mid, int len )
{
    char      ch = pre[0];
    TreeNode *tree = new TreeNode( 0 );
    int       pos = 0;
    if ( len == 0 )
    {
        return nullptr;
    }
    while ( mid[pos] != ch )
    {
        pos++;
    }
    tree->left = creat( pre + 1, mid, pos );
    tree->right = creat( pre + pos, mid + pos, len - pos );
    return tree;
}
class BinaryTree
{
public:
    // 中序遍历
    static void inOrderTraversal( TreeNode *root )
    {
        if ( root == NULL )
        {
            cout << "#"
                 << " ";
            return;
        }
        inOrderTraversal( root->left );   // 遍历左子树
        cout << root->val << " ";         // 访问当前节点
        inOrderTraversal( root->right );  // 遍历右子树
    }
    // 后序遍历
    static void postOrderTraversal( TreeNode *root )
    {
        if ( root == NULL )
        {
            cout << "#"
                 << " ";
            return;
        }
        postOrderTraversal( root->left );   // 遍历左子树
        postOrderTraversal( root->right );  // 遍历右子树
        cout << root->val << " ";           // 访问当前节点
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
        preOrderTraversal( root->left );
        preOrderTraversal( root->right );
    }
    static int count( TreeNode *root, char e )
    {
        if ( root != NULL )
        {
            int lc = 0;
            int rc = 0;
            if ( root->left && root->right )
            {
                lc = count( root->left, e );
                rc = count( root->right, e );
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
    char  data;            //字符
    float weight;          //权重
    int   lchild, rchild;  //左右孩子
    int   parent;          //父结点
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
            cout << prefix << nodes[index].data << "(" << nodes[index].weight
                 << ")" << endl;
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
    vector<pair<char, float>> data = { { 'a', 5 },  { 'b', 9 },  { 'c', 12 },
                                       { 'd', 13 }, { 'e', 16 }, { 'f', 45 } };

    HuffmanTree tree( data );
    tree.printTree();
    return 0;
}


// int main()
// {
//     // 创建一个简单的二叉树
//     //       a
//     //      / \
//     //     b   c
//     //    / \
//     //   d   e
//     TreeNode *root = new TreeNode( 'a' );
//     root->left = new TreeNode( 'b' );
//     root->left->parent = root;
//     root->right = new TreeNode( 'c' );
//     root->right->parent = root;
//     root->left->left = new TreeNode( 'd' );
//     root->left->left->parent = root->left->left;
//     root->left->right = new TreeNode( 'e' );
//     root->left->right->parent = root->left->right;
//     BinaryTree::inOrderTraversal( root );
//     cout << endl;
//     BinaryTree::preOrderTraversal( root );
//     cout << endl;
//     BinaryTree::postOrderTraversal( root );
//     cout << endl;
//     cout << BinaryTree::count( root, 'a' );
//     cout << endl;
//     BinaryTree::visualOutput( root );
//     delete root->left->left;
//     delete root->left->right;
//     delete root->left;
//     delete root->right;
//     delete root;
//     TreeNode *t = creat( "bcefhij", "cbfeihj", 7 );
//     visualOutput( t );
//     return 0;
// }