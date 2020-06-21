#include<bits/stdc++.h>
using namespace std;
int dp[1003][1003];

int countSubsetSum(int *arr,int n,int sum)
{
    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=0;
    }

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];

}
int main()
{
    int arr[]={2,3,5,6,8};
    int n=sizeof(arr)/sizeof(int);
    memset(dp,-1,sizeof(dp));

    int sum=9;

    cout<<countSubsetSum(arr,n,sum);
}
