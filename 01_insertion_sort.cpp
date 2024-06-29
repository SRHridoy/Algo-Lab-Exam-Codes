#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n){
    //3 4 1 2
    for(int i = 1; i < n; i++){
        int value = arr[i];
        int hole = i;
        while(hole>0 and arr[hole-1]>value){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = value;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    insertion_sort(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}