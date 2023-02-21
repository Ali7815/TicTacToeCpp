#include <iostream>
#include <conio.h>
using namespace std;
char pattern[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string player1,player2;
char symbol='X';
int digit;
int row,col;
bool tie=false;
int draw=0;
//Function Prototype Start-----------------------------------------------------------------------------------------------------------------
void header();
void structure();
void input();
bool winner();
bool checkrows(char symbol);
bool checkcolumns(char symbol);
bool checkdiagonal(char symbol);
main()
{
	header();
	cout<<"Enter the Name of First Player[X] : ";
	getline(cin,player1);
	cout<<"Enter the Name of Second Player[0] : ";
	getline(cin,player2);
	while(!winner())
	{
	system("cls");
	header();
	structure();
	input();
	winner();
    } 
    if (symbol=='X' && tie==true)
    {
    	cout<<"Congratulation "<<player1 <<",You have won the Game.......";
	}
	if (symbol=='0' && tie==true)
    {
    	cout<<"Congratulation "<<player2 <<",You have won the Game.......";
	}
	else if (tie==false)
	{
	cout<<"Ooops...It is a Draw"<<endl;	
	}
    
}
void header()
{
	cout<<"___________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"   ______________        ___________        ______________                 ____________       ____________    ___________     _____________  "<<endl;
	cout<<"          |         |   |                         |             ||        |                        |         |           |   |              "<<endl; 
	cout<<"          |         |   |                         |            |  |       |                        |         |           |   |              "<<endl; 
	cout<<"          |         |   |                         |           |    |      |                        |         |           |   |____________  "<<endl; 
	cout<<"          |         |   |                         |          |______|     |                        |         |           |   |              "<<endl; 
	cout<<"          |         |   |                         |         |        |    |                        |         |           |   |              "<<endl; 
	cout<<"          |         |   |___________              |        |          |   |____________            |         |___________|   |____________ "<<endl; 
	cout<<"___________________________________________________________________________________________________________________________________________"<<endl;
}
void structure()
{
	cout<<"                               "<<endl;
	cout<<"                               "<<endl;
	cout<<"\t\t\t\t      |      |                "<<endl;
	cout<<"\t\t\t\t  "<<pattern[0][0]<<"   |"<<"  "<<pattern[0][1]<<"   |"<<"  "<<pattern[0][2]<<endl;
	cout<<"\t\t\t\t _____|______|______          "<<endl;
	cout<<"\t\t\t\t      |      |                "<<endl;
	cout<<"\t\t\t\t  "<<pattern[1][0]<<"   |"<<"  "<<pattern[1][1]<<"   |"<<"  "<<pattern[1][2]<<endl;
	cout<<"\t\t\t\t _____|______|______          "<<endl;
	cout<<"\t\t\t\t      |      |                "<<endl;
    cout<<"\t\t\t\t  "<<pattern[2][0]<<"   |"<<"  "<<pattern[2][1]<<"   |"<<"  "<<pattern[2][2]<<endl;
	cout<<"\t\t\t\t      |      |                "<<endl;
}
void input()
{
	if(symbol=='X')
	{
		cout<<player1<<" enter your position[X] : ";
		cin>>digit; 
	}
	if(symbol=='0')
	{
		cout<<player2<<" enter your position[0] : ";
		cin>>digit; 
	}
	if (digit==1)
	{
		row=0;
		col=0;
	}
	if (digit==2)
	{
		row=0;
		col=1;
	}
	if (digit==3)
	{
		row=0;
		col=2;
	}
	if (digit==4)
	{
		row=1;
		col=0;
	}
	if (digit==5)
	{
		row=1;
		col=1;
	}
	if (digit==6)
	{
		row=1;
		col=2;
	}
	if (digit==7)
	{
		row=2;
		col=0;
	}
	if (digit==8)
	{
		row=2;
		col=1;
	}
	if (digit==9)
	{
		row=2;
		col=2;
	}
	if (digit<=0 || digit>9)
	{
		cout<<"Invalid Input.........................."<<endl;
		cout<<"Press any key to Continue............"<<endl;
		getch();
	}
	if(symbol=='X' && pattern[row][col]!='X' && pattern[row][col]!='0')
	{
		pattern[row][col]='X';
		symbol='0';
		draw++;
	}
	else if(symbol=='0' && pattern[row][col]!='X' && pattern[row][col]!='0')
	{
		pattern[row][col]='0';
		symbol='X';
		draw++;
	}
	else
	{
    cout<<"Space is already Filled"<<endl;
    cout<<"Press any key to Continue........."<<endl;
    getch();
    }
}
bool checkrows(char symbol)
{
	int count=0;
	for (int row=0 ; row<3 ; row++)
	{
		count=0;
		for (int col=0 ; col<3 ; col++)
		{
			if (pattern[row][col]==symbol)
			{
				count++;
			}
		}
		if (count==3)
		{
			return true;
		}
	}
	return false;
}
bool checkcolumns(char symbol)
{
	int count=0;
	for (int col=0 ; col<3 ; col++)
	{
		count=0;
		for (int row=0 ; row<3 ; row++)
		{
			if (pattern[row][col]==symbol)
			{
				count++;
			}
		}
		if (count==3)
		{
			return true;
		}
	}
	return false;
}
bool checkdiagonal(char symbol)
{
	int count=0;
	for (int idx=0 ; idx<3 ; idx++)
	{
		if (pattern[idx][idx]==symbol)
		{
			count++;
		}
	}
	if (count==3)
	{
		return true;
	}
	count=0;
	for (int row=0,col=2 ;row<3 ; row++,col--)
	{
		if (pattern[row][col]==symbol)
		{
			count++;
		}
	}
	if (count==3)
	{
		return true;
	}
	return false;
}
bool winner()
{
	if (checkrows(symbol) || checkcolumns(symbol) || checkdiagonal(symbol))
	{
		tie=true;
		return true;
	}

	else
	
	{
		return false;
	}
}

