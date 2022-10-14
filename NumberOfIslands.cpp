#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int n, int m)
{
    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (grid[i][j] == 0)
        return;
    if (!vis[i][j])
    {
        vis[i][j] = 1;
        dfs(i - 1, j, grid, vis, n, m);
        dfs(i + 1, j, grid, vis, n, m);
        dfs(i, j - 1, grid, vis, n, m);
        dfs(i, j + 1, grid, vis, n, m);
    }
}
int numIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int c = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                dfs(i, j, grid, vis, n, m);
                c++;
            }
        }
    }
    return c;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout<<numIslands(grid)<<endl;
}