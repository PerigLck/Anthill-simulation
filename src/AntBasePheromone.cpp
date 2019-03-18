/*
 * AntBasePheromone.cpp
 *
 *  Created on: 15 mars 2019
 *      Author: 17008053
 */

#include <AntBasePheromone.h>
#include <Pheromone.h>
#include "Pheromone.h"
AntBasePheromone::AntBasePheromone(Environment * evt,Vector2<float> centre,Anthill * f, Vector2<float> valdirection) :
AntBase(evt,centre,f,valdirection)

{
}

void AntBasePheromone::putPheromone(float q){
	std::vector<Pheromone*> pheromones=LocalizedEntity::perceive<Pheromone>();
	if(!pheromones.empty()){
		pheromones.back()->addQuantity(q);
	}
	else{
		new Pheromone(getEvt(),getPosition(),q);
	}
}

Pheromone* AntBasePheromone::choosePheromone() {
	std::vector<Pheromone*> pheromones=LocalizedEntity::perceive<Pheromone>(getDirection().normalized(),MathUtils::piDiv2,8);
	std::vector<float> qtes;
	if (pheromones.empty()) return nullptr;
	else {
	for (Pheromone * p:pheromones) {
		qtes.push_back(p->getQuantity());
	}
	int indice=MathUtils::randomChoose(qtes);
	return pheromones[indice];
	}

}

AntBasePheromone::~AntBasePheromone() {
	// TODO Auto-generated destructor stub
}

