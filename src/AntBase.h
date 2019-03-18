/*
 * AntBase.h
 *
 *  Created on: 7 mars 2019
 *      Author: 17008053
 */

#ifndef ANTBASE_H_
#define ANTBASE_H_
#include "Vector2.h"
#include "Anthill.h"
#include "food.h"
#include "Timer.h"

class AntBase : public Agent {
private :
	int dureeVie;
	float transport;
	Anthill * fourmiliere;
	float vitesse;
	Vector2<float> direction;
public:
	AntBase(Environment * evt,Vector2<float> centre,Anthill * f, Vector2<float> valdirection);
	virtual ~AntBase();
	void avancer();
	void tourner(float radian);
	void demitour();
	void orienter(const Agent & obj);
	void deposer();
	std::vector<food*> percevoir();
	Vector2<float> getDirection();
	void recolter(food f);
	virtual void update();
	float getTransport();
	Anthill * getFourmiliere();
	void SetTransport(float qte);
};

#endif /* ANTBASE_H_ */
