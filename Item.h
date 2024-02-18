#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>

using namespace std;

class Item
{
	public:
		Item();
		Item(int qtd,int qtdcontrol,string titulo,vector<string> autor,string cidade,int ano,string cdu,string assunto,vector<string> pchave,vector<float> tamanho);
		~Item();
		
		int get_qtd();
		int get_qtdcontrol();
		string get_titulo();
		void get_autores(vector<string> *autores); //trocar por ponteiro para passagem por referencia
		string get_cidade();
		int get_ano();
		void get_tamanho(float *x,float *y,float *z);
		string get_cdu();
		string get_assunto();
		void get_pchaves(vector<string> *pchaves);
		
		void set_qtd(int qtd);
		void set_qtd(int qtd,int qtdcontrol); //sobrecarga para arquivo
		void set_titulo(string titulo);
		void set_autor(string nome);
		void set_cidade(string cidade);
		void set_ano(int ano);
		void set_tamanho(float x,float y,float z);
		bool set_cdu(string cdu);
		void set_assunto(string assunto);
		void set_pchave(string palavra);
		
		bool emprestar();
		bool devolver();
		virtual void ficha_catalografica()=0;
		void limpar_autor();
		void limpar_pchave();
	protected:
		int quantidade; //quantidade de copias para serem emprestadas pela biblioteca
		int qtdcontrol; //define a quantidade de itens totais da biblioteca
		string titulo;
		vector<string> autor;
		string cidade;
		int ano;
		float tamanho[3]; //tridimensional
		string cdu;
		string assunto;
		vector<string> pchave;
		
		virtual int maior_tamanho(); //define maior linha de informações na ficha catalografica
		
};

#endif
