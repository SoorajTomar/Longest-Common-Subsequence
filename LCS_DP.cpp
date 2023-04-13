#include <iostream>
using namespace std;
int f(string a,string b){
    int x=a.length(),y=b.length();
    int dp[x+1][y+1];
    for(int i=0;i<x+1;i++)
    dp[i][0]=0;
    for(int i=0;i<y+1;i++)
    dp[0][i]=0;
    for(int i=1;i<x+1;i++)
    for(int j=1;j<y+1;j++)
    if(a[i-1]==b[j-1])
    dp[i][j]=1+dp[i-1][j-1];
    else
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    int ans=dp[x][y];
    char lcs[ans];
    for(int i=0;i<x+1;i++){
        for(int j=0;j<y+1;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    int i=x,j=y;
    while(i>0 and j>0){
        if(a[i-1]==b[j-1])
        {lcs[ans-1]=a[i-1];
        i--;
        j--;
        ans--;}
        else if(dp[i-1][j]>dp[i][j-1])
        i--;
        else
        j--;
    }
    cout<<"LCS is: ";
    for(int i=0;i<dp[x][y];i++)
    cout<<lcs[i];
    cout<<endl<<"Length of LCS: ";
    return dp[x][y];
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<f(a,b);
    return 0;
}
