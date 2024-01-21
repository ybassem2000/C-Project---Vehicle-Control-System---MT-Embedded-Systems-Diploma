/*
 * project.c
 *
 *  Created on: Dec 27, 2023
 *      Author: Youssef Bassem
 */
#include<stdio.h>
#include<stdlib.h>
enum OnOff  {OFF,ON};


void EngineMenu(){

	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
}


void  SensorMenu(){

	 	printf("Sensors set menu:\n");
	    printf("a. Turn off the engine\n");
	    printf("b. Set the traffic light color\n");
	    printf("c. Set the room temperature (Temperature Sensor)\n");
	    printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
	}

void VehicleState(int EngineState, int AC, int Speed, int RoomTemp, int EngTempCtrl,int EngTemp)
	{
		printf("Engine state: %s \n",EngineState ? "ON" : "OFF");
		printf(" AC: %s \n", AC ? "ON":"OFF");
		printf("Vehicle Speed = %d \n",Speed);
		printf("Room Temperature = %d \n", RoomTemp);
		printf("Engine Temperature Controller State. %s \n", EngTempCtrl ? "ON":"OFF");
		printf("Engine Temperature = %d \n ",EngTemp);
	}



int main(void){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char input,SensorInput,TrafficColour;
	int EngineState = OFF;
	int Speed = 0;
	int RoomTemp = 20 ;
	int AcState = OFF;
	int EngineTemp = 125;
	int EngineTempCtrl = OFF;


	printf("Welcome to your car \n");


	do{
		EngineMenu();
		scanf(" %c",&input);
		switch(input){
			case'a':

				if(EngineState == OFF)
				{ EngineState = ON;}
				printf("  Vehicle engine ON \n");
				do{
				VehicleState(EngineState,AcState,Speed,RoomTemp,EngineTempCtrl,EngineTemp);
				SensorMenu();
				scanf(" %c",&SensorInput);
						switch(SensorInput){
							case'a':
								EngineState=OFF;
								break;

							case'b':
								printf("Enter traffic light color (G/O/R): ");
								scanf(" %c", &TrafficColour);
								if (TrafficColour == 'G' || TrafficColour == 'g' )
									{
									Speed = 100;
									}
								else if (TrafficColour == 'O' ||TrafficColour == 'o' )
									{
									Speed = 30;
									}
								else if (TrafficColour == 'R' || TrafficColour == 'r' )
									{
									Speed = 0;
									}
								break;

							case'c':
								printf("Enter The Room Temperature \n ");
								scanf("%d",&RoomTemp);
								if(RoomTemp < 10)
								{	AcState = ON;
									RoomTemp = 20;
								}
								else if(RoomTemp > 30)
								{	AcState = ON;
									RoomTemp = 20;
								}
								else
								{
									AcState = OFF;
								}
								break;
							case'd':
								printf("Enter The Engine Temperature \n ");
								scanf("%d",&EngineTemp);
								if(EngineTemp < 100)
								{	EngineTempCtrl = ON;
									EngineTemp = 125;
								}
								else if(EngineTemp > 150)
								{	EngineTempCtrl = ON;
									EngineTemp = 125;
								}
								else
								{
									EngineTempCtrl = OFF;

								}
								break;
						}
		}while(SensorInput != 'a');
								break;



			case 'b':
				if(EngineState == ON)
				{ EngineState = OFF;}
				printf("  Vehicle engine OFF \n");
				break;


	}
		 if (Speed == 30){
			 if (AcState == 0) {
				 AcState = 1;
				 RoomTemp = RoomTemp * (5/4) + 1;
		 	 	 }
		 }
		 VehicleState(EngineState,AcState,Speed,RoomTemp,EngineTempCtrl,EngineTemp);



}while(input != 'c');

	return 0;
}

