#include "Acervo.h"

Acervo::Acervo(){
	chave_cdu=0;
}

Acervo::~Acervo(){
}

Item* Acervo::get_item(int pos){
	return inventario[pos];
}
void Acervo::add_item(Item* item){
	inventario.push_back(item);
	Acervo::get_maior_cdu();
}
Item* Acervo::remover_item(int pos){
	Item *save=inventario[pos];
	inventario.erase(inventario.begin()+pos);
	Acervo::get_maior_cdu();
	return save;
}

int Acervo::get_tamanho(){
	return inventario.size();
}

string Acervo::construir_cdu(int tipo){
	int tam=chave_cdu;
	string cdu;
	cdu="00";
	cdu+=to_string(tipo)+".";
	
	int aux,ant=0,dif,p=1000000;
	
	while(p>=1){ //enquanto houver valores de tam
		dif=tam/p; //pega casa atual
		aux=dif-(ant*10); //limpa casas indesejadas
		if(p==10000){
			cdu+=":";
		}
		if(p==10){
			cdu+=".";
		}
		
		cdu+=to_string(aux);
		ant=dif;
		p/=10;
	}
	return cdu;
}

int Acervo::stoi_cdu(Item *item){
	//0123456789abc
	//000.00:000.00
	string s=item->get_cdu();
	string aux;
	int cdui;
	/*aux=s.substr(0,3);
	cdui=stoi(aux)*10000000; //012.*/
	
	aux=s.substr(4,2);
	cdui=stoi(aux)*100000; //34:
	
	aux=s.substr(7,3);
	cdui+=stoi(aux)*100; //567.
	
	aux=s.substr(11,2);
	cdui+=stoi(aux); //89
	
	return cdui;
}

void Acervo::criar_item(Item *novo){
	int i=0;
	string aux;
	
	int qtd;
	string titulo;
	string cidade;
	int ano;
	float tamanho[3];
	string assunto;
	
	cout<<"Título da obra: ";
	getline(cin,titulo);
	novo->set_titulo(titulo);
	cin.clear();
	fflush(stdin);
	
	cout<<"Quantidade: ";
	cin>>qtd;
	novo->set_qtd(qtd);
	cin.clear();
	fflush(stdin);
	
	cout<<"Digite '0' para finalizar:\n";
	do{
		cout<<"Autor "<<i+1<<": ";
		getline(cin,aux);
		if(aux.compare("0")!=0){
			novo->set_autor(aux);
		}
		cin.clear();
		fflush(stdin);
		i++;
	}while(aux.compare("0")!=0);
	
	cout<<"Cidade da obra: ";
	getline(cin,cidade);
	novo->set_cidade(cidade);
	cin.clear();
	fflush(stdin);
	
	if((dynamic_cast<Periodico*>(novo))==false){
		do{
			cout<<"Ano: ";
			cin>>ano;
			if(ano>2023 || ano<0){
				cout<<"Ano inválido!\n";
			}
			cin.clear();
			fflush(stdin);
		}while(ano>2023 || ano<0);
		novo->set_ano(ano);
	}
	
	cout<<"Tamanho do item (cm):\nComprimento: ";
	cin>>tamanho[0];
	cin.clear();
	fflush(stdin);
	
	cout<<"Altura: ";
	cin>>tamanho[1];
	cin.clear();
	fflush(stdin);
	
	cout<<"Largura: ";
	cin>>tamanho[2];
	cin.clear();
	fflush(stdin);
	
	novo->set_tamanho(tamanho[0],tamanho[1],tamanho[2]);
	
	cout<<"Assunto: ";
	getline(cin,assunto);
	novo->set_assunto(assunto);
	cin.clear();
	fflush(stdin);
	
	i=0;
	cout<<"Digite '0' para finalizar:\n";
	do{
		cout<<"Palavra Chave "<<i+1<<": ";
		getline(cin,aux);
		if(aux.compare("0")!=0){
			novo->set_pchave(aux);
		}
		cin.clear();
		fflush(stdin);
		i++;
	}while(aux.compare("0")!=0);
}

Item* Acervo::criar_livro(){
	Item* novo=new Livro();
	
	cout<<"Cadastrar Livro:\n";
	
	criar_item(novo);
	
	string cdu=construir_cdu(1);
	novo->set_cdu(cdu);
	
	int paginas;
	int edicao;
	string editora; //editora/revista cientifica
	string isbn;
	bool tst;
	
	cout<<"Paginas: ";
	cin>>paginas;
	(dynamic_cast<Livro*>(novo))->set_paginas(paginas);
	cin.clear();
	fflush(stdin);
	
	cout<<"Edicao: ";
	cin>>edicao;
	(dynamic_cast<Livro*>(novo))->set_edicao(edicao);
	cin.clear();
	fflush(stdin);
	
	cout<<"Editora: ";
	getline(cin,editora);
	(dynamic_cast<Livro*>(novo))->set_editora(editora);
	cin.clear();
	fflush(stdin);
	
	do{
		cout<<"ISBN: ";
		getline(cin,isbn);
		tst=(dynamic_cast<Livro*>(novo))->set_isbn(isbn);
		if(tst==false){
			cout<<"ISBN inválido!\n";
		}
		cin.clear();
	fflush(stdin);
	}while(tst==false);
	
	return novo;
}

Item* Acervo::criar_periodico(){
	Item* novo=new Periodico();
	
	cout<<"Cadastrar Periódico:\n";
	
	criar_item(novo);
	
	string cdu=construir_cdu(2);
	novo->set_cdu(cdu);
	//Livro
	int paginas;
	int edicao;
	string editora; //editora/revista cientifica
	string isbn;
	bool tst;
	//Periodico
	string data;
	int choice;
	string subs;
	
	cout<<"Paginas: ";
	cin>>paginas;
	(dynamic_cast<Periodico*>(novo))->set_paginas(paginas);
	cin.clear();
	fflush(stdin);
	
	cout<<"Edicao: ";
	cin>>edicao;
	(dynamic_cast<Periodico*>(novo))->set_edicao(edicao);
	cin.clear();
	fflush(stdin);
	
	cout<<"Editora: ";
	getline(cin,editora);
	(dynamic_cast<Periodico*>(novo))->set_editora(editora);
	cin.clear();
	fflush(stdin);
	
	do{
		cout<<"ISBN: ";
		getline(cin,isbn);
		tst=(dynamic_cast<Periodico*>(novo))->set_isbn(isbn);
		if(tst==false){
			cout<<"ISBN inválido!\n";
		}
		cin.clear();
	fflush(stdin);
	}while(tst==false);
	
	do{
		cout<<"Data: ";
		getline(cin,data);
		tst=(dynamic_cast<Periodico*>(novo))->set_data(data);
		if(tst==false){
			cout<<"Data inválida!\n";
		}
		cin.clear();
	fflush(stdin);
	}while(tst==false);
	subs=data.substr(6,4); //copia ano de data
	novo->set_ano(stoi(subs));
	
	do{
		cout<<"Tipo de Periódico:\n\t1 para Jornal;\n\t2 para Revista;\n";
		cin>>choice;
		if(choice<1 || choice>2){
			cout<<"Opção inválida!\n";
		}
		cin.clear();
		fflush(stdin);
	}while(choice<1 || choice>2);
	switch(choice){
		case 1:
			(dynamic_cast<Periodico*>(novo))->set_tipo(Jornal);
		break;
		case 2:
			(dynamic_cast<Periodico*>(novo))->set_tipo(Revista);
		break;
	}
	
	return novo;
}

Item* Acervo::criar_trab(){
	Item* novo=new TrabConclusao();
		
	cout<<"Cadastrar Trabalho científico:\n";
		
	criar_item(novo);
	
	string cdu=construir_cdu(3);
	novo->set_cdu(cdu);
	//Livro
	int paginas;
	int edicao;
	string editora; //editora/revista cientifica
	string isbn;
	bool tst;
	//TrabC
	string instituicao;
	int choice;
	
	cout<<"Paginas: ";
	cin>>paginas;
	(dynamic_cast<TrabConclusao*>(novo))->set_paginas(paginas);
	cin.clear();
	fflush(stdin);
	
	cout<<"Edicao: ";
	cin>>edicao;
	(dynamic_cast<TrabConclusao*>(novo))->set_edicao(edicao);
	cin.clear();
	fflush(stdin);
	
	cout<<"Editora: ";
	getline(cin,editora);
	(dynamic_cast<TrabConclusao*>(novo))->set_editora(editora);
	cin.clear();
	fflush(stdin);
	
	do{
		cout<<"ISBN: ";
		getline(cin,isbn);
		tst=(dynamic_cast<TrabConclusao*>(novo))->set_isbn(isbn);
		if(tst==false){
			cout<<"ISBN inválido!\n";
		}
		cin.clear();
	fflush(stdin);
	}while(tst==false);
	
	cout<<"Instituição: ";
	getline(cin,instituicao);
	(dynamic_cast<TrabConclusao*>(novo))->set_instituicao(instituicao);
	cin.clear();
	fflush(stdin);
	
	do{
		cout<<"Tipo de Trabalho:\n\t1 para Monografia;\n\t2 para Dissertação;\n\t3 para Tese;\n\t4 para Relatório;\n\t5 para Cartaz;\n";
		cin>>choice;
		if(choice<1 || choice>5){
			cout<<"Opção inválida!\n";
		}
		cin.clear();
		fflush(stdin);
	}while(choice<1 || choice>5);
	switch(choice){
		case 1:
			(dynamic_cast<TrabConclusao*>(novo))->set_tipo(Monografia);
		break;
		case 2:
			(dynamic_cast<TrabConclusao*>(novo))->set_tipo(Dissertacao);
		break;
		case 3:
			(dynamic_cast<TrabConclusao*>(novo))->set_tipo(Tese);
		break;
		case 4:
			(dynamic_cast<TrabConclusao*>(novo))->set_tipo(Relatorio);
		break;
		case 5:
			(dynamic_cast<TrabConclusao*>(novo))->set_tipo(Cartaz);
		break;
	}
	
	return novo;
}

Item* Acervo::criar_midia(){
	Item *novo=new Midia();
	
	cout<<"Cadastrar Mídia:\n";
	
	criar_item(novo);
	
	string cdu=construir_cdu(4);
	novo->set_cdu(cdu);
	
	bool tst;
	float duracao; //minutos
	int choice;
	
	do{
		cout<<"Duração(min): ";
		cin>>duracao;
		tst=(dynamic_cast<Midia*>(novo))->set_duracao(duracao);
		if(tst==false){
			cout<<"Tempo inválido!\n";
		}
		cin.clear();
		fflush(stdin);
	}while(tst==false);
	
	do{
		cout<<"Tipo de Midia:\n\t1 para VHS;\n\t2 para CD;\n\t3 para DVD;\n\t4 para Cartao SD;\n";
		cin>>choice;
		if(choice<1 || choice>4){
			cout<<"Opção inválida!\n";
		}
		cin.clear();
		fflush(stdin);
	}while(choice<1 || choice>4);
	switch(choice){
		case 1:
			(dynamic_cast<Midia*>(novo))->set_tipo(VHS);
		break;
		case 2:
			(dynamic_cast<Midia*>(novo))->set_tipo(CD);
		break;
		case 3:
			(dynamic_cast<Midia*>(novo))->set_tipo(DVD);
		break;
		case 4:
			(dynamic_cast<Midia*>(novo))->set_tipo(SDCard);
		break;
	}
	
	return novo;
}

Item* Acervo::criar_mapa(){
	Item* novo=new Mapa();
	
	cout<<"Cadastrar Mapa:\n";
	
	criar_item(novo);
	
	string cdu=construir_cdu(5);
	novo->set_cdu(cdu);
	
	bool tst;
	string local;
	float ratio; //proporção
	
	cout<<"Local do Mapa: ";
	cin>>local;
	(dynamic_cast<Mapa*>(novo))->set_local(local);
	cin.clear();
	fflush(stdin);
	
	do{
		cout<<"Proporção do Mapa: ";
		cin>>ratio;
		tst=(dynamic_cast<Mapa*>(novo))->set_ratio(ratio);
		if(tst==false){
			cout<<"Proporção inválida!\n";
		}
		cin.clear();
		fflush(stdin);
	}while(tst==false);
	
	return novo;
}

void Acervo::imprimir_cdu_all(){
	int i;
	Item* aux;
	for(i=0;i<inventario.size();i++){
		aux=inventario[i];
		cout<<i+1<<"- CDU: "<<aux->get_cdu()<<"; Título: "<<aux->get_titulo()<<endl;
	}
}

Item* Acervo::pesquisar_cdu(string chave){
	int i;
	Item *aux;
	//nnn.nn:nnn.nn
	if(chave.size()!=13 || chave[3]!='.' || chave[6]!=':' || chave[10]!='.'){
		return NULL;
	}
	if(inventario.size()==0){
		return NULL;
	}
	for(i=0;i<inventario.size();i++){
		aux=inventario[i];
		
		if(aux->get_cdu().compare(chave)==0){
			return aux;
		}
	}
	return NULL;
}

Item* Acervo::pesquisar_isbn(string chave){
	int i;
	Item* aux;
	//ISBN: nn-nnnn-nnn-n
	if(chave.size()!=13 || chave[2]!='-' || chave[7]!='-' || chave[11]!='-'){
		return NULL;
	}
	if(inventario.size()==0){
		return NULL;
	}
	for(i=0;i<inventario.size();i++){
		aux=inventario[i];
		if((dynamic_cast<Livro*>(aux))){ //se conseguir transformar em livro, tem isbn
			if((dynamic_cast<Livro*>(aux))->get_isbn().compare(chave)==0){
				return aux;
			}
		}
	}
	return NULL;
}

vector<int> Acervo::pesquisar_assunto(string chave){
	int i;
	Item *aux;
	vector<int> l;
	
	if(inventario.size()==0){
		return l;
	}
	for(i=0;i<inventario.size();i++){
		aux=inventario[i];
		
		if(aux->get_assunto().compare(chave)==0){
			l.push_back(i);
		}
	}
	return l;
}

vector<int> Acervo::pesquisar_pchave(string chave){
	int i,j;
	Item *aux;
	vector<string> p;
	string c;
	vector<int> l;
	
	if(inventario.size()==0){
		return l;
	}
	for(i=0;i<inventario.size();i++){
		aux=inventario[i];
		aux->get_pchaves(&p);
		for(j=0;j<p.size();j++){
			c=p[j];
			if(c.compare(chave)==0){
				l.push_back(i);
				//break?
			}
		}
	}
	return l;
}

vector<int> Acervo::pesquisar_autor(string chave){
	int i,j;
	Item *aux;
	vector<string> p;
	string c;
	vector<int> l;
	
	if(inventario.size()==0){
		return l;
	}
	for(i=0;i<inventario.size();i++){
		aux=inventario[i];
		aux->get_autores(&p);
		for(j=0;j<p.size();j++){
			c=p[j];
			if(c.compare(chave)==0){
				l.push_back(i);
			}
		}
	}
	return l;
}

vector<int> Acervo::pesquisar_ano(int chave){
	int i;
	Item *aux;
	vector<int> l;
	
	if(inventario.size()==0){
		return l;
	}
	for(i=0;i<inventario.size();i++){
		aux=inventario[i];
		
		if(aux->get_ano()==chave){
			l.push_back(i);
		}
	}
	return l;
}

void Acervo::imprimir_cdu_sp(vector<int> sp){
	int i,j;
	Item* aux;
	for(i=0;i<inventario.size();i++){
		for(j=0;j<sp.size();j++){
			if(i==sp[j]){
				aux=inventario[i];
				cout<<"CDU: "<<aux->get_cdu()<<"; Título: "<<aux->get_titulo()<<endl;
				break;
			}
		}
	}
}

void Acervo::imprimir_devolucao(){
	int i;
	Item* aux;
	for(i=0;i<inventario.size();i++){
		aux=inventario[i];
		if(aux->get_qtd()!=aux->get_qtdcontrol()){
			cout<<"CDU: "<<aux->get_cdu()<<"; Título: "<<aux->get_titulo()<<endl;
		}
	}
}

bool Acervo::opcao_alt(Item* item){
	int op,i=0;
	string s_aux;
	int i_aux;
	float f_aux,tamanho[3];
	bool tst;
	cout<<"O que será atualizado:\n\t1 - Titulo da obra;\n\t2 - Quantidade;\n\t3 - Autores;\n\t4 - Cidade;\n\t5 - Ano;\n\t6 - Tamanho;\n\t7 - Assunto;\n\t8 - Palavra chave;\n";
	if((dynamic_cast<Livro*>(item))){
		cout<<"\t9 - N° de páginas;\n\t10 - Edição;\n\t11 - Editora;\n\t12 - ISBN;\n";
		if((dynamic_cast<Periodico*>(item))){
			cout<<"\t13 - Data;\n\t14 - Tipo de Periódico;\n";
		}
		else if((dynamic_cast<TrabConclusao*>(item))){
			cout<<"\t13 - Instituição;\n\t14 - Tipo de Trabalho;\n";
		}
	}
	else if((dynamic_cast<Midia*>(item))){
		cout<<"\t9 - Duração;\n\t10 - Tipo de Mídia;\n";
	}
	else if((dynamic_cast<Mapa*>(item))){
		cout<<"\t9 - Local;\n\t10 - Proporção;\n";
	}
	cout<<"\t0 - Cancelar;\n";
	cout<<"------------------------------------\n";
	cin>>op;
	cin.clear();
	fflush(stdin);
	
	switch(op){
		case 0:
			return 0;
		break;
		case 1:
			cout<<"Digite novo título ("<<item->get_titulo()<<"): ";
			getline(cin,s_aux);
			item->set_titulo(s_aux);
			cin.clear();
			fflush(stdin);
		break;
		case 2:
			cout<<"Digite nova quantidade ("<<item->get_qtdcontrol()<<"): ";
			cin>>i_aux;
			item->set_qtd(i_aux);
			cin.clear();
			fflush(stdin);
		break;
		case 3:
			item->limpar_autor();
			cout<<"Digite '0' para finalizar:\n";
			do{
				cout<<"Autor "<<i+1<<": ";
				getline(cin,s_aux);
				if(s_aux.compare("0")!=0){
					item->set_autor(s_aux);
				}
				cin.clear();
				fflush(stdin);
				i++;
			}while(s_aux.compare("0")!=0);
		break;
		case 4:
			cout<<"Digite nova cidade ("<<item->get_cidade()<<"): ";
			getline(cin,s_aux);
			item->set_cidade(s_aux);
			cin.clear();
			fflush(stdin);
		break;
		case 5:
			do{
				cout<<"Novo ano ("<<item->get_ano()<<"): ";
				cin>>i_aux;
				if(i_aux>2023 || i_aux<0){
					cout<<"Ano inválido!\n";
				}
				cin.clear();
				fflush(stdin);
			}while(i_aux>2023 || i_aux<0);
			item->set_ano(i_aux);
			if((dynamic_cast<Periodico*>(item))){
				s_aux=(dynamic_cast<Periodico*>(item))->get_data();
				s_aux.replace(6,4,to_string(i_aux));
				(dynamic_cast<Periodico*>(item))->set_data(s_aux);
			}
		break;
		case 6:
			item->get_tamanho(&tamanho[0],&tamanho[1],&tamanho[2]);
			cout<<"Novo tamanho do item ("<<tamanho[0]<<"x"<<tamanho[1]<<"x"<<tamanho[2]<<") (cm):\nComprimento: ";
			cin>>tamanho[0];
			cin.clear();
			fflush(stdin);
			
			cout<<"Altura: ";
			cin>>tamanho[1];
			cin.clear();
			fflush(stdin);
			
			cout<<"Largura: ";
			cin>>tamanho[2];
			cin.clear();
			fflush(stdin);
			
			item->set_tamanho(tamanho[0],tamanho[1],tamanho[2]);
		break;
		case 7:
			cout<<"Digite novo assunto ("<<item->get_assunto()<<"): ";
			getline(cin,s_aux);
			item->set_assunto(s_aux);
			cin.clear();
			fflush(stdin);
		break;
		case 8:
			item->limpar_pchave();
			cout<<"Digite '0' para finalizar:\n";
			do{
				cout<<"Palavra chave "<<i+1<<": ";
				getline(cin,s_aux);
				if(s_aux.compare("0")!=0){
					item->set_pchave(s_aux);
				}
				cin.clear();
				fflush(stdin);
				i++;
			}while(s_aux.compare("0")!=0);
		break;
		case 9:
			if((dynamic_cast<Livro*>(item))){
				cout<<"Novo n° paginas ("<<(dynamic_cast<Livro*>(item))->get_paginas()<<"): ";
				cin>>i_aux;
				(dynamic_cast<Livro*>(item))->set_paginas(i_aux);
				cin.clear();
				fflush(stdin);
			}
			else if((dynamic_cast<Midia*>(item))){
				do{
					cout<<"Nova duração ("<<(dynamic_cast<Midia*>(item))->get_duracao()<<") (min): ";
					cin>>f_aux;
					tst=(dynamic_cast<Midia*>(item))->set_duracao(f_aux);
					if(tst==false){
						cout<<"Tempo inválido!\n";
					}
					cin.clear();
					fflush(stdin);
				}while(tst==false);
			}
			else if((dynamic_cast<Mapa*>(item))){
				cout<<"Digite novo local ("<<(dynamic_cast<Mapa*>(item))->get_local()<<"): ";
				getline(cin,s_aux);
				(dynamic_cast<Mapa*>(item))->set_local(s_aux);
				cin.clear();
				fflush(stdin);
			}
		break;
		case 10:
			if((dynamic_cast<Livro*>(item))){
				cout<<"Nova edição ("<<(dynamic_cast<Livro*>(item))->get_edicao()<<"): ";
				cin>>i_aux;
				(dynamic_cast<Livro*>(item))->set_edicao(i_aux);
				cin.clear();
				fflush(stdin);
			}
			else if((dynamic_cast<Midia*>(item))){
				do{
					cout<<"Novo tipo de Midia:\n\t1 para VHS;\n\t2 para CD;\n\t3 para DVD;\n\t4 para Cartao SD;\n";
					cin>>i_aux;
					if(i_aux<1 || i_aux>4){
						cout<<"Opção inválida!\n";
					}
					cin.clear();
					fflush(stdin);
				}while(i_aux<1 || i_aux>4);
				switch(i_aux){
					case 1:
						(dynamic_cast<Midia*>(item))->set_tipo(VHS);
					break;
					case 2:
						(dynamic_cast<Midia*>(item))->set_tipo(CD);
					break;
					case 3:
						(dynamic_cast<Midia*>(item))->set_tipo(DVD);
					break;
					case 4:
						(dynamic_cast<Midia*>(item))->set_tipo(SDCard);
					break;
				}
			}
			else if((dynamic_cast<Mapa*>(item))){
				do{
					cout<<"Nova proporção do Mapa ("<<(dynamic_cast<Mapa*>(item))->get_ratio()<<"): ";
					cin>>f_aux;
					tst=(dynamic_cast<Mapa*>(item))->set_ratio(f_aux);
					if(tst==false){
						cout<<"Proporção inválida!\n";
					}
					cin.clear();
					fflush(stdin);
				}while(tst==false);
			}
		break;
		case 11:
			if((dynamic_cast<Livro*>(item))){
				cout<<"Nova editora ("<<(dynamic_cast<Livro*>(item))->get_editora()<<"): ";
				getline(cin,s_aux);
				(dynamic_cast<Livro*>(item))->set_editora(s_aux);
				cin.clear();
				fflush(stdin);
			}
		break;
		case 12:
			if((dynamic_cast<Livro*>(item))){
				do{
					cout<<"novo ISBN ("<<(dynamic_cast<Livro*>(item))->get_isbn()<<"): ";
					getline(cin,s_aux);
					tst=(dynamic_cast<Livro*>(item))->set_isbn(s_aux);
					if(tst==false){
						cout<<"ISBN inválido!\n";
					}
					cin.clear();
					fflush(stdin);
				}while(tst==false);
			}
		break;
		case 13:
			if((dynamic_cast<Periodico*>(item))){
				do{
					cout<<"Nova data ("<<(dynamic_cast<Periodico*>(item))->get_data()<<"): ";
					getline(cin,s_aux);
					tst=(dynamic_cast<Periodico*>(item))->set_data(s_aux);
					if(tst==false){
						cout<<"Data inválida!\n";
					}
					cin.clear();
				fflush(stdin);
				}while(tst==false);
				item->set_ano(stoi(s_aux.substr(6,4)));
			}
			else if((dynamic_cast<TrabConclusao*>(item))){
				cout<<"Nova instituição ("<<(dynamic_cast<TrabConclusao*>(item))->get_instituicao()<<"): ";
				getline(cin,s_aux);
				(dynamic_cast<TrabConclusao*>(item))->set_instituicao(s_aux);
				cin.clear();
				fflush(stdin);
			}
		break;
		case 14:
			if((dynamic_cast<Periodico*>(item))){
				do{
					cout<<"Tipo de Periódico:\n\t1 para Jornal;\n\t2 para Revista;\n";
					cin>>i_aux;
					if(i_aux<1 || i_aux>2){
						cout<<"Opção inválida!\n";
					}
					cin.clear();
					fflush(stdin);
				}while(i_aux<1 || i_aux>2);
				switch(i_aux){
					case 1:
						(dynamic_cast<Periodico*>(item))->set_tipo(Jornal);
					break;
					case 2:
						(dynamic_cast<Periodico*>(item))->set_tipo(Revista);
					break;
				}
			}
			else if((dynamic_cast<TrabConclusao*>(item))){
				do{
					cout<<"Tipo de Trabalho:\n\t1 para Monografia;\n\t2 para Dissertação;\n\t3 para Tese;\n\t4 para Relatório;\n\t5 para Cartaz;\n";
					cin>>i_aux;
					if(i_aux<1 || i_aux>5){
						cout<<"Opção inválida!\n";
					}
					cin.clear();
					fflush(stdin);
				}while(i_aux<1 || i_aux>5);
				switch(i_aux){
					case 1:
						(dynamic_cast<TrabConclusao*>(item))->set_tipo(Monografia);
					break;
					case 2:
						(dynamic_cast<TrabConclusao*>(item))->set_tipo(Dissertacao);
					break;
					case 3:
						(dynamic_cast<TrabConclusao*>(item))->set_tipo(Tese);
					break;
					case 4:
						(dynamic_cast<TrabConclusao*>(item))->set_tipo(Relatorio);
					break;
					case 5:
						(dynamic_cast<TrabConclusao*>(item))->set_tipo(Cartaz);
					break;
				}
			}
		break;
	}
	return 1;
}

void Acervo::get_maior_cdu(){
	Item *item;
	int i,maior=0,p;
	
	if(inventario.size()==0){
		chave_cdu=0; //zero itens
	}
	else{
		maior=Acervo::stoi_cdu(inventario[0]);
		for(i=1;i<inventario.size();i++){ //procura maior cdu
			item=inventario[i];
			p=Acervo::stoi_cdu(item);
			if(maior<p){
				maior=p; //salva maior cdu
			}
		}
		//012.34:567.89
		chave_cdu=maior+1; //subtrai classificacao
	}
}
