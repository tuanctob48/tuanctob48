#include <stdio.h>
#include <stdlib.h>
int findMax(float a, float b){
	if(a>b) return 0;
	return 1;
}
int main(int argc, char const *argv[])
{
	int numOfThings;
	int tmp;
	int *arrValue = NULL;
	float *arrRatio = NULL, *arrLossValue = NULL, sum;
	FILE *input;
	FILE *output;
	input = fopen("input.txt","r");
// DOC file du lieu =.='	
	// Doc so luong do vat
	if(input == NULL)
		{
			printf("Khong ton tai tap tin input.txt\n");
			return 0;
		}
	else 
		{
		fscanf(input, "%d\n", &numOfThings);
		printf("So luong do vat la : %d \n", numOfThings);
		arrRatio = malloc(sizeof(float)*numOfThings);
		arrValue = malloc(sizeof(int)*numOfThings);
		arrLossValue = malloc(sizeof(float)*numOfThings);
		if(arrRatio!= NULL) printf("Cap phat bo nho cho ArrRatio thanh cong\n");
		if(arrValue!= NULL) printf("Cap phat bo nho cho ArrValue thanh cong\n");
		printf("Vi tri hien tai cua con tro ki tu trong file la: %ld \n",ftell(input));
		// Doc gia tri do vat
		printf("Gia tri do vat lan luot la:\n");
		for (tmp = 0; tmp < numOfThings; tmp++)
			{
			fscanf(input, "%d ", (arrValue+tmp));
			printf("%d \n", *(arrValue+tmp));
			}
		// Doc ti le mat mat do vat
		tmp = 0;
		printf("Ti le mat mat lan luot la: \n");
		for (tmp = 0; tmp < numOfThings; tmp++)
			{
			fscanf(input, "%f ", (arrRatio+tmp));
			printf("%.2f \n", *(arrRatio+tmp));
			}
		// Gan gia tri ket thuc cho 2 mang
			*(arrValue+tmp+1) = '\0';
			*(arrRatio+tmp+1) = '\0';
			fclose(input);
		}
		// Tinh gia tri con lai 
		printf("Gia tri mat di cua cac do vat lan luot la: \n");
		for (tmp = 0; tmp < numOfThings; tmp++)
		{
			// printf("%.2f\n", (*(arrValue+tmp))*(*(arrRatio+tmp)));
			*(arrLossValue+tmp) = (*(arrValue+tmp))*(*(arrRatio+tmp)) 	;
			printf("%.2f\n",*(arrLossValue+tmp));
		}
		int indexMax1 = findMax(*arrLossValue, *(arrLossValue+1));
		int indexMax2 = findMax(*(arrLossValue+1), *(arrLossValue));
		// Tim 2 do vat mat di nhieu gia tri nhat de cho vao o bao toan
		for(tmp = 2; tmp <numOfThings ; tmp ++)
		{
			if (*(arrLossValue+tmp)>*(arrLossValue+indexMax1))
			{
				indexMax2 = indexMax1;
				indexMax1 = tmp;
			}
			else if (*(arrLossValue+tmp)> *(arrLossValue+indexMax2))
			{
				indexMax2 = tmp;
			}
		}
		for(tmp = 0; tmp < numOfThings; tmp ++)
		{
			if(tmp == indexMax2 || tmp == indexMax1){
				sum+=*(arrValue+tmp);
			}
			else sum+=(*(arrValue+tmp))*(1 - *(arrRatio+tmp));
		}
		output = fopen("output.txt","w+");
		fprintf(output,"%d %d\n%.0f",indexMax1,indexMax2,sum);
	return 0;
}