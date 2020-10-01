#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       long long  int n;
        cin>>n;
        long long int a[n];
        for (long long int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        for (long long int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}