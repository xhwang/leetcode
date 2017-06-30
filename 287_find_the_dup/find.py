
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # TODO: not fully understand yet

        slow = nums[0]
        fast = nums[slow]

        while (slow != fast):
            slow = nums[slow]
            fast = nums[nums[fast]]
            
        slow = 0
        while (slow != fast):
            slow = nums[slow]
            fast = nums[fast]

        return slow


if __name__ == '__main__':
    demo = Solution()

    nums = [1, 3, 3, 4, 2]

    print demo.findDuplicate(nums)

