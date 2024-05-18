#include <bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Edge {
    int to;
    long long cost;
};

struct State {
    int city;
    int couponUsed;
    long long cost;

    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

long long dijkstra(int n, vector<vector<Edge>>& graph) {
    vector<vector<long long>> dist(n, vector<long long>(2, INF));
    dist[0][0] = 0;  // Start from city 1 without using the coupon

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        int city = cur.city;
        int couponUsed = cur.couponUsed;
        long long cost = cur.cost;

        if (city == n - 1) {
            return cost;
        }

        if (cost > dist[city][couponUsed]) {
            continue; // Skip outdated information
        }

        for (const Edge& edge : graph[city]) {
            int neighbor = edge.to;
            long long price = edge.cost;

            if (couponUsed == 0) {
                // Try using the coupon on this flight
                long long newCost = cost + price / 2;
                if (newCost < dist[neighbor][1]) {
                    dist[neighbor][1] = newCost;
                    pq.push({neighbor, 1, newCost});
                }
            }

            // Continue without using the coupon
            if (cost + price < dist[neighbor][couponUsed]) {
                dist[neighbor][couponUsed] = cost + price;
                pq.push({neighbor, couponUsed, cost + price});
            }
        }
    }

    return -1; // This should not happen as there is always a path from city 1 to city n.
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; // Convert to 0-based indexing
        b--; // Convert to 0-based indexing
        graph[a].push_back({b, c});
    }

    long long result = dijkstra(n, graph);
    cout << result << endl;

    return 0;
}


