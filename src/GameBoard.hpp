
#include <iostream>
#include <string>
#include <array>

struct GameBoard
{
   void create_board_game();
   void draw_board();
   void boardMove(int entry, char symbol);
   bool isCellEmpty(int entry);
   void convertInt(int entry);
   std::array<std::array<char, 3>, 3> boardArray;
   int row;
   int column;
};

