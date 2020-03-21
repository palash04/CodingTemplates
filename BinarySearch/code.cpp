int binarySearchRecursive(vector<int> &nums, int start, int end, int target){
    if (end >= start){
        int mid = start + (end-start)/2;
        if (nums[mid] == target){
            return mid;
        }else if (target < nums[mid]){
            return binarySearchRecursive(nums, start, mid-1, target);
        }else{
            return binarySearchRecursive(nums, start+1, end, target);
        }
    }
    return -1;
}

int binarySearchIterative(vector<int> &nums,int start,int end,int target){
    while (start <= end){
        int mid = start + (end-start)/2;
        if (nums[mid] == target){
            return mid;
        }else if(target < nums[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}
