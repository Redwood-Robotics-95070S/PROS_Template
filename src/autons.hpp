#include "main.h"

//Auton functions

//pls make sure u know what these functions r before using them

//set motors to coasting
void setcoast() {
    fl.set_brake_mode(MOTOR_BRAKE_COAST);
    fr.set_brake_mode(MOTOR_BRAKE_COAST);
    bl.set_brake_mode(MOTOR_BRAKE_COAST);
    br.set_brake_mode(MOTOR_BRAKE_COAST);
}

void sethold() {
    fl.set_brake_mode(MOTOR_BRAKE_HOLD);
    fr.set_brake_mode(MOTOR_BRAKE_HOLD);
    bl.set_brake_mode(MOTOR_BRAKE_HOLD);
    br.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void setbrake() {
    fl.set_brake_mode(MOTOR_BRAKE_BRAKE);
    fr.set_brake_mode(MOTOR_BRAKE_BRAKE);
    bl.set_brake_mode(MOTOR_BRAKE_BRAKE);
    br.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

//set drivetrain velocity pct value
void setv(double pctamt) {
    fl.move_velocity(pctamt*200*0.01);
    fr.move_velocity(pctamt*200*0.01);
    bl.move_velocity(pctamt*200*0.01);
    br.move_velocity(pctamt*200*0.01);
}

//set drivetrain velocity rpm value
void setvrpm(double rpmamt) {
    fl.move_velocity(rpmamt);
    fr.move_velocity(rpmamt);
    bl.move_velocity(rpmamt);
    br.move_velocity(rpmamt);
}

//move forward or backward an amount of degrees at a set velocity then wait for a set amount, waittime and vcity (wait time and velocity) are optional parameters, and are defaulted to 20 ms and 100 pct velocity, but can be changed when called
void forback(double amt, int waittime = 0, double vcity = 100) {
    fl.move_relative(amt, vcity*200*0.01);
    fr.move_relative(amt, vcity*200*0.01);
    bl.move_relative(amt, vcity*200*0.01);
    br.move_relative(amt, vcity*200*0.01);
    pros::delay(waittime);
}

//same as above function but input for velocity is rpm
void forbackrpm(double amt, int waittime = 0, double vcity = 200) {
    fl.move_relative(amt, vcity);
    fr.move_relative(amt, vcity);
    bl.move_relative(amt, vcity);
    br.move_relative(amt, vcity);
    pros::delay(waittime);
}

//same as forbackpct but for turning, positive value turns right, negative value turns left
void turnpct(double amt, int waittime = 0, double vcity = 100) {
    fl.move_relative(amt, vcity*200*0.01);
    fr.move_relative(-amt, vcity*200*0.01);
    bl.move_relative(amt, vcity*200*0.01);
    br.move_relative(-amt, vcity*200*0.01);
    pros::delay(waittime);
}

//same as above, but rpm
void turnrpm(double amt, int waittime = 0, double vcity = 200) {
    fl.move_relative(amt, vcity);
    fr.move_relative(-amt, vcity);
    bl.move_relative(amt, vcity);
    br.move_relative(-amt, vcity);
    pros::delay(waittime);
}
//someone help this is vexcode version and idk how to make motors move without giving them a value, and having them run forever 
/*
void ForBack(double ms) {
  fl.spin(forward);
  fr.spin(forward);
  bl.spin(forward);
  br.spin(forward);
  wait(ms,msec);
  fl.stop();
  fr.stop();
  bl.stop();
  br.stop();
}

//same as above but for turning, bool dir 1 is turning right, 0 is turning left (true is right, false is left)
void Turn(double ms, bool dir) {
  if(dir) {
    fl.spin(forward);
    fr.spin(reverse);
    bl.spin(forward);
    br.spin(reverse);
  }
  else {
    fl.spin(reverse);
    fr.spin(forward);
    bl.spin(reverse);
    br.spin(forward);
  }
  wait(ms,msec);
  fl.stop();
  fr.stop();
  bl.stop();
  br.stop();
}
*/