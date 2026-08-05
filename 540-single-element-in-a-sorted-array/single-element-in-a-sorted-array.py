class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return nums[0]
        if nums[0] != nums[1]:
            return nums[0]
        if nums[n-1] != nums[n-2]:
            return nums[n-1]
        l,r=0,n-1
        while l <= r:
            mid=l+(r-l)//2
            if nums[mid] > nums[mid-1] and nums[mid] < nums[mid+1]:
                return nums[mid]
            if nums[mid]==nums[mid-1]:
                l_ele=mid+1
                r_ele=n-l_ele
                if l_ele%2:
                    r=mid-1
                else:
                    l=mid+1
            else:
                r_ele=n-mid
                l_ele=n-r_ele
                if r_ele % 2:
                    l=mid+1
                else:
                    r=mid-1
        return -1
