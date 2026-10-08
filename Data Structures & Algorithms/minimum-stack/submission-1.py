class MinStack:

       # ONE STACK 
       # Time O(1) , Space O(n)

        def __init__(self):
            self.min = float('inf')
            self.stack = []
        
        def push(self, val:int) -> None:
            if not self.stack:
                self.stack.append(0)
                self.min = val
            else:
                self.stack.append(val-self.min)
                if val < self.min:
                    self.min = val

        def pop(self):
            if not self.stack:
                return

            pop = self.stack.pop()
            if pop < 0:
                self.min = self.min - pop

        def top(self) -> int:
            top = self.stack[-1]
            if top > 0:
                return top + self.min
            else:
                return self.min
        
        def getMin(self) -> int:
            return self.min
       
        # TWO STACKS - pop all elements
        # Time O(1) , Space O(n)

            # def __init__(self):
            #     self.stack = []
            #     self.minStack = []
            
            # def push(self, val:int) -> None:
            #     self.stack.append(val)
            #     val = min(val, self.minStack[-1] if self.minStack else val)
            #     self.minStack.append(val)

            # def pop(self) -> None:
            #     self.stack.pop() 
            #     self.minStack.pop()
            
            # def top(self) -> int: 
            #     return self.stack[-1]

            # def getMin(self) -> int:
            #     return self.minStack[-1]

        # BRUTE FORCE - pop all elements
        # Time O(n) , Space O(n)

            # def __init__(self):
            #     self.stack = []

            # def push(self, val: int) -> None:
            #     self.stack.append(val)

            # def pop(self) -> None:
            #     self.stack.pop()

            # def top(self) -> int:
            #     return self.stack[-1]

            # def getMin(self) -> int:

            #     temp = []
            #     mini = self.stack[-1]
                
            #     while len(self.stack):
            #         mini = min(mini, self.stack[-1])
            #         temp.append(self.stack.pop())

            #     while len(temp):
            #         self.stack.append(temp.pop())

            #     return mini

