

#include <bits/stdc++.h>
using namespace std;

class LinkedIn {
private:
    unordered_map<string, vector<string>> connections;

    // Depth Limit Search function (helper for iterative deepening)
    bool depthLimitSearch(string current, string target, int level, int limit, set<string>& visited) {
        if (level > limit) return false;

        cout << "Searching at Level " << level << ": " << current << endl;  // Debug line

        if (current == target) {
            cout << "Target " << target << " found at Level " << level << endl;  // Debug line
            return true;
        }

        visited.insert(current);
        for (auto& neighbor : connections[current]) {
            if (visited.find(neighbor) == visited.end()) {
                if (depthLimitSearch(neighbor, target, level + 1, limit, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Initialize the network with default connections
    void initializeDefaultConnections() {
        connections["John_Doe"] = {"Alice_Smith", "Bob_Johnson"};
        connections["Grace_Lee"] = {"Alice_Smith"};
        connections["Alice_Smith"] = {"John_Doe", "Grace_Lee", "Frank_Brown"};
        connections["Bob_Johnson"] = {"John_Doe", "Emily_Davis", "Frank_Brown", "Chris_Wilson"};
        connections["Emily_Davis"] = {"Bob_Johnson", "Hannah_Walker"};
        connections["Hannah_Walker"] = {"Emily_Davis"};
        connections["David_Moore"] = {"Chris_Wilson"};
        connections["Chris_Wilson"] = {"Bob_Johnson", "David_Moore"};
        connections["Frank_Brown"] = {"Alice_Smith", "Bob_Johnson"};
    }

    // Allow user to input their own graph
    void initializeUserConnections() {
        int choice;
        string person1, person2;
        while (1) {
            cout << "Enter names of two Persons: ";
            cin >> person1 >> person2;
            addConnection(person1, person2);
            cout << "Do you want to add another connection? (0/1): ";
            cin >> choice;
            if (choice == 0) break;
        }
    }

public:
    LinkedIn(bool useDefault) {
        if (useDefault) {
            initializeDefaultConnections();
        } else {
            initializeUserConnections();
        }
    }

    void addConnection(string u, string v) {
        connections[u].push_back(v);
        connections[v].push_back(u);
    }

    // Breadth First Search
    void bfs(string start) {
        queue<pair<string, int>> q; // Pair of person and level
        set<string> visited;
        q.push({start, 0});
        visited.insert(start);

        cout << "\nBreadth First Search:\n";
        while (!q.empty()) {
            string person = q.front().first;
            int level = q.front().second;
            q.pop();

            cout << "Level " << level << ": " << person << endl;

            for (auto& neighbor : connections[person]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push({neighbor, level + 1});
                    visited.insert(neighbor);
                }
            }
        }
    }

    // Depth First Search
    void dfs(string current, int level, set<string>& visited) {
        visited.insert(current);
        cout << "Level " << level << ": " << current << endl;

        for (auto& neighbor : connections[current]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, level + 1, visited);
            }
        }
    }

    void depthFirstSearch(string start) {
        set<string> visited;
        cout << "\nDepth First Search:\n";
        dfs(start, 0, visited);
    }

    // Iterative Deepening Search
    void iterativeDeepeningSearch(string start, string target, int maxDepth) {
        cout << "\nIterative Deepening Search:\n";
        for (int depth = 1; depth <= maxDepth; ++depth) {
            set<string> visited;
            cout << "Searching at depth " << depth << "--->" << endl;
            if (depthLimitSearch(start, target, 0, depth, visited)) {
                cout << "Found " << target << " at depth " << depth << endl;
                return;
            }
        }
        cout << target << " is not reachable from " << start << " within the depth " << maxDepth << endl;
    }
};

int main() {
    bool useDefault;
    cout << "Do you want to use the default graph? (1 for Yes, 0 for No): ";
    cin >> useDefault;

    LinkedIn rn(useDefault);

    int choice = 0;
    string startPerson, targetPerson;
    int depth;

    while (1) {
        cout << "\nChoose an option:\n";
        cout << "1. Breadth First Search\n";
        cout << "2. Depth First Search\n";
        cout << "3. Iterative Deepening Search\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the starting Person: ";
                cin >> startPerson;
                rn.bfs(startPerson);
                break;
            case 2:
                cout << "Enter the starting Person: ";
                cin >> startPerson;
                rn.depthFirstSearch(startPerson);
                break;
            case 3:
                cout << "Enter the starting Person: ";
                cin >> startPerson;
                cout << "Enter the target Person: ";
                cin >> targetPerson;
                cout << "Enter the maximum depth for search: ";
                cin >> depth;
                rn.iterativeDeepeningSearch(startPerson, targetPerson, depth);
                break;
            case 4:
                cout << "Exiting. Thank you for using the LinkedIn Connections graph system!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    }
}
