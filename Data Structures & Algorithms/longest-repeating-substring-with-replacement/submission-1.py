class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        res = 0

        maxf = 0
        
        l = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)

            # OPTIMAL SOLUTION - MAXFREQ
                #maxf = currentmax OR FREQ_JUSTADDED_CHAR
            maxf = max(maxf, count[s[r]])  #constant time operation. 

            while (r - l + 1) - maxf > k:

            # BRUTE FORCE

            # check current window is valid
                # while window not valid 
                    #length_window - count of most freq character
            
            # while (r - l + 1) - max(count.values()) > k:
                
                # decrement count of left pointer
                count[s[l]] -= 1

                # increment left pointer
                l += 1

            # result = max of result or size of current window
            res = max(res, r - l + 1)

        return res