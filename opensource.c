#include <stdio.h>
#include <string.h>

	int stripos (char *haystack, char *needle, int offset ){

		int count=0,i,needlecount=0,j=0;

		// counting length of haystack
		do{
			count++;
		}
		while(*haystack++);

		haystack=haystack - count;

		//Counting length of needle
		do{	
			needlecount++;
		}
		while(*needle++);
		needle = needle - needlecount;

		/*Comparison*/
		for(i=0; i<= count;i++){
			
			if(*(haystack+offset+i) == *(needle+j)){ //If charc of haystack and needle is the same. Offset is taken into consideration. 
					j++;
					if(j == (needlecount-1)) {
							printf("Total char counted =%d\n", i+1);
							printf("Length of needle = %d\n", j);
							printf("Offset value = %d\n",offset);
							return (i+1-j);
						}	
				}
			else if (*(haystack+offset+i) == *(needle)) //Consider the llow case!
			{
				j=1;
			}
			else{j=0;} //If is not the same - Reset J
		}
	return -1; //needle not found
	}   


int main()
{	int position = stripos("helloworld", "lldd" , 0);
	if (position == -1) {
		printf("Needle is not found in haystack.\n");
	} 
	else {
		printf("Position of needle in haystack = %d\n",position );
	}
}