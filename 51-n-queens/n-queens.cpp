class Solution {
public:
    vector<vector<string>> ans;
    int N;

    bool isValid(vector<string> &board, int r, int c) {
        for (int tc = 0; tc < c; tc++) {
            if (board[r][tc] == 'Q') return false;
        }

        for (int tr = 0; tr < r; tr++) {
            if (board[tr][c] == 'Q') return false;
        }

        for (int tr = r - 1, tc = c - 1; tr >= 0 && tc >= 0; tr--, tc--) {
            if (board[tr][tc] == 'Q') return false;
        }

        for (int tr = r - 1, tc = c + 1; tr >= 0 && tc < N; tr--, tc++) {
            if (board[tr][tc] == 'Q') return false;
        }

        return true;
    }

    void solve(vector<string> &board, int r) {
        if (r >= N) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < N; c++) {
            if (isValid(board, r, c)) {
                board[r][c] = 'Q';
                solve(board, r + 1);
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return ans;
    }
};
