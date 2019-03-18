/*
 * SillyAnt.h
 *
 *  Created on: 11 mars 2019
 *      Author: 17008053
 */

#ifndef SRC_SILLYANT_H_
#define SRC_SILLYANT_H_
#include "AntBase.h"
class SillyAnt : public AntBase{
public:
	SillyAnt(Environment * evt,Vector2<float> centre,Anthill * f);
	virtual ~SillyAnt();
	virtual void update();
};

#endif /* SRC_SILLYANT_H_ */
