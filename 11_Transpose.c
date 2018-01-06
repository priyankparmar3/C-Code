/*
 * Program to find the transpose of a matrix
 */
#include<stdio.h>
int main(){
	int mat[3][3],mat1[3][3];	
	char i,j,k=1;
	printf("Matrix is  :\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			mat[i][j]=k++;
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
	printf("\n------------------------------------------");	
	printf("Transposed  Matrix is  :\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			mat1[i][j]=mat[j][i];
			printf("%d\t",mat1[i][j]);
		}
		printf("\n");
	}
	return 0;
}
