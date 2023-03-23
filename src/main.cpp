#include "main.h"
#include "display/lvgl.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

int x; // time
double xinit; // x initial position
double yinit; // y initial position
double headinit; // heading initial position (usually 180)
int auton;
int numofautons;
double xpos = 0; // x coordinate target
double ypos = 0; // y coordinate target
void initialize() {
	GPST.initialize_full(xinit, yinit, headinit, 0, 0);
	int auton = 1;
	int numofautons = 3;
	fl.set_brake_mode(MOTOR_BRAKE_COAST);
	fr.set_brake_mode(MOTOR_BRAKE_COAST);
	bl.set_brake_mode(MOTOR_BRAKE_COAST);
	br.set_brake_mode(MOTOR_BRAKE_COAST);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	controller.clear();
	int i = 0;
	while (i != x) {
		controller.rumble("." "-");
		i++;
	}
}
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
bool a = 0;
void competition_initialize() {
	int auton = 1;
	int numofautons = 3;
	while(!a){
		if(controller.get_digital_new_press(DIGITAL_RIGHT)) {
			auton++;
			pros::delay(200);
		}
		else if(controller.get_digital_new_press(DIGITAL_LEFT)) {
			auton--;
			pros::delay(200);
		}
		if(controller.get_digital_new_press(DIGITAL_A)){
			a = 1;
		}
		if(auton > numofautons) {auton = 1;}
		if(auton < 1) {auton = numofautons;}
		
		if(auton == 1) {
			controller.clear();
			controller.set_text(1,1,"one");
		}
		else if(auton == 2) {
			controller.clear();
			controller.set_text(1,1,"two");
		}
		else if(auton == 3) {
			controller.clear();
			controller.set_text(1,1,"three");
		}
	}
	while (a) {
		if(controller.get_digital_new_press(DIGITAL_RIGHT)){
			xpos++;
		}
		else if(controller.get_digital_new_press(DIGITAL_LEFT)) {
			xpos--;
		}
		if(controller.get_digital_new_press(DIGITAL_UP)){
			ypos++;
		}
		else if(controller.get_digital_new_press(DIGITAL_DOWN)) {
			ypos--;
		}
	}
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	int x = 0;
	while(1) {
		pros::delay(1000);
		x++;
	}
	if(auton == 1) {
		one();
	}
	else if(auton == 2) {
		two();
	}

	else if(auton == 3) {
		three();
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
	double rightspeed = controller.get_analog(ANALOG_LEFT_X) - controller.get_analog(ANALOG_LEFT_Y);
	double leftspeed = controller.get_analog(ANALOG_LEFT_X) - controller.get_analog(ANALOG_LEFT_Y);
	fl.move(leftspeed);
	fr.move(rightspeed);
	bl.move(leftspeed);
	br.move(rightspeed);
}
