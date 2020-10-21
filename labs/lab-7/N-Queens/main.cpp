#include "n-queens.h"

int main()
{
    unsigned int n;
    std::cout << "Enter Board Size: ";

    std::cin >> n;

    NQueens Q(n);

    Q.solve();

    Q.display_board();

    return 0;
}