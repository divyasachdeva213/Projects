#include<iostream>
#include<stdlib.h>
using namespace std;
char b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	char turn='X';
	int row,col;
	bool draw=false;
void display()
{
	system("cls");
		cout<<"     tick    "<<endl;
	cout<<"\t Player1 [X] \n\t Player2 [O] \n\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t "<<b[0][0]<<"   |  "<<b[0][1]<<"  |  "<<b[0][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<b[1][0]<<"  |  "<<b[1][1]<<"  |  "<<b[1][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<b[2][0]<<"  |  "<<b[2][1]<<"  |  "<<b[2][2]<<"  \n";
	cout<<"\t\t     |     |     \n";
}

void plturn()
{
	int choice;
	if(turn=='X')
		cout<<"\n\t Player1 [X] turn:";
		if(turn=='O')
		cout<<"\n\t Player2 [O] turn:";
	cin>>choice;
	switch(choice)
	{
		
		case 1: row=0;col=0; break;
		case 2: row=0;col=1; break;
		case 3: row=0;col=2; break;
		case 4: row=1;col=0; break;
		case 5: row=1;col=1; break;
		case 6: row=1;col=2; break;
		case 7: row=2;col=0; break;
		case 8: row=2;col=1; break;
		case 9: row=2;col=2; break;
		
			default:
				cout<<"Invalid choice"<<endl;
				break;
			
	}
	if(turn=='X' && b[row][col]!='X' && b[row][col]!='O')
	{
		b[row][col]='X';
		turn='O';
	}
	else if(turn=='O'&& b[row][col]!='X' && b[row][col]!='O')
	{
		b[row][col]='O';
		turn='X';
	}
	else
	{
		cout<<"Box already filled! \n plz try again!! \n\n";
		plturn();
	}
	display();
}
bool gameover()
{
	for(int i=0;i<3;i++)
	if(b[i][0]==b[i][1] && b[i][0]==b[i][2] || b[0][i]==b[1][i] && b[0][i]==b[2][i])
	 return false;
	 
	 if(b[0][0]==b[1][1] && b[0][0]==b[2][2] || b[0][2]==b[1][1] && b[0][2]==b[2][0])
	 return false;
	 
	 for(int i=0;i<3;i++)
	 for(int j=0;j<3;j++)
	 if(b[i][j]!= 'X' && b[i][j]!='O')
	   return true;
	   
	//draw
	   draw=true;
	   return false;
	
}
int main()
{
	
	while(gameover())
	{
	
	display();
	plturn();
	gameover();
	
}
	if(turn=='X' && draw==false)
	  cout<<"Player2 [O] Wins!! Congo....\n";
	  else if(turn=='O'&& draw==false)
	  cout<<"Player1 [X] Wins!! Congo....\n";
	  else
	  cout<<"GAME DRAW!!";
}
