/*
 * CarPlateHeader.h
 *
 *  Created on: 16 nov. 2020
 *      Author: blomg
 */

#ifndef CARPLATEHEADER_H_
#define CARPLATEHEADER_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX 9
#define SEP " "
#define LETTER "abcdefghijklmnopqrstuvxyz"
#define DIGIT "0123456789"
#define EOS '\0'
#define ENTER '\n'


_Bool Checker(char temp, const char *filters);

void Args_to_char(char *argA[], char res[]);


#endif /* CARPLATEHEADER_H_ */
