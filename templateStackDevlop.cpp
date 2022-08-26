#include<bits/stdc++.h>
using namespace std;
template<typename T> T findMax(T a,T b)
{
    return (a>b) ? a : b;
}
int main()
{
    cout<<findMax(10,20)<<endl; //functionName <data type> (parameter)
    cout<<findMax(10.5,20.2)<<endl;
    cout<<findMax('a','f')<<endl;
    cout<<findMax("kaochar","khalekuzzaman");

    return 0;
}
