/*
 * Ant.cpp
 *
 *  Created on: 16 mars 2019
 *      Author: 17008053
 */

#include <Ant.h>

Ant::Ant(Environment * evt,Vector2<float> centre,Anthill * f, Vector2<float> valdirection):
AntBasePheromone(evt,centre,f,valdirection)
{

}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

void Ant::update() {
	std::vector<food *> nourriture_percue=percevoir();
	Pheromone* pheromone=AntBasePheromone::choosePheromone();
	if (getTransport()==0) {
		if (!nourriture_percue.empty()) {
			recolter(*nourriture_percue.back());
		}
		else {
			if (pheromone!=nullptr) {
				orienter(*pheromone);
			}
			else {
				float ori=MathUtils::random(-1*MathUtils::pi*0.1*Timer::dt(),MathUtils::pi*0.1*Timer::dt());
				tourner(ori);
			}
		}
		putPheromone(10);

	}

	if (getTransport()!=0) {
//		orienter(*getFourmiliere());
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
			demitour();
		}

		else {
			orienter(*getFourmiliere());
			if (pheromone!=nullptr) {
			orienter(*pheromone);}
			else orienter(*getFourmiliere());
		}
		putPheromone(100);

	}

	AntBase::update();

}
