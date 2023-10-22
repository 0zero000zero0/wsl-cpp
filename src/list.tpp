#include <bits/stdc++.h>
using namespace std;
template <typename T>
linkList<T>::linkList()
{
    head.next = nullptr;
    length = 0;
}
template <typename T>
void linkList<T>::show()
{

    node<T> *p = head.next;
    if ( length == 0 )
    {
        cout << "empty" << endl;
        return;
    }
    // cout << "now the link list is:" << endl;
    for ( int i = 0; i < length; i++ )
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

template <typename T>
void linkList<T>::erase( const int &pos )
//删除下标为pos的结点
{
    if ( pos < 0 || pos >= length )
    {
        string s( to_string( pos ) + " is a wrong delete place" );
        throw s;
    }

    node<T> *p = &head;
    for ( int i = 0; i < pos && p->next; i++ )
    {
        p = p->next;
    }
    node<T> *q = p->next;
    const T  value = q->data;
    p->next = q->next;
    delete q;
    length--;
    cout << "erase vlaue " << value << " in " << pos << endl;
}
template <typename T>
void linkList<T>::insert( const int &pos, const T &value )
//在pos位置上插入value
{
    if ( pos < 0 || pos > length )
    {
        string s( to_string( pos ) + " is a wrong insert place" );
        throw s;
    }
    node<T> *p = &head;
    for ( int i = 0; i < pos && p->next; i++, p = p->next ) {}
    node<T> *q = new node<T>;
    q->data = value;
    q->next = p->next;
    p->next = q;
    length++;
    // std::cout << "insert " << value << " in " << pos << endl;
    // show();
}
template <typename T>
T linkList<T>::DeleteMin()
{
    //擂台法求最小
    node<T> *p = head.next;
    T        min = p->data;  //最小元素
                             //由于假设中无重复,且有元素
    while ( p->next )
    {
        //开打👊
        if ( p->data < min )
        {
            min = p->data;
        }
        p = p->next;
    }
    //循环结束时p指向最后一个元素,因此还要再次比较
    if ( p->data < min )
    {
        min = p->data;
    }
    p = &head;
    node<T> *q = p;
    while ( p->data != min )
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
    length--;
    return min;
}
template <typename T>
void linkList<T>::Reserve()
{
    node<T> *curr = head.next;
    node<T> *prev = nullptr;
    node<T> *next = curr->next;
    while ( curr->next )
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    head.next = curr;
}
template <typename T>
int linkList<T>::Length()
{
    node<T> *p = head.next;
    if ( !p )
    {
        return 0;
    }
    int l = 1;

    while ( p->next )
    {
        l++;
        p = p->next;
    }

    return l;
}

template <typename T>
node<T> *linkList<T>::getMiddle( node<T> *start )
{
    if ( !start )
        return nullptr;
    //快慢指针
    node<T> *slow = start;
    node<T> *fast = start->next;

    while ( fast && fast->next )
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
node<T> *linkList<T>::merge( node<T> *a, node<T> *b )
{
    node<T> *result = nullptr;

    if ( !a )
        return b;
    if ( !b )
        return a;

    // Recursively merge nodes based on value comparison
    if ( a->data < b->data )
    {
        result = a;
        result->next = merge( a->next, b );
    }
    else
    {
        result = b;
        result->next = merge( a, b->next );
    }
    return result;
}

template <typename T>
void linkList<T>::sort()
{
    // 如果为空或者是只有一个元素,不需要排序
    if ( !head.next || !head.next->next )
        return;
    //分治,递归
    node<T> *middle = getMiddle( head.next );  // 找到分治点
    node<T> *middleNext = middle->next;

    middle->next = nullptr;  // 分割链表

    linkList<T> leftHalf, rightHalf;
    leftHalf.head.next = head.next;
    rightHalf.head.next = middleNext;
    //递归排序
    leftHalf.sort();
    rightHalf.sort();
    //递归合并
    head.next = merge( leftHalf.head.next, rightHalf.head.next );
}
template <typename T>
void linkList<T>::unique()
{
    node<T> *p = head.next;

    while ( p )
    {
        node<T> *q = p;  // q遍历链表

        while ( q->next )
        {  //如果q是最后一个结点,则遍历完成
            if ( q->next->data == p->data )
            {
                //删除重复项
                node<T> *temp = q->next;
                q->next = q->next->next;
                delete temp;
                length--;
            }
            else
            {
                // 找下一个结点
                q = q->next;
            }
        }

        p = p->next;  //继续遍历链表
    }
}
template <typename T>
linkList<T> linkList<T>::Spilt()
{
    // head存正数
    linkList<T> *negative = new linkList<T>;
    node<T>     *p = head.next;
    node<T>     *q = p->next;
    // p,q用于遍历原链表
    node<T> *s = &( negative->head );
    // s用于增加negative
    while ( p && p->next )
    {
        if ( q->data < 0 )
        {
            p->next = q->next;  //跳过负数结点
            this->length--;
            p = q->next;  //前进
            s->next = q;  //把负数结点连接到negative上
            negative->length++;
            s = s->next;
            if ( p )
            {
                q = p->next;  // q前进
            }
        }
    }
    return *negative;
}