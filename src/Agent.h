/*
 * Agent.h
 *
 *  Created on: 6 mars 2019
 *      Author: 17008053
 */

#ifndef SRC_AGENT_H_
#define SRC_AGENT_H_
#include "Vector2.h"
#include "Environment.h"

class Agent : public Environment::LocalizedEntity {
protected :
    typedef enum {running,destroy} Status;
private :
	static std::set<Agent*> agents;
	Environment * environnement;
	Vector2<float> centre;
	float rayon;
    Status state;
public:
	Agent(Environment * val,Vector2<float> c,float r=Environment::LocalizedEntity::defaultRadius());
	virtual ~Agent();
	virtual void update() =0;
	Status getStatus() const;
	void setStatus(Status s);
	float getRayon();
	Vector2<float> getCentre();
	Environment * getEvt();
	void setCentre(Vector2<float> valcentre);
	static void finalize();
	static void simulate();
};

#endif /* SRC_AGENT_H_ */
