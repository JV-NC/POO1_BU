#include "Midia.h"

Midia::Midia(){
}

Midia::Midia(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,float duracao,TipoMidia tipo) : Item(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho){
	set_duracao(duracao);
	set_tipo(tipo);
}

Midia::~Midia(){
}

float Midia::get_duracao(){
	return duracao;
}
TipoMidia Midia::get_tipo(){
	return tipo;
}

bool Midia::set_duracao(float duracao){
	if(duracao>0.0){
		this->duracao=duracao;
		return 1;
	}
	return 0;
}
void Midia::set_tipo(TipoMidia tipo){
	this->tipo=tipo;
}

void Midia::ficha_catalografica(){
	int i,max;
	max=maior_tamanho();
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<endl;
	switch(tipo){
		case 1:
			cout<<"VHS\n\n";
		break;
		
		case 2:
			cout<<"CD\n\n";
		break;
		
		case 3:
			cout<<"DVD\n\n";
		break;
		
		case 4:
			cout<<"SDCard\n\n";
		break;
	}
	cout<<"Autor/es: ";
	for(i=0;i<autor.size();i++){
		cout<<autor[i]<<". ";
	}
	cout<<"\n\nTítulo: "<<titulo<<" - Cidade: "<<cidade<<", Ano: "<<ano<<endl<<tamanho[0]<<"x"<<tamanho[1]<<"x"<<tamanho[2]<<" cm\n\n";
	cout<<"Duração: "<<duracao<<" min\n\nAssunto: ";
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
