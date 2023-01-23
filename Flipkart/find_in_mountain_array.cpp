class Solution {
public:
    int findpeak(MountainArray &arr)
    {  
        int start=0;
        int n=arr.length();
        int end=n-1;
        while(start<end)
        {    int mid=start +(end-start)/2;
             int low,high;
             int mid_ele=arr.get(mid);
             if(mid>0 && mid<n-1){
                 low=arr.get(mid-1); 
                 high=arr.get(mid+1);
                 if(low< mid_ele && mid_ele>high )  
                    return mid;
                 else if(low<mid_ele)
                   start=mid;
                 else 
                  end=mid;
              }
         else if(mid==0 && mid_ele>arr.get(mid+1)) 
         return mid; 
         else if(mid_ele>arr.get(mid-1)) 
         return mid;  
        }
        return -1;
    }
              
    int leftbsearch(MountainArray &arr,int s,int e,int target) 
    {
         while(s<=e)
          {  int mid=s +(e-s)/2;
             int midd=arr.get(mid);
             if(midd==target)
                 return mid;
             else if(midd>target)
                  e=mid-1;
             else 
                  s=mid+1;
            }
        return -1;
        
    }
    int rightbsearch(MountainArray &arr,int s,int e,int target) 
    {
         while(s<=e)
           {  int mid=s +(e-s)/2;
              int midd=arr.get(mid);
              if(midd==target)
                return mid;
              else if(midd>target)
                 s=mid+1;
              else 
                e=mid-1;
              }
        return -1;
     }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakindex=findpeak(mountainArr);      
        int n=mountainArr.length();
        int low=leftbsearch(mountainArr,0,peakindex,target);     
        int high=rightbsearch(mountainArr,peakindex+1,n-1,target);  
        if(low==-1)                     
            return high;                
        return low;
    }
};
