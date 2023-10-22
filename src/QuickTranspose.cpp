#include <bits/stdc++.h>
using namespace std;
struct Triplet
{
    int row, col, value;
    Triplet( int r, int c, int v ) : row( r ), col( c ), value( v ) {}
    Triplet() = default;
    inline bool operator<( const Triplet &rhl )
    {
        return this->col < rhl.col;
    }
    inline bool operator>( const Triplet &rhl )
    {
        return this->col > rhl.col;
    }
    inline Triplet &operator=( const Triplet &rhl )
    {
        this->col = rhl.col;
        this->row = rhl.row;
        this->value = rhl.value;
        return *this;
    }
    Triplet( const Triplet &rhl )
    {
        this->col = rhl.col;
        this->row = rhl.row;
        this->value = rhl.value;
    }
};
void out( const vector<Triplet> &v, int pos )
{
    for ( int i = pos; i < v.size(); i++ )
    {
        cout << v[i].row << "," << v[i].col << "," << v[i].value << endl;
    }
}
int main()
{
    int  n, m, k;
    char ch;  //忽略逗号
    cin >> n >> ch >> m >> ch >> k;
    vector<Triplet> matrix( k + 1 );
    matrix[0].row = n;
    matrix[0].col = m;
    matrix[0].value = k;
    for ( int i = 1; i <= k; i++ )
    {
        cin >> matrix[i].row >> ch >> matrix[i].col >> ch >> matrix[i].value;
    }
    //构造num数组,每一列的前一列的非零元素个数
    vector<int> num( m + 1, 0 );
    for ( int i = 1; i <= k; i++ )
    {
        num[matrix[i].col]++;
    }
    //构造cpot数组,即转置后第一个每一行的第一个非零元素下标
    vector<int> cpot( m + 1, { 0 } );
    cpot[1] = 1;
    for ( int i = 2; i <= m; i++ )
    {
        cpot[i] = cpot[i - 1] + num[i - 1];
    }
    //结果数组
    vector<Triplet> result( k + 1 );
    result[0] = matrix[0];
    for ( int i = 1; i <= k; i++ )
    {
        //先把第一个元素位置填上,在++
        result[cpot[matrix[i].col]++] = matrix[i];
    }
    for ( auto &&i : result )
    {
        //交换行列
        swap( i.row, i.col );
    }
    out( result, 0 );
    return 0;
}
