class Solution {
public:
int solve(vector<vector<int>>& v,int index,int k,vector<vector<int>>& dp){
        if(k==0 || index==v.size())return 0;
        
        if(dp[index][k]!=0)return dp[index][k];
        
        int ans=solve(v,index+1,k,dp);
        int sum=0;
        
        for(int i=0;i<v[index].size() && i<k;i++){
            sum=sum+v[index][i];
            ans=max(ans,sum+solve(v,index+1,k-i-1,dp));
        }
        return dp[index][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(),vector<int>(k+1,0));
        return solve(piles,0,k,dp);
    }
};