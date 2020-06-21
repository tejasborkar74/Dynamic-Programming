//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.

#include<bits/stdc++.h>
using namespace std;

bool dp[1002][1002];

bool subsetSumPresent(int arr[],int sum,int n )
{
    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=false;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j]= (dp[i-1][j-arr[i-1]]) || (dp[i-1][j]);
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
    int arr[]={2,3,7,8,10};
    int sum=11;
    int n=sizeof(arr)/sizeof(int);

    cout<<subsetSumPresent(arr,sum,n);
}
