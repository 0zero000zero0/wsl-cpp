#include <bits/stdc++.h>
using namespace std;

struct node
{
    //结点
    node *next;
    int   val;  //假设为int
    node( int val ) : val( val ), next( nullptr ){};
};
struct linkList
{
    node head;  //带头结点的
    int  length;
    linkList() : head( node( INTMAX_MIN ) ), length( 0 ) {}
    node            *insert( int pos, int val );
    void             remove( int pos );
    void             remove( int val );
    void             clear();
    node            *find( int val );
    void             merge( linkList *B );
    static linkList *merge( linkList *A, linkList *B );
    int              operator[]( int i );
};

node *linkList::insert( int pos, int val )
{
    if ( pos < 0 || pos > length )
        return nullptr;
    node *current = &head;
    for ( int i = 0; i < pos; ++i )
    {
        current = current->next;
    }
    node *newNode = new node( val );
    newNode->next = current->next;
    current->next = newNode;
    length++;
    return newNode;
}

void linkList::remove( int pos )
{
    if ( pos < 0 || pos >= length )
        return;
    node *current = &head;
    for ( int i = 0; i < pos; ++i )
    {
        current = current->next;
    }
    node *temp = current->next;
    current->next = temp->next;
    delete temp;
    length--;
}

void linkList::remove( int val )
{
    node *current = &head;
    while ( current->next != nullptr )
    {
        if ( current->next->val == val )
        {
            node *temp = current->next;
            current->next = temp->next;
            delete temp;
            length--;
            return;
        }
        current = current->next;
    }
}

void linkList::clear()
{
    node *current = head.next;
    node *temp = nullptr;
    while ( current != nullptr )
    {
        temp = current;
        current = current->next;
        delete temp;
    }
    head.next = nullptr;
    length = 0;
}

node *linkList::find( int val )
{
    node *current = head.next;
    while ( current != nullptr )
    {
        if ( current->val == val )
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void linkList::merge( linkList *B )
{
    if ( B == nullptr )
        return;
    node *current = &head;
    while ( current->next != nullptr )
    {
        current = current->next;
    }
    current->next = B->head.next;
    length += B->length;

    B->head.next = nullptr;
    B->length = 0;
}

static linkList *merge( linkList *A, linkList *B )
{
    linkList *newList = new linkList();
    node     *current = &( newList->head );
    node     *currentA = A->head.next;
    node     *currentB = B->head.next;

    while ( currentA != nullptr && currentB != nullptr )
    {
        if ( currentA->val < currentB->val )
        {
            current->next = new node( currentA->val );
            currentA = currentA->next;
        }
        else
        {
            current->next = new node( currentB->val );
            currentB = currentB->next;
        }
        current = current->next;
        newList->length++;
    }

    while ( currentA != nullptr )
    {
        current->next = new node( currentA->val );
        currentA = currentA->next;
        current = current->next;
        newList->length++;
    }
    while ( currentB != nullptr )
    {
        current->next = new node( currentB->val );
        currentB = currentB->next;
        current = current->next;
        newList->length++;
    }

    return newList;
}

int linkList::operator[]( int i )
{
    if ( i < 0 || i >= length )
        throw std::out_of_range( "Index out of range" );
    node *current = head.next;
    for ( int index = 0; index < i; ++index )
    {
        current = current->next;
    }
    return current->val;
}

int main()
{
    return 0;
}