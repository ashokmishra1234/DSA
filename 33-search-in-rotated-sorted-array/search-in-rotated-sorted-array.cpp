class Solution {
public:
    int binarySearch(int l, int r,int target, vector<int> &nums){
        while(l <= r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid] > target){
                r=mid-1;
            }else l=mid+1;
        }
        return -1;
    }
    int findPivot(vector<int> &nums){
        int l=0,r=nums.size()-1;
        while(l < r){
            int mid=l+(r-l)/2;
            if(nums[mid] > nums[r]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return r;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        int pivot=findPivot(nums);
        cout<<pivot<<endl;
        int ans=-1;
        ans=binarySearch(0,pivot-1,target,nums);
        if(ans!=-1) return ans;
        ans=binarySearch(pivot,h,target,nums);
        return ans;
    }
};