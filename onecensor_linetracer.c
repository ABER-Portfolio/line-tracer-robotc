
task main()
{
int check_r = 0;

	while(true)
	{
	check_r = SensorValue[S1];

		//check black
		if (check_r < 15.5)
		{
		setMotorSpeed(motorA,-25);
		setMotorSpeed(motorB,0);
		}
		else
		{
		setMotorSpeed(motorA,0);
		setMotorSpeed(motorB,-25);
		}
	}
}
