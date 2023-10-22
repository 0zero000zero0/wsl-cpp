#include <bits/stdc++.h>
using namespace std;
const int MAX_LEN = 256;
struct MyString
{
    char data[MAX_LEN];
    int  length;
    MyString( const char *s )
    {
        strcpy( this->data, s );
        length = strlen( s );
    }
    void operator+( MyString &rhs )
    {
        int l = this->length + rhs.length;
        for ( int i = 0; i < rhs.length; )
        {
            data[length++] = rhs.data[i++];
        }
        this->length = l;
    }
    void remove( int pos, int len )
    {
        if ( len + pos > this->length )
        {
            len = this->length - pos;
        }
        for ( int i = pos; i < length; i++ )
        {
            this->data[i] = this->data[i + len];
        }
        length -= len;
    }
    char operator[]( int i )
    {
        return this->data[i];
    }
};
int Index( const char s[], const char t[], int pos = 0 )
{   //索引子串
    // O(n)=nm
    int n = strlen( s ), m = strlen( t );
    int i = pos, j = 0;
    while ( i < n && j < m && n - i > m - j )
    {
        if ( s[i] == t[j] )
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if ( j == m )
        return i - m;
    else
        return -1;
}

ostream &operator<<( ostream &os, MyString s )
{
    for ( int i = 0; i < s.length; i++ )
    {
        os << s.data[i];
    }
    return os;
}

