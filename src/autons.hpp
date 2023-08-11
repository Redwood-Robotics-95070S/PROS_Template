#include "main.h"

//Auton functions

//pls make sure u know what these functions r before using them

//2 for green, 1 for red, 6 for blue
const int gearset = 2;

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

void stopping() {
    fl.brake();
    fr.brake();
    bl.brake();
    br.brake();
}

//set drivetrain velocity pct value
void setv(double pctamt) {
    fl.move_velocity(pctamt*gearset);
    fr.move_velocity(pctamt*gearset);
    bl.move_velocity(pctamt*gearset);
    br.move_velocity(pctamt*gearset);
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
    fl.move_relative(amt, vcity*gearset);
    fr.move_relative(amt, vcity*gearset);
    bl.move_relative(amt, vcity*gearset);
    br.move_relative(amt, vcity*gearset);
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
    fl.move_relative(amt, vcity*gearset);
    fr.move_relative(-amt, vcity*gearset);
    bl.move_relative(amt, vcity*gearset);
    br.move_relative(-amt, vcity*gearset);
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

//move forward for an amount of time 
void For(double waittime, double volt = 127) {
    sethold();
    fl.move(volt);
    fr.move(volt);
    bl.move(volt);
    br.move(volt);
    delay(waittime);
    //pros::delay(waittime);
    stopping();
}

//same as above but reverse
void Rev(double waittime, double volt = 127) {
    sethold();
    fl.move(-volt);
    fr.move(-volt);
    bl.move(-volt);
    br.move(-volt);
    delay(waittime);
    //pros::delay(waittime);
    stopping();
}

//same as above but turning. turns right unless dir is set to 0
void Turn(double waittime, bool dir = 1, double volt = 127) {
    sethold();
    if(dir) {
        fl.move(volt);
        fr.move(-volt);
        bl.move(volt);
        br.move(-volt);
    }
    else {
        fl.move(-volt);
        fr.move(volt);
        bl.move(-volt);
        br.move(volt);
    }
    delay(waittime);
    //pros::delay(waittime);
    stopping();
}

//everything above but in rpm

//move forward for an amount of time 
void Forrpm(double waittime, double rpm = 100) {
    sethold();
    fl.move(rpm*gearset);
    fr.move(rpm*gearset);
    bl.move(rpm*gearset);
    br.move(rpm*gearset);
    delay(waittime);
    //pros::delay(waittime);
    stopping();
}

//same as above but reverse
void Revrpm(double waittime, double rpm = 127) {
    sethold();
    fl.move(-rpm*gearset);
    fr.move(-rpm*gearset);
    bl.move(-rpm*gearset);
    br.move(-rpm*gearset);
    delay(waittime);
    //pros::delay(waittime);
    stopping();
}

//same as above but turning. turns right unless dir is set to 0
void Turnrpm(double waittime, bool dir = 1, double rpm = 127) {
    sethold();
    if(dir) {
        fl.move(rpm*gearset);
        fr.move(-rpm*gearset);
        bl.move(rpm*gearset);
        br.move(-rpm*gearset);
    }
    else {
        fl.move(-rpm*gearset);
        fr.move(rpm*gearset);
        bl.move(-rpm*gearset);
        br.move(rpm*gearset);
    }
    delay(waittime);
    //pros::delay(waittime);
    stopping();
}