

//..............STANDARD LIBRARIES........

#include <stdio.h>
#include <string.h>

//..............COLOUR CODES AND RESET CODES
#define black				"\x1b[40m"
#define white				"\x1b[47m"
#define red		     	"\x1b[41m"
#define green				"\x1b[42m"
#define yellow			"\x1b[43m"
#define blue				"\x1b[44m"
#define magenta			"\x1b[45m"
#define cyan				"\x1b[46m"
#define reset     	  "\x1b[0m"

//...............ARRAY SIZES
#define SIZE 150
#define SIZE1 24
#define SIZE2 132

// ...............HASHING FOR SMALL URL SIZE

void hash24(char URL[25],char hash2[25],int size,int limit){
	int i,j,m;
	limit =strlen(URL);
	int hash1[200];
	hash1[0]=50+limit;


//LOOP FOR REPEATING

	for (i=1; i<limit+1; i++)
		{
		hash1[i]=(int)(URL[i-1]);
		}
	for (j=limit+1;j<(2*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-limit]+1);
		}
	for (j=(2*limit)+1;j<(3*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-(2*limit)]+2);
		}
	for (j=(3*limit)+1;j<(4*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-(3*limit)]+3);
		}
	for (j=(4*limit)+1;j<(5*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-(4*limit)]+4);
		}
	for (j=(5*limit)+1;j<(6*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-(5*limit)]+5);
		}


//REVERSING THE STRING

	for(m=0;m<limit+1;m++)
		{
		hash2[m]=hash1[m];
		}
	for(m=limit+1;m<24;m++)
		{
		hash2[m]=hash1[24-m+limit];
		}



}


// ................ HASHING FOR LARGE URL SIZE

void hash132(char URL[200],char hash2[200],int size2,int limit){
	int i,j,m;
	limit =strlen(URL);
	int hash1[1000];
	hash1[0]=50+limit;


//LOOP FOR REPEATING

	for (i=1; i<limit+1; i++)
		{
		hash1[i]=(int)(URL[i-1]);
		}
	for (j=limit+1;j<(2*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-limit]+1);
		}
	for (j=(2*limit)+1;j<(3*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-(2*limit)]+2);
		}
	for (j=(3*limit)+1;j<(4*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-(3*limit)]+3);
		}
	for (j=(4*limit)+1;j<(5*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-(4*limit)]+4);
		}
	for (j=(5*limit)+1;j<(6*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-(5*limit)]+5);
		}
	for (j=(6*limit)+1;j<(7*limit)+1;j++)
		{
		hash1[j]=(int)(URL[j-1-(6*limit)]+6);
		}


//REVERSING THE STRING
	for(m=0;m<limit+1;m++)
		{
		hash2[m]=hash1[m];
		}
	for(m=limit+1;m<132;m++)
		{
		hash2[m]=hash1[132-m+limit];
		}

}


//BINARY CONVERTING FUNCTION
void binaryconvt(char url[], int arr[][9], int size){
	int temp,i;
	for(temp=0;temp<size;temp++){
		for(i=8;i>=0;i--){
			arr[temp][i]=url[temp]%2;
			url[temp]=url[temp]/2;
		}
	}
}



//POSITION FUNCTION FOR SMALL BOX
void positionid(int blackline[][38]){
	int i,j;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(i==0||i==20-1||j==0||j==20-1){
				blackline[i][j]=1;
			}else if((i>=2 && i<=5 && (j==2||j==5))|| (j>=2 && j<=5 && (i==2||i==5))){
				blackline[i][j]=1;
			}else if((i>=2 && i<=5 && (j==14||j==17))|| (j>=2 && j<=5 && (i==14||i==17))){
				blackline[i][j]=1;
			}else if((i>=14 && i<=17 && (j==2||j==5))|| (j>=14 && j<=17 && (i==2||i==5))){
				blackline[i][j]=1;
			}else{
				blackline[i][j]=0;
			}
		}
	}
}



//POSITION FUNCTION FOR LARGE BOX
void positionid2( int blackline[][38]){
	int i,j;
	for(i=0;i<38;i++){
		for(j=0;j<38;j++){
			if(i==0||i==38-1||j==0||j==38-1){
				blackline[i][j]=1;
			}else if((i>=2 && i<=5 && (j==2||j==5))|| (j>=2 && j<=5 && (i==2||i==5))){
				blackline[i][j]=1;
			}else if((i>=2 && i<=5 && (j==32||j==35))|| (j>=2 && j<=5 && (i==32||i==35))){
				blackline[i][j]=1;
			}else if((i>=32 && i<=35 && (j==2||j==5))|| (j>=32 && j<=35 && (i==2||i==5))){
				blackline[i][j]=1;
			}else{
				blackline[i][j]=0;
			}
		}
	}
}


void processchar24(int arr[][9], int URL[][38]){
	int k=0, l=0, num1, num2, i, j;

	for(num1=7; num1<17;num1=num1+3){
		for(num2=7; num2<17;num2=num2+3){
			for(i=num1;i<=num1+2;i++){
				for(j=num2;j<=num2+2;j++){
					if(arr[k][l]==1){
						URL[i][j]=0;
					}else{
						URL[i][j]=1;
					}l++;
				}
			}k++;
			l=0;
		}
	}
	for(num1=1; num1<5;num1=num1+3){
		for(num2=7; num2<11;num2=num2+3){
			for(i=num1;i<=num1+2;i++){
				for(j=num2;j<=num2+2;j++){
					if(arr[k][l]==1){
						URL[i][j]=0;
					}else{
						URL[i][j]=1;
					}l++;
				}
			}k++;
			l=0;
		}
	}
	for(num1=7; num1<11;num1=num1+3){
		for(num2=1; num2<5;num2=num2+3){
			for(i=num1;i<=num1+2;i++){
				for(j=num2;j<=num2+2;j++){
					if(arr[k][l]==1){
						URL[i][j]=0;
					}else{
						URL[i][j]=1;
					}l++;
				}
			}k++;
			l=0;
		}
	}
}

void processchar132(int arr[][9], int URL[][38]){
	int k=0, l=0, num1, num2, i, j;

	for(num1=7; num1<35;num1=num1+3){
		for(num2=7; num2<35;num2=num2+3){
			for(i=num1;i<=num1+2;i++){
				for(j=num2;j<=num2+2;j++){
					if(arr[k][l]==1){
						URL[i][j]=0;
					}else{
						URL[i][j]=1;
					}l++;
				}
			}k++;
			l=0;
		}
	}
	for(num1=1; num1<5;num1=num1+3){
		for(num2=7; num2<31;num2=num2+3){
			for(i=num1;i<=num1+2;i++){
				for(j=num2;j<=num2+2;j++){
					if(arr[k][l]==1){
						URL[i][j]=0;
					}else{
						URL[i][j]=1;
					}l++;
				}
			}k++;
			l=0;
		}
	}
	for(num1=7; num1<31;num1=num1+3){
		for(num2=1; num2<5;num2=num2+3){
			for(i=num1;i<=num1+2;i++){
				for(j=num2;j<=num2+2;j++){
					if(arr[k][l]==1){
						URL[i][j]=0;
					}else{
						URL[i][j]=1;
					}l++;
				}
			}k++;
			l=0;
		}
	}
}
void oneboxprint(char new[9]){
	if (strcmp(new,"black")==0){
		printf(black "  " );
	}
	else if(strcmp(new,"red")==0){
		printf(red "  " );
	}
	else if(strcmp(new,"green")==0){
		printf(green "  " );
	}
	else if(strcmp(new,"yellow")==0){
		printf(yellow "  " );
	}
	else if(strcmp(new,"magenta")==0){
		printf(magenta "  " );
	}
	else if(strcmp(new,"cyan")==0){
		printf(cyan "  " );
	}
	else if(strcmp(new,"blue")==0){
		printf(blue "  " );
	}
}



int main(int argc, char *argv[]){

	char Backcolor[7][9]={"black","red","green","yellow","blue","magenta","cyan"};
	char ActualColor[9];

	if(argc==3){
		if(strcmp(argv[1],"-c")==0){
			if(strcmp(argv[2],"black")==0){
				strcpy(ActualColor,Backcolor[0]);
			}
			else if(strcmp(argv[2],"red")==0){
				strcpy(ActualColor,Backcolor[1]);
			}
			else if(strcmp(argv[2],"green")==0){
				strcpy(ActualColor,Backcolor[2]);
			}
			else if(strcmp(argv[2],"yellow")==0){
				strcpy(ActualColor,Backcolor[3]);
			}
			else if(strcmp(argv[2],"blue")==0){
				strcpy(ActualColor,Backcolor[4]);
			}
			else if(strcmp(argv[2],"bmagenta")==0){
				strcpy(ActualColor,Backcolor[5]);
			}
			else if(strcmp(argv[2],"cyan")==0){
				strcpy(ActualColor,Backcolor[6]);
			}
			else if(strcmp(argv[2],"black")!=0||strcmp(argv[2],"red")!=0||strcmp(argv[2],"green")!=0||strcmp(argv[2],"yellow")!=0||strcmp(argv[2],"blue")!=0||strcmp(argv[2],"magenta")!=0||strcmp(argv[2],"cyan")!=0){
				printf("Invalid argument for color.\n");
				printf("usage:\n");
				printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
				printf("%s -h for the help about the program\n",argv[0]);
			return 0;
			}
		}

		else{
			printf("usage:\n");
			printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
			printf("%s -h for the help about the program\n",argv[0]);
		}
	}
	else if(argc==1){
		strcpy(ActualColor,Backcolor[0]);
	}
	else if(argc==2){
		if(strcmp(argv[1],"-h")==0){
			printf("usage:\n");
			printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
			printf("%s -h for the help about the program\n",argv[0]);
			return 0;
	}
		else{
			printf("Incorrect usage of arguments");
			printf("usage:\n");
			printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
			printf("%s -h for the help about the program\n",argv[0]);
			return 0;
		}
	}else if(argc>3){
		printf("Incorrect usage of arguments");
		printf("usage:\n");
		printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argv[0]);
		printf("%s -h for the help about the program\n",argv[0]);
		return 0;
	}


	char URL[120], URL20[SIZE1], URL120[SIZE2];
	int i,j;
	int printUrlS[20][38], printUrlL[38][38], charConS[SIZE1][9], charConL[SIZE2][9];

	printf("Enter your URL: ");
	int x=scanf("%s", URL);
	//Erase Display
	printf("\033c");

	int urllen=strlen(URL);

	if(x==-1 || urllen>120 || urllen<3){
		printf("String is too long. Not supported by available QR versions\n");
		return 0;
	}

	if(x==-1 || urllen<3){
		printf("String is too short. Not supported by available QR versions\n");
		return 0;
	}

	if(urllen<20){
		hash24(URL, URL20, SIZE1, urllen);
		binaryconvt(URL20,charConS,SIZE1);
		positionid(printUrlS);
		processchar24(charConS, printUrlS);

		for(i=0; i<20;i++){
			for(j=0;j<20;j++){
				if(printUrlS[i][j]==1){
					printf(white  "  " );
				}else{
					oneboxprint(ActualColor);
				}
			}printf("\n");
		}
   printf(reset);
	}else{
		hash132(URL, URL120, SIZE2, urllen);
		binaryconvt(URL120,charConL,SIZE2);
		positionid2( printUrlL);
		processchar132(charConL, printUrlL);

		for(i=0; i<38;i++){
			for(j=0;j<38;j++){
				if( printUrlL[i][j]==1){
					printf(white  "  " );
				}else{
					oneboxprint(ActualColor);
				}
			}printf("\n");
		}
		printf(reset);
	}




	return 0;


}

//TETTOLIZER
