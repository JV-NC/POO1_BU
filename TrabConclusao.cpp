#include "TrabConclusao.h"

TrabConclusao::TrabConclusao(){
}

TrabConclusao::TrabConclusao(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,int paginas,int edicao,string editora,string isbn,string instituicao,TipoTrabalho tipo) : Livro(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho,paginas,edicao,editora,isbn){
	set_instituicao(instituicao);
	set_tipo(tipo);
}

TrabConclusao::~TrabConclusao(){
}

TipoTrabalho TrabConclusao::get_tipo(){
	return tipo;
}
string TrabConclusao::get_instituicao(){
	return instituicao;
}

void TrabConclusao::set_tipo(TipoTrabalho tipo){
	this->tipo=tipo;
}
void TrabConclusao::set_instituicao(string instituicao){
	this->instituicao=instituicao;
}

int TrabConclusao::maior_tamanho(){
	int a=10,max=0,t,p;
	a+=autor.size()*2;
	for(int i=0;i<autor.size();i++){
		a+=autor[i].size();
	}
	//qtd de caracteres da linha de autor
	
	t=8+11+2+11+12+16+7+4; //t+e+e+c+e+i+a+a
	t+=titulo.size()+cidade.size()+editora.size()+instituicao.size();
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

void TrabConclusao::ficha_catalografica(){
	int i,max;
	max=maior_tamanho();
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<endl;
	switch(tipo){
		case 1:
			cout<<"Monografia\n\n";
		break;
		
		case 2:
			cout<<"Dissertação\n\n";
		break;
		
		case 3:
			cout<<"Tese\n\n";
		break;
		
		case 4:
			cout<<"Relatório\n\n";
		break;
		
		case 5:
			cout<<"Cartaz\n\n";
		break;
	}
	cout<<"Autor/es: ";
	for(i=0;i<autor.size();i++){
		cout<<autor[i]<<". ";
	}
	cout<<"\n\nTítulo: "<<titulo<<" - Edição: "<<edicao<<" - Cidade: "<<cidade<<" : Editora: "<<editora<<" : Instituição: "<<instituicao<<", Ano: "<<ano<<endl<<paginas<<" pág :"<<tamanho[0]<<"x"<<tamanho[1]<<"x"<<tamanho[2]<<" cm\n\n"<<"ISBN: "<<isbn<<"\n\nAssunto: "<<assunto<<". Palavras chave: ";
	for(i=0;i<pchave.size();i++){
		cout<<i+1<<". "<<pchave[i]<<". ";
	}
	cout<<"\n\n"<<"CDU: "<<cdu<<"\nQtd: "<<quantidade<<endl;
	for(i=0;i<max;i++){ //bordas
		cout<<"-";
	}
	cout<<endl;
}
