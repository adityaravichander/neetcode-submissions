class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        # start time - 9:50 pm
        # end time - 10:05 pm (used solution)
        
        # hashmap - update count of each character in string
        '''
         eg: [act] - a1 c1 t1
             [pots] p1 o1 t1 s1
             [tops] t1 o1 p1 s1
             [cat] - c1 a1 t1
             [stop] - s1 t1 o1 p1
             [hat] - h1 a1 t1

        '''
        map = defaultdict(list)
        # map count : strings of that count

        for s in strs:
            count = [0] * 26

            for c in s:
                count[ord(c) - ord('a')] += 1
            map[tuple(count)].append(s)

        return list(map.values())