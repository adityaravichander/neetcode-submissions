class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        result = []
        folder_set = set(folder)

        for f in folder:
            result.append(f)
            for index in range(len(f)):
                if f[index] == "/" and f[:index] in folder_set:
                    result.pop()
                    break
        return result
        