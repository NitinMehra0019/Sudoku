#include <iostream>
#include <vector>
using namespace std;


void printSudoku9x9(int arr[9][9]) {
	cout << "-------------------------" << endl;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++)
			cout << arr[y][x] << " ";
		cout << endl;
	}
	cout << "-------------------------" << endl;

}
bool isSafe(int board[9][9], int row, int col, int val){
	for(int i=0; i<9; i++){
		if(board[row][i] == val){
			return false;
		}
		if(board[i][col] == val){
			return false;
		}

		//3*3 matrix
		if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
			return false;
		}
	}
	return true;
}

bool solve(int board[9][9]){
	int n =9;
	for(int row = 0; row<n; row++){
		for(int col=0; col<9; col++){
			if(board[row][col] == 0){
				for(int val=1; val<=9; val++){
					if(isSafe(board,row,col,val)){
						board[row][col] = val;
						//Recursive call
						bool nextSolPossible = solve(board);

						if(nextSolPossible){
							return true;
						}
						else{
							//Backtrack
							board[row][col] = 0;
						}
					}
				}
				return false;
			}
		}
		return true;
	}
}


int main(int argc, char** argv)
{
	int board[9][9] = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};
	int board2[9][9] = {
		{8,0,0,0,0,0,0,0,0},
		{0,0,3,6,0,0,0,0,0},
		{0,7,0,0,9,0,2,0,0},
		{0,5,0,0,0,7,0,0,0},
		{0,0,0,0,4,5,7,0,0},
		{0,0,0,1,0,0,0,3,0},
		{0,0,1,0,0,0,0,6,8},
		{0,0,8,5,0,0,0,1,0},
		{0,9,0,0,0,0,4,0,0}
	};

	cout<<"Before Solving"<<endl;

	printSudoku9x9(board);

	
	if (solve(board)) cout << "successfully solved board!" << std::endl;
	printSudoku9x9(board);
	if (solve(board2)) cout << "successfully solved board 2!" << std::endl;
	printSudoku9x9(board2);

	return 0;
}
