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
void kebenaran(bool x,bool y,bool z);

int main(){
	string input;
		getline(cin,input);
	
	if (!cekInput(input)){
		cout<<"Anda tidak menginputkan Binary code dengan benar\nMohon inputkan kode biner saja";
	}else{
		input = hapusSpasi(input);
		if(!cekPanjang(input)){
			cout<<"Anda tidak menginputkan Binary code dengan benar\nMohon inputkan kode biner dengan panjang kelipatan 7";
		}else{
			int ulang=input.length()/7;
			int perulangan=ulang-1;
			
			for(int i=0;i<=perulangan;i++){
				bool x = koreksi(0,1,3,input,perulangan);
				bool y = koreksi(0,2,3,input,perulangan);
				bool z = koreksi(1,2,3,input,perulangan);
				
				x=bandingkan(4, input, perulangan, x);
				y=bandingkan(5, input, perulangan, y);
				z=bandingkan(6, input, perulangan, z);
				
				kebenaran(x,y,z);
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
	bool hasil2=(input[(perulangan*7)+index]);
	
	if (hasil2 == hasil){
		return true;
	}else{
		return false;
	}
}

void kebenaran(bool x,bool y,bool z){
	if (x == 1){
		if(y == 1){
			if (z == 1){
				//no error
				cout<<"Tidak ada kode yang salah";
			}else{
				cout<<"Z error";
			}
		}else{
			if (z == 1){
				cout<<"Y error";
			}else{
				cout<<"C error";
			}
		}
	}else{
		if(y == 1){
			if (z == 1){
				cout<<"X error";
			}else{
				cout<<"B error";
			}
		}else{
			if (z == 1){
				cout<<"A error";
			}else{
				cout<<"D error";
			}
		}
	}
}
