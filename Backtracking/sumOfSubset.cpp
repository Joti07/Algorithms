#include <bits/stdc++.h>
#define mx 1000
using namespace std;
int arr[mx],x[mx],m;
int cnt=0;
bool ok=false;
void printSet(int k)
{
    cout<<"Solution of Subset "<<++cnt<<endl;
    for(int i=0; i<=k; i++)
    {
        if(x[i]==1)
            cout<<arr[i]<<" ";
    }
    cout<<endl;

}
bool SumOfSub(int s,int k,int r)
{

    x[k]=1;
    if(s+arr[k]==m)
    {
        printSet(k);
        ok=true;
    }
    else if(s+arr[k]+arr[k+1]<=m)
    {
        SumOfSub(s+arr[k],k+1,r-arr[k]);
    }
    if( (s+r-arr[k]>=m) && (s+arr[k+1])<=m)
    {
        x[k]=0;
        SumOfSub(s,k+1,r-arr[k]);
    }
    else
    {
        return ok;
    }

}

int main()
{
    int n,sum=0;
    cout<<"Enter the number of elements in the set"<<endl;
    cin>>n;
    cout<<"Enter the values"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<"Enter the value of required  sum"<<endl;
    cin>>m;

    sort(arr,arr+n);
    bool result=SumOfSub(0,0,sum);

    if(result==false)
        cout<<"no required subset found"<<endl;


}
