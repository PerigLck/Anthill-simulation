/*
 * Pheromone.cpp
 *
 *  Created on: 15 mars 2019
 *      Author: 17008053
 */

#include <Pheromone.h>
#include <Timer.h>
#include <Renderer.h>

Pheromone::Pheromone(Environment * evt,Vector2<float> centre,float q):
Agent(evt,centre,1),
quantite_depose(q) {

}

Pheromone::~Pheromone() {
	// TODO Auto-generated destructor stub
}

float Pheromone::getQuantity() {
	return quantite_depose;
}
void Pheromone::addQuantity(float quantite) {
	quantite_depose+=quantite;
}

void Pheromone::update() {

	quantite_depose=quantite_depose-0.01*quantite_depose*Timer::dt();
	Renderer::getInstance()->drawPixel(getPosition(),Renderer::Color(0,128,128,std::min(int(quantite_depose), 255)));

	if(quantite_depose<=0.01){
		setStatus(destroy);
	}
}
