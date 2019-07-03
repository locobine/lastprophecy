#pragma once
#include "Personagem.h"
class Cacador :
	public Personagem
{
public:
	Cacador();
	~Cacador();
	void inicializar(int x_, int y_);
	void atualizar();
	void andaCima();
	void andaBaixo();
	void andaEsquerda();
	bool getCooldownCacador();
	void recuar();
	void especial();
	void desEspecial();
private:
	bool deveRecuar, cooldownCacador;

};

