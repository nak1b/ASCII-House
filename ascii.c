#include <stdio.h>
#include <ctype.h>

//Prototype Declaration
void drawDashes(int num);
void drawPipes(int num);
void limitChecker(int x, int y, int* input);
void groundFloor(int winSpacing, int windowWidth, int windowHeight, int winPerFloor);
void floors(int winSpacing, int winWidth, int windowHeight, int numOfWin);
void drawSpace(int num);
void gableRoof(int x);
void drawEquals(int num);
void flatRoof(int x);
void pitchedRoof(int roofWidth);
void roofSelector(char s, int roofWidth);
void charChecker(char* c);

int main(void)
{
	int windowWidth;
	int windowHeight;
	int winPerFloor;
	int numOfStories;
	int winSpacing;
	char roofType;

	printf("IPC ASCII house generator \n");
	printf("------------------------------------------------------ \n \n");

	printf("Enter the width of the windows. \n");
	printf("Please enter a value (5 - 10): ");
	scanf("%d", &windowWidth);
	limitChecker(5, 10, &windowWidth);
	printf("\n");

	printf("Enter the height of the windows. \n");
	printf("Please enter a value (3 - 5): ");
	scanf("%d", &windowHeight);
	limitChecker(3, 5, &windowHeight);
	printf("\n");

	printf("Enter the spacing between windows. \n");
	printf("Please enter a value (3 - 10): ");
	scanf("%d", &winSpacing);
	limitChecker(3, 10, &winSpacing);
	printf("\n");

	printf("Enter the maximum number of windows per floor \n");
	printf("Please enter a value (1 - 6): ");
	scanf("%d", &winPerFloor);
	limitChecker(1, 6, &winPerFloor);
	printf("\n");

	printf("Enter number of stories in the building \n");
	printf("Please enter a value (1 - 6): ");
	scanf("%d", &numOfStories);
	limitChecker(1, 6, &numOfStories);
	printf("\n");

	printf("Enter the type of roof (f)lat, (g)able, or (p)itched: ");
	scanf(" %c", &roofType);
	charChecker(&roofType);
	printf("\n");

	int roofWidth = (winPerFloor*windowWidth) + (winPerFloor+1)*winSpacing + 4;
	roofSelector(roofType, roofWidth);

	if(numOfStories == 1)
	{
		groundFloor(winSpacing, windowWidth, windowHeight, winPerFloor);
	}
	else
	{	
		numOfStories = numOfStories - 1;
		while(numOfStories>0)
		{
			floors(winSpacing, windowWidth, windowHeight, winPerFloor);
			numOfStories--;
		}
		groundFloor(winSpacing, windowWidth, windowHeight, winPerFloor);
	}

}

//Draw number of dashes(-)  user input
void drawDashes(int num)
{
	while (num>0)
	{
		printf("-");
		num--;
	}
}

//Draw number of Equals (=)  user input
void drawEquals(int num)
{
	while (num>0)
	{
		printf("=");
		num--;
	}
}

//Draw number of spaces (" ") user input
void drawSpace(int num)
{
	while(num>0)
	{
		printf(" ");
		num--;
	}
}

//drawPipes draw pipe or height at the start and end of width provided (Eg:If width is 5 it draws / at 1 and  5)
void drawPipes(int num)
{
	int numCopy = num;
	while (numCopy>0)
	{
		if(numCopy == num || numCopy == 1)
		{
			printf("|");
		}
		else
		{
			printf(" ");
		}
		numCopy--;
	}
}

//drawPipes draw pipe or height at the start and end of width provided (Eg:If width is 5 it draws / at 1 and \ at 5 Else id space)
void drawSlash(int num)
{
	int numCopy = num;
	while (numCopy>0)
	{
		if(numCopy == num)
		{
			printf("/");
		}
		else if(numCopy == 1)
		{
			printf("\\");
		}
		else
		{
			printf(" ");
		}
		numCopy--;
	}
}

//Validate user input to check the input is between the limit if not ask the user to enter again
void limitChecker(int x, int y, int* input)
{
    while(!(*input>=x && *input<=y))
    {
    printf("Please enter a value between (%d - %d): ",x,y);
    scanf("%d", input);
    }
}


//checking if user input matches F, G or P, if not asking again
void charChecker(char* c)
{
	while(!(*c == 'f' || *c == 'g' || *c == 'p'))
    {
	    printf("Please enter F, G or P: ");
	    scanf(" %c", c);
    }
}

//Drawing floor
void floors(int winSpacing, int winWidth, int windowHeight, int numOfWin)
{
	int roofWidth = (winWidth*numOfWin)+ ((numOfWin+1)*winSpacing) + 2;
	int i;
	int windowHeightCopy = windowHeight;
	for(i = 1; i<=8; i++)
	{
		printf("    ");
		if(i==1)
		{
			drawPipes(roofWidth);
			printf("\n");
		}
		else if(i==8)
		{
			drawDashes(roofWidth);
		}
		else if(windowHeightCopy>0)
		{
			if(windowHeightCopy == windowHeight || windowHeightCopy==1)
			{

				int counter = (numOfWin*2) + 1;
				int counterCp = counter;
				printf("|");
				while(counter>0)
				{
					if(counter==1 || counter==counterCp)
					{
						drawSpace(winSpacing);
					}
					else if(counter%2==0)
					{
						drawDashes(winWidth);
					}
					else
					{
						drawSpace(winSpacing);
					}

					counter--;
				}
				printf("| \n");
			}
			else
			{
				int counter = (numOfWin*2) + 1;
				int counterCp = counter;

				printf("|");
				while(counter>0)
				{
					if(counter==1 || counter==counterCp)
					{
						drawSpace(winSpacing);
					}
					else if(counter%2==0)
					{
						drawPipes(winWidth);
					}
					else
					{
						drawSpace(winSpacing);
					}
					counter--;
				}
				printf("| \n");
			}
			windowHeightCopy--;
			
		}
		else
		{
			drawPipes(roofWidth);
			printf("\n");
		}
	}
	printf("\n");
}

//Drawing ground floor or the base floor
void groundFloor(int winSpacing, int windowWidth, int windowHeight, int winPerFloor)
{
	int roofWidth = (winPerFloor*windowWidth) + (winPerFloor+1)*winSpacing + 2;
	int doorSpacing = (windowWidth + winSpacing) - 5;
	int winHeightCp = windowHeight;
	int i;

	for(i=1; i<=8; i++)
	{
		printf("    ");
		if(i==1)
		{
			drawPipes(roofWidth);
			printf("\n");
		}
		else if(i==8)
		{
			drawDashes(roofWidth);
			printf("\n");
		}
		else if(i==2)
		{
			int counter = winPerFloor - 1;
			printf("|");
			drawSpace(winSpacing+windowWidth+winSpacing);
			
			while (counter>0)
			{
				drawDashes(windowWidth);
				drawSpace(winSpacing);
				counter--;
			}
			printf("|\n");
			winHeightCp--;
		}
		else if(winHeightCp>0)
		{
			if(winHeightCp == (windowHeight -1))
			{
				int counter = winPerFloor - 1;
				printf("|");
				drawSpace(winSpacing);
				drawDashes(5);
				drawSpace(winSpacing + windowWidth - 5);

				while (counter>0)
				{
					drawPipes(windowWidth);
					drawSpace(winSpacing);
					counter--;
				}

			}
			else if(winHeightCp == 1)
			{
				int counter = winPerFloor - 1;
				printf("|");
				drawSpace(winSpacing);
				drawPipes(5);
				drawSpace(winSpacing + windowWidth - 5);

				while (counter>0)
				{
					drawDashes(windowWidth);
					drawSpace(winSpacing);
					counter--;
				}
			
			}
			else
			{
				int counter = winPerFloor - 1;
				printf("|");
				drawSpace(winSpacing);
				drawPipes(5);
				drawSpace(winSpacing + windowWidth - 5);

				while (counter>0)
				{
					drawPipes(windowWidth);
					drawSpace(winSpacing);
					counter--;
				}
			}

			printf("|\n");
			winHeightCp--;
		}
		else
		{
			printf("|");
			drawSpace(winSpacing);
			drawPipes(5);
			drawSpace(roofWidth - (winSpacing+5) - 2);
			printf("|\n");
		}
	}
}

//Simple flat roof 
void flatRoof(int x)
{
	printf("  ");
	drawEquals(x);	
	printf("\n");
}

//gable roof 
void gableRoof(int x)
{
	int i = x - 10;
	int iCp = i;
	int j = 5;
	while(i <= x)
	{
		printf("  ");
		if(i==iCp)
		{
			drawSpace(j);
			drawDashes(i);
			i = i + 2;
			printf("\n");
		}
		else if(i==x)
		{
			drawSpace(j);
			drawEquals(i);
			i = i + 2;
			printf("\n");
		}
		else
		{
			drawSpace(j);
			drawSlash(i);
			i = i + 2;
			printf("\n");
		}
		j--;
	}
}

//pitched roof
void pitchedRoof(int roofWidth)
{
	if(roofWidth%2==0)   //pitched roof for even numbers
	{
		int i = roofWidth/2;
		int space = 2;
		while(i>0)
		{
			printf("  ");
			if(i == roofWidth/2)
			{
				drawSpace(i);
				printf("/\\ \n");
			}
			else
			{
				drawSpace(i);
				printf("/--");
				drawSpace(space);
				printf("--\\ \n");
				space = space + 6;
			}
			i = i - 3;
		}
	}
	else    //pitched roof for odd numbers
	{
		int i = roofWidth/2 + 1;
		int space = 3;
		while(i>0)
		{
			printf("  ");
			if(i== roofWidth/2 + 1)
			{
				drawSpace(i);
				printf("* \n");
				i--;
				drawSpace(i+2);
				printf("/ \\  \n");
			}
			else if(i == roofWidth/2)
			{
				printf("I: %i \n", i);
				drawSpace(i);
				printf("/\\ \n");
			}
			else
			{
				drawSpace(i);
				printf("/--");
				drawSpace(space);
				printf("--\\ \n");
				space = space + 6;
			}
			i = i - 3;
		}
	}
	printf("   ");
	drawEquals(roofWidth);
	printf("\n");
}

//selecting the flat, gable or pitched roof as provided by the user
void roofSelector(char s, int roofWidth)
{
	if(tolower(s) == 'f')
	{
		flatRoof(roofWidth + 2);
	}
	else if(tolower(s) == 'g')
	{
		gableRoof(roofWidth + 2);
	}
	else
	{
		pitchedRoof(roofWidth);
	}	
}
