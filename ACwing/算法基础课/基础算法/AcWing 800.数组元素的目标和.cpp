#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<m;j++)
    {
        cin>>b[j];
    }
    int j=m-1;
    for(int i=0;i<n;i++)
    {
        while(j>=0&&a[i]+b[j]>k)
        {
            j--;
        }
        if(a[i]+b[j]==k)
        {
            cout<<i<<" "<<j<<endl;
            break;
        }
    }
    return 0;
}