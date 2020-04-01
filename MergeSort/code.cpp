#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums,int start,int mid,int end){
    int n1 = mid-start+1;
    int n2 = end-mid;
    
    int L[n1];
    int R[n2];
    
    for (int i=0;i<n1;i++){
        L[i] = nums[start+i];
    }
    for (int i=0;i<n2;i++){
        R[i] = nums[mid+1+i];
    }
    
    int i=0,j=0,k=start;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            nums[k] = L[i];
            i++;
            k++;
        }else{
            nums[k] = R[j];
            j++;
            k++;
        }
    }
    while (i < n1){
        nums[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        nums[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &nums,int start,int end){
    if (start < end){
        int mid = start + (end-start)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums,start,mid,end);
    }
}

int main(){
    
    vector<int> nums = {9,8,7,6,5,4,3,2,1,0};
    int n = (int)nums.size();
    
    mergeSort(nums,0,n-1);
    
    for (int i=0;i<n;i++){
        cout << nums[i] <<  " ";
    }
    cout << "\n";
    return 0;
}
