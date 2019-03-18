/*
 * Ant.h
 *
 *  Created on: 16 mars 2019
 *      Author: 17008053
 */

#ifndef SRC_ANT_H_
#define SRC_ANT_H_
#include "AntBasePheromone.h"
class Ant :public AntBasePheromone {
public:
	Ant(Environment * evt,Vector2<float> centre,Anthill * f, Vector2<float> valdirection);
	virtual ~Ant();
	virtual void update();
};

#endif /* SRC_ANT_H_ */
