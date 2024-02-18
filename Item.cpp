#include "Item.h"

Item::Item(){
}

Item::Item(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho){
	int i;
	set_qtd(qtd,qtdcontrol);
	set_titulo(titulo);
	for(i=0;i<autor.size();i++){
		set_autor(autor[i]);
	}
	set_cidade(cidade);
	set_ano(ano);
	set_cdu(cdu);
	set_assunto(assunto);
	for(i=0;i<pchave.size();i++){
		set_pchave(pchave[i]);
	}
	set_tamanho(tamanho[0],tamanho[1],tamanho[2]);
}

Item::~Item(){
}

int Item::get_qtd(){
	return quantidade;
}
int Item::get_qtdcontrol(){
	return qtdcontrol;
}
string Item::get_titulo(){
	return titulo;
}
void Item::get_autores(vector<string> *autores){
	*autores=autor;
}
string Item::get_cidade(){
	return cidade;
}
int Item::get_ano(){
	return ano;
}
void Item::get_tamanho(float *x,float *y,float *z){
	*x=tamanho[0];
	*y=tamanho[1];
	*z=tamanho[2];
}
string Item::get_cdu(){
	return cdu;
}
string Item::get_assunto(){
	return assunto;
}
void Item::get_pchaves(vector<string> *pchaves){
	*pchaves=pchave;
}

void Item::set_qtd(int qtd){
	if(qtd>0){
		this->quantidade=qtd;
		this->qtdcontrol=qtd;
	}
	else{
		this->quantidade=1;
		this->qtdcontrol=1;
	}
}
void Item::set_qtd(int qtd,int qtdcontrol){
	if(qtd<=qtdcontrol && qtd>=0 && qtdcontrol>0){
		this->quantidade=qtd;
		this->qtdcontrol=qtdcontrol;
	}
	else{
		this->quantidade=1;
		this->qtdcontrol=1;
	}
	
}
void Item::set_titulo(string titulo){
	this->titulo=titulo;
}
void Item::set_autor(string nome){
	autor.push_back(nome);
}
void Item::set_cidade(string cidade){
	this->cidade=cidade;
}
void Item::set_ano(int ano){
	this->ano=ano;
}
void Item::set_tamanho(float x,float y,float z){
	tamanho[0]= (x>0) ? x : 1;
	tamanho[1]= (y>0) ? y : 1;
	tamanho[2]= (z>0) ? z : 1;
}
bool Item::set_cdu(string cdu){
	if(cdu.length()==13){
		this->cdu=cdu;
		return 1;
	}
	return 0;
}
void Item::set_assunto(string assunto){
	this->assunto=assunto;
}
void Item::set_pchave(string palavra){
	pchave.push_back(palavra);
}

bool Item::emprestar(){
	if(quantidade>0){
		quantidade--;
		return 1;
	}
	return 0;
}
bool Item::devolver(){
	if(quantidade<qtdcontrol){
		quantidade++;
		return 1;
	}
	return 0;
}

int Item::maior_tamanho(){
	int a=10,max=0,t,p;
	a+=autor.size()*2;
	for(int i=0;i<autor.size();i++){
		a+=autor[i].size();
	}
	//qtd de caracteres da linha de autor
	
	t=8+11+7+4; //t+c+a+a
	t+=titulo.size()+cidade.size();
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

void Item::ficha_catalografica(){
	int i,max;
	max=maior_tamanho();
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<"\nAutor/es: ";
	for(i=0;i<autor.size();i++){
		cout<<autor[i]<<". ";
	}
	cout<<"\n\nTítulo: "<<titulo<<" - Cidade: "<<cidade<<", Ano: "<<ano<<endl<<tamanho[0]<<"x"<<tamanho[1]<<"x"<<tamanho[2]<<" cm\n\nAssunto: "<<assunto<<". Palavras chave: ";
	for(i=0;i<pchave.size();i++){
		cout<<i+1<<". "<<pchave[i]<<". ";
	}
	cout<<"\n\nCDU: "<<cdu<<"\nQtd: "<<quantidade<<endl;
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<endl;
}

void Item::limpar_autor(){
	autor.clear();
}
void Item::limpar_pchave(){
	pchave.clear();
}
