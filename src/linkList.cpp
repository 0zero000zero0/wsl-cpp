#include <bits/stdc++.h>
using namespace std;
// 选择排序
void selectionSort( int *a, int l )
{
    int minIndex = 0;
    for ( int i = 0; i < l - 1; i++ )
    {
        minIndex = i;
        for ( int j = i; j < l; j++ )
        {
            if ( a[j] < a[minIndex] )
            {
                minIndex = j;
            }
        }
        if ( minIndex != i )
            swap( a[i], a[minIndex] );
    }
}
void selectionSort( double *a, int l )
{
    int minIndex = 0;
    for ( int i = 0; i < l - 1; i++ )
    {
        minIndex = i;
        for ( int j = i; j < l; j++ )
        {
            if ( a[j] < a[minIndex] )
            {
                minIndex = j;
            }
        }
        if ( minIndex != i )
            swap( a[i], a[minIndex] );
    }
}

// 冒泡排序
void bubbleSort( int *a, int n )
{
    int k = 0;
    for ( int i = 0; i < n - 1; i++ )
    {
        for ( int j = 0; j < n - 1 - i; j++ )
        {
            if ( a[j] > a[j + 1] )
            {
                swap( a[j], a[j + 1] );
            }
        }
    }
}

void bubbleSort( double *a, int n )
{
    double k = 0;
    for ( int i = 0; i < n - 1; i++ )
    {
        for ( int j = 0; j < n - 1 - i; j++ )
        {
            if ( a[j] > a[j + 1] )
            {
                swap( a[i], a[j] );
            }
        }
    }
}
// 链表
typedef struct Node
{  // 单向 链表数据结构
    int          a;
    struct Node *next;
} node;

int insert_node( node **head, int i, int a )  // 插入NODE
{
    node *p1, *p2;
    p1 = p2 = *head;
    int j = 1;
    while ( p1->next && j < i - 1 )
    {
        p1 = p1->next;
        j++;
    }
    if ( !p1->next || j > i )
    {
        printf( "insert error" );
        system( "pause" );
        return 0;
    }
    if ( i == 1 )  // 检查是否为头NODE
    {
        p1 = new node;
        p1->a = a;
        p1->next = p2;
        *head = p1;
        printf( "insert successfully" );
        system( "pause" );
        return 1;
    }
    else
    {
        p2 = new node;
        p2->a = a;
        //必须让新NODE先指向后继
        p2->next = p1->next;
        //再让前驱指向新NODE
        p1->next = p2;
        printf( "insert successfully" );
        system( "pause" );
        return 1;
    }
}

int delete_node_oder( node **head, int i )  // 通过序号来删除NODE
{
    if ( i <= 0 )

    {
        printf( "invalid" );
        return 0;
    }
    node *p1, *p2;
    p1 = p2 = *head;
    if ( *head == NULL )
    {
        printf( "empty" );
        return 0;
    }
    int j = 1;
    if ( i == 1 )
    {
        *head = p1->next;
        free( p1 );
        printf( "delete successfully" );
        system( "pause" );
        return 1;
    }
    else
    {
        while ( !p1->next && j < i - 1 )
        {
            p1 = p1->next;
            j++;
            if ( p1->next == NULL )
            {
                printf( "delete error" );
                system( "pause" );
                return 0;
            }
        }
        if ( !p1->next || j > i - 1 )
        {
            printf( "delete error" );
            system( "pause" );
            return 0;
        }
        // p1指向要删除NODE的前驱
        p2 = p1;
        p1 = p1->next;  // p1指向要删除的NODE
        //判断是否为尾NODE
        if ( p1->next != NULL )
        {
            p2->next = p1->next;
            free( p1 );
        }
        else
        {
            free( p1 );
            p2->next = NULL;
        }
    }
    printf( "delete successfully" );
    system( "pause" );
    return 1;
}

int delete_node_number( node **head, int a )  // ͨ通过数值来删除链表的NODE
{
    node *p1, *p2;
    p1 = p2 = *head;
    if ( *head == NULL )
    {
        printf( "empty" );
        system( "pause" );
        return 0;
    }
    if ( ( *head )->a == a )
    {
        *head = ( *head )->next;
        free( p1 );
        return 1;
    }
    while ( p1->next != NULL && p1->a != a )
    {
        p1 = p1->next;
        if ( p1->next == NULL && p1->a == a )
        {
            break;
        }
        if ( p1->next == NULL && p1->a != a )
        {
            printf( "delete error,no such data" );
            system( "pause" );
            return 0;
        }
    }
    if ( p1->next == NULL && p1->a != a )
    {
        printf( "delete error" );
        system( "pause" );
        return 0;
    }
    else
    {
        while ( p2->next != p1 )
            p2 = p2->next;
        p2->next = p1->next;
        free( p1 );
    }
    printf( "delete successfully" );
    system( "pause" );
    return 1;
}

int change_value( node *head, int i, int new_value )  // 改变链表NODE的值
{
    node *p1, *p2;
    p1 = p2 = head;
    int j = 1;
    while ( p1->next && j < i )
    {
        p1 = p1->next;
        j++;
    }
    if ( !p1->next || j > i )
    {
        printf( "change error" );
        system( "pause" );
        return 0;
    }
    p1->a = new_value;
    printf( "change successfully" );
    system( "pause" );
    return 1;
}

void linkedLstMain()
{
    node *head, *p1, *p2;
    int   n = 0;
    int   a;
    printf( "请输入初始链表长度\n" );
    scanf( "%d", &n );
    while ( n <= 0 )
    {
        printf( "无效数据,请重新输入\n" );
        scanf( "%d", &n );
    }

    printf( "请输入NODE数据\n" );
    for ( int i = 0; i < n; i++ )
    {
        scanf( "%d", &a );
        if ( i == 0 )  // 创建头NODE
        {
            head = ( node * )malloc( sizeof( node ) );
            head->a = a;
            head->next = NULL;
            p1 = p2 = head;
        }
        else  // 创建一般NODE
        {
            p1 = ( node * )malloc( sizeof( node ) );
            p1->a = a;
            p1->next = NULL;
            p2->next = p1;
            p2 = p1;
        }
    }
    // printf("链表初始为：\n");
    // for (p1 = head; p1->next != NULL; p1 = p1->next)
    // {
    //     printf("%d ", p1->a);
    // }
    // printf("%d ", p1->a);
    system( "cls" );
    printf( "现有数据:\n" );
    for ( p1 = head; p1->next != NULL; p1 = p1->next )
    {
        printf( "%d ", p1->a );
    }
    printf( "%d\n", p1->a );
    printf( "接下来要\n1.创建\n2.删除（通过位置）\n3.删除（通过数据\n4.插入"
            "\n5.改值\n6.退出\n" );
    int opt = 0;
    scanf( "%d", &opt );
    int i = 0;

    while ( 1 )
    {

        switch ( opt )
        {
        case 1:
            printf( "请输入数据\n" );  // 创建的新NODE
            scanf( "%d", &a );
            p2 = ( node * )malloc( sizeof( node ) );
            p2->a = a;
            p2->next = NULL;
            p1->next = p2;
            break;

        case 2:
            printf( "请输入删除的位置\n" );
            scanf( "%d", &i );
            delete_node_oder( &head, i );
            break;

        case 3:
            printf( "请输入要删除NODE的数据\n" );
            scanf( "%d", &a );
            delete_node_number( &head, a );
            break;

        case 4:
            printf( "请输入插入的NODE的位置和数据\n" );
            scanf( "%d%d", &i, &a );
            insert_node( &head, i, a );
            break;

        case 5:
            printf( "请输入要改变位置和值\n" );
            scanf( "%d %d", &i, &a );
            change_value( head, i, a );
            break;

        case 6:
            printf( "确认退出? 1(yes) 2(no) \n" );
            scanf( "%d", &a );
            if ( a == 1 )
                return;
            else
                continue;
        default:
            printf( "输入错误,请重新输入\n" );
            system( "pause" );
            break;
        }
        system( "cls" );  // 清屏
        printf( "现有数据:\n" );
        for ( p1 = head; p1->next != NULL; p1 = p1->next )
        {
            printf( "%d ", p1->a );
        }
        printf( "%d \n", p1->a );
        printf( "接下来要\n1.创建\n2.删除（通过位置）\n3.删除（通过数据）\n4.插入"
                "\n5.改值\n6.退出\n" );
        scanf( "%d", &opt );
    }
    system( "pause" );
}
// 判断素数
int isPrime( int x )
{
    int is = 1;
    for ( int i = 2; i < sqrt( ( double )x ); i++ )
    {
        if ( x % i == 0 )
        {
            return 0;
        }
    }
    return is;
}
void convert_string( char p[] )  // 反转字符串
{
    int  l = strlen( p );
    char tamp;
    for ( int i = 0, j = l - 1; i < l / 2; i++, j-- )
    {
        tamp = p[i];
        p[i] = p[j];
        p[j] = tamp;
    }
    p[l + 1] = '\0';
}

// 循环链表，约瑟夫问题
typedef struct josepdus
{
    int              data;
    struct josepdus *next;
} josepdus;

// 乘法口诀表
void tableOfMutiply()
{
    cout.left;
    for ( int column = 1; column <= 9; column++ )
    {
        for ( int row = 1; row <= column; row++ )
        {
            cout << column << "*" << row << "=" << column * row << " ";
        }
        cout << endl;
    }
}

void jps( int n /*人数*/, int k /*离开的报数*/ )  // 约瑟夫环(循环列表)
{
    int       count = 0;
    josepdus *head = nullptr, *p = nullptr, *q = nullptr;
    // 创建循环列表
    head = new josepdus;
    head->data = 1;
    head->next = NULL;
    p = q = head;
    for ( int i = 1; i < n; ++i )
    {
        p = new josepdus;
        p->data = i + 1;
        p->next = NULL;
        q->next = p;
        q = p;
    }
    q->next = head;
    p = q = head;
    // 创建结束
    // 遍历链表找到离开的NODE
    while ( p->next != p )
    {
        for ( int i = 1; i < k; i++ )
        {
            // 离开的NODE
            q = p;  // 保存离开NODE的前一个NODE
            p = p->next;
        }
        std::cout << p->data << " ";
        q->next = p->next;
        p = p->next;
    }
}

// 水仙花数
int myPow( int x, int n )  // 求整次方
{
    int p = 1;
    for ( int i = 1; i <= n; i++ )
    {
        p *= x;
    }
    return p;
}
void numberOfWaterFlower( int min, int max )
{
    int m_max = max, c = 0;
    while ( m_max )
    {
        m_max /= 10;
        ++c;
    }
    int *a = new int[c];
    for ( int n = min; n < max; n++ )
    {
        int t = n, cnt = 0, i = 0;
        while ( t > 0 )
        {
            a[i] = t % 10;
            t /= 10;
            ++i;
            ++cnt;
        }
        i = 0;
        int sum = 0;
        for ( ; i < cnt; ++i )
        {
            sum += myPow( a[i], cnt );
        }
        if ( sum == n )
        {
            cout << n << " ";
        }
    }
    cout << endl;
}

int EuclideanAlgorithm( int x, int y )
{
    int tamp = x % y;
    while ( tamp )
    {
        x = y;
        y = tamp;
        tamp = x % y;
    }
    return y;
}

void YangHuiSanJiao( int n )
{
    cout << "请输入行数\n";
    cin >> n;
    // cin >> n;
    // int **a = new int *[n];
    // for (int i = 0; i < n; i++)
    // {
    //     a[i] = new int[n];
    // }
    int a[n][n];
    for ( int i = 0; i < n; i++ )
    {
        a[i][i] = 1;
        a[i][0] = 1;
    }
    for ( int i = 2; i < n; i++ )
    {
        for ( int j = 1; j <= i - 1; j++ )
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j <= i; j++ )
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
//删除小于平均数的结点
node *deleteNodeUnderAverage( node *head )
{
    double ave = 0;
    int    cnt = 0;
    node  *p1 = head, *p2;
    while ( p1->next )
    {
        ave += p1->a;
        cnt++;
        p1 = p1->next;
    }
    ave += p1->a;
    cnt++;
    ave /= cnt;
    p1 = head;
    p2 = head;
    while ( p1->next )
    {
        if ( ( p1->a < ave ) && ( p1 = head ) && ( p1->next != NULL ) )
        {
            head = p1->next;
            p1 = head;
            p2 = p1;
        }
        else if ( ( p1->a < ave ) && ( p1 != head ) && ( p1->next != NULL ) )
        {
            p2 = p1->next;
            p1 = p2;
        }
        else if ( ( p1->a < ave ) && ( p1 != head ) && ( p1->next == NULL ) )
        {
            p2->next = NULL;
        }
        else
        {
            p2 = p1;
            p1 = p1->next;
        }
    }
    p1 = p2 = head;
    while ( p1->next )
    {
        cout << p1->a << " ";
        p1 = p1->next;
    }
    cout << p1->a << " ";
    return head;
}