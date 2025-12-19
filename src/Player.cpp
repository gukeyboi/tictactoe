#include <iostream>
#include <string>
#include <array>
#include "GameBoard.hpp"

struct Player
{
    std::string name;
    std::string symbol;
};

Player create_player()
{
    std::string name;
    std::string symbol;
    std::cout << "Veuillez indiquer votre nom" << std::endl;
    std::cin >> name;
    std::cout << "Veuillez indiquer votre symbole" << std::endl;
    std::cin >> symbol;
    Player one{name, symbol};
    return one;
}


void draw_board(const std::array<std::array<char, 3>, 3> &board)
{
    for (size_t row = 0; row < board.size(); ++row) {
        for (size_t column = 0; column < board[row].size(); ++column) {
            size_t pos = row * board[row].size() + column + 1; // 1..9
            char ch = board[row][column];
            if (ch == ' ') ch = static_cast<char>('0' + pos); // show position number for empty cells
            std::cout << ' ' << ch << ' ';
            if (column + 1 < board[row].size()) std::cout << '|';
        }
        std::cout << std::endl;
       //if (r + 1 < board.size()) std::cout << "---+---+---" << std::endl;
    }
}

int main()
{
    auto player = create_player();
    auto board = create_board_game();

    std::cout << "Bienvenue " << player.name << "!" << std::endl;
    draw_board(board);
}