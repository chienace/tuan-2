#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
using namespace std;
struct bien{
	string ch,a,b,c,d,da; 
};
int n;
// doc du lieu tu file
void doc(ifstream &f,vector <bien> &ds)
{

	f>>n;
	string temp;
	getline(f,temp);
	ds.resize(n);
	for(int i=0;i<n;i++)
	{
		getline(f,ds[i].ch);
		getline(f,ds[i].a);
		getline(f,ds[i].b);
		getline(f,ds[i].c); 
		getline(f,ds[i].d);
		getline(f,ds[i].da);
	}	
}
bool ktra(bien q)
{
	string k;
	cout<<"nhap dan an: ";
		fflush(stdin);
		getline(cin,k);
		if(q.da.compare(k)==0)
		{
			cout <<"Ban da tra loi dung!"<<endl;
			return true;
		}	
		else  
		{
			cout <<"Ban da tra loi sai dap an la: "<<q.da<<endl;
			return false;
		}
}
void xuat1(bien q)
{
	cout<<q.ch<<endl;
	cout<<q.a<<endl;
	cout<<q.b<<endl;
	cout<<q.c<<endl;
	cout<<q.d<<endl;
}
// xuat cau hoi va chon cau tra loi
void xuat(vector<bien> &ds,int dem)
{		
	for(int i=0;i<n;i++)
	{
		xuat1(ds[i]);
		if(ktra(ds[i]))
			dem++;
	}
	cout <<"ban da tra loi dung: "<<dem<<" cau hoi!"<<endl;
}
void menu()
{
	 cout<<"chon bo de so 1:"<<endl;
	 cout<<"chon bo de so 2"<<endl;
}
void chon(vector<bien> &ds,ifstream &f)
{	
int dem =0;
	menu();
	int b ;
	cout<<"----------------"<<"chon cac muc trong menu phia tren"<<"-----------"<<endl;
	cout<<"lua chon so:";
	cin>>b;
	switch(b)
	{			
		case 1: 
				system("cls");
				f.open("cauhoi1.txt");
				doc(f,ds);
				xuat(ds,dem);
				break;
		case 2:system("cls");
				f.open("cauhoi2.txt");
				doc(f,ds);
				xuat(ds,dem);
			break;
		
		case 3:
					cout<<"ban nhap ko hop le"<<endl<<"--------"<<"moi ban nhap lai"<<"--------"<<endl;	
					break;
						
					
	}
	f.close();	
}
int main()
{

	vector <bien> ds;
	ifstream f;
	chon(ds,f);
}
