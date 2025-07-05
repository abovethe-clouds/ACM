#include <bits/stdc++.h>  
using namespace std; 
struct lianbiao
{
    int pre;
    int data;
    int next;
};
lianbiao a[1000002];
void charu(int data,int i)
{
    a[i].data=i;// data区取值是自己
    a[i].pre=data;
    a[i].next=a[data].next;
    a[a[data].next].pre=a[i].data;
    a[data].next=i;
    return;
}
void del(int data)
{
    a[a[data].pre].next=a[data].next;
    a[a[data].next].pre=a[data].pre;
    a[data].pre=0;
    a[data].next=0;
    return;
}
void print(int x)
{
    if(a[x].next==1000001)
    cout<<0<<endl;
    else
    cout<<a[x].next<<endl;
    return ;
}
int main()
{
    int t;
    
    a[0].next=1;
    a[1].pre=0;
    a[1].data=1;
    a[1].next=1000001;
    a[1000001].pre=1;
    cin>>t;
    while (t--)
    {
        int judge;
        cin>>judge;
        if(judge==1)
        {
            int x,y;
            cin>>x>>y;
            charu(x,y);
        }
        if (judge==3)
        {
            int x;
            cin>>x;
            del(a[x].next);
        }
        if(judge==2)
        {
            int x;
            cin>>x;
            print(x);
        }
    }
    
}