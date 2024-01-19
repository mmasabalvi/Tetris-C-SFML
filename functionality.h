

//---Piece Starts to Fall When Game Starts---//
int Score = 0;

void fallingPiece(float& timer, float& delay, int& colorNum)
{
    if (timer>delay)
    {
        for (int i=0;i<4;i++)
        {
            point_2[i][0]=point_1[i][0];                                              //copy current cordinates to point_2
            point_2[i][1]=point_1[i][1];                                             
            point_1[i][1]+=1;                                                       //Move 1 unit down
        }
        
        
        
        if (!anamoly())
        {
            for (int i = 0; i < 4; i++)
            {
                gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;
            }

             colorNum= rand()%7+1;					                               // will give random color
             int n=rand()%7;                                                       // will give 7 different shapes at random
                                                                                    
            
                for (int i=0;i<4;i++)
                {                                          
                    point_1[i][0] = BLOCKS[n][i] % 2;                                   
                    point_1[i][1] = BLOCKS[n][i] / 2;                      
                }
            
        }

       timer=0;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///



void movement(int& delta_x){							    // function for movement
										  
	for (int i=0; i<4; i++)
    {
		 point_2[i][0]= point_1[i][0];
		 point_2[i][1]= point_1[i][1];
		 point_1[i][0]+= delta_x;                                          // delta x is +1 if right key pressed and vice versa
    }                                                                     // movement wrt x- axis
		 delta_x = 0;
		 
	if (!anamoly())
    {
		for (int i=0; i<4; i++)
        {
		point_1[i][0]= point_2[i][0];
		point_1[i][1]= point_2[i][1];
		}
	}
}
	


void linecomp(int M, int delta_x, int rotate, int delay)
{
int x = M-1;

    for (int i = M-1; i>0; i--)
    {
        int count=0;
        
        for (int j=0; j<N; j++)
        {
            if (gameGrid[i][j])
            {
            count++;
            }
            gameGrid[x][j]= gameGrid[i][j];
     	    
        }
        if (count<N)
        {   
            x--;
        }  

        else
        {
            // Increment the score when a line is completed
            Score++;
        }
    }

delta_x=0; 
rotate=0; 
delay=0.3;


int lines= 0;
}


void rotation()
{
    int pivotX = point_1[1][0];  // Use the x-coordinate of the second point as the pivot
    int pivotY = point_1[1][1];  // Use the y-coordinate of the second point as the pivot

    for (int i = 0; i < 4; i++)
    {
        int relativeX = point_1[i][0] - pivotX;
        int relativeY = point_1[i][1] - pivotY;

        // Perform a 90-degree clockwise rotation
        int newX = -relativeY + pivotX;
        int newY = relativeX + pivotY;

        // Update the positions of the points
        point_1[i][0] = newX;
        point_1[i][1] = newY;
    }

    // Check for anomalies and revert if necessary
    if (!anamoly())
    {
        for (int i = 0; i < 4; i++)
        {
            point_1[i][0] = point_2[i][0];
            point_1[i][1] = point_2[i][1];
        }
    }
}

bool checkGameOver(int M)
{
    for (int j = 0; j < N; j++)
    {
        if (gameGrid[0][j] != 0)
        {
            // If any block is present in the top row, the game is over
            return true;
        }
    }
    return false;
}




///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
