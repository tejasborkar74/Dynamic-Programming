#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int LCSString(string a,string b,int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    string a="abe";
    string b="wnm";

    cout<<LCSString(a,b,a.length(),b.length());
}
