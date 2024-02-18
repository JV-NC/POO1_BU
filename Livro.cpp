#include "Livro.h"

Livro::Livro(){
}

Livro::Livro(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,int paginas,int edicao,string editora,string isbn) : Item(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho){
	set_paginas(paginas);
	set_edicao(edicao);
	set_editora(editora);
	set_isbn(isbn);
}

Livro::~Livro(){
}

int Livro::get_paginas(){
	return paginas;
}
int Livro::get_edicao(){
	return edicao;
}
string Livro::get_editora(){
	return editora;
}
string Livro::get_isbn(){
	return isbn;
}

void Livro::set_paginas(int paginas){
	if(paginas>0){
		this->paginas=paginas;
	}
	else{
		this->paginas=0;
	}
}
void Livro::set_edicao(int edicao){
	if(edicao>0){
		this->edicao=edicao;
	}
	else{
		this->edicao=1;
	}
}
void Livro::set_editora(string editora){
	this->editora=editora;
}
bool Livro::set_isbn(string isbn){
	if(isbn.size()==13 && isbn[2]=='-' && isbn[7]=='-' && isbn[11]=='-'){
		this->isbn=isbn;
		return 1;
	}
	else{
		this->isbn="00-0000-000-0";
		return 0;
	}
}

int Livro::maior_tamanho(){
	int a=10,max=0,t,p;
	a+=autor.size()*2;
	for(int i=0;i<autor.size();i++){
		a+=autor[i].size();
	}
	//qtd de caracteres da linha de autor
	
	t=8+11+2+11+12+7+4; //t+e+e+c+e+a+a
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

void Livro::ficha_catalografica(){
	int i,max;
	max=maior_tamanho();
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<"\nLivro\n\nAutor/es: ";
	for(i=0;i<autor.size();i++){
		cout<<autor[i]<<". ";
	}
	cout<<"\n\nTítulo: "<<titulo<<" - Edição: "<<edicao<<" - Cidade: "<<cidade<<" : Editora: "<<editora<<", Ano: "<<ano<<endl<<paginas<<" pág :"<<tamanho[0]<<"x"<<tamanho[1]<<"x"<<tamanho[2]<<" cm\n\n"<<"ISBN: "<<isbn<<"\n\nAssunto: "<<assunto<<". Palavras chave: ";
	for(i=0;i<pchave.size();i++){
		cout<<i+1<<". "<<pchave[i]<<". ";
	}
	cout<<"\n\nCDU: "<<cdu<<"\nQtd: "<<quantidade<<endl;
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<endl;
}
