
#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "GameBoard.hpp"
#include "Player.hpp"


void GameBoard::create_board_game()
{
    for (int temprow = 0; temprow < 3; temprow++)
    {
        for (int tempcolumn = 0; tempcolumn < 3; tempcolumn++)
        {
            boardArray[temprow][tempcolumn] = ' ';
        }
       
    }
}

void GameBoard::draw_board()
{
    for (int temprow = 0; temprow < 3; temprow++)
    {
        for (int tempcolumn = 0; tempcolumn < 3; tempcolumn++)
        {
            std::cout <<  " | " << boardArray[temprow][tempcolumn];
        }
        std::cout <<  " |" << std::endl;
        //std::cout << "---+---+---" << std::endl;
        
    }
    //std::cout << "tour joué" << std::endl;
}

bool GameBoard::isCellEmpty(int entry)
{
    convertInt(entry);
    if (boardArray[row][column] == ' ') {
            
            return true;
    }
    
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

bool GameBoard::checkVictory(char symbol) {
    for (int i = 0; i < 3; i++)
    {
        if (boardArray[i][0] == boardArray[i][1] && boardArray[i][1] == boardArray[i][2] && symbol == boardArray[i][2])
        {
            std::cout << "lignes" << std::endl;
            return true; 
        }
        
        if (boardArray[0][i] == boardArray[1][i] && boardArray[1][i] == boardArray[2][i] && symbol == boardArray[2][i])
        {
            std::cout << "colonnes" << std::endl;
            return true; 
        }
        
    }
   if (boardArray[0][0] == boardArray[1][1] && boardArray[1][1] == boardArray[2][2] && symbol == boardArray[2][2])
        {
            std::cout << "diagonales" << std::endl;
            return true; 
        }
    if (boardArray[0][2] == boardArray[1][1] && boardArray[1][1] == boardArray[2][0] && symbol == boardArray[0][2])
        {
            std::cout << "diagonales" << std::endl;
            return true; 
        }
    return false;
}