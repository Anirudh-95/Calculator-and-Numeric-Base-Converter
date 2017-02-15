#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* This is struct that is created to store the sign and type of each number */
struct calcC_ {
	char *sign;
	char *type;
};

typedef struct calcC_ calcC;

/* This is the method where the addition of the two numbers takes place and 
it returns the sum back to main*/

long int add(long int n1, long int n2, char ch1, char ch2){
	long int sum; //variable to store the sum
	
	if(ch1=='-' && ch2=='+')
	   sum=-n1+n2;
	else if(ch2=='-' && ch1=='+')
	   sum=n1-n2;
	else if(ch1=='-' && ch2=='-')
		sum=-n1-n2;
	else 
        sum= n1+n2;


	return sum; // returning the sum back to main 
}

/* This is the method where the subtraction of the two numbers takes place and 
it returns the difference back to main*/
long int subtract(long int n1, long int n2, char ch1, char ch2){
	long int difference; //variable to store the difference
	if(ch1=='-' && ch2=='+')
	   difference=-n1-n2;
	else if(ch2=='-' && ch1=='+')
	   difference=n1+n2;
	else if(ch1=='-' && ch2=='-')
		difference=-n1+n2;
	else 
        difference= n1-n2;

	return difference; // returning the difference back to main 
}

/* This method accepts a decimal number and converts it into its equivalent binary value */
int Dec_Bin(int n){
	int l=sizeof(n);
	int bin[l]; //creating an array of the size of the number to strore the converted number
	int i=0;
	//code for converting from decimal to binary 
	while(n!=0){
		bin[i] = n%2;
		n=n/2;
		i++;
	}
	i--;
	long int  binaryvalue=0;
	// creating a single binary from the array containing all the numbers seperately 
	while(i>=0){
		binaryvalue=(10*binaryvalue)+ bin[i];
		i--;
	}
	return binaryvalue; //returning the binary value back to the main
}
/* This method accepts a decimal number and converts it into its equivalent octal value */
int Dec_Oct(int n){
  long int l=sizeof(n);
  int octal[l];
  int i=0;
  // code for converting from a decimal to octal number
  while(n!=0){
      octal[i++]= n%8;
      n=n/8;
  }
  i--;
  int  octalvalue=0;
  //creating a single octal number from the array containg the different parts of the octal number	
  while(i>=0){
		octalvalue=(10*octalvalue)+ octal[i];
		i--;
	}
	return octalvalue; //returning the octal value back to the main method	
}

/* This method accepts a decimal number and converts it into its equivalent hexadecimal value */
long int Dec_Hex(long int nsent){
    int i=1,j,temp;
    int l=sizeof(nsent);
    long int n;
    char hexadecimalNumber[l]; //char array to store the different parts of the hexadecimal value
    //code to convert from decimal number to hexadecimal number
    if(nsent<0){
    	n=-nsent;
    }
    else{
     n=nsent;
    }
    while(n!=0){
      temp = n%16;
      if(temp<10){
           temp=temp+48;
      }
      else{
         temp=temp+55;
      }      
      hexadecimalNumber[i++]= temp;
      n= n/16;

  }
  	//printing the hexadecimal value
    if(nsent<0){
    	printf("-x");
    }
    else{
    	printf("x");
    }
    for(j = i -1 ;j> 0;j--){
      printf("%c",hexadecimalNumber[j]);
    }
  	printf("\n");
    return 0;
}

/* This method accepts a hexadeciaml number and converts it into its equivalent decimal value */
long int Hex_Dec(char *n){
	long int decimalNumber=0;
    int i=0;
    int power=0;
    int j;
    char hexchar[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    char ch;
    //code to convert from hexadecimal to decimal value
    for(i=(strlen(n)-1);i>=0;i--){
    	ch=n[i];
    	for(j=0;j<16;j++){
    	  if(ch==hexchar[j]){
          decimalNumber=decimalNumber+(j*pow(16,power));
          power++;
       }
     }
    }
   return decimalNumber;//returning the decimal number back to the main method
}
/* This method accepts a octal number and converts it into its equivalent decimal value */
long int Oct_Dec(long int n){
    long int decimalNumber=0;
    int i=0;
    //code to convert from octal to decimal value
    while(n!=0){
         decimalNumber=decimalNumber+((n%10)*pow(8,i));
         i++;
         n=n/10;
    }
   return decimalNumber;//returning the decimal number back to the main method
}

/* This method accepts a binary number and converts it into its equivalent decimal value */
long  Bin_Dec(long int n){
    long  decimalNumber=0;
    long int j=1;
    long int remainder;

    //code to convert from binary to decimal value 
    while(n!=0){
        remainder=n%10;
        decimalNumber=decimalNumber+(remainder*j);
        j=j*2;
        n=n/10;
    }

    return decimalNumber; //returning the decimal number back to main
}
            
/* THis method converts the string value in the command line to an integer value */                                                                                                                 
long int stringconvert(char *s){
	long int convert = 0; 
	int i;

    for (i = 0; s[i] != '\0';i++){
        convert = convert*10 + s[i] - '0';
		}  

    return convert; //returning the converted integer value
}

/* This method checks for errors in the command line and returns 
    0 for error and 1 if it is not an error */

char Error_check(char *s, int l){
	int boolean=1; //intializing the flag to 1	
	char ch;

	if(s[0]=='+' || s[0]=='-'){
		ch=s[1];
	}
	else {
		ch=s[0];
	}


	if(ch=='b'){ //binary number check
		int i;
		for(i=2;i<l;i++){
			if(s[i]=='0' || s[i]=='1'){
				boolean=1;
			}
			else{
				boolean=0;
				break;
			}
	    }
    }

	else if(ch=='d'){ //decimal number check
		int i;
		for(i=2;i<l;i++){
			if(isdigit(s[i])){
				boolean=1;
			}
			else{ 
	      	boolean=0;
	      	break;
	        }
	    }
	}

	else if(ch=='o'){ //octal number check
		int i;
		for(i=2;i<l;i++)
			if(s[i]=='0' || s[i]=='1'|| s[i]=='2'|| s[i]=='3'|| s[i]=='4'|| s[i]=='5'|| s[i]=='6'|| s[i]=='7'){
				boolean=1;
			}
			else{
				boolean=0;
				break;
			}
	}

	else if(ch=='x'){//hexadecimal number check
		int i;
		for(i=2;i<l;i++){
			if(isxdigit(s[i])){
				boolean=1;
			}
			else {
				boolean=0;
				break;
			}
		}	
	}
	else{
		boolean=0;
	}
	return boolean;
}
/*method to free the memory in the structs created */
void calcDestroy( calcC * num ) {
  free (num->type);
  free (num->sign);
}

/* main method where the numbers are sent to respective methods for conversions 
   arithmetic operations and final output to be displayed */
int main(int argc, char **argv){
	
	if(argc!=5){
		fprintf(stderr, "ERROR: INCORRECT NUMBER OF ARGUMENTS\n");
		return 0;
	}

	int i=0;
	int l1=strlen(argv[2]); // finding the length of the first number 
	char s1[l1];
	strcpy(s1,argv[2]);//copying the first number to s1
	char a1[l1];

	int k=0;
	int l2=strlen(argv[3]); //finding the length of the second number
	char s2[l2];
	strcpy(s2,argv[3]); //copying the second number into s2
	char a3[l2];
	
	if(strcmp(argv[1],"+")==0 || strcmp(argv[1],"-")==0 ){
		//
	}
	else{
		fprintf(stderr, "ERROR: DOES NOT GIVE THE REQUIRED OPERATION\n");
		return 0;
	}

	//if-else statements for error checks to occur
	if(Error_check(s1,l1)==0 || Error_check(s2,l2)==0){
		fprintf(stderr, "ERROR: INVALID INPUT FOR ONE OF THE NUMBERS \n ");
	}
	else{
   	  char outputtype[1]; //variable to store the output type
	  strcpy(outputtype,argv[4]);// copying the output type into the variable

 	  calcC* number1; //creating a struct for number 1
	  calcC* number2; //creating a struct for  number 2
	  //allocatiing memory for both the structs 
	  number1 = (calcC*)malloc(sizeof(calcC));   
	  number2 = (calcC*)malloc(sizeof(calcC));
	
	  number1->type = ((char*)malloc(sizeof(char)*1));
	  number2->type = ((char*)malloc(sizeof(char)*1));
      number1->sign = ((char*)malloc(sizeof(char)*1));
	  number2->sign = ((char*)malloc(sizeof(char)*1));

	  if(s1[0]=='-' || s1[0]=='+'){
	    *number1->sign=s1[0];
      	*number1->type=s1[1];
      }
      else{
        *number1->sign= '+';
        *number1->type=s1[0];
      }

      if(s2[0]=='-'|| s2[0]=='+'){
	    *number2->sign= s2[0];
	    *number2->type=s2[1];
	  }
	  else{
		*number2->sign= '+';
		*number2->type=s2[0];
	  }

	  //storing digits of number1 into a another string 
	  int t;
	  if(s1[0]=='-' || s1[0]=='+'){
	  	t=2;
	  }
	  else 
	  	t=1;

	  while((t-2)<l1){
	    a1[i]=s1[t];
	    i++;
	    t++;
	  }
	  long int a2 = stringconvert(a1); //converting the method to a method to be converted
	  
	  //storing the digits of number2 into another string 
	  int r;
	  if(s2[0]=='-' || s2[0]=='+'){
	  	r=2;
	  }
	  else 
	  	r=1;

	  while((r-2)<l2){
	    a3[k]=s2[r];
	    k++;
	    r++;
	  }
	  long int a4 = stringconvert(a3); //converting the string to a method to be converted 
	  
	  //creating variables to store the converted values of both the numbers
	  long int converted_number1=0;
	  long int converted_number2=0;
	
	  //check the type of the number1 and send to correct method to be converted in to equivalent decimal value
	  if(*number1->type=='b'){
		converted_number1=(Bin_Dec(a2));
	  }
	  else if(*number1->type=='o'){
		converted_number1=(Oct_Dec(a2));
	  }
	  else if(*number1->type=='x'){
	   int k;
       char s[l1];
       for(k=0;k<strlen(a1);k++){
    	      s[k]=tolower(a1[k]);
       }
	   converted_number1=(Hex_Dec(s));
	  }
	  else{
		converted_number1=a2;
	  }
	
	//check the type of the number2 and send to correct method to be converted in to equivalent decimal value
	  if(*number2->type=='b'){
		converted_number2=(Bin_Dec(a4));
	  }
	  else if(*number2->type=='o'){
		converted_number2=(Oct_Dec(a4));
	  }
	  else if(*number2->type=='x'){
       int k;
       char s[l2];
       for(k=0;k<strlen(a3);k++){
    	      s[k]=tolower(a3[k]);
       }
		converted_number2=(Hex_Dec(s));
	  }
	  else{
		converted_number2=a4; 
	  }

	  long int output=0;
	  // checks command line for the arithmetic operation to be performed and sends it to that method
	  if(*argv[1]=='+'){
		output=add(converted_number1, converted_number2, *number1->sign, *number2->sign);
	  }
	  else if(*argv[1]=='-'){
		output=subtract(converted_number1, converted_number2, *number1->sign, *number2->sign);
	  }
	 /* checls the ouputtype and sends the deciamal value to required method to be 
	    converted into type of the desired ouput */
	 if(*outputtype=='b'){
		printf("b%i\n", Dec_Bin(output));
      }
	  else if(*outputtype=='o'){
		printf("o%i\n", Dec_Oct(output));
      }
      else if(*outputtype=='x'){
		Dec_Hex(output);
      }
      else if(*outputtype=='d'){
    	if(output<0){
    		printf("-d%ld\n", -output);
        }
        else{
        	printf("d%ld\n",output );
        }
     }
      else{
      	fprintf(stderr,"ERROR: INVALID OUTPUT TYPE \n");
      }
   calcDestroy(number1);
   calcDestroy(number2);
 }
 return 0;
}
//end of the program 