#include<bits/stdc++.h>
using namespace std;

void solve(int i,int mini,int maxi,vector<vector<vector<int>>> & dp, vector<int>& points,int thr){
    dp[i][maxi][mini]=0;
    if (points[maxi]-points[mini]>=thr){
        return;
    }
    int new_maxi=maxi,new_mini=mini;
    if (points[i]>points[maxi]){
        new_maxi=i;
    }
    if (points[i]<points[mini]){
        new_mini=i;
    }

    if (i+1 <points.size()){
        if (dp[i+1][new_maxi][new_mini]==-1) solve(i+1,new_mini,new_maxi,dp,points,thr);
        dp[i][maxi][mini]=dp[i+1][new_maxi][new_mini];
        if (i+2<points.size()){
            if (dp[i+2][new_maxi][new_mini]==-1) solve(i+2,new_mini,new_maxi,dp,points,thr);
            dp[i][maxi][mini]=min(dp[i][maxi][mini],dp[i+2][new_maxi][new_mini]);
        }
    }
    dp[i][maxi][mini]+=1;
}

int main(){
    int n=points.size();
    if (n<=1) return n;
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
    solve(1,points[0],points[0],dp,points,threshold);
    int ans=dp[1][points[0]][points[0]];
    if (n>2) {
        solve(2,points[0],points[0],dp,points,threshold);
        ans=min(ans,dp[2][points[0]][points[0]]);
    }
    cout<<ans<<endl;
    return ans;
}