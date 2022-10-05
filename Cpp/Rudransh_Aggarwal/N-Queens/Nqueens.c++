class Solution
{
public:
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        int dupcol = col;
        int duprow = row;
        // row and col dec(upwards)
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;

        // same row diff col
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }
        col = dupcol;
        row = duprow;
        // row inc ,col dec (downwards)
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        // base case will write afterwards
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        solve(0, board, ans, n);
        return ans;
    }
};