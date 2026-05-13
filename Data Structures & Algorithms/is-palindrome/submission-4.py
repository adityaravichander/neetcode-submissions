class Solution:
    def isPalindrome(self, s: str) -> bool:

        anstringu = "".join(char for char in s if char.isalnum())

        anstring = anstringu.lower()
        print(anstring)
        l = 0
        r = len(anstring) - 1

        while(l < len(anstring)):
            print(anstring[l])
            print(r)
            print(len(anstring))
            print(anstring[r])
            if anstring[l] == anstring[r]:
                l+=1
                r-=1
            else:
                return False

        return True            



        