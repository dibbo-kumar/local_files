import heapq
import math


# Heuristic Function
def heuristic(node, goal, mode):
    x, y = node
    gx, gy = goal

    if mode == "manhattan":
        return abs(gx - x) + abs(gy - y)
    else:  # euclidean
        return math.sqrt((gx - x) ** 2 + (gy - y) ** 2)


# A* Algorithm
def run_astar(grid, start, goal, mode):
    rows, cols = len(grid), len(grid[0])

    pq = []  # priority queue
    h0 = heuristic(start, goal, mode)

    # (f, h, node) → ensures tie-breaking
    heapq.heappush(pq, (h0, h0, start))

    g_cost = {start: 0}
    parent = {start: None}

    visited = set()
    expanded_nodes = 0

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while pq:
        f_val, h_val, current = heapq.heappop(pq)

        if current in visited:
            continue

        if current == goal:
            return construct_path(parent, goal), expanded_nodes

        visited.add(current)
        expanded_nodes += 1

        for dx, dy in directions:
            nx, ny = current[0] + dx, current[1] + dy

            # boundary + obstacle check
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] != "#":
                neighbor = (nx, ny)
                new_g = g_cost[current] + 1

                if neighbor not in g_cost or new_g < g_cost[neighbor]:
                    g_cost[neighbor] = new_g

                    h_new = heuristic(neighbor, goal, mode)
                    f_new = new_g + h_new

                    heapq.heappush(pq, (f_new, h_new, neighbor))
                    parent[neighbor] = current

    return None, expanded_nodes


# -------- Path Reconstruction --------
def construct_path(parent_map, end):
    path = []
    cur = end

    while cur is not None:
        path.append(cur)
        cur = parent_map[cur]

    path.reverse()
    return path


# -------- MAIN PROGRAM --------
# Input
n, m = map(int, input().split())
grid = [list(input()) for _ in range(n)]

start = goal = None

# Find R and D
for i in range(n):
    for j in range(m):
        if grid[i][j] == "R":
            start = (i, j)
        elif grid[i][j] == "D":
            goal = (i, j)

# Run A* for both heuristics
path_m, expanded_m = run_astar(grid, start, goal, "manhattan")
path_e, expanded_e = run_astar(grid, start, goal, "euclidean")

# Choose path (both should be optimal)
final_path = path_m if path_m else path_e

# -------- OUTPUT --------
print("Shortest Path Length:", len(final_path))

# Print path
print("Path:", end=" ")
for i in range(len(final_path)):
    print(f"({final_path[i][0]},{final_path[i][1]})", end="")
    if i != len(final_path) - 1:
        print("->", end="")
print()

# Mark grid
grid_copy = [row[:] for row in grid]

for r, c in final_path:
    if grid_copy[r][c] not in ("R", "D"):
        grid_copy[r][c] = "*"

print("\nGrid with Path:")
for row in grid_copy:
    print("".join(row))

# Expanded nodes
print("\nNodes Expanded:")
print("Euclidean Distance:", expanded_e)
print("Manhattan Distance:", expanded_m)
