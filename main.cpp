/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)14 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include<string>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
using namespace sf;
using namespace std;

int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(320, 480), title);
    Texture obj1, obj2, obj3;                                               
                                                                               
    obj1.loadFromFile("img/tiles.png");                                                   
    obj2.loadFromFile("img/background.png");   
    obj3.loadFromFile("img/frame.png");                  
    

    Sprite sprite(obj1), background(obj2), frame(obj3);  

    Font Scfont;
    Scfont.loadFromFile("LilitaOne-Regular.ttf");

   
                                                                  
    int delta_x=0, colorNum=1;                                                        
    float timer=0, delay=0.3;                                                         // delay, objects will come at delay of 0.3 seconds
    bool rotate=0;
    Clock clock;
    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;                                                                  

        int score = Score;
        string scoreString = "Score: " + to_string(score);
        Text scText(scoreString, Scfont, 20);
        scText.setPosition(235, 160);
        scText.setFillColor(Color::Red);

       
        
        Event e;
        while (window.pollEvent(e))
        {                      			 //Event is occurring - until the game is in running state

            delay= 0.3;                                       
            if (e.type == Event::Closed)                   			//If cross/close is clicked/pressed
                window.close();                            			//Opened window disposes
            if (e.type == Event::KeyPressed) {             			//If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            			//Check if the other key pressed is UP key
                    rotation();                         			//Rotation gets on
                else if (e.key.code == Keyboard::Left)     			//Check if the other key pressed is LEFT key
                    delta_x = -1;                          			//Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    			//Check if the other key pressed is RIGHT key
                    delta_x = 1;                           			//Change in X-Axis - Positive
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))  			 //Just another way to detect key presses without event listener
            delay=0.05;      					 //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
       
       else if (Keyboard::isKeyPressed(Keyboard::Space))
       { }                                                     


        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
       
        
        fallingPiece(timer, delay, colorNum); 
        
        movement(delta_x);
        
	    linecomp(M, delta_x, rotate, delay);

        if (checkGameOver(M)==true)
        {
            window.close();
        }
        
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////


        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); 										//offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);

        window.draw(scText);

        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    return 0;
}
