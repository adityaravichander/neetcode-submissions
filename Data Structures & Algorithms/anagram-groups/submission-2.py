class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        res = defaultdict(list)

        for s in strs:
            sortedS = ' '.join(sorted(s)) 
            #sorted(s) returns list of characters
            res[sortedS].append(s)
        return list(res.values())
        