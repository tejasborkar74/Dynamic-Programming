//Given weights and values of n items,
//put these items in a knapsack of capacity W
//to get the maximum total value in the knapsack.
//In other words, given two integer arrays val[0..n-1] and wt[0..n-1]
//which represent values and weights associated with n items respectively


//Recursive

#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int w,int n)
{
    if(n==0||w==0)return 0;

    if(wt[n-1]<=w)
    {
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else
    {
        return knapsack(wt,val,w,n-1);
    }
}
int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int W=7;

    int n=sizeof(wt)/sizeof(int);

    cout<<knapsack(wt,val,W,n);
}

//Memoization

#include<bits/stdc++.h>
using namespace std;
int dp[103][1003];

int knapsack(int wt[],int val[],int w,int n)
{
    if(n==0||w==0)return 0;

    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }

    if(wt[n-1]<=w)
    {
        return dp[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else
    {
        return dp[n][w]= knapsack(wt,val,w,n-1);
    }
}
int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int W=7;

    memset(dp,-1,sizeof(dp));

    int n=sizeof(wt)/sizeof(int);

    cout<<knapsack(wt,val,W,n);
}


//Bottom Up

#include<bits/stdc++.h>
using namespace std;
int dp[103][1003];
int knapsack(int wt[],int val[],int w,int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);

            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }


   return dp[n][w];
}
int main()
{
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int W=50;
    memset(dp,-1,sizeof(dp));

    int n=sizeof(wt)/sizeof(int);

    cout<<knapsack(wt,val,W,n);
}
