void Parking_start(void) {

	int parking_distance;
	int position_parking = 3000;

	right_front = DistanceSensor(2);
	printf("**********************right_front = %d\n", right_front);
	switch (status) {

	case 0:
		//&& right_front < 1200
		if (right_front > 650) {

			Winker_Write(ALL_ON);
			printf("right_front = %d\n", right_front);
			status = 1;

		}
		break;

	case 1:

		if (right_front < 400) {

			PositionControlOnOff_Write(CONTROL);
			DesireEncoderCount_Write(position_parking);


			printf("right_front = %d\n", right_front);
			status = 2;

		}
		break;
	case 2:
		parking_distance = position_parking - DesireEncoderCount_Read();
		if (parking_distance > 2000) // not parking
		{
			printf("**********not parking because parking_distance is %d\n",
				parking_distance);
			status = 0;
			Winker_Write(ALL_OFF);
		}

		if (right_front > 650) {

			printf("#################### %d\n", DesireEncoderCount_Read());
			printf("right_front = %d\n", right_front);
			DesireSpeed_Write(0);

			printf("*****parking_distance = %d\n", parking_distance);

			if (parking_distance > 850 && parking_distance < 1200) //horizontal
			{
				PositionControlOnOff_Write(UNCONTROL);

				Parking_horizontal();
				status = 4;
				//850
			}
			else if (parking_distance > 450 && parking_distance < 850) //vertical
			{
				PositionControlOnOff_Write(UNCONTROL);

				Parking_vertical();
				status = 4;

			}



		}
		break;
	case 4:

			status = 0;
			parking_count++;

		}
		break;
	default:
		break;
	}
	printf("status = %d\n", status);

}


void Parking_finish() {
	DesireSpeed_Write(0);
	Alarm_Write(ON);
	usleep(1000000);
	Alarm_Write(OFF);
	usleep(1000000);
}



//�����ʿ� vertical������
void Parking_vertical() {
	DesireSpeed_Write(0);

	SteeringServoControl_Write(1500);  //����
	usleep(500000);
	DesireSpeed_Write(70);
	usleep(100000);
	DesireSpeed_Write(0);


	SteeringServoControl_Write(2000);  //����
	usleep(500000);
	DesireSpeed_Write(70);
	usleep(1200000);
	DesireSpeed_Write(0);


	SteeringServoControl_Write(1000);  //������
	usleep(500000);
	DesireSpeed_Write(-70);
	usleep(1650000);
	DesireSpeed_Write(0);	
	

	SteeringServoControl_Write(1500);
	usleep(500000);  //cm??
	
	while (1) {
		
		DesireSpeed_Write(-50);
		usleep(200000);
		
		
		if (DistanceSensor(4) > 1000) {   //cm??   �����ְ�
			Parking_finish();
			break;
		}

		if (DistanceSensor(3) > 2000) {  //cm??
			SteeringServoControl_Write(1000);
			usleep(500000);
			DesireSpeed_Write(70);
			uslep(200000);
			SteeringServoControl_Write(1500);
			usleep(500000);
		}

		if (DistanceSensor(5) > 2000) {  //cm??
			SteeringServoControl_Write(2000);
			usleep(500000);
			DesireSpeed_Write(70);
			usleep(200000);
			SteeringServoControl_Write(1500);
			usleep(500000);
		}
	}//while

	DesireSpeed_Write(70);
	usleep(1500000);

	DesireSpeed_Write(0);
	SteeringServoControl_Write(1000);
	usleep(500000);
	
	DesireSpeed_Write(70);
	usleep(1500000);

	SteeringServoControl_Write(1500);
	usleep(500000);


}




//horizontal park

void Parking_horizontal() {

	DesireSpeed_Write(0);
	SteeringServoControl_Write(1500);
	usleep(500000);
	
	if () {//close
		DesireSpeed_Write(70);
		usleep(1000000);

		DesireSpeed_Write(0);
		SteeringServoControl_Write(2000);
		usleep(500000);

		
		while (1) {
			DesireSpeed_Write(-50);
			usleep(200000);
			if (DistanceSensor(4) > 1500) {
				DesireSpeed_Write(0);
				break;
			}
		}//while1

		SteeringServoControl_Write(1400);
		usleep(500000);

		while (1) {
			
			DesireSpeed_Write(50);
			usleep(200000);
			if (DistanceSensor(1) > 2000 || DistanceSensor(2) > 2000) {//cm??
				DesireSpeed_Write(0);
				break;
			}
		}//while2

		SteeringServoControl_Write(2000);
		usleep(500000);

		while (1) {
			DesireSpeed_Write(-50);
			usleep(200000);
			if (DistanceSensor(4) > 2000) {
				DesireSpeed_Write(0);
				Parking_finish();
				break;
			}
		}//while3

		DesireSpeed_Write(70);
		usleep(2000000);

		DesireSpeed_Write(0);
		SteeringServoControl_Write(1000);
		usleep(500000);

		DesireSpeed_Write(70);
		usleep(2000000);


		

	}

}
