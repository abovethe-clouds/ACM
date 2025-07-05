#include<bits/stdc++.h>
using namespace std;
int main()
{
    string mingzi[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"},s;
    cin>>s;
    int l=s.length();
    if(s[0]>='0'&&s[0]<='9')
        cout<<mingzi[int(s[0]-'0')];
    else
        cout<<"fu";
    for (int i = 1; i < l; i++)
    {
        cout<<" "<<mingzi[int(s[i]-'0')];
    }
    
}
/*
0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu*/