bool isSafe(vector<string> &board, int row, int col, int N){
    // Check for previous rows
    for(int i=col;i>=0;i--)
        if(board[row][i] == 'Q')
            return false;
    // Check for upper diagonal leftwards....
    for(int i=col, j=row; i>=0 && j>=0; i--,j--)
        if(board[j][i] == 'Q')
            return false;
    // Check for lower diagonal leftwards....
    for(int i=col, j=row; i>=0 && j<N; i--,j++)
        if(board[j][i] == 'Q')
            return false;
    return true;
}

void solve(vector<string> temp, int col, int size, vector<vector<string>> &board){
    if(col == size){
        board.push_back(temp);
    }
    for(int i=0;i<size;i++){
        if(isSafe(temp, i, col, size)){
            temp[i][col] = 'Q';
            solve(temp, col+1, size, board);
            temp[i][col] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> board;
    if(A == 2 || A == 3)
        return board;

    string s(A,'.');
    vector<string> temp(A,s);
    solve(temp, 0, A, board);
    return board;
}

// https://www.interviewbit.com/problems/nqueens/