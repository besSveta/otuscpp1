/*
 * main.cpp
 *
 *  Created on: 8 апр. 2019 г.
 *      Author: sveta
 */

#include <iostream>
#include "buildNumber.h"

using namespace std;

int buildNumber(){
	return PROJECT_VERSION_PATCH;
}

int main()
{
	auto number = buildNumber();
	cout<<"build "<< number;
	cout<<"Hello, World!";
}


