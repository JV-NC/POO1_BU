#include "Mapa.h"

Mapa::Mapa(){
}

Mapa::Mapa(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,string local,float ratio) : Item(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho){
	set_local(local);
	set_ratio(ratio);
}

Mapa::~Mapa(){
}

string Mapa::get_local(){
	return local;
}
float Mapa::get_ratio(){
	return ratio;
}

void Mapa::set_local(string local){
	this->local=local;
}
bool Mapa::set_ratio(float ratio){
	if(ratio>=0){
		this->ratio=ratio;
		return 1;
	}
	return 0;
}

void Mapa::ficha_catalografica(){
	int i,max;
	max=maior_tamanho();
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<"\nMapa\n\nAutor/es: ";
	for(i=0;i<autor.size();i++){
		cout<<autor[i]<<". ";
	}
	cout<<"\n\nTítulo: "<<titulo<<" - Cidade: "<<cidade<<", Ano: "<<ano<<endl<<tamanho[0]<<"x"<<tamanho[1]<<"x"<<tamanho[2]<<" cm\n\n";
	cout<<"Local: "<<local<<"\nEscala - 1:"<<1.0/ratio<<"\n\nAssunto: ";
	cout<<assunto<<". Palavras chave: ";
	for(i=0;i<pchave.size();i++){
		cout<<i+1<<". "<<pchave[i]<<". ";
	}
	cout<<"\n\n"<<"CDU: "<<cdu<<"\nQtd: "<<quantidade<<endl;
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<endl;
}
