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
int sp[100][26];
int iii=0;
bool judge(string s)
{
    int cnt=0;
    int sp1[100][26];
    for(int i=0;i<100;i++)
    	for(int j=0;j<26;j++)
    		sp1[i][j]=sp[i][j];
    for(int i=0;i<iii;i++)
    {
        int l=s.length();
        bool flag=true;
        for (int j = 0; j < l; j++)
        {
            
            if(s[j]>='A'&&s[j]<='Z')
            {
                if(sp1[i][s[j]-'A']<=0)
                {
                    flag=false;
                    break;
                }
                else
                	sp1[i][s[j]-'A']--;	
                    
            }
            if(s[j]>='a'&&s[j]<='z')
            {
                if(sp1[i][s[j]-'a']<=0)
                {
                    flag=false;
                    break;
                }
                else
                	sp1[i][s[j]-'a']--;	
            }
        }
        if(flag==true&&sp1[i][0]==0&&sp1[i][1]==0&&sp1[i][2]==0&&sp1[i][3]==0&&sp1[i][4]==0&&sp1[i][5]==0&&sp1[i][6]==0&&sp1[i][7]==0&&sp1[i][8]==0&&sp1[i][9]==0&&sp1[i][10]==0&&sp1[i][11]==0&&sp1[i][12]==0&&sp1[i][13]==0&&sp1[i][14]==0&&sp1[i][15]==0&&sp1[i][16]==0&&sp1[i][17]==0&&sp1[i][18]==0&&sp1[i][19]==0&&sp1[i][20]==0&&sp1[i][21]==0&&sp1[i][22]==0&&sp1[i][23]==0&&sp1[i][24]==0&&sp1[i][25]==0)
            cnt++;
    }
    if(cnt>=2)
        return true;
    else
        return false;
    
}
void solve()
{
    string s;
    vector<string> v;
    
    while(cin>>s)
    {
        if(s=="#")
            break;
        v.push_back(s);
        int l=s.length();
        for (int i = 0; i < l; i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                sp[iii][(s[i]-'A')]++;
            }
            else
            {
                sp[iii][(s[i]-'a')]++;
            }
        }
        iii++;
    }
    sort(v.begin(),v.end());
    for(auto o:v)
    {
        if(judge(o)==false)
        {
            cout<<o<<endl;
            
        }
        
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
// #include<bits/stdc++.h>
// using namespace std;
// #define fir first
// #define sec second
// #define endl "\n"   
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int> pii;
// typedef pair<ll, ll> pll;
// const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
// set<string> o;
// void solve()
// {
//     string s;
//     vector<string> v;
//     while(cin>>s)
//     {
//         if(s=="#")
//             break;
//         if(!o.count(s))
//         {
//             o.insert(s);
//             v.push_back(s);
//         }
//     }
//     sort(o.begin(),o.end());

// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int t = 1;
//     //cin >> t;
//     while(t --)
//         solve();

//     return 0;
// }