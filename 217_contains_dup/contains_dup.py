
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        # retrun len(set(nums)) != len(nums):
        # XXX: build the set from 0 to n, is more efficient
        s = set()

        for n in nums:
            if n is in s:
                return True
            else
                s.add(n)
        return False

if __name__ == '__main__':
    demo = Solution()
