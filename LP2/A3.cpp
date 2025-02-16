#include <bits/stdc++.h>
using namespace std;

// Structure for Job Scheduling
struct Job {
    char id;    // Job Id
    int dead;   // Deadline of the job
    int profit; // Profit if the job is done before or on the deadline
};

// Graph class for Prim’s and Dijkstra’s Algorithms
class Graph {
    int nv;                           // Number of vertices
    vector<pair<int, int>> *adjList;  // Adjacency list e.g. {vertex, weight}

public:
    Graph(int nv) {
        this->nv = nv;
        adjList = new vector<pair<int, int>>[nv];
    }

    void addEdge(int src, int des, int weight) {
        adjList[src].push_back({des, weight});
        adjList[des].push_back({src, weight});  // For undirected graph
    }

    void primsMST(int start) {
        vector<int> parent(nv, -1);
        vector<int> key(nv, INT_MAX);
        vector<bool> mstSet(nv, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            mstSet[u] = true;

            for (auto i : adjList[u]) {
                int v = i.first;
                int weight = i.second;

                if (!mstSet[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }

        cout << "\nEdges in Minimum Spanning Tree (MST):\n";
        for (int i = 1; i < nv; i++) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
        }

        int totalWeight = accumulate(key.begin() + 1, key.end(), 0);
        cout << "Total weight of MST: " << totalWeight << endl;
    }

    void dijkstra(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(nv, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto i : adjList[u]) {
                int v = i.first;
                int weight = i.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "\nShortest paths from vertex " << src << ":\n";
        for (int i = 0; i < nv; i++) {
            cout << "To " << i << " -> " << dist[i] << endl;
        }
    }
};

// Comparison function for sorting jobs by profit (Job Scheduling)
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

// Job Scheduling Algorithm
void printJobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comparison);

    vector<bool> slot(n, false);
    vector<char> result(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = arr[i].id;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Following is the sequence of jobs selected:\n";
    for (char job : result) {
        if (job) cout << job << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "\nChoose an algorithm to execute:\n";
        cout << "1. Job Scheduling\n";
        cout << "2. Prim's Minimum Spanning Tree\n";
        cout << "3. Dijkstra's Shortest Path\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the number of jobs: ";
                cin >> n;
                Job arr[n];

                for (int i = 0; i < n; i++) {
                    cout << "Enter Job " << i + 1 << " details:\n";
                    cout << "Job ID: ";
                    cin >> arr[i].id;
                    cout << "Deadline: ";
                    cin >> arr[i].dead;
                    cout << "Profit: ";
                    cin >> arr[i].profit;
                }

                printJobScheduling(arr, n);
                break;
            }

            case 2: {
                int nv, edges;
                cout << "Enter the number of vertices: ";
                cin >> nv;

                Graph g(nv);

                cout << "Enter the number of edges: ";
                cin >> edges;

                cout << "Enter the edges in the format (source destination weight):\n";
                for (int i = 0; i < edges; i++) {
                    int src, des, weight;
                    cin >> src >> des >> weight;
                    g.addEdge(src, des, weight);
                }

                int start;
                cout << "Enter the starting vertex for Prim's Algorithm: ";
                cin >> start;
                g.primsMST(start);
                break;
            }

            case 3: {
                int nv, edges;
                cout << "Enter the number of vertices: ";
                cin >> nv;

                Graph g(nv);

                cout << "Enter the number of edges: ";
                cin >> edges;

                cout << "Enter the edges in the format (source destination weight):\n";
                for (int i = 0; i < edges; i++) {
                    int src, des, weight;
                    cin >> src >> des >> weight;
                    g.addEdge(src, des, weight);
                }

                int start;
                cout << "Enter the starting vertex for Dijkstra's Algorithm: ";
                cin >> start;
                g.dijkstra(start);
                break;
            }

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please select a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
