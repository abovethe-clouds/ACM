#include<bits/stdc++.h>
using namespace std;
int n;
void digui(int a)
{
    for(int i=14;i>=0;i--)
    {
        if(pow(2,i)<=a)
        {
            if (i==1) cout<<"2";
            else
            {
                if (i==0)
                    cout<<"2(0)";
                else
                {
                    cout<<"2(";
                    digui(i);
                    cout<<")";
                }
            }
            a-=pow(2,i);
            if(a>0)
                cout<<"+";
        }
        
    }
}
int main()
{
    cin>>n;
    digui(n);
}