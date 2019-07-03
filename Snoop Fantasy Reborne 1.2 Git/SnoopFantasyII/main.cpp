#pragma once
#include "Jogo.h"

int main(int ArgC, char** ArgV)
{
	Jogo game("Last Prophecy");
	game.carregaJogo();
	return 0;
}