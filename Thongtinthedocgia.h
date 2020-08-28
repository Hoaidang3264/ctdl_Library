#pragma once
#include <iostream>
#include<string>
#include "Thongtinmuontra.h"
#include "Thongtinsach.h"
#include "Date.h"
#include <fstream>
#include<ctime>
#include "Giaodien.h"
#include "Xulychuoi.h"

using namespace std;

const int MaxNodes = 10000;
const int Max_DG = 10000;
static bool* MangRandom = new bool[Max_DG];
const int SoSachMuonToiDa = 3;

//===========================================================CAU TRUC============================================
//Danh sách thẻ độc giả: cây nhị phân tìm kiếm 
struct THEDOCGIA
{
	int Ma_The;
	string Ho;
	string Ten;
	Date Ngaysinh;
	string Phai;
	int Trang_Thai;
	int SoSachDangMuon = 0;
//	MUONTRA MuonTra;
	nodeptr MuonTra;
};
struct NODE_TREE
{
	THEDOCGIA data;
	NODE_TREE* Left;
	NODE_TREE* Right;
};
typedef NODE_TREE* TREE;

struct DS_DG
{
	TREE tree = NULL;
	int SoLuongDocGia = 0;
};
typedef struct DS_DG ds_dg;
//====================================================

//=====================================================================================
bool kiem_tra_ma_doc_gia_trung(TREE t, int ma)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (t->data.Ma_The == ma)
		{
			return 1;
		}
		else if (t->data.Ma_The > ma)
		{
			kiem_tra_ma_doc_gia_trung(t->Left, ma);
		}
		else
		{
			kiem_tra_ma_doc_gia_trung(t->Right, ma);
		}
	}
}

int Random_Ma_DG(TREE t)
{
	srand(time(NULL));
	int ma;
	do
	{
		ma = 1 + rand() % Max_DG;
	} while (kiem_tra_ma_doc_gia_trung(t, ma) == true);
	return ma;
}

////Khoi tao node DG
//NODE_TREE* Khoi_tao_nut_doc_gia()
//{
//	NODE_TREE* t = new NODE_TREE;
//	t->Left = NULL;
//	t->Right = NULL;
//	return t;
//}
//
////==============Them 1 doc gia===============
//void Them_1_doc_gia(TREE& t, NODE_TREE* p)
//{
//	if (t == NULL)
//	{
//		t = p;
//	}
//	else
//	{
//		if (p->data.Ma_The > t->data.Ma_The)
//		{
//			Them_1_doc_gia(t->Right, p);
//		}
//		else if (p->data.Ma_The < t->data.Ma_The)
//		{
//			Them_1_doc_gia(t->Left, p);
//		}
//	}
//}

//Khoi tao node DG
TREE Khoi_tao_nut_doc_gia()
{
	TREE t = new NODE_TREE;
	t->Left = NULL;
	t->Right = NULL;
	return t;
}

//==============Them 1 doc gia===============
void Them_1_doc_gia(TREE& t, TREE p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->data.Ma_The > t->data.Ma_The)
		{
			Them_1_doc_gia(t->Right, p);
		}
		else if (p->data.Ma_The < t->data.Ma_The)
		{
			Them_1_doc_gia(t->Left, p);
		}
	}
}

//void Nhap_DG(ds_dg& dg)
//{
//	TREE t = Khoi_tao_nut_doc_gia();
//	t->data.Ma_The = Random_Ma_DG(dg.tree);
//	cout << "Ma the: " << t->data.Ma_The << endl;
//	cin.ignore();
//	cout << "Nhap ho: ";
//	getline(cin, t->data.Ho);
//	cout << "Nhap ten: ";
//	getline(cin, t->data.Ten);
//	cout << "nhap ngay sinh: ";
//	cin >> t->data.Ngaysinh.Ngay;
//	cin >> t->data.Ngaysinh.Thang;
//	cin >> t->data.Ngaysinh.Nam;
//	cout << "Nhap phai: ";
//	cin.ignore();
//	getline(cin, t->data.Phai);
//	cout << "Nhap Trang thai: ";
//	cin >> t->data.Trang_Thai;
//	//Chuan hoa 
//	Chuan_hoa_chu(t->data.Ho);
//	Chuan_hoa_chu(t->data.Ten);
//	Them_1_doc_gia(dg.tree, t);
//	dg.SoLuongDocGia++;
//}


void Them_doc_gia(ds_dg& dg)
{
	TREE t = Khoi_tao_nut_doc_gia();
	t->data.Ma_The = Random_Ma_DG(dg.tree);
	gotoxy(28, 15);
	cout << t->data.Ma_The;
	cin.ignore();
	gotoxy(28, 18);
	getline(cin, t->data.Ho);
	gotoxy(28, 21);
	getline(cin, t->data.Ten);
	Nhap_Ngay_Thang_Nam(t->data.Ngaysinh);
	cin.ignore();
	ChonPhai(32, 27, t->data.Phai, 17);
	t->data.Trang_Thai = 1;
	//Chuan hoa 
	Chuan_hoa_chu(t->data.Ho);
	Chuan_hoa_chu(t->data.Ten);
	Them_1_doc_gia(dg.tree, t);
	dg.SoLuongDocGia++;
}
//===================IN DANH SACH DOC GIA=====================

//=====Chuyen cay sang mang==============
void chuyen_cay_sang_mang(TREE t, NODE_TREE* ds[], int& nds)
{
	if (t != NULL)
	{
		chuyen_cay_sang_mang(t->Left, ds, nds);
		ds[nds] = new NODE_TREE;
		//data
		ds[nds]->data.Ma_The = t->data.Ma_The;
		ds[nds]->data.Ho = t->data.Ho;
		ds[nds]->data.Ten = t->data.Ten;
		ds[nds]->data.Ngaysinh.Ngay = t->data.Ngaysinh.Ngay;
		ds[nds]->data.Ngaysinh.Thang = t->data.Ngaysinh.Thang;
		ds[nds]->data.Ngaysinh.Nam = t->data.Ngaysinh.Nam;
		ds[nds]->data.Phai = t->data.Phai;
		ds[nds]->data.Trang_Thai = t->data.Trang_Thai;
		nds++; 
		chuyen_cay_sang_mang(t->Right, ds, nds);
	}
}

//void Xuat_DG(NODE_TREE* ds[], int& nds)
//{
//	for (int i = 0; i < nds; i++)
//	{
//		cout << "\t\t=============Nhan vien thu " << i + 1 << "==================" << endl;
//		cout << "Ma the: " << ds[i]->data.Ma_The << endl;
//		cout << "Ho ten: " << ds[i]->data.Ho << " " << ds[i]->data.Ten << endl;
//		cout << "Ngay sinh: " << ds[i]->data.Ngaysinh.Ngay << "/" << ds[i]->data.Ngaysinh.Thang << "/" << ds[i]->data.Ngaysinh.Nam << endl;
//		cout << "Phai: " << ds[i]->data.Phai << endl;
//		cout << "Trang thai: " << ds[i]->data.Trang_Thai << endl;
//	}
//}

//void Xuat_DG(NODE_TREE* ds[], int& nds, int x, int y)
//{
////	GiaoDienXuatTheDocGia(1, 1, 1);
//
//	TextColor(7);
//	int j = 0;
//	for (int i = 0; i < nds; i++)
//	{
//		gotoxy(x + 1, y + 4 + j);
//		cout << CanDeuChuoi(ChuyenSoSangString(ds[i]->data.Ma_The), 9);
//		gotoxy(x + 10 + 1, y + 4 + j);
//		cout << CanDeuChuoi(ds[i]->data.Ho + " " + ds[i]->data.Ten, 39);
//		gotoxy(x + 46 + 1, y + 4 + j);
//		//cout << CanDeuChuoi(ChuyenSoSangString(ds[i]->data.Ngaysinh.Ngay) + "/" + ChuyenSoSangString(ds[i]->data.Ngaysinh.Thang) + "/" +
//		//	ChuyenSoSangString(ds[i]->data.Ngaysinh.Nam),9);
//		cout << ds[i]->data.Ngaysinh.Ngay << "/" << ds[i]->data.Ngaysinh.Thang << "/" << ds[i]->data.Ngaysinh.Nam;
//		gotoxy(x+ 60 + 1, y + 4 + j);
//		cout << CanDeuChuoi(ds[i]->data.Phai, 11);
//		gotoxy(x+ 72 + 1, y + 4 + j);
//		cout << CanDeuChuoi(TrangThaiDocGia(ds[i]->data.Trang_Thai), 11);
//		j = j + 2;
//	}
//	TextColor(7);
//	getch();
//}
void Xuat_ds_DG(NODE_TREE* ds[], int nds, int x, int y)
{
	//GiaoDienXuatTheDocGia(1, 1, 1);
	int dem_so_luong_xuat = 0;
	
	while(true){
		int j = 0;
		system("cls");
		GiaoDienXuatTheDocGia(1, 1, 1);
		for (int i = dem_so_luong_xuat; i < dem_so_luong_xuat + 10 ; i++)
		{
			TextColor(14);
			gotoxy(x + 1, y + 4 + j);
			cout << CanDeuChuoi(ChuyenSoSangString(ds[i]->data.Ma_The), 9);
			gotoxy(x + 10 + 1, y + 4 + j);
			cout << CanDeuChuoi(ds[i]->data.Ho + " " + ds[i]->data.Ten, 39);
			gotoxy(x + 46 + 1, y + 4 + j);
			cout << ds[i]->data.Ngaysinh.Ngay << "/" << ds[i]->data.Ngaysinh.Thang << "/" << ds[i]->data.Ngaysinh.Nam;
			gotoxy(x+ 60 + 1, y + 4 + j);
			cout << CanDeuChuoi(ds[i]->data.Phai, 11);
			gotoxy(x+ 72 + 1, y + 4 + j);
			cout << CanDeuChuoi(TrangThaiDocGia(ds[i]->data.Trang_Thai), 11);
			j = j + 2;
			
			gotoxy(110,28);
			TextColor(7);
			cout<<"Nhan mui ten de chuyen trang!";
			gotoxy(110,30);
			TextColor(7);
			cout<<"NHAN ESC DE THOAT!";
			if(i >= nds-1) break; 
		}
		
		int key = getch();
		
		if(key==224){
			key = getch();
			
			if(key==75){ ///left
				if(dem_so_luong_xuat >=10){
					dem_so_luong_xuat-=10;
				}
			}
			else if(key==77){ ///right
				if(dem_so_luong_xuat < nds - 10){
					dem_so_luong_xuat+=10;
				}
			}
		}
		 if (key== 27){
			break;
		}	
	}
	
	TextColor(14);
	//getch();
}


void Sap_xep_doc_gia_theo_ten(TREE t, NODE_TREE* ds[], int& nds)
{
	NODE_TREE* tam = new NODE_TREE;
	for (int i = 0; i < nds - 1 ; i++)
	{
		for (int j = i + 1; j < nds; j++)
		{
			if (NoiHoTen(ds[i]->data.Ten, ds[i]->data.Ho) > NoiHoTen(ds[j]->data.Ten, ds[j]->data.Ho))
 			{
				tam = ds[i];
				ds[i] = ds[j];
				ds[j] = tam;
			}
		}
	}
}

void Sap_xep_doc_gia_theo_ma(TREE t, NODE_TREE* ds[], int& nds)
{
	NODE_TREE* tam = new NODE_TREE;
	for (int i = 0; i < nds - 1; i++)
	{
		for (int j = i + 1; j < nds; j++)
		{
			if (ds[i]->data.Ma_The > ds[j]->data.Ma_The)
			{
				tam = ds[i];
				ds[i] = ds[j];
				ds[j] = tam;
			}
		}
	}
}

void Menu_Xuat_DG_theo_ma(TREE t)
{
	NODE_TREE* ds[Max_DG];
	int nds = 0;
	chuyen_cay_sang_mang(t, ds, nds);
	//Sap_xep_doc_gia_theo_ten(dg.tree, ds, nds);
	//Sap_xep_doc_gia_theo_ma(t, ds, nds);
	//XuatDanhSachDocGiaTheoPage(ds, nds);
	bool check = true;
			while(check == true)
			{
				system("cls");
//				Khung_quan_ly_chuc_nang();
				gotoxy(110, 1);
				cout << "I. IN DANH SACH DOC GIA THEO TEN." << endl;
				gotoxy(110, 2);
				cout << "II. IN DANH SACH DOC GIA THEO MA TANG DAN." << endl;
				gotoxy(110, 3);
				cout << "III. THOAT." << endl;
				gotoxy(110, 10);
				int luachon;
				cout << "Nhap lua chon: " ; 
				cin >> luachon;
				switch (luachon)
				{
				case 1:
				{
					Sap_xep_doc_gia_theo_ten(t, ds, nds);
					Xuat_ds_DG(ds,nds,1,1);
					//_getch();
					break;
				}
				case 2:
				{
					Sap_xep_doc_gia_theo_ma(t, ds, nds);
					Xuat_ds_DG(ds,nds,1,1);
					//_getch();
					break;
				}
				case 3:
				{
					check = false;
					break;
				}
				}
			}
}


//==================XOA DOC GIA==============================
void Xoa_node(TREE& p, TREE& t)
{
	if (t->Left != NULL)
	{
		Xoa_node(p, t->Left);
	}
	else
	{
		//		tree->data.Ma_The = t->data.Ma_The;
		p->data = t->data;
		p = t;
		t = t->Right;
	}
}


void xoa_1_dg(TREE& t, int ma)
{
	if (t != NULL)
	{
		if (t->data.Ma_The == ma)
		{
			NODE_TREE* p = t;
			if (t->Left == NULL)
			{
				t = t->Right;
			}
			else if (t->Right == NULL)
			{
				t = t->Left;
			}
			else if (t->Left != NULL && t->Right != NULL)
			{
				Xoa_node(p, t->Right);
			}
			delete p;
		}
		else if (t->data.Ma_The > ma)
		{
			xoa_1_dg(t->Left, ma);
		}
		else if (t->data.Ma_The < ma)
		{
			xoa_1_dg(t->Right, ma);
		}
	}
}

void Xoa_doc_gia_theo_ma(ds_dg& dg)
{
	int ma;
	cout << "Nhap ma doc gia: ";
	cin >> ma;
	bool kt = kiem_tra_ma_doc_gia_trung(dg.tree, ma);
	if (kt == true)
	{
		xoa_1_dg(dg.tree, ma);
		dg.SoLuongDocGia--;
		gotoxy(110,30);
		TextColor(180);
		cout << "Xoa thanh cong! ";
	}
	else
	{
		gotoxy(110,30);
		cout << "Ma doc gia khong ton tai ! ";
	}
}

//==================Hieu chinh doc gia========================

void Sua_thong_tin_1_dg(TREE& t, int ma)
{
	if (t != NULL)
	{
		if (t->data.Ma_The == ma)
		{
			gotoxy(28, 15);
			cout << t->data.Ma_The;
			cin.ignore();
			gotoxy(28, 18);
			getline(cin, t->data.Ho);
			gotoxy(28, 21);
			getline(cin, t->data.Ten);
			Nhap_Ngay_Thang_Nam(t->data.Ngaysinh);
			cin.ignore();
			ChonPhai(32, 27, t->data.Phai, 17);
			//t->data.Trang_Thai = TrangThaiDocGia(1);
			//Chuan hoa 
			Chuan_hoa_chu(t->data.Ho);
			Chuan_hoa_chu(t->data.Ten);
		}
		else if (t->data.Ma_The > ma)
		{
			Sua_thong_tin_1_dg(t->Left, ma);
		}
		else if (t->data.Ma_The < ma)
		{
			Sua_thong_tin_1_dg(t->Right, ma);
		}
	}
}

void Sua_thong_tin_doc_gia(ds_dg& dg)
{
	int ma;
	gotoxy(5, 10);
	cout << "Nhap ma doc gia: ";
	VeHCN(27, 9, 10, 2, 4);
	gotoxy(28, 10);
	cin >> ma;
	bool kt = kiem_tra_ma_doc_gia_trung(dg.tree, ma);
	if (kt == true)
	{
		Sua_thong_tin_1_dg(dg.tree, ma);
		gotoxy(110,30);
		TextColor(180);
		cout << "Hieu chinh thanh cong! ";
	}
}


//=================DOC GIA MUON SACH=======================================
nodeptr New_node()
{
	nodeptr p;
	p = (nodeptr)malloc(sizeof(struct NODE));
	return p;
}

void Khoi_tao_node_MT(nodeptr& First)
{
	First = NULL;
}

//Insert first
void Them_1_sach_MT_First(nodeptr& f, MUONTRA &mt)
{
	nodeptr p = New_node();

	p->data = mt;

	if (f == NULL)
	{
		p->Right = NULL;
	}
	else
	{
		p->Right = f;
		f->Left = p;
	}
	f = p;
	p->Left = NULL;
}

void Them_1_sach_MT_Right(nodeptr& p, MUONTRA& mt)
{
	nodeptr q , r;

	//Khoi_tao_node_MT(p);
	if (p == NULL)
	{
		cout << "Nut ko hien huu. Khong the them nut\n";
	}
	else
	{
		q = New_node();
		q->data = mt;
		r = p->Right;
		//tao lien ket giua r va q
		r->Left = q;
		q->Right = r;
		//tao lien ket p va q
		q->Left = p;
		p->Right = q;
	}
}

//void Nhap_thong_tin_MT(nodeptr& p,MUONTRA& mt)
//{
//	nodeptr f;
//	Khoi_tao_node_MT(f);
//	Date Ngayhientai;
//	LayNgayHienTai(Ngayhientai);
//
//	cout << "Nhap ma can muon: ";
//	cin >> mt.Ma_Sach;
//	mt.Ngay_Muon = Ngayhientai;
//	cout << "Ngay Muon: " << Ngayhientai.Ngay << "/" << Ngayhientai.Thang << "/" << Ngayhientai.Nam << endl;
//	Ngay_tra_sach(Ngayhientai, mt.Ngay_Tra);
//	mt.SoNgayQuaHan = 0;
//	mt.Trang_Thai = 0;
//	
//	if (f == NULL)
//	{
//		Them_1_sach_MT_First(p, mt);
//	}
//	else
//	{
//		Them_1_sach_MT_Right(f, mt);
//	}
//}




//int them_thong_tin_MT(nodeptr &p, MUONTRA &mt){
//	nodeptr q = New_node();
//	q->data = mt;
//	q->Right = NULL;
//	q->Left = p;
//	
//	for(int i = 0; i < 3; i++){
//		if(p != NULL){
//			p = p->Right;
//		}
//		else {
//			p = q;
//			return 1;
//		}
//	}
//	cout << "them false" << endl;
//	
//	return 0;
//}

void them_thong_tin_MT(nodeptr &First, MUONTRA &mt){
	
	nodeptr q = new NODE();
	q->data = mt;
	q->Right = First;
	q->Left = NULL;
	
	First = q;
}


// KIEM TRA SACH DA MUON HAY CHUA
bool KT_trang_thai_sach(dsDauSach ds, int idSach) 
{                                                       
	for (int i = 0; i < ds.n; i++) {
		dsDMS p = ds.dsDS[i]->dms;
		for (int j = 0; j < ds.dsDS[i]->soLuongSach; j++) {

			if (p->dsm.maSach == idSach)
			{
				if (p->dsm.trangThai == 0)
					return true;
				else
					return false;
			}
			p = p->next;
		}

	}
}

bool KT_ma_sach_trung(dsDauSach ds, int idSach) 
{                                                       
	for (int i = 0; i < ds.n; i++) {
		dsDMS p = ds.dsDS[i]->dms;
		for (int j = 0; j < ds.dsDS[i]->soLuongSach; j++) {

			if (p->dsm.maSach == idSach){
				return true;
			}
			 p = p->next;
		}

	}
	return false;
}


int Nhap_thong_tin_MT(TREE& t, dsDauSach& ds, int ma)
{

	if (t != NULL)
	{
		if (t->data.Ma_The == ma)
		{	
			int ma_sach_tim;
			while(true){
				cout << "Nhap ma sach can muon: " ; cin>> ma_sach_tim;
				bool check = KT_ma_sach_trung(ds, ma_sach_tim);
				if (check == false)
				{
					gotoxy(1,1);cout << "Sach khong ton tai" << endl;
					return 0;
				}
				else break;
			}
			
			
			//////////KIEM TRA MUON TRUNG DAU SACH
			bool check_trung_dau_sach =true;   // false neu da muon sach 
			for (nodeptr node = t->data.MuonTra; node != NULL; node = node->Right){
				if(node->data.Trang_Thai == 0 || node->data.Trang_Thai == 2){
					int vitriDauSach_da_muon = tim_thong_tin_sach(ds, node->data.Ma_Sach);  
					int vitriDauSach_sap_muon = tim_thong_tin_sach(ds, ma_sach_tim);
					
					if (vitriDauSach_sap_muon == vitriDauSach_da_muon){
						check_trung_dau_sach = false;
						break;
					}
						
				}
			}	
			
			bool check_ngay_qua_han = true; ///neu chua qua han la true
				////lay ngay hien tai
			Date Ngayhientai;
			Thoi_Gian_Thuc(Ngayhientai);
			
			for(nodeptr ptr = t->data.MuonTra; ptr != NULL; ptr = ptr->Right){
				if(ptr->data.Trang_Thai == 0)
					if(So_Sanh_Ngay(ptr->data.Ngay_Tra, Ngayhientai) == 2){
						check_ngay_qua_han = false; break;
					}
			}
			
			
			
			
			if(!check_trung_dau_sach){
				gotoxy(1,1);cout << "Doc gia da muon dau sach nay!"  << endl;
				return 0;
			}
			else if(!check_ngay_qua_han){
				cout << "Doc gia da co sach muon qua 7 ngay!" << endl;
				return 0;
			}
			else 
			{
				/// thay doi trang thai sach co the muon
				int vitriDauSach = tim_thong_tin_sach(ds, ma_sach_tim);
				cout << "Ten sach: " << ds.dsDS[vitriDauSach]->tenSach << endl;
				
				if(t->data.SoSachDangMuon >= 3 || t->data.SoSachDangMuon <0){
					gotoxy(1,1);cout << "So sach cho muon da qua so luong cho phep!"<<endl;
					return 0;
				}
				else {
					for (dsDMS p = ds.dsDS[vitriDauSach]->dms; p->next != NULL; p = p->next){
						if (p->dsm.maSach == ma_sach_tim)
						{
							if (p->dsm.trangThai == 1 || p->dsm.trangThai == 2)
							{
								gotoxy(1,1);cout << "KHONG THE MUON SACH!\nSACH DA DUOC MUON HOAC DA THANH LY!"<< endl;
								return 0;
							}
							else{
								p->dsm.trangThai = 1;
								cout << "da thay doi trang thai" << endl;
								break; // ngung vong for neu tim duoc sach
							}
						}
					}	
				}
				
				nodeptr mt = new NODE;
				///check
//				Date late_time;
//				late_time.Nam = 2020;
//				late_time.Thang = 1;
//				late_time.Ngay = 1;
				
				mt->data.Ma_Sach = ma_sach_tim;
				mt->data.Ngay_Muon = Ngayhientai;
//				mt->data.Ngay_Muon = late_time;
				cout << "Ngay Muon: " << mt->data.Ngay_Muon.Ngay << "/" << mt->data.Ngay_Muon.Thang << "/" << mt->data.Ngay_Muon.Nam << endl;
				Ngay_tra_sach(mt->data.Ngay_Muon, mt->data.Ngay_Tra);
				
				mt->data.SoNgayQuaHan = 0;
				mt->data.Trang_Thai = 0;
				t->data.SoSachDangMuon++;
				cout << "\nSo sach dang muon" << t->data.SoSachDangMuon << endl; 
				  //add
				them_thong_tin_MT(t->data.MuonTra, mt->data);
				
				cout << " trang thai da nhap : " << mt->data.Trang_Thai << endl;
				
				cout << "===============================" << endl;
			}
		}	
		else if (t->data.Ma_The > ma)
		{
			Nhap_thong_tin_MT(t->Left, ds, ma);
		}
		else if (t->data.Ma_The < ma)
		{
			Nhap_thong_tin_MT(t->Right, ds, ma);
		}
		
	}
}

//duyet left=== phai - trai
void Xuat_Thong_Tin_Phieu_Muon_Tra(TREE t, dsDauSach ds, int ma)
{
	if (t != NULL)
	{
		if (t->data.Ma_The == ma)
		{
			if (t->data.MuonTra == NULL)
			{
				cout << "\nDanh sach rong!" << endl;
				return;
			}
			else
			{
				for (nodeptr p = t->data.MuonTra; p != NULL; p = p->Right)
					{
						if(p->data.Trang_Thai == 0){
							int vitrisach = tim_thong_tin_sach(ds,p->data.Ma_Sach);
							cout << "\nMa sach: " << p->data.Ma_Sach << endl; 
							cout << "Ten sach: " << ds.dsDS[vitrisach]->tenSach ;
							cout << "\nNgay muon sach: " << p->data.Ngay_Muon.Ngay << "/" << p->data.Ngay_Muon.Thang << "/" << p->data.Ngay_Muon.Nam;
							cout << "\nNgay tra sach: " << p->data.Ngay_Tra.Ngay << "/" << p->data.Ngay_Tra.Thang << "/" << p->data.Ngay_Tra.Nam;
							cout << "\nTrang thai sach: " << p->data.Trang_Thai << endl;
							cout << "=======================================================\n" ;
						}
						
					}
			}
		}
		else if (t->data.Ma_The > ma)
		{
			Xuat_Thong_Tin_Phieu_Muon_Tra(t->Left, ds, ma);
		}
		else if (t->data.Ma_The < ma)
		{
			Xuat_Thong_Tin_Phieu_Muon_Tra(t->Right, ds, ma);
		}
	}
}


void Thong_tin_dg_muon_sach(TREE t, int ma)
{
	if (t != NULL)
	{
		if (t->data.Ma_The == ma)
		{
			cout << "Ma doc gia:" << t->data.Ma_The << endl;
			cout << "Ten doc gia:" << t->data.Ho << " " << t->data.Ten << endl;
			cout << "Trang thai The:" << TrangThaiDocGia(t->data.Trang_Thai) << endl;
			cout << "So sach dang muon:" << t->data.SoSachDangMuon << endl;
		}
		else if (t->data.Ma_The > ma)
		{
			Thong_tin_dg_muon_sach(t->Left, ma);
		}
		else if (t->data.Ma_The < ma)
		{
			Thong_tin_dg_muon_sach(t->Right, ma);
		}
	}
}

bool KT_Trang_thai_the_DG(TREE t, int tt, int ma)
{
	if (t != NULL)
	{
		if (t->data.Ma_The == ma)
		{
			tt = t->data.Trang_Thai;
			if (tt == 1)
			{
				return true;
			}
			return false;
		}
		else if (t->data.Ma_The > ma)
		{
			KT_Trang_thai_the_DG(t->Left, tt, ma);
		}
		else if (t->data.Ma_The < ma)
		{
			KT_Trang_thai_the_DG(t->Right, tt, ma);
		}
	}
}

bool KT_so_luong_sach_DG(TREE t, int sl, int ma)
{
	if (t != NULL)
	{
		if (t->data.Ma_The == ma)
		{
			sl = t->data.SoSachDangMuon;
			if (sl < SoSachMuonToiDa)
			{
				return true;
			}
			return false;
		}
		else if (t->data.Ma_The > ma)
		{
			KT_so_luong_sach_DG(t->Left, sl, ma);
		}
		else if (t->data.Ma_The < ma)
		{
			KT_so_luong_sach_DG(t->Right, sl, ma);
		}
	}
}


void Muon_sach(TREE& t,dsDauSach& ds)
{
	MUONTRA mt;
	int ma;

	cout << "Nhap ma doc gia: ";
	cin >> ma;
	
	Xuat_Thong_Tin_Phieu_Muon_Tra(t, ds, ma);
	
	bool kt = kiem_tra_ma_doc_gia_trung(t, ma);
	if (kt == false)
	{
		cout << "Ma nhan vien khong ton tai ! " << endl;
	}
	else
	{  
		cout << "\n========================= MUON SACH ==============================\n" ;
		if (KT_Trang_thai_the_DG(t,t->data.Trang_Thai,ma) == false)
		{
			cout << "THE DA KHOA!\nKhong the muon sach!" << endl;
			return;
		}
		if (KT_so_luong_sach_DG(t, t->data.SoSachDangMuon, ma) == false)
		{
			cout << "KHONG THE MUON SACH.\nSO SACH DANG MUON DA DAT TOI DA!"<< endl;
			return;
		}
//		Xuat_Thong_Tin_Phieu_Muon_Tra(t, ds, ma);
		cout << endl ;
		Nhap_thong_tin_MT(t, ds, ma);
		cout << endl;
//		Xuat_Thong_Tin_Phieu_Muon_Tra(t, ds, ma);
	}

}

//========================== TRA SACH ================================


void Nhap_thong_tin_sach_can_tra(TREE& t, dsDauSach& ds, int ma)
{
	if (t != NULL)
	{
		if (t->data.Ma_The == ma)
		{	
		
			int ma_sach_tim;
			cout << "NHAP MA SACH " ; cin>> ma_sach_tim;
			
			bool check = KT_ma_sach_trung(ds, ma_sach_tim);
			if (check == false)
			{
				cout << "SACH KHONG TON TAI"<< endl;
				getch();
			}
			else 
			{
				
				int vitriDauSach = tim_thong_tin_sach(ds, ma_sach_tim);
				cout << "Ten sach: " << ds.dsDS[vitriDauSach]->tenSach << endl;
				
				if(t->data.SoSachDangMuon <=0 ){
					cout << "NGUOI DOC KHONG CON MUON SACH NAO!"<<endl;
				}
				else {
					for (dsDMS p = ds.dsDS[vitriDauSach]->dms; p->next != NULL; p = p->next)
						if (p->dsm.maSach == ma_sach_tim)
						{
							p->dsm.trangThai = 0;
							cout << "\n\n ";
							break; // ngung vong for neu tim duoc sach
						}
					
				}
				
				for(nodeptr ptr = t->data.MuonTra; ptr != NULL; ptr = ptr->Right){
					if(ptr->data.Ma_Sach == ma_sach_tim){
						ptr->data.Trang_Thai = 1;
						cout << "da thay doi trang thai the dang muon" << endl;
						break;
					}
				}
				
				t->data.SoSachDangMuon--;
				cout << "\n SO SACH DOC GIA MUON: " << t->data.SoSachDangMuon << endl; 
				
				cout << "Tra sach thanh cong" << endl; 
				getch();
				
			}
		}	
		
		else if (t->data.Ma_The > ma)
		{
			Nhap_thong_tin_sach_can_tra(t->Left, ds, ma);
		}
		else if (t->data.Ma_The < ma)
		{
			Nhap_thong_tin_sach_can_tra(t->Right, ds, ma);
		}
	}
}

void Tra_sach(TREE& t,dsDauSach& ds)
{
	MUONTRA mt;
	int ma;

	cout << "Nhap ma doc gia: ";
	cin >> ma;
	
	Xuat_Thong_Tin_Phieu_Muon_Tra(t, ds, ma);
	
	bool kt = kiem_tra_ma_doc_gia_trung(t, ma);
	if (kt == false)
	{
		cout << "Ma doc gia khong ton tai ! " << endl;
	}
	else
	{  
		Thong_tin_dg_muon_sach(t, ma);
		if (KT_Trang_thai_the_DG(t,t->data.Trang_Thai,ma) == false)
		{
			cout << "THE DA KHOA!\nKhong the truy cap sach!" << endl;
			return;
		}
		
		cout << endl ; 
		Nhap_thong_tin_sach_can_tra(t, ds, ma);
		cout << endl;
	}

}


void Xuat_danh_sach_DG_dang_muon_sach(TREE t, dsDauSach ds)
{
	MUONTRA mt;
	int ma;

	cout << "Nhap ma doc gia: ";
	cin >> ma;
	
	bool kt = kiem_tra_ma_doc_gia_trung(t, ma);
	if (kt == false)
	{
		cout << "Ma doc gia khong ton tai ! " << endl;
	}
	else
	{  
		Xuat_Thong_Tin_Phieu_Muon_Tra(t, ds, ma);
	}
}

