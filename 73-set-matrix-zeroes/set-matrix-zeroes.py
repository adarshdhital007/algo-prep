class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        row = len(matrix)
        col = len(matrix[0])

        zeroRows = set()
        zeroCols = set()

        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 0:
                    zeroRows.add(i)
                    zeroCols.add(j)

        for r in zeroRows:
            for j in range(col):
                matrix[r][j] = 0
        
        for c in zeroCols:
            for i in range(row):
                matrix[i][c] = 0