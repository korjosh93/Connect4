#include "board.h"

Board::Board() {

    for (int i = 0; i < NUM_ROWS; i++){
        for (int j = 0; j < NUM_COLS; j++){
            
             data[i][j] = Empty;
        }
    }
    
    nextPlayer_to_move = Player1;
}

Board::Board(const string &fen) {
    // Requires: a legal FEN string (i.e. you do not need to check for bad input)
    // Modifies: private data members
    // Effects: Constructs a board using a "fen" string.
    // Difficulty: Medium-Hard
    // Topics: class constructors, string parsing, testing
    
    //Example: fen = 7/7/7/7/7/7 x
    //Example 2: 2x4/7/7/7/7/7 o
    //Example 3: 2x1oo1/2x4/7/7/7/7 x
    
    //create
    for (int i = 0; i < NUM_ROWS; i++){
        for (int j = 0; j < NUM_COLS; j++){
           
            data[i][j] = Empty;
        }
    }
    
    int rowMoved = 0;
    int colMoved = 0;
    //how to move according to number fen[i]
    
    for (int i = 0; i < fen.length(); i++){
        
        if (fen[i] >= '1' && fen[i] <= '7'){
            for (int j = 0; j < fen[i]; j++){
                rowMoved++;
            }
        }
        else if (fen[i] == '/'){
            colMoved++;
            rowMoved = 0;
        }
        else if (fen[i] == PLAYER1_TOKEN){
            rowMoved++;
            data[rowMoved][colMoved] = Player1;
            
        }
        else if (fen[i] == PLAYER2_TOKEN){
            rowMoved++;
            data[rowMoved][colMoved] = Player2;
            
        }
    }
}

void Board::printBoard_as_FENstring(ostream &os) const {
    // Requires: os has been opened
    // Effects: Prints the board as a "fen" string (described in spec), to the specified
    //          stream. This allows games to be saved to files.
    // Difficulty: Hard
    // Topics: array traversal, nested loops, streams
    //os - print information along the line.
    

    int countEmpty = 0;
    
    for (int row = 0; row < NUM_ROWS; row++){
        for (int col = 0; col < NUM_COLS; col++){
            
            if (data[row][col] == Empty){
                
                for (int i = col; i < NUM_COLS; i++){
                    if (data[row][i] == Empty){
                        countEmpty++;
                    }
                }
                
                os << countEmpty;
            }
            else if (data[row][col] == Player1){
                os << PLAYER1_TOKEN;
                
            }
            else if (data[row][col] == Player2){
                os << PLAYER2_TOKEN;
            }
            if (col == NUM_COLS - 1){
                os << '/';
            }
            
            
        }
    }
    
}

PieceType Board::atLocation(int row, int col) {
  
    return data[row][col];
}

void Board::prettyPrintBoard(ostream &os) const {
	os << endl;
    for (int row = NUM_ROWS - 1; row >= 0; row--)  {
        os << "     +---+---+---+---+---+---+---+"
           << endl
           << "    ";
        
        for (int col = 0; col < NUM_COLS; col++)   {
            os << " | " ;
            if ( data[row][col] == Player1)
                os <<  PLAYER1_TOKEN;
            else if (data[row][col] == Player2)
                os << PLAYER2_TOKEN;
            else
                os << EMPTY_TOKEN;
        }
        os << " |" << endl;
    }
    os << "     +---+---+---+---+---+---+---+" << endl
       <<"  col  1   2   3   4   5   6   7" << endl;
    return;
}

PieceType Board::atLocation(int row, int col) {
    return data[row][col];
}

int Board::toMove() const {
    // Effects: Returns the player to move (1 for player 1, 2 for player 2)
    // Difficulty: Easy
    // Topics: member functions
    return 1;
}

Result Board::makeMove(int col) {
    // Modifies: private data members
    // Effects: Makes the move, returning the appropriate result --
    //          IllegalMove, Win, Draw, NoResult. The function itself is
    //          pretty simple, as it uses several helper functions.
    // Note: parameter col represents array index
    // Difficulty: Easy-Medium
    // Topics: Use of private helper functions
    // Calls: getFirstFreeRow, updateToMove, isBoardFull, isWin
    return NoResult;
}

int Board::getFirstFreeRow(int col) const {
    // Requires: col must be inbounds of array
    // Effects: Returns the lowest row that is Empty in the column specified.
    //          Returns NUM_ROWS if there are no rows free.
    // Difficulty: Easy-Medium
    // Topics: array traversal
    return NUM_ROWS;
}

PieceType Board::updateToMove() {
    // Effects: Updates the next player to move to be the next player.
    //          Returns the old, previous player.
    //          Example: If Player 1 just moved, the next player is now Player 2,
    //          while returning Player1.
    // Difficulty: Easy
    // Topics: enums, invariant maintenance
    return Player1;
}

bool Board::isBoardFull() const {
    // Requires: there is not a win
    // Effects: Returns true iff the game is a draw, i.e.,
    //          the board is full
    // Difficulty: Easy-Medium
    // Topics: array traversal
    return false;
}

bool Board::inBounds(int row, int col) const {
    // Helper for piecesInDirection.
    // Effects: Returns true iff (row,col) is in bounds.
    // Difficulty: Easy
    // Topics: predicate functions
    return false;
}

int Board::piecesInDirection(int row, int col, int dRow, int dCol) const {
    // Requires: row and col are within bounds of the array
    // Helper function for isWin.
    // Effects: Counts the number of consecutive pieces in the direction
    //          of the vector, which are the same type as the piece at (row, col).
    //          It DOES NOT count the piece at (row, col).
    //          Returns the count
    // Difficulty: Medium
    // Topics: Array traversal (bounds checking), loop logic
    // calls: inBounds
    // sample calls:
    // int count1 = piecesInDirection(row, col, 0, -1);
    // int count2 = piecesInDirection(row, col, 1, 0);
    // Note: Thinking in terms of Cartesian coordiates,
    //       dRow is the change in the row
    //       dCol is the change in the col
    return 0;
}

bool Board::isWin(int row, int col) const {
    // Requires: row and col are within bounds of the array
    // Effects: returns true iff the piece placed at (row, col) caused a win.
    // Difficulty: Medium
    // Topics: logic/reading directions
    // Calls: piecesInDirection,
    return false;
}


