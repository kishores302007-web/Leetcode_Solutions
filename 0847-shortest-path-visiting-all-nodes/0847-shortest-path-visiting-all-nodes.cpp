class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        // All nodes visited
        int fullMask = (1 << n) - 1;

        // visited[node][mask]
        vector<vector<bool>> visited(
            n,
            vector<bool>(1 << n, false)
        );

        // {current node, visited mask}
        queue<pair<int, int>> q;

        // We can start from ANY node
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);

            q.push({i, mask});
            visited[i][mask] = true;
        }

        int distance = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [node, mask] = q.front();
                q.pop();

                // Have we visited every node?
                if (mask == fullMask) {
                    return distance;
                }

                // Visit all neighbors
                for (int next : graph[node]) {

                    int newMask = mask | (1 << next);

                    if (!visited[next][newMask]) {

                        visited[next][newMask] = true;

                        q.push({
                            next,
                            newMask
                        });
                    }
                }
            }

            distance++;
        }

        return -1;
    }
};