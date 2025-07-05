#include <bits/stdc++.h>  
using namespace std;
int n;
struct lianbiao
{
    int pre;
    int data;
    int next;
    lianbiao(){}
    lianbiao(int x,int y,int z)
    {
        pre=x;
        data=y;
        next=z;
    }
};
int main() 
{ 
    lianbiao a[100002];
    a[1].pre=0;
    a[1].data=1;
    a[1].next=100001;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int data,judge;
        cin>>data>>judge;
        if(judge==0)//左边
        {
            a[i].data=i;// data区取值是自己
            a[i].pre=a[data].pre; //i的左边是原data的左边 i把左手给原data左边
            a[i].next=data;//右边就是data
            a[a[data].pre].next=a[i].data;//左边的右手给i
            a[data].pre=i;//data的左手给i
        }
        else
        {
            a[i].data=i;// data区取值是自己
            a[i].pre=data;
            a[i].next=a[data].next;
            a[a[data].next].pre=a[i].data;
            a[data].next=i;
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int data;
        cin>>data;
        if(a[data].pre==0&&a[data].next==0)
            continue;
        a[a[data].pre].next=a[data].next;
        a[a[data].next].pre=a[data].pre;
        a[data].pre=0;
        a[data].next=0;
    }
    for (int i=a[0].next; i != 100001;)
    {
        
        cout<<i<<" ";
        i=a[i].next;
    }
}