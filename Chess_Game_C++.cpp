#include <iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

void chess_board(char board[8][8]);
void start();
void Display_menu();
void Selected_choice();
void Printing_number();

int main()
{
	start();
}

void Print_number()
	{
    cout << "    ";
    for (int i = 0; i < 8; i++) {
        cout << i << "   ";
    }
    cout << endl;
}

void start()
{
	char choice;
	
	cout<<" Press Y or y to Start the Game: ";
	cin>>choice;
	if(choice=='Y' || choice=='y')
	{
		Display_menu();
	}
	else
	{
		cout<<" Wrong Entry... \n Start again..";
		exit(0);
	}
		
	Selected_choice();
}

void Display_menu()
{
	cout<<" Choose your piece from the Given Menu: "<<endl;
		cout<<"==--Pieces--=="<<endl;
		cout<<"1.|Queen |"<<endl;
		cout<<"2.|Bishop|"<<endl;
		cout<<"3.|Rock  |"<<endl;
		cout<<"4.|Knight|"<<endl;
		cout<<"5.|Exit  |"<<endl;	
		cout<<"-------------"<<endl;
}

void chess_board(char board[8][8])
{
		 Print_number();
	  for (int i = 0; i < 8; i++) {
        cout << "------------------------------------" << endl;
        cout << i  << "  ";
        for (int j = 0; j < 8; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
    }

    cout << "------------------------------------" << endl;

}

bool check(int q_row, int q_col, int k_row, int k_col) {
    
    if (q_row == k_row || q_col == k_col || abs(q_row - k_row) == abs(q_col - k_col)) {
        return true; // The king is in check
    }
    return false; // The king is not in check
}


bool mate(int q_row, int q_col, int k_row, int k_col) {
    
    if (check(q_row, q_col, k_row, k_col)) {
    
        for (int i = k_row-1; i <= k_row+1; i++) {
            for (int j = k_col-1; j <= k_col+1; j++) {
                if (i >= 0 && i <= 7 && j >= 0 && j <= 7 && !(i == k_row && j == k_col)) {
                    if (!check(q_row, q_col, i, j)) {
                        return false; // The king is not in checkmate
                    }
                }
            }
        }
        return true; // The king is in checkmate
    }
    return false; // The king is not in check
}


void Selected_choice()
{
		int r1,c1;
		int row,col,row1,col1;
		int choice;
	// char piece;
	
		char board1[8][8]=
		{
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
		};
		
		 
		chess_board(board1);
		cout<<" Enter your Piece number: ";
		cin>>choice;
		if(choice==5)
		{
			cout<<" You Quit the Game... (: "; 
			exit(0);
		}	
		
		while(true)
		{
		switch(choice)
{
    case 1:
        cout<<" Enter the row (0-7) of the starting position for Queen: ";
        cin>>row;
        cout<<" Enter the column (0-7) of the starting position for Queen: ";
        cin>>col;
        break;
    case 2:
        cout<<" Enter the row (0-7) of the starting position for Bishop(a): ";
        cin>>row;
        cout<<" Enter the column (0-7) of the starting position for Bishop(a): ";
        cin>>col;
        cout<<" Enter the row (0-7) of the starting position for Bishop(b): ";
        cin>>row1;
        cout<<" Enter the column (0-7) of the starting position for Bishop(b): ";
        cin>>col1;
        break;
    case 3:
        cout<<" Enter the row (0-7) of the starting position for Rook(a): ";
        cin>>row;
        cout<<" Enter the column (0-7) of the starting position for Rook(a): ";
        cin>>col;
        cout<<" Enter the row (0-7) of the starting position for Rook(b): ";
        cin>>row1;
        cout<<" Enter the column (0-7) of the starting position for Rook(b): ";
        cin>>col1;
        break;
    case 4:
        cout<<" Enter the row (0-7) of the starting position for Knight(a): ";
        cin>>row;
        cout<<" Enter the column (0-7) of the starting position for Knight(a): ";
        cin>>col;
        cout<<" Enter the row (0-7) of the starting position for Knight(b): ";
        cin>>row1;
        cout<<" Enter the column (0-7) of the starting position for Knight(b): ";
        cin>>col1;
        break;
    default:
        cout<<" Invalid Entry...? "<<endl;
        break;
}
	
do
{
    if(row>7 || row<0 || col>7 || col<0)
    {
        cout<<" Invalid entry.. \n Enter the values again: "<<endl;
        cout<<" Enter the row (0-7) of the starting position: ";
        cin>>row;
        cout<<" Enter the column (0-7) of the starting position: ";
        cin>>col;
    }
}
while(row>7 || row<0 || col>7 || col<0);

		char board[8][8]=
		{
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
		};
		
		unsigned seed=time(0);
		srand(seed);
		int r1; //=rand()%7+1;
		int	c1; //=rand()%7+1;
		// For the movement of the king
		cout<<" Enter the row (0-7) of the starting position for King: ";
        cin>>r1;
        cout<<" Enter the column (0-7) of the starting position for King: ";
        cin>>c1;
		for (int i = r1-1; i <= r1+1; i++) {
                for (int j = c1-1; j <= c1+1; j++) {
                    if (i >= 0 && i <= 7 && j >= 0 && j <= 7 && (i != r1 || j != c1))
					{
                        board[i][j]='*';
                    }
                }  		
            }
		board[r1][c1]='K';
		
		// For the Queen
		cout<<"===--> Current Position <--=== "<<endl;
		cout << " Current Position: " <<"["<< row << "," << col <<"]"<< endl;
		cout<<"===------------------------=== "<<endl;
		if(choice==1)
		{
		for(int i=row-1; i>=0; i--)
		{
			if (board[i][col]==' ')
			{
				board[i][col]='.';
			}
			else if ( board[i][col]=='*' ||board[i][col]=='K')
			{
				break;
			}		
			else
			{
				board[i][col]=='.';
				break;
			}
		}
		
		// For lower half of vertical direction
		for(int i=row+1; i<8; i++)
		{
			if(board[i][col]==' ')
			{
				board[i][col]=='.';
			}
			else if (board[i][col]=='*' || board[i][col]=='K')
			{
				break;
			}
			else
			{
				board[i][col]='.';
			}
		}
		// For first half of the horizontal line
		for(int j=col+1; j<8; j++)
		{
			if(board[row][j]==' ')
			{
				board[row][j]='.';
			}
			else if (board[row][j]=='*' || board[row][j]=='K')
			{
				break;
			}
			else
			{
				board[row][j]='.';
				break;
			}
		}
		// For second half of the horizontal line
		for(int j=col-1; j>=0; j--)
		{
			if(board[row][j]==' ')
			{
				board[row][j]='.';
			}
			else if (board[row][j]=='*'|| board[row][j]=='K')
			{
				break;
			}
			else 
			{
				board[row][j]='.';
			}
		}
	
	// For diagonal possible moves of the queen
	// For printing 1st uppper half of the diagonal 
	for(int i=row-1, j=col+1; i>=0 && j<8; i--, j++)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='*' || board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
			break;
		}
	}
	// For printing 2nd upper half of the diagonal
	for(int i=row+1, j=col-1; i<8 && j>=0; i++, j--)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='*'|| board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
			break;
		}
	}
	// For printing 3rd half of the diagonal 
	for(int i=row-1, j=col-1; i>=0 && j>=0; i-- ,j--)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='*' || board[i][j]=='K')
		{
				break;
		}
		else
		{
			board[i][j]='.';
		}
	}
	// For 4th half of the diagonal
	for(int i=row+1, j=col+1; i<8 && j<8; i++ ,j++)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='*' || board[i][j]=='K')
		{
				break;
		}
		else
		{
			board[i][j]='.';
		}
	}
			board[row][col]='Q';
			
		// Moves for the check mate for queen
			if (check(row, col,r1 , c1)) {
				cout<<"=====--> Check <--====="<<endl;
        cout << "The king is in check" << endl;
        	cout<<"------> Check <-------"<<endl;
        if (mate(row, col, r1, c1)) {
        	cout << "The king is in checkmate" << endl;
        	cout<<" Congratulations...:)";
        	cout<<" Player 2 Won the Game.."<<endl;
            break;
        }
    }
    else {
    	cout<<"======---> Safe <---======"<<endl;
        cout << "The king is not in check" << endl;
        cout<<"---------> Safe <---------"<<endl;
    }
	}
		// For bishoop moves 	
	
		else if(choice==2)
		{	
		for(int i=row-1, j=col+1; i>=0 && j<8; i--, j++)
		{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
			break;
		}
	}
	// For printing 2nd upper half of the diagonal
	for(int i=row+1, j=col-1; i<8 && j>=0; i++, j--)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
			break;
		}
	}
	// For printing 3rd half of the diagonal 
	for(int i=row-1, j=col-1; i>=0 && j>=0; i-- ,j--)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
		}
	}
	// For 4th half of the diagonal
	for(int i=row+1, j=col+1; i<8 && j<8; i++ ,j++)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
		}
	}
	bool Check = false;

    // Check the upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++)
    {
        if (board[i][j] == ' ')
        {
            board[i][j] = '.';
        }
        else if (board[i][j] == 'K')
        {
            cout << "King is in check!" << endl;
            Check = true;
            break;
        }
        else
        {
            break;
        }
    }

    // Check the upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == ' ')
        {
            board[i][j] = '.';
        }
        else if (board[i][j] == 'K')
        {
            cout << "King is in check!" << endl;
            Check = true;
            break;
        }
        else
        {
            break;
        }
    }

    // Check the lower-right diagonal
    for (int i = row + 1, j = col + 1; i < 8 && j < 8; i++, j++)
    {
        if (board[i][j] == ' ')
        {
            board[i][j] = '.';
        }
        else if (board[i][j] == 'K')
        {
            cout << "King is in check!" << endl;
            Check = true;
            break;
        }
        else
        {
            break;
        }
    }

    // Check the lower-left diagonal
    for (int i = row + 1, j = col - 1; i < 8 && j >= 0; i++, j--)
    {
        if (board[i][j] == ' ')
        {
            board[i][j] = '.';
        }
        else if (board[i][j] == 'K')
        {
            cout << "King is in check!" << endl;
            Check = true;
            break;
        }
        else
        {
            break;
        }
    }
   
	

	// For Second bishop
	for(int i=row1-1, j=col1+1; i>=0 && j<8; i--, j++)
		{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='*' || board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
			break;
		}
		}
		
		
	// For printing 2nd upper half of the diagonal
	for(int i=row1+1, j=col1-1; i<8 && j>=0; i++, j--)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='*'|| board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
			break;
		}
	}
	// For printing 3rd half of the diagonal 
	for(int i=row1-1, j=col1-1; i>=0 && j>=0; i-- ,j--)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='*'|| board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
		}
	}
	// For 4th half of the diagonal
	for(int i=row1+1, j=col1+1; i<8 && j<8; i++ ,j++)
	{
		if(board[i][j]==' ')
		{
			board[i][j]='.';
		}
		else if (board[i][j]=='*' || board[i][j]=='K')
		{
			break;
		}
		else
		{
			board[i][j]='.';
		}
		
	}
			board[row][col]='B';
			board[row1][col1]='b';
			
			// Check the upper-left diagonal
    for (int i = row1 - 1, j = col1 - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == ' ')
        {
            board[i][j] = '.';
        }
        else if (board[i][j] == 'K')
        {
            cout << "King is in check!" << endl;
            Check = true;
            break;
        }
        else
        {
            break;
        }
    }

    // Check the lower-right diagonal
    for (int i = row1 + 1, j = col1 + 1; i < 8 && j < 8; i++, j++)
    {
        if (board[i][j] == ' ')
        {
            board[i][j] = '.';
        }
        else if (board[i][j] == 'K')
        {
            cout << "King is in check!" << endl;
            Check = true;
            break;
        }
        else
        {
            break;
        }
    }

    // Check the lower-left diagonal
    for (int i = row1 + 1, j = col1 - 1; i < 8 && j >= 0; i++, j--)
    {
        if (board[i][j] == ' ')
        {
            board[i][j] = '.';
        }
        else if (board[i][j] == 'K')
        {
            cout << "King is in check!" << endl;
            Check = true;
            break;
        }
        else
        {
            break;
        }
    }
}	
    		// for  The Rook Movement
			else if(choice==3)
			{
			for(int i=row-1; i>=0; i--)
			{
			if (board[i][col]==' ')
			{
				board[i][col]='.';
			}
			else if (board[i][col]=='*' || board[i][col]=='K' )
			{
			break;
			}
			else
			{
				board[i][col]='.';
				break;
			}
		}
		// For lower half of vertical direction
		for(int i=row+1; i<8; i++)
		{
			if(board[i][col]==' ')
			{
				board[i][col]='.';
			}
			else if (board[i][col]=='*' || board[i][col]=='K')
			{
			break;
			}
			else
			{
				board[i][col]='.';
			}
		}
		// For first half of the horizontal line
		for(int j=col+1; j<8; j++)
		{
			if(board[row][j]==' ')
			{
				board[row][j]='.';
			}
			else if (board[row][j]=='*' || board[row][j]=='K' )
			{
			break;
			}
			else
			{
				board[row][j]='.';
				break;
			}
		}
		// For second half of the horizontal line
		for(int j=col-1; j>=0; j--)
		{
			if(board[row][j]==' ')
			{
				board[row][j]='.';
			}
			else if (board[row][j]=='*' || board[row][j]=='K')
			{
			break;
			}
			else 
			{
				board[row][j]='.';
			}
		}
		
		
		// Check for check
		bool Check_for_Rook = false;
		
		// Check vertically
		for (int i = row - 1; i >= 0; i--) {
		    if (board[i][col] == 'K') {
		        Check_for_Rook = true;
		        break;
		    } else if (board[i][col] != ' ') {
		        break;
		    }
		}
		
		for (int i = row + 1; i < 8; i++) {
		    if (board[i][col] == 'K') {
		        Check_for_Rook = true;
		        break;
		    } else if (board[i][col] != ' ') {
		        break;
		    }
		}
		
		// Check horizontally
		for (int j = col - 1; j >= 0; j--) {
		    if (board[row][j] == 'K') {
		        Check_for_Rook = true;
		        break;
		    } else if (board[row][j] != ' ') {
		        break;
		    }
		}
		
		for (int j = col + 1; j < 8; j++) {
		    if (board[row][j] == 'K') {
		        Check_for_Rook = true;
		        break;
		    } else if (board[row][j] != ' ') {
		        break;
		    }
		}
		
		// Print check result
		if (Check_for_Rook) {
		    cout << "The king is not in check!" << endl;
		} else {
		    cout << "The king is in check." << endl;
		}
		
		// Check for checkmate
		bool Checkmate_for_Rook = true;
		
		// Check vertically
		for (int i = row - 1; i >= 0; i--) {
		    if (board[i][col] == 'K') {
		       Checkmate_for_Rook = false;
		        break;
		    } else if (board[i][col] != ' ') {
		        break;
		    }
		}
		
		for (int i = row + 1; i < 8; i++) {
		    if (board[i][col] == 'K') {
		        Checkmate_for_Rook = false;
		        break;
		    } else if (board[i][col] != ' ') {
		        break;
		    }
		}
		
		// Check horizontally
		for (int j = col - 1; j >= 0; j--) {
		    if (board[row][j] == 'K') {
		        Checkmate_for_Rook = false;
		        break;
		    } else if (board[row][j] != ' ') {
		        break;
		    }
		}
		
		for (int j = col + 1; j < 8; j++) {
		    if (board[row][j] =='K') {
		        Checkmate_for_Rook = false;
		        break;
		    } else if (board[row][j] != ' ') {
		        break;
		    }
		}
		
		// Print checkmate result
//		if (Checkmate_for_Rook) {
//		    cout << "The king is in checkmate!" << endl;
//		} else {
//		    cout << "The king is not in checkmate." << endl;
//		}
			
		// For the movement of the second rook
		for(int i=row1-1; i>=0; i--)
		{
			if (board[i][col1]==' ')
			{
				board[i][col1]='.';
			}
			else if (board[i][col1]=='*'|| board[i][col1]=='K')
			{	
			break;
			}
			else
			{
				board[i][col1]='.';
				break;
			}
		}
		// For lower half of vertical direction
		for(int i=row1+1; i<8; i++)
		{
			if(board[i][col1]==' ')
			{
				board[i][col1]='.';
			}
			else if (board[i][col1]=='*' || board[i][col1]=='K')
			{	
			break;
			}
			else
			{
				board[i][col1]='.';
			}
		}
		// For first half of the horizontal line
		for(int j=col1+1; j<8; j++)
		{
			if(board[row1][j]==' ')
			{
				board[row1][j]='.';
			}
			else if (board[row1][j]=='*'|| board[row1][j]=='K')
			{
			break;
			}
			else
			{
				board[row1][j]='.';
				break;
			}
		}
		// For second half of the horizontal line
		for(int j=col1-1; j>=0; j--)
		{
			if(board[row1][j]==' ')
			{
				board[row1][j]='.';
			}
			else if (board[row1][j]=='*' || board[row1][j]=='K')
			{
			break;
			}
			else 
			{
				board[row1][j]='.';
			}
		}
			board[row][col]='R';
			board[row1][col1]='r';	
			
	}
			// Movement for the knight
			else if(choice==4)
		{	
			int knight_moves[8][2]= {
								{-2,-1},{-1,-2},{1,-2},{2,-1},
								{2,1},{1,2},{-1,2},{-2,1}
								};
								
	
		for(int i=0; i<8; i++)
		{
			int new_row=row+knight_moves[i][0];
			int new_col=col+knight_moves[i][1];
		if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
            board[new_row][new_col]='.';
        }
           	else if (knight_moves[new_row][new_col]=='*')
		{
			break;
		}
	
 		}
    cout << endl;
    
    int knight_moves1[8][2]= {
								{-2,-1},{-1,-2},{1,-2},{2,-1},
								{2,1},{1,2},{-1,2},{-2,1}
								};
								
	
		for(int i=0; i<8; i++)
		{
			int new_row=row1+knight_moves[i][0];
			int new_col=col1+knight_moves[i][1];
		if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
            board[new_row][new_col]='.';
        }
        	else if (knight_moves[new_row][new_col]=='*')
		{
			break;
		}
    }
    cout << endl;
			
			board[row][col]='N';
			board[row1][col1]='n';

	// Check logic for the check
    bool Check_for_knight = false;
    for (int i = 0; i < 8; i++) {
        int new_row = r1 + knight_moves[i][0];
        int new_col = c1 + knight_moves[i][1];
        
        if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8 && board[new_row][new_col]=='N') {
             Check_for_knight = true;
            break;
        }
    }
    if (Check_for_knight) {
        cout << "The king is in check!" << endl;
    } else {
        cout << "The king is not in check." << endl;
    }
    // Checkmate logic for the knight
    bool Checkmate_for_knight = true;
    for (int i = r1 - 1; i <= r1 + 1; i++) {
        for (int j = c1 - 1; j <= c1 + 1; j++) {
            if (i >= 0 && i < 8 && j >= 0 && j < 8 && (i != r1 || j != c1)) {
                if (board[i][j] == ' ' || board[i][j] == '.') {
                    Checkmate_for_knight = false;
                    break;
                }
            }
        }
        if (!Checkmate_for_knight) {
            break;
        }
    }
    for (int i = 0; i < 8; i++) {
        int new_row = r1 + knight_moves[i][0];
        int new_col = c1 + knight_moves[i][1];
        
        if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8 && board[new_row][new_col]=='N') {
            Checkmate_for_knight = false;
            break;
        }
    }
    if (Checkmate_for_knight) {
       		cout << "The king is in checkmate" << endl;
        	cout<<" Congratulations...:)";
        	cout<<" Player 2 Won the Game.."<<endl;
            break;	
    } else {
        cout << "The king is not in checkmate." << endl;
    }
}
		chess_board(board);
}
}














