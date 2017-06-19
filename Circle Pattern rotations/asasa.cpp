#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll binary(ll a[],ll m,ll end)
{
    int start=0;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(a[mid]==m)
        {
            return mid+1;
        }
        else if(a[mid]>m)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return start;
}
int main()
{
    ll i=0,n,a[100000],q,m;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cin>>q;
    while(q--)
    {
        cin>>m;
        cout<<binary(a,m,n-1)<<"\n";
    }
    return 0;
}
