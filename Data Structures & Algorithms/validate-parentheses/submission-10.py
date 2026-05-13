class Solution:
    def isValid(self, s: str) -> bool:

        # each open - same closed
        # inside most open - closed first 
        # every close bracket has corresponding open of same type -- no standalone closed

        stack = []

        for i in range(len(s)):
            if self.isCB(s[i]) and stack == []:
                return False

            elif self.isOB(s[i]):
                stack.append(s[i])
            
            elif s[i] == ')':
                if stack[-1] == '(':
                    stack.pop();
                else:
                    return False
            
            elif s[i] == ']':
                if stack[-1] == '[':
                    stack.pop();
                else:
                    return False

            elif s[i] == '}':
                if stack[-1] == '{':
                    stack.pop();
                else:
                    return False

        return not stack 
    
    def isOB(self, c: char) -> bool:
        return c == '(' or c == '[' or c == '{'
    
    def isCB(self, c: char) -> bool:
        return c == ')' or c == ']' or c == '}'