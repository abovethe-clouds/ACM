#include<bits/stdc++.h>
using namespace std;
struct student
{
    int year;
    int month;
    int day;
    int x;
    string name;
    student(){}
    student(string a,int b,int c,int d,int e)
    {
        name=a;
        year=b;
        month=c;
        day=d;
        x=e;
    }
};
bool paixu(student x,student y)
{
    if(x.year!=y.year)
        return x.year<y.year;
    else
    {
        if(x.month!=y.month)
            return x.month<y.month;
        else
        {
            if(x.day!=y.day)
                return x.day<y.day;
            else
                return x.x>y.x;
        }
    }
} 
int main()
{
    student qqq[101];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int a,b,c;
        cin>>s>>a>>b>>c;
        qqq[i].name=s;
        qqq[i].year=a;
        qqq[i].month=b;
        qqq[i].day=c;
        qqq[i].x=i;
    }
    sort(qqq,qqq+n,paixu);
    for(int i=0;i<n;i++)
    {
        cout<<qqq[i].name<<endl;
    }
    return 0;
}