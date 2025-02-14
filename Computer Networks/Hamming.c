#include<stdio.h>
#include<conio.h>

void encoding(){
    int data[7],rec[7],i,c1,c2,c3,c;
    printf("\n--------Encoding--------\n");
	printf("Enter message bit one by one:  \n");
	scanf("%d%d%d%d",&data[0],&data[1],&data[2],&data[4]);
	data[6]=data[0]^data[2]^data[4];
	data[5]=data[0]^data[1]^data[4];
	data[3]=data[0]^data[1]^data[2];
	printf("\nThe encoded bits are: ");
	for (i=0;i<7;i++) {
		printf("%d ",data[i]);
	}
    printf("\n");
}

void errorDetection(){
    int data[7],rec[7],i,c1,c2,c3,c;
    printf("\n--------Error Detection--------");
	printf("\nEnter the received data bits one by one: \n");
	for (i=0;i<7;i++) {
		scanf("%d",&rec[i]);
	}
	c1=rec[6]^rec[4]^rec[2]^rec[0];
	c2=rec[5]^rec[4]^rec[1]^rec[0];
	c3=rec[3]^rec[2]^rec[1]^rec[0];
	c=c3*4+c2*2+c1;
	if(c==0) {
		printf("\nThere is no error! \n");
	} 
    else {
		printf("\nError on the postion: %d\nCorrect message is: ",c);
		if(rec[7-c]==0){
            rec[7-c]=1;
        }	 
        else{
            rec[7-c]=0;
        }
		for (i=0;i<7;i++) {
			printf("%d ",rec[i]);
		}
        printf("\n");
	}
}

int main() {
    int sel;
    printf("--------Hamming Code--------\n");
    printf("\n!! This program only works for messages of 4bits in size !!\n\n");
    printf("Encoding: 1\nError Detection: 2\nBoth: 3\n\n");
    printf("Enter the serial number of the operation required: ");
    scanf("%d",&sel);
    switch(sel){
        case 1:
            encoding();
            break;
        case 2:
            errorDetection();
            break;
        case 3:
            encoding();
            printf("\n");
            errorDetection();
            break;
        default:
            printf("\nPlease provide an input within valid range(1 - 3)!!\n");
    }
}