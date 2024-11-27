#include <iostream>
#include <climits> // For INT_MAX
#include <vector>
#include <string>
#include <queue> // For priority_queue
#include <utility> // For std::pair

// function using Dijkstra's algorithm using min-heap
void dijkstra(const std::vector<std::vector<int> >& graph, int n, int src, std::vector<int>& dist, std::vector<int>& prev) {
    // min-heap
    typedef std::pair<int, int> pii;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> > minHeap;

    // initialize distances and previous node array
    dist.assign(n, INT_MAX);
    prev.assign(n, -1);
    dist[src] = 0;

    minHeap.push(std::make_pair(0, src)); // source node distance is zero

    while (!minHeap.empty()) {
        int u = minHeap.top().second; // get the node with the smallest distance
        int currentDist = minHeap.top().first;
        minHeap.pop();

        // if the current distance is already greater than the recorded distance, skip
        if (currentDist > dist[u]) continue;

        // update distances to neighbors
        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0) { // Edge exists
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    prev[v] = u; 
                    minHeap.push(std::make_pair(newDist, v)); // add the updated distance to the heap
                }
            }
        }
    }
}

// function reconstruct the path from source to target
void reconstructPath(const std::vector<int>& prev, int src, int target, const std::vector<std::string>& locations) {
    if (target == -1) return;

    if (src == target) {
        std::cout << locations[src] << " ";
        return;
    }

    reconstructPath(prev, src, prev[target], locations);
    std::cout << locations[target] << " ";
}

int main() {
    int k; // number of test cases
    std::cin >> k;

    for (int test = 0; test < k; test++) {
        int n; // number of locations
        std::cin >> n;

        // input locations
        std::vector<std::string> locations(n);
        for (int i = 0; i < n; i++) {
            std::cin >> locations[i];
        }

        // input distance matrix
        std::vector<std::vector<int> > matrix(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> matrix[i][j];
            }
        }

        
        int src = 0, target = n - 1; // first and last location
        std::vector<int> dist(n), prev(n);
        dijkstra(matrix, n, src, dist, prev);

        // output the shortest distance and path
        if (dist[target] == INT_MAX) {
            std::cout << "No path exists." << std::endl;
        } else {
            reconstructPath(prev, src, target, locations);
            std::cout <<dist[target] << std::endl;
        }
    }

    return 0;
}
