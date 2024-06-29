#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int left = low;
    int right = mid+1;

    int temp[high];
    int i = 0;
    while(left<=mid and right<=high){
        if(arr[left]<=arr[right]){
            temp[i++] = arr[left++];
        }else{
            temp[i++] = arr[right++];
        }
    }

    while(left <= mid){
        temp[i++] = arr[left++];
    }
    while(right<=high){
        temp[i++] = arr[right++];
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}

void merge_sort(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int low = 0, high = n-1;
    merge_sort(arr,low,high);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}