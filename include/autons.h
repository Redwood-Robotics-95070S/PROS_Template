#include "main.h"

// Autonomous Functions

// Constantly moving, in namespace vex Motor.spin(direction, speed value, units for speed value);
void forward(double velocity) {
    fl.move_velocity(velocity);
    fr.move_velocity(velocity);
    bl.move_velocity(velocity);
    br.move_velocity(velocity);
}

void reverse(double velocity) {
    fl.move_velocity(-velocity);
    fr.move_velocity(-velocity);
    bl.move_velocity(-velocity);
    br.move_velocity(-velocity);
}

void right(double velocity) {
    fl.move_velocity(velocity);
    fr.move_velocity(-velocity);
    bl.move_velocity(velocity);
    br.move_velocity(-velocity);
}


void left(double velocity) {
    fl.move_velocity(-velocity);
    fr.move_velocity(velocity);
    bl.move_velocity(velocity);
    br.move_velocity(-velocity);
}

// Moving set amount, in namespace vex, Motor.spinFor(direction, amount, units for turning) set motor velocity before
void setf(double degrees, double velocity) {
    fl.move_relative(degrees, velocity);
    fr.move_relative(degrees, velocity);
    bl.move_relative(degrees, velocity);
    br.move_relative(degrees, velocity);
}

void setr(double degrees, double velocity) {
    fl.move_relative(degrees, -velocity);
    fr.move_relative(degrees, -velocity);
    bl.move_relative(degrees, -velocity);
    br.move_relative(degrees, -velocity);
}

void settr(double degrees, double velocity) {
    fl.move_relative(degrees, velocity);
    fr.move_relative(degrees, -velocity);
    bl.move_relative(degrees, velocity);
    br.move_relative(degrees, -velocity);
}

void settl(double degrees, double velocity) {
    fl.move_relative(degrees, -velocity);
    fr.move_relative(degrees, velocity);
    bl.move_relative(degrees, -velocity);
    br.move_relative(degrees, velocity);
}