#ifndef LIVRO_H
#define LIVRO_H

#include "Item.h"

class Livro : public Item
{
	public:
		Livro();
		Livro(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,int paginas,int edicao,string editora,string isbn);
		~Livro();
		
		int get_paginas();
		int get_edicao();
		string get_editora();
		string get_isbn();
		
		void set_paginas(int paginas);
		void set_edicao(int edicao);
		void set_editora(string editora);
		bool set_isbn(string isbn);
		
		virtual void ficha_catalografica();
	protected:
		int paginas;
		int edicao;
		string editora; //editora/revista cientifica
		string isbn;
		
		virtual int maior_tamanho();
};

#endif
