/************************************************************
*  File:       KaitlinLab1.c
*  Project:    Lab 01
*  Author:
*  Version:    1.0
*  Date:       7 February, 2020
*  Course:     CMPE170
*  Instructor: Oveeyn Moonian
*  Description: The average number of runs of adjacent one bits in an 8-bit, 12-bit, and 16 bit integer.
* *********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


//FUNCTION DECLARATION
double CalcRunningAvg(double, unsigned int, unsigned int);

/*********************************************************************
 * Function     Print Error; checks number of runs; calculates avgBitsRuns using function CalcRunningAvg
 * Arguments:   char * message - string error message
 *
 * Returns:     avgBitRuns
 * Description: if the arguments does not equal 2, an error message will be produced. If the argument
 *				equals 2, follows through with calculating avgBitRuns
 * ******************************************************************/
int main(int argc, char* argv[]) {

	//checks to see if arguments is equal to 2; if arguments are more or less than two, error statement will be produced
	if (argc != 2) {
		printf("\nError: Expected integer argument.\n");
		return(EXIT_FAILURE);
	}

	int numBits = atoi(argv[1]);			//the number of bits in the numbers to count bit runs 
	int maxNum = pow(2, numBits);			//the maximum number based on the given number of bits (numBits)
	double avgBitRuns = 0;					//the running average of the number of bit runs

	for (unsigned int i = 0; i < maxNum; i++)
	{
		unsigned int j = i;						//used to cycle through all of the bits for each number (i)
		int runCount = 0;						//the number of bit runs for the current number (i)
		bool runStarted = 0;					//boolean to identify when a new run of bits has been detected

		while (j > 0) {

			//look at the least significant bit (LSB) in 'j'
			//a run is started (and counted) if the LSB is 1 AND a run hasn't already started
			if (j & 1) {
				if (!runStarted) {
					runStarted = 1;
					runCount++;
				}
			}

			//a run of bits is ended (runStarted = 0) when the LSB goes back to 0
			else {
				if (runStarted) {
					runStarted = 0;
				}
			}

			//bit shift 'j' to the right by 1, because we need to look at the next bit
			//so a number with a bit pattern of 00011010 shifts to the right to become 00001101
			j >>= 1;
		}

		//calculates the average bit runs using the function CalcRunningAvg below
		avgBitRuns = CalcRunningAvg(avgBitRuns, i, runCount);
	}

	//prints the average to the user
	printf("\n%.2f\n", avgBitRuns);

	return (EXIT_SUCCESS);
}

/*********************************************************************
 * Function     calculate the newRunningAvg
 * Arguments:   no arguments
 *
 * Returns:     newRunningAvg
 * Description: calculates newRunningAvg from the number input from the user.
 * ******************************************************************/
double CalcRunningAvg(double currentAvg, unsigned int n, unsigned int newCount) {

	double runNum = (double)n;
	double newRunningAvg = (currentAvg * (runNum / (runNum + 1.0))) + ((double)newCount / (runNum + 1.0));

	return newRunningAvg;
}
