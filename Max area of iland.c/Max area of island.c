/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.
*/

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {

    //creating a hash set for visited
    int** visited = malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        visited[i] = calloc(*gridColSize, sizeof(int));
    }


    int cnt_area(int r, int c, int** visited, int** grid) {
        if (r < 0 || c < 0 || r >= gridSize || c >= *gridColSize || visited[r][c] || grid[r][c] == 0) { return 0; }
        visited[r][c] = 1;
        return 1 + cnt_area(r - 1, c, visited, grid) +
            cnt_area(r + 1, c, visited, grid) +
            cnt_area(r, c - 1, visited, grid) +
            cnt_area(r, c + 1, visited, grid);
    }

    int max = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            int c = cnt_area(i, j, visited, grid);
            if (c > max) { max = c; }
        }
    }
    for (int i = 0; i < gridSize; i++) {
        free(visited[i]);
    }
    free(visited);
    return max;
}