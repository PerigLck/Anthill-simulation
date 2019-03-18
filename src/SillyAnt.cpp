/*
 * SillyAnt.cpp
 *
 *  Created on: 11 mars 2019
 *      Author: 17008053
 */

#include <SillyAnt.h>
#include "AntBase.h"
#include <iostream>
SillyAnt::SillyAnt(Environment * evt,Vector2<float> centre,Anthill * f):
AntBase(evt,centre,f,Vector2<float>::random().normalized())
{
}

SillyAnt::~SillyAnt() {

}

void SillyAnt::update() {
	std::vector<food *> nourriture_percue=percevoir();
	if (getTransport()==0) {
		if (!nourriture_percue.empty()) {
			recolter(*nourriture_percue.back());
		}

		else {
			float ori=MathUtils::random(-1*MathUtils::pi*0.1*Timer::dt(),MathUtils::pi*0.1*Timer::dt());
			tourner(ori);}
		}

	if (getTransport()!=0) {
		orienter(*getFourmiliere());
		std::vector<Anthill*> fourmiliere=perceive<Anthill>(getDirection().normalized(),MathUtils::pi,3);
		bool b=false;
		for (Anthill* f:fourmiliere) {
			if (f==getFourmiliere()) {
				b=true;
			}
		}
		if (b) {

			//std::cout << "coucou" << std::endl;
			getFourmiliere()->depositFood(getTransport());
			deposer();

		}
	}
	AntBase::update();

	}




