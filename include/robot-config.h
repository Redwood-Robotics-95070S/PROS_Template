#include "main.h"

using namespace pros;

extern Controller controller;

extern Motor fl;
extern Motor fr;
extern Motor bl;
extern Motor br;
extern GPS GPST;

pros::Motor fl(1, true);
pros::Motor fr(7,false);
pros::Motor bl(10,true);
pros::Motor br(3,false);
pros::Controller controller(E_CONTROLLER_MASTER);