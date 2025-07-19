def compute_result(grid):
    values=[]
    m,n=len(grid),len(grid[0])

    directions = [(0,1),(1,0),(-1,0),(0,-1)]

    visited = [[False for _ in range(n)] for _ in range(m)] 


    def compute_path_value(y,x):
        if (grid[y][x] == '9'):
            return 1
        visited[y][x] = True
        res=0
        for dy,dx in directions:
            if dy+y < 0 or dx + x < 0 or dy + y >= m or dx + x >= n:
                continue
            if not visited[dy+y][dx+x] and ord(grid[dy+y][dx+x]) == ord(grid[y][x]) + 1:
                res += compute_path_value(dy+y,dx+x)
        visited[y][x] = False
        return res



    for y in range(m):
        for x in range(n):
            if grid[y][x] == '0':
                values.append(compute_path_value(y,x))

    return sum(values)


def getMap():
    m = []
    while True:
        try:
            line=input()
            m.append(line)
        except:
            break
    return m 

m=getMap()
print(compute_result(m))