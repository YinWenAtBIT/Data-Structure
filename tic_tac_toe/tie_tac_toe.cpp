/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/1
description:三连棋，使用alpha-beta枝减
********************************************/
#include "tic_tac_toe.h"

void FindComMove(BoardType Board, int *BestMove, int *Value, int Alpha, int Beta)
{
	int Dc, i, j, Response;

	if(FullBoard(Board))
		*Value = Draw;
	else if(ImmediateHumanWin(Board))
		*Value = ComLoss;
	else
	{
		*Value = Alpha;
		for(i =0; i<9 && *Value < Beta; i++)
		{

			if(IsEmpty(Board, i/3, i%3))
			{
				Place(Board, i/3, i%3, 'C');
				FindHumanMove(Board, &Dc, &Response, *Value, Beta);
				Unplace(Board, i/3, i%3);

				if(Response > *Value)
				{
					*Value = Response;
					*BestMove = i;
				}
			}
		}
	}
}







void FindHumanMove(BoardType Board, int *BestMove, int *Value, int Alpha, int Beta)
{
	int Dc, i, j, Response;

	if(FullBoard(Board))
		*Value = Draw;
	else if(ImmediateComWin(Board))
		*Value = ComWin;
	else
	{
		*Value = Beta;
		for(i =0; i<9 && *Value > Alpha; i++)
		{

			if(IsEmpty(Board, i/3, i%3))
			{
				Place(Board, i/3, i%3, 'H');
				FindComMove(Board, &Dc, &Response, Alpha, *Value);
				Unplace(Board, i/3, i%3);

				if(Response < *Value)
				{
					*Value = Response;
					*BestMove = i;
				}
			}
		}
	}
}




bool FullBoard(BoardType Board)
{
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(Board[i][j] == ' ')
				return false;

	return true;
	
}

bool ImmediateHumanWin(BoardType Board)
{
	if(Board[0][0] == 'H' && Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2])  
    {  
		return true;
    }  
    if (Board[1][0] == 'H' &&Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2])  
    {  
		return true;
    }  
    if(Board[2][0] == 'H' && Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2])  
    {  
		return true;
    }  
    if (Board[0][0] == 'H' && Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0])  
    {  
        return true;
    }  
    if (Board[0][1] == 'H' && Board[0][1] == Board[1][1] && Board[1][1] == Board[2][1])  
    {  
        return true;
    }  
    if (Board[0][2] == 'H' && Board[0][2] == Board[1][2] && Board[1][2] == Board[2][2])  
    {  
        return true;
    }  
    if (Board[0][0] == 'H' && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])  
    {  
        return true;
    }  
    if (Board[0][2] == 'H' && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0])  
    {  
        return true; 
    }  
    return false;  
}

bool ImmediateComWin(BoardType Board)
{
	if(Board[0][0] == 'C' && Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2])  
    {  
		return true;
    }  
    if (Board[1][0] == 'C' &&Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2])  
    {  
		return true;
    }  
    if(Board[2][0] == 'C' && Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2])  
    {  
		return true;
    }  
    if (Board[0][0] == 'C' && Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0])  
    {  
        return true;
    }  
    if (Board[0][1] == 'C' && Board[0][1] == Board[1][1] && Board[1][1] == Board[2][1])  
    {  
        return true;
    }  
    if (Board[0][2] == 'C' && Board[0][2] == Board[1][2] && Board[1][2] == Board[2][2])  
    {  
        return true;
    }  
    if (Board[0][0] == 'C' && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])  
    {  
        return true;
    }  
    if (Board[0][2] == 'C' && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0])  
    {  
        return true; 
    }  
    return false;  
}

bool IsEmpty(BoardType Board, int i, int j)
{
	return Board[i][j] == ' ';
}

void Place(BoardType Board, int i, int j, char value)
{
	Board[i][j] = value;
}

void Unplace(BoardType Board, int i, int j)
{
	Board[i][j] = ' ';
}


void manFirst()
{
	BoardType Board ={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	int BestStep = -1;
	int Value;
	int Result = -2;
	int humanstep;
	while(Result == -2)
	{
		std::cout<<"now the board is:\n";
		DrawBoard(Board);

		do
		{
			std::cout<<"please choose your step: "<<std::endl;
			std::cin>>humanstep;
			humanstep -= 1;
		}while(!IsEmpty(Board, humanstep/3, humanstep%3));

		Place(Board, humanstep/3, humanstep%3, 'H');
		if(ImmediateHumanWin(Board))
			Result = -1;

		else if(!FullBoard(Board))
		{
			FindComMove(Board, &BestStep, &Value,  -1, 1);
		//	FindComMove(Board, &BestStep, &Value);
			Place(Board, BestStep/3, BestStep%3, 'C');
			if(ImmediateComWin(Board))
				Result = 1;
		}
		else
			Result = 0;
	}
	std::cout<<"game over!"<<std::endl;
	DrawBoard(Board);
}



void comFirst()
{
	BoardType Board ={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	int BestStep = -1;
	int Value;
	int Result = -2;
	int humanstep;
	int firststep = random();

	Place(Board, 2*firststep/3,  2*firststep%3, 'C');

	while(Result == -2)
	{
		if(!FullBoard(Board))
		{
			std::cout<<"now the board is:\n";
			DrawBoard(Board);

			do
			{
				std::cout<<"please choose your step: "<<std::endl;
				std::cin>>humanstep;
				humanstep -= 1;
			}while(!IsEmpty(Board, humanstep/3, humanstep%3));

			Place(Board, humanstep/3, humanstep%3, 'H');
			if(ImmediateHumanWin(Board))
				Result = -1;

			else
			{
				FindComMove(Board, &BestStep, &Value,  -1, 1);
			//	FindComMove(Board, &BestStep, &Value);
				Place(Board, BestStep/3, BestStep%3, 'C');
				if(ImmediateComWin(Board))
					Result = 1;
			}
		}
		else
			Result = 0;
	}
	std::cout<<"game over!"<<std::endl;
	DrawBoard(Board);
}

void DrawBoard(BoardType Board)
{
	printf("\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n"
		,Board[0][0],Board[0][1],Board[0][2],Board[1][0],Board[1][1],Board[1][2],Board[2][0],Board[2][1],Board[2][2]); 
}

int random()
{
	return rand()%5;
}


//void FindComMove(BoardType Board, int *BestMove, int *Value)
//{
//	int Dc, i, j, Response;
//
//	if(FullBoard(Board))
//		*Value = Draw;
//	else if(ImmediateHumanWin(Board))
//		*Value = ComLoss;
//	else
//	{
//		*Value = ComLoss;
//		for(i =0; i<9; i++)
//		{
//
//			if(IsEmpty(Board, i/3, i%3))
//			{
//				Place(Board, i/3, i%3, 'C');
//				FindHumanMove(Board, &Dc, &Response);
//				Unplace(Board, i/3, i%3);
//
//				if(Response > *Value)
//				{
//					*Value = Response;
//					*BestMove = i;
//				}
//			}
//		}
//	}
//}
//
//
//
//
//
//
//
//void FindHumanMove(BoardType Board, int *BestMove, int *Value)
//{
//	int Dc, i, j, Response;
//
//	if(FullBoard(Board))
//		*Value = Draw;
//	else if(ImmediateComWin(Board))
//		*Value = ComWin;
//	else
//	{
//		*Value = ComWin;
//		for(i =0; i<9; i++)
//		{
//
//			if(IsEmpty(Board, i/3, i%3))
//			{
//				Place(Board, i/3, i%3, 'H');
//				FindComMove(Board, &Dc, &Response);
//				Unplace(Board, i/3, i%3);
//
//				if(Response < *Value)
//				{
//					*Value = Response;
//					*BestMove = i;
//				}
//			}
//		}
//	}
//}
