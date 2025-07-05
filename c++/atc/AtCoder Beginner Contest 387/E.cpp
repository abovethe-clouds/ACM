#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
 
bool judge(ull x)
{
    ull d=x;
	ull a=0;
    while(x!=0)
    {
        a+=(x%10);
        x/=10;
    }
    ull c=d%a;
    if(c==0)
    {
        return true;
    }
        
    else 
        return false;

}
int main()
{
    ull n;
    cin>>n;
    for(ull i=n;i<=2*n-1;i++)
    {
        if(judge(i)&&judge((ull)(i+1)))
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}