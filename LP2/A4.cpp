// #include <bits/stdc++.h>
// using namespace std;

// // Function to check if placing a queen at board[row][col] is safe
// bool isSafe(vector<vector<int>> &board, int row, int col, int n)
// {
//     // Check the current column
//     for (int i = 0; i < row; i++)
//     {
//         if (board[i][col] == 1)
//         {
//             return false;
//         }
//     }

//     // Check upper-left diagonal
//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//     }

//     // Check upper-right diagonal
//     for (int i = row, j = col; i >= 0 && j < n; i--, j++)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//     }

//     return true;
// }

// // Recursive function to solve N-Queens using Branch and Bound
// void solveNQueensUtil(vector<vector<int>> &board, int row, int n, vector<vector<vector<int>>> &solutions)
// {
//     if (row == n)
//     {
//         // All queens are placed successfully
//         solutions.push_back(board);
//         return;
//     }

//     for (int col = 0; col < n; col++)
//     {
//         if (isSafe(board, row, col, n))
//         {
//             // Place the queen
//             board[row][col] = 1;

//             // Recur for the next row
//             solveNQueensUtil(board, row + 1, n, solutions);

//             // Backtrack (remove the queen)
//             board[row][col] = 0;
//         }
//     }
// }

// // Function to solve the N-Queens problem and return all solutions
// vector<vector<vector<int>>> solveNQueens(int n)
// {
//     vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize the board
//     vector<vector<vector<int>>> solutions;           // Store all solutions
//     solveNQueensUtil(board, 0, n, solutions);
//     return solutions;
// }

// // Function to print all solutions
// void printSolutions(const vector<vector<vector<int>>> &solutions)
// {
//     for (const auto &solution : solutions)
//     {
//         for (const auto &row : solution)
//         {
//             for (int cell : row)
//             {
//                 cout << (cell == 1 ? "Q" : ".") << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     int ch;
    
//     do{
//     cout<<"Enter the choice for the program:\n1: Input\n2: Stop"<<endl;
//     cin>>ch;
//     int n;
//     cout << "Enter the number of queens (n): ";
//     cin >> n;

//     vector<vector<vector<int>>> solutions = solveNQueens(n);

//     cout << "Total solutions for " << n << "-queens problem: " << solutions.size() << endl;
//     printSolutions(solutions);
//     cout << "Total solutions for " << n << "-queens problem: " << solutions.size() << endl;
//     }while(ch != 2);

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// // Function to check if placing a queen at board[row][col] is safe
// bool isSafe(vector<vector<int>> &board, int row, int col, int n)
// {
//     // Check the current column
//     for (int i = 0; i < row; i++)
//     {
//         if (board[i][col] == 1)
//         {
//             return false;
//         }
//     }

//     // Check upper-left diagonal
//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//     }

//     // Check upper-right diagonal
//     for (int i = row, j = col; i >= 0 && j < n; i--, j++)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//     }

//     return true;
// }

// // Recursive function to solve N-Queens using Backtracking
// void solveNQueensBacktracking(vector<vector<int>> &board, int row, int n, vector<vector<vector<int>>> &solutions)
// {
//     if (row == n)
//     {
//         // All queens are placed successfully
//         solutions.push_back(board);
//         return;
//     }

//     for (int col = 0; col < n; col++)
//     {
//         if (isSafe(board, row, col, n))
//         {
//             // Place the queen
//             board[row][col] = 1;

//             // Recur for the next row
//             solveNQueensBacktracking(board, row + 1, n, solutions);

//             // Backtrack (remove the queen)
//             board[row][col] = 0;
//         }
//     }
// }

// // Recursive function to solve N-Queens using Branch and Bound
// void solveNQueensBranchAndBound(vector<vector<int>> &board, int row, int n, vector<vector<vector<int>>> &solutions, vector<bool> &colUsed, vector<bool> &diag1Used, vector<bool> &diag2Used)
// {
//     if (row == n)
//     {
//         // All queens are placed successfully
//         solutions.push_back(board);
//         return;
//     }

//     for (int col = 0; col < n; col++)
//     {
//         // Check if the column or diagonals are already used
//         if (!colUsed[col] && !diag1Used[row - col + n - 1] && !diag2Used[row + col])
//         {
//             // Place the queen
//             board[row][col] = 1;
//             colUsed[col] = true;
//             diag1Used[row - col + n - 1] = true;
//             diag2Used[row + col] = true;

//             // Recur for the next row
//             solveNQueensBranchAndBound(board, row + 1, n, solutions, colUsed, diag1Used, diag2Used);

//             // Backtrack (remove the queen)
//             board[row][col] = 0;
//             colUsed[col] = false;
//             diag1Used[row - col + n - 1] = false;
//             diag2Used[row + col] = false;
//         }
//     }
// }

// // Function to solve the N-Queens problem using the selected method
// vector<vector<vector<int>>> solveNQueens(int n, string method)
// {
//     vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize the board
//     vector<vector<vector<int>>> solutions;           // Store all solutions

//     if (method == "backtracking")
//     {
//         solveNQueensBacktracking(board, 0, n, solutions);
//     }
//     else if (method == "branchandbound")
//     {
//         vector<bool> colUsed(n, false);                  // Track used columns
//         vector<bool> diag1Used(2 * n - 1, false);        // Track used diagonals (top-left to bottom-right)
//         vector<bool> diag2Used(2 * n - 1, false);        // Track used diagonals (top-right to bottom-left)
//         solveNQueensBranchAndBound(board, 0, n, solutions, colUsed, diag1Used, diag2Used);
//     }

//     return solutions;
// }

// // Function to print all solutions
// void printSolutions(const vector<vector<vector<int>>> &solutions)
// {
//     for (const auto &solution : solutions)
//     {
//         for (const auto &row : solution)
//         {
//             for (int cell : row)
//             {
//                 cout << (cell == 1 ? "Q" : ".") << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     int ch;
//     do
//     {
//         cout << "Enter the choice for the program:\n1: Input\n2: Stop" << endl;
//         cin >> ch;
//         if (ch == 1)
//         {
//             int n;
//             string method;
//             cout << "Enter the number of queens (n): ";
//             cin >> n;
//             cout << "Enter the method (backtracking/branchandbound): ";
//             cin >> method;

//             vector<vector<vector<int>>> solutions = solveNQueens(n, method);

//             cout << "Total solutions for " << n << "-queens problem using " << method << ": " << solutions.size() << endl;
//             printSolutions(solutions);
//         }
//     } while (ch != 2);

//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(vector<int>& board, int row, int col)
{
    // Check the current column
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
        {
            return false;  // Same column or diagonal
        }
    }
    return true;
}

// Recursive function to solve N-Queens using Branch and Bound
void solveNQueensUtil(vector<int>& board, int row, int n, vector<vector<int>>& solutions)
{
    if (row == n)
    {
        // All queens are placed successfully, record the solution
        solutions.push_back(board);
        return;
    }

    // Try placing the queen in all columns
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;  // Place the queen

            // Recur for the next row
            solveNQueensUtil(board, row + 1, n, solutions);

            // Backtrack (remove the queen)
            board[row] = -1;
        }
    }
}

// Function to solve the N-Queens problem and return all solutions
vector<vector<int>> solveNQueens(int n)
{
    vector<int> board(n, -1);   // Initialize the board (all positions are unassigned)
    vector<vector<int>> solutions;  // Store all solutions
    solveNQueensUtil(board, 0, n, solutions);
    return solutions;
}

// Function to print all solutions
void printSolutions(const vector<vector<int>>& solutions)
{
    for (const auto& solution : solutions)
    {
        for (int col : solution)
        {
            for (int i = 0; i < solution.size(); i++)
            {
                cout << (i == col ? "Q" : ".") << " "; // Print Q or .
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    int ch;
    do {
        cout << "Enter the choice for the program:\n1: Input\n2: Stop" << endl;
        cin >> ch;

        if (ch == 1) {
            int n;
            cout << "Enter the number of queens (n): ";
            cin >> n;

            vector<vector<int>> solutions = solveNQueens(n);

            cout << "Total solutions for " << n << "-queens problem: " << solutions.size() << endl;
            printSolutions(solutions);
            cout << "Total solutions for " << n << "-queens problem: " << solutions.size() << endl;
        }

    } while (ch != 2);

    return 0;
}