
#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "GameBoard.hpp"
#include "Player.hpp"


void GameBoard::create_board_game()
{
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            boardArray[row][column] = ' ';
        }
       
    }
}

void GameBoard::draw_board()
{
    for (int row = 0; row < 3; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            std::cout <<  " | " << boardArray[row][column];
        }
        std::cout <<  " |" << std::endl;
        //if (row + 1 < board.size()) std::cout << "---+---+---" << std::endl;
        
    }
    std::cout << "tour joué" << std::endl;
}

bool GameBoard::isCellEmpty(int entry)
{
    convertInt(entry);
    if (boardArray[row][column] == ' ') {
            
            return true;
    }
    std::cout << "Case déjà occupée, recommencez" << std::endl;
    return false; 
            
}

void GameBoard::convertInt(int entry)
{   
    row = (entry - 1) / 3;
    column = (entry - 1) % 3;
}

void GameBoard::boardMove(int entry, char symbol) {
    convertInt(entry);
    boardArray[row][column] = symbol;
}
