#include<bits/stdc++.h>                                             
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int a;
stack<int> s;
int main()
{
    while(cin>>a)
    {   
		
        while(a)
        {   
			a--;
        	s.push(a%26);
            a/=26;
        }
        while(!s.empty())
        {
            int q=s.top();
            s.pop();
            cout<<char(q+'A');
        }
        cout<<endl;
    }

    return 0;
}