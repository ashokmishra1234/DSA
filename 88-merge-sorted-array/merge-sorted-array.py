class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        total_len=m+n
        ind=total_len-1
        i,j=m-1,n-1
        while i >= 0 and j >= 0:
            if nums1[i] >= nums2[j]:
                nums1[ind]=nums1[i]
                i-=1
            else:
                nums1[ind]=nums2[j]
                j-=1
            ind-=1
        while i >= 0:
            nums1[ind]=nums1[i]
            i-=1
            ind-=1
        while j >= 0:
            nums1[ind]=nums2[j]
            j-=1
            ind-=1
        return

