#ifndef MAPA_H
#define MAPA_H

#include "Item.h"

class Mapa : public Item
{
	public:
		Mapa();
		Mapa(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho,string local,float ratio);
		~Mapa();
		
		string get_local();
		float get_ratio();
		
		void set_local(string local);
		bool set_ratio(float ratio);
		
		void ficha_catalografica();
	protected:
		string local;
		float ratio; //proporção
};

#endif
