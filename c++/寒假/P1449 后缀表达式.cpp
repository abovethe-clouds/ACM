#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<int> a;
    char it;
    for(int i=0;i<s.length()-1;i++)
    {
        it=s[i];
        if(it>'0'&&it<'9')
        {
            int q=0;
            int j=i;
            while(it!='.')
            {
                q=q*10+(it-'0');
                j++;
                it=s[j];
            }
            i=j;
            a.push(q);
        }
        else
        {
            int p=a.top();
            a.pop();
            int q=a.top();
            a.pop();
            if(it=='+') a.push(p+q);
            else if(it=='-') a.push(q-p);
            else if(it=='*') a.push(q*p);
            else  a.push(q/p);
        }
    }
    cout<<a.top();
}