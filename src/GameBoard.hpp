#pragma once
#include <iostream>
#include <string>
#include <array>

struct GameBoard
{
   void create_board_game();
   void draw_board();
   bool checkVictory(char symbol);
   void boardMove(int entry, char symbol);
   bool isCellEmpty(int entry);
   void convertInt(int entry);
   char getCellSymbol(int cell) const;
   std::array<std::array<char, 3>, 3> boardArray;
   int row;
   int column;
};

