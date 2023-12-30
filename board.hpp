#ifndef BOARD_HPP
#define BOARD_HPP

#include <cctype>
#include <map>
#include <string>
#include <vector>

enum Color
{
    WHITE = 8,
    BLACK = 16
};

enum Piece
{
    PAWN = 1,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

const int PIECE_OFFSET = 7;

enum Square
{
    A1,
    B1,
    C1,
    D1,
    E1,
    F1,
    G1,
    H1,
    A2,
    B2,
    C2,
    D2,
    E2,
    F2,
    G2,
    H2,
    A3,
    B3,
    C3,
    D3,
    E3,
    F3,
    G3,
    H3,
    A4,
    B4,
    C4,
    D4,
    E4,
    F4,
    G4,
    H4,
    A5,
    B5,
    C5,
    D5,
    E5,
    F5,
    G5,
    H5,
    A6,
    B6,
    C6,
    D6,
    E6,
    F6,
    G6,
    H6,
    A7,
    B7,
    C7,
    D7,
    E7,
    F7,
    G7,
    H7,
    A8,
    B8,
    C8,
    D8,
    E8,
    F8,
    G8,
    H8,
};

const int printArray[] = {
    A8,
    B8,
    C8,
    D8,
    E8,
    F8,
    G8,
    H8,
    A7,
    B7,
    C7,
    D7,
    E7,
    F7,
    G7,
    H7,
    A6,
    B6,
    C6,
    D6,
    E6,
    F6,
    G6,
    H6,
    A5,
    B5,
    C5,
    D5,
    E5,
    F5,
    G5,
    H5,
    A4,
    B4,
    C4,
    D4,
    E4,
    F4,
    G4,
    H4,
    A3,
    B3,
    C3,
    D3,
    E3,
    F3,
    G3,
    H3,
    A2,
    B2,
    C2,
    D2,
    E2,
    F2,
    G2,
    H2,
    A1,
    B1,
    C1,
    D1,
    E1,
    F1,
    G1,
    H1,
};

// map from square to string
std::string SquaretoString(Square c)
{
    switch (c)
    {
    case A1:
        return "A1";
    case B1:
        return "B1";
    case C1:
        return "C1";
    case D1:
        return "D1";
    case E1:
        return "E1";
    case F1:
        return "F1";
    case G1:
        return "G1";
    case H1:
        return "H1";
    case A2:
        return "A2";
    case B2:
        return "B2";
    case C2:
        return "C2";
    case D2:
        return "D2";
    case E2:
        return "E2";
    case F2:
        return "F2";
    case G2:
        return "G2";
    case H2:
        return "H2";
    case A3:
        return "A3";
    case B3:
        return "B3";
    case C3:
        return "C3";
    case D3:
        return "D3";
    case E3:
        return "E3";
    case F3:
        return "F3";
    case G3:
        return "G3";
    case H3:
        return "H3";
    case A4:
        return "A4";
    case B4:
        return "B4";
    case C4:
        return "C4";
    case D4:
        return "D4";
    case E4:
        return "E4";
    case F4:
        return "F4";
    case G4:
        return "G4";
    case H4:
        return "H4";
    case A5:
        return "A5";
    case B5:
        return "B5";
    case C5:
        return "C5";
    case D5:
        return "D5";
    case E5:
        return "E5";
    case F5:
        return "F5";
    case G5:
        return "G5";
    case H5:
        return "H5";
    case A6:
        return "A6";
    case B6:
        return "B6";
    case C6:
        return "C6";
    case D6:
        return "D6";
    case E6:
        return "E6";
    case F6:
        return "F6";
    case G6:
        return "G6";
    case H6:
        return "H6";
    case A7:
        return "A7";
    case B7:
        return "B7";
    case C7:
        return "C7";
    case D7:
        return "D7";
    case E7:
        return "E7";
    case F7:
        return "F7";
    case G7:
        return "G7";
    case H7:
        return "H7";
    case A8:
        return "A8";
    case B8:
        return "B8";
    case C8:
        return "C8";
    case D8:
        return "D8";
    case E8:
        return "E8";
    case F8:
        return "F8";
    case G8:
        return "G8";
    case H8:
        return "H8";
    }
    return ""; // Default case
}

std::string PieceToString(int square)
{
    switch (square)
    {
    case 9:
        return "P";
    case 17:
        return "p";
    case 10:
        return "N";
    case 18:
        return "n";
    case 11:
        return "B";
    case 19:
        return "b";
    case 12:
        return "R";
    case 20:
        return "r";
    case 13:
        return "Q";
    case 21:
        return "q";
    case 14:
        return "K";
    case 22:
        return "k";
    default:
        return ".";
    }
    return ""; // Default case
}

struct Move
{
    int from;     // Square from which the piece is moving
    int to;       // Square to which the piece is moving
    int piece;    // Piece that is moving
    int captured; // Piece that is captured
    int promoted; // Piece that is promoted
};

class Board
{
public:
    int board[64];           // Represents the chessboard
    Color whoToMove = WHITE; // Indicates whose move it is

    int enPassantSquare = -1; // Indicates the square where an en passant capture is possible

    // Castling rights
    bool whiteksc = true;
    bool whiteqsc = true;
    bool blackksc = true;
    bool blackqsc = true;

    // map from square to string
    const std::map<char, Piece> pieceMap = {
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
        {'K', Piece::KING}};

    Board()
    {
        // Initialize the board with all zeros
        for (int i = 0; i < 64; ++i)
        {
            board[i] = 0; // 0 might represent an empty square
        }
    }

    // Function to print the board to the console
    void printBoard()
    {
        for (int i = 0; i < 64; ++i)
        {
            std::cout << PieceToString(board[printArray[i]]) << " ";
            if ((i + 1) % 8 == 0)
            { // Newline every 8 numbers for 8x8 structure
                std::cout << std::endl;
            }
        }
    }

    void setBoard(std::string fenString)
    {
        int piececolor;
        int currentSquare;
        int piece = 0;
        int currentSquareInd = 0;
        int lineIndex = 0;
        for (; lineIndex < fenString.length(); lineIndex++)
        {
            currentSquare = printArray[currentSquareInd];
            char c = fenString[lineIndex];
            if (c == '/')
            {
                continue;
            }
            else if (std::isdigit(c))
            {
                currentSquareInd += (c - '0');
                continue;
            }
            else if (std::isupper(c))
            {
                piececolor = Color::WHITE;
                piece = pieceMap.at(c);
                board[currentSquare] = (piece | piececolor);
                currentSquareInd++;
            }
            else if (std::islower(c))
            {
                piececolor = Color::BLACK;
                piece = pieceMap.at(c);
                board[currentSquare] = (piece | piececolor);
                currentSquareInd++;
            }
            else
            {
                break;
            }
        }

        whoToMove = (fenString[++lineIndex] == 'w') ? Color::WHITE : Color::BLACK;

        lineIndex += 2;
        while (fenString[lineIndex] != ' ')
        {
            switch (fenString[lineIndex])
            {
            case 'K':
                blackksc = true;
                break;
            case 'Q':
                blackqsc = true;
                break;
            case 'k':
                whiteksc = true;
                break;
            case 'q':
                whiteqsc = true;
                break;
            case '-':
                blackksc = false;
                blackqsc = false;
                whiteksc = false;
                whiteqsc = false;
                break;
            default:
                break;
            }
            lineIndex++;
        }
        lineIndex++;
        if (fenString[lineIndex] != '-')
        {
            int file = fenString[lineIndex] - 'a';
            int rank = fenString[lineIndex + 1] - '0';

            // int square =

            if (whoToMove == Color::WHITE)
            {
                rank--;
            }
            else
            {
                rank++;
            }

            Square epSquare = static_cast<Square>((file) + ((rank - 1) * 8));
            // std::cout << "En Passant = " << SquaretoString(epSquare) << std::endl;
            enPassantSquare = epSquare;
        }
        else
        {
            enPassantSquare = -1;
        }
        lineIndex++;
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

        setBoard(line);
    }

    std::vector<Move> possibleMoves()
    {
        std::vector<Move> moves;
        for (int square = A1; square <= H8; square++)
        {
            // Skip the square if the square is empty or the piece is not the color of the player whose turn it is
            if (board[square] == 0 || (board[square] & whoToMove) == 0)
            {
                continue;
            }
            else
            {
                switch (board[square] & PIECE_OFFSET)
                {
                case Piece::PAWN:
                    if (whoToMove == Color::WHITE)
                    {
                        // moving a white pawn one square forward
                        if (board[square + 8] == 0)
                        {
                            moves.push_back({square, square + 8, Piece::PAWN, 0, 0});
                            // if the pawn is on the second rank, it can move two squares forward
                            if ((square < A3 && square > H1) && board[square + 16] == 0)
                            {
                                // pawn can now be captured en passant
                                moves.push_back({square, square + 16, Piece::PAWN, 0, 0});
                                // enPassantSquare = square + 16;
                            }
                        }
                        // capturing a piece provided it is the opposite color and not on the 1st rank
                        if (board[square + 7] != 0 && ((board[square + 7] & Color::BLACK) != 0) && (square % 8 != 0))
                        {
                            moves.push_back({square, square + 7, Piece::PAWN, board[square + 7], 0});
                        }
                        // capturing a piece provided it is the opposite color and not on the 8th rank
                        if (board[square + 9] != 0 && ((board[square + 9] & Color::BLACK) != 0) && (square % 8 != 7))
                        {
                            moves.push_back({square, square + 9, Piece::PAWN, board[square + 9], 0});
                        }
                        // capturing en passant if the en passant square is occupied by a black pawn and the white pawn is not on the 8th rank
                        if ((board[enPassantSquare] & Color::BLACK) != 0 && board[enPassantSquare] == board[square + 1] && (square % 8 != 7))
                        {
                            moves.push_back({square, enPassantSquare + 8, Piece::PAWN, board[enPassantSquare], 0});
                        }
                        // capturing en passant if the en passant square is occupied by a black pawn and the white pawn is not on the 1st rank
                        if ((board[enPassantSquare] & Color::BLACK) != 0 && board[enPassantSquare] == board[square - 1] && (square % 8 != 0))
                        {
                            moves.push_back({square, enPassantSquare + 8, Piece::PAWN, board[enPassantSquare], 0});
                        }
                    }
                    else
                    {
                        // moving a black pawn one square forward
                        if (board[square - 8] == 0)
                        {
                            moves.push_back({square, square - 8, Piece::PAWN, 0, 0});
                            // if the pawn is on the seventh rank, it can move two squares forward
                            if ((square < A8 && square > H6) && board[square - 16] == 0)
                            {
                                moves.push_back({square, square - 16, Piece::PAWN, 0, 0});
                                // enPassantSquare = square - 16;
                            }
                        }
                        // capturing a piece provided it is the opposite color and not on the 8th rank
                        if (board[square - 7] != 0 && ((board[square - 7] & Color::WHITE) != 0) && (square % 8 != 7))
                        {
                            moves.push_back({square, square - 7, Piece::PAWN, board[square - 7], 0});
                        }
                        // capturing a piece provided it is the opposite color and not on the 1st rank
                        if (board[square - 9] != 0 && ((board[square - 9] & Color::WHITE) != 0) && (square % 8 != 0))
                        {
                            moves.push_back({square, square - 9, Piece::PAWN, board[square - 9], 0});
                        }
                        // capturing en passant if the en passant square is occupied by a white pawn and the black pawn is not on the 8th rank
                        if ((board[enPassantSquare] & Color::WHITE) != 0 && board[enPassantSquare] == board[square + 1] && (square % 8 != 7))
                        {
                            moves.push_back({square, enPassantSquare - 8, Piece::PAWN, board[enPassantSquare], 0});
                        }
                        // capturing en passant if the en passant square is occupied by a white pawn and the black pawn is not on the 1st rank
                        if ((board[enPassantSquare] & Color::WHITE) != 0 && board[enPassantSquare] == board[square - 1] && (square % 8 != 0))
                        {
                            moves.push_back({square, enPassantSquare - 8, Piece::PAWN, board[enPassantSquare], 0});
                        }
                    }
                    // enPassantSquare = -1;
                    break;
                case Piece::KNIGHT:
                    // enPassantSquare = -1;
                    break;
                case Piece::BISHOP:
                    // enPassantSquare = -1;
                    break;
                case Piece::ROOK:
                    // enPassantSquare = -1;
                    break;
                case Piece::QUEEN:
                    // enPassantSquare = -1;
                    break;
                case Piece::KING:
                    // enPassantSquare = -1;
                    break;
                }
            }
        }
        return moves;
    }
};

// map from string to piece
const std::map<char, Piece> pieceMap = {
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
    {'K', Piece::KING}};

// void printBoard();

void loadFromFenString(std::string filePath);

int legalMoves(int chessboard[]);

#endif