//Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.

#include<bits/stdc++.h>
using namespace std;
bool dp[1002][1002];

bool subsetSum(int arr[],int n,int sum)
{
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=false;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j]=(dp[i-1][j-arr[i-1]]) || (dp[i-1][j]);
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
    int arr[]={1,5,12,5};
    int n=sizeof(arr)/sizeof(int);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    if(sum%2==1)
    {
        cout<<"partition not possible";
        return 0;
    }
    else
    {
        int Partition=sum/2;

        if(subsetSum(arr,n,Partition))
        {
            cout<<"true";
        }
        else
        {
            cout<<"false";
        }

    }

    return 0;
}
