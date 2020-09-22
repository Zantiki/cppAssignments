//
// Created by sebastian on 04.09.2020.
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        virtual std::string short_type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
        // missing implementations


        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
            //Piece::valid_move(from_x, from_y, to_x, to_y);
            int diff_x = to_x - from_x;
            int diff_y = to_y - from_y;

            if(diff_x*diff_x == 1 && diff_y == 0){
                return true;
            }
            if(diff_y*diff_y == 1 && diff_x == 0){
                return true;
            }
            if(diff_x*diff_y == 1){
                return true;
            }
            return false;


        }

        std::string type() const{
            return this->color_string()+" King";
        }

        string short_type() const{
            string color = this->color_string();
            return string(1,color[0]) +"K ";
        }

    public:
        explicit King(ChessBoard::Color color_) : Piece(color_){}
    };

    class Knight : public Piece {

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
            //Piece::valid_move(from_x, from_y, to_x, to_y);
            int diff_x = to_x-from_x;
            int diff_y = to_y-from_y;

            if(diff_x*diff_x == 1 && diff_y*diff_y == 4  ) {
                return true;
            }
            if (diff_x*diff_x == 4 && diff_y*diff_y == 1 ){
                return true;
            }
            return false;
        }

        string short_type() const{
            string color = this->color_string();
            return string(1,color[0]) +"Kn";
        }

        std::string type() const override{
            return this->color_string()+" Knight";
        }

    public:
// missing implementations
explicit Knight(ChessBoard::Color color) : Piece(color){}
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<shared_ptr<Piece>>> squares;
    function<void(const std::string, std::string, vector<vector<shared_ptr<Piece>>>)> on_move;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        on_move(from, to, squares);
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color == piece_to->color)  {
                        return false;
                    }
                }
                piece_to = move(piece_from);
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

class ChessBoardPrint{
public:

    ChessBoard *board;

    ChessBoardPrint(ChessBoard *_board){
        this->board = _board;

        function<void(vector<vector<shared_ptr<ChessBoard::Piece>>>)> print = []( auto squares ){
            string graphical_board = "\n---------------------------------";
            for(unsigned long y = 0; y < squares.size(); y++){
                string y_str = "\n|";

                for(unsigned long x = 0; x < squares[y].size(); x++){
                    auto& cell = squares[y][x];
                    if(cell){
                        y_str += cell->short_type() + "|";
                    }else{
                        y_str += "   |";
                    }
                }
                y_str += "\n---------------------------------";
                graphical_board += y_str;
            }
            graphical_board += "\n";
            cout << graphical_board << endl;
        };

        function<void(const std::string, const std::string, vector<vector<shared_ptr<ChessBoard::Piece>>>)>
                move_piece_graphics = [](const std::string &from, const std::string &to, auto squares ){
            int from_x = from[0] - 'a';
            int from_y = stoi(string() + from[1]) - 1;
            int to_x = to[0] - 'a';
            int to_y = stoi(string() + to[1]) - 1;
            auto &piece_from = squares[from_x][from_y];
            if (piece_from) {
                if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                    cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
                    auto &piece_to = squares[to_x][to_y];
                    if (piece_to) {
                        if (piece_from->color != piece_to->color) {
                            cout << piece_to->type() << " is being removed from " << to << endl;
                            if (auto king = dynamic_cast<ChessBoard::King *>(piece_to.get()))
                                cout << king->color_string() << " lost the game" << endl;
                        } else {
                            // piece in the from square has the same color as the piece in the to square
                            cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                            return;
                        }
                    }
                    return;
                } else {
                    cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                    return;
                }
            } else {
                cout << "no piece at " << from << endl;
                return;
            }
            cout << "Should have printed" << endl;
        };
       _board->on_move = [&print, &move_piece_graphics](const std::string &from, const std::string &to, auto squares ){
           cout << "Called" << endl;
           print(squares);
           //move_piece_graphics(from, to, squares);
        };


    };

};

int main() {
    ChessBoard board;

    // Todo: segfault at function calls in on_move;
    ChessBoardPrint printer(&board);
    //vector<vector<shared_ptr<ChessBoard::Piece>>> squares;
    //board.on_move("e3", "e2", squares);

    board.squares[4][0] = make_shared<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_shared<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_shared<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_shared<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_shared<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_shared<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");

}