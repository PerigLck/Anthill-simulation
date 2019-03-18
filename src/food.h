/*
 * food.h
 *
 *  Created on: 6 mars 2019
 *      Author: 17008053
 */

#ifndef SRC_FOOD_H_
#define SRC_FOOD_H_
#include "Agent.h"
class food : public Agent{
private:
	float quantite;
	float oldQuantity;
public:
	food(Environment * env, Vector2<float> position,float qte);
	virtual ~food();
	float getFoodQuantity() const;
	float collectFood(float quantity);
	virtual void update();
	void supprimer();
};

#endif /* SRC_FOOD_H_ */
