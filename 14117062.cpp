/* Reza Octaviany
14117062*/

#include <iostream>
using namespace std;

bool cekInput (string input);
bool cekPanjang (string input);
string hapusSpasi (string input);

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
			//mulai 
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


