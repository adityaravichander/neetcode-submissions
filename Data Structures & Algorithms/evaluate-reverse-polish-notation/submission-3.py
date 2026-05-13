class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

        stack = []

        for t in tokens:
            if t == "+":
                stack.append(stack.pop() + stack.pop())
            elif t == "-":
                top, bottom = stack.pop(), stack.pop()
                stack.append(bottom-top)
            elif t == "*":
                stack.append(stack.pop() * stack.pop())
            elif t == "/":
                top, bottom = stack.pop(), stack.pop()
                stack.append(int(float(bottom)/top))
            else:
                stack.append(int(t))
        
        return stack[0]
        