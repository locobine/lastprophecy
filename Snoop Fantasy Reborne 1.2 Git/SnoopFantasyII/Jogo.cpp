#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::Jogo(string Title)
{
	janela.create(VideoMode(1280, 720), Title);
	//janela.create(VideoMode(1280, 720), Title, Style::Fullscreen);
}

Jogo::~Jogo()
{
}

void Jogo::carregaJogo()
{
	inicializar();
	while (janela.isOpen())
	{
		executar();
	}
	finalizar();
}

void Jogo::finalizar()
{
	
	/*while (!minhasBuild.empty())
	{
		minhasBuild.erase(minhasBuild.begin());
	}
	while (!minhasUnit.empty())
	{
		minhasUnit.erase(minhasUnit.begin());
	}*/
	
}

void Jogo::inicializar()
{
	srand(time(0));

	if (!txtBatalha.loadFromFile("bin/batalha.png"))
	{
		cout << "Erro, nao rolou a batalha." << endl;
	}
	sprBatalha.setTexture(txtBatalha);
	sprBatalha.setPosition(0, 0);
	if (!txtUIbatalha.loadFromFile("bin/interface.png"))
	{
		cout << "Erro, nao rolou a UI da batalha." << endl;
	}
	sprUIbatalha.setTexture(txtUIbatalha);
	sprUIbatalha.setPosition(0, 0);
	//personagemAtual->inicializar(3);
	//tresPerso[0].inicializar(300, 300);
	//tresPerso[1].inicializar(200, 300);
	//tresPerso[2].inicializar(100, 300);
	//filaPerso.insereInicio(&tresPerso[2]);
	//filaPerso.insereInicio(&tresPerso[1]);
	//filaPerso.insereInicio(&tresPerso[0]);

	persoDinam = new Ferreiro;
	persoDinam->inicializar(300, 300);
	filaPerso.insereInicio(persoDinam);

	persoDinam = new Musico;
	persoDinam->inicializar(200, 300);
	filaPerso.insereInicio(persoDinam);

	persoDinam = new Cacador;
	persoDinam->inicializar(100, 300);
	filaPerso.insereInicio(persoDinam);

	
	podeCima = true;
	podeBaixo = true;
	podeEsquerda = true;
	podeDireita = true;
	playerAtacando = false;
	correndo = false;
	cacadorAtacou = false;
	delayPassou = false;
	magoMagiou = false;
	apertouTab = false;

	
	//for (int x = 0; x < 3; x++)
	//{
	//	inimigoAux = new Inimigo;
	//	inimigoAux->inicializar(x);
	//	vetorInimigos.push_back(inimigoAux);
	//	//iniBeta[x].inicializar(x);

	//}
	Inimigo* inimigoAux;
	inimigoAux = new Inimigo;
	inimigoAux->inicializar(0, 1000, 200);
	vetorInimigos.push_back(inimigoAux);

	inimigoAux = new Inimigo;
	inimigoAux->inicializar(0, 1000, 300);
	vetorInimigos.push_back(inimigoAux);

	inimigoAux = new Inimigo;
	inimigoAux->inicializar(0, 1000, 400);
	vetorInimigos.push_back(inimigoAux);

	inimigoAux = new Inimigo;
	inimigoAux->inicializar(1, 800, 250);
	vetorInimigos.push_back(inimigoAux);

	inimigoAux = new Inimigo;
	inimigoAux->inicializar(1, 800, 350);
	vetorInimigos.push_back(inimigoAux);

	if (!fonteBatalha.loadFromFile("bin/fonte.ttf"))
	{
		cout << "error" << endl;
	}
	nome1.setFont(fonteBatalha);
	nome2.setFont(fonteBatalha);
	nome3.setFont(fonteBatalha);
	vida1.setFont(fonteBatalha);
	vida2.setFont(fonteBatalha);
	vida3.setFont(fonteBatalha);
	mana1.setFont(fonteBatalha);
	mana2.setFont(fonteBatalha);
	mana3.setFont(fonteBatalha);
	level1.setFont(fonteBatalha);
	level2.setFont(fonteBatalha);
	level3.setFont(fonteBatalha);

	nome1.setPosition(50, 550);
	nome2.setPosition(50, 600);
	nome3.setPosition(50, 650);

	level1.setPosition(200, 550);
	level2.setPosition(200, 600);
	level3.setPosition(200, 650);

	vida1.setPosition(250, 550);
	vida2.setPosition(250, 600);
	vida3.setPosition(250, 650);

	mana1.setPosition(375, 550);
	mana2.setPosition(375, 600);
	mana3.setPosition(375, 650);


	//relogioDelayCaminhada.contaAte(0.3);

	//projeTeste.inicializar(0, false, 0, personagemAtual->getXReal() + 72, personagemAtual->getYReal() + 23, personagemAtual->getAtaque());
	//projeTeste2.inicializar(1, false, 0, personagemAtual->getXReal() + 67, personagemAtual->getYReal() + 25, personagemAtual->getAtaque());
}

void Jogo::maoManager(Event eventinho)
{
	Event eventto;
	eventto = eventinho;
	
	if (eventto.type == Event::KeyReleased)
	{
		switch (eventto.key.code)
		{
		case Keyboard::Escape:
			janela.close();
			break;
		case Keyboard::Num3:
			//trocaTerceiro();
			break;
		case Keyboard::Num2:
			//trocaSegundo();
			break;
		case Keyboard::Num1:

			break;
		case Keyboard::Tab:
			
			if (personagemAtual->proximo->getMorto() && filaPerso.getUltimo()->getMorto())
			{

			}
			else if (personagemAtual->proximo->getMorto())
			{
				trocaTerceiro();
				cout << "troca segundo" << endl;
			}
			else if (filaPerso.getUltimo()->getMorto())
			{
				trocaSegundoDois();
				cout << "troca segundo dois " << endl;
			}
			else
			{
				trocaSegundo();
			}
		default:

			break;
		}
	}
	
}

void Jogo::checaCliques()
{
	personagemAtual->paraAndar();
	if (Mouse::isButtonPressed(Mouse::Button::Left) && !personagemAtual->getEspecializando())
	{
		personagemAtual->ataca();
	}
	else if (Mouse::isButtonPressed(Mouse::Button::Right) && !personagemAtual->getAtacando())
	{
		personagemAtual->especial();
	}
	
	if (personagemAtual->getAtacouTipo() == 2)
	{
		Projetil* magAuxiliar;
		magAuxiliar = new Projetil;
		//magAuxiliar->inicializarTeste(0, false, 0, personagemAtual->getXReal() + 72, personagemAtual->getYReal() + 23, personagemAtual->getAtaque(), txtTeste);
		magAuxiliar->inicializar(0, false, 0, personagemAtual->getXReal() + 72, personagemAtual->getYReal() + 23, personagemAtual->getAtaque());
		projeteis.push_back(magAuxiliar);
		//projeteis.emplace_back(magAuxiliar);
		personagemAtual->setAtacouTipo(0);

		//FUNCIONA MAS EH MT BUGADO
		/*projeTeste.reinicializar(0, false, 0, personagemAtual->getXReal() + 72, personagemAtual->getYReal() + 23, personagemAtual->getAtaque());
		projeTestes.push_back(projeTeste);
		personagemAtual->setAtacouTipo(0);*/
	}
	if (personagemAtual->getCastou())
	{
		Projetil* magAuxiliar;
		magAuxiliar = new Projetil;
		magAuxiliar->inicializar(1, false, 0, personagemAtual->getXReal() + 67, personagemAtual->getYReal() + 25, personagemAtual->getAtaque());
		projeteis.push_back(magAuxiliar);
		personagemAtual->setCastou(false);


		//FUNCIONA MAS EH MT BUGADO
		/*projeTeste2.reinicializar(1, false, 0, personagemAtual->getXReal() + 67, personagemAtual->getYReal() + 25, personagemAtual->getAtaque());
		projeTestes.push_back(projeTeste2);
		personagemAtual->setCastou(false);*/
	}
	if (!Mouse::isButtonPressed(Mouse::Button::Right))
	{
		if (personagemAtual->getEspecializando())
		{
			personagemAtual->desEspecial();
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::LShift) && !personagemAtual->getEspecializando())
	{
		correndo = true;
	}
	if (correndo)
	{
		personagemAtual->setCorrendo(true);
		correndo = false;
	}
	else
	{
		personagemAtual->setCorrendo(false);
	}

	if (!personagemAtual->getAtacando())
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::W) && podeCima)
		{
			personagemAtual->andaCima();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::S) && podeBaixo)
		{
			personagemAtual->andaBaixo();
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::A) && podeEsquerda)
		{
			personagemAtual->andaEsquerda();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::D) && podeDireita)
		{
			personagemAtual->andaDireita();
		}
	}
	/*if (Keyboard::isKeyPressed(Keyboard::Tab))
	{
		apertouTab = true;
	}
	else if (apertouTab)
	{
		apertouTab = false;
		if (personagemAtual->proximo->getMorto() && filaPerso.getUltimo()->getMorto())
		{

		}
		else if (personagemAtual->proximo->getMorto())
		{
			trocaTerceiro();
			cout << "troca segundo" << endl;
		}
		else if (filaPerso.getUltimo()->getMorto())
		{
			trocaSegundoDois();
			cout << "troca segundo dois " << endl;
		}
		else
		{
			trocaSegundo();
		}
	}*/
}

void Jogo::coliseia()
{
	personagemAtual = filaPerso.getPrimeiro();
	//COLISOES COM CIMA E BAIXO
	if (personagemAtual->getYbotas() <= 226)
	{
		podeCima = false;
	}
	else
	{
		podeCima = true;
	}
	if (personagemAtual->getYbotas() >= 494)
	{
		podeBaixo = false;
	}
	else
	{
		podeBaixo = true;
	}
	//COLISOES COM ESQUERDA E DIREITA
	if (personagemAtual->getXbotas() <= 0)
	{
		podeEsquerda = false;
	}
	else
	{
		podeEsquerda = true;
	}
	if (personagemAtual->getXbotas() >= 1208)
	{
		podeDireita = false;
	}
	else
	{
		podeDireita = true;
	}

	// ANTIGO TESTE DE COLISAO COM VECTOR COM PONTEIROS
	if (projeteis.size() > 0)
	{
		for (int u = 0; u < projeteis.size(); u++)
		{
			for (int i = 0; i < vetorInimigos.size(); i++)
			{
				if (Collision::PixelPerfectTest(projeteis[u]->getSpriteFrameAtual(), vetorInimigos[i]->getSpriteFrameAtual()))
				{
					vetorInimigos[i]->recebeDano(projeteis[u]->getDano());
					cout << "cobra " << i << " recebeu dano!" << endl;
					projeteis[u]->setDeleteMeTrue();
				}
			}
		}
	}

	//COISA MAIS BUGADA Q EXISTE
	/*if (projeTestes.size() > 0)
	{
		for (int u = 0; u < projeTestes.size(); u++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (Collision::PixelPerfectTest(projeTestes[u].getSpriteFrameAtual(), vetorInimigos[i]->getSpriteFrameAtual()))
				{
					vetorInimigos[i]->recebeDano(projeTestes[u].getDano());
					cout << "cobra " << i << " recebeu dano!" << endl;
					projeTestes[u].setDeleteMeTrue();
				}
				
			}
		}
	}*/
	if (personagemAtual->getAtacouTipo() == 1)
	{
		for (int i = 0; i < vetorInimigos.size(); i++)
		{
			if (Collision::PixelPerfectTest(personagemAtual->getSpriteFrameAtual(), vetorInimigos[i]->getSpriteFrameAtual()))
			{
				vetorInimigos[i]->recebeDano(personagemAtual->getAtaque());
				cout << "cobra " << i << " recebeu dano!" << endl;
				personagemAtual->setAtacouTipo(0);
				break;
			}
		}
	}
	if (personagemAtual->getXbotas() > 690)
	{		
		for (int i = 0; i < vetorInimigos.size(); i++)
		{
			if (vetorInimigos[i]->getAtacou())
			{
				if (Collision::PixelPerfectTest(vetorInimigos[i]->getSpriteFrameAtual(), personagemAtual->getSpriteFrameAtual()))
				{
					if (personagemAtual->getTipoPersonagem() == 1 && personagemAtual->getEspecializando())
					{

					}
					else
					{
						personagemAtual->recebeDano(vetorInimigos[i]->getAtaque());
						cout << "cobra " << i << " deu dano no player xD" << endl;
					}
				}
				vetorInimigos[i]->setAtacou(false);
			}
		}
		
	}

	if (personagemAtual->getXbotas() > 690)
	{
		for (int i = 0; i < vetorInimigos.size(); i++)
		{
			if (!vetorInimigos[i]->getMorto() && !personagemAtual->getAtacando())
			{
				if (Collision::PixelPerfectTest(vetorInimigos[i]->getSpriteFrameAtual(), personagemAtual->getSpriteFrameAtual()))
				{
					personagemAtual->recebeDano(vetorInimigos[i]->getAtaque());
				}
			}
		}

	}

	for (int i = 0; i < vetorInimigos.size(); i++)
	{
		if (vetorInimigos[i]->getAcidou())
		{
			Projetil* projetilAux;
			projetilAux = new Projetil;
			projetilAux->inicializarInimigo(vetorInimigos[i]->getX(), vetorInimigos[i]->getY(), vetorInimigos[i]->getAtaque());
			projeteisIni.push_back(projetilAux);
			vetorInimigos[i]->setAcidou(false);
		}
	}

	if (projeteisIni.size() > 0)
	{
		for (int u = 0; u < projeteisIni.size(); u++)
		{
			if (Collision::PixelPerfectTest(projeteisIni[u]->getSpriteFrameAtual(), personagemAtual->getSpriteFrameAtual()))
			{
				if (personagemAtual->getTipoPersonagem() == 1 && personagemAtual->getEspecializando())
				{

				}
				else
				{
					personagemAtual->recebeDano(projeteisIni[u]->getDano());
					cout << "cobra " << u << " recebeu dano!" << endl;
					projeteisIni[u]->setDeleteMeTrue();
				}
			}
		}
	}
	/*if (personagemAtual->getXbotas() > 690)
	{
		for (int i = 0; i < 3; i++)
		{
			if (!vetorInimigos[i]->getMorto())
			{
				if ((personagemAtual->getXmeio() + 25) >= (vetorInimigos[i]->getXcolisao() - 63))
				{
					if ((personagemAtual->getYmeio()) <= (vetorInimigos[i]->getYcolisao() + 56) && (personagemAtual->getYmeio()) >= (vetorInimigos[i]->getYcolisao() - 56))
					{
						podeDireita = false;
						break;
					}
				}
				else
				{
					podeDireita = true;
				}
			}
		}
	}*/

	//if (relogioAtaque.checaConta() && playerAtacando)
	//{
	//	for (int i = 0; i < 3; i++)
	//	{
	//		if (vetorInimigos[i]->getXcolisao() - personagemAtual->getXatacando() <= (vetorInimigos[i]->desenhar().getAnimation()->getFrame(0).width / 2))
	//		{
	//			int difModulo;
	//			difModulo = vetorInimigos[i]->getYcolisao() - personagemAtual->getYmeio();
	//			if (difModulo < 0)
	//			{
	//				difModulo *= -1;
	//			}
	//			if (difModulo <= ((vetorInimigos[i]->getYcolisao() + personagemAtual->getYmeio()) / 2))
	//			{
	//				vetorInimigos[i]->recebeDano(personagemAtual->getAtaque());
	//				cout << "cobra " << i << " recebeu dano!" << endl;
	//			}
	//		}
	//		/*if (personagemAtual->getXatacando() > (vetorInimigos[i]->getXcolisao() - 60) && personagemAtual->getXatacando() < (vetorInimigos[i]->getXcolisao() + 60))
	//		{
	//			if (personagemAtual->getYatacando() > (vetorInimigos[i]->getYcolisao() - 55) && personagemAtual->getYatacando() < (vetorInimigos[i]->getYcolisao() + 55))
	//			{
	//				vetorInimigos[i]->recebeDano(personagemAtual->getAtaque());
	//				cout << "cobra " << i << " recebeu dano!" << endl;
	//			}
	//		}*/
	//	}
	//	playerAtacando = false;
	//}
	//for (int i = 0; i < 3; i++)
	//{
	//	if (vetorInimigos[i]->getAtacou())
	//	{
	//		//if (personagemAtual->getYatacando() > (vetorInimigos[i]->getYcolisao() - 55) && personagemAtual->getYatacando() < (vetorInimigos[i]->getYcolisao() + 55))
	//		if (vetorInimigos[i]->getYcolisao() - personagemAtual->getYmeio() <= 96 || personagemAtual->getYmeio() - vetorInimigos[i]->getYcolisao() <= 96)
	//		{
	//			cout << "em y eles tao parelho" << endl;
	//			if (vetorInimigos[i]->getXcolisao() - personagemAtual->getXmeio() <= 96 || personagemAtual->getXmeio() - vetorInimigos[i]->getXcolisao() <= 96)
	//			{
	//				personagemAtual->recebeDano(vetorInimigos[i]->getAtaque());
	//				cout << "cobra " << i << " deu dano no player xD" << endl;
	//			}
	//		}
	//		vetorInimigos[i]->setAtacou(false);
	//	}
	//}
}

void Jogo::executar()
{
	Time frameTime = frameClock.restart();
	
	Event evento;
	personagemAtual = filaPerso.getPrimeiro();
	while (janela.pollEvent(evento))
	{
		// Close window: exit
		maoManager(evento);
	}
	personagemAtual = filaPerso.getPrimeiro();
	coliseia();
	checaCliques();
	
	
	
	

	/*if (reloginho.taRolando())
	{
		if (reloginho.checaConta())
		{
			cout << "rolou a contagem" << endl;
		}
	}*/

	janela.clear();

	janela.draw(sprBatalha);
	
	personagemAtual->atualizar();
	personagemAtual->proximo->atualizar();
	filaPerso.getUltimo()->atualizar();
	
	janela.draw(filaPerso.getUltimo()->desenhar());
	janela.draw(personagemAtual->proximo->desenhar());
	janela.draw(personagemAtual->desenhar());

	//janela.draw(personagemAtual->getSpriteFrameAtual()); //AJOELHEM-SE PERANTE ZOD
	
	for (int i = 0; i < projeteis.size(); i++)
	{
		projeteis[i]->atualizar();
		if (!projeteis[i]->getDeleteMe())
		{
			janela.draw(projeteis[i]->desenhar());
		}
		else
		{
			projeteis.erase(projeteis.begin() + i);
		}
	}
	/*for (int i = 0; i < projeTestes.size(); i++)
	{
		projeTestes[i].atualizar();
		if (!projeTestes[i].getDeleteMe())
		{
			janela.draw(projeTestes[i].desenhar());
		}
		else
		{
			projeTestes.erase(projeTestes.begin() + i);
		}
	}*/

	for (int i = 0; i < projeteisIni.size(); i++)
	{
		projeteisIni[i]->atualizarIni();
		if (!projeteisIni[i]->getDeleteMe())
		{
			janela.draw(projeteisIni[i]->desenhar());
		}
		else
		{
			projeteisIni.erase(projeteisIni.begin() + i);
		}
	}
	
	moveAFK();
	
	
	for (int i = 0; i < vetorInimigos.size(); i++)
	{
		vetorInimigos[i]->atualizar();
		if (!vetorInimigos[i]->getMorto())
		{
			janela.draw(vetorInimigos[i]->desenhar());
		}
		else
		{
			vetorInimigos.erase(vetorInimigos.begin() + i);
			break;
		}
	}

	janela.draw(sprUIbatalha);

	fazUI();

	janela.display();
	
	
}

void Jogo::moveAFK()
{
	if (!personagemAtual->proximo->getMorto())
	{
		personagemAtual->proximo->movePara(personagemAtual->getXReal(), personagemAtual->getYReal());
		
	}
	if (!filaPerso.getUltimo()->getMorto())
	{
		filaPerso.getUltimo()->movePara(personagemAtual->proximo->getXReal(), personagemAtual->proximo->getYReal());
	}
	
	/*if (relogioDelayCaminhada.checaConta())
	{
		delayPassou = true;
	}
	if (delayPassou)
	{
		if (filaPerso.getUltimo()->movePara(personagemAtual->proximo->getXReal(), personagemAtual->proximo->getYReal()) == 0)
		{
			delayPassou = false;
		}
	}*/
}

void Jogo::trocaSegundo()
{
	Personagem *auxiliar;
	auxiliar = personagemAtual;
	filaPerso.removeInicio();
	auxiliar->proximo = NULL;
	auxiliar->anterior = NULL;
	//filaPerso.insereDepois(personagemAtual, auxiliar);
	filaPerso.insereFim(auxiliar);
}
void Jogo::trocaSegundoDois()
{
	Personagem *auxiliar;
	auxiliar = personagemAtual;
	filaPerso.removeInicio();
	auxiliar->proximo = NULL;
	auxiliar->anterior = NULL;
	filaPerso.insereDepois(filaPerso.getPrimeiro(), auxiliar);
	//laPerso.insereFim(auxiliar);
}

void Jogo::trocaTerceiro()
{
	/*Personagem *auxiliar;
	auxiliar = personagemAtual;
	filaPerso.removeInicio();
	auxiliar->proximo = NULL;
	auxiliar->anterior = NULL;
	filaPerso.insereFim(auxiliar);
	auxiliar = personagemAtual;
	filaPerso.removeInicio();
	auxiliar->proximo = NULL;
	auxiliar->anterior = NULL;
	filaPerso.insereDepois(personagemAtual, auxiliar);*/
	trocaSegundo();
	trocaSegundo();
}

void Jogo::interpretaMagia()
{
	Magia magiaAuxiliar = personagemAtual->getMagia();
	switch (magiaAuxiliar.tipoMagia)
	{
	case 0:

		break;
	case 1:

		break;
	case 2:

		break;
	}
}

void Jogo::fazUI()
{
	nome1.setString(personagemAtual->getNome());
	nome2.setString(personagemAtual->proximo->getNome());
	nome3.setString(personagemAtual->proximo->proximo->getNome());
	
	vida1.setString(to_string(personagemAtual->getVida()) + "/" + to_string(personagemAtual->getVidaMax()));
	vida2.setString(to_string(personagemAtual->proximo->getVida()) + "/" + to_string(personagemAtual->proximo->getVidaMax()));
	vida3.setString(to_string(personagemAtual->proximo->proximo->getVida()) + "/" + to_string(personagemAtual->proximo->proximo->getVidaMax()));

	mana1.setString(to_string(personagemAtual->getMana()) + "/" + to_string(personagemAtual->getManaMax()));
	mana2.setString(to_string(personagemAtual->proximo->getMana()) + "/" + to_string(personagemAtual->proximo->getManaMax()));
	mana3.setString(to_string(personagemAtual->proximo->proximo->getMana()) + "/" + to_string(personagemAtual->proximo->proximo->getManaMax()));

	level1.setString(to_string(personagemAtual->getLevel()));
	level2.setString(to_string(personagemAtual->proximo->getLevel()));
	level3.setString(to_string(personagemAtual->proximo->proximo->getLevel()));

	janela.draw(nome1);
	janela.draw(vida1);
	janela.draw(mana1);
	janela.draw(level1);

	janela.draw(nome2);
	janela.draw(vida2);
	janela.draw(mana2);
	janela.draw(level2);

	janela.draw(nome3);
	janela.draw(vida3);
	janela.draw(mana3);
	janela.draw(level3);
	
}