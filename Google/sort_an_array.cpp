class Solution {
public:
void merge(vector<int>&nums, int l, int mid, int r){
    int n1 = mid -l+1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i] = nums[l+i];
    }
    for(int j = 0;j<n2;j++){
        b[j] = nums[mid+1+j];
    }
  
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            nums[k] = a[i];
            i++;
            k++;
        }
        else{
            nums[k] = b[j];
            j++;
            k++;
        }
    }
    
    while(i<n1){
        nums[k] = a[i];
        i++;
        k++;
    }
    while(j<n2){
        nums[k] = b[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>&nums,int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums, mid+1, r);
        
        merge(nums , l, mid, r);
    }
}
vector<int> sortArray(vector<int>& nums) {
   int l = 0;
   int r = nums.size() - 1;
    mergeSort( nums, l, r);
    return nums;
}
};
