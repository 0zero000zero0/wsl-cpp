#include <bits/stdc++.h>
using namespace std;
int Brute( const string &target, const string &pattern )
{
    int targetSize = target.size();
    int patternSize = pattern.size();
    int count = 0;
    int i = 0;
    for ( ; i <= targetSize - patternSize; i++ )
    {
        for ( int j = 0; j < patternSize; j++ )
        {
            count++;
            if ( target[i + j] != pattern[j] )
            {
                break;
            }
            if ( j == patternSize - 1 )
            {
                cout << count << endl;
                return i;
            }
        }
    }
    cout << count << endl;
    return i;
}

int KMP( const string &target, const string &pattern )
{
    int targetSize = target.size();
    int patternSize = pattern.size();
    //构造next数组
    vector<int> next( patternSize, 0 );
    int         j = 0, k = -1;
    next[0] = -1;
    while ( j < patternSize - 1 )
    {
        if ( k == -1 || pattern[j] == pattern[k] )
        {

            next[++j] = ++k;
        }
        else
        {
            k = next[k];
        }
    }
    vector<int> nextVal( patternSize, 0 );
    nextVal[0] = -1;
    for ( int i = 1; i < patternSize; i++ )
    {
        if ( pattern[next[i]] == pattern[i] )
        {
            nextVal[i] = nextVal[next[i]];
        }
        else
        {
            nextVal[i] = next[i];
        }
    }

    int i = 0;
    j = 0;
    int count = 0;
    while ( i < targetSize && j < patternSize
            && i + patternSize - j <= targetSize )
    {
        count++;
        if ( target[i] == pattern[j] )
        {
            i++;
            j++;
        }
        else
        {
            if ( j == 0 )
            {
                i++;
            }
            else
            {
                j = nextVal[j];
            }
        }
    }
    if ( j == patternSize - 1 )
    {
        cout << count << endl;
        return i - patternSize;
    }

    cout << count << endl;
    return -1;
}

int Sunday( const string &target, const string &pattern )
{
    int         targetSize = target.size();
    int         patternSize = pattern.size();
    vector<int> shitfTable( 128, patternSize + 1 );
    for ( int i = 0; i < patternSize; i++ )
    {
        //直接以字符的ASCII码作为下标(桶)
        shitfTable[pattern[i]] = patternSize - i;
    }
    int count = 0;
    int i = 0;
    while ( i <= targetSize - patternSize )
    {
        for ( int j = 0; j < patternSize; j++ )
        {
            count++;
            if ( target[i + j] != pattern[j] )
            {
                if ( i + patternSize >= targetSize )
                {
                    cout << count << endl;
                    return -1;
                }
                i += shitfTable[target[i + patternSize]];
                break;
            }
            if ( j == patternSize - 1 )
            {
                cout << count << endl;
                return i;
            }
        }
    }
    cout << count << endl;
    return -1;
}

int main()
{
    string input;
    getline( cin, input );
    // This is cpp
    stringstream ss( input );
    string       opt, target, pattern;
    getline( ss, opt, ',' );
    getline( ss, target, ',' );
    getline( ss, pattern, ',' );

    if ( opt == "Brute" )
    {
        Brute( target, pattern );
    }
    else if ( opt == "KMP" )
    {
        KMP( target, pattern );
    }
    else if ( opt == "Sunday" )
    {
        Sunday( target, pattern );
    }

    return 0;
}
