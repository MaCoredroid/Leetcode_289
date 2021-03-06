//students ID:517021910070
//student name:马致远


#include <vector>
#include<algorithm>

class Solution {
public:
	void gameOfLife(std::vector<std::vector<int>>& board) 
	{
		int height = board.size();//get the height of board
		int width = board[0].size();//get the width of the board
		for (int i = 0; i < height; ++i) 
		{
			for (int j = 0; j < width; ++j) 
			{
				int count = 0;
				for (int p = std::max(i - 1, 0); p < std::min(i + 2, height); ++p)//count the alive neighbour and make sure it dosen't come over the border
				{
					for (int q = std::max(j - 1, 0); q < std::min(j + 2, width); ++q)
					{
						count += board[p][q] & 1;//if neighbour is alive(1), count++;else,do nothing
					}
				}
				
				if (count == 3 || count - board[i][j] == 3)//0->10;1->11
					board[i][j] |= 2;//if this point will be alive in next round, put an '1' on the highest position
			}
		}
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)//01->0 11->1 10->1 00->0
			{
				board[i][j] >>= 1;//shift one bit to the right so that the previously recorded state will appear
			}
		}



	}
};

