class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        res = defaultdict(list)

        # solution 1 - sorted() function

        # for s in strs:
        #     sortedS = ' '.join(sorted(s)) 
        #     #sorted(s) returns list of characters
        #     res[sortedS].append(s)
        # return list(res.values())
        
        # solution 2 - hash table

        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            res[tuple(count)].append(s)
        
        return list(res.values())