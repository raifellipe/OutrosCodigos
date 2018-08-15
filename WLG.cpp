#include <iostream>
#include <string>
#include <vector>
#include <locale>
using namespace std;

vector <string> wlist;

void recebe (void){
	string aux, aux2;
	getline(cin,aux);
	for (int i=0; i<aux.size(); i++){
		if(aux[i]!=' ')
			aux2.push_back(aux[i]);
		else{
			wlist.push_back(aux2);
			aux2.clear();
		}
	}
	wlist.push_back(aux2);
	aux.clear();
}

void imprime (void){
	for(int i=0; i<wlist.size(); i++)
		cout<<wlist[i]<<endl;
}

void matrix_gen (string a){
	string num, numa, numi, nume, numo, mai;
	num=numa=numi=numo=nume=mai=a;
	for(int i=0; i<a.size(); i++){
		if(a[i]=='a')
			numa[i]=num[i]='4';
		else if (a[i]=='e')
			nume[i]=num[i]='3';
		else if (a[i]=='o')
			numo[i]=num[i]='0';
		else if (a[i]=='i')
			numi[i]=num[i]='1';
		mai[i]=toupper(a[i]);
	}
	wlist.push_back(num);
	wlist.push_back(numa);
	wlist.push_back(nume);
	wlist.push_back(numi);
	wlist.push_back(numo);
	wlist.push_back(mai);
}
void wlistgen(bool flag0, bool flag, bool flag2){
	int holder;
	holder=wlist.size();
	if(flag0){
		for(int i=0; i<holder; i++){
			for(int j=0; j<holder; j++){
				if(wlist[i].size()+wlist[j].size()<13&&i!=j){
					string aux;
					aux=wlist[i]+wlist[j];
					wlist.push_back(aux);
					aux.clear();
				}
			}
		}
	}
	if (flag){
	int hdr=wlist.size();
	for(int i=holder; i<hdr;i++){
		for (int j=0; j<hdr; j++){
			if(wlist[i].size()+wlist[i].size()>5 && wlist[i].size()+wlist[i].size()<16&&i!=j){
				string aux;
				aux=wlist[i]+wlist[j];
				wlist.push_back(aux);
				aux.clear();
			}
		}
	}
	if(flag2){
	holder=wlist.size();
	for(int i=0; i<holder; i++)
		matrix_gen(wlist[i]);
	}
}
}
int main(){
	int a;
	/*cout<<"\n\nWord List Gen ---> R. A. Mithriell\n
	       Escolha o estagio de combinação ou a força e entre com a lista\n
		Estagios:
		1--> Arranjo simples;\n
		2--> Arranjo simples seguido por mais um arranjo;\n
		3--> Mudança de letras.\n
		Força:\n
		1--> Fraca\n 2--> Forte\n 3-->Complexa"<<endl
	cin>>a;
	recebe();
	if(a==1)
		wlistgen(true,false,false);
	else if(a==2)
		wlistgen(true, true, false);
	else if(a==3)
		wlistgen(false, false, true);*/
	recebe();
	wlistgen(true, true, true);
	imprime();
	return 0;
}

