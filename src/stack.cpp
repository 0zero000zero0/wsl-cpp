#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct MyStack
{
    static const int MAX_SIZE = 20;
    T                stack[MAX_SIZE];
    int              top;
    MyStack()
    {
        top = 0;
    }
    int size()
    {
        return top;
    }
    bool isEmpty()
    {
        return top == 0;
    }
    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }
    void push( T c )
    {
        if ( isFull() )
        {
            throw "full";
        }
        stack[top++] = c;
    }
    T pop()
    {
        if ( isEmpty() )
        {
            throw "empty";
        }
        return stack[--top];
    }
};

inline int ctoi( char c )
{
    return c - '0';
}
pair<double, int> parseNumber( const string &s, int idx )
{
    double num = 0.0;
    //遍历找到非数字部分
    int flag = 1;
    while ( idx < s.length() && isdigit( s[idx] )
            || ( idx == 0 && s[idx++] == '-' ) )
    {
        //构造整数部分

        num = num * 10 + ctoi( s[idx] );
        if ( idx == 0 && s[idx] == '-' )
        {

            num *= -1;
        }
        idx++;
    }
    // 解析小数部分
    if ( idx < s.length() && s[idx] == '.' )
    {
        idx++;
        double divisor = 10.0;
        while ( idx < s.length() && isdigit( s[idx] ) )
        {
            num += ctoi( s[idx] ) / divisor;
            divisor *= 10;
            idx++;
        }
    }
    return make_pair( num, idx );
}
int precedence( char op )
{
    //优先级
    switch ( op )
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
double compute( double a, double b, char op )
{
    switch ( op )
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow( a, b );
    default:
        throw "Invalid operation";
    }
}

double evaluateExpression( const string &s )
{
    MyStack<double> numbers;
    MyStack<char>   options;
    int             i = 0;
    while ( i < s.length() )
    {
        if ( s[i] == ' ' )
        {
            i++;
            continue;
        }
        if ( isdigit( s[i] )
             || ( i > 0 && s[i] == '-' && ( s[i - 1] == '(' ) ) )
        {
            pair<double, int> result = parseNumber( s, i );
            numbers.push( result.first );
            i = result.second;
        }
        else if ( i == 0 && s[i] == '-' )
        {
            pair<double, int> result = parseNumber( s, i + 1 );
            numbers.push( -result.first );
            i = result.second;
        }

        else if ( s[i] == '(' )
        {
            options.push( s[i] );
            i++;
        }
        else if ( s[i] == ')' )
        {
            while ( options.top > 0 && options.stack[options.top - 1] != '(' )
            {
                double val2 = numbers.pop();
                double val1 = numbers.pop();
                char   op = options.pop();
                numbers.push( compute( val1, val2, op ) );
            }
            options.pop();  //弹出)
            i++;
        }
        else
        {
            while ( options.top > 0
                    && precedence( options.stack[options.top - 1] )
                           >= precedence( s[i] ) )
            {
                double val2 = numbers.pop();
                double val1 = numbers.pop();
                char   op = options.pop();
                numbers.push( compute( val1, val2, op ) );
            }
            options.push( s[i] );
            i++;
        }
    }
    while ( options.top > 0 )
    {
        double val2 = numbers.pop();
        double val1 = numbers.pop();
        char   op = options.pop();
        numbers.push( compute( val1, val2, op ) );
    }
    return numbers.pop();
}
void bracketPair( string s )
{
    getline( cin, s );
    MyStack<char> sk;
    bool          flag = true;
    for ( int i = 0; i < s.size(); i++ )
    {
        switch ( s[i] )
        {
        case '{':
        case '[':
        case '(':
            sk.push( s[i] );
            break;
        case ')':
            if ( !sk.isEmpty() && sk.pop() == '(' )
            {
                break;
            }
            else
            {
                flag = false;
            }
            break;
        case ']':
            if ( !sk.isEmpty() && sk.pop() == '[' )
            {
                break;
            }
            else
            {
                flag = false;
            }
            break;
        case '}':
            if ( !sk.isEmpty() && sk.pop() == '{' )
            {
                break;
            }
            else
            {
                flag = false;
            }
            break;
        }
    }

    cout << ( flag ? "correct" : "error" ) << endl;
}
int main()
{
    return 0;
}
