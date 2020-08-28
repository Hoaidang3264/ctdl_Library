#include"Giaodien.h"
#include<iostream>
#include<conio.h>

#include"Thongtinthedocgia.h"
#include"Thongtinmuontra.h"
#include"DocGhiFile.h"

void menu()
{
	//DS_DAU_SACH ds_ds;
    
	while (kt == true)
	{
		TextColor(14);
	    dsDauSach ds;
		docFile(ds);
		DS_DG dg;
	
		MUONTRA mt;
		bool kt = true;
		Doc_file_danh_sach_DG(dg);
		Doc_file_danh_sach_MT(dg.tree,ds);
		system("cls");
		Khung_quan_ly_chuc_nang();
		gotoxy(110, 1);
		cout << "1. Them doc gia." << endl;
		gotoxy(110, 2);
		cout << "2. In danh sach doc gia." << endl;
		gotoxy(110, 3);
		cout << "3. Xoa doc gia." << endl;
		gotoxy(110, 4);
		cout << "4. Sua thong tin doc gia." << endl;
		gotoxy(110, 5);
		cout << "5. Muon sach." << endl;
		gotoxy(110, 6);
		cout << "6. Tra Sach." << endl;
		gotoxy(110, 7);
		cout << "7. Xuat Thong tin muon sach cua 1 doc gia." << endl;
		gotoxy(110, 8);
		cout << "8. Doc gia qua han." << endl;
		gotoxy(110, 9);
		cout << "9. Thong ke 10 sach duoc muon nhieu nhat." << endl;
		gotoxy(110, 10);
		cout << "10. QL SACH." << endl;
		gotoxy(110, 11);
		cout << "0. Thoat." << endl;
		int luachon;
		gotoxy(110, 12);
		cout << "Nhap lua chon: " ; cin >> luachon;
		switch (luachon)
		{
		case 1:
		{
//			Nhap_DG(dg);
//			Khung_quan_ly_DG(27,17);
			Them_doc_gia(dg);
			_getch();
			break;
		}
		case 2:
		{
			Menu_Xuat_DG_theo_ma(dg.tree);
//			_getch();
			break;	
		}
		case 3:
		{
			if (dg.tree == NULL)
			{
				cout << "DANH SACH DOC GIA RONG !";
			}
			else
			{
				Xoa_doc_gia_theo_ma(dg);
			}
			_getch();
			break;
		}
		case 4:
		{
			Khung_quan_ly_DG(27, 17);
			Sua_thong_tin_doc_gia(dg);
			_getch();
			break;
		}
		
		case 5:
		{
			Muon_sach(dg.tree,ds);
//			Xuat_Thong_Tin_Phieu_Muon_Tra(dg.tree, ds, 1152);
			_getch();
			break;
		}
		case 6:
			{
				Tra_sach(dg.tree,ds);
				getch();
				break;
			}
		case 7:
			{
				Xuat_danh_sach_DG_dang_muon_sach(dg.tree,ds);
				getch();
				break;
			}
		case 8:
			{
				/// Thong ke nguoi muon qua han
				
				getch();
				break;
			}
		case 9:
			{
				// thong ke top 10 sach
				getch();
				break;
			}
		
		case 10:
		{
			//Xuat_Thong_Tin_Phieu_Muon_Tra(p);
			Quan_ly_sach(ds);
//			_getch();
			break;
		}
		case 0:
		{
			kt = false;
			break;
		}
		}

	}
	Ghi_file_danh_sach_DG(dg.tree);
	ghiFile(ds);
}
//void RunMenu()
//{
//	int chon; 
//    while  (1) {
//    	
//        chon = MenuDong (thucdon);
//        switch (chon) 
//		{
//        
//        case 1: gotoxy (10,20); 
//        		system("cls");
//		        menu();
//				break;
//        case 2:gotoxy (10,20); 
//		        cout << "Vua chon chuc nang " << chon; 
//		         break;
//		case 3: gotoxy (10,20); 
//		        cout << "Vua chon chuc nang " << chon;
//				break;
//        case so_item  : break; 
//        }
//    }
//}

int main()
{
	resizeConsole(2000, 1000);
	//Intro();
	//MainMenu(Chucnang, sizeof(Chucnang) / sizeof(string));
	//Khungten();
	menu();
//RunMenu();
//	Khung_quan_ly_chuc_nang();
//	GiaoDienXuatTheDocGia(1, 1, 1);
//	Menu_Quan_Ly_Doc_Gia(Chuc_nang_DG,5);

	return 0;
}
