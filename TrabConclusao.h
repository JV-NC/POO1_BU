#ifndef TRABCONCLUSAO_H
#define TRABCONCLUSAO_H

#include "Livro.h"

enum TipoTrabalho{
	Monografia=1,
	Dissertacao=2,
	Tese=3,
	Relatorio=4,
	Cartaz=5
};

class TrabConclusao : public Livro
{
	public:
		TrabConclusao();
		TrabConclusao(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,int paginas,int edicao,string editora,string isbn,string instituicao,TipoTrabalho tipo);
		~TrabConclusao();
		
		TipoTrabalho get_tipo();
		string get_instituicao();
		
		void set_tipo(TipoTrabalho tipo);
		void set_instituicao(string instituicao);
		
		void ficha_catalografica();
	protected:
		TipoTrabalho tipo;
		string instituicao;
		
		int maior_tamanho();
};

#endif
