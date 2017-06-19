#include <iostream>
using namespace std;
int a[10];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    int min=a[0],max=a[1];
    for(i=0;i<n;i++)
    {
        if(a[i]<min) min=a[i];
        if(a[i]>max) max=a[i];
    }
    cout<<min<<" "<<max;
    return 0;
}
