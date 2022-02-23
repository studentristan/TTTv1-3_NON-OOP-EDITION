//TTTv1-3.cpp
//Tristan Werden
//NOTES: I used the oop one I built last year as a base, and cleaned some of the really bad stuff I had in there up. 
//NOTES: This one is exactly like TTTv1-3.cpp but I changed the board display so that it matches the numpad. (It also makes the comments on winstate() invalid, but I don't really care...)


# include <iostream>
using namespace std;

void boardDisplay();
void user();                                                
void alreadyTaken();
void winState();
void tieCheck();
// global variables...

int input;                                                      //ends the game if 0.
int turn = 0;                                                   //turn counter
char xo = ' ';                                                  // input variable      

char board[10] = {' ','1','2','3','4','5','6','7','8','9'};     //board contents - leave board[0] empty to simplify the 1-10 structure
                                                                

int main(){
    do{  // I thought you didn't like do-whiles, but using a do here was actually your idea last year. 
        boardDisplay();
        cout << "Turn#: " << turn << ".  Please choose a number, 1 - 9 (or 0 to quit): ";   // user input
																							// Moved this input out of boardDisplay() so it didn't print when board display is called to show off the board in win and tie scenarios.
        user();
    	tieCheck();
        
    
    }while(input != 0);
	
	
    
    return 0;   
}

void boardDisplay(){	// uses one array, using board[1-9], also matches # key rather than being backwards for keypad users		
        cout << " " << board[7] << " " << "|" << " " << board[8] << " " << "|" << " " << board[9] << " " << endl;   
        cout << "----------" << endl;
        cout << " " << board[4] << " " << "|" << " " << board[5] << " " << "|" << " " << board[6] << " " << endl;               
        cout << "----------" << endl;
        cout << " " << board[1] << " " << "|" << " " << board[2] << " " << "|" << " " << board[3] << " " << endl;               
    
        
        
        }

void user(){
        turn++;
        
        cin >> input;
        
        cout << endl << endl;

        if(turn % 2 == 0)
            xo = 'X';
        else
            xo = 'O';
    
        //This if/else-if chain used to be a super ugly, MASSIVE switch-case statement. It was like 30 lines, checking things over and over. I'm so glad I cleaned it up. 
        if ( (input != 0) && (input != 1) && (input != 2) && (input != 3) && (input != 4) && (input != 5) && (input != 6) && (input != 7) && (input != 8) && (input != 9)) {
            alreadyTaken();
		} else if ((board[input] == 'x')||(board[input] == 'X')||(board[input] == 'o')||(board[input] =='O')) {
            alreadyTaken();
 		} else if (input == 0 ) {
            //do nothing - it'll close itself when it runs winState()
		} else {
            board[input] = xo;
		}
        
        
        winState();
}

void alreadyTaken() { // also gets run for invalid inputs - I don't handle non-int input, the program just crashes, but I do handle any int that's not 1-9
    cout << "This spot is already taken, or you gave an invalid input. Please try again." << endl;
    turn--; // My old one didn't have this. I guess I never hit the issue in bug-checking... oops!
}

void winState() {   //I was so proud of breaking this down into 2 if statements when I did it last year.I'm sure there is a more efficeint way of doing it, but it works.                                                    
    																  
    if(                                                                          //X's first
	((board[1] == board[4]) && (board[4] == board[7]) && (board[7] == 'X')) ||   //left column 
	((board[2] == board[5]) && (board[5] == board[8]) && (board[5] == 'X')) ||   //middle column 
	((board[3] == board[6]) && (board[6] == board[9]) && (board[9] == 'X')) ||   //right column 
	((board[1] == board[2]) && (board[2] == board[3]) && (board[2] == 'X')) ||   //top row
	((board[4] == board[5]) && (board[5] == board[6]) && (board[5] == 'X')) ||   //mid row
	((board[7] == board[8]) && (board[8] == board[9]) && (board[9] == 'X')) ||   //bottom Row
	((board[1] == board[5]) && (board[5] == board[9]) && (board[9] == 'X')) ||	 //slant 1
	((board[3] == board[5]) && (board[5] == board[7]) && (board[5] == 'X'))      //slant 2	
	){
		boardDisplay();
		cout << "X Wins!" << endl;
		input = 0;                              // end game
    	turn = 0;								// resets the counter so tiecheck() doesn't go off after the game has already ended if the final move is on turn 9		      

	} else if(
	((board[1] == board[4]) && (board[4] == board[7]) && (board[7] == 'O')) ||   //left column 
	((board[2] == board[5]) && (board[5] == board[8]) && (board[5] == 'O')) ||   //middle column 
	((board[3] == board[6]) && (board[6] == board[9]) && (board[9] == 'O')) ||   //right column 
	((board[1] == board[2]) && (board[2] == board[3]) && (board[2] == 'O')) ||   //top row
	((board[4] == board[5]) && (board[5] == board[6]) && (board[5] == 'O')) ||   //mid row
	((board[7] == board[8]) && (board[8] == board[9]) && (board[9] == 'O')) ||   //bottom Row
	((board[1] == board[5]) && (board[5] == board[9]) && (board[9] == 'O')) ||	 //slant 1
	((board[3] == board[5]) && (board[5] == board[7]) && (board[5] == 'O'))
	){
		boardDisplay();
		cout << "O Wins!" << endl;
		input = 0;                              // end game
    	turn = 0;								// resets the counter so tiecheck() doesn't go off after the game has already ended if the final move is on turn 9
	}}



void tieCheck() {
	if (turn >= 9){
		boardDisplay();
		cout << "Sorry! It was a draw.";
		input = 0;                        
	}
}

