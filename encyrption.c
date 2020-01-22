#include <stdio.h>
#include <stdlib.h>
//note that there is no use of string library foe educational purposes , however u should use it 
int get_stringlen(char* str_name ){
 int i=0; // counter & a string function to find null
 while(str_name[i++]!='\0')
 return i;}

int main(){
char massage[81]; char enco[162];
 //insert the string
scanf("%s",massage);
rewrite_string(massage,enco); //it's an embedded practice to sent the output as an argument to the function instead of taking it back
printf("%s",enco);
 return 0;}

void rewrite_string(char * str ,char * enco){
int len , rows , cols ,count=0; double l ;
char mess[9][81]; //9 is sqrt root of 81 , it's better to malloc this function with rows instead of 9
//get string length
L=get_stringlen(massage);
rows=(int) floor(sqrt(L));
cols=(int) ceil(sqrt(L));
while(rows*cols<L){if(cols>rows){rows++;} else {cols++;}} //make sure that rows*cols>stringlen
if(rows*cols>len)for(int i=len ; i<=rows*cols ; i++){
    str[i]='0'; //fill the string with 0 instead of nulls , it will be removed later
} //devide the string into rows word each equal to cols letters
for(int k=0 ; k<=rows ;k++ ){
for(int i=0; i<cols;i++){
mess[k][i]=str[k*cols+i];
}}

for(int k=0 ; k<cols ;k++ ){
for(int i=0; i<rows;i++){
if(mess[i][k]!='0'){enco[count++]=mess[i][k];}} //reverse the order for exm n word will n letter of each word
enco[count++]=(" ");} //addspace after each rows letter
enco[count]='\0'; //manually termniate string
 }
