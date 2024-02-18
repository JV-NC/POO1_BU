#ifndef PERIODICO_H
#define PERIODICO_H

#include "Livro.h"

enum TipoPeriodico{
	Jornal=1,
	Revista=2,
};

class Periodico : public Livro
{
	public:
		Periodico();
		Periodico(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,int paginas,int edicao,string editora,string isbn,string data,TipoPeriodico tipo);
		~Periodico();
		
		string get_data();
		TipoPeriodico get_tipo();
		
		bool set_data(string data);
		void set_tipo(TipoPeriodico tipo);
		
		void ficha_catalografica();
	protected:
		string data;
		TipoPeriodico tipo;
		
		int maior_tamanho();
};

#endif
