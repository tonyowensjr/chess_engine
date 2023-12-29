#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <map>
#include <board.hpp>

using namespace std;

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

void printBoard() {
    for (int i = 0; i < 64; i++) {
        if (i % 8 == 0 && i != 0) {
            std::cout << std::endl;
        }
        std::cout << (board[i]) << " ";
    }
    std::cout << std::endl;
}

void loadFromFenString(std::string filePath){
    std::map<char, Piece> pieceMap {
        {'p', Piece::PAWN},
        {'n', Piece::KNIGHT},
        {'b', Piece::BISHOP},
        {'r', Piece::ROOK},
        {'q', Piece::QUEEN},
        {'k', Piece::KING},
        {'P', Piece::PAWN},
        {'N', Piece::KNIGHT},
        {'B', Piece::BISHOP},
        {'R', Piece::ROOK},
        {'Q', Piece::QUEEN},
        {'K', Piece::KING}
    };

    std::ifstream file(filePath); // Replace with your file path
    std::string line;

    if (file.is_open()) {
        if (std::getline(file, line)) {
            // Successfully read a line
            std::cout << "The line is: " << line << std::endl;
        } else {
            // File is empty or other read error occurred
            std::cout << "No line read from the file." << std::endl;
        }
        file.close(); // Close the file
    } else {
        std::cout << "Unable to open file." << std::endl;
    }

    int piececolor;
    int piece = 0;
    int currentSquare = A1;
    int lineIndex = 0;
    for (;lineIndex < line.length(); lineIndex++) {
        char c = line[lineIndex];
        if(c == '/'){
            continue;
        } else if(std::isdigit(c)){
            currentSquare += (c - '0');
            continue;
        } else if(std::isupper(c)){
            piececolor = Color::WHITE;
            piece = pieceMap.at(c);
            board[currentSquare] = (piece | piececolor);
            currentSquare++;
        } else if(std::islower(c)){
            piececolor = Color::BLACK;
            piece = pieceMap.at(c);
            board[currentSquare] = (piece | piececolor);
            currentSquare++;
        } else{
            std::cout << c << std::endl;
            break;
        }
    }
    printBoard();
    cout << "Done" << line[lineIndex] << endl;

}

int main(){
    std::string fenString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    loadFromFenString("fen_test.txt");
    return 0;
}