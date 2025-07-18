// Include the source files for three different Rubik's Cube implementations
#include "Prototype/RubiksCube3dArray.cpp"
#include "Prototype/RubiksCube1dArray.cpp"
#include "Prototype/RubiksCubeBitboard.cpp"




#include "Solver/DFSSolver.h"


// Bring the entire C++ Standard Library namespace into scope
using namespace std;

// Main function, the entry point of the program
int main() {


//    // Object Creation and Printing for RubiksCube3dArray
    // RubiksCube3dArray Objectof3darray;
    // Objectof3darray.print();
//
//    // Object Creation and Printing for RubiksCube1dArray
//    RubiksCube1dArray Objectof1darray;
//    Objectof1darray.print();
//
//    // Object Creation and Printing for RubiksCubeBitboard
//    RubiksCubeBitboard ObjectofBitboard;
//    ObjectofBitboard.print();
//
//// Testing for RubiksCube3dArray
//
//    if(Objectof3darray.isSolved()) cout << "SOLVED\n";
//    else cout<< "NOT SOLVED\n";
//
//    // Generate random shuffle moves and print them for RubiksCube3dArray
    // vector<RubiksCube::MOVE> movesToShuffle3dArray = Objectof3darray.randomShuffleCube(2);
    // for (auto move: movesToShuffle3dArray)
    // {
    //     cout << Objectof3darray.getMove(move) << " ";
    // }
    // cout << "\n";
//
//    // Print the cube's state after shuffling and check if it's solved
    // Objectof3darray.print();
    // if(Objectof3darray.isSolved()) cout << "SOLVED\n";
    // else cout<< "NOT SOLVED\n";
//
////  (( Testing for RubiksCube1dArray ))
//
//    if(Objectof1darray.isSolved()) cout << "SOLVED\n";
//    else cout<< "NOT SOLVED\n";
//
//    // Generate random shuffle moves and print them for RubiksCube1dArray
//    vector<RubiksCube::MOVE> movesToShuffle1dArray = Objectof1darray.randomShuffleCube(2);
//    for (auto move: movesToShuffle1dArray)
//    {
//        cout << Objectof1darray.getMove(move) << " ";
//    }
//    cout << "\n";
//
//    // Print the cube's state after shuffling and check if it's solved
//    Objectof1darray.print();
//    if(Objectof1darray.isSolved()) cout << "SOLVED\n";
//    else cout<< "NOT SOLVED\n";
//
////  (( Testing for RubiksCubeBitboard ))
//
//    if(ObjectofBitboard.isSolved()) cout << "SOLVED\n";
//    else cout<< "NOT SOLVED\n";
//
//    // Generate random shuffle moves and print them for RubiksCubeBitboard
//    vector<RubiksCube::MOVE> movesToShuffleBitboard = ObjectofBitboard.randomShuffleCube(3);
//    for (auto move: movesToShuffleBitboard)
//    {
//        cout << ObjectofBitboard.getMove(move) << " ";
//    }
//    cout << "\n";
//
//    // Print the cube's state after shuffling and check if it's solved
//    ObjectofBitboard.print();
//    if(ObjectofBitboard.isSolved()) cout << "SOLVED\n";
//    else cout<< "NOT SOLVED\n";


    // TESTING DFS SOLVER ----------------------------------------------------------------------------------------

    RubiksCube3dArray cube;
    cube.print();

    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(1);

    cout << "Shuffled moves: ";
    for (auto move : shuffle_moves)
        cout << cube.getMove(move) << " ";
    cout << "\n";

    cube.print();

    DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 10);
    cout << "Solver created\n";

    vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
    cout << "Solution size: " << solve_moves.size() << "\n";

    for (auto move : solve_moves)
        cout << cube.getMove(move) << " ";
    cout << "\n";

    dfsSolver.rubiksCube.print();

    cout << "Done! Press Enter to exit...\n";
    cin.get(); // to hold console

}
