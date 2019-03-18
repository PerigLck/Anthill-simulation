/*
 * AntBase.cpp
 *
 *  Created on: 7 mars 2019
 *      Author: 17008053
 */

#include "AntBase.h"
#include "MathUtils.h"
#include "food.h"
#include "Renderer.h"
AntBase::AntBase(Environment * evt,Vector2<float> centre,Anthill * f, Vector2<float> valdirection) :
Agent(evt,centre,1),
dureeVie(MathUtils::random(1000000,20000000)),
transport(0),
fourmiliere(f),
vitesse(1),
direction(Vector2<float>::random())
{
}

AntBase::~AntBase() {

}

void AntBase::avancer() {
	//setCentre(getCentre()+direction*vitesse*Timer::dt());
	setPosition(getPosition()+direction.normalized()*vitesse*Timer::dt());
}



void AntBase::tourner(float radian) {
	direction=direction.rotate(radian).normalized();
}

void AntBase::demitour() {
	tourner(MathUtils::pi);
}

void AntBase::orienter(const Agent & obj) {
	direction=getPosition().direction(obj.getPosition()).normalized();
			//direction*position.normalized();
}
void AntBase::deposer() {
	transport=0;
}

std::vector<food*> AntBase::percevoir(){
	return perceive<food>(direction.normalized(), MathUtils::piDiv2, 3);
}

Vector2<float> AntBase::getDirection() {
	return direction;
}

void AntBase::recolter(food f) {
	transport=f.collectFood(5);
}

void AntBase::update() {
	dureeVie-=Timer::dt();
	if (dureeVie<=0) {
		setStatus(destroy);
	}

	if (transport == 0){
		Renderer::getInstance()->drawPixel(getPosition(),Renderer::Color(255,255,255,255));

	}
	else {
 		Renderer::getInstance()->drawPixel(getPosition(),Renderer::Color(255,0,0,255));

	}
	avancer();

}
void AntBase::SetTransport(float qte) {
	transport=qte;
}

float AntBase::getTransport(){
	return transport;
}
Anthill * AntBase::getFourmiliere(){
	return fourmiliere;
}
