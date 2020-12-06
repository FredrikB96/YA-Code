/*
 * Flextime_header.h
 *
 *  Created on: 24 nov. 2020
 *      Author: blomg
 */

#ifndef FLEXTIME_HEADER_H_
#define FLEXTIME_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


#define DAYS 5
#define DUAL 2
#define STEP 4
#define WORKDAYH 8
#define SIZE 10
#define NAME 20
#define WORKWEEK 80
#define FILEMAX 100

#define TEST1 {"307,07,33; 307,11,44; 307,12,31; 307,16,10; 308,07,33; 308,11,44; 308,12,31; 308,16,10;"}

typedef struct{
	int Employee_No;
	int Period;
	float tot_hours;
	float Flex_Time;
	float Flex_Change;
	float Tot_Work [DUAL][DAYS];

}employee;

typedef struct{
	int day;
	int hour;
	int minutes;
}stamp;

void Employee_Name(char Input[],char *inptr);
// =========== Employee Name ==============
// Gets the Employee Name from file name
// By reversing the input and searching for two  '_' characters
// When found it will save the next characters until '\' character or end of input
int Employee_Number(char Input[]);
// =========== EMPLOYEE NUMBER ============
// Gets the Employee number from file name
// By reversing the input and searching for  '_' character
// When found it will save the next characters until another '_' character is found
// Input has to have one '_' characters after what you want to save ie: _saved data_
int Enployee_Period(char Input[]);
// =========== EMPLOYEE NUMBER ============
// Gets the Employee number from file name
// By reversing the input and saving all digits until a '_' character found
// Input has to have one '_' character before  what you want to save ie: _save me
stamp INPUT(char *tempptr);
// ========== INPUT_SAVER ================
// Separate data from input file into correct slot in struct
// By calling SPLITTER function to look for either ',' character or ';' then saves
// the return int to correct stamp position
// Returns struct

int SPLITTER(char *tempptr,char operand);
// ========== SPLITTER ===================
// Splits the input by looking for the input operand and saves all before in an array
// Will then use atoi function to convert the char array to an int
// Has to get an pointer to the char array/string that you want to split, then the operand
// to look for ie: 12345 , 9876 and operand: , it will now save all digits before , operand and return it as one int
employee WORK_TIME(stamp temp[2][5][4]);
// ========= WORK_TIME ==================
// adding all the values together in the multidimensional array
// saves it down in a float inside the employee struct called Tot_Hours
// Returns a employee struct
employee FLEX_TIME(employee temp);
// ======== FLEX_TIME =================
// calculates the total work hours for the entire period
// then checking the flex by subtracting 80 hours from Tot_Hours
void Output(employee Employee, char Name[],	char *Nptr,char Employee_no[],char Employee_Period[]);
// ======== OUTPUT ===================
// Creates a file with the file name based on the input
// in this order: ( Name_Employee_no_Employee_Period .dat )
// Will also call Write_Data_To_File function and sending the file pointer and employee variable
void Write_Data_To_File(FILE *fpnt ,employee employe);
// ============= Write_Data_To_File ===================
// Saves down the float variables holding the value of worked time per day ( in this case: employee.Tot_Work[][] )

void Print_Out(FILE *fpnt,char Name[],employee Employee);
// =============== Print_Out =========================
// Reads the data from previous created file, and prints it out in a nice table
// has to get a file pointer and a variable of employee type

#endif /* FLEXTIME_HEADER_H_ */
