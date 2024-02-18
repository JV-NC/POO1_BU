#include "ManterDados.h"

ManterDados::ManterDados(){
}

ManterDados::~ManterDados(){
}

bool ManterDados::carregar(Acervo *a){
	Item *aux;
	fstream arq;
	
	int i,tipo_item,qtd,qtdcontrol,ano,paginas,edicao,nautor,npchave;
	float duracao,ratio;
	string titulo,cdu,cidade,assunto,editora,isbn,data,instituicao,local;
	vector<float> tamanho;
	vector<string> autor;
	vector<string> pchave;
	string linha;
	TipoPeriodico tp;
	TipoTrabalho tt;
	TipoMidia tm;
	
	arq.open(ARQUIVO,ios::in);
	
	if(arq.is_open()){
		while(!arq.eof()){
			getline(arq,linha);
			
			if(!linha.empty()){
				//informações gerais
				tipo_item=stoi(linha);
				
				getline(arq,linha);
				qtd=stoi(linha);
				
				getline(arq,linha);
				qtdcontrol=stoi(linha);
				
				getline(arq,titulo);
				
				getline(arq,linha);
				nautor=stoi(linha);
				for(i=0;i<nautor;i++){ //autores
					getline(arq,linha);
					autor.push_back(linha);
				}
				
				getline(arq,cidade);
				
				getline(arq,linha);
				ano=stoi(linha);
				
				getline(arq,cdu);
				
				getline(arq,assunto);
				
				getline(arq,linha);
				npchave=stoi(linha);
				for(i=0;i<npchave;i++){ //pchaves
					getline(arq,linha);
					pchave.push_back(linha);
				}
				for(i=0;i<3;i++){ //tamanho
					getline(arq,linha);
					tamanho.push_back(stof(linha));
				}
				//livro
				if(tipo_item>=1 && tipo_item<=3){
					getline(arq,linha);
					paginas=stoi(linha);
					
					getline(arq,linha);
					edicao=stoi(linha);
					
					getline(arq,editora);
					getline(arq,isbn);
					
					if(tipo_item==1){ //livro
						aux= new Livro(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho,paginas,edicao,editora,isbn);
						a->add_item(aux);
					}
					else if(tipo_item==2){ //periodico
						getline(arq,data);
						getline(arq,linha); //tipo
						i=stoi(linha);
						switch(i){
							case 1:
								tp=Jornal;
							break;
							case 2:
								tp=Revista;
							break;
						}
						aux= new Periodico(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho,paginas,edicao,editora,isbn,data,tp);
						a->add_item(aux);
					}
					else if(tipo_item==3){ //Trabalho Cientifico
						getline(arq,instituicao);
						
						getline(arq,linha);
						i=stoi(linha);
						switch(i){
							case 1:
								tt=Monografia;
							break;
							case 2:
								tt=Dissertacao;
							break;
							case 3:
								tt=Tese;
							break;
							case 4:
								tt=Relatorio;
							break;
							case 5:
								tt=Cartaz;
							break;
						}
						aux=new TrabConclusao(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho,paginas,edicao,editora,isbn,instituicao,tt);
						a->add_item(aux);
					}
				}
				else if(tipo_item==4){ //midia
					getline(arq,linha);
					duracao=stof(linha);
					
					getline(arq,linha);
					i=stoi(linha);
					switch(i){
						case 1:
							tm=VHS;
						break;
						case 2:
							tm=CD;
						break;
						case 3:
							tm=DVD;
						break;
						case 4:
							tm=SDCard;
						break;
					}
					aux=new Midia(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho,duracao,tm);
					a->add_item(aux);
				}
				else if(tipo_item==5){ //mapa
					getline(arq,local);
					
					getline(arq,linha);
					ratio=stof(linha);
					
					aux=new Mapa(qtd,qtdcontrol,titulo,autor,cidade,ano,cdu,assunto,pchave,tamanho,local,ratio);
					a->add_item(aux);
				}
			}
			autor.clear();
			pchave.clear();
			tamanho.clear();
			//limpar vectors
		}
		arq.close();
		//fechar arq
		return true;
	}
	return false;
}

int ManterDados::get_tipo_item(Item *item){
	if((dynamic_cast<Periodico*>(item))){
		return 2;
	}
	else if((dynamic_cast<TrabConclusao*>(item))){
		return 3;
	}
	else if((dynamic_cast<Livro*>(item))){
		return 1;
	}
	else if((dynamic_cast<Midia*>(item))){
		return 4;
	}
	else if((dynamic_cast<Mapa*>(item))){
		return 5;
	}
}

string ManterDados::trocar_ponto(string s){
	int i;
	for(i=0;i<s.size();i++){
		if(s[i]=='.'){
			s[i]=',';
		}
	}
	return s;
}

bool ManterDados::salvar(Acervo *a){
	fstream arq;
	int i,j,tipo_item;
	vector<string> vsaux;
	float tamanho[3];
	string saux;
	Item *aux;
	arq.open(ARQUIVO,ios::out | ios::trunc);
	int max=a->get_tamanho();
	if(arq.is_open()){
		for(i=0;i<max;i++){
			//informações gerais
			aux=a->get_item(i);
			tipo_item=ManterDados::get_tipo_item(aux); //define tipo de classe
			arq<<tipo_item<<endl;
			arq<<aux->get_qtd()<<endl;
			arq<<aux->get_qtdcontrol()<<endl;
			arq<<aux->get_titulo()<<endl;
			
			aux->get_autores(&vsaux);
			arq<<vsaux.size()<<endl;
			for(int j=0;j<vsaux.size();j++){ //autores
				arq<<vsaux[j]<<endl;
			}
			
			arq<<aux->get_cidade()<<endl;
			arq<<aux->get_ano()<<endl;
			arq<<aux->get_cdu()<<endl;
			arq<<aux->get_assunto()<<endl;
			
			aux->get_pchaves(&vsaux);
			arq<<vsaux.size()<<endl;
			for(j=0;j<vsaux.size();j++){ //pchaves
				arq<<vsaux[j]<<endl;
			}
			
			aux->get_tamanho(&tamanho[0],&tamanho[1],&tamanho[2]);
			for(j=0;j<3;j++){ //tamanho
				saux=to_string(tamanho[j]);
				saux=ManterDados::trocar_ponto(saux); //trocar ponto por virgula para evitar inconpatibilidade do arquivo
				arq<<saux<<endl; //trocar no mapa e duracao
			}
			
			if((dynamic_cast<Livro*>(aux))){ //livro / periodico / trab
				arq<<(dynamic_cast<Livro*>(aux))->get_paginas()<<endl;
				arq<<(dynamic_cast<Livro*>(aux))->get_edicao()<<endl;
				arq<<(dynamic_cast<Livro*>(aux))->get_editora()<<endl;
				arq<<(dynamic_cast<Livro*>(aux))->get_isbn()<<endl;
				
				if((dynamic_cast<Periodico*>(aux))){ //periodico
					arq<<(dynamic_cast<Periodico*>(aux))->get_data()<<endl;
					arq<<(dynamic_cast<Periodico*>(aux))->get_tipo()<<endl;
				}
				else if((dynamic_cast<TrabConclusao*>(aux))){ //trab
					arq<<(dynamic_cast<TrabConclusao*>(aux))->get_instituicao()<<endl;
					arq<<(dynamic_cast<TrabConclusao*>(aux))->get_tipo()<<endl;
				}
			}
			else if((dynamic_cast<Midia*>(aux))){ //midia
				saux=to_string((dynamic_cast<Midia*>(aux))->get_duracao());
				saux=ManterDados::trocar_ponto(saux);
				arq<<saux<<endl;
				
				arq<<(dynamic_cast<Midia*>(aux))->get_tipo()<<endl;
			}
			else if((dynamic_cast<Mapa*>(aux))){ //mapa
				arq<<(dynamic_cast<Mapa*>(aux))->get_local()<<endl;
				
				saux=to_string((dynamic_cast<Mapa*>(aux))->get_ratio()); //trocar ponto por virgula
				saux=ManterDados::trocar_ponto(saux);
				arq<<saux<<endl;
			}
			//limpar;
			arq<<endl;
		}
		arq.close();
		return true;
	}
	return false;
}
