#include "Giaodien.h"
#include<fstream>
#include <iostream>
#include<string>
#include<string.h>
#include<Windows.h>
#include<conio.h>	

/////////////////////////////define_key/////////////////////////////////
#define key_up 72
#define key_down 80
#define f1 59
#define f2 60
#define f3 61
#define f4 62
#define esc 27
#define Enter 13

////////////////////////////define_color////////////////////////////////
#define white 15
#define black 0
#define red 12
#define blue 1
#define background 0
#define draw_color 11
#define text_title_color 14
#define file_data "Data1.txt"
#define MaxList 500


using namespace std;


struct DanhMucSach {
	int maSach;
	int trangThai;  /// 2: da thanh ly 1: co nguoi muon, 0: khong ai muon 
	int viTri;
};

struct dsDanhMucSach {
	DanhMucSach dsm;
	struct dsDanhMucSach* next;
};
typedef struct dsDanhMucSach* dsDMS;


struct dauSach {
	string idDauSach;
	string tenSach;
	int soTrang;
	string tacgia;
	int namXB;
	string theLoai;
	int soLuongSach;
	dsDMS dms;
};

struct dsDauSach {
	int n = 0; ///size of list point
	dauSach* dsDS[MaxList];
};




void xoa_console(int x, int y, int ngang, int doc){
	for(int i = x; i < x + ngang; i++){
		for(int j = y; j < y + doc; j++){
			gotoxy(i,j); cout << " ";
		}
	}
}

void ve_khung(int x, int y, int hang_y, int cot_x){
	SetColor(draw_color);
	///ngang
	for(int i = x; i <= x + cot_x; i++){
		gotoxy(i, y-1); cout << "_";
		gotoxy(i, y + hang_y-1); cout << "-";
	}
	/// doc
	for(int i = y; i < y + hang_y; i++){
		gotoxy(x, i); cout << "|";
		gotoxy(cot_x + x, i); cout << "|";
	}
	SetColor(white);
}

//void insert_after_DMS(dsDMS &p,DanhMucSach &sach){
//	if(p == NULL) {
//		cout << "Them khong thanh cong!!! error" << endl;
//	}
//	else {
//		dsDMS pnew = new dsDanhMucSach;
//		pnew->dsm = sach;
//		pnew->next = p->next;
//		p->next = pnew;
//	}
//} 
 
int insert_first_DMS(dsDMS &First, DanhMucSach &sach){
	dsDMS pnew = new dsDanhMucSach;
	pnew->dsm = sach;
	pnew->next = First;
	First = pnew;
}



dsDMS timID_DMS(dsDauSach ds, int idSach){                                    ///Tra ve vi tri tim duoc id
	for(int i = 0; i < ds.n-1; i++){    /// vi tri n - 1 dang duoc nhap
		dsDMS p = ds.dsDS[i]->dms;
		for (int j = 0; j < ds.dsDS[i]->soLuongSach; j++){
			
			if(p->dsm.maSach == idSach) return p;
			else p = p->next;
		}
	}
	return NULL;
}

int tim_thong_tin_sach(dsDauSach ds, int idSach){                                    ///Tra ve vi tri tim duoc id
	for(int i = 0; i < ds.n; i++){
		dsDMS p = ds.dsDS[i]->dms;
		for (int j = 0; j < ds.dsDS[i]->soLuongSach; j++){
			if(p->dsm.maSach == idSach) {
				return i;
			} 
			else p = p->next;
		}
			
	}
	return -1;
}

int so_luong_DMS(dsDauSach ds){
	int count = 0;
	for(int i = 0; i < ds.n - 1; i++){              
		count += ds.dsDS[i]->soLuongSach;	
	}
	return count;
}

int Tao_ma_DMS(dsDauSach ds){
	int id = so_luong_DMS(ds);
	while(true){
		if(timID_DMS(ds, id) == NULL) return id;
		id++;
	}
}

bool Kiem_tra_viTri(int vitriArr[], int id){
	for(int i = 0; i < 500; i++){
		if(vitriArr[id] > 19) return false;
	}
	return true;
}

void Nhap_vitri(dsDauSach ds, int &vitri, int &vitri_Truoc, int arrVitri[] ,int x_temp, int y_temp){
	
	int demSach = 0, y = y_temp + 1;
	while(true){
		string temps = "";                       //chuyen du lieu thanh dang string de xoa
		gotoxy(x_temp, y_temp); cout << vitri_Truoc << endl;
		gotoxy(x_temp,y);
		gotoxy(5, y_temp + 5);cout << "Bam phim bat ki neu ban muon thay doi thong tin, \"Enter\" neu khong!"; char temp = getch();
	
		if((int)temp == 13 ){
			vitri = vitri_Truoc;
		}
		else {
			temps = "" + vitri_Truoc;
			xoaConsoleS(x_temp, y_temp, temps);
			
			vitri = 0;
			nhapInt(vitri, x_temp, y_temp);
			
			vitri_Truoc = 0;
			vitri_Truoc = vitri;
		}
		
		if(Kiem_tra_viTri(arrVitri, vitri)) {
			arrVitri[vitri]++;
			system("cls");
			break;
		}
		else {
			gotoxy(5, y_temp + 6);cout << "Vi tri " << vitri << " da day! ("<< arrVitri[vitri] << ") Hay chon mot vi tri khac." ;
			temps = "" + vitri;
			xoaConsoleS(x_temp, y_temp, temps);
		}
	}
}


void Them_dms(dsDauSach &ds , dsDMS &First,int n){
	int x = 10 , y = 5;
	int vitri_Truoc = 0, demSach = 0;
	int arrVitri[500]; //dung de kiem tra vi tri da day hay chua
	for (int i = 0; i < 500; i++){
		arrVitri[i] = 0;
	}
	
	for(int i = 0; i < ds.n - 1; i++){
		dsDMS p = ds.dsDS[i]->dms;
		for(int j = 0; j < ds.dsDS[i]->soLuongSach; j++){
			arrVitri[p->dsm.viTri]++;
			p=p->next;
		}
	}
	
	
	
	for(int i = 0; i < n; i++){
		system("cls");
//		xoa_console(x-3, y-1, 6, 30);
		
		SetBGColor(draw_color);
		ve_khung(x-3, y-1 , 6, 35);
		SetBGColor(black);
		
		SetColor(red); SetBGColor(white);
		gotoxy(x + 10, y - 2); cout << " THEM SACH ";
		SetColor(white); SetBGColor(black);
		
		DanhMucSach danhmucsach;
		///Dem xuong dong
		int demY = y; 
		
		gotoxy(x,demY); demY++;
		cout << "ID sach: "; 
		danhmucsach.maSach = Tao_ma_DMS(ds) + demSach; 
		demSach++; 
		cout << danhmucsach.maSach;
		
		gotoxy(x,demY); demY++;
		cout << "Trang thai: 0" << endl;
		danhmucsach.trangThai = 0;
		
		gotoxy(x,demY); demY++;	
		cout << "Vi tri: ";
		danhmucsach.viTri = 0;
		int x_temp = wherex(), y_temp = wherey();
		Nhap_vitri(ds, danhmucsach.viTri,vitri_Truoc, arrVitri, x_temp, y_temp);
		
		insert_first_DMS(First, danhmucsach);
	}
}

int xoa_sach(dsDauSach &ds){
	dsDMS p =NULL, node_Tim = NULL;
	string temp;
	int idSach = 0,x = 50, y = 5;
	
	while(true){
		system("cls");
		SetColor(blue); SetBGColor(white);
		gotoxy(x,y); cout << "Nhap MA SACH muon xoa: "; 
		int x_save = wherex(), y_save = wherey() ;
		xoa_console(x_save, y_save, 10, 1);
		nhapInt(idSach, x_save, y_save); 
		SetColor(white); SetBGColor(black);
		
		for(int i = 0; i < ds.n; i++){
			dsDMS p = ds.dsDS[i]->dms;
//			cout << "so luong : " << ds.dsDS[i]->soLuongSach;
			for(int j = 0; j < ds.dsDS[i]->soLuongSach; j++){
				if(idSach == p->dsm.maSach){
					gotoxy(x-5, y + 4);
					if(p->dsm.trangThai == 0) cout << "Trang thai: CHUA MUON";
					else if(p->dsm.trangThai == 1) cout << "Trang thai: DA MUON";
					else cout << "Trang thai: THANH LY";
					
					gotoxy(x-5, y + 5); cout << "Vi tri: " << p->dsm.viTri;
				}
				p = p->next;
			}
		}
		
		if(idSach!= -1) break;
	}
	
	 
	
	for(int i = 0; i < ds.n; i++){
		p = ds.dsDS[i]->dms;
		node_Tim = ds.dsDS[i]->dms;
		
		for(int j = 0; j < ds.dsDS[i]->soLuongSach; j++){
			if(j == 0){
				if(node_Tim->dsm.maSach == idSach && node_Tim->dsm.trangThai != 1){
					while(true){
						gotoxy(x - 20, y + 15);cout << "Ban co chac chan muon XOA ma sach " << idSach << " khong? (y/n)";
						
						int _key = getch();
						if(_key == 78 || _key == 110){
							temp = "Xoa KHONG thanh cong!!!";
							gotoxy(1,1);  cout << temp; getch();
							xoaConsoleS(1,1,temp);
							return 0;
						}
						else if(_key == 89 || _key == 121){
							ds.dsDS[i]->dms = node_Tim->next;  // con tro cua dau sach tro den dms tiep theo
							temp = "Xoa thanh cong!!!";
							gotoxy(1,1);  cout << temp; getch();
							xoaConsoleS(1,1,temp);
							ds.dsDS[i]->soLuongSach--;
							return 1; // xoa thanh cong
						}	
					}
				}
			}
			
			node_Tim = node_Tim->next;
			if(node_Tim->dsm.maSach == idSach && node_Tim->dsm.trangThai != 1){
				
				while(true){
					gotoxy(x - 20, y + 15);cout << "Ban co chac chan muon XOA ma sach " << idSach << " khong? (y/n)";
					
					int _key = getch();
					if(_key == 78 || _key == 110){
						temp = "Xoa KHONG thanh cong!!!";
						gotoxy(1,1);  cout << temp; getch();
						xoaConsoleS(1,1,temp);
						return 0;
					}
					else if(_key == 89 || _key == 121){
						p->next = node_Tim->next;
						temp = "Xoa thanh cong!!!";
						gotoxy(1,1); cout << temp; getch();
						xoaConsoleS(1,1,temp);
						ds.dsDS[i]->soLuongSach--;
						return 1; // xoa thanh cong
					}
						
				}
			}
			p = p->next;
		}
	}
	temp = "Khong tim thay sach hoac sach dang duoc muon!!!";
	gotoxy(x,y); cout << temp; getch();
	xoaConsoleS(x,y,temp);
	return 0; // xoa khong thanh cong
}


	//Xu ly dau sach
bool Check_idDauSach_add(dsDauSach ds, string id){
	if (ds.n == 1) return true;
	for(int i = 0; i < ds.n - 1; i++){	
		if(ds.dsDS[i]->idDauSach == id){
			return false;
		}
	}
	return true;
}

void ID_dau_sach(dsDauSach ds, string &s, int x, int y){
	string temp;
	while(true){
		gotoxy(x, y);
		s = "";
		for(int i = 0; i < 6; i++){
			while(true){
				temp[i] = getch(); temp[i] = chuyenInHoa(temp[i]);
				if(((int)temp[i] > 64 && (int)temp[i] < 91) || ((int)temp[i] > 47 && (int)temp[i] < 58) ) {
					cout << temp[i];
					break;
				}
				else continue;
			}
			s += temp[i];
		}

		if(!Check_idDauSach_add(ds,s)){
			xoaConsoleS(x,y,s);
			gotoxy(1,1); cout << "ID khong hop le! Moi nhap lai!" << endl;
		}
		else {
			break;
		}
	}
}

bool themSach(dsDauSach &ds){
	int x = 10, y = 5;
	
	
	
	
	while(true)
	{
		ds.n++;
		int count = ds.n-1;
		
		system("cls");
		SetBGColor(draw_color);
		ve_khung(x-3, y-1 , 10, 90);
		SetBGColor(black);
		
		SetColor(red); SetBGColor(white);
		gotoxy(x + 26, y - 2); cout << " THEM DAU SACH ";
		SetColor(white); SetBGColor(black);
		
		int i = 0;
		dauSach *dauSachPtr = new dauSach;
		gotoxy(0, 0); cout << "TONG SO SACH : " << ds.n ;
		
		gotoxy(x, y + i);
		cout << " MA DAU SACH " ; gotoxy(x + 29, y + i); 
		cout << ": ";
		ID_dau_sach(ds, dauSachPtr->idDauSach, wherex(), wherey());i++; 
		
		gotoxy(x, y + i); 
		cout << " TEN SACH " ;gotoxy(x + 29, y + i); 
		cout << ": ";
		nhapS(dauSachPtr->tenSach, wherex(), wherey());i++;
		  
		gotoxy(x, y + i);
		cout << " TAC GIA" ; gotoxy(x + 29, y + i); 
		cout << ": ";
		nhapS(dauSachPtr->tacgia, wherex(), wherey()); i++;
		 
		gotoxy(x, y + i);
		cout << " THE LOAI" ; gotoxy(x + 29, y + i); 
		cout << ": ";
		nhapS(dauSachPtr->theLoai, wherex(), wherey()); i++;
		 
		gotoxy(x, y + i);
		cout << " SO TRANG" ; gotoxy(x + 29, y + i); 
		cout << ": ";
		dauSachPtr->soTrang = 0;
		nhapInt(dauSachPtr->soTrang, wherex(), wherey()); i++;
		 
		gotoxy(x, y + i);
		cout << " NAM XUAT BAN" ;gotoxy(x + 29, y + i);
		cout << ": ";
		int x_temp = wherex(), y_temp = wherey();
		while(true){
			dauSachPtr->namXB =0;
			nhapInt(dauSachPtr->namXB, x_temp, y_temp);
			string s_temp = "" + dauSachPtr->namXB;
			if(dauSachPtr->namXB <= 2020 && dauSachPtr->namXB >= 1800) break;
			else {
				xoaConsoleS(x_temp, y_temp, s_temp);
				deleteConsole(x_temp, y_temp, 8);
			}
		}  i++;
		
		gotoxy(x,y+i);
		cout << " SO SACH THUOC DAU SACH " ; gotoxy(x + 29, y + i);
		cout << ": ";
		dauSachPtr->soLuongSach = 0;
		nhapInt(dauSachPtr->soLuongSach, wherex() , y+i);i++;
		system("cls");
		
		dauSachPtr->dms = new dsDanhMucSach;
		dauSachPtr->dms->next = NULL;
		Them_dms(ds,dauSachPtr->dms,dauSachPtr->soLuongSach);
		
		ds.dsDS[count] = dauSachPtr; count ++;
		system("cls");
		SetBGColor(blue);
		cout << "Ban co muon nhap tiep khong? (y/n)" ;
		SetBGColor(black); 
		int key = getch();
		if(key == 89 || key == 121) {
			system("cls");
		}
		else {
			system("cls");
			break;
		}
		
	}
}

int sua_thong_tin_dau_sach(dsDauSach &ds, string IDDauSach, int x, int y){
	
	ve_khung(x-5, y , 9, 50);
	
	for(int i = 0; i < ds.n; i++){
		if(ds.dsDS[i] != NULL && ds.dsDS[i]->idDauSach == IDDauSach){
		
			int j = 0;
			dauSach *dauSachPtr = new dauSach;
			gotoxy(x + 7, y-1); cout << "THAY DOI THONG TIN DAU SACH";
			
			gotoxy(x, y + j); 
			dauSachPtr->idDauSach = ds.dsDS[i]->idDauSach;
			cout << " MA SACH: ";
			gotoxy(x + 15, y + j);
			cout << dauSachPtr->idDauSach;  
			j++;
			
			gotoxy(x, y + j); 
			cout << " TEN SACH: " ;
			gotoxy(x + 15, y + j);
			nhapS(dauSachPtr->tenSach, wherex() , wherey());
			j++;
			  
			gotoxy(x, y + j); 
			cout << " TAC GIA: " ; 
			gotoxy(x + 15, y + j);
			nhapS(dauSachPtr->tacgia, wherex(), wherey()); 
			j++;
			 
			gotoxy(x, y + j); 
			cout << " THE LOAI: " ; 
			gotoxy(x + 15, y + j);
			nhapS(dauSachPtr->theLoai, wherex(), wherey()); 
			j++;
			 
			gotoxy(x, y + j); 
			cout << " SO TRANG: " ; dauSachPtr->soTrang = 0;
			gotoxy(x + 15, y + j);
			nhapInt(dauSachPtr->soTrang, wherex(), wherey()); 
			j++;
			 
			gotoxy(x, y + j); 
			cout << " NAM XUAT BAN: " ;
			gotoxy(x + 15, y + j); 
			int x_temp = wherex(), y_temp = wherey();
			while(true){
				dauSachPtr->namXB =0;
				nhapInt(dauSachPtr->namXB, x_temp, y_temp);
				string s_temp = "" + dauSachPtr->namXB;
				if(dauSachPtr->namXB <= 2020 && dauSachPtr->namXB >= 1800) break;
				else {
					xoaConsoleS(x_temp, y_temp, s_temp);
					deleteConsole(x_temp, y_temp, 8);
				}
			} 
			j++;
			
			dauSachPtr->soLuongSach = ds.dsDS[i]->soLuongSach;
			gotoxy(x,y+j) ;cout << " SO SACH: " ;
			gotoxy(x + 15, y + j);
			cout << dauSachPtr->soLuongSach; 
			
			dauSachPtr->dms = ds.dsDS[i]->dms;
			gotoxy(x + 30, y - 2);cout << "sua thanh cong!" << endl;
			getch();
			ds.dsDS[i] = dauSachPtr;
			return 1;
		}
	}
	cout << "Khong tim thay sach" << endl; getch();
	system("cls");
}

void ghiFile(dsDauSach &ds){
	
   ofstream outfile;
   outfile.open(file_data);
	
	outfile << ds.n << endl;
	for(int i = 0; i < ds.n; i++ ){
		outfile << ds.dsDS[i]->idDauSach << endl;
		outfile << ds.dsDS[i]->tenSach << endl;
		outfile << ds.dsDS[i]->tacgia << endl;
		outfile << ds.dsDS[i]->soTrang << endl;
		outfile << ds.dsDS[i]->namXB << endl;
		outfile << ds.dsDS[i]->theLoai << endl;
		outfile << ds.dsDS[i]->soLuongSach << endl;
		dsDMS p = ds.dsDS[i]->dms;
		for(int count = 0 ; count < ds.dsDS[i]->soLuongSach; count++){
			outfile << p->dsm.maSach << endl;
			outfile << p->dsm.trangThai << endl;
			outfile << p->dsm.viTri << endl;
			p = p->next;
		}
	}
	
	cout << "Da them sach!" << endl;
    outfile.close();

}


void docFile(dsDauSach &ds){
//	    mo mot file trong che do read.

//   resizeConsole(1000, 500);	
	
   ifstream infile; 
   infile.open(file_data); 
   
   infile >> ds.n; infile.ignore();

   for(int i = 0; i < ds.n; i++ ){
   		ds.dsDS[i] = new dauSach;
		getline(infile, ds.dsDS[i]->idDauSach);
		getline(infile, ds.dsDS[i]->tenSach);
		getline(infile, ds.dsDS[i]->tacgia);
		infile >> ds.dsDS[i]->soTrang; infile.ignore();
		infile >> ds.dsDS[i]->namXB; infile.ignore();
		getline(infile, ds.dsDS[i]->theLoai);

		infile >> ds.dsDS[i]->soLuongSach;infile.ignore();
		
		ds.dsDS[i]->dms = new dsDanhMucSach;
		ds.dsDS[i]->dms->next = NULL;
		for(int j = 0; j < ds.dsDS[i]->soLuongSach; j++){
			DanhMucSach sach;
			
			infile >> sach.maSach; infile.ignore();
			infile >> sach.trangThai; infile.ignore();
			infile >> sach.viTri; infile.ignore();
			
			insert_first_DMS(ds.dsDS[i]->dms, sach);
		}
	}

   infile.close();
   
}

void in_mot_sach(DanhMucSach dms, int x, int y){
	gotoxy(x, y); cout << dms.maSach;
	
	gotoxy(x + 6, y); 
	if(dms.trangThai == 0) cout << "CHUA MUON";
	else if(dms.trangThai == 1) cout << "DA MUON";
	else cout << "THANH LY";
	
	gotoxy(x + 26, y); cout << dms.viTri;
}

void inDSDMS(dsDMS First, int soluong){
	int x = 50, y = 5, lua_chon = 0;
	ve_khung(x-1, y-2, soluong + y -2, 34);
	SetColor(text_title_color);
	gotoxy(x, y-2);cout << "ID";
	gotoxy(x + 5, y-2);cout << "TRANG THAI";
	gotoxy(x + 25, y-2);cout << "VI TRI";
	SetColor(white);
	
	SetColor(draw_color);
	/// truc ngang
	for(int i = x; i < x + 33; i++) {
		gotoxy(i, y-1); cout << "-";
	}
	
	/// truc doc
	gotoxy(x-1, y-2); cout << "|";
	gotoxy(x+4, y-2); cout << "|";
	gotoxy(x+24, y-2); cout << "|";
	gotoxy(x+33, y-2); cout << "|";

	gotoxy(x-1, y-1); cout << "|";
	gotoxy(x+4, y-1); cout << "|";
	gotoxy(x+24, y-1); cout << "|";
	gotoxy(x+33, y-1); cout << "|";
	SetColor(white);
	

	dsDMS p = First;
	for(int count = 0; count < soluong; count++){
		SetColor(draw_color);
		
		gotoxy(x-1, y+count); cout << "|";
		gotoxy(x+4, y+count); cout << "|";
		gotoxy(x+24, y+count); cout << "|";
		gotoxy(x+33, y+count); cout << "|";
		
		SetColor(white);
		
		in_mot_sach(p->dsm,x, y+count);
		p = p->next;
	}
	
	
	getch();system("cls");
}


// dung de kiem tra
bool Check_the_loai_DauSach(dsDauSach ds, string the_loai){
	if (ds.n == 1) return true;
	for(int i = 0; i < ds.n; i++){	
		if(ds.dsDS[i]->theLoai == the_loai){
			return false;
		}
	}
	return true;
}

void Sap_xep_dau_sach(dsDauSach &ds){
	string MinTL, MinT;
	for(int i = 0; i < ds.n-1; i++){
		MinTL = ds.dsDS[i]->theLoai;
		for(int j = i + 1; j < ds.n; j++){
			if(ds.dsDS[j]->theLoai < MinTL ){
				MinTL = ds.dsDS[j]->theLoai;
				dauSach *ptr = ds.dsDS[j];
				ds.dsDS[j] = ds.dsDS[i];
				ds.dsDS[i] = ptr;
			}
		}
	}

	for(int i = 0; i < ds.n-1; i++){
		MinT = ds.dsDS[i]->tenSach;
		for(int j = i + 1; j < ds.n; j++){
			if(ds.dsDS[j]->tenSach < MinT && ds.dsDS[i]->theLoai == ds.dsDS[j]->theLoai){
				MinT = ds.dsDS[j]->tenSach;
				dauSach *ptr = ds.dsDS[j];
				ds.dsDS[j] = ds.dsDS[i];
				ds.dsDS[i] = ptr;
			}
		}
	}
}

void Thong_ke_top_sach(dsDauSach ds){
	int x = 20, y = 6;
	system("cls");
	gotoxy(x + 20, y - 4); cout << "|10 CUON SACH DUOC MUON NHIEU NHAT|";
	
	ve_khung(x-1, y-2, 13, 73);
	SetColor(draw_color);
	 /// ve ngang
	for(int i = x; i < x + 72; i++){
		gotoxy(i, y-1); cout << "=";
	}
	 /// ve doc
	for(int i = y-2; i <= y + 10; i++){
		gotoxy(x + 48, i); cout << "|";
	}
	
	SetColor(text_title_color);
	gotoxy(x+15, y-2); cout << "TEN SACH" ;
	gotoxy(x+52, y-2); cout << "SO SACH DANG MUON" ;
	SetColor(white);
	
	
	int thongKe[ds.n];   /// max_top la danh sach vi tri cua nhung sach co so sach duoc muon nhieu nhat
	
	/// reset bo nho
	for(int i = 0; i < ds.n; i++){
		thongKe[i] = 0;
	}
	
	/// thong ke so sach duoc muon
	for(int i = 0; i < ds.n; i++){
		dsDMS p = ds.dsDS[i]->dms;
		
		for(int j = 0; j < ds.dsDS[i]->soLuongSach; j++){
			if(p->dsm.trangThai == 1)
				thongKe[i]++;
			p = p->next;
		}
		
	}
	
	// tim ra cac sach co nguoi muon nhieu nhat
	int maxtemp = 0, maxtemp_after = 9000,dem = 0;   // dem: da add duoc bao nhieu vi tri co nhieu ng muon nhat
	while(dem < 10){
		// tim dau sach co so sach lon nhat
		maxtemp = 0;
		for(int i = 0; i < ds.n; i++){
			if(thongKe[i] > maxtemp && thongKe[i] < maxtemp_after)
				maxtemp = thongKe[i];
		}
		
		for(int i = 0; i < ds.n; i++){
			
			if(thongKe[i] == maxtemp && dem < 10){
				gotoxy(x + 2, y); cout << ds.dsDS[i]->tenSach;
				gotoxy(x+51, y++); cout << thongKe[i] << endl;
				dem++;
			}
		}
		maxtemp_after = maxtemp;
	}
	
	getch();system("cls");
}

void tim_kiem_sach_ID(dsDauSach ds){
	
	int id_tim = 0, vitriDauSach = 0;
	cout << "Nhap id can tim: "; nhapInt(id_tim, wherex(), wherey());
	vitriDauSach = tim_thong_tin_sach(ds, id_tim);
	
	if(vitriDauSach == -1){
		cout << "Khong tim thay sach!!!" << endl;
	}
	else{
		cout << "Ten sach: " << ds.dsDS[vitriDauSach]->tenSach << endl;
		cout << "Tac gia: " << ds.dsDS[vitriDauSach]->tacgia << endl;
		cout << "The loai: " << ds.dsDS[vitriDauSach]->theLoai << endl;
		cout << "NamXB: " << ds.dsDS[vitriDauSach]->namXB << endl;
		for(dsDMS p = ds.dsDS[vitriDauSach]->dms; p->next != NULL; p = p->next)
			if(p->dsm.maSach == id_tim)
				cout << "Vi tri sach: " << p->dsm.viTri << endl;	
	}
}
		///so sanh bang nhau hay khong
bool so_sanh_S(string s_TimKiem, string s_Nhap){ 
		for(int i = 0; i < s_Nhap.length(); i++){
			if( i >= s_TimKiem.length())
				return false;
			else {
				if (s_Nhap[i] != s_TimKiem[i])
				return false;
			}
		}
		return true;
}

void tim_kiem_sach_TenSach(dsDauSach ds){
	
	int x = 40, y = 1;
	
	while(true){
		system("cls");
		string nhap_tensach; 
		SetColor(blue); SetBGColor(white);
		gotoxy(x,y); cout << "Nhap ten sach can tim: "; 
		int x_save = wherex(), y_save = wherey() ;
		xoa_console(x_save, y_save, 20, 1);
		nhapS(nhap_tensach, x_save, y_save); 
		SetColor(white); SetBGColor(black);
		
		int y_temp = 5;
		
		for(int i = 0; i < ds.n; i++){
			if(so_sanh_S(ds.dsDS[i]->tenSach, nhap_tensach)){
				
				SetColor(text_title_color); SetBGColor(15 - text_title_color);
				xoa_console(50, y_temp, 39,6);
				ve_khung(49, y_temp, 6, 40);
				gotoxy(65, y_temp - 1); cout << "DAU SACH"; 
				gotoxy(50, y_temp); cout << "Ma dau sach: " << ds.dsDS[i]->idDauSach;
				gotoxy(50, y_temp+1); cout << "Ten sach: " << ds.dsDS[i]->tenSach;
				gotoxy(50, y_temp+2); cout << "Tac gia: " << ds.dsDS[i]->tacgia;
				gotoxy(50, y_temp+3); cout << "Nam xuat ban : " << ds.dsDS[i]->namXB;
				gotoxy(50, y_temp+4); cout << "The loai: " << ds.dsDS[i]->theLoai;
				
				gotoxy(10 , y_temp - 2); cout << "DANH MUC SACH"; 
				ve_khung(4, y_temp, ds.dsDS[i]->soLuongSach+1, 21);
				xoa_console(5, y_temp, 20,ds.dsDS[i]->soLuongSach);
				
				dsDMS p = ds.dsDS[i]->dms;
				gotoxy(5, y_temp - 1); cout << "Ma sach";
				gotoxy(14, y_temp - 1); cout << "|";
				gotoxy(15, y_temp - 1); cout << "Trang thai";
				
				for(int j = 0; j < ds.dsDS[i]->soLuongSach; j++){
					gotoxy(5, y_temp+j); cout << p->dsm.maSach;
					gotoxy(15, y_temp+j);
					gotoxy(14, y_temp+j); cout << "|";
					if(p->dsm.trangThai == 0) cout << "CHUA MUON";
					else if(p->dsm.trangThai == 1) cout << "DA MUON";
					else cout << "THANH LY";
					p = p->next;
				} 
				SetColor(white); SetBGColor(black);
				getch(); system("cls");
			}
		}
		cout << "Khong con ket qua tim kiem nao khac!\nBam phim bat ki de TIEP TUC, \"Esc\" de THOAT " << endl;
		int key = getch();
		if(key == esc) break;
	}
}

void Quan_ly_sach(dsDauSach ds){
	resizeConsole(2000,1000);
	
//	docFile(ds);
	int x =  10, y = 5;
	Sap_xep_dau_sach(ds);	
	
	int lua_chon = 0, count = 0;
	while(true){
		count = lua_chon - lua_chon%10;
		system("cls"); 
		
		gotoxy(50, 1); cout << "|DANH SACH DAU SACH CUA THU VIEN|";
		
		SetColor(text_title_color); SetBGColor(15-text_title_color);
		gotoxy(8, y+15); cout << "CHUC NANG: ";
		gotoxy(10, y+16); cout << "-Enter: Xem chi tiet danh muc sach";
		gotoxy(10, y+17); cout << "-1: Thay doi thong tin dau sach.";
		gotoxy(10, y+18); cout << "-2: Sap xep lai danh sach dau sach.";
		gotoxy(10, y+19); cout << "-3: Them sach moi.";
		gotoxy(10, y+20); cout << "-4: Tim kiem sach.";
		gotoxy(10, y+21); cout << "-5: Xoa sach.";
//		gotoxy(10, y+22); cout << "-6: Thong ke 10 sach duoc muon nhieu nhat.";
		gotoxy(10, y+23); cout << "-UP, DOWN: Di chuyen con tro.";
		gotoxy(10, y+24); cout << "-Esc: Thoat.";
		SetColor(white); SetBGColor(black);
		
		/// cac de muc
		ve_khung(x-1, y-2, 13, 104);
		SetColor(text_title_color);
		gotoxy(x,y - 2); cout << "ID" ;
		gotoxy(x + 9,y - 2); cout << "TEN SACH" ;
		gotoxy(x + 40,y - 2); cout << "TAC GIA" ;
		gotoxy(x + 60 ,y - 2); cout << "THE LOAI" ;
		gotoxy(x + 80,y - 2); cout << "SO TRANG" ;
		gotoxy(x + 90,y - 2); cout << "NAM XUAT BAN" ;
		SetColor(white);
		
		SetColor(draw_color);
		///cac duong ngan ngang
		for(int i = 0; i < (x+95); i++){
			gotoxy(x - 1+i , y-1); cout << "=" ;
		}
		
		///cac duong ngan doc
		gotoxy(x-1 , y-2); cout << "|" ;
		gotoxy(x+8 , y-2); cout << "|" ;
		gotoxy(x+39 , y-2); cout << "|" ;
		gotoxy(x+59 , y-2); cout << "|" ;
		gotoxy(x+79 , y-2); cout << "|" ;
		gotoxy(x+89 , y-2); cout << "|" ;
		gotoxy(x+103 , y-2); cout << "|" ;
		
		gotoxy(x-1 , y-1); cout << "|" ;
		gotoxy(x+8 , y-1); cout << "|" ;
		gotoxy(x+39 , y-1); cout << "|" ;
		gotoxy(x+59 , y-1); cout << "|" ;
		gotoxy(x+79 , y-1); cout << "|" ;
		gotoxy(x+89 , y-1); cout << "|" ;
		gotoxy(x+103 , y-1); cout << "|" ;
		SetColor(white);
		
		for(int i = 0; i < 10; i ++ ){
			if(lua_chon == count+i) {
				
				xoa_console(x-1, y+i, 104, 1);
				
//				SetBGColor(draw_color);
				gotoxy(x-1 , y + i); cout << "|" ;
				gotoxy(x+8 , y + i); cout << "|" ;
				gotoxy(x+39 , y + i); cout << "|" ;
				gotoxy(x+59 , y + i); cout << "|" ;
				gotoxy(x+79 , y + i); cout << "|" ;
				gotoxy(x+89 , y + i); cout << "|" ;
				gotoxy(x+103 , y + i); cout << "|" ;
				
				SetBGColor(white);
				SetColor(blue);
				
				gotoxy(x,y + i); cout << ds.dsDS[count+i]->idDauSach ;
				gotoxy(x + 9,y + i); cout << ds.dsDS[count+i]->tenSach ;
				gotoxy(x + 40,y + i); cout << ds.dsDS[count+i]->tacgia ;
				gotoxy(x + 60 ,y + i); cout << ds.dsDS[count+i]->theLoai ;
				gotoxy(x + 80,y + i); cout << ds.dsDS[count+i]->soTrang ;
				gotoxy(x + 90,y + i); cout << ds.dsDS[count+i]->namXB ;
				SetBGColor(black);
				
			}
			else if(count+i < ds.n){
				SetColor(draw_color);
				gotoxy(x-1 , y + i); cout << "|" ;
				gotoxy(x+8 , y + i); cout << "|" ;
				gotoxy(x+39 , y + i); cout << "|" ;
				gotoxy(x+59 , y + i); cout << "|" ;
				gotoxy(x+79 , y + i); cout << "|" ;
				gotoxy(x+89 , y + i); cout << "|" ;
				gotoxy(x+103 , y + i); cout << "|" ;
				SetColor(white);
				
				gotoxy(x,y + i); cout << ds.dsDS[count+i]->idDauSach ;
				gotoxy(x + 9,y + i); cout << ds.dsDS[count+i]->tenSach ;
				gotoxy(x + 40,y + i); cout << ds.dsDS[count+i]->tacgia ;
				gotoxy(x + 60 ,y + i); cout << ds.dsDS[count+i]->theLoai ;
				gotoxy(x + 80,y + i); cout << ds.dsDS[count+i]->soTrang ;
				gotoxy(x + 90,y + i); cout << ds.dsDS[count+i]->namXB ;
				
			}
		}
		
		int key = getch();
		

		if(key == 224){
			key = getch();
			
			if(key == key_up){
				if(lua_chon > 0)
					lua_chon--;
			}
			else if(key == key_down){
				if(lua_chon < ds.n-1)
					lua_chon++;
			}
		}
		// enter: xem thong tin chi tiet tung sach
		else if(key == Enter){
			system("cls");
			inDSDMS(ds.dsDS[lua_chon]->dms, ds.dsDS[lua_chon]->soLuongSach);
		}
		/// 1: thay doi thong tin sach 
		else if(key == 49){
			sua_thong_tin_dau_sach(ds, ds.dsDS[lua_chon]->idDauSach, 60, 20);
		}
		/// 2: sap xep lai danh sach
		else if(key == 50){ 
			Sap_xep_dau_sach(ds);
		}
		/// 3: them sach moi
		else if(key == 51){
			themSach(ds);
		}
		/// 4: tim sach
		else if(key == 52){
			tim_kiem_sach_TenSach(ds);
		}
		/// 5: xoa sach
		else if(key == 53){
			xoa_sach(ds);
		}
//		/// 6: thong ke
//		else if(key == 54){
//			Thong_ke_top_sach(ds);
//		}
		else if(key == esc) {
			ghiFile(ds); 
			system("cls");
			break;
		}
	}
}

int Cap_nhat_trang_thai_sach(dsDauSach &ds, int masach, int trangthai){
	for(int i = 0; i < ds.n; i++){
		dsDMS p = ds.dsDS[i]->dms;
		for(int j = 0; j < ds.dsDS[i]->soLuongSach; j++){
			if(p->dsm.maSach == masach)
				if(trangthai >= 0 && trangthai <=2){
					p->dsm.trangThai = trangthai;
					return 1;    ///cap nhat thanh cong
				}
			p = p->next;
		}
	}
	return 0; ////cap nhap that bai
}

//int main(){
//	dsDauSach ds;
//
//	Quan_ly_sach(ds);
//
//	return 0;
//}
