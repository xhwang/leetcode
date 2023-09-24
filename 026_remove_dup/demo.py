
class Solution(object):

    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if not nums:
            return 0
        
        pos = 0
        for i, n in enumerate(nums[1:]):
            if n == nums[pos]:
                continue
            pos += 1
            nums[pos] = n

        return pos + 1


if __name__ == '__main__':
    demo = Solution()

    nums = [1, 2, 2, 3]

    print demo.removeDuplicates(nums)
    print nums
