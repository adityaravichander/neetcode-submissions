class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        # cycle detection

        # map of prereq of each course
        preMap = { i: [] for i in range(numCourses)}
        
        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        # visited courses
        visiting = set()

        # for every node from 0 to n-1 --> perform dfs 
        def dfs(crs):
            if crs in visiting:
                return False
            if preMap[crs] == []:
                return True
            
            visiting.add(crs)
            
            for pre in preMap[crs]:
                if not dfs(pre):
                    return False
            
            visiting.remove(crs)
            preMap[crs] = []
            return True

        for c in range(numCourses):
            if not dfs(c):
                return False
        
        return True