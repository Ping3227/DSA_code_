/**
 *  A simple class that implements an 8x8 game checker board with three possible values
 *  for each cell:  0, 1 or 2.
 *
 **/
 /*
 @author 			黃緯翔  Huang-wei-hsiang
 @ID 				B09204045
 @Department 		地質科學系 Geosciences
 @Affiliation 	National Taiwan University
 I put all the  inform at HashTableChained.h
 */
/**
 *  Invariants:
 *  (1) grid.length == DIMENSION.
 *  (2) for all 0 <= i < DIMENSION, grid[i].length == DIMENSION.
 *  (3) for all 0 <= i, j < DIMENSION, grid[i][j] >= 0 and grid[i][j] <= 2.
 **/
#include "iostream"
#include "CheckerBoard.h"

/**
 *  Construct a new board in which all cells are zero.
 */
CheckerBoard::CheckerBoard() {
    for (int i = 0; i < DIMENSION; i++)
        for (int j = 0; j < DIMENSION; j++)
            grid[i][j] = 0;
}

/**
 *  Set the cell (x, y) in the board to the given value mod 3.
 *  @param value to which the element should be set (normally 0, 1, or 2).
 *  @param x is the x-index.
 *  @param y is the y-index.
 *  @exception ArrayIndexOutOfBoundsException is thrown if an invalid index
 *  is given.
 **/
void CheckerBoard::setElementAt(int x, int y, int value) {
    grid[x][y] = value % 3;
    if (grid[x][y] < 0) {
        grid[x][y] += 3;
    }
}

/**
 *  Get the valued stored in cell (x, y).
 *  @param x is the x-index.
 *  @param y is the y-index.
 *  @return the stored value (between 0 and 2).
 *  @exception ArrayIndexOutOfBoundsException is thrown if an invalid index
 *  is given.
 */
int CheckerBoard::elementAt(int x, int y) {
    return grid[x][y];
}

/**
 *  Returns true if "this" CheckerBoard and "board" have identical values in
 *    every cell.
 *  @param board is the second CheckerBoard.
 *  @return true if the boards are equal, false otherwise.
 */
bool CheckerBoard::equals(const CheckerBoard& board) {
    // Replace the following line with your solution.  Be sure to return false
    //   (rather than throwing a ClassCastException) if "board" is not
    //   a CheckerBoard.
    if (typeid(board) != typeid(CheckerBoard)) return false;
    for (int i{}; i < DIMENSION; i++) {
        for (int j{}; j < DIMENSION; j++) {
            if (const_cast<CheckerBoard&>(board).elementAt(i, j) != grid[i][j]) return false;
        }
        
    }
    return true;
}

/**
 *  Returns a hash code for this CheckerBoard.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int CheckerBoard::hashCode() {
    // Replace the following line with your solution.
    int hash{};
    for (int i{}; i < DIMENSION; i++) {
        for (int j{}; j < DIMENSION; j++) {
            hash += elementAt(i, j)*(i+2);
           // hash %= 297171793;
            hash *= 31;
        }
        hash %= 629137;
        hash *= 7393917;
       
    }
    
    return hash;
}
/*for (int j{}; j < DIMENSION; j++) {
            hash += elementAt(i, j)*(i+2);
            if ((i + j) % 3 == 1)
                hash *= 137; 
            if ((i + j) % 3 == 2)
                hash *= 127;
            if ((i + j) % 3 == 0)
                hash *= 739;
        }
        hash = hash * hash;*/