//
// Created by Base on 2018-03-20.
//

#include "stdafx.h"
#include "funkcijosBeStrukturos.h"

int randomPazymys() {
	int pazymys{};
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 10);
	pazymys = dis(gen);
	return pazymys;
}