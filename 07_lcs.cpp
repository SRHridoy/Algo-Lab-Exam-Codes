#include"bits/stdc++.h"
using namespace std;

int lcs(string s1, string s2, int m, int n){
    int dp[m+1][n+1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i==0 or j==0){
                dp[i][j] = 0;
            }else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();

    int len = lcs(s1,s2,m,n);
    cout << len << endl;
    
}
