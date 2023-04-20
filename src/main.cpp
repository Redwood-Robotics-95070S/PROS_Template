#include "main.h"
#include "display/lvgl.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

int x; // time
int mode = 1;
int sensitivity = 1;
bool a = 1;
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	while(a) {
		if(controller.get_digital_new_press(DIGITAL_RIGHT)) {
			mode++;
		}
		else if(controller.get_digital_new_press(DIGITAL_LEFT)) {
			mode--;
		}
		if(mode > 3) {
			mode = 1;
			pros::delay(100);
		}
		else if(mode < 1) {
			mode = 3;
			pros::delay(100);
		}
		if(mode == 1) {
			controller.clear();
			controller.print(1,1,"arcade 1 joystick");
		}
		else if(mode == 2) {
			controller.clear();
			controller.print(1,1,"arcade 2 joystick");
		}
		else if(mode == 3) {
			controller.clear();
			controller.print(1,1,"tank");
		}
	}
	if(controller.get_digital_new_press(DIGITAL_A)) {
		a = 0;
	}
	while(!a) {
		controller.clear();
		controller.print(0, 0, "Sensitivity: %d", sensitivity);
		if(controller.get_digital_new_press(DIGITAL_A)) {
			a = 1;
		}
		if(controller.get_digital_new_press(DIGITAL_UP)) {
			sensitivity++;
			pros::delay(100);
		}
		else if(controller.get_digital_new_press(DIGITAL_DOWN)) {
			sensitivity--;
			pros::delay(100);
		}
		if(controller.get_digital_new_press(DIGITAL_RIGHT)) {
			sensitivity += 10;
		}
		else if(controller.get_digital_new_press(DIGITAL_LEFT)) {
			sensitivity -= 10;
		}
		if(sensitivity > 200) {
			sensitivity = 1;
		}
		else if(sensitivity < 1) {
			sensitivity = 200;
		}
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
	controller.rumble("...");
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
	
	if(mode == 1) {
		fl.move((controller.get_analog(ANALOG_LEFT_X) + controller.get_analog(ANALOG_LEFT_Y))*sensitivity*0.01);
		fr.move((controller.get_analog(ANALOG_LEFT_X) - controller.get_analog(ANALOG_LEFT_Y))*sensitivity*0.01);
		bl.move((controller.get_analog(ANALOG_LEFT_X) - controller.get_analog(ANALOG_LEFT_Y))*sensitivity*0.01);
		br.move((controller.get_analog(ANALOG_LEFT_X) + controller.get_analog(ANALOG_LEFT_Y))*sensitivity*0.01);
	}
	else if(mode == 2) {
		fl.move((controller.get_analog(ANALOG_LEFT_X) + controller.get_analog(ANALOG_RIGHT_Y))*sensitivity*0.01);
		fr.move((controller.get_analog(ANALOG_LEFT_X) - controller.get_analog(ANALOG_RIGHT_Y))*sensitivity*0.01);
		bl.move((controller.get_analog(ANALOG_LEFT_X) - controller.get_analog(ANALOG_RIGHT_Y))*sensitivity*0.01);
		br.move((controller.get_analog(ANALOG_LEFT_X) + controller.get_analog(ANALOG_RIGHT_Y))*sensitivity*0.01);
	}
	else if(mode == 3) {
		fl.move((controller.get_analog(ANALOG_LEFT_X))*sensitivity*0.01);
		fr.move((controller.get_analog(ANALOG_RIGHT_X))*sensitivity*0.01);
		bl.move((controller.get_analog(ANALOG_LEFT_X))*sensitivity*0.01);
		br.move((controller.get_analog(ANALOG_RIGHT_X))*sensitivity*0.01);
	}
}
