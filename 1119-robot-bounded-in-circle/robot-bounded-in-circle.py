class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        dirs = [(0,1), (1,0), (0,-1), (-1,0)]
        x = y = 0
        d = 0
        for c in instructions:
            if c == 'G':
                dx, dy = dirs[d]
                x += dx
                y += dy
            elif c == 'L':
                d = (d + 3) % 4
            else:
                d = (d + 1) % 4
        return (x == 0 and y == 0) or d != 0