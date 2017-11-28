#ifndef STATE_H_
#define STATE_H_


enum SamusState
{
	no_state = 0,

	run_right = 1,
	run_left = 2,

	jump_right = 3,
	jump_left = 4,

	stand_right = 5,
	stand_left = 6,

	run_right_shoot_right = 7,
	run_left_shoot_left = 8,

	jump_shoot_right = 9,
	jump_shoot_left = 10,

	stand_right_shoot_up = 11,
	stand_left_shoot_up = 12,

	run_right_shoot_up = 13,
	run_left_shoot_up = 14,

	jump_right_shoot_up = 15,
	jump_left_shoot_up = 16,

	rolling_right = 17,
	rolling_left = 18,

	turning_right = 19,
	turning_left = 20

};

#endif // !STATE_H_
