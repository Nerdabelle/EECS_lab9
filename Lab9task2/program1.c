/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: a473s013
 */
#include <stdio.h>
#include <limits.h>
#define MONTHS 12
#define WINDOW 6
void print_moving_averages(double sales[]);
double calculate_average(double sales[], int start, int end);
void findMinimumMaximum(float arr[], int N)
{
	int i;
	float minE = arr[0], maxE = arr[0];
	for(i=0; i<N; i++)
	{
		if(arr[i] > maxE)
		{
			maxE = arr[i];
		}
		if(arr[i] < minE)
		{
			minE = arr[i];
		}
	}
	float sum;
	float avg;
	sum = avg = 0;
	for (int loop = 0; loop <N; loop++){
		sum = sum + arr[loop];
	}
	avg = sum/N;
	printf("\nSales summary:\n");
	printf("Minimum sales: %.2f\n", minE);
	printf("Maximum sales: %.2f\n", maxE);
	printf("Average sales: %.2f\n", avg);
	return;
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

 
// Function to perform Selection Sort
void selectionSort(int arr[], int N)
{
    int i, j, max_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < N - 1; i++) {
 
        // Find the minimum element in unsorted array
        max_idx = i;
        for (j = i + 1; j < N; j++)
            if (arr[j] > arr[max_idx])
                max_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[max_idx], &arr[i]);
 
    }
}

int main()
{
	char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char *smonths[] = {"December","November","July","October","September","June","August","March","February","May","April","January"};
    float money[MONTHS];
    double sales[MONTHS];
    FILE *money_file = fopen("money.txt", "r");
    if (money_file == NULL) {
        printf("Error: could not open file 'money.txt'\n");
        exit(1);
    }
    for (int i = 0; i < MONTHS; i++) {
        fscanf(money_file, "%f", &money[i]);
    }

    fclose(money_file);
    for (int i=0; i<MONTHS; i++){
    	sales[i] = (double)money[i];
    }

	printf("Monthly sales report for 2022\n");
	printf("Month     Sales\n");

	for (int i =0; i < 12; i++)
	{
		printf("%-10s$%-8.2lf\n", months[i], money[i]);
	}
	int N = sizeof(money)/ sizeof(money[0]);
	findMinimumMaximum(money, N);
	printf("\n");


    //double sales[MONTHS] = {23458.01, 40112.00,56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89,  67230.84, 68233.12, 80950.34, 95225.22 };

    print_moving_averages(sales);
    printf("\nSales Report (Highest to Lowest): \n");
    printf("  Months    Sales   \n");
    selectionSort(money, N);
	for (int i =0; i < 12; i++)
	{
		printf("%-10s$%-8.2lf\n", smonths[i], money[i]);
	}

	return 0;
    

}
void print_moving_averages(double sales[]) {
    printf("Six-Month Moving Average Report:\n");
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i <= MONTHS - WINDOW; i++) {
        double average = calculate_average(sales, i, i + WINDOW - 1);
        printf("%-8s  -  %-10s$%-8.2lf\n", months[i], months[i + 5], average);
    }
}

double calculate_average(double sales[], int start, int end) {
    double sum = 0.0;
    for (int i = start; i <= end; i++) {
        sum += sales[i];
    }
    return sum / (end - start + 1);
}