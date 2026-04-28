#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
int n;
struct clas
{
    int bianhao;
    int lim;
    int youxianclass;
    vector<int>youxian,putong;
};
clas classes[1001];
struct stu
{
    vector<int>ke;
    int ans;
};
stu student[1001];
void xueke(int classs,int ban,int xuehao)
{
    if(ban==classes[classs].youxianclass)
    {
        if(classes[classs].youxian.size()+classes[classs].putong.size()<classes[classs].lim)
        {

        }
    }
}
void solve()
{
	cin>>n;
    for (int i = 1; i <= n; i++)
    {
        classes[i].bianhao=i;
        cin>>classes[i].youxianclass>>classes[i].lim;
    }
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int caozuo,classs,xuehao;
        cin>>xuehao>>classs>>xuehao;
        int ban=xuehao/40;
        if(caozuo==1)
            xueke(classs,ban,xuehao);
        else
    }
    
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