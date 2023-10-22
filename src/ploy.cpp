#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int          coef;  // 系数
    int          exp;   // 指数
    struct node *next;
} node;
void swap( node *a, node *b )
{
    int tempCoef = a->coef;
    int tempExp = a->exp;
    a->coef = b->coef;
    a->exp = b->exp;
    b->coef = tempCoef;
    b->exp = tempExp;
}
void sort( node **start )
{
    int   swapped;
    node *ptr1;
    node *ptr2 = NULL;
    if ( *start == NULL )
    {
        return;
    }
    do
    {
        swapped = 0;
        ptr1 = *start;
        while ( ptr1->next != ptr2 )
        {
            if ( ptr1->exp > ptr1->next->exp )
            {
                swap( ptr1, ptr1->next );
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while ( swapped );
}
// 创建新节点
node *newnode( int coef, int exp )
{
    node *new_node = ( node * )malloc( sizeof( node ) );
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}

// what the fuck
void insert( node **poly, int coef, int exp )
{
    node *new_node = newnode( coef, exp );
    if ( !*poly )
    {
        *poly = new_node;
        return;
    }
    node *curr = *poly;
    node *prev = *poly;

    while ( curr->next && curr->next->exp <= exp )
    {
        prev = curr;
        curr = curr->next;
    }
    if ( curr->exp == exp )
    {
        //指数一样
        curr->coef += coef;
        free( new_node );
    }
    else if ( curr->exp > exp )
    {
        if ( curr == *poly )
        {
            new_node->next = curr;
            *poly = new_node;
        }
        else
        {
            new_node->next = curr;
            prev->next = new_node;
        }
    }
    else
    {
        new_node->next = curr->next;
        curr->next = new_node;
    }
}
void erease( node **poly )  // 删除系数为0的项
{
    node *p = *poly;
    node *q = p;
    node *r = p;

    while ( p->next && q->next )
    {
        if ( p->coef == 0 )  //第一个为0
        {
            *poly = p->next;
            free( p );
            p = *poly;
            continue;
        }
        q = p->next;
        r = q->next;
        if ( q->coef == 0 )
        {
            p->next = r;
            free( q );
        }
        p = p->next;
    }
    if ( p->coef == 0 )  //如果只剩下一个结点
    {
        p->next = NULL;
        free( p );
        ( *poly ) = NULL;
    }
}
// 加法
node *add( node *A, node *B )
{
    sort( &A );
    sort( &B );
    node *result = NULL;
    while ( A )
    {

        insert( &result, A->coef, A->exp );
        A = A->next;
    }
    sort( &result );
    while ( B )
    {
        insert( &result, B->coef, B->exp );
        B = B->next;
    }
    return result;
}

// 减法
node *subtract( node *A, node *B )
{
    node *result = NULL;
    sort( &A );
    sort( &B );
    while ( A )
    {
        insert( &result, A->coef, A->exp );
        A = A->next;
    }
    while ( B )
    {
        insert( &result, -B->coef, B->exp );
        B = B->next;
    }
    return result;
}

// 乘法
node *multiply( node *A, node *B )
{
    sort( &A );
    sort( &B );
    node *result = NULL;
    node *tempB = B;
    while ( A )
    {
        while ( B )
        {
            insert( &result, A->coef * B->coef, A->exp + B->exp );
            B = B->next;
        }
        A = A->next;
        B = tempB;
    }
    return result;
}

// 打印多项式
void show( node *poly )
{
    erease( &poly );
    if ( !poly )
    {
        printf( "None\n" );
        return;
    }
    sort( &poly );
    int isFirst = 1;
    while ( poly )
    {
        if ( poly->coef == 0 )
        {
            poly = poly->next;
            continue;
        }

        if ( !isFirst )
        {
            if ( poly->coef > 0 )
                printf( "+" );
        }
        isFirst = 0;
        printf( "%dx^%d", poly->coef, poly->exp );
        poly = poly->next;
    }
    printf( "\n" );
}

// oh my good
node *parsePoly( char *str )
{

    node *poly = NULL;
    int   coef, exp;
    while ( *str )
    {
        int sign = 1;  // 判断正负,默认为正
        if ( *str == '-' )
        {
            sign = -1;
            str++;
        }
        else if ( *str == '+' )
        {
            str++;
        }

        if ( sscanf( str, "%dx^%d", &coef, &exp ) == 2 )  //判读是否正常读入
        {
            coef *= sign;  // 调整系数
            insert( &poly, coef, exp );
            while ( *str && *str != '+' && *str != '-' )
                str++;  //把指针移到多项式末尾
        }
        else
        {
            break;  // 如果没有正确的格式，跳出循环
        }
    }
    return poly;
}

int main()
{
    char strA[100], strB[100], op;
    scanf( "%s", strA );
    scanf( "%s", strB );
    getchar();
    scanf( "%c", &op );

    node *A = parsePoly( strA );
    node *B = parsePoly( strB );
    node *C;

    if ( op == '+' )
    {
        C = add( A, B );
    }
    else if ( op == '-' )
    {
        C = subtract( A, B );
    }
    else if ( op == '*' )
    {
        C = multiply( A, B );
    }
    else
    {
        C = NULL;
    }

    show( C );
    return 0;
}
