class Solution:
    def generate(self, n: int) -> List[List[int]]:
        def fact(n):
            f = 1
            for i in range(1, n+1):
                f *= i
            return f
        l = []
        for i in range(0,n):
            temp = []
            for j in range(0,i+1):
                temp.append(fact(i) // ((fact(i - j)) * fact(j)))
            l.append(temp)
        return l
