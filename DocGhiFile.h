#pragma once

#include <iostream>
#include"Thongtinthedocgia.h"
#include <fstream>


// Doc file Ngay Thang Nam
void Doc_File_Ngay_Thang_Nam(ifstream& file, Date& d)
{
	file >> d.Ngay;
	file.ignore();
//	file.seekg(1, 1);
	file >> d.Thang;file.ignore();
//	file.seekg(1, 1);
	file >> d.Nam;file.ignore();
//	file.seekg(1, 1);
}



//void Doc_file_danh_sach_MT(DS_DG& ds_dg)
//{
//	ifstream filein;
//	filein.open("DANHSACHMUONTRA.TX.TXT", ios_base::in);
//	while (filein.eof() != true)
//	{
//		nodeptr p = Khoi_tao_node_muon_tra();
//		filein >> ds_dg.tree->data.Ma_The;
//		filein.seekg(1, 1);
//		getline(filein, p->data.Ma_Sach, ',');
//		Doc_File_Ngay_Thang_Nam(filein, p->data.Ngay_Muon);
//		Doc_File_Ngay_Thang_Nam(filein, p->data.Ngay_Tra);
//		filein >> p->data.Trang_Thai;
//		Them_thong_tin_muon_tra(ds_dg->tree.Right,ds_dg->tree.data.MuonTra->data);
//		ds_dg.tree->data.SoSachDangMuon++;
//	}
//	filein.ignore();
//	filein.close();
//}
//
//// Ghi file Ngay Thang Nam
//void Ghi_File_Ngay_Thang_Nam(ofstream& file, Date d)
//{
//	file << d.Ngay << "/" << d.Thang << "/" << d.Nam;
//}
//
//// Ghi file 1 doc gia


void Doc_file_danh_sach_DG(DS_DG& ds_dg)
{
	ifstream filein;
	filein.open("THEDOCGIA.TXT", ios_base::in);

	if (filein.fail() == true) {
		cout << "Khong tim thay file THEDOCGIA.TXT ";
	}

	while (filein.eof() != true)
	{
		TREE t = Khoi_tao_nut_doc_gia();
		filein >> t->data.Ma_The;
		filein.ignore();
		getline(filein, t->data.Ho, ',');
		getline(filein, t->data.Ten, ',');
		//Doc_File_Ngay_Thang_Nam(filein, t->data.Ngaysinh);
		filein >> t->data.Ngaysinh.Ngay;
		filein.ignore();
		filein >> t->data.Ngaysinh.Thang;
		filein.ignore();
		filein >> t->data.Ngaysinh.Nam;
		filein.ignore();
		getline(filein, t->data.Phai, ',');
		filein >> t->data.Trang_Thai;
		filein.ignore();

		if (filein.eof()) {
			break;
		}

		Them_1_doc_gia(ds_dg.tree, t);
		ds_dg.SoLuongDocGia++;
	}
	
//	NODE_TREE* ds[500];
//	chuyen_cay_sang_mang(ds_dg.tree, ds,ds_dg.SoLuongDocGia);
//	Xuat_ds_DG(ds, ds_dg.SoLuongDocGia, 10,10);
	
	filein.close();
}


//void Doc_file_danh_sach_MT(DS_DG& ds_dg,dsDauSach& ds)
//{
//	ifstream filein;
//	int Ma_dg;
//	filein.open("DANHSACHMUONTRA.TXT", ios_base::in);
//
//	if (filein.fail() == true) {
//		cout << "Khong tim thay file DANHSACHMUONTRA.TXT";
//	}
//
//	while (filein.eof() != true)
//	{
//		ds_dg.tree = Khoi_tao_nut_doc_gia();
//		filein >> ds_dg.tree->data.Ma_The;
//		filein.ignore();
//		
//		if (Ma_dg == 0)
//		{
//			break;
//		}
//		nodeptr p = new NODE;
//		if (p == NULL)
//		{
//			cout << "\nCap phat that bai !";
//			system("pause");
//			return;
//		}
//			filein >> p->data.Ma_Sach;
//			filein.ignore();
//			Doc_File_Ngay_Thang_Nam(filein, p->data.Ngay_Muon);
//			Doc_File_Ngay_Thang_Nam(filein, p->data.Ngay_Tra);
//			filein >> p->data.Trang_Thai;
//			filein.ignore();
//			
//			int vitriDauSach = tim_thong_tin_sach(ds, p->data.Ma_Sach);
//			
//			for (dsDMS k = ds.dsDS[vitriDauSach]->dms; k->next != NULL; k = k->next)
//			{
//				if (k->dsm.maSach == p->data.Ma_Sach)
//				{
//					if (p->data.Trang_Thai == 0) // dang muon
//					{
//						k->dsm.trangThai = 1; //da co doc gia muon
//					}
//					else if (p->data.Trang_Thai == 2)// lam mat
//					{
//						k->dsm.trangThai = 2; //da thanh li
//					}	
//					break; // ngung vong for neu tim duoc sach
//				}
//			}
//
//			them_thong_tin_MT(ds_dg.tree->data.MuonTra, p->data);
//		
//		if (filein.eof()) {
//			break;
//		}
//		ds_dg.SoLuongDocGia++;
//	}
//	filein.close();
//}


void Doc_file_MT(TREE& t, ifstream& filein,dsDauSach& ds, int Ma_dg)
{
	
	if(t != NULL)
	{
		if (t->data.Ma_The == Ma_dg)
		{
			nodeptr p = new NODE;
			if (p == NULL)
			{
				cout << "\nCap phat that bai !";
				system("pause");
				return;
			}
//			filein.ignore();
			filein >> p->data.Ma_Sach;
			filein.ignore();
			Doc_File_Ngay_Thang_Nam(filein, p->data.Ngay_Muon);
			Doc_File_Ngay_Thang_Nam(filein, p->data.Ngay_Tra);
			filein >> p->data.Trang_Thai;
			filein.ignore();
			if (p->data.Trang_Thai == 0)
			{
				t->data.SoSachDangMuon++;
			}
			
//			int vitriDauSach = tim_thong_tin_sach(ds, p->data.Ma_Sach);
			
//			for (dsDMS k = ds.dsDS[vitriDauSach]->dms; k->next != NULL; k = k->next)
//			{
//				if (k->dsm.maSach == p->data.Ma_Sach)
//				{
//					if (p->data.Trang_Thai == 0) // dang muon
//					{
//						k->dsm.trangThai = 1; //da co doc gia muon
//					}
//					else if (p->data.Trang_Thai == 2)// lam mat
//					{
//						k->dsm.trangThai = 2; //da thanh li
//					}	
//					break; // ngung vong for neu tim duoc sach
//				}
//			}

//			them_thong_tin_MT(t->data.MuonTra, p->data);
//			t->data.SoSachDangMuon++;
		if (t->data.MuonTra == NULL)
		{
			t->data.MuonTra = p;
			p->Right = NULL;
			p->Left = NULL;
		}
		else
		{
			nodeptr q = t->data.MuonTra;
			while(true){
				
				if(q->Right == NULL){
					p->Right = NULL;
					q->Right = p;
					p->Left = q;
					break;
				}
				else q = q->Right;
			}
			t->data.MuonTra->Right = p;
			p->Left = t->data.MuonTra->Right;
			p->Right =NULL;
		}
		return;
		}
		else if (t->data.Ma_The > Ma_dg)
		{
			Doc_file_MT(t->Left, filein,ds, Ma_dg);
		}
		else
		{
			Doc_file_MT(t->Right, filein,ds, Ma_dg);
		}
	}
}

void Doc_file_danh_sach_MT(TREE& t, dsDauSach& ds)
{
	ifstream filein;
	int Ma_dg;
	filein.open("DANHSACHMUONTRA.TXT", ios_base::in);

	if (filein.fail() == true) {
		cout << "Khong tim thay file DANHSACHMUONTRA.TXT";
	}

	while (filein.eof() != true)
	{
		cout<<"TOI DAY R KO CHAY";
		Ma_dg = 0;
		filein >> Ma_dg ;
		cout << "ma dg: " << Ma_dg << endl;
		filein.ignore();
		if(Ma_dg ==0)
		{
			break;
		}
		Doc_file_MT(t, filein,ds,Ma_dg);
		if (filein.eof())
		{
			break;
		}
	}
	filein.close();
}

void Ghi_file_1_doc_gia(ofstream& fileout_DG, ofstream& fileout_MT, TREE t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{ 
		Ghi_file_1_doc_gia(fileout_DG, fileout_MT, t->Left);
		fileout_DG << t->data.Ma_The << ",";
		fileout_DG << t->data.Ho << ",";
		fileout_DG << t->data.Ten << ",";
		fileout_DG << t->data.Ngaysinh.Ngay << "/" << t->data.Ngaysinh.Thang << "/" << t->data.Ngaysinh.Nam << ",";
		fileout_DG << t->data.Phai << ",";
		fileout_DG << t->data.Trang_Thai<<".";
		fileout_DG << endl;
		Ghi_file_1_doc_gia(fileout_DG, fileout_MT, t->Right);
		for (nodeptr k = t->data.MuonTra; k != NULL; k = k->Right)
		{
			fileout_MT << t->data.Ma_The << "," << k->data.Ma_Sach << ",";
			fileout_MT << k->data.Ngay_Muon.Ngay << "/" << k->data.Ngay_Muon.Thang << "/" << k->data.Ngay_Muon.Nam << ",";
			fileout_MT << k->data.Ngay_Tra.Ngay << "/" << k->data.Ngay_Tra.Thang << "/" << k->data.Ngay_Tra.Nam << ",";
			fileout_MT << k->data.Trang_Thai << endl;
		}
	}
}
void Ghi_file_danh_sach_DG(TREE t)
{
	ofstream fileout_DG;
	ofstream fileout_MT;
	fileout_DG.open("THEDOCGIA.TXT", ios::out);
	fileout_MT.open("DANHSACHMUONTRA.TXT", ios::out);
	Ghi_file_1_doc_gia(fileout_DG, fileout_MT, t);
	fileout_DG.close();
	fileout_MT.close();
}




//void Ghi_file_1_doc_gia(ofstream& fileout_DG, TREE t)
//{
//	if (t == NULL)
//	{
//		return;
//	}
//	else if( t != NULL)
//	{ 
//		Ghi_file_1_doc_gia(fileout_DG, t->Left);
//		fileout_DG << t->data.Ma_The << ",";
//		fileout_DG << t->data.Ho << ",";
//		fileout_DG << t->data.Ten << ",";
//		fileout_DG << t->data.Ngaysinh.Ngay << "/" << t->data.Ngaysinh.Thang << "/" << t->data.Ngaysinh.Nam << ",";
//		fileout_DG << t->data.Phai << ",";
//		fileout_DG << t->data.Trang_Thai << endl;
//		Ghi_file_1_doc_gia(fileout_DG, t->Right);
//	}
//}
//
//void Ghi_file_danh_sach_DG(TREE t)
//{
//	ofstream fileout_DG;
//	//ofstream fileout_MT;
//
//	fileout_DG.open("THEDOCGIA.TXT", ios::out);
//	//fileout_MT.open("DANHSACHMUONTRA.TXT", ios::out);
//
//	Ghi_file_1_doc_gia(fileout_DG, t);
//
//	fileout_DG.close();
//	//fileout_MT.close();
//}
