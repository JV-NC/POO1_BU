#ifndef ACERVO_H
#define ACERVO_H

#include <string>
#include "Periodico.h"
#include "TrabConclusao.h"
#include "Midia.h"
#include "Mapa.h"

class Acervo
{
	public:
		Acervo();
		~Acervo();
		
		Item* get_item(int pos);
		void add_item(Item* item);
		Item* remover_item(int pos);
		int get_tamanho();
		
		Item* criar_livro();
		Item* criar_periodico();
		Item* criar_trab();
		Item* criar_midia();
		Item* criar_mapa();
		
		void imprimir_cdu_all();
		
		Item* pesquisar_cdu(string chave);
		Item* pesquisar_isbn(string chave);
		vector<int> pesquisar_assunto(string chave);
		vector<int> pesquisar_pchave(string chave);
		vector<int> pesquisar_autor(string chave);
		vector<int> pesquisar_ano(int chave);
		
		void imprimir_cdu_sp(vector<int> sp);
		void imprimir_devolucao();
		
		bool opcao_alt(Item* item);
		
	private:
		vector<Item*> inventario;
		int chave_cdu;
		
		string construir_cdu(int tipo);
		int stoi_cdu(Item *item);
		void criar_item(Item *novo);
		void get_maior_cdu();
};

#endif
