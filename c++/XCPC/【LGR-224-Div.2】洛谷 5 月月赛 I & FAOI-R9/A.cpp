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
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;//G代入a  B回三分线a  A认真 b  W随意 c 
    string s;
    cin>>s;
    int cnt=0,随便投=0,认真投=0,sum=0;
    bool 状态=1;//1三分线 0场内
    for (auto i : s)
    {
        if(i=='G')
        {
            状态=0;
            sum+=a;
        }    
        else if(i=='B')
        {
            状态=1;
            sum+=a;
        }
        else if(i=='A')
        {
            sum+=b;
            认真投++;
        }
        else if(i=='W')
        {
            sum+=c;
            随便投++;
        }
        if((认真投==1||随便投==3)&&状态==1)
        {
            cnt++;
            随便投=0,认真投=0;
        }
    }
    while (cnt<4)
    {
        if((认真投==1||随便投==3)&&状态==0)//投了，没运出来
        {
            状态=1;
            sum+=a;
        }
        else if(状态==1)//场外
        {
            状态=0;
            sum+=a;
        }
        else //投一半
        {
            if(认真投==0&&随便投==0)
            {
                if(3*c<b)
                    sum+=3*c;
                else
                    sum+=b;
            }
            else if(随便投==1)
            {
                if(2*c<b)
                    sum+=2*c;
                else
                    sum+=b;
            }
            else
            {
                if(c<b)
                    sum+=c;
                else
                    sum+=b;
            }

        }
        if((认真投==1||随便投==3)&&状态==1)
        {
            cnt++;
            随便投=0,认真投=0;
        }
    }
    cout<<sum;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}