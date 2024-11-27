#include <iostream>
#include <climits> // For INT_MAX
#include <vector>
#include <string>
#include <cstring> // For memset

// Function to perform Dijkstra's algorithm and track paths
void dijkstra(const std::vector<std::vector<int> >& graph, int n, int src, std::vector<int>& dist, std::vector<int>& prev) {
    std::vector<bool> visited(n, false); // Track visited nodes

    // Initialize distances and previous node array
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1; // No previous node
    }
    dist[src] = 0; // Distance to source is 0

    for (int count = 0; count < n - 1; count++) {
        // Find the node with the minimum distance that hasn't been visited
        int minDist = INT_MAX, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // All remaining nodes are unreachable
        visited[u] = true;

        // Relaxation: Update distances and track the previous node
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u; // Track the node leading to `v`
            }
        }
    }
}

// Function to reconstruct the path from source to target
void reconstructPath(const std::vector<int>& prev, int src, int target, const std::vector<std::string>& locations) {
    if (target == -1 || src == target) {
        std::cout << locations[src] << " ";
        return;
    }

    reconstructPath(prev, src, prev[target], locations);
    std::cout << locations[target] << " ";
}

int main() {
    int k; // Number of test cases
    std::cin >> k;

    for (int test = 0; test < k; test++) {
        int n; // Number of locations
        std::cin >> n;

        // Input locations
        std::vector<std::string> locations(n);
        for (int i = 0; i < n; i++) {
            std::cin >> locations[i];
        }

        // Input distance matrix
        std::vector<std::vector<int> > graph(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> graph[i][j];
        }   }

        // Perform Dijkstra's algorithm from the first location (index 0)
        int src = 0, target = n - 1; // From first to last location
        std::vector<int> dist(n), prev(n);
        dijkstra(graph, n, src, dist, prev);

        // Output the shortest distance
        if (dist[target] == INT_MAX) {
            std::cout << "No path exists." << std::endl;
        } else {
            reconstructPath(prev, src, target, locations);
            std::cout << dist[target] << std::endl;
        }
    }

    return 0;
}
