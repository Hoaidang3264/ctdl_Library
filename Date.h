#pragma once
#include<iostream>
#include<ctime>
#include"Giaodien.h"

using namespace std;


int SoNgayDcMuon = 7; //so ngay toi da duoc muon sach

struct  Date
{
	int Ngay;
	int Thang;
	int Nam;
};
//typedef struct DATE Date;
// Xu Ly Ngay
bool KT_Nam_Nhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	else
		return false;
}

// Lay Ngay Hien Tai
int ChuyenThang(string str)
{
	if (str == "Jan")
	{
		return 1;
	}
	else if (str == "Feb")
	{
		return 2;
	}
	else if (str == "Mar")
	{
		return 3;
	}
	else if (str == "Apr")
	{
		return 4;
	}
	else if (str == "May")
	{
		return 5;
	}
	else if (str == "Jun")
	{
		return 6;
	}
	else if (str == "Jul")
	{
		return 7;
	}
	else if (str == "Aug")
	{
		return 8;
	}
	else if (str == "Sep")
	{
		return 9;
	}
	else if (str == "Oct")
	{
		return 10;
	}
	else if (str == "Nov")
	{
		return 11;
	}
	else if (str == "Dec")
	{
		return 12;
	}
}
//void LayNgayHienTai(Date& d)
//{
//	// tra ve date/time hien tai dua tren system hien tai
//	time_t hientai = time(0);
//	// chuyen doi hientai thanh dang chuoi
//	char* dt = ctime(&hientai);
//	string str1, str2, str3;
//	//ngay
//	for (int i = 8; i < 10; i++)
//	{
//		str1.push_back(dt[i]);
//	}
//	d.Ngay = atoi(str1.c_str());
//	// thang
//	for (int i = 4; i < 7; i++)
//	{
//		str2.push_back(dt[i]);
//	}
//	d.Thang = ChuyenThang(str2);
//	//nam
//	for (int i = 20; i < 24; i++)
//	{
//		str3.push_back(dt[i]);
//	}
//	d.Nam = atoi(str3.c_str());
//}

void Thoi_Gian_Thuc(Date& x)
{
	time_t t = time(0);
	struct tm* now = localtime(&t);
	x.Ngay = now->tm_mday;
	x.Thang = now->tm_mon + 1;
	x.Nam = now->tm_year + 1900;
}
// 1:ngay > ngay1; 2:ngay < ngay1; 3:ngay=ngay1
int So_Sanh_Ngay(Date d, Date t)
{
	if (d.Nam == t.Nam)
	{
		if (d.Thang == t.Thang)
		{
			if (d.Ngay > t.Ngay)
			{
				return 1;
			}
			else if (d.Ngay < t.Ngay)
			{
				return 2;
			}
			else
				return 3;
		}
		else if (d.Thang > t.Thang)
		{
			return 1;
		}
		else
			return 2;
	}
	else if (d.Nam > t.Nam)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
int SoNgayCuaThang(int thang)
{
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		return 31;
	}
	else if (thang == 2)
	{
		if (KT_Nam_Nhuan)
		{
			return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}
//int SoNgayQuaHan(Date d)
//{
//	Date d1;
//	LayNgayHienTai(d1);
//	if (So_Sanh_Ngay(d1, d) == 1)
//	{
//		if (d.Nam == d1.Nam)
//		{
//			if (d.Thang == d1.Thang)
//			{
//				return d1.Ngay - d.Ngay;
//			}
//			else
//			{
//				return SoNgayCuaThang(d.Thang) - d.Ngay + d1.Ngay;
//			}
//		}
//		else
//		{
//			int SoNgayConLaiCuaNam = 0;
//			for (int i = 1; i < d.Thang; i++)
//			{
//				SoNgayConLaiCuaNam = SoNgayConLaiCuaNam + i * SoNgayCuaThang(i);
//			}
//			if (KT_Nam_Nhuan(d.Nam))
//			{
//				return 366 - SoNgayConLaiCuaNam - d.Ngay + d1.Ngay;
//			}
//			else
//			{
//				return 365 - SoNgayConLaiCuaNam - d.Ngay + d1.Ngay;
//			}
//		}
//	}
//	else
//		return 0;
//}
//Date TinhNgay(Date t, int SoNgay)
//{
//	Thoi_Gian_Thuc(t);
//	Date d = t;
//	d.Ngay = d.Ngay + SoNgay;
//	if (d.Ngay > SoNgayCuaThang(d.Thang))
//	{
//		if (d.Thang == 12)
//		{
//			d.Thang = 1;
//			d.Nam = d.Nam + 1;
//		}
//		else
//		{
//			d.Thang = d.Thang + 1;
//		}
//		d.Ngay = d.Ngay - SoNgayCuaThang(t.Thang);
//	}
//	return d;
//}


void In_ngay_hien_tai(Date& d)
{
	Thoi_Gian_Thuc(d);
	cout << d.Ngay << "/" << d.Thang << "/" << d.Nam;
}

void Ngay_tra_sach(Date& d, Date& t)
{
	Thoi_Gian_Thuc(d);
	t = d;
	t.Ngay = d.Ngay + SoNgayDcMuon;
	if (t.Ngay > SoNgayCuaThang(d.Thang))
	{
		if (d.Thang == 12)
		{
			t.Thang = 1;
			t.Nam = d.Nam + 1;
		}
		else
		{
			t.Thang = d.Thang + 1;
		}
		t.Ngay = t.Ngay - SoNgayCuaThang(d.Thang);
	}
	//cout << t.Ngay << "/" << t.Thang << "/" << t.Nam;
}

// Ham kiem tra Ngay/thang/Nam nhap vao co hople hay khong
bool Kiem_Tra_Tinh_Hop_Le(Date x, bool& Ngay, bool& Thang, bool& Nam)
{
	// lay thoi gian thuc he thoong 
	time_t t = time(0);
	struct tm* now = localtime(&t);

	// kiem tra ngay thang nam nhap vao co lon hon ngay hien tai hay khong
	if (x.Nam > now->tm_year + 1900)
	{
		Nam = false; 
		return false;
	}
	else if (x.Nam == now->tm_year + 1900)
	{
		if (x.Thang > now->tm_mon + 1)
		{
			Thang = false;
			return false;
		}
		else if (x.Thang == now->tm_mon + 1)
		{
			if (x.Ngay > now->tm_mday)
			{
				Ngay = false;
				return false;
			}
		}
	}

	// Kiem tra so ngay cua tung thang
	if (x.Thang == 4 || x.Thang == 6 || x.Thang == 9 || x.Thang == 11)
	{
		if (x.Ngay > 30)
		{
			Ngay = false;
			return false;
		}
	}
	else if (x.Thang == 2)
	{
		if (KT_Nam_Nhuan(x.Nam) == true)
		{
			if (x.Ngay > 29)
			{
				Ngay = false;
				return false;
			}
		}
		else
		{
			if (x.Ngay > 28)
			{
				Ngay = false;
				return false;
			}
		}
	}
	else
	{
		if (x.Ngay > 31)
		{
			Ngay = false;
			return false;
		}
	}
	return true; //Dung thi tra ve true
}

// hàm nhập ngày tháng năm
void Nhap_Ngay_Thang_Nam(Date& x)
{
	bool a = true;
	bool b = true;
	bool c = true;
	do
	{
		// KT ngay co hop le khong
		do
		{
			gotoxy(28, 24);
			cin >> x.Ngay;
			if (x.Ngay < 0 || x.Ngay > 31)
			{
				gotoxy(110, 30);
				cout << "Ngay khong hop le. Xin nhap lai" << endl;
				system("pause");
			}
		} while (x.Ngay < 0 || x.Ngay > 31);

		// KT thang co hop le khong
		do
		{
			gotoxy(31, 24);
			cin >> x.Thang;
			if (x.Thang < 0 || x.Thang > 12)
			{
				gotoxy(110, 30);
				cout << "Thang khong hop le. Xin nhap lai" << endl;
				system("pause");
			}
		} while (x.Thang < 0 || x.Thang > 12);

		// KT nam co hop le khong
		do
		{
			gotoxy(34, 24);
			cin >> x.Nam;
			if (x.Nam < 1900)
			{
				gotoxy(110, 30);
				cout << "Nam khong hop le. Xin nhap lai" << endl;
				system("pause");
			}
		} while (x.Nam < 1900);

		if (Kiem_Tra_Tinh_Hop_Le(x, a, b, c) == false)
		{
			gotoxy(110, 30);
			cout << "Ngay thang nam khong hop le. Xin kiem tra lai" << endl;
			system("pause");
		}

	} while (Kiem_Tra_Tinh_Hop_Le(x, a, b, c) == false);

}

int SoNgayQuaHan(Date d)
{
	Date d1;
	Thoi_Gian_Thuc(d1);
	if (So_Sanh_Ngay(d1, d) == 1)
	{
		if (d.Nam == d1.Nam)
		{
			if (d.Thang == d1.Thang)
			{
				return d1.Ngay - d.Ngay;
			}
			else
			{
				int qua_han = 0;
				for(int i = d.Thang + 1; i< d1.Thang;i++)
				{
					qua_han = qua_han + SoNgayCuaThang(i);
				}
				return SoNgayCuaThang(d.Thang) - d.Ngay + d1.Ngay + qua_han;
			}
		}
		else if (d.Nam < d1.Nam)
		{
			int SoNgayConLaiCuaNam = 0;
			int dem = 0;
			if(d1.Nam - d.Nam == 1)
			{
				int demd = 0;
				int demd1 =0;
				for(int i = d.Thang + 1; i <= 12;i++)
				{
					demd = demd + SoNgayCuaThang(i);
				}
				for(int i = 1; i < d1.Thang ; i++)
				{
					demd1 = demd1 + SoNgayCuaThang(i);
				}
				dem = demd + demd1;
				return SoNgayCuaThang(d.Thang) - d.Ngay + d1.Ngay + dem;
			}
			else if(d1.Nam - d.Nam > 1)
			{
				int demd = 0;
				int demd1 =0;
				int dem_nam = 0;
				for(int i = d.Thang + 1; i <= 12 ; i++)
				{
					demd = demd + SoNgayCuaThang(i);
				}
				for(int i = 1; i < d1.Thang ; i++)
				{
					demd1 = demd1 + SoNgayCuaThang(i);
				}
				for(int i = d.Nam + 1; i < d1.Nam ; i++)
				{
					if(KT_Nam_Nhuan(d.Nam)) 
					{
						dem_nam = dem_nam+366;
					}
					else
						dem_nam = dem_nam+365;
				}
				dem = demd + demd1 + dem_nam;
				return SoNgayCuaThang(d.Thang) - d.Ngay + d1.Ngay + dem;
			}
		}
	}
	else
		return 0;
}
