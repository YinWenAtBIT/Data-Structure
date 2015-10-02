/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/1
description:三连棋，使用alpha-beta枝减
********************************************/
#include <ctime>
#include <cstdlib>
#include <iostream>

typedef char BoardType[3][3];

#define Draw 0
#define ComWin 1
#define ComLoss -1



void FindComMove(BoardType Board, int *BestMove, int *Value, int Alpha, int Beta);

void FindHumanMove(BoardType Board, int *BestMove, int *Value, int Alpha, int Beta);

//void FindComMove(BoardType Board, int *BestMove, int *Value);
//
//void FindHumanMove(BoardType Board, int *BestMove, int *Value);

bool FullBoard(BoardType Board);

bool ImmediateHumanWin(BoardType Board);

bool ImmediateComWin(BoardType Board);

bool IsEmpty(BoardType Board, int i, int j);

void Place(BoardType Board, int i, int j, char value);

void Unplace(BoardType Board, int i, int j);


void DrawBoard(BoardType Board);

void manFirst();

void comFirst();

int random();