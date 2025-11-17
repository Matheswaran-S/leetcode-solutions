class Solution:
    def isHappy(self, n: int) -> bool:
        has = set()
        has.add(n)
        while n != 1:
            m = n
            n = 0
            while m > 0:
                n += (m%10)**2
                m = m//10
            if n == 1:
                return True
            if n in has:
                return False
            has.add(n) 
        return True;