#include<iostream>
using namespace std;
int lowbit(int x)
{
    return x & -x;
}
int main()
{
	int n;
    cin>>n;
    cout<<lowbit(n);
} 
