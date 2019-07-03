#include "Cacador.h"



Cacador::Cacador()
{
}


Cacador::~Cacador()
{
}

void Cacador::inicializar(int x_, int y_)
{
	tipoPersonagem = 3;
	/*if (!txtChar.loadFromFile("bin/cacador.png"))
	{
		cout << "Nao rolou cacador." << endl;
		system("pause"); return;
	}*/
	Collision::CreateTextureAndBitmask(txtChar, "bin/cacador.png");

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

	//animEspecial2

	//animEspecial3

	x = x_;
	y = y_;
	spChar.setPosition(x, y);
	spChar.setFrameTime(seconds(0.2));
	spChar.setLooped(true);

	animaAtual = &animParado;
	nAnimacaoAtual = 0;
	atacando = false;
	podeAndar = true;

	deveRecuar = false;
	cooldownCacador = false;
	speedRecuo = 0.7;
	//speedRecuo = 0.1;
	//speedAtual = 0.05;
	speedAtual = 0.4;
	level = 1;
	vida = 55;
	vidaMaxima = 55;
	mana = 0;
	manaMaxima = 0;
	nome = "Cacador";
	ataque = 10;
	defesa = 5;
	morrer = false;
	especializando = false;
	andando = false;
	morto = false;
}

void Cacador::atualizar()
{
	Time frameTime = frameClock.restart();
	//cout << "especializando " << especializando << endl;
	//cout << "deve recuar " << deveRecuar << endl;
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
		if (cooldownCacador && tempoCooldownCacador.checaConta())
		{
			cout << "entrou no cooldowncacador!" << endl;
			cooldownCacador = false;
			tempoCooldownCacador.reset();
		}
		if (nAnimacaoAtual == TomaDano)
		{
			empurraEsquerda();
		}
		if (tempoAtaque.checaConta())
		{
			atacouTipo = 2;
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

void Cacador::andaEsquerda()
{
	if (podeAndar)
	{
		if (!cooldownCacador)
		{
			if (deveRecuar)
			{
				recuar();
				x -= speedAtual;
				andando = true;
			}
			else
			{
				if (nAnimacaoAtual != Andando)
				{
					nAnimacaoAtual = Andando;
					animaAtual = &animAndando;
				}
				x -= speedAtual;
				andando = true;
			}
		}
		else
		{
			if (nAnimacaoAtual != Andando)
			{
				nAnimacaoAtual = Andando;
				animaAtual = &animAndando;
			}
			x -= speedAtual;
			andando = true;
		}
	}
}

void Cacador::andaCima()
{
	if (podeAndar)
	{
		if (especializando)
		{
			y -= speedAtual;
			andando = true;
		}
		else
		{
			if (nAnimacaoAtual != Andando)
			{
				nAnimacaoAtual = Andando;
				animaAtual = &animAndando;
			}
			y -= speedAtual;
			andando = true;
		}
	}
}

void Cacador::andaBaixo()
{
	if (podeAndar)
	{
		if (especializando)
		{
			y += speedAtual;
			andando = true;

		}
		else
		{
			if (nAnimacaoAtual != Andando)
			{
				nAnimacaoAtual = Andando;
				animaAtual = &animAndando;
			}
			y += speedAtual;
			andando = true;
		}
	}
}

bool Cacador::getCooldownCacador()
{
	return cooldownCacador;
}

void Cacador::recuar()
{
	if (nAnimacaoAtual != Especial)
	{
		nAnimacaoAtual = Especial;
		especializando = true;
		animaAtual = &animEspecial;
		double segs = 0.15;
		spChar.setFrameTime(seconds(segs));
		spChar.setLooped(false);
	}
	x -= speedRecuo;
}

void Cacador::especial()
{
	if (!especializando && !cooldownCacador)
	{
		atacando = false;
		deveRecuar = true;
	}
}

void Cacador::desEspecial()
{
	especializando = false;
	podeAndar = true;
	cooldownCacador = true;
	deveRecuar = false;
	setAnima(Parado);
	tempoCooldownCacador.contaAte(3.0);
}