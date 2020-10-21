#include <vector>
#include <iostream>

class NQueens{
    private:
        unsigned int board_size;
        std::vector<std::vector<unsigned int> > * board;
        bool solve_rec(int col);
        bool is_valid(unsigned int row, unsigned int col);
    public:
        NQueens();
        NQueens(unsigned int n);
        ~NQueens();
        void display_board();
        bool solve();
};