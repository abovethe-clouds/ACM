#include <bits/stdc++.h>
using namespace std;

long long a[1001] = {0};

int main(){
    int n;
    cin>>n;
    a[1] = 1;
    for(int i=2; i<=n; i++){
        a[i] = a[i-1];
        if(i%2 == 0)
            a[i] += a[i/2];
    }
    cout<<a[n];
    return 0;
}