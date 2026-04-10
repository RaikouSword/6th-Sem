W, H = 80, 30
grid = [[' ']*W for _ in range(H)]

def put(x, y, c):
    if 0 <= x < W and 0 <= y < H:
        grid[y][x] = c

# Bresenham line (DSA-ish)
def line(x1, y1, x2, y2, c):
    dx = abs(x2-x1)
    dy = abs(y2-y1)
    sx = 1 if x1 < x2 else -1
    sy = 1 if y1 < y2 else -1
    err = dx - dy

    while True:
        put(x1, y1, c)
        if x1 == x2 and y1 == y2:
            break
        e2 = 2*err
        if e2 > -dy:
            err -= dy
            x1 += sx
        if e2 < dx:
            err += dx
            y1 += sy

# build structure using geometry
line(5,5,15,5,'-')
line(15,5,20,10,'/')
line(20,10,10,15,'\\')

for row in grid:
    print("".join(row))