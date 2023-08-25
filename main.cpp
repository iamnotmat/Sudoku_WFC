#include <bits/stdc++.h>
using namespace std;

void print_board(vector<vector<vector<int>>> &brd)
{
    cout << "Board:" << endl;
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) cout << "-------------------------" << endl;
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) cout << "| ";
            for (int k = 0; k < 9; k++)
            {
                if (brd[i][j].size() > k) cout << brd[i][j][k] << " ";
                else cout << "  ";
            }
            cout << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------------------" << endl;
}

bool check_valid(int row, int col, int value, vector<vector<vector<int>>> &brd) 
{
    // Check if value is already collapsed
    if (brd[row][col].size() == 1) {
        // cout << "Value already collapsed" << endl;
        return false;
    }

    // Check if value is in row
    for (int i = 0; i < 9; i++)
        if (i != col && brd[row][i].size() == 1 && brd[row][i][0] == value) {
            // cout << "Value already in row" << endl;
            return false;
        }

    // Check if value is in column
    for (int i = 0; i < 9; i++)
        if (i != row && brd[i][col].size() == 1 && brd[i][col][0] == value) {
            // cout << "Value already in column" << endl;
            return false;
        }

    // Check if value is in 3x3 square
    int row_start = row - row % 3;
    int col_start = col - col % 3;
    for (int i = row_start; i < row_start + 3; i++)
        for (int j = col_start; j < col_start + 3; j++)
            if (i != row && j != col && brd[i][j].size() == 1 && brd[i][j][0] == value) {
                // cout << "Value already in 3x3 square" << endl;
                return false;
            }

    return true;
}

bool collapse_tile(int row, int col, int value, vector<vector<vector<int>>> &brd) 
{
    // Collapse value
    brd[row][col] = {value};

    // Remove value from all other tiles in row
    for (int i = 0; i < 9; i++)
        if (i != col)
            brd[row][i].erase(remove(brd[row][i].begin(), brd[row][i].end(), value), brd[row][i].end());

    // Remove value from all other tiles in column
    for (int i = 0; i < 9; i++)
        if (i != row)
            brd[i][col].erase(remove(brd[i][col].begin(), brd[i][col].end(), value), brd[i][col].end());

    // Remove value from all other tiles in 3x3 square
    int row_start = row - row % 3;
    int col_start = col - col % 3;
    for (int i = row_start; i < row_start + 3; i++)
        for (int j = col_start; j < col_start + 3; j++)
            if (i != row && j != col)
                brd[i][j].erase(remove(brd[i][j].begin(), brd[i][j].end(), value), brd[i][j].end());

    return true;
}

bool complete_board(int row, int col, vector<vector<vector<int>>> brd) 
{
    if (row == 8 && col == 9) {
        cout << "Board complete" << endl;
        print_board(brd);
        return true;
    }
    if (col == 9) row++, col = 0;

    // Check if there are no possible values for tile
    if (brd[row][col].size() == 0) return false;

    // Try all possible values for tile
    for (int i = 0; i < brd[row][col].size(); i++) 
    {
        int value = brd[row][col][i];
        vector<vector<vector<int>>> brd_copy = brd;
        if (collapse_tile(row, col, value, brd_copy))
            if (complete_board(row, col + 1, brd_copy)) return true;
    }

    return false;
}

int main() 
{
    cout << "SUDOKU SOLVER USING WFC (WAVE FUNCTION COLLAPSE)" << endl;

    // Initialize board
    vector<vector<vector<int>>> board(9, vector<vector<int>>(9, vector<int>(9)));

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            iota(board[i][j].begin(), board[i][j].end(), 1);

    char collapse_new = 'y';
    while (collapse_new == 'y') 
    {
        cout << "Enter new collapse (ROW COL VALUE): ";
        int row, col, value;
        cin >> row >> col >> value;
        row--, col--;

        if (row < 0 || row > 8 || col < 0 || col > 8 || value < 1 || value > 9) {
            cout << "Invalid input" << endl;
            continue;
        }

        if (check_valid(row, col, value, board) && collapse_tile(row, col, value, board))
            cout << "Collapse successful" << endl;
        else
            cout << "Collapse unsuccessful" << endl;

        cout << "Enter new collapse? (y/n): ";
        cin >> collapse_new;
    }

    complete_board(0, 0, board);
}
