/*
 * Anthill.cpp
 *
 *  Created on: 7 mars 2019
 *      Author: 17008053
 */

#include "Anthill.h"
#include "Renderer.h"
Anthill::Anthill(Environment * evt,Vector2<float> centre):
Agent(evt,centre,10),
qteNourriture(0)
{
}

void Anthill::update() {
	Renderer::getInstance()->drawCircle(getCentre(),getRayon(),Renderer::Color(0,0,255,255));
}

void Anthill::depositFood(float quantite) {
	qteNourriture=qteNourriture+quantite;
}

Anthill::~Anthill() {
}

