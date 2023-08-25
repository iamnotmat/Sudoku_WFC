bool check_valid(int row, int col, int value, vector<vector<vector<int>>> &brd) 
        {
            // Check if value is already collapsed
            if (board[row][col].size() == 1) {
                // cout << "Value already collapsed" << endl;
                return false;
            }

            // Check if value is in row
            for (int i = 0; i < 9; i++)
                if (i != col && board[row][i].size() == 1 && board[row][i][0] == value) {
                    // cout << "Value already in row" << endl;
                    return false;
                }

            // Check if value is in column
            for (int i = 0; i < 9; i++)
                if (i != row && board[i][col].size() == 1 && board[i][col][0] == value) {
                    // cout << "Value already in column" << endl;
                    return false;
                }

            // Check if value is in 3x3 square
            int row_start = row - row % 3;
            int col_start = col - col % 3;
            for (int i = row_start; i < row_start + 3; i++)
                for (int j = col_start; j < col_start + 3; j++)
                    if (i != row && j != col && board[i][j].size() == 1 && board[i][j][0] == value) {
                        // cout << "Value already in 3x3 square" << endl;
                        return false;
                    }

            return true;
        }