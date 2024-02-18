#ifndef MANTERDADOS_H
#define MANTERDADOS_H

#include <fstream>
#include <sstream>
#include "Acervo.h"

#define ARQUIVO "log.txt"

class ManterDados
{
	public:
		ManterDados();
		~ManterDados();
		
		bool carregar(Acervo *a);
		bool salvar(Acervo *a);
	protected:
		int get_tipo_item(Item *item);
		string trocar_ponto(string s);
};

#endif
