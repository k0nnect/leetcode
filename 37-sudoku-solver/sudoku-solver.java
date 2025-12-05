class Solution {

    private int n = 9;
    private boolean[][] rows = new boolean[n][n + 1];
    private boolean[][] cols = new boolean[n][n + 1];
    private boolean[][] boxes = new boolean[n][n + 1];
    private char[][] board;
    private boolean solved = false;

    public void solveSudoku(char[][] board) {
        this.board = board;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    int num = Character.getNumericValue(board[i][j]);
                    placeNumber(num, i, j);
                }
            }
        }
        backtrack(0, 0);
    }

    private void backtrack(int row, int col) {
        if (board[row][col] == '.') {
            for (int num = 1; num <= n; num++) {
                if (canPlace(num, row, col)) {
                    placeNumber(num, row, col);
                    placeNextNumber(row, col);

                    if (!solved) {
                        removeNumber(num, row, col);
                    }
                }
            }
        } else {
            placeNextNumber(row, col);
        }
    }

    private boolean canPlace(int num, int row, int col) {
        int boxIndex = (row / 3) * 3 + (col / 3);
        return !rows[row][num] && !cols[col][num] && !boxes[boxIndex][num];
    }

    private void placeNumber(int num, int row, int col) {
        int boxIndex = (row / 3) * 3 + (col / 3);
        rows[row][num] = true;
        cols[col][num] = true;
        boxes[boxIndex][num] = true;
        board[row][col] = (char) (num + '0');
    }

    private void removeNumber(int num, int row, int col) {
        int boxIndex = (row / 3) * 3 + (col / 3);
        rows[row][num] = false;
        cols[col][num] = false;
        boxes[boxIndex][num] = false;
        board[row][col] = '.';
    }

    private void placeNextNumber(int row, int col) {
        if (row == n - 1 && col == n - 1) {
            solved = true;
        } else {
            if (col == n - 1) {
                backtrack(row + 1, 0);
            } else {
                backtrack(row, col + 1);
            }
        }
    }
}