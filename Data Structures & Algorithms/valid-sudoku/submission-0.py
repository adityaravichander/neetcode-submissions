class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        rows = collections.defaultdict(set)
        cols = collections.defaultdict(set)
        squares = collections.defaultdict(set)

        for r in range(9):
            for c in range(9):
                value = board[r][c]
                # check for empty elements and continue 
                if value == ".":
                    continue

                # check if duplicate value in that row / in that column / in that square
                if( value in rows[r] or value in cols[c] or value in squares[(r // 3, c // 3)] ):
                    return False 

                # add into set if new value
                cols[c].add(value)
                rows[r].add(value)
                squares[(r // 3,c // 3)].add(value)

        return True
        
        