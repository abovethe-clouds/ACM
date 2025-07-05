#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn=1e5+5;
int read() 
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') 
    {  
        if (ch == '-') w = -1;        
        ch = getchar();               
    }
    while (ch >= '0' && ch <= '9') 
    {  
        x = x * 10 + (ch - '0');
        ch = getchar();  
    }
    return x * w; 
}
int n;
string sol(int* s,bool aa,char* ans)
{
    deque<int> a,b;
    //queue<char> f;
    //stack<char> e;
    //a.push_back(s[0]);
    int i;
    int p=0,q=n-1;
    if(aa==0)
    {
        for ( i = 1; i < n; i++)
        {
            a.push_back(s[i]);
            if(s[i]==s[0])
                break;
        }
        a.pop_back();
        i++;
        for (i; i < n; i++)
        {
            b.push_back(s[i]);
        }
        ans[p++]='L';
        ans[q--]='L';
    }
    else
    {
        for ( i = 0; i < n; i++)
        {
            a.push_back(s[i]);
            if(s[i]==s[n-1])
                break;
        }
        a.pop_back();
        i++;
        for (i; i < n-1; i++)
        {
            b.push_back(s[i]);
        }
        ans[p++]='R';
        ans[q--]='L';
    }
    while(!(a.empty()&&b.empty()))
    {
        if (a.size() >= 2 && a.front() == a.back()) 
        {
            ans[p++]='L'; 
            ans[q--]='L';
            a.pop_back(); 
            a.pop_front();
        } 
        else if (!a.empty() && !b.empty() && a.front() == b.front()) 
        {
            ans[p++]='L'; 
            ans[q--]='R';
            b.pop_front();
            a.pop_front();
        } 
        else if (!a.empty() && !b.empty() && a.back() == b.back()) 
        {
            ans[p++]='R';
            ans[q--]='L';
            a.pop_back();
            b.pop_back();
        } 
        else if (b.size() >= 2 && b.front() == b.back()) 
        {
            ans[p++]='R';
            ans[q--]='R';
            b.pop_back();
            b.pop_front();
        } 
        else 
        {
            return "-1";
        }
    }
    
    return "Y";
}
void print(char* p)
{
    for (int i = 0; i < n; i++)
    {
        cout<<p[i];
    }
    cout<<endl;
}
void solve()
{
    //int n;
    n=read();
    n*=2;
    int ppp[n];
    char ans[n]={};
    for (int i = 0; i < n; i++)
    {
        ppp[i]=read();
    }
    string s1=sol(ppp,0,ans);
    if(s1!="-1")
    {
        print(ans);
        return;
    }
    string s2=sol(ppp,1,ans);
    if(s2=="-1")
        cout<<"-1"<<endl;
    else
        print(ans);
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    t=read();
    while(t --)
        solve();

    return 0;
}