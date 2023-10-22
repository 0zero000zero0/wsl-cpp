template <typename T>
struct node
{
    T        data;
    node<T> *next;
};
template <typename T>
struct linkList
{
    int     length;
    node<T> head;
    linkList();
    void         show();
    void         insert( const int &pos, const T &value );
    void         erase( const int &pos );
    T            DeleteMin();
    void         Reserve();
    int          Length();
    void         sort();
    node<T>     *getMiddle( node<T> *start );
    node<T>     *merge( node<T> *a, node<T> *b );
    void         unique();
    linkList<T> Spilt();
};
// 包含模板定义
#include "list.tpp"