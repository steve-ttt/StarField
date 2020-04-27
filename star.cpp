#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <vector>


int SCREENWIDTH = 1280;
int SCREENHEIGHT = 1024;
int NUMOFSTARS = 300;
int MAXSIZE = 3;
float SPEEDmultiplier = 2;



class StarField : public olc::PixelGameEngine
{
public:
	StarField()
	{
		sAppName = "Star Field";
	}

public:

	struct Star 
	{ 
		float x;
		float y;
		float velocity_x;
		float velocity_y;
		int nsize;
	};

	std::vector<Star> stars;


	bool OnUserCreate() override
	{
		// fill out the vector of stars to make the star field    
		for (int i =0; i < NUMOFSTARS; i++)
		{
			float x = rand() %SCREENWIDTH;
			float y = rand() %SCREENHEIGHT;
			float vx = x - SCREENWIDTH/2;
			float vy = y - SCREENHEIGHT/2;
			int size = rand() %MAXSIZE;
			stars.push_back({x, y, vx, vy,  size});
		}
 
	 	return true;
    }


	bool OnUserUpdate(float fElapsedTime) override
	{
		// Clear Screen
	    Clear(olc::BLACK); 
			
		// Draw the stars from the star vector and update their x and y positoin based on their velocity  
		for (auto &i : stars)
		{
			i.x += i.velocity_x * fElapsedTime * SPEEDmultiplier;
			i.y += i.velocity_y * fElapsedTime * SPEEDmultiplier;
			FillCircle(i.x, i.y, i.nsize, olc::WHITE);
		}
                
		// destroy stars leaving the screen and create new ones
		for (auto &i : stars)
		{
			if(i.x  > SCREENWIDTH || i.x < 0 || i.y > SCREENHEIGHT || i.y < 0)
			{
				i.x = rand() %SCREENWIDTH;
				i.y = rand() %SCREENHEIGHT;
				i.velocity_x = i.x - SCREENWIDTH/2;
				i.velocity_y = i.y - SCREENHEIGHT/2;
				i.nsize = rand() %5;
				
			}
		}
          
		return true;
	}
};


int main()
{
	StarField sfield;
	if (sfield.Construct(SCREENWIDTH, SCREENHEIGHT, 1, 1))
		sfield.Start();



	return 0;
}
