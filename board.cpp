#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <map>
#include "board.hpp"

int board[64];
// int board[64] = {
//     WHITE | ROOK, WHITE | KNIGHT, WHITE | BISHOP, WHITE | QUEEN, WHITE | KING, WHITE | BISHOP, WHITE | KNIGHT, WHITE | ROOK,
//     WHITE | PAWN, WHITE | PAWN, WHITE | PAWN, WHITE | PAWN, WHITE | PAWN, WHITE | PAWN, WHITE | PAWN, WHITE | PAWN,
//     0, 0, 0, 0, 0, 0, 0, 0,
//     0, 0, 0, 0, 0, 0, 0, 0,
//     0, 0, 0, 0, 0, 0, 0, 0,
//     0, 0, 0, 0, 0, 0, 0, 0,
//     BLACK | PAWN, BLACK | PAWN, BLACK | PAWN, 0, 0, BLACK | PAWN, BLACK | PAWN, BLACK | PAWN,
//     BLACK | ROOK, BLACK | KNIGHT, BLACK | BISHOP, BLACK | QUEEN, BLACK | KING, BLACK | BISHOP, BLACK | KNIGHT, BLACK | ROOK
// };

/*
    The pieces will be encoded with 5 bits, where the 3 rightmost bits are the piece type and the 2 leftmost bits are the color.
*/

void printBoard()
{
    for (int i = 0; i < 64; i++)
    {
        if (i % 8 == 0 && i != 0)
        {
            std::cout << std::endl;
        }
        std::cout << (board[i]) << " ";
    }
    std::cout << std::endl;
}

int legalMoves(int chessboard[])
{
    int movecount = 0;

    return 0;
}

void loadFromFenString(std::string filePath)
{

    std::ifstream file(filePath); // Replace with your file path
    std::string line;

    if (file.is_open())
    {
        if (std::getline(file, line))
        {
            // Successfully read a line
            std::cout << "The line is: " << line << std::endl;
        }
        else
        {
            // File is empty or other read error occurred
            std::cout << "No line read from the file." << std::endl;
        }
        file.close(); // Close the file
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }

    int piececolor;
    int piece = 0;
    int currentSquare = A1;
    int lineIndex = 0;
    for (; lineIndex < line.length(); lineIndex++)
    {
        char c = line[lineIndex];
        if (c == '/')
        {
            continue;
        }
        else if (std::isdigit(c))
        {
            currentSquare += (c - '0');
            continue;
        }
        else if (std::isupper(c))
        {
            piececolor = Color::WHITE;
            piece = pieceMap.at(c);
            board[currentSquare] = (piece | piececolor);
            currentSquare++;
        }
        else if (std::islower(c))
        {
            piececolor = Color::BLACK;
            piece = pieceMap.at(c);
            board[currentSquare] = (piece | piececolor);
            currentSquare++;
        }
        else
        {
            std::cout << c << std::endl;
            break;
        }
    }
    printBoard();
    std::cout << "Done" << line[lineIndex] << std::endl;
}

int main()
{
    Board chessboard;
    std::string black_enPassantFen = "rnbqkbnr/pppppppp/8/8/3pP3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 2";

    std::string white_enPassantFen = "rnbqkbnr/ppp1pppp/8/3pP4/8/8/PPPP1PPP/RNBQKBNR w KQkq d6 0 1";
    chessboard.setBoard(black_enPassantFen);

    std::vector<Move> moves = chessboard.possibleMoves();

    for (int i = 0; i < moves.size(); i++)
    {
        int from = moves[i].from;
        int to = moves[i].to;
        Square fromSquare = Square(from);
        Square toSquare = Square(to);
        std::cout << "from " << SquaretoString(fromSquare) << " to " << SquaretoString(toSquare) << std::endl;
    }

    chessboard.printBoard();
    // std::cout << SquaretoString(static_cast<Square>(chessboard.enPassantSquare)) << " test" << std::endl;

    return 0;
}