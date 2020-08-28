#pragma once

#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <iomanip>
#include "Xulychuoi.h"

using namespace std;

#define Y_MAIN 15

const int so_item = 4;
const int dong =15;
const int cot = 100 ;
const int Up = 72;
const int Down = 80;
const int Enter = 13;
// key
//#define SPACE  32
//#define ESC  27
//#define ENTER 13
//#define BACKSPACE 8
//#define KEY_UP 72
//#define KEY_DOWN 80
//#define KEY_LEFT 75
//#define KEY_RIGHT 77
//#define KEY_F2 60
//#define KEY_F3 61
//#define KEY_F4 62
//#define KEY_F5 63
//#define KEY_F10 68
//#define PAGE_DOWN 81
//#define PAGE_UP 73

// Mau

#define GREY 7
#define GREEN 6
#define PURPLE 5


//============================================================================
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//void SetBGColor(WORD color)
//{
//    HANDLE hConsoleOutput;
//    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
//    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
//
//    WORD wAttributes = screen_buffer_info.wAttributes;
//    color &= 0x000f;
//    color <<= 4;
//    wAttributes &= 0xff0f;
//    wAttributes |= color;
//
//    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
//}


//void gotoxy(short x, short y)
//{
//	HANDLE hConsoleOutput;
//	COORD Cursor_an_Pos = { x, y };
//	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
//}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void TextColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void Normal() {
	TextColor(11);
	SetBGColor(0);
}

void setColor(int textColor, int BackColor) {
	// converts the textColor and BackColor to one
	int color = textColor + (BackColor * 16);

	// creates the handle we need to use
	HANDLE Console_Handle;

	// grab the handle so we can use it
	Console_Handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// sets the color desired
	SetConsoleTextAttribute(Console_Handle, color);
}

//===================================XU LY=========================

string CanDeuChuoi(string str, int ChieuRong)
{
	if (str.empty())
	{
		return str;
	}
	else if (str.length() > ChieuRong)
	{
		return str;
	}
	return string((ChieuRong - str.length()) / 2, ' ') + str;
}

//===============================GIAO DIEN=========================
// Hàm xóa màn hình.
void XoaManHinh()
{
	for (int i = 3; i < 29; i++)
	{
		gotoxy(2, i);
		cout << "                                                           ";
	}
}

void Intro() {
	string a;
	ifstream file("tieude.txt");
	while (!file.eof()) {
		getline(file, a);
		cout << a << endl;
	}
}

void XuatPage(int page)
{
	gotoxy(48, 34);
	cout << char(174);
	gotoxy(52, 34);
	cout << char(175);
	gotoxy(50, 34);
	cout << page;
}

void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauSet)
{
	setColor(mauSet, 0);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoxy(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoxy(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoxy(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoxy(chieudai + toadoX, i);
		cout << (char)179;
	}
	setColor(7, 0);
}

void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	TextColor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
	TextColor(7);
}

void XoaHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mau)
{
	TextColor(mau);
	for (int j = toadoY + 1; j < toadoY + chieucao; j++)
	{
		for (int i = toadoX + 1; i < toadoX + chieudai; i++)
		{
			gotoxy(i, j);
			cout << " ";
		}
	}
}

void Khungten() {
	TextColor(11);
	gotoxy(25, 14); cout << char(218); // moc phai
	for (int i = 0; i < 15; i++) {
		gotoxy(26 + i, 14); cout << char(196); // thang ngang
	}
	cout << "THONG TIN";
	for (int i = 24; i < 39; i++) {
		gotoxy(26 + i, 14); cout << char(196);
	}

	cout << char(191); // moc trai

	for (int i = 1; i < 16; i++) {
		gotoxy(25, 14 + i); cout << char(179); // cot thang
		gotoxy(65, 14 + i); cout << char(179); // cot thang
	}

	TextColor(14);
	gotoxy(32, 17); cout << "LE PHUOC ANH DAT";
	gotoxy(32, 19); cout << "N17DCCN033";
	gotoxy(45, 19); cout << "D17CQCN01 - N";
	gotoxy(32, 21); cout << "LE NGUYEN HOAI DANG";
	gotoxy(32, 23); cout << "N17DCCN036";
	gotoxy(45, 23); cout << "D17CQCN01 - N";
	gotoxy(32, 25); cout << "TRAN VAN DAO";
	gotoxy(32, 27); cout << "N14DCDT035";
	gotoxy(45, 27); cout << "D14CQDT01 - N";
	TextColor(11);

	gotoxy(25, 29); cout << char(192);
	for (int i = 1; i < 40; i++) {
		gotoxy(25 + i, 29); cout << char(196);
	}
	cout << char(217);

		//chuc nang
//	TextColor(14);
//	SetBGColor(3);
//	gotoxy(30, 38); cout << "         ";
//	gotoxy(30, 39); cout << "  ENTER  ";
//	gotoxy(30, 40); cout << "         ";
//	gotoxy(80, 38); cout << "         ";
//	gotoxy(80, 39); cout << "   ECS   ";
//	gotoxy(80, 40); cout << "         ";
//	TextColor(11);
//	SetBGColor(0);
}

string Chucnang[3] = { " QUAN LI SACH " ," QUAN LI DOC GIA "," THONG KE" };
int taodoxChucnang[5];
// Di chuyen khung chon

// Nen chay
void RunningColor(int x, int y)
{
	gotoxy(x, y);
	setColor(11, 0);
}

void ChangeColorItemMainMenu(string key, int index, int newColor, int oldColor)
{
	gotoxy(taodoxChucnang[index], Y_MAIN);
	setColor(0, newColor);
	cout << key;
	setColor(11, oldColor);
}

void MainMenu(string key[], int nKey)
{
	int center;
	system("color 0B");
	gotoxy(108 - 7, Y_MAIN); cout << char(175); // 2 dau lon hon
	gotoxy(108 + 7, Y_MAIN); cout << char(174); // 2 dau be hon
	for (int i = 0; i < nKey; i++)
	{
		center = 108 - (Chucnang[i].length() / 2);
		taodoxChucnang[i] = center;
		gotoxy(center, Y_MAIN + i * 2);
		cout << " " << Chucnang[i] << " ";
	}
	//ChangeColorItemMainMenu(key[0], 3, 14, 0);
}

char thucdon [so_item][50] = {"      QUAN LI SACH     ",
			                  "     QUAN LI DOC GIA   ",
			                  "       THONG KE        ",
							  "		 THOAT            "};
							  
							  

void HighLight () {
	SetColor(15);
	SetBGColor(2);
}
int MenuDong(char td [so_item][50])
{
  Normal();
  system("cls");   
  int chon =0;
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong + i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==224) 
  kytu = getch();
  switch (kytu) {
    case Up :if (chon >0)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon); 	cout << td[chon];  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon); 	cout << td[chon];
  				
  			  }
  			  break;
  	case Enter : return chon+1;
  }  // end switch
  } while (1);
}
int Menu (char td [so_item][50]){

  system("cls");   int chon =0;
  int i;
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
Nhaplai:
  gotoxy (cot, dong + so_item);
  cout << "Ban chon 1 so (1..10) :    ";
  gotoxy (wherex(), wherey());
  cin >> chon;
  if (chon <1 || chon >so_item) goto Nhaplai;
  return chon;

}

//===========================               VE KHUNG CHON DOC GIA                   ===============================================
void ChonPhai(int toadoX, int toadoY, string& Phai, int pointer2)
{
	ShowCur(0);
	int pointer1 = toadoX;
	while (true)
	{
		gotoxy(toadoX, toadoY);
		cout << "Nam";
		gotoxy(toadoX + 15, toadoY);
		cout << "Nu";

		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 75)
				{
					if (pointer1 == toadoX)
						pointer1 = toadoX + 15;
					else
						pointer1 = toadoX;
				}
				else if (c == 77)
				{
					if (pointer1 == toadoX + 15)
						pointer1 = toadoX;
					else
						pointer1 = toadoX + 15;
				}
			}
			if (c == 13)
			{
				gotoxy(58, 27);
				cout << "   ";
				gotoxy(pointer1, toadoY);
				setColor(4, 0);
				if (pointer1 == toadoX)
				{
					cout << "Nam";
					gotoxy(58, 27);
					cout << "Nam";
					Phai = "Nam";
				}
				else if (pointer1 == toadoX + 15)
				{
					cout << "Nu";
					gotoxy(58, 27);
					cout << "Nu";
					Phai = "Nu";
				}
				TextColor(7);
				break;
			}
		}

		gotoxy(pointer1, toadoY);
		setColor(4,0);
		if (pointer1 == toadoX)
		{
			cout << "Nam";
		}
		else if (pointer1 == toadoX + 15)
		{
			cout << "Nu";
		}
		TextColor(7);
		Sleep(100);
	}
}

void Khung_quan_ly_chuc_nang()
{
	VeHCN(0, 0, 100, 35, 14);
	cout << endl;
}

void Khung_quan_ly_DG(int toadoX, int toadoY)
{
	gotoxy(5, 15);
	cout << "Ma The:";
	VeHCN(27, 14, 50, 2, 4);
	gotoxy(5, 18);
	cout << "Nhap Ho va Ten Lot:";
	VeHCN(toadoX, toadoY, 50, 2, 15);
	gotoxy(5, 21);
	cout << "Nhap Ten:";
	VeHCN(toadoX, toadoY + 3, 50, 2, 15);
	gotoxy(5, 24);
	cout << "Nhap Ngay Sinh:";
	gotoxy(30, 24);
	cout << "/  " << "/  ";
	VeHCN(toadoX, toadoY + 6, 20, 2, 15);
	gotoxy(5, 27);
	cout << "Chon Phai:";
	VeHCN(57, 26, 20, 2, 4);
	gotoxy(toadoX + 5, toadoY + 10);
	cout << "Nam";
	gotoxy(toadoX + 20, toadoY + 10);
	cout << "Nu";
	gotoxy(toadoX + 15, toadoY + 15);
	cout << "Dang Ki";
	gotoxy(toadoX + 30, toadoY + 15);
	cout << "Cancel\n\n" << endl;
}

void GiaoDienXuatTheDocGia(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 100;

	ToMauHCN(toadoX, toadoY - 1, chieudai, 4, 180);
	TextColor(180);
	gotoxy(toadoX + 1, toadoY + 1);
	cout << CanDeuChuoi("Ma The", 9);
	gotoxy(toadoX + 11, toadoY + 1);
	cout << CanDeuChuoi("Ho va Ten", 39);
	gotoxy(toadoX + 46, toadoY + 1);
	cout << CanDeuChuoi("Ngay sinh", 14);
	gotoxy(toadoX + 61, toadoY + 1);
	cout << CanDeuChuoi("Phai", 11);
	gotoxy(toadoX + 73, toadoY + 1);
	cout << CanDeuChuoi("Trang Thai", 11);
	/*gotoxy(toadoX + 73, toadoY + 1);
	cout << CanDeuChuoi("So Sach", 11);
	gotoxy(toadoX + 73, toadoY + 2);
	cout << CanDeuChuoi("Dang Muon", 11);
	gotoxy(toadoX + 85, toadoY + 1);
	cout << CanDeuChuoi("So Ngay", 15);
	gotoxy(toadoX + 85, toadoY + 2);
	cout << CanDeuChuoi("Qua Han", 15);*/

}

//================== MENU QUAN LY DOC GIA ================================
typedef char str[30];
str Chuc_nang_DG[5] = { "THEM DOC GIA" , "XOA DOC GIA" , "SUA THONG TIN DOC GIA" , "MUOC SACH" , "IN DANH SACH DOC GIA" };
enum TRANGTHAI { UP, DOWN, LEFT, RIGHT, ENTER };
TRANGTHAI key(int x)
{
	if (x = 224)
	{
		char c;
		c = _getch();
		if (c == 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 77)
			return LEFT;
		if (c == 75)
			return RIGHT;
	}
	else if (x == 13)
		return ENTER;
}
int Menu_Quan_Ly_Doc_Gia(str Chucnang[5], int n)
{
	int tt = 0;
	int* mau = new int[n];
	for (int i = 0; i < n; i++)
		mau[i] = 7;
	mau[0] = 11;
	while (1)
	{
		clrscr();
		for (int i = 0; i < n; i++)
		{
			//gotoxy(110, 1 + i);
			TextColor(mau[i]);
			cout << Chuc_nang_DG[i]<<endl;
		}

		int x = _getch();
		TRANGTHAI trangthai = key(x);
		switch (trangthai)
		{
		case UP:
		{
			if (tt == 0)
				tt == n - 1;
			else
				tt--;
			break;
		}
		case DOWN:
		{
			if (tt == n - 1)
				tt == 0;
			else
				tt++;
			break;
		}
		case ENTER:
		{
			return tt;
		}
		}
		for (int i = 0; i < n; i++)
			mau[i] = 7;
		mau[0] = 14;
	}
}

