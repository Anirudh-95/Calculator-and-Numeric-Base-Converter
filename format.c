#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

/*This method is used to return the string in reverse for the conversion */
char* string_reverse(char* s){
  int i;
  int l=strlen(s);
  char *ns=malloc(l);//creating a new string to store the reversed string
  int j=(l-1);
  for(i=0;i<l;i++){ //iterating through the string 
    ns[i]=s[j]; //storing the string in reverse order in new string 
    j--;
  }
  return ns; //returning the reversed string 
}

/*Method that gets the mantissa value for the float conversion and 
 accepts a string of 23 characters for the conversion*/
float get_mantissa(char *s){
  float mantissa= 0;
  int digit=1;
  int i= 0;

  while(s[i]!='\0'){
      if(s[i]=='1'){
        mantissa= mantissa+ (1.0/(1<<(digit)));
      }
      digit=digit+1;
      i=i+1;
    }
  return mantissa;
}
/*This is the method where the binary to integer via the 2's complement takes 
  place and the converted number is returned*/
int Bin_Int(char *s) {
  int i;
  int converted=0; // to store the converted int value 
  int power=0;
  int digit=0;
  
  for (i = 0; i<32; i++){ //iterating through the entire string
    //if statements to get the int value of the binary 
    if(s[i]=='1' && digit==32){
      converted=converted-pow(2, power);
    }
    else if(s[i]=='1'){
      converted=converted+pow(2, power);
    }
    digit++;
    power++;
  }
  return converted; //retunring converted value back to the required fuction
}

/*Method to convert the Binary number to a floating point variable 
 and then displaying the output */
 
 float Bin_Float(char *s, int exp){
   //getting the sign for the converted number
   int sign=1;
   if(s[0]=='1'){
      sign=-1;
    }

   char sv[23];//char array to store the 23 digits in the mantissa 
   int loop;
   int innervalue=9;
   
   //copying the mantissa values into the array
   for(loop=0;loop<23;loop++){
      sv[loop]=s[innervalue];
      innervalue++;
    }

   float returnedvalue=get_mantissa(sv);//getting the mantissa value from the "get_mantissa" function
   float floatVal=(returnedvalue+1)*pow(2,exp); //calculating the actual floating point number
   
   int p=0;
   //print the final converted value with the exponent and normalizing the numbers 
   if(floatVal==0){
      floatVal=floatVal*sign;
      printf("%fe%i \n", floatVal,p);
    }
   else if(floatVal>1){
      while(floatVal>1.0){
         p--;
         floatVal=floatVal/10;
      }
       floatVal=floatVal*10*sign;
       printf("%fe%i \n", floatVal,p+1);
    }
   else{
      while(floatVal<1){
         floatVal=floatVal*10;
         p++;
      }
      floatVal=floatVal*sign;
      printf("%fe%i \n",floatVal , p*-1);
    }

  return returnedvalue;
}

/* main where all the functions are executed sequentially and the errors are checked*/
int main(int argc, char **argv){
  //to check for the correct number of arguments 
  if(argc!=3){
     fprintf(stderr, "ERROR: INVALID NUMBER OF ARGUMENTS \n" );
    return 0;
  }
  
  int l=strlen(argv[1]);
	char rs[l];
  strcpy(rs,string_reverse(argv[1]));
  char s1[l];
  strcpy(s1,argv[1]);
  
  int i;
  int q=7;
  int exp=0;
  for(i=1; i<9;i++){
    if(s1[i]== '1'){
       exp=exp+pow(2,q);
       } 
      q--;
  }
  exp=exp-127; 

int sign=0;
   if(s1[0]=='1'){
      sign=1;
    }
   char sv[23];//char array to store the 23 digits in the mantissa 
   int loop;
   int innervalue=9;
   //copying the mantissa values into the array
   for(loop=0;loop<23;loop++){
      sv[loop]=s1[innervalue];
      innervalue++;
    }
   float mantissa = get_mantissa(sv) ;

   //if statements to print out ninf, pinf, NaN etc
   if(exp==128 && sign == 1 &&  mantissa == 0.000000) {
    printf("ninf\n");
    return 0;
  }
  if(exp==128 && sign == 0 &&  mantissa == 0.000000) {
    printf("pinf\n");
    return 0;
  }
  if(exp==128 && sign == 1 &&  mantissa != 0) {
    printf("-NaN\n");
    return 0;
  }
  if(exp==128 && sign == 0 &&  mantissa != 0) {
    printf("+NaN\n");
    return 0;
  }
  if(exp==-127 && sign == 1 && mantissa == 0) {
    printf("-0.0e0\n");
    return 0;
  }
  if(exp==-127 && sign == 0 && mantissa == 0) {
    printf("+0.0e0\n");
    return 0;
  }

  //send the string for the approriate output else outputting an error 
	if(strcmp(argv[2], "int")==0){
	     long converted=Bin_Int(rs);
	     printf("%ld\n",converted);
    }
  else if(strcmp(argv[2], "float")==0){
       Bin_Float(s1, exp);
  }
  else { 
    	printf("ERROR: INVALID INPUT FOR TYPE\n");
   } 

   
	return 0;
}