#pragma once
#include "Personagem.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <fstream>
#include <iostream>
#include <time.h>
#include "Timer.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "ListaPersonagens.h"
#include "Ferreiro.h"
#include "Barbeiro.h"
#include "Cacador.h"
#include "Musico.h"
#include "Collision.h"

//enum Menu
//{
//	Logo, NovoJogo, ContinuarJogo, Creditos, Sair,
//	Inicial, CriarTime, SelecionarTime, InicializarServidor, ConectarServidor,
//	preBatalha, Batalha, AcaoAtacar, AcaoDefender, AcaoItem, AcaoMagia, GameOver
//};

using namespace std;
using namespace sf;

enum MomentoAtualDoJogo
{
	MenuIni, Editor, TelaJogo
};

class Jogo
{
public:
	Jogo();
	Jogo(string Title);
	~Jogo();

	void carregaJogo();

private:
	void inicializar();
	void executar();
	void finalizar();
	void maoManager(Event eventinho);
	void checaCliques();
	void coliseia();
	void moveAFK();
	void trocaSegundo();
	void trocaSegundoDois();
	void trocaTerceiro();
	void interpretaMagia();
	void fazUI();
	RenderWindow janela;
	Mouse mouse;
	Clock frameClock;
	Sprite sprBatalha, sprUIbatalha;
	Texture txtBatalha, txtUIbatalha;
	Personagem persBeta;
	Personagem *persoDinam;
	Personagem tresPerso[3];
	bool correndo, playerAtacando, cacadorAtacou, andou, delayPassou;
	bool podeCima, podeBaixo, podeEsquerda, podeDireita, magoMagiou, apertouTab;
	//bool direita, cima, esquerda, baixo;
	Timer reloginho, relogioAtaque, relogioAtaqueCacador, relogioDelayCaminhada, relogioMagia;
	
	ListaPersonagens filaPerso;
	vector<Projetil*> projeteis;
	vector<Inimigo*> vetorInimigos;
	Inimigo iniBeta[3];
	vector<Projetil*> projeteisIni;
	
	Font fonteBatalha;
	Text nome1, nome2, nome3, vida1, vida2, vida3, mana1, mana2, mana3, level1, level2, level3;

	Personagem* personagemAtual;

	//TESTE
	vector<Projetil> projeTestes;
	Projetil projeTeste, projeTeste2;
};