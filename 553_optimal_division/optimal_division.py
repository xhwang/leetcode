class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if len(nums) == 1:
            return str(nums[0])

        if len(nums) == 2:
            return "{}/{}".format(nums[0], nums[1])

        rel = "{}/({}".format(nums[0], nums[1])
        for i in range(2, len(nums)):
            rel += "/{}".format(nums[i])
        rel += ")"

        return rel


if __name__ == '__main__':

    demo = Solution()

    import random
    for s in range(20):

        n = random.randint(1, 10)

        nums = []
        for i in range(n):
            nums.append(random.randint(2, 1000))

        print(nums)
        print(demo.optimalDivision(nums))
