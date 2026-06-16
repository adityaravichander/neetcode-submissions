class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        # june 15 2026
        # start time - 9.15 pm 
        # end time - 9:25 pm 
        
        # determine if anagrams of each other
        # anagram = exact number of characters, order can be different

        # hashmap - store count of each character
        # if hashmap1 == hashmap 2 , then mass

        if len(s) != len(t):
            print("test")
            return False
        
        s_map = {}
        t_map = {}

        for c1, i1 in enumerate(s):
            print(i1)
            if i1 in s_map:
                s_map[i1] = s_map[i1] + 1
            else:
                s_map[i1] = 1
        
        for c2, i2 in enumerate(t):
            print(i2)
            if i2 in t_map:
                t_map[i2] = t_map[i2] + 1
            else:
                t_map[i2] = 1
        
        return s_map == t_map

        