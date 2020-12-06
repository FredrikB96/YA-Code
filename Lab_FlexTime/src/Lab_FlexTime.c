/*
 ============================================================================
 Name        : Lab_FlexTime.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "FlexTime_Header.h"



int main(int args, char *argv[]) {

	setbuf(stdin,NULL);
	char location[FILEMAX];
	char Name[NAME];
	char *Nameptr = &Name[0];

	int length;

	stamp stamps [DUAL][DAYS][STEP];
	employee Employee;

	// Get Input file name, Counts in that it could be a location name ie: C:\..\..\Lab_Flex_Time\500190.txt
	if(args>1)
	{
		strcpy(location,argv[1]);
	}
	else{
		printf("\n Enter employee number: ");
		fgets(location,FILEMAX,stdin);
		length = strlen(location);
		if(length<SIZE){
			length--;
			location[length]='.';
			length++;
			location[length]='t';
			length++;
			location[length]='x';
			length++;
			location[length]='t';
			length++;
			location[length]='\0';
		}
	}
	length = strlen(location);

	// Load Input file data
	FILE *fpnt;

	if((fpnt=fopen(location,"rt"))==NULL){
		printf("\n Cannot find the file!");
		exit(1);
	}

	char File_Data[SIZE]; // Used to save each stamp and send to function
	char data_temp; // Disregard variable

	int position,day,week;
	position = 0;
	day = 0;
	week = 0;

	// TODO: will prob not work with missing stamps, will need to add a function before
	// TODO: that checks for empty stamps and subtracting in a dummy stamp
	// TODO: then removing correct time from flex. ( Can it be connected with WORK_TIME or flex function? )
	// TODO: could check for it in INPUT, then calculate missing time from dummy stamp and save in
	// TODO: temp work file? to avoid passing pointer?


	while(fread(&File_Data[0],sizeof(char),SIZE,fpnt)==SIZE){

		stamps[week][day][position++] = INPUT(File_Data);
		if(position==STEP){
			fread(&data_temp,sizeof(char),1,fpnt); // Disregarding the \n symbol
			position=0;
			day++;
		}
		if(day==DAYS){
			day=0;
			week++;
		}
	}
	week=0;

	// Calculate total work time
	// should only take struct as input
	// ========== WORK_TIME ============
	Employee = WORK_TIME(stamps);

	// Gets the employee name from file name
	Employee_Name(location,Nameptr);

	// Gets the employee number from file name
	Employee.Employee_No = Employee_Number(location);

	// Gets Period of stamps
	Employee.Period = Enployee_Period(location);

	// Calculate flex time
	// takes struct as input
	// calculate flex time by checking if Tot_work are above 8 then add to flex time
	// If less than 8 subtract remainder from flex time
	// ========= FLEX_TIME ===========

	Employee = FLEX_TIME(Employee);
	fclose(fpnt);
	// Export data from struct into file
	// Will take struct as input? maybe save location

//	======== OUTPUT ================
	char Employee_no[WORKDAYH];
	char Employee_Period[WORKDAYH];
	sprintf(Employee_no,"%d",Employee.Employee_No);

	sprintf(Employee_Period,"%d",Employee.Period);

	int length_no = strlen(Employee_no);
	int length_Period = strlen(Employee_Period);
	length = strlen(Name);
	int size = length + length_no + length_Period+STEP;


	char *Nptr = (char*) malloc(size*sizeof(char));

	if(Nptr==NULL){
		printf("\n Not enough memory!");
		exit(1);
	}

	// Adding data to file
	Output(Employee,Name,Nptr,Employee_no,Employee_Period);


	// ============ PRINT_OUT ===========
	fpnt=fopen(Nptr,"rb");

	Print_Out(fpnt,Name,Employee);

	fclose(fpnt);
	free(Nptr);

	return EXIT_SUCCESS;
}
