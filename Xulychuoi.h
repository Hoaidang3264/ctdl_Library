#pragma once
#include <iostream>
#include "Giaodien.h"
#include <conio.h>
#include <string>
#include <string.h>

using namespace std;

//======================================================================================================================
bool checkCharacter(char c) {
	if ((int)c > 64 && (int)c < 91)
		return true;
	else if ((int)c > 96 && (int)c < 123)
		return true;
	else if ((int)c > 43 && (int)c < 58)
		return true;
	else if ((int)c == 47 || (int)c == 32 || (int)c == 46 || (int)c == 45 || (int)c == 44) // '/', ' ', '?', '.', '-'
		return true;
	else return false;
}

bool checkString(string s) 
{
	bool temp;

	if (s.length() == 0) return 0;

	for (int i = 0; i < s.length(); i++) {
		if (checkCharacter(s[i]) == false) {
			temp = false;
			break;

		}
		else temp = true;
	}
	return temp;
}

void XoaKhoangTrang(string& s) 
{
	char tempArr[150];
	string tempS;
	//ghi lai chuoi thanh 1 mang char de xu ly	
	int n = 0;
	for (int i = 0; i < s.length(); i++) {
		tempArr[n] = s[i];
		n++;
	}

	////xoa khoang trang
	bool check = false;
	if (tempArr[0] != ' ') {
		tempS += tempArr[0];
		check = true;
	}

	///xu ly cac phan tu sau
	for (size_t i = 1; i < n; i++)
	{
		if (tempArr[i] != ' ')
		{
			tempS += tempArr[i];
			if (check == false) check = true;
		}
		else {
			if (tempArr[i + 1] != ' ' && i != n - 1 && check == true)
			{
				tempS += tempArr[i];
				//				cout << tempS << "." << endl;
			}
		}
	}
	//	cout << "Chuoi sau khi xu ly:" << tempS << "." << endl;

}

char chuyenInHoa(char& c) {
	if ((int)c > 96 && (int)c < 123) c -= 32;
	return c;
}

string chuyenInHoaS(string& s) {
	int t;
	for (int i = 0; i < s.length(); i++) {
		t = (int)s[i];
		if (t > 96 && t < 123) t -= 32;
		s[i] = (char)t;
	}
	return s;
}

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void xoaConsoleS(int x, int y,string s){     
		///doi voi con tro co vi tri nhap ban dau
	for(int i = x; i <= x + s.length(); i++){
		gotoxy(i,y); 
		cout << " ";
	}
}

void deleteConsole(int x, int y, int lengh){
	for(int i = x; i <= x + lengh; i++){
		gotoxy(i,y); cout << " ";
	}
}


void nhapS(string &s, int x, int y){
	string error = "Nhap khong hop le!";
	while(true){
		gotoxy(x, y);
		getline(cin,s);
		if(checkString(s) == true) break;
		else {
			xoaConsoleS(x,y,s);
			gotoxy(x + 6,y);
			cout << error << endl;
			getch(); xoaConsoleS(x + 6,y,error);
		}
	}
	
	XoaKhoangTrang(s);
	s = chuyenInHoaS(s);
	
}
 
void nhapInt(int &number, int x, int y){
	string s;
	bool check = false;
	while(true){
		gotoxy (x,y); getline(cin, s);
		if (s.length() < 7){
			for(int i = 0; i <= s.length(); i++){
				if(s[i] >47 && s[i] < 58) check = true;
			}
			if(check == true) break;
			else {
				//xoaConsoleS(x, y, s);
//				deleteConsole(x,y,10);
			}
		}
		else {
			//xoaConsoleS(x, y, s);
			deleteConsole(x,y,10);
		}
	}
	
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '0'){
			if(i == 0) number += 0;
			if(i != 0) number = number*10 + 0;
		}
		
		else if(s[i] == '1'){
			if(i == 0) number += 1;
			if(i != 0) number = number*10 + 1;
		}
		
		else if(s[i] == '2'){
			if(i == 0) number += 2;
			if(i != 0) number = number*10 + 2;
		}
		
		else if(s[i] == '3'){
			if(i == 0) number += 3;
			if(i != 0) number = number*10 + 3;
		}
		
		else if(s[i] == '4'){
			if(i == 0) number += 4;
			if(i != 0) number = number*10 + 4;
		}
		
		else if(s[i] == '5'){
			if(i == 0) number += 5;
			if(i != 0) number = number*10 + 5;
		}
		
		else if(s[i] == '6'){
			if(i == 0) number += 6;
			if(i != 0) number = number*10 + 6;
		}
		
		else if(s[i] == '7'){
			if(i == 0) number += 7;
			if(i != 0) number = number*10 + 7;
		}
		
		else if(s[i] == '8'){
			if(i == 0) number += 8;
			if(i != 0) number = number*10 + 8;
		}
		
		else if(s[i] == '9'){
			if(i == 0) number += 9;
			if(i != 0) number = number*10 + 9;
		}
	}
} 

char Chuyen1SoSangKiTu(int n)
{
	switch (n)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	}
}

string ChuyenSoSangString(int n)
{
	string str;
	int a;
	if (n == 0)
	{
		str = "0";
	}
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}

string NoiHoTen(string ten, string ho)
{
	string tam;
	tam = ten;
	for (int i = 0; i < ho.length(); i++)
	{
		tam.push_back(ho[i]);
	}
	return tam;
}

void Chuan_hoa_chu(string &s)
{
	//Xu ly ky tu dau + cuoi
	while (s[0] == ' ')
	{
		s.erase(s.begin() + 0);
	}
	while (s[s.length() - 1] == ' ')
	{
		s.erase(s.begin() + s.length() - 1);
	}
	//xoa kt giua
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(s.begin() + i);
			i--;
		}
	}

	//Chuan hoa ky tu
	if (s[0] >= 97 && s[0] <= 122)
	{
		s[0] -= 32;
	}

	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			i++;
			if (s[i] >= 97 && s[i] <= 122)
			{
				s[i] -= 32;
			}
		}
		else
		{
			if (s[i] >= 65 && s[i] <= 90)
			{
				s[i] -= 32;
			}
		}
	}
}

string TrangThaiDocGia(int n)
{
	if (n == 1)
		return "Hoat Dong";
	else
		return "Khoa";
}


//=====================         MUON SACH               ===========================================
string TrangThaiMuonTra(int n)
{
	if (n == 0)
		return "Dang Muon";
	else if (n == 1)
		return "Da Tra";
	else if (n == 2)
		return "Da Mat(Da Den)";
	else if (n == 3)
		return "Da Mat(Chua Den)";
}
//*****===================================================================================================********
