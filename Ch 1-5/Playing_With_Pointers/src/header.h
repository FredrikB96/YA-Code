/*
 * header.h
 *
 *  Created on: 14 okt. 2020
 *      Author: Benny
 */

#ifndef HEADER_H_
#define HEADER_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdBool.h>
#include <string.h>
#include <Ctype.h>

#define MAX_INPUT 10
#define ACTUAL_INPUT MAX_INPUT - 1
#define TOTAL_INPUT_LENGTH 25


_Bool Input_Control(char *IPCptr,char *FNptr,char *LNptr,int *Age);

#endif /* HEADER_H_ */
