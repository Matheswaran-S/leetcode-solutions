class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        jobs.sort(reverse=True)
        workers = [0] * k
        self.ans = sum(jobs)

        def backtrack(index):
            if index == len(jobs):
                self.ans = min(self.ans, max(workers))
                return

            for i in range(k):
                if workers[i] + jobs[index] >= self.ans:
                    continue

                workers[i] += jobs[index]
                backtrack(index + 1)
                workers[i] -= jobs[index]

                if workers[i] == 0:
                    break

        backtrack(0)
        return self.ans