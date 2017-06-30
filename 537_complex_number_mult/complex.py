
class Solution(object):
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        ar, ai = self.get_real(a)
        br, bi = self.get_real(b)

        r = ar * br - ai * bi
        i = ar * bi + ai * br

        return '{}+{}i'.format(r, i)

    def get_real(self, c):
        r, i = c.split('+')
        r = int(r)
        i = int(i[:-1])
        return r, i


if __name__ == '__main__':

    demo = Solution()

    a = '1+1i'
    b = '1+1i'
    print demo.complexNumberMultiply(a, b)

    a = '1+-1i'
    b = '1+-1i'
    print demo.complexNumberMultiply(a, b)
