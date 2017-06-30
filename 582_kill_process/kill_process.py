
class Solution(object):
    def killProcess(self, pid, ppid, kill):
        """
        :type pid: List[int]
        :type ppid: List[int]
        :type kill: int
        :rtype: List[int]
        """
        remain = [kill]

        import collections
        counter = collections.defaultdict(list)

        for p, c in zip(ppid, pid):
            counter[p].append(c)

        for k in remain:
            remain.extend(counter.get(k, []))

        return remain


if __name__ == '__main__':
    demo = Solution()

    pid = [1, 3, 10, 5]
    ppid = [3, 0, 5, 3]

    kill = 3

    print demo.killProcess(pid, ppid, kill)
