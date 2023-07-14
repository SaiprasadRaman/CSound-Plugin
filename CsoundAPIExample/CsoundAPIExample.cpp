#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include "csound.hpp"
#include <string>
#include <time.h>

void user(void);
void calculation(void);
void play(void);

using namespace std;
int i, j, a;
float vol, start = 0;

	string sco = "";
	string orc = "sr=44100\n\
	ksmps=32\n\
	nchnls=2\n\
	0dbfs=1\n\
	\n\
	instr 1\n\
	aout oscili p4, cpspch(p5)\n\
	outs aout, aout\n\
	endin";

	int main()

	{
		csoundSetGlobalEnv("OPCODE6DIR64", "C:\\Program Files\\Csound6_x64\\plugins64");
		user();
		calculation();
		play();

	}
void user(void)
{

	cout << "Where would you like to have the accent? enter a between 1-8 \n  ";
	cin >> a;
}

void calculation(void)
{
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == a) { vol = 1; }
			else { vol = .2; }
			sco.append("i1 " + to_string(start) + " " + to_string(.2) + " " + to_string(vol) + " " + to_string(8.00) + "\n");
			start = start + .2;
		}
	}


	cout << sco.c_str();
}

void play(void)
{
	//create an instance of Csound  sdfr
	Csound* csound = new Csound();

	//set CsOptions
	csound->SetOption("-odac");

	//compile orc
	csound->CompileOrc(orc.c_str());

	//compile sco
	csound->ReadScore(sco.c_str());

	//prepare Csound for performance
	csound->Start();

	//perform entire score
	csound->Perform();

	//free Csound object
	delete csound;

	
}




















