/*
 * AntBasePheromone.h
 *
 *  Created on: 15 mars 2019
 *      Author: 17008053
 */

#ifndef SRC_ANTBASEPHEROMONE_H_
#define SRC_ANTBASEPHEROMONE_H
#include <AntBase.h>
#include <Pheromone.h>

class AntBasePheromone : public AntBase{

public:
	AntBasePheromone(Environment * evt,Vector2<float> centre,Anthill * f, Vector2<float> valdirection);
	virtual ~AntBasePheromone();
	void putPheromone(float q);
	Pheromone* choosePheromone();
};

#endif /* SRC_ANTBASEPHEROMONE_H_ */
