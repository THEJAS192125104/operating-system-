#include <stdio.h>
int main()
{
	int A[100][4]; 			
	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;
	printf("Enter number of process: ");
	scanf("%d", &n);
	printf("Enter Burst Time:\n");	
	for (i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &A[i][1]);
		A[i][0] = i + 1;
	}
	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}
	A[0][2] = 0;
	for (i = 1; i < n; i++) {
		A[i][2] = 0;
		for (j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}
	avg_wt = (float)total / n;
	
	
	output
		
	total = 0;
	printf("P	 BT	 WT	 TAT\n");
	
	for (i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		printf("P%d	 %d	 %d	 %d\n", A[i][0],A[i][1], A[i][2], A[i][3]);
	}
	avg_tat = (float)total / n;
	printf("Average Waiting Time= %f", avg_wt);
	printf("\nAverage Turnaround Time= %f", avg_tat);
}


output
Enter number of process:8
nEnter Burst Time:np1:5
p2:2
p3:6
p4:9
p5:73
p6:1
p7:6
p8:5
nProcesst    Burst Time    tWaiting TimetTurnaround Timenp6tt  1tt    0ttt1np2tt  2tt    1ttt3np1tt  5tt    3ttt8np8tt  5tt    8ttt13np3tt  6tt    13ttt19np7tt  6tt    19ttt25np4tt  9tt    25ttt34np5tt  73tt    34ttt107nnAverage Waiting Time=12.875000nAverage Turnaround Time=26.250000n
