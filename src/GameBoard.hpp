
#include <iostream>
#include <string>
#include <array>

std::array<std::array<char, 3>, 3> create_board_game()
{
    std::array<std::array<char, 3>, 3> board{};
    for (auto &row : board) {
        row.fill(' ');
    }
    return board;
}
