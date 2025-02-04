#include <bits/stdc++.h>

using namespace std;

// Directions: Right, Left, Down, Up
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// Structure to represent a cell in the maze
struct Node {
    int x, y, g, h, f;
    Node* parent;

    Node(int x, int y, int g, int h, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}

    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

// Manhattan distance heuristic function
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Check if a cell is within the grid boundaries
bool isWithinBounds(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Check if a cell is a valid move
bool isValid(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (maze[x][y] == 0 && !visited[x][y]);
}

// A* Search Algorithm
vector<pair<int, int>> aStarSearch(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> end) {
    int rows = maze.size(), cols = maze[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    Node* startNode = new Node(start.first, start.second, 0, heuristic(start.first, start.second, end.first, end.second));
    pq.push(*startNode);

    cout << "\nProcessing nodes step by step:\n";
    cout << "------------------------------------------------------\n";
    cout << "Current (x, y) | Move to (x, y) | g(n) | h(n) | f(n) | Status\n";
    cout << "------------------------------------------------------\n";

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        // If we reached the goal, reconstruct the path
        if (current.x == end.first && current.y == end.second) {
            vector<pair<int, int>> path;
            Node* pathNode = &current;
            while (pathNode) {
                path.push_back({pathNode->x, pathNode->y});
                pathNode = pathNode->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        visited[current.x][current.y] = true;

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            // Skip out-of-bounds cases (don't print them)
            if (!isWithinBounds(newX, newY, rows, cols)) {
                continue;
            }

            int newG = current.g + 1;
            int newH = heuristic(newX, newY, end.first, end.second);
            int newF = newG + newH;

            if (isValid(newX, newY, maze, visited)) {
                cout << "   (" << current.x << ", " << current.y << ")  ->  (" << newX << ", " << newY << ")   |  " 
                     << newG << "  |  " << newH << "  |  " << newF << "  | Accepted \n";
                Node* nextNode = new Node(newX, newY, newG, newH, new Node(current.x, current.y, current.g, current.h, current.parent));
                pq.push(*nextNode);
            } else {
                string reason = (maze[newX][newY] == 1) ? "Wall (1)"
                              : (visited[newX][newY]) ? "Already visited"
                              : "Invalid";
                cout << "   (" << current.x << ", " << current.y << ")  ->  (" << newX << ", " << newY << ")   |  --  |  --  |  --  | Rejected  (" << reason << ")\n";
            }
        }
    }

    return {}; // Return empty path if no solution found
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> maze(rows, vector<int>(cols));
    cout << "Enter the maze matrix (0 for path, 1 for wall):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> maze[i][j];
        }
    }

    int startX, startY, endX, endY;
    cout << "Enter start coordinates (row col): ";
    cin >> startX >> startY;
    cout << "Enter end coordinates (row col): ";
    cin >> endX >> endY;

    pair<int, int> start = {startX, startY};
    pair<int, int> end = {endX, endY};

    if (maze[startX][startY] == 1 || maze[endX][endY] == 1) {
        cout << "Invalid start or end position (walls cannot be selected)!\n";
        return 1;
    }

    vector<pair<int, int>> path = aStarSearch(maze, start, end);

    if (!path.empty()) {
        cout << "\nFinal Path Found:\n";
        for (auto& p : path) {
            cout << "(" << p.first << ", " << p.second << ") -> ";
        }
        cout << "END\n";
    } else {
        cout << "No path found!\n";
    }

    return 0;
}
