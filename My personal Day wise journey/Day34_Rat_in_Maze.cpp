// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends



bool isSafe(int row, int col, int m[][MAX],  
                 int n, bool visited[][MAX]) 
{ 
    if (row == -1 || row == n || col == -1 ||  
                  col == n || visited[row][col]  
                           || m[row][col] == 0) 
        return false; 
  
    return true; 
} 
 
void printPathUtil(int row, int col, int m[][MAX],  
              int n, string& path, vector<string>&  
               possiblePaths, bool visited[][MAX]) 
{ 

    if (row == -1 || row == n || col == -1  
               || col == n || visited[row][col]  
                           || m[row][col] == 0) 
        return; 
  

    if (row == n - 1 && col == n - 1) { 
        possiblePaths.push_back(path); 
        return; 
    } 
  

    visited[row][col] = true; 

    if (isSafe(row + 1, col, m, n, visited)) 
    { 
        path.push_back('D'); 
        printPathUtil(row + 1, col, m, n, 
                 path, possiblePaths, visited); 
        path.pop_back(); 
    } 
  

    if (isSafe(row, col - 1, m, n, visited)) 
    { 
        path.push_back('L'); 
        printPathUtil(row, col - 1, m, n, 
                   path, possiblePaths, visited); 
        path.pop_back(); 
    } 
  
 
    if (isSafe(row, col + 1, m, n, visited))  
    { 
        path.push_back('R'); 
        printPathUtil(row, col + 1, m, n, 
                   path, possiblePaths, visited); 
        path.pop_back(); 
    } 
  
   
    if (isSafe(row - 1, col, m, n, visited)) 
    { 
        path.push_back('U'); 
        printPathUtil(row - 1, col, m, n, 
               path, possiblePaths, visited); 
        path.pop_back(); 
    } 

    visited[row][col] = false; 
} 

vector<string> printPath(int m[MAX][MAX], int n) {
       vector<string> possiblePaths; 
    string path; 
    bool visited[n][MAX]; 
    memset(visited, false, sizeof(visited)); 

    printPathUtil(0, 0, m, n, path,  
                      possiblePaths, visited); 
    
    return possiblePaths;
}
