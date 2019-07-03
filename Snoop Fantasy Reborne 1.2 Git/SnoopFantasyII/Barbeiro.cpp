#include "Barbeiro.h"



Barbeiro::Barbeiro()
{
}


Barbeiro::~Barbeiro()
{
}

void Barbeiro::inicializar(int x_, int y_)
{
	tipoPersonagem = 2;
	/*if (!txtChar.loadFromFile("bin/barbeiro.png"))
	{
		cout << "Nao rolou barbeiro." << endl;
		system("pause"); return;
	}*/
	Collision::CreateTextureAndBitmask(txtChar, "bin/barbeiro.png");

	animParado.setSpriteSheet(txtChar);
	animAndando.setSpriteSheet(txtChar);
	animAtacando.setSpriteSheet(txtChar);
	animTomaDano.setSpriteSheet(txtChar);
	animMorrer.setSpriteSheet(txtChar);
	animMorto.setSpriteSheet(txtChar);
	animEspecial.setSpriteSheet(txtChar);
	animEspecial2.setSpriteSheet(txtChar);
	animEspecial3.setSpriteSheet(txtChar);

	//animParado
	animParado.addFrame(IntRect(0, 0, 96, 96));
	animParado.addFrame(IntRect(96, 0, 96, 96));
	animParado.addFrame(IntRect(192, 0, 96, 96));
	animParado.addFrame(IntRect(288, 0, 96, 96));

	//animAndando
	animAndando.addFrame(IntRect(0, 96, 96, 96));
	animAndando.addFrame(IntRect(96, 96, 96, 96));
	animAndando.addFrame(IntRect(192, 96, 96, 96));
	animAndando.addFrame(IntRect(288, 96, 96, 96));

	//animAtacando
	animAtacando.addFrame(IntRect(0, 192, 96, 96));
	animAtacando.addFrame(IntRect(96, 192, 96, 96));
	animAtacando.addFrame(IntRect(192, 192, 96, 96));
	animAtacando.addFrame(IntRect(288, 192, 96, 96));
	animAtacando.addFrame(IntRect(384, 192, 96, 96));
	animAtacando.addFrame(IntRect(480, 192, 96, 96));

	//animTomaDano
	animTomaDano.addFrame(IntRect(0, 288, 96, 96));
	animTomaDano.addFrame(IntRect(96, 288, 96, 96));
	animTomaDano.addFrame(IntRect(192, 288, 96, 96));
	animTomaDano.addFrame(IntRect(288, 288, 96, 96));
	animTomaDano.addFrame(IntRect(384, 288, 96, 96));
	animTomaDano.addFrame(IntRect(480, 288, 96, 96));

	//animMorrer
	animMorrer.addFrame(IntRect(0, 384, 96, 96));
	animMorrer.addFrame(IntRect(96, 384, 96, 96));
	animMorrer.addFrame(IntRect(192, 384, 96, 96));
	animMorrer.addFrame(IntRect(288, 384, 96, 96));
	animMorrer.addFrame(IntRect(384, 384, 96, 96));
	animMorrer.addFrame(IntRect(480, 384, 96, 96));
	animMorrer.addFrame(IntRect(576, 384, 96, 96));
	animMorrer.addFrame(IntRect(672, 384, 96, 96));

	//animMorto
	animMorto.addFrame(IntRect(672, 384, 96, 96));

	//animEspecial
	animEspecial.addFrame(IntRect(0, 480, 96, 96));
	animEspecial.addFrame(IntRect(96, 480, 96, 96));
	animEspecial.addFrame(IntRect(192, 480, 96, 96));
	animEspecial.addFrame(IntRect(288, 480, 96, 96));
	animEspecial.addFrame(IntRect(384, 480, 96, 96));
	animEspecial.addFrame(IntRect(480, 480, 96, 96));

	//animEspecial2

	//animEspecial3

	//Seta Magia
	magiazinha.magiaInimigo = false;
	magiazinha.nomeMagia = "Fireball";
	magiazinha.efeitoSecundario = false;
	magiazinha.speedMagia = 0.5;
	magiazinha.tipoMagia = 0;
	magiazinha.alvoMagia = 0;

	x = x_;
	y = y_;
	spChar.setPosition(x, y);
	spChar.setFrameTime(seconds(0.2));
	spChar.setLooped(true);

	animaAtual = &animParado;
	nAnimacaoAtual = 0;
	atacando = false;
	podeAndar = true;

	//speedAtual = 0.05;
	speedAtual = 0.4;
	vida = 43;
	vidaMaxima = 43;
	mana = 30;
	manaMaxima = 30;
	nome = "Barbeiro";
	ataque = 5;
	defesa = 3;
	level = 1;
	morrer = false;
	especializando = false;
	andando = false;
	morto = false;
	tempoRegenMana.contaAte(8);
}

void Barbeiro::atualizar()
{
	Time frameTime = frameClock.restart();

	if (!morto && !morrer)
	{
		if (especializando && !spChar.isPlaying())
		{
			desEspecial();
		}

		if (atacando)
		{
			if (!spChar.isPlaying())
			{
				if (nAnimacaoAtual != Parado)
				{
					cout << "realmente entrou aqui" << endl;
					setAnima(Parado);
				}
				atacando = false;
				podeAndar = true;
			}
		}
		else if (!especializando && nAnimacaoAtual != TomaDano)
		{
			if (!andando && nAnimacaoAtual != Parado)
			{
				setAnima(Parado);
			}
		}
		if (!spChar.isPlaying() && nAnimacaoAtual == TomaDano)
		{
			podeAndar = true;
			setAnima(Parado);
		}
		if (nAnimacaoAtual == TomaDano)
		{
			empurraEsquerda();
		}
		if (tempoAtaque.checaConta())
		{
			atacouTipo = 1;
		}
		if (mana < manaMaxima)
		{
			if (tempoRegenMana.checaConta())
			{
				mana += 1;
				tempoRegenMana.contaAte(8);
			}
		}
	}
	if (morrer && !morto)
	{
		nAnimacaoAtual = Morrer;
		animaAtual = &animMorrer;
		spChar.setLooped(false);
		morto = true;
	}
	if (morrer && morto)
	{
		if (nAnimacaoAtual == Morrer)
		{
			if (!spChar.isPlaying())
			{
				nAnimacaoAtual = Morto;
				animaAtual = &animMorto;
			}
		}
	}

	spChar.setPosition(x, y);

	spChar.play(*animaAtual);

	spChar.update(frameTime);
}

void Barbeiro::castar()
{
	if (nAnimacaoAtual != Especial)
	{
		nAnimacaoAtual = Especial;
		especializando = true;
		animaAtual = &animEspecial;
		double segs = 0.15;
		spChar.setFrameTime(seconds(segs));
		spChar.setLooped(false);
		podeAndar = false;
	}
}

void Barbeiro::especial()
{
	if (!especializando)
	{
		atacando = false;
		castar();
	}
}