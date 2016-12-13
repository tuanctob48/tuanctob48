#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{	
	int numCustomers, tmpPresentDay,tmpPresentValue, maxSumOfDay,dayHasMax;
	int start, end, sumPeriod = 0, flag = 0, count=0, tmpPeriod;
	FILE* input = NULL, *output = NULL;
	int *sumValueOfDay = NULL,*dayWithoutSelling = NULL;

//Part 1: Xu ly input.txt
	input = fopen("inputSS.txt","r");
	if (input == NULL)
	{
		fprintf(output,"Khong ton tai tap tin inputSS.txt\n");
		return 0;
	}
	else
	{
		fscanf(input,"%d",&numCustomers);
		sumValueOfDay =  malloc(31*sizeof(int));
		dayWithoutSelling =  malloc(31*sizeof(int));
		for(int i = 0; i < numCustomers; i++)
		{
			fscanf(input,"%d %d", &tmpPresentDay,&tmpPresentValue);
			*(sumValueOfDay+tmpPresentDay-1) += tmpPresentValue;
		}
		output = fopen("outputSS.txt","a+");
		fprintf(output, "Phan 1:\n");
		fprintf(output,"Luong hang ban moi ngay la: \n");
		for(int i = 0; i < 31; i++)
		{
			fprintf(output,"%d- %d\n", i+1, *(sumValueOfDay+i));
		}
// Quet khoang thoi gian tinh tong	
		fscanf(input,"%d %d",&start,&end);
		start--;
		end--;
// Dong file input XD
		fclose(input);
		maxSumOfDay=-1;
//Part 2: Tim ngay ban duoc hang nhieu nhat + so luong va cac ngay khong ban duoc hang
		for(int i = 0; i < 31; i++)
		{
			// Ngay khong ban duoc hang
			if(*(sumValueOfDay+i)==0) 
			{
				flag = 1;
				*(dayWithoutSelling+i) = 1;
			}
			// Ngay ban nhieu nhat
			if(maxSumOfDay<*(sumValueOfDay+i)) 
				{
					dayHasMax = i;
					maxSumOfDay=*(sumValueOfDay);
				}
		}
		fprintf(output,"\nPhan 2: \nNgay ban duoc hang nhieu nhat la: %d\n", dayHasMax+1);
		if(flag)
		{
			fprintf(output,"Nhung ngay khong ban duoc hang la:\n");
			for(int i = 0; i < 31; i++)
			{
				if(*(dayWithoutSelling+i)) fprintf(output,"%d, ", i+1);
			}
		}
		else 
		{
			fprintf(output,"Khong co ngay nao khong ban duoc hang\n");
		}
	//Part 3: Tinh tong luong mua tinh tu start -> end
		for(int i = start; i <end+1;i++)
		{
			sumPeriod+=*(sumValueOfDay+i);
		}
		fprintf(output, "\n\nPhan 3: \nTong luong hang ban duoc tu ngay %d den ngay %d la: %d\n", start+1, end+1, sumPeriod );
	// Part 4: Tim chuoi ngay khong co ngua mua hang
		fprintf(output,"\nPhan 4:\nChuoi ngay khong co nguoi mua hang la: \n");
		for(int i = 0 ; i < 31; i++)
		{
			if(*(dayWithoutSelling+i)) 
			{	fprintf(output,"%d, %d",++count,i+1 );
				int k = 1;
				while(*(dayWithoutSelling+i+k++)&&((i+k) < 31));
				fprintf(output,"-%d\n", i+k-1);
				i += k-1; 
			}
		}
	return 0;
	}
}