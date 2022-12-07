/**
 * @file	client.c
 * @author	MarshallingVoid	(marshallingvoid@gmail.com)
 * @breif	The Client implementation to use the Generic InsertionSort.
 * @date	20/11/2022
 * @version	1.0
 * 
 * @copyright	Copyright (c) 2022
 */


#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>
#include "mv_insertion_sort.h"
#define  NEW_LINE  fprintf(stdout, "\n\n")
struct Demo
{
long long llnum;    //  8
int inum;           //  4
char ch;            //  1 + 3
};                      //  16
struct Demo* darr = NULL;
ret_t compare_proc(data_t data1, data_t data2)
{

//Code
//Sorting Condition
//fprintf(stdout, " %lld\n", (long long) data1);

if( (long long)data1 > (long long)data2 )   
return(SUCCESS);
return(FAILURE);
}
int main(void)
{
srand(time(0));

//long long  no_of_elements = 10 + rand() % 10;

long long  no_of_elements = 10;
darr = (struct Demo*) calloc(no_of_elements, sizeof(struct Demo));
for( long long le = 0; le < no_of_elements; ++le )
{
darr[le].llnum = 1 + rand() % 999;
darr[le].inum = 1 + rand() % 50;
darr[le].ch = 65 + rand() % 26;
}
NEW_LINE;
fprintf(stdout, "Before Sort:\n");
fprintf(stdout, "No Of Elements: %lld\n", no_of_elements);
fprintf(stdout, "[START]-");
for( long long le = 0; le < no_of_elements; ++le )
{

//fprintf(stdout, "[%lld]-", darr[le]);

fprintf(stdout, "[%lld | %d | %c]-", darr[le].llnum, darr[le].inum, darr[le].ch);
}
fprintf(stdout, "[END]");
NEW_LINE;

//MOMENT OF TRUTH: Call The Insertion Sort 

clock_t start = clock();
mv_insertion_sort((data_t*)darr, no_of_elements, compare_proc);
clock_t end = clock();
double time_for_sorting = ( (double)(end - start) ) / CLOCKS_PER_SEC;
fprintf(stdout, "Time of Sorting: %lf\n", time_for_sorting);
NEW_LINE;
fprintf(stdout, "After Sort:\n");
fprintf(stdout, "No Of Elements: %lld\n", no_of_elements);
fprintf(stdout, "[START]\n");
for( long long le = 0; le < no_of_elements; ++le )
{
fprintf(stdout, "[%lld | %d | %c]-", darr[le].llnum, darr[le].inum, darr[le].ch);
}
fprintf(stdout, "[END]");
NEW_LINE;
if( darr )
{
free(darr);
darr = NULL;
}
exit(EXIT_SUCCESS);
}
