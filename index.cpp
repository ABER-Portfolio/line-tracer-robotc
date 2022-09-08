task main()
{
int l_light = 0; // return left light sensor value
int r_light = 0; // return right light sensor value
int speed = 7; // movement speed
int l_w_val = 30; // left light sensor white color value
int r_w_val = 35; // right light sensor white color value
int l_motor = motorA; // left motor
int r_motor = motorB; // right motor
int first_collision = 0; // check collision
int return_to_line = 0;

	while(1)
	{
	l_light = SensorValue(S3); // get left light sensor value
	r_light = SensorValue(S4);// get right light sensor value

	if (SensorValue(S2) <= 10 && return_to_line < 0)
	{
	return_to_line = 0;
	}

		if (return_to_line >= 0)
		{
		 	if (return_to_line == 0)
		 	{
		 	//setMotorSpeed(l_motor,30);
		 	//setMotorSpeed(r_motor,-30);
		 	//wait1Msec(200);
		 	//setMotorSpeed(l_motor,30);
		 	//setMotorSpeed(r_motor,30);
		 	//wait1Msec(400);
		 	//setMotorSpeed(l_motor,-30);
		 	//setMotorSpeed(r_motor,30);
		 	//wait1Msec(200);
		 	//setMotorSpeed(l_motor,30);
		 	//setMotorSpeed(r_motor,30);
		 	//wait1Msec(400);
		 	setMotorSpeed(l_motor,0);
		 	setMotorSpeed(r_motor,0);
		 	//wait1Msec(200);
		 	return_to_line = 0;
		 	}

		 	if (return_to_line == 1)
		 	{
		 		if (l_light <= l_w_val && r_light <= r_w_val)
		 		{
		 		return_to_line = -1;
		 		}
		 		else
		 		{
		 		setMotorSpeed(l_motor,30);
		 		setMotorSpeed(r_motor,30);
		 		}
		 	}
	 	}
		else/////////////////////////////////////////line tracer///////////////////////////////
		{
			if (l_light > l_w_val) // left light sensor detect white line
			{
			setMotorSpeed(l_motor,speed); // go backward
			}
			else // left light sensor detect black line
			{
			setMotorSpeed(l_motor,-speed); // go forward
				if (first_collision == 0) // when left sensor detected black line at first before right sensor detected black line
				{
				first_collision = -1;
				}
			}

			if (r_light > r_w_val) // right light sensor detect white line
			{
			setMotorSpeed(r_motor,-speed); // go forward
			}
			else // right light sensor detect black line
			{
			setMotorSpeed(r_motor,speed); // go backward
				if (first_collision == 0) // when right sensor detected black line at first before left sensor detected black line
				{
				first_collision = 1;
				}
			}


			if ((l_light > l_w_val && r_light > r_w_val) || (l_light <= l_w_val && r_light <= r_w_val)) // when l,r sensor detected white line  or  when l,r sensor detected black line
			{
				if (first_collision == -1)
				{
				setMotorSpeed(l_motor,-speed); // go forward
				setMotorSpeed(r_motor,speed*1.5); // go backward
				wait1Msec(400);
				first_collision = 0;
				}
				else
				{
				setMotorSpeed(l_motor,speed*1.5); // go backward
				setMotorSpeed(r_motor,-speed); // go forward
				wait1Msec(400);
				first_collision = 0;
				}
			}
		}
	}
}
