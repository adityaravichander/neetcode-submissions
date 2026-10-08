class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        
        # STACK 
        # Time = O(n)
        # Space = O(n)

        warm_days = [0] * len(temperatures)
        stack = [] # pair: [temp, index]

        for i,t in enumerate(temperatures):
            while stack and t > stack[-1][0]:
                stackTemp, stackIndex = stack.pop()
                warm_days[stackIndex] = i - stackIndex
            stack.append((t,i))
        return warm_days

        
        # brute force


        # Time = O(n^2)
        # Space = O(n)
                # warm_days = []

                # for i in range(0, len(temperatures)):
                #     count = 1
                #     j = i + 1

                #     while j < len(temperatures):
                #         if temperatures[j] > temperatures[i]:
                #             break
                #         j += 1
                #         count += 1
                #     count = 0 if j == len(temperatures) else count
                #     warm_days.append(count)
                # return warm_days

        