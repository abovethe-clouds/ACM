#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    string s;
    cin>>s;
    int l=s.length();
    for (int i = 0; i < l; i++)
    {
        a[int(s[i]-'0')]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if(a[i])
        cout<<i<<":"<<a[i]<<endl;
    }
    return 0;
}