#pragma once
#include "Personagem.h"
class Ferreiro :
	public Personagem
{
public:
	Ferreiro();
	~Ferreiro();
	void inicializar(int x_, int y_);
	void atualizar();
	void defender();
	void especial();
private:

};

