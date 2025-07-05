#include <bits/stdc++.h>  
using namespace std;
queue<int>q;
void push()
{
    int x;
    cin>>x;
    q.push(x);
    return;
} 
void pop()
{
    if(q.empty())
    {
        cout<<"ERR_CANNOT_POP"<<endl;
        return;
    }
    q.pop();
    return;
} 
void top()
{
    if(q.empty())
    {
        cout<<"ERR_CANNOT_QUERY"<<endl;
        return;
    }
    cout<<q.front()<<endl;
    return;
} 

int main()
{
    
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        switch (x)
        {
            case 1: push();break;
            case 2: pop();break;
            case 3:top();break;
            case 4:cout<<q.size()<<endl;break;
        }
    }
}