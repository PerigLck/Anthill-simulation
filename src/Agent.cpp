/*
 * Agent.cpp
 *
 *  Created on: 6 mars 2019
 *      Author: 17008053
 */
#include "Vector2.h"
#include "Environment.h"
#include <Agent.h>

	std::set<Agent*> Agent::agents;

	Agent::Agent(Environment * val,Vector2<float> c,float r)
		:
				Environment::LocalizedEntity(val,c,r),
				environnement(val),
				centre(c),
				rayon(r),
				state(running)
		{Agent::agents.insert(this);}

	Agent::~Agent() {

	}

	Agent::Status Agent::getStatus() const{
		return state;
	}

	void Agent::setStatus(Status s){
		state=s;
	}

	float Agent::getRayon() {
		return rayon;
	}

	Vector2<float> Agent::getCentre() {
		return centre;
	}

	Environment * Agent::getEvt() {
		return environnement;
	}


	void Agent::simulate() {
		for (Agent* a: agents) {
			if (a->getStatus()==running) {
				a->update();
			}
			else {
				delete a;
				agents.erase(a);
			}
		}
	}

	void Agent::setCentre(Vector2<float> valcentre) {
		setPosition(valcentre);
	}


	void Agent::finalize() {
		for (Agent* a: agents) {
			delete a;
		}}
