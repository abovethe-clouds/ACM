#include "cmath"
#include"iostream"
using namespace std;
int sand_clock_level,n;
char symbol;
void sand_clock(int n,int level)
{
    if (n<((level*2)+1)*2) 
    {
        sand_clock_level=level;
        return;
    }
    else return sand_clock((n-((level*2)+1)*2),level+1);
}
int main(){
    int ans=0;
    cin>>n>>symbol;
    sand_clock(n-1,1);
    for(int i=0;i<sand_clock_level;i++)
    {
        for(int j=0;j<i;j++)
        cout<<" ";
        for(int j=0;j<2*(sand_clock_level-i)-1;j++)
            {cout<<symbol;ans++;}
        cout<<endl;
    } 
    for(int i=sand_clock_level-2;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        cout<<" ";
        for(int j=0;j<2*(sand_clock_level-i)-1;j++)
            {cout<<symbol;ans++;}
        cout<<endl;
    }     
    cout<<n-ans;
    return 0;
}