#include<bits/stdc++.h>
using namespace std;

vector<bool>  mss(int *arr,int n,int range)
{
    bool dp[n+1][range+1];

    for(int i=0;i<=range;i++)
    {
        dp[0][i]=false;
    }

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=range;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }

        }
    }

    vector<bool> ans;

    for(int i=0;i<=range;i++)
    {
        ans.push_back(dp[n][i]);
    }

    return ans;

}

int mssd(int *arr,int n,int range)
{
   vector<bool> temp = mss(arr,n,range);

   int mn=INT_MAX;

   for(int i=0;i<temp.size();i++)
   {
       if(temp[i])
        mn=min(mn,abs(range-(2*i)));
   }

   return mn;
}
int main()
{
    int arr[]={1,6,11};
    int n=sizeof(arr)/sizeof(int);
    int range=0;

    for(int i=0;i<n;i++)
    {
        range+=arr[i];
    }

    cout<< mssd(arr,n,range);
}
