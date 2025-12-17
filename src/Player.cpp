#include <iostream>
#include <string>
#include <array>

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

std::array<std::array<char, 3>, 3> create_board_game()
{
    std::array<std::array<char, 3>, 3> board{};
    for (auto &row : board) {
        row.fill(' ');
    }
    return board;
}

int main()
{
    create_player();
    auto board = create_board_game();
}
