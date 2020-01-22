#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include "datatypes.h"

int main(){
char massage[81]; char enco[162];int L , rows , cols; double l ;
//insert the string
printf("please enter string ");
scanf("%s",massage);
//get string length
L=get_stringlen(massage);
rows=(int) floor(sqrt(L));
cols=(int) ceil(sqrt(L));
rewrite_string(massage,enco,L,rows,cols);
for(int i=0 ; i<L+cols ; i++){printf("%c",enco[i]);}
printf("%d",L);
//printf("%s %d %d",enco,rows,cols);

 return;}
int get_stringlen(char* str_name ){
 int i=0; // counter & a string function to find null
 while(str_name[i]!='\0'){i++;}return i;}
 void rewrite_string(char * str ,char * enco, int len , int rows, int cols ){
     //repeat the process rows time
     for(int i=0 ; i<len ; i++){
 for (int k=0 ; k<cols; k++){
    for (int j = 0; j <=rows ; j++ ){
    enco[j+k*cols]=str[k+j*cols];}}
   int * p=&len; *p=i;
   }

//put a space here

 }
