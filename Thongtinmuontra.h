#pragma once
#include "Date.h"


using namespace std;

//Danh sách MUONTRA : danh sách liên kết kép 
struct MUONTRA
{
	int Ma_Sach;
	Date Ngay_Muon;
	Date Ngay_Tra;
	int SoNgayQuaHan;
	int Trang_Thai;
//	struct MUOTRA* Left, * Right;
};
struct NODE
{
	MUONTRA data;
	struct NODE* Left;
	struct NODE* Right;
};
typedef struct NODE* nodeptr;

struct DS_MUON_TRA
{
	nodeptr  First;
	nodeptr  Last;
};


//===================================================================================================================================================
