#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

//memoise

int LCS(string a,string b,int n,int m)
{
    if(n==0||m==0)return 0;

    if(dp[n][m]!=-1)return dp[n][m];

    if(a[n-1]==b[m-1])
    {
        return dp[n][m] = 1 + LCS(a,b,n-1,m-1);
    }
    else
    {
        return dp[n][m] = max(LCS(a,b,n-1,m) , LCS(a,b,n,m-1));
    }
}

//DP sol
int LCSdp(string a,string b,int n,int m)
{
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }

    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    string a="abcdgh";
    string b="abedfh";

    //cout<<LCS(a,b,a.length(),b.length());
    cout<<LCSdp(a,b,a.length(),b.length());
}
