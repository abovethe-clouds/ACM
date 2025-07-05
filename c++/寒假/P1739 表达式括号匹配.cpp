#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int zuo=0;int you=0;
    bool flag=true;
    for(int i=0;i<s.length()-1;i++)
    {
        if (s[i]=='(')
        {
            zuo++;
            if(zuo<you)
            {
                cout<<"NO";
                return 0;
            }
        }
        if (s[i]==')')
        {
            you++;
            if(zuo<you)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    if(zuo!=you)
    {
        cout<<"NO";return 0;
    }
    cout<<"YES";
    return 0;
}