#include <vector>
#include <cstdint>

using namespace std;

class TicTacToe {
public:
    TicTacToe(int n) {
        board_size = n;
        xPerCols.reserve(n);
        oPerCols.reserve(n);
        xPerRows.reserve(n);
        oPerRows.reserve(n);
        
        for (int i = 0; i < n; ++i)
        {
            xPerCols.push_back(0);
            oPerCols.push_back(0);
            xPerRows.push_back(0);
            oPerRows.push_back(0);
            xFirstDiag = 0;
            oFirstDiag = 0;
            xSecondDiag = 0;
            oSecondDiag = 0;
        }       
    }
    
    int move(int row, int col, int player) {
        if (player == 1)
        {
            ++xPerRows[row];
            ++xPerCols[col];
            if (row == col)
            {
                ++xFirstDiag;
            }
            if (row + col == board_size - 1)
            {
                ++xSecondDiag;
            }
        }
        if (player == 2)
        {
            ++oPerRows[row];
            ++oPerCols[col];
            if (row == col)
            {
                ++oFirstDiag;
            }
            if (row + col == board_size - 1)
            {
                ++oSecondDiag;
            }
        }
        if (xPerRows[row] == board_size || 
            xPerCols[col] == board_size ||
            oPerRows[row] == board_size || 
            oPerCols[col] == board_size ||
            xFirstDiag == board_size ||
            oFirstDiag == board_size ||
            xSecondDiag == board_size ||
            oSecondDiag == board_size)
        {
            return player;
        }
        return 0;
    }
private:
    vector<size_t> xPerCols;
    vector<size_t> oPerCols;
    vector<size_t> xPerRows;
    vector<size_t> oPerRows;
    size_t xFirstDiag;
    size_t oFirstDiag;
    size_t xSecondDiag;
    size_t oSecondDiag;
    size_t board_size;
};
