class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """

        return self.recursive(s, 0, len(s)-1)

    def recursive(self, s, i, j):

        rel = ""
        while i <= j:

            if (s[i] >= 'a' and s[i] <= 'z'):
                rel += s[i]

            if (s[i] >= '1' and s[i] <= '9'):

                num = s[i]
                i += 1
                while (s[i] >= '1' and s[i] <= '9'):
                    num += s[i]
                    i += 1

                t = i+1
                bracket = 1
                while True:
                    t += 1
                    if (s[t] == ']'):
                        bracket -= 1
                        if bracket == 0:
                            break

                    if (s[t] == '['):
                        bracket += 1

                rel += int(num) * self.recursive(s, i+1, t-1)
                i = t

            i += 1

        return rel


if __name__ == '__main__':
    demo = Solution()

    print demo.decodeString("3[a]2[bc]")
    print demo.decodeString("3[a2[c]]")
    print demo.decodeString("2[abc]3[cd]ef")
