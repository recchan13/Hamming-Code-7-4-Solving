/* Reza Octaviany
14117062*/

#include <iostream>
#include <sstream>
using namespace std;

bool cekInput (string input);
bool cekPanjang (string input);
string hapusSpasi (string input);
bool koreksi(int p, int q, int r, string input, int perulangan);
bool bandingkan(int index, string input, int perulangan, bool hasil);
int kebenaran(bool x,bool y,bool z, string input, int perulangan);

int main(){
	string input;
		cout<<"Masukkan kode : ";
		getline(cin,input);
	
	if (!cekInput(input)){
		cout<<"Anda tidak menginputkan Binary code dengan benar\nMohon inputkan kode biner saja";
	}else{
		input = hapusSpasi(input);
		if(!cekPanjang(input)){
			cout<<"Anda tidak menginputkan Binary code dengan benar\nMohon inputkan kode biner dengan panjang kelipatan 7";
		}else{
			int perulangan=(input.length()/7)-1;
			
			for(int i=0;i<=perulangan;i++){
				cout<<"\nKoreksi blok kode ke-"<<i+1;
				
				bool x = koreksi(0,1,3,input,i);
				bool y = koreksi(0,2,3,input,i);
				bool z = koreksi(1,2,3,input,i);
				
				x=bandingkan(4, input, i, x);
				y=bandingkan(5, input, i, y);
				z=bandingkan(6, input, i, z);
				
				int salah=kebenaran(x,y,z,input,i);
				
				if (salah>=0){
					if (input[salah] == '1'){
						input[salah]='0';
					}else{
						input[salah]='1';	
					}
				}
				
				cout<<"Kode yang benar : ";
				for(int j=(i*7);j<((i*7)+7);j++){
					cout<<input[j];
				}cout<<"\n";
			}
			
			cout<<"\nKeseluruhan kode yang benar : ";
			for(int i=0;i<input.length();i++){
				if ((i+1)%7==0){
					cout<<input[i]<<" ";
				}else{
					cout<<input[i];
				}
			}
		}
	}
}

bool cekInput(string input){
	for (int i=0; i<input.length();i++){
		if (input[i]!='0' && input[i]!='1' && input[i]!=' '){
			cout<<i;
			return false;
		}
	}return true;
}

bool cekPanjang(string input){
	if(input.length()%7==0 && input.length()!=0){
		return true;
	}else{
		return false;
	}
}

string hapusSpasi (string input){
	string baru="";
	for (int i=0; i<input.length();i++){
		if (input[i]!=' '){
			baru=baru+input[i];
		}
	}
	return baru;
}

bool koreksi(int p, int q, int r, string input, int perulangan){
	bool hasil;
	
	if ((input[(perulangan*7)+p]) != (input[(perulangan*7)+q])){
		if ((input[(perulangan*7)+r]) != '1'){
			return true;
		}else{
			return false;
		}
	}else{
		if ((input[(perulangan*7)+r]) != '0'){
			return true;
		}else{
			return false;
		}
	}
}

bool bandingkan(int index, string input, int perulangan, bool hasil){
	int hasil2=(int)input[(perulangan*7)+index]-48;
	
	if (hasil == hasil2){
		return true;
	}else{
		return false;
	}
}

int kebenaran(bool x,bool y,bool z, string input, int perulangan){
	int index=-999;
	
	cout<<"\nError: ";
	if (x == 1){
		if(y == 1){
			if (z == 1){
				//no error
				cout<<"Tidak ada kode yang salah";
			}else{
				cout<<"Z error";
				index=6;
			}
		}else{
			if (z == 1){
				cout<<"Y error";
				index=5;
			}else{
				cout<<"C error";
				index=2;
			}
		}
	}else{
		if(y == 1){
			if (z == 1){
				cout<<"X error";
				index=4;
			}else{
				cout<<"B error";
				index=1;
			}
		}else{
			if (z == 1){
				cout<<"A error";
				index=0;
			}else{
				cout<<"D error";
				index=3;
			}
		}
	}
	cout<<"\n";
	return ((perulangan*7)+index);
}
