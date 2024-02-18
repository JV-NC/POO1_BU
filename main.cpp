#include <locale>

#include "Acervo.h"
#include "ManterDados.h"

void menu();

int main() { //João Vitor Neves Costa
	setlocale(LC_ALL,"Portuguese");
	system("chcp 1252 > nul");
	
	menu();
	
	return 0;
}

void menu(){
	Acervo *a=new Acervo();
	Item *item;
	ManterDados md;
	int op,select;
	string chave;
	bool check;
	vector<int> lista;
	check=md.carregar(a);
	if(!check){
		cout<<"Falha ao carregar o log!\n";
	}
	else{
		cout<<a->get_tamanho()<<" itens carregados do log!\n";
	}
	cout<<"--------------------------------------\n\t   Trabalho de POO I\n\tJoão Vitor Neves Costa\n--------------------------------------\n\n";
	do{
		cout<<"----------------------------------------------------------------\n\t\t";
		cout<<"Sistema Biblioteca Universitária\n\n\t1 - Cadastrar item;\n\t2 - Pesquisar item;\n\t3 - Emprestar item;\n\t4 - Devolver item;\n\t5 - Imprimir ficha catalográfica;\n\t6 - Alterar item;\n\t7 - Remover item;\n\t0 - Sair;\n";
		cout<<"----------------------------------------------------------------\n\n";
		cin>>op;
		cin.clear();
		fflush(stdin);
		
		switch(op){
			case 0:
				cout<<"--------------------------\n";
				cout<<"Saindo...\n";
				
				check=md.salvar(a);
				delete a;
				//funções de salvar e liberar memoria
			break;
			case 1:
				cout<<"--------------------------------\n";
				cout<<"Cadastrar:\n\t1 - Livro;\n\t2 - Periódico;\n\t3 - Trabalho científico;\n\t4 - Mídia;\n\t5 - Mapa;\n\t0 - Cancelar;\n";
				cout<<"--------------------------------\n";
				cin>>select;
				cin.clear();
				fflush(stdin);
				item=NULL;
				switch(select){
					case 1:
						item=a->criar_livro();
						if((dynamic_cast<Livro*>(item))){
							cout<<"Livro cadastrado com sucesso!\n";
						}
					break;
					case 2:
						item=a->criar_periodico();
						if((dynamic_cast<Periodico*>(item))){
							cout<<"Periódico cadastrado com sucesso!\n";
						}
					break;
					case 3:
						item=a->criar_trab();
						if((dynamic_cast<TrabConclusao*>(item))){
							cout<<"Trabalho cadastrado com sucesso!\n";
						}
					break;
					case 4:
						item=a->criar_midia();
						if((dynamic_cast<Midia*>(item))){
							cout<<"Mídia cadastrada com sucesso!\n";
						}
					break;
					case 5:
						item=a->criar_mapa();
						if((dynamic_cast<Mapa*>(item))){
							cout<<"Mapa cadastrado com sucesso!\n";
						}
					break;
				}
				if(select>=1 && select<=5){
					a->add_item(item);
				}
			break;
			case 2:
				cout<<"--------------------------\n";
				cout<<"Pesquisar por:\n\t1 - CDU;\n\t2 - ISBN;\n\t3 - Assunto;\n\t4 - Palavra Chave;\n\t5 - Autor;\n\t6 - Ano;\n\t0 - Cancelar;\n";
				cout<<"--------------------------\n";
				cin>>select;
				cin.clear();
				fflush(stdin);
				
				switch(select){
					case 1:
						cout<<"CDU a ser pesquisado: ";
						getline(cin,chave);
						cin.clear();
						fflush(stdin);
						
						item=a->pesquisar_cdu(chave);
						
						if(item==NULL){
							cout<<"CDU não foi encontrado!\n";
						}
						else{
							item->ficha_catalografica();
						}
					break;
					case 2:
						cout<<"ISBN a ser pesquisado: ";
						getline(cin,chave);
						cin.clear();
						fflush(stdin);
						
						item=a->pesquisar_isbn(chave);
						
						if(item==NULL){
							cout<<"ISBN não foi encontrado!\n";
						}
						else{
							item->ficha_catalografica();
						}
					break;
					case 3:
						cout<<"Assunto a ser pesquisado: ";
						getline(cin,chave);
						cin.clear();
						fflush(stdin);
						
						lista=a->pesquisar_assunto(chave);
						
						if(lista.size()==0){
							cout<<"Não foi possível encontrar nenhum item com esse assunto;\n";
						}
						else{
							cout<<"Itens com o assunto \""<<chave<<"\":\n";
							a->imprimir_cdu_sp(lista);
						}
						
						lista.clear();
					break;
					case 4:
						cout<<"Palavra chave a ser pesquisada: ";
						getline(cin,chave);
						cin.clear();
						fflush(stdin);
						
						lista=a->pesquisar_pchave(chave);
						
						if(lista.size()==0){
							cout<<"Não foi possível encontrar nenhum item com essa palavra chave;\n";
						}
						else{
							cout<<"Itens com a palavra chave \""<<chave<<"\":\n";
							a->imprimir_cdu_sp(lista);
						}
						
						lista.clear();
					break;
					case 5:
						cout<<"Autor a ser pesquisado: ";
						getline(cin,chave);
						cin.clear();
						fflush(stdin);
						
						lista=a->pesquisar_autor(chave);
						
						if(lista.size()==0){
							cout<<"Não foi possível encontrar nenhum item com esse autor;\n";
						}
						else{
							cout<<"Itens com o autor \""<<chave<<"\":\n";
							a->imprimir_cdu_sp(lista);
						}
						
						lista.clear();
					break;
					case 6:
						cout<<"Ano a ser pesquisado: ";
						getline(cin,chave);
						cin.clear();
						fflush(stdin);
						
						lista=a->pesquisar_ano(stoi(chave));
						
						if(lista.size()==0){
							cout<<"Não foi possível encontrar nenhum item desse ano;\n";
						}
						else{
							cout<<"Itens de \""<<chave<<"\":\n";
							a->imprimir_cdu_sp(lista);
						}
						
						lista.clear();
					break;
				}
			break;
			case 3:
				cout<<"------------------------------------\n";
				cout<<"CDU: ";
				getline(cin,chave);
				cin.clear();
				fflush(stdin);
				
				item=a->pesquisar_cdu(chave);
				
				if(item==NULL){
					cout<<"CDU não foi encontrado!\n";
				}
				else{
					check=item->emprestar();
					
					if(check){
						cout<<"Item emprestado com sucesso!\nQtd no estoque: "<<item->get_qtd()<<endl;
					}
					else{
						cout<<"Não foi possível emprestar o livro!\n";
					}
				}
				cout<<"------------------------------------\n";
			break;
			case 4:
				cout<<"------------------------------------------------\n";
				a->imprimir_devolucao();
				cout<<"CDU: ";
				getline(cin,chave);
				cin.clear();
				fflush(stdin);
				
				item=a->pesquisar_cdu(chave);
				
				if(item==NULL){
							cout<<"CDU não foi encontrado!\n";
				}
				else{
					check=item->devolver();
					
					if(check){
						cout<<"Item devolvido com sucesso!\nQtd no estoque: "<<item->get_qtd()<<endl;
					}
					else{
						cout<<"Não foi possível devolver o item desejado!\n";
					}
				}
				cout<<"------------------------------------------------\n";
			break;
			case 5:
				if(a->get_tamanho()==0){
					cout<<"Acervo vazio!\n";
					break;
				}
				cout<<"------------------------------------------------\n";
				a->imprimir_cdu_all();
				cout<<"------------------------------------------------\n";
				cout<<"\nn°: ";
				cin>>select;
				cin.clear();
				fflush(stdin);
				if(select>0 && select<=a->get_tamanho()){
					item=a->get_item(select-1);
					item->ficha_catalografica();
				}
				else{
					cout<<"Opção inválida!\n";
				}
			break;
			case 6:
				cout<<"CDU: ";
				getline(cin,chave);
				cin.clear();
				fflush(stdin);
				
				item=a->pesquisar_cdu(chave);
				
				if(item==NULL){
					cout<<"CDU não foi encontrado!\n";
				}
				else{
					cout<<"------------------------------------\n";
					check=a->opcao_alt(item);
					
					if(check){
						cout<<"Item alterado com sucesso!\n";
					}
					else{
						cout<<"Operação cancelada!\n";
					}
				}
			break;
			case 7:
				if(a->get_tamanho()==0){
					cout<<"Acervo vazio!\n";
					break;
				}
				cout<<"------------------------------------------------\n";
				a->imprimir_cdu_all();
				cout<<"------------------------------------------------\n";
				cout<<"\nn°: ";
				cin>>select;
				cin.clear();
				fflush(stdin);
				if(select>0 && select<=a->get_tamanho()){
					item=a->remover_item(select-1);
					cout<<"Item: "<<item->get_titulo()<<", CDU: "<<item->get_cdu()<<", foi removido com sucesso!\n";
				}
				else{
					cout<<"Opção inválida!\n";
				}
			break;
			default:
				cout<<"Opção inválida!\n";
			break;
		}
	}while(op!=0);
	if(check){
		cout<<"Itens salvos com sucesso!\n";
	}
	else{
		cout<<"Falha ao salvar os itens!\n";
	}
	cout<<"--------------------------\n";
}
