#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <limits>
#include "GameBoard.hpp"



struct Player
{
    std::string name;
    char symbol;
    std::vector<int> playerPlays{};
};

Player create_player()
{
    std::string name;
    char symbol;
    std::cout << "Veuillez indiquer votre nom" << std::endl;
    std::cin >> name;
    do {
        std::cout << "Veuillez choisir votre symbole (X ou O)" << std::endl;
        std::cin >> symbol;
        //symbol = toupper(symbol);
    } while (symbol != 'X' && symbol != 'O');
    Player one{name, symbol};
    return one;
}

Player create_ia(Player &player1)
{
    std::string name = "IA";
    char symbol;
    char iaSymbol = (player1.symbol == 'X') ? 'O' : 'X';
    return Player{"IA", iaSymbol};
    Player one{name, symbol};
    return one;
}



void playerTurn(GameBoard &activeBoard, Player &currentplayer)
{
    int num_case;
    while (true) {
        std::cout << currentplayer.name <<" quelle case choisissez-vous ?" << std::endl;
        if (!(std::cin >> num_case)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Valeur invalide, recommencez" << std::endl;
            continue;
        }
        if (num_case >= 1 && num_case <= 9) {
            if (!activeBoard.isCellEmpty(num_case)) {
                continue;
            }
                activeBoard.boardMove(num_case, currentplayer.symbol);
                activeBoard.draw_board();
            
            currentplayer.playerPlays.push_back(num_case);
            break;
        }
    }
    
}

void modePvP(GameBoard activeBoard, Player &player1, Player &player2)
{   
    activeBoard.draw_board();
    int turns {0};
    while (turns < 4)
    {
        playerTurn(activeBoard, player1);
       if (activeBoard.checkVictory(player1.symbol))
       {
        std::cout << "bravo joueur 1" << std::endl;
        return;
       }
        
        playerTurn(activeBoard, player2);

        if (activeBoard.checkVictory(player2.symbol))
       {
        std::cout << "bravo joueur 2" << std::endl;
        return;
       }
        turns++;
    }
    playerTurn(activeBoard, player1);
    std::cout << "Match Nul !" << std::endl;
}

void modeIA(GameBoard activeBoard, Player &player1, Player &ia) {
    activeBoard.draw_board();
    int turns {0};
    while (turns < 4)
    {
        playerTurn(activeBoard, player1);
       if (activeBoard.checkVictory(player1.symbol))
       {
        std::cout << "bravo joueur 1" << std::endl;
        return;
       }
        
        playerTurn(activeBoard, ia);

        if (activeBoard.checkVictory(ia.symbol))
       {
        std::cout << "Victoire de l'IA, elle va nous remplacer dans quelques années..." << std::endl;
        return;
       }
        turns++;
    }
    playerTurn(activeBoard, player1);
    std::cout << "Match Nul !" << std::endl;

}

int main()
{
    GameBoard activeBoard;
    activeBoard.create_board_game();
    std::cout << "Bienvenue dans le jeu du TicTacToe, veuillez choisir votre mode de jeu" << std::endl;
    std::cout << "1. Joueur contre Joueur, 2. Contre l'ordinateur" << std::endl;
    int gamemode{0};

    do
    {
        if (!(std::cin >> gamemode)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "On a dit 1 ou 2, recommencez" << std::endl;
            continue;
        }

        if (gamemode == 1)
        {
            auto player1 = create_player();
            auto player2 = create_player();
            modePvP(activeBoard, player1, player2);
            break;
        }
        else if (gamemode == 2)
        {
            auto player1 = create_player();
            auto ia = create_player();
            break;
        }
        else
        {
            std::cout << "Choix inconnu, recommencez" << std::endl;
        }
    } while (gamemode != 1 && gamemode != 2);
    
    return 0;
}