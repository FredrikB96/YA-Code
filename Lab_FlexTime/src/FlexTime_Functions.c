/*
 * FlexTime_Functions.c
 *
 *  Created on: 24 nov. 2020
 *      Author: blomg
 */


#include "FlexTime_Header.h"


void Employee_Name(char Input[],char *inptr){

	char temp[NAME];
	int length = strlen(Input);
	int special_character=0;

	char t;
	int k,j=0; // Iteration values

	for(int i=0;i<NAME;i++){ // resetting the array to nothing
		temp[i] = '\0';
	}

	k=length-1;
	for(int i=0;i<length;i++){ // saves the name by reversing the input and looking for _ character
		t = Input[k--];
		if(isalpha(t)&&(special_character==DUAL)){
			temp[j] = t;
			j++;
		}else if(t=='\\'){ // since we look in reverse when reached: \ or \\ we are at system path then we are done
			i=length;
		}
		else if(t=='_'){
			special_character++;
		}
	}

	temp[j] = '\0';
	length = strlen(temp);
	j= length-1;
	for(int i=0;i<NAME;i++){ // reversing the saved input to get correct way
		if(i>length-1){
			*inptr = '\0';
		}else {
			*inptr = temp[j];
			j--;
			inptr++;
		}
	}
}

int Employee_Number(char Input[]){

	char Employee_No[SIZE+DUAL];
	char temp[WORKDAYH];
	int length = strlen(Input);

	int j = 0; // Iteration value
	int k = 0;

	char t;
	for(int i=0;j<DUAL;i++){ // looks at the input in reverse to find first _ character, then the digits after are the employee no
		t = Input[length--];
		if(t=='_')
			j++;
		if(j==1){
			if(isdigit(t)){
				temp[k] =t;
				k++;
			}
		}
	}
	temp[k] = '\0';

	length = strlen(temp);
	j = length-1;
	k=0;
	for(int i=0;i<length;i++){ // reversing the saved input to get correct
		Employee_No[k++] = temp[j--];
	}
	Employee_No[k] = '\0';
	int numb = atoi(Employee_No);
	return numb;
}

int Enployee_Period(char Input[]){
	int length = strlen(Input);

	char temp[DAYS+DUAL];
	char value[DAYS+DUAL];
	int j=0; // Iteration value
	char t;
	for(int i=0;t!='_';i++){

		t = Input[length--];
		if(isdigit(t)){
			temp[j] = t;
			j++;
		}
	}

	temp[j] = '\0';
	length = strlen(temp);
	j=length;
	j--;

	for(int i=0;i<length;i++){
		value[i]=temp[j--];
	}

	value[j]='\0';

	return atoi(value);
}

stamp INPUT(char tempc[]){

	stamp temp;

	char *temptr = &tempc[0];
	char operand = ',';
	temp.day = SPLITTER(temptr,operand);

	for(int i=0;i<STEP;i++){
		temptr++;
	}
	temp.hour = SPLITTER(temptr,operand);
	for(int i=0;i<3;i++){
		temptr++;
	}
	operand = ';';
	temp.minutes = SPLITTER(temptr,operand);


	return temp;
}

int SPLITTER(char *tempptr,char operand){
	int temp;
	char tempc = *tempptr;
	char tempa[DUAL+STEP];
	int i;
	for(i=0;tempc!=operand;i++)
	{
		if(tempc == ','){
			tempc='.';
		}

		tempa[i] = tempc;
		tempptr++;
		tempc = *tempptr;
	}
	tempa[i] = '\n';
	temp = atoi(tempa);
	return temp;
}

employee WORK_TIME(stamp temp[DUAL][DAYS][STEP]){
	employee Employee;
	float temp_minutes=0;
	int temp_hours = 0;
	int hour_a;
	int hour_b;
	float min_a;
	float min_b;
	int week = 0;
	int position = 0;
	int day = 0;

	while(week<DUAL){ // when week variable hits 2 both weeks are done

		for(int i=0;i<DUAL;i++){ // counts hours between to stamps per period
			hour_a = temp[week][day][position].hour; // assigning first hour stamp
			hour_b = temp[week][day][position+1].hour; // assigning second hour stamp

			temp_hours = (hour_a<hour_b) ? temp_hours+hour_b-hour_a: temp_hours+hour_a-hour_b;

			min_a = (float)temp[week][day][position].minutes; // repeat but with minutes
			min_b = (float)temp[week][day][position+1].minutes;

			temp_minutes += min_b - min_a;


			if(temp_minutes>FILEMAX){ // if minutes are above 100 then its one hour more worked
				temp_hours +=1;
				temp_minutes -=FILEMAX;
			}
			position +=DUAL;
		}

		temp_minutes /= 60;
		position = 0; // resetting position to 0 for next round

		float worked_time = temp_hours;

		worked_time += temp_minutes;

		temp_minutes = 0; // resetting values for next run
		temp_hours = 0;

		Employee.Tot_Work[week][day] = worked_time; // defining the time in correct Tot_work array

		day++;
		if(day==5){ // if days are 5 then its a week done, turn days to 0 and move week forward one step
			day=0;
			week++;
		}
		worked_time = 0; // resetting values for next run

	}

	return Employee;
}

employee FLEX_TIME(employee temp){

	int a=0,b=0;

	for(int i=0;b!=DAYS;i++){
		temp.tot_hours += temp.Tot_Work[a][b] + temp.Tot_Work[a+1][b];
		b++;
	}

	temp.Flex_Change = temp.tot_hours - WORKWEEK;

	return temp;
}

void Output(employee Employee, char Name[],	char *Nptr,char Employee_no[],char Employee_Period[]){

	int length_no = strlen(Employee_no);
	int length_Period = strlen(Employee_Period);
	int  length = strlen(Name);

	_Bool done = false;
	_Bool name = false;
	_Bool No = false;
	_Bool Period = false;
	FILE *fpnt;
	char *bptr = Nptr;

	int i=0;
	while(!done){

		if(!name && !done){
			*bptr = Name[i++];
		}
		if(name && !No && !Period && !done){
			*bptr = Employee_no[i++];
		}
		if(name && No &&!Period && !done){
			*bptr = Employee_Period[i++];

		}

		if(i==length_Period+1 && name && No && !Period){
			Period = true;
			*bptr = '.';
			i=0;
		}

		if(i==length_no+1 && name && !No && !Period){
			No = true;
			*bptr = '_';
			i=0;
		}

		if(i==length+1 && !No && !Period && !name){
			name = true;
			*bptr = '_';
			i = 0;
		}

		if(name && No && Period)
			done = true;

		bptr++;

	}

	*bptr = 'd';
	bptr++;
	*bptr = 'a';
	bptr++;
	*bptr = 't';
	bptr++;
	*bptr = '\0';

	if ((fpnt=fopen(Nptr,"wb"))==NULL){
		printf("\n Cannot access the requested file!");
		exit(1);
	}

	Write_Data_To_File(fpnt,Employee);

}

void Write_Data_To_File(FILE *fpnt ,employee employe){

	int a =0,b=0;
	for(int i=0;i<SIZE;i++){
		float temp = employe.Tot_Work[a][b++];
		fwrite(&temp,sizeof(float),1,fpnt);
		if(b==DAYS){
			a++;
			b = 0;
		}
	}

	fclose(fpnt);
}

void Print_Out(FILE *fpnt,char Name[],employee Employee){

	float  t= 0;

	printf("\n Name: %3s   Employee No: %d   Period:  %d \n",Name,Employee.Employee_No,Employee.Period);
	printf("\n Overview:   Day1:   Day2:  Day3:  Day4:  Day5: ");
	printf("\n Week 1:   ");
	for(int i=0;i<SIZE;i++){
		fread(&t,sizeof(float),1,fpnt);
		printf("   %2.2f", t);
		if(i==STEP){
			printf("\n Week 2:   ");
		}
	}

	printf("\n \n Period Time: %2.2f (%2.2f)",Employee.tot_hours,Employee.Flex_Change);

}
