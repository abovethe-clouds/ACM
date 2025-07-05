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
int q=1;
void pri(int x)
{
    switch (x)
    {
    case 1:
        cout<<"yi ";
        break;
    case 2:
        cout<<"er ";
        break;
    case 3:
        cout<<"san ";
        break;
    case 4:
        cout<<"si ";
        break;
    case 5:
        cout<<"wu ";
        break;
    case 6:
        cout<<"liu ";
        break;
    case 7:
        cout<<"qi ";
        break;
    case 8:
        cout<<"ba ";
        break;
    case 9:
        cout<<"jiu ";
        break;
    case 0:
        cout<<"ling ";
        break;
    }
}
void print(int x)
{
    if(x<10)
        pri(x);
    if(x>9&&x<100)
    {
        if(x==10)
        {
        	if(q==0||q==1)
				cout<<"shi ";
			else
			{
                pri(x/10);
                cout<<"shi ";
            }
			
		}
            
        else
        {
            if(x%10==0)
            {
                pri(x/10);
                cout<<"shi ";
            }
            else
            {
                pri(x/10);
                cout<<"shi ";
                pri(x%10);
            }
        }
    }
    if(x>99&&x<1000)
    {
        if(x%100==0)
        {
            pri(x/100);
            cout<<"bai ";
        }
        else
        {
            pri(x/100);
            cout<<"bai ";
            if(x%100<10)
            {
                pri(0);
                pri(x%100);
            }
            else
                print(x%100);
        }
    }
    if(x>1000&&x<10000)
    {
        if(x%1000==0)
        {
            pri(x/1000);
            cout<<"qian ";
        }
        else
        {
            pri(x/1000);
            cout<<"qian ";
            if(x%1000<100)
            {
                pri(0);
                print(x%1000);
            }
            else
                print(x%1000);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    
    bool flag=true,lll=1;
    if(n>=10000)
    {
        if(n==100000000)
        {
        	cout<<"yi yi"<<endl;
            return;
		}
		q=0;
		print(n/10000);
        if(n/10000%10==0)
            lll=0;
        n%=10000;
        cout<<"wan ";
        flag=false;
    }
    if(q==0)
    	q=2;
//    if(q==2&&flag==false)
//    {
//        print(0);
//        print(n);
//        cout<<endl;
//		return;
//	  }
    if(lll==0&&n==0)
    {
        cout<<endl;
		return;
	}
	if(lll==0)
    {
        print(0);
		print(n);
		cout<<endl;
		return;
	}
	if(n<1000&&flag==false)
    {
        print(0);
        print(n);
        cout<<endl;
		return;
	}
	print(n);
    cout<<endl;
	return;
		
    
    

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t --)
        solve();

    return 0;
}