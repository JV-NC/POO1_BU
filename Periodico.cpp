#include "Periodico.h"

Periodico::Periodico(){
}

Periodico::Periodico(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,int paginas,int edicao,string editora,string isbn,string data,TipoPeriodico tipo) : Livro(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho,paginas,edicao,editora,isbn){
	set_data(data);
	set_tipo(tipo);
}

Periodico::~Periodico(){
}

string Periodico::get_data(){
	return data;
}
TipoPeriodico Periodico::get_tipo(){
	return tipo;
}

bool Periodico::set_data(string data){
	string sub;
	bool trigger=true;
	int i;
	if(data.size()==10 && data[2]=='/' && data[5]=='/'){
		for(i=0;i<data.size();i++){
			if(i!=2 && i!=5){
				if(!isdigit(data[i])){
					trigger=false;
				}
			}
		}
		sub=data.substr(0,2);
		if(stoi(sub)<1 || stoi(sub)>31){
			trigger=false;
		}
		sub=data.substr(3,2);
		if(stoi(sub)<1 || stoi(sub)>12){
			trigger=false;
		}
		sub=data.substr(6,4);
		if(stoi(sub)<1 || stoi(sub)>2023){
			trigger=false;
		}
		if(trigger){
			this->data=data;
		return 1;
		}
	}
	return 0;
}
void Periodico::set_tipo(TipoPeriodico tipo){
	this->tipo=tipo;
}

int Periodico::maior_tamanho(){
	int a=10,max=0,t,p;
	a+=autor.size()*2;
	for(int i=0;i<autor.size();i++){
		a+=autor[i].size();
	}
	//qtd de caracteres da linha de autor
	
	t=8+11+2+11+12+8+10; //t+e+e+c+e+d+d
	t+=titulo.size()+cidade.size()+editora.size();
	//qtd de caracteres da linha de titulo
	
	max= (a>t) ? a : t;
	
	p=9+18; //a+pc
	p+=assunto.size();
	p+=pchave.size()*5;
	for(int i=0;i<pchave.size();i++){
		p+=pchave[i].size();
	}
	//qtd de caracteres da linha de palavras chave
	
	max= (max>p) ? max : p;
	
	return max;
}

void Periodico::ficha_catalografica(){
	int i,max;
	max=maior_tamanho();
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<endl;
	if(tipo==Jornal){
		cout<<"Jornal\n\n";
	}
	else{
		cout<<"Revista\n\n";
	}
	cout<<"Autor/es: ";
	for(i=0;i<autor.size();i++){
		cout<<autor[i]<<". ";
	}
	cout<<"\n\nTítulo: "<<titulo<<" - Edição: "<<edicao<<" - Cidade: "<<cidade<<" : Editora: "<<editora<<", Data: "<<data<<endl<<paginas<<" pág :"<<tamanho[0]<<"x"<<tamanho[1]<<"x"<<tamanho[2]<<" cm\n\n"<<"ISBN: "<<isbn<<"\n\nAssunto: "<<assunto<<". Palavras chave: ";
	for(i=0;i<pchave.size();i++){
		cout<<i+1<<". "<<pchave[i]<<". ";
	}
	cout<<"\n\n"<<"CDU: "<<cdu<<"\nQtd: "<<quantidade<<endl;
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<endl;
}
