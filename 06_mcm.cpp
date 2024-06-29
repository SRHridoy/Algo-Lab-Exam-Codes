#include"bits/stdc++.h"
using namespace std;

int mcm(int d[], int n){
    int c[n][n];
    int i, j, k, l,cost;

    for(i = 1; i < n; i++) c[i][i] = 0;

    for(l = 2; l < n; l++){
        for(i = 1; i < n-l+1; i++){
            j = i+l-1;
            c[i][j] = INT_MAX;
            for(k = i; k < j; k++){
                cost = c[i][k]+c[k+1][j]+d[i-1]*d[k]*d[j];
                if(cost<c[i][j]){
                    c[i][j] = cost;
                }
            }
        }
    }

    return c[1][n-1];
}

int main(){
    int n;
    cin >> n;
    int d[n];
    for(int i = 0; i<n; i++){
        cin >> d[i];
    }
    
    int cost = mcm(d,n);
    cout << cost << endl;
}
