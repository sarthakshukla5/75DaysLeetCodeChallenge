class Solution:
    def getBiggestThree(self, grid):
        rows = len(grid)
        cols = len(grid[0])
        
        sums = set()
        
        for r in range(rows):
            for c in range(cols):
                
                sums.add(grid[r][c])
                
                size = 1
                while True:
                    
                    if (r - size < 0 or r + size >= rows or
                        c - size < 0 or c + size >= cols):
                        break
                    
                    total = 0
                    
                    i, j = r - size, c
                    while i < r and j < c + size:
                        total += grid[i][j]
                        i += 1
                        j += 1
                    
                    while i < r + size and j > c:
                        total += grid[i][j]
                        i += 1
                        j -= 1
                    
                    while i > r and j > c - size:
                        total += grid[i][j]
                        i -= 1
                        j -= 1
                    
                    while i > r - size and j < c:
                        total += grid[i][j]
                        i -= 1
                        j += 1
                    
                    sums.add(total)
                    
                    size += 1
        
        result = sorted(sums, reverse=True)
        return result[:3]