class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # XXX: What we need is a mark array,
        # since 1<=a[i]<=n (n size of array)
        # so we can treat the value as idx,
        # using the sign of the num at idx pos as marker

        rel = []
        for n in nums:
            idx = abs(n) - 1
            if nums[idx] < 0:
                rel.append(abs(n))
            nums[idx] = -nums[idx]

        return rel

if __name__ == '__main__':
    demo = Solution()

    nums = [4, 3, 2, 7, 8, 2, 3, 1]
    print demo.findDuplicates(nums)
        
