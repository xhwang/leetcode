class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        
        """
        d = collections.defaultdict(list)
        
        for i, n in enumerate(nums):
            if len(d[n]) > 0 and i - d[n][-1] <=k:
                return True
            d[n].append(i)
            if i - k >= 0:
                d.pop(nums[i-k])
            
        return False
        """

        # XXX: only retain a set of size k
        s = set()

        for i in range(len(nums)):
            if nums[i] in s:
                return True
            else:
                s.add(nums[j])

            if i - k >= 0:
                s.remove(nums[i-k])

        return False
            
if __name__ == '__main__':
    demo = Solution()
                
