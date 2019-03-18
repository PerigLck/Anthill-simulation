/*
 * food.cpp
 *
 *  Created on: 6 mars 2019
 *      Author: 17008053
 */

#include <food.h>
#include "Vector2.h"
#include "Agent.h"
#include "Renderer.h"

food::food(Environment * env, Vector2<float> position,float qte):
Agent(env,position,MathUtils::circleRadius(qte)),
quantite(qte),
oldQuantity(qte)
{
}

float food::getFoodQuantity() const {
	return quantite;
}

float food::collectFood(float quantity) {
	if (getFoodQuantity()>=quantity) {
		quantite-=quantity;
		return quantity;
	}
	else {
		float oldQuantity=quantite;
		quantite=0;
		return oldQuantity;
	}
}

 void food::update() {
	if (getFoodQuantity()!=oldQuantity) {
		this->setRadius(quantite);
		oldQuantity=quantite;
	}
	Renderer::getInstance()->drawCircle(this->getCentre(),MathUtils::circleRadius(quantite),Renderer::Color(154,235,38,255));
	if (quantite<=0) {setStatus(destroy);}
}

 void food::supprimer() {
	 setStatus(destroy);
 }

food::~food() {
}

