
class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        rel = 0

        if len(timeSeries) < 2:
            return len(timeSeries) * duration

        start = timeSeries[0]
        for t in timeSeries[1:]:

            if t >= start + duration:
                rel += duration
            else:
                rel += (t - start)

            start = t
        rel += duration
            
        return rel


if __name__ == '__main__':
    demo = Solution()

    print demo.findPoisonedDuration([1, 4], 2)
    print demo.findPoisonedDuration([1, 2], 2)
