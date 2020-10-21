#include <vector>
#include <string>

class Sudoku{
    private:
        const unsigned int EMPTY = 0;
        const unsigned int BOARD_SIZE = 9;
        std::vector<std::vector<unsigned int> > * board;

        bool find_empty_location(unsigned int& row, unsigned int& col);
        bool is_valid(unsigned int row, unsigned int col, int num);
        bool check_row(unsigned int row, unsigned int num);
        bool check_col(unsigned int col, unsigned int num);
        bool check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num);

    public:
        Sudoku();
        Sudoku(std::string f_name);
        ~Sudoku();

        bool solve();
        void display_board();
};