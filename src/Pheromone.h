/*
 * Pheromone.h
 *
 *  Created on: 15 mars 2019
 *      Author: 17008053
 */

#ifndef SRC_PHEROMONE_H_
#define SRC_PHEROMONE_H_
#include <Agent.h>

class Pheromone: public Agent {
private :
	float quantite_depose;

public:
	Pheromone(Environment * evt,Vector2<float> centre,float q);
	float getQuantity();
	void addQuantity(float quantite);
	virtual ~Pheromone();
	virtual void update();
};

#endif /* SRC_PHEROMONE_H_ */
