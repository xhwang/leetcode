
class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        rel = duration * len(timeSeries)
        for i in range(1, len(timeSeries)):
            rel -= max(0, duration - (timeSeries[i] - timeSeries[i-1]))
            
        return rel


if __name__ == '__main__':
    demo = Solution()

    print demo.findPoisonedDuration([1, 4], 2)
    print demo.findPoisonedDuration([1, 2], 2)
