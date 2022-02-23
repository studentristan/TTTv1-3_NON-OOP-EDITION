//old version of the user() function, just so I can remember how dumb I am. 

void user(){
        turn++;
        
        cin >> input;
        
        cout << endl << endl;

        if(turn % 2 == 0)
            xo = 'X';
        else
            xo = 'O';
    
        switch (input){
            case 1:	
                if ((board[1] == 'x')||(board[1] == 'X')||(board[1] == 'o')||(board[1] == 'O')) { // decides if spot is already taken
                    alreadyTaken();
                    break;
                }
                board[1] = xo;
                break;
            
	       	case 2:	
                if ((board[2] == 'x')||(board[2] == 'X')||(board[2] == 'o')||(board[2] == 'O')) { // same process for all cases
                    alreadyTaken();
                    break;
                }
                board[2] = xo;
                break;
		    case 3:	
                if ((board[3] == 'x')||(board[3] == 'X')||(board[3] == 'o')||(board[3] == 'O')) {
                    alreadyTaken();
                    break;
                }
                board[3] = xo;
                break; 
            case 4:
                if ((board[4] == 'x')||(board[4] == 'X')||(board[4] == 'o')||(board[4] == 'O')) {
                    alreadyTaken();
                    break;
                }
                board[4] = xo;
                break;
	       	case 5:	if ((board[5] == 'x')||(board[5] == 'X')||(board[5] == 'o')||(board[5] =='O')) {
                    alreadyTaken();
                    break;
                }
                board[5] = xo;
                break;
		    case 6:	
                if ((board[6] == 'x')||(board[6] == 'X')||(board[6] == 'o')||(board[6] =='O')) {
                    alreadyTaken();
                    break;
                }
                board[6] = xo;
                break;
            case 7:	
                if ((board[7] == 'x')||(board[7] == 'X')||(board[7] == 'o')||(board[7] =='O')) {
                    alreadyTaken();
                    break;
                }
                board[7] = xo;
                break;
	       	case 8:	
                if ((board[8] == 'x')||(board[8] == 'X')||(board[8] == 'o')||(board[8] =='O')) {
                    alreadyTaken();
                    break;
                }
                board[8] = xo;
                break;
		    case 9:	
            if ((board[9] == 'x')||(board[9] == 'X')||(board[9] == 'o')||(board[9] =='O')) {
                    alreadyTaken();
                    break;
                }
                board[9] = xo;
                break;
            case 0:  
                break;                                                      //quit flag
	       	default:	
                cout << "You did not enter a valid input" << endl;
    	}
        
        
        winState();
}
