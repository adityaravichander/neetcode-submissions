class Solution:
    def isPalindrome(self, s: str) -> bool:

        anstring = "".join(char.lower() for char in s if char.isalnum())
        l = 0
        r = len(anstring) - 1

        while(l < r):
            if anstring[l] == anstring[r]:
                l+=1
                r-=1
            else:
                return False

        return True            



        