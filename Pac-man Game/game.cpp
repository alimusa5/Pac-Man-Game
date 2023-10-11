#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
	float gx = 320; 
	float gy = 15; 
        float gx2 = 460; 
	float gy2 = 15;
	float gxinc = 5 , gyinc = 5;
        int score=0;
	int lives=3;  
	int levels=1;
       	bool menu=true;
	bool opt1=false;
	bool opt2=false;
	bool opt3=false;
	bool opt4=false;
	bool opt5=false;
	bool car1=true;
        bool car2=true;
	float width  = 10; 
	float height = 10;
	float radius = 5.0;
	float* color = colors[RED]; 
	int f=0;
	bool hmenu=false;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
// cases for the making of food
bool top_food  [8]  ={true,true,true,true,true,true,true,true};
bool top_food1 [8] = {true,true,true,true,true,true,true,true};
bool top_food2 [8] = {true,true,true,true,true,true,true,true};
bool top_food3 [8] = {true,true,true,true,true,true,true,true};
bool top_food4 [8] = {true,true,true,true,true,true,true,true};
bool top_food5 [8] = {true,true,true,true,true,true,true,true};
bool top_food6 [8] = {true,true,true,true,true,true,true,true};
bool top_food7 [8] = {true,true,true,true,true,true,true,true};
bool top_food8 [8] = {true,true,true,true,true,true,true,true};
bool top_food9 [8] = {true,true,true,true,true,true,true,true};
bool top_food10[8] = {true,true,true,true,true,true,true,true};
bool top_food11[8] = {true,true,true,true,true,true,true,true};

/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	if(menu==true)
	{
		if(hmenu==false)
		{
		if (opt1==true || opt2==true || opt3==true || opt4==true || opt5==true )
		{
		if(opt1==true)
		{	menu=false;
			opt1=false;
		 	opt2=false;
			opt3=false;
	 		opt4=false;
	 		opt5=false;

			for(int i=0;i<8;i++)
			{
			 top_food  [i] = true;
			 top_food1 [i] =true;
			 top_food2 [i] = true;
			 top_food3 [i] =true;
			 top_food4 [i] =true;
			 top_food5 [i] =true; 
			 top_food6 [i] =true;
			 top_food7 [i] =true;
			 top_food8 [i] =true;
			 top_food9 [i] =true;
			 top_food10[i] =true;
  			 top_food11[i] =true;
			}
			 gxinc = 5 ;
			 gyinc = 5;
        		 score=0;
			 lives=3;  
			 levels=1;
			 gx = 340; 
			 gy = 15; 
        		 gx2 = 440; 
			 gy2 = 15;
			}

			if(opt3==true)//for help option
			
			{
                              
				menu=true;
				opt1=false;
		 		opt2=false;
				opt3=false;
		 		opt4=false;
		 		opt5=false;
				hmenu=true;


			}
			if(opt4==true)
			{
				exit(1); // exit the program
			}

		


			if(opt5==true)
			{
				menu=false;
				opt1=false;
		 		opt2=false;
				opt3=false;
		 		opt4=false;
		 		opt5=false;
			}
		}
		
		else
		{

		 glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
				0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		 glClear (GL_COLOR_BUFFER_BIT); //Update the colors
        	 DrawString(400,650, "1) Start New Game" , colors[PURPLE]);
        	 DrawString(400,550, "2) High Scores" , colors[PURPLE]);
        	 DrawString(400,450, "3) Help" , colors[PURPLE]);
        	 DrawString(400,350, "4) Exit" , colors[PURPLE]);
        	 DrawString(400,250, "5) continue" , colors[PURPLE]);
		}
		}
		else
		{
		 glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
				0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		 glClear (GL_COLOR_BUFFER_BIT); //Update the colors

			
			DrawString(10,650, "There is an opponent car and your car.You just have to eat the food my moving over it. And you have to save your yourself from the opposition car by avoiding to collide with it.If you collide you lose a 				live." ,colors[PURPLE]);
        	 	DrawString(10,550, "Your level will be completed as soon as you finish the food in the arena.and Then you will move onto the next level." , colors[PURPLE]);
        	 	DrawString(10,450, "There will be 3 levels and the difficulty increases with each level." , colors[PURPLE]);
        	 	DrawString(10,350, "In order to finish the whole game you have to complete the 3 levels." , colors[PURPLE]);
        	 	DrawString(10,250, "Wish you all the best in the game. Enjoy!  and thanks for playing." , colors[PURPLE]);


		}
	}
	else
	{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file for better understanding

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	
        
        //User car
	if(car2==true)
	{
	float width  = 10; 
	float height = 10;
	float radius = 5.0;
	float* color = colors[RED]; 
	

	
	
        //Automatic movement

        if (gy>10 && gy<25  && gx >30)//outermost loop 
     	   gx-=gxinc;
        else if(gx>10 && gx<55  && gy <750)
     	   gy+=gyinc; 
        else if(gy>=750 && gy<770 && gx<770)
     	   gx+=gxinc;
        else if(gx>750 && gx<790 && gy>15)
     	   gy-=gyinc;

	
        else if (gy>80 && gy<110 && gx >110)//2nd loop
     	   gx-=gxinc;
        else if(gx>90 && gx<140 && gy <680)
     	   gy+=gyinc; 
        else if(gy>=680 && gy<700 && gx<700)
     	   gx+=gxinc;
        else if(gx>680 && gx<720 && gy>95)
     	   gy-=gyinc;

	else if (gy>165  && gy<195 && gx >190)//3rd loop
     	   gx-=gxinc;
        else if(gx>170 && gx<210 && gy <610)
     	   gy+=gyinc; 
        else if(gy>600 && gy<630 && gx<630)
     	   gx+=gxinc;
        else if(gx>610 && gx<650 && gy>180)
     	   gy-=gyinc;

	else if (gy>240 && gy<270 && gx >270)//innermost loop
     	   gx-=gxinc;
        else if(gx>250 && gx<290 && gy <540)
     	   gy+=gyinc; 
        else if(gy>=540 && gy<560 && gx<560)
     	   gx+=gxinc;
        else if(gx>540 && gx<580  && gy>255)
     	   gy-=gyinc;




	

        // Body of the car
	DrawRoundRect(gx,gy,width,height,color,radius); // bottom left tyre
	DrawRoundRect(gx+width*3,gy,width,height,color,radius); // bottom right tyre
	DrawRoundRect(gx+width*3,gy+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(gx,gy+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(gx, gy+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(gx+width, gy+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(gx+width*3, gy+height*2, width, height, color, radius/2); // body right rect



	}

	// Opponent car
	if(car2 == true)
	{
	
	 
        width = 10; 
        height = 10;
	color = colors[BLUE]; 
        radius = 5.0;

        // Automatic movement
 
	if  (gy2 ==15 && gx2 <770)//outermost loop
     	   gx2+=gxinc;
        else if(gx2>=770 && gy2 <750)
     	   gy2+=gyinc; 
        else if(gy2==750 && gx2>30)
     	   gx2-=gxinc;
        else if(gx2==30 && gy2>15)
     	   gy2-=gyinc;

	else if (gy2==95 && gx2 <700)//2nd loop
     	   gx2+=gxinc;
        else if(gx2>=700 && gy2 <680)
     	   gy2+=gyinc; 
        else if(gy2==680 && gx2>110)
     	   gx2-=gxinc;
        else if(gx2==110 && gy2>95)
     	   gy2-=gyinc;


	else if (gy2==180 && gx2 <630)//3rd loop
     	   gx2+=gxinc;
        else if(gx2>=630 && gy2 <610)
     	   gy2+=gyinc; 
        else if(gy2==610 && gx2>190)
     	   gx2-=gxinc;
        else if(gx2==190 && gy2>180)
     	   gy2-=gyinc;


	else if (gy2==255 && gx2 <550)//outermost loop
     	   gx2+=gxinc;
        else if(gx2>=550 && gy2 <540)
     	   gy2+=gyinc; 
        else if(gy2==540 && gx2>270)
     	   gx2-=gxinc;
        else if (gx2==270 && gy2>255)
     	   gy2-=gyinc;
	

        
        //Body of the car
	DrawRoundRect(gx2,gy2,width,height,color,radius); // bottom left tyre
	DrawRoundRect(gx2+width*3,gy2,width,height,color,radius); // bottom right tyre
	DrawRoundRect(gx2+width*3,gy2+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(gx2,gy2+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(gx2, gy2+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(gx2+width, gy2+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(gx2+width*3, gy2+height*2, width, height, color, radius/2); //body right rect
        
	// Drawing Arena
	}


		
		//Collision detection 		
		for(int y=0;y<840;y++)
		{
			if( car1 && car2)
			{
			
			for(int l=0 ; l<width+45 ; l++ )
			    for(int w=0; w<height+60 ; w++ )
				if( (gx+l)>(gx2) && (gx+l) <(gx2+30) && (gy+w)>(gy2) && (gy+w)<(gy2+30) )
				{
					if(car1 && car2)
				{	
				if(lives>0)
				{
                                  car1=false;
				  car2=false;
				  lives--;
				 }
				 }                                 
				}
			
			
			}

		}
		if(car1==false && car2==false)
		{
		car1=true;
		car2=true;
		gx=320;
		gy=15;
		gx2=460;
		gy2=15;
		}
		
		if(lives==0)
		{
		menu=true;
		for(int i=0;i<8;i++)
			{
			 top_food  [i] = true;
			 top_food1 [i] =true;
			 top_food2 [i] = true;
			 top_food3 [i] =true;
			 top_food4 [i] =true;
			 top_food5 [i] =true; 
			 top_food6 [i] =true;
			 top_food7 [i] =true;
			 top_food8 [i] =true;
			 top_food9 [i] =true;
			 top_food10[i] =true;
  			 top_food11[i] =true;
			}
			 gxinc = 5 ;
			 gyinc = 5;
        		 score=0;
			 lives=3;  
			 levels=1;
			 gx = 340; 
			 gy = 15; 
        		 gx2 = 440; 
			 gy2 = 15;
		}

		
		


                         
        //food loops

	int lol=0;
		for(int y=0;y<800;y+=105)//loop1
		{
			if( top_food[ lol ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(40+y) && (gx+l) <(40+y+20) && (gy+w)>(765) && (gy+w)<(785) )
				{
					if(top_food[lol])
				{
					
                                  top_food[lol] = false;
				  score++;
                                 
				}
				}
                         
			DrawRoundRect(40+y,765,20,20,colors[GREEN],10);
		

			}
		
		lol++;
		}
	

            int lol1=0;
		for(int y=0;y<800;y+=105)//loop2
		{
                  if( top_food1[ lol1 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(40+y) && (gx+l) <(40+y+20) && (gy+w)>(695) && (gy+w)<(715) )
				{
				if(top_food1[lol1])
				{
					
					top_food1[lol1] = false;
                                        score++;
				}
				}

			DrawRoundRect(40+y,695,20,20,colors[GREEN],10);
		}
         lol1++;
 	}



       int lol2=0;
	
		for(int y=0;y<500;y+=138)//loop3
		{
                 if( top_food2[ lol2 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(130) && (gx+l) <(150) && (gy+w)>(200+y) && (gy+w)<(220+y) )
				{
					if(top_food2[lol2])
				{
					
					top_food2[lol2] = false;
                                	score++;
				}
				}
			DrawRoundRect(130,200+y,20,20,colors[GREEN],10);
		}
        lol2++;
	}

       
	 int lol3=0;
		for(int y=0;y<500;y+=138)//loop4
		{
                   if( top_food3[ lol3 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(40) && (gx+l) <(60) && (gy+w)>(200+y) && (gy+w)<(220+y) )
				{
					if(top_food3[lol3])
				{
					
					top_food3[lol3] = false;
                          		 score++;
				}
				}
				
			DrawRoundRect(40,200+y,20,20,colors[GREEN],10);
		}
        lol3++;
	}

        int lol4=0;
       
		for(int y=0;y<500;y+=138)//loop5
		{
                 if( top_food4[ lol4 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(210) && (gx+l) <(230) && (gy+w)>(200+y) && (gy+w)<(220+y) )
				{
					if(top_food4[lol4])
				{
					
					top_food4[lol4] = false;
                                	score++;
				}
				}
			DrawRoundRect(210,200+y,20,20,colors[GREEN],10);
		}
         lol4++;
	}


       int lol5=0;
     
		for(int y=0;y<500;y+=138)//loop6
		{
                 if( top_food5[ lol5 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(300) && (gx+l) <(320) && (gy+w)>(200+y) && (gy+w)<(220+y) )
				{
					if(top_food5[lol5])
				{
					
					top_food5[lol5] = false;
                                 	score++;
				}
				}
			DrawRoundRect(300,200+y,20,20,colors[GREEN],10);
		}
         lol5++;
	}
        



        int lol6=0;
		for(int y=0;y<500;y+=138)//loop7
		{
               if( top_food6[ lol6 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(565) && (gx+l) <(585) && (gy+w)>(200+y) && (gy+w)<(220+y) )
				{
					if(top_food6[lol6])
				{
					
					top_food6[lol6] = false;
			                score++;
				}
				}
			DrawRoundRect(565,200+y,20,20,colors[GREEN],10);
		}
            lol6++;
	}


         
	int lol7=0;
		for(int y=0;y<500;y+=138)//loop8
		{
                if( top_food7[ lol7 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(640) && (gx+l) <(660) && (gy+w)>(200+y) && (gy+w)<(220+y) )
				{
					if(top_food7[lol7])
				{
					
					top_food7[lol7] = false;
					score++;
				}
				}

			DrawRoundRect(640,200+y,20,20,colors[GREEN],10);
		}
         lol7++;
	}

        int lol8=0;
		for(int y=0;y<500;y+=138)//loop9
		{
                 if( top_food8[ lol8 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(715) && (gx+l) <(735) && (gy+w)>(200+y) && (gy+w)<(220+y) )
				{
					if(top_food8[lol8])
				{
					
					top_food8[lol8] = false;
                                	score++;
				}
				}
			DrawRoundRect(715,200+y,20,20,colors[GREEN],10);
		}
        lol8++;
	}

         int lol9=0;

		for(int y=0;y<500;y+=138)//loop10
		{
                  if( top_food9[ lol9 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(775) && (gx+l) <(795) && (gy+w)>(200+y) && (gy+w)<(220+y) )
				{
					if(top_food9[lol9])
				{
					
					top_food9[lol9] = false;
                                  	score++;
				}
				}
			DrawRoundRect(775,200+y,20,20,colors[GREEN],10);
		}
           lol9++;
	}


      
	int lol10=0;

		for(int y=0;y<800;y+=105)//loop11
		{
                   if( top_food10[ lol10 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(40+y) && (gx+l) <(60+y) && (gy+w)>(110) && (gy+w)<(130) )
				{
					if(top_food10[lol10])
				{
					
					top_food10[lol10] = false;
                                	score++;
				}
				}
			DrawRoundRect(40+y,110,20,20,colors[GREEN],10);
		}
           lol10++;
	}


        int lol11=0;
 
		for(int y=0;y<800;y+=105)//loop12
		{
                 if( top_food11[ lol11 ])
			{
			
			for(int l=0 ; l<width+25 ; l++ )
				for(int w=0; w<height+40 ; w++ )
				if( (gx+l)>(40+y) && (gx+l) <(60+y) && (gy+w)>(35) && (gy+w)<(55) )
				{
					if(top_food11[lol11])
				{
					
					top_food11[lol11] = false;
                                  	score++;
				}
				}
			DrawRoundRect(40+y,35,20,20,colors[GREEN],10);
		}
        lol11++;
	}
	
	if(score==64)
	{
	levels=2;
	for(int i=0;i<8;i++)
			{
			 top_food  [i] = true;
			 top_food1 [i] =true;
			 top_food2 [i] = true;
			 top_food3 [i] =true;
			 top_food4 [i] =true;
			 top_food5 [i] =true; 
			 top_food6 [i] =true;
			 top_food7 [i] =true;
			 top_food8 [i] =true;
			 top_food9 [i] =true;
			 top_food10[i] =true;
  			 top_food11[i] =true;
			}
			 gxinc = 5 ;
			 gyinc = 5;
        		 score=0;
			 lives=3;  
			 levels=1;
			 gx = 340; 
			 gy = 15; 
        		 gx2 = 440; 
			 gy2 = 15;
			
	}
		
			
			

			

        // DrawSquare( 332, 320 ,215,colors[RED]);
       
        // Structure of maze

        // Outer boundary
        int gap_turn = 0;
	int sx = 20;
	int sy = 0;
	int ss=800;
	int swidth = ss/2 - gap_turn/2; // half width
	int sheight = 5;
	float *scolor = colors[RED];

	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+ss+10, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+ss+10, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	
        // Inner 4 boundaries
	for(int i=1 ;i<5 ;i++)
	{	
		gap_turn = 110;
		if(i==4) // To close the inner most boundary  
		{
			gap_turn=0;
		}
		sx+=80;
		sy+=80;
		ss-=150;
		swidth=ss/2-gap_turn/2;

		DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
		DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
		DrawRectangle(sx + swidth + gap_turn, sy+ss+10, swidth, sheight, scolor); // top left
		DrawRectangle(sx, sy+ss+10, swidth, sheight, scolor); // top right
		DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
		DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	
	}
         DrawString(20,817, "SCORE:" , colors[PURPLE]);
         DrawString(700,817, "LEVEL:" , colors[PURPLE]);
	 DrawString(390,817, "LIVES:" , colors[PURPLE]);
	 string ali1= Num2Str(lives) ;
         DrawString(465,817, ali1, colors[PURPLE]);
	 string ali2= Num2Str(levels) ;
         DrawString(785,817, ali2, colors[PURPLE]);

	
         string ali= Num2Str(score) ;
         DrawString(105,817, ali, colors[PURPLE]);
	/* highscores[5];
	 for(int a=0; a<5 ; a++)
	{
	

	}*/

	}

	glutSwapBuffers(); // do not modify this line.. or draw anything below this line

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key																
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

		gx-=10;
 
   



		
	

			
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	if(gx>15 && gx<140 && gy>350 && gy<470)
	{
	gx+=90;
	}
	if(gx>130 && gx<170 && gy>350 && gy<470)	
	{
        gx+=20;
	}
	if(gx>180 && gx<200 && gy>350 && gy<470)	
	{
        gx+=30;
	}
	if(gx>210 && gx<250 && gy>350 && gy<470)	
	{
        gx+=40;
	}










	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

		
	//Lower part
       	if (gx>350 && gx<460 && gy>0 && gy<140)
	{
	gy+=65;
	}
	if( gx>350 && gx<460 && gy>130 && gy<150)
	{
	gy+=35;
	}
	if( gx>350 && gx<460 && gy>170 && gy<240)
	{
	gy+=55;
	}
	

	//Upper part
 	if(gx>350 && gx<460 && gy>380 && gy<510)
	{
	gy+=95;
	}
	if(gx>350 && gx<460 && gy>510 && gy<670)
	{
	gy+=65;
	}
	if(gx>350 && gx<460 && gy>670 && gy<770)
	{
	gy+=70;
	}

	}


	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		
	if (gx>350 && gx<460 && gy>580 && gy<770)//Upper part
	{
	gy-=55;
	}
	if( gx>350 && gx<460 && gy>380 && gy<480)
	{
	gy-=35;
	}
	
	


	if (gx>350 && gx<460 && gy>170 && gy<240)//Lower part
	{
	gy-=60;
	}
	if( gx>350 && gx<460 && gy>0 && gy<140)
	{
	gy-=50;
	}
	



}
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}


/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'p' || key == 'P')
	{
		if((menu==true && opt5==true) )
		{
			menu=false;
			opt1=false;
	 		opt2=false;
	 		opt3=false;
		 	opt4=false;
	 		opt5=false;
	
		}
		else
		{
			menu=true;
			opt1=false;
	 		opt2=false;
	 		opt3=false;
	 		opt4=false;
	 		opt5=false;

		}
	}
	if (key == '1')
	{
	 opt1=true;
	 opt2=false;
	 opt3=false;
	 opt4=false;
	 opt5=false;

	}
	if (key == '2')
	{
	 opt1=false;
	 opt2=true;
	 opt3=false;
	 opt4=false;
	 opt5=false;
	
	}
	if (key == '3')
	{
	 opt1=false;
	 opt2=false;
	 opt3=true;
	 opt4=false;
	 opt5=false;
	
	}
	if (key == '4')
	{
	 opt1=false;
	 opt2=false;
	 opt3=false;
	 opt4=true;
	 opt5=false;
	
	}
	if (key == '5')
	{
	 opt1=false;
	 opt2=false;
	 opt3=false;
	 opt4=false;
	 opt5=true;

	}

	if ((key == 'b' || key == 'B') && hmenu==true)
	{
		hmenu=false;
	}


	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	


	// implement your functionality here
	glutPostRedisplay();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(10.0, Timer, 1);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}


/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */