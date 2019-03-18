/*
 * Anthill.h
 *
 *  Created on: 7 mars 2019
 *      Author: 17008053
 */

#ifndef ANTHILL_H_
#define ANTHILL_H_
#include "Agent.h"

class Anthill : public Agent {
private:
	float qteNourriture;
public:
	Anthill(Environment * evt,Vector2<float> centre);
	virtual ~Anthill();
	virtual void update();
	void depositFood(float quantite);
};

#endif /* ANTHILL_H_ */
