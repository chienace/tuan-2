#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;
int n,a;
struct nhanvien{
	int tuoi,ma;
	int luongcb;
	string ten;
};
typedef struct nhanvien nv;
void nhap(nhanvien &nv)
{
		cout<<"nhap ma nhan vien: ";
		cin>>nv.ma;
		cout<<"nhap ten nhan vien: ";
		cin.ignore();
		getline(cin,nv.ten);
		cout<<" nhap tuoi: ";
		cin>>nv.tuoi;
		cout<<"nhap luong co ban: ";
		cin>>nv.luongcb;
}
void nhapDS(vector<nv> &ds)
{	
	cout<<"nhap so luong nhan vien: ";
	cin>>n;
	ds.resize(n);
	for(int i=0;i<ds.size();i++)
	{
		nhap(ds[i]);
	}
}
void xuat(nhanvien nv)
{
	
		cout<<"ma nhan vien: "<<nv.ma<<endl;
		cout<<"ten nhan vien: "<<nv.ten<<endl;
		cout<<"tuoi nhan vien: "<<nv.tuoi<<endl;
		cout<<"luong co ban: "<<nv.luongcb<<endl;
}
void xuatDS(vector<nv> ds)
{	
	cout<<endl<<"=====ket qua========="<<endl;
	for(int i=0;i<ds.size();i++)
	{
		xuat(ds[i]);
	}
}
// kiem tra nhan vien da co trong danh sach hay chua
int  kt(vector<nv> ds,int manv)
{	
	for(int i=0;i<ds.size();i++)
	{
		if(ds[i].ma==manv)
		return i;
	}
	return -1;

}
// ghi vao file nhi phan
//void ghifile(vector<nv> ds)
//{	
//	fstream f;
//	f.open("D:\\output.dat",ios::out|ios::app);
//	for(int i=0;i<ds.size();i++)
//	{
//		f<<endl<<"ma nhan vien: "<<ds[i].ma<<endl;
//		f<<endl<<"ten nhan vien: "<<ds[i].ten<<endl;
//		f<<endl<<"tuoi nhan vien: "<<ds[i].tuoi<<endl;
//		f<<endl<<"luong co ban: "<<ds[i].luongcb<<endl;
//	}
//	f.close();
//}
// kiem tra dieu kien va them nhan vien vao
void themnv(vector<nv> &ds)
{	
	ds.resize(n);
	nhanvien nv;
	nhap(nv);
	if(kt(ds,nv.ma)==-1)
	{
		ds.push_back(nv);
		//ghi du lieu vao file
			fstream f;
			f.open("D:\\output.dat",ios::out|ios::app);
			f<<"===**thong tin sau khi them**===="<<endl;
			for(int i=0;i<ds.size();i++)
			{
				f<<endl<<"ma nhan vien: "<<ds[i].ma<<endl;
				f<<endl<<"ten nhan vien: "<<ds[i].ten<<endl;
				f<<endl<<"tuoi nhan vien: "<<ds[i].tuoi<<endl;
				f<<endl<<"luong co ban: "<<ds[i].luongcb<<endl;
			}
			f.close();
	}
	else cout<<"!>>thong tin bi trung<<!";
}
//kiem tra dieu kien va xoa nhan vien
void xoa(vector <nv> &ds)
{	
	fstream f;
	f.open("D:\\output.dat",ios::out|ios::app);
	f<<"===**thong tin sau khi xoa**===="<<endl;
	int x,manv;
	nhanvien nv;
	cout<<"nhap ma nhan vien can xoa:";
	cin>>manv;
	if(kt(ds,manv)==-1)   //goi lai ham kt de kiem tra ma nv có xuat hien ko
	{
		cout<<"ko co ma nhan vien nay"<<endl;
		f<<"ko co ma nhan vien nay"<<endl;
	}
	else {	
			x=kt(ds,manv);
			ds.erase(ds.begin()+x);
					////
					for(int i=0;i<ds.size();i++)
					{
						f<<endl<<"ma nhan vien: "<<ds[i].ma<<endl;
						f<<endl<<"ten nhan vien: "<<ds[i].ten<<endl;
						f<<endl<<"tuoi nhan vien: "<<ds[i].tuoi<<endl;
						f<<endl<<"luong co ban: "<<ds[i].luongcb<<endl;
					}
					f.close();
		}
}
// kiem tra dieu kien sau do sua
void sua(vector <nv> &ds)
{	
	fstream f;
	f.open("D:\\output.dat",ios::out|ios::app);
	f<<"===**thong tin sau khi sua**===="<<endl;
	////------------	
	nhanvien nv;
	int manv,x;
	cout<<"nhap ma nhan vien can sua: ";
	cin>>manv;
	if(kt(ds,manv)==-1)
	{
	cout<<"ko co ma nhan vien nay";
	f<<"ko co ma nhan vien nay";
	}
	else {	
			x=kt(ds,manv);
			cout<<"nhap ten nhan vien:";
			cin.ignore();
			getline(cin,nv.ten);
			cout<<"nhap tuoi nhan vien: ";
			cin>>nv.tuoi;
			cout<<"nhap luong cb :";
			cin>>nv.luongcb;
			ds[x].ten=nv.ten;
			ds[x].tuoi=nv.tuoi;
			ds[x].luongcb=nv.luongcb;
			///--------------
			
			for(int i=0;i<ds.size();i++)
			{
				f<<endl<<"ma nhan vien: "<<ds[i].ma<<endl;
				f<<endl<<"ten nhan vien: "<<ds[i].ten<<endl;
				f<<endl<<"tuoi nhan vien: "<<ds[i].tuoi<<endl;
				f<<endl<<"luong co ban: "<<ds[i].luongcb<<endl;
			}
			f.close();
		}
}
// kiem tra dieu kien roi  sau do tim
void tim(vector <nv> ds)
{	
	
	fstream f;
	f.open("D:\\output.dat",ios::out|ios::app);
	f<<"thong tin nhan vien sau khi tim:"<<endl;
	//--------------
	nhanvien nv;
	int manv,x;
	cout<<"nhap ma nhan vien can tim: ";
	cin>>manv;
	if(kt(ds,manv)==-1)   // goi lai ham kt de kiem tra ma nv có xuat hien ko
	{
		cout<<"ko co nhan vien can tim:"<<endl;
		f<<"ko co nhan vien can tim:"<<endl;
	}else x=kt(ds,manv);
	cout<<"=====thong tin nhap vien can tim==== "<<endl;
	xuat(ds[x]);
	//ghi vao file
		f<<endl<<"ma nhan vien: "<<ds[x].ma<<endl;
		f<<endl<<"ten nhan vien: "<<ds[x].ten<<endl;
		f<<endl<<"tuoi nhan vien: "<<ds[x].tuoi<<endl;
		f<<endl<<"luong co ban: "<<ds[x].luongcb<<endl;
	f.close();
}


void menu()
{
	cout<<"1.them 1 nhan vien"<<endl;
	cout<<"2.xoa nhan vien theo ma"<<endl;
	cout<<"3.sua nhan vien theo ma"<<endl;
	cout<<"4.tim kiem thong tin nhan vien theo ma"<<endl;
	cout<<"5.in danh sach nhan vien"<<endl;
}
void chon(vector <nv> ds)
{
	cout<<"================*******==================="<<endl;
	menu();
	int b ;
	cout<<"==========="<<"chon cac muc trong menu phia tren"<<"==========="<<endl;
	cout<<"lua chon so:";
	cin>>b;
	switch(b)
	{					
		case 1: 
				 cout<<"nhan vien can them: "<<endl;
				 cin.ignore();
				 themnv(ds);
				 xuatDS(ds);
				 chon(ds);
			break;
		case 2 :
				xoa(ds);
				cout<<"thong tin sau khi xoa"<<endl;
				xuatDS(ds);
				chon(ds);
			break;
		case 3:	
				sua(ds);
				cout<<"thong sau khi sua";
				xuatDS(ds);
				chon(ds);	
			break;
		case 4:
				tim(ds);
				chon(ds);	
			break;
		case 5:
				
			break;	
		default:
					cout<<"ban nhap ko hop le"<<endl<<"--------"<<"moi ban nhap lai"<<"--------"<<endl;	
						
					
	}	
}
int main()
{	
	vector <nv> ds_l;
	nhapDS(ds_l);
//	ghifile(ds_l);
	chon(ds_l);

}
