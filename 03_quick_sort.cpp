#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i]<=pivot and i < high)i++;
        while(arr[j]>pivot and j > low)j--;

        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}

void quick_sort(int arr[], int low, int high){
    if(low<high){
        int pIndex = partition(arr,low,high);
        quick_sort(arr,low,pIndex-1);
        quick_sort(arr,pIndex+1,high);
    }
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int low = 0, high = n - 1;
    quick_sort(arr, low, high);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}