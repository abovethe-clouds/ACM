#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
char mp[100][100];
int dp[20][20]={},N;
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
void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int h = 0; h < N; h++)
        {
            cout<<dp[i][h]<<" ";
        }
        cout<<endl;
    }
}
void solve()
{
   N=read();
   int a[N];
   for (int i = 0; i < N; i++)
        a[i]=read();
    vector<int> load[N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N-1-i; j++)
        {
            int qqq=read();
            load[i].push_back(qqq);
        }
    }
    int maxn=0;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j]=a[i];
        maxn=max(dp[i][0],maxn);
        }
        
        
    }
    int jilu[N],max_point=-1;
    for (int i = 0; i < N; i++)
    {
        jilu[i]=i;
    }
    for (int i = 0; i < N; i++)
    {
        int mmax=a[i];
        for (int j = 0; j < N; j++)
        {
            if(dp[i][j]>mmax)
            {
                mmax=dp[i][j];
                jilu[i]=j;
            }  
            //cout<<i<<" "<<jilu[i]<<endl;
        }
        dp[i][0]=mmax;
        for (int j = 0; j < load[i].size(); j++)
        {
            if(load[i][j])
            {
                int k = i+j;
                dp[i+j+1][i]=max(dp[i+j+1][i],dp[i][0]+dp[i+j+1][i]);
                //cout<<i+1<<" "<<i+2+j<<" "<<k+1<<" "<<dp[i][0]<<" "<<dp[i+j+1][k]<<endl;
                //print();
                if(dp[i+j+1][k]>maxn)
                {
                    maxn=max(dp[i+j+1][k],maxn);
                    max_point=i+j+1;
                }  
            }
        }
    }
    stack<int> jjjj;
    jjjj.push(max_point);
    while (jilu[max_point]!=max_point)
    {
        jjjj.push(jilu[max_point]);
        max_point=jilu[max_point];
    }
    while (!jjjj.empty())
    {
        cout<<jjjj.top()+1<<" ";
        jjjj.pop();
    }
   //cout<<jilu[1];
    
    cout<<endl<<maxn;
    
    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}