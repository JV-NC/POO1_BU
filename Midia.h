#ifndef MIDIA_H
#define MIDIA_H

#include "Item.h"

enum TipoMidia{
	VHS=1,
	CD=2,
	DVD=3,
	SDCard=4
};

class Midia : public Item
{
	public:
		Midia();
		Midia(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,float duracao,TipoMidia tipo);
		~Midia();
		
		float get_duracao();
		TipoMidia get_tipo();
		
		bool set_duracao(float duracao);
		void set_tipo(TipoMidia tipo);
		
		void ficha_catalografica();
	protected:
		float duracao; //minutos
		TipoMidia tipo;
};

#endif
