#include"bits/stdc++.h"
using namespace std;

int knap_sack(int profit[],int weight[],int n,int maxW){
    int dp[maxW+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int w = maxW; w >= 0; w--){
            if(weight[i-1]<=w){
                dp[w] = max(dp[w],dp[w-weight[i-1]]+profit[i-1]); 
            }
        }
    }
    return dp[maxW];
}

int main(){
   int n;
   cin >> n;
   int profit[n];
   int weight[n];
   for(int i = 0; i < n; i++)cin >> profit[i];
   for(int i = 0; i < n; i++)cin >> weight[i];
   int maxW;
   cin >> maxW;

   int maxProfit = knap_sack(profit,weight,n,maxW);
   cout << maxProfit << endl;
}
