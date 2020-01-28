#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct querie{
    int x;
    int y;
};
typedef struct querie querie;
//double array can be used but I like structs

int is_even (int x){ //for readabillity 
int temp=0;
if (x>1) {if (x%2==0) {temp=1;}} //this is supposed to be boolean but C standard doesn't support , unless you made you're boolean type don't use bool
if(x==0){temp=1;} //0 is considered even 
return temp;}
//didn't really used this function , and you don't even need it , but here it is if you like to waste your time
int find (int* A,int x , int y,int arr_count){
int ans;
    if(arr_count<y){return 1;}
    if(x>y) return 1;
    if(A[x]==0) return 1;
    if(x+1>arr_count) return A[x];
    ans = pow(A[x],find(A,x+1,y,arr_count));
    return ans;}

char * solve(int* arr,int arr_count,int x,int y) { //always return odd unless arr[x] is even 
  const char * evn="Even"; const char* odd="Odd";int result;
  if(y>arr_count){result=1; return odd;} //this is called defensive programming in case you're not sure that input follow constrain , don't use defensive programming if you use that code without that statment it will work absloutley fine
  if(x>y){result=1;return odd;} //again not needed as above
  if(arr[x]==0){result=2;return evn;} //o to any power is still 0 and is even 
  if(x+1>y){result=arr[x];} //if x+1 doesn't exist , we will have arr[x] to power 1 
  else{if (is_even(arr[x])) //if a[x] is an even number to begin with it can only turn odd to the power 0 , a[x]^0=1 , so check next
     {if(arr[x+1]!=0){result=2;return evn;} //we made sure that x+1 does exist , if it's not 0 then the number is even 
       else{result=1 ;return odd;} }} //otherwise it is odd
  if (is_even(result)) {return evn;} //following 35 , if there is no next operations check if a[x] is even or odd
  else{return odd ;}} //note that multiple returns is against misra C++ 2004 standards , and not the best programming practice

int main()
{int N ,tmp1, Q;
int* dynarr; int * dynamicarray;
querie* queieres; char * result;
    scanf("%d",&N); //array size
    dynarr=(int*) malloc(sizeof(int)*N); //don't forget to free otherwise it will crash in a few tests , also don't use dynaimc arrays in limted or constrained enviroment unless asked to
    for(int i=0 ; i<N ; i++){ 
        scanf("%d",&tmp1);
        if(tmp1>=0){ //aslo defensive programming , sometimes hr tests with constrains or bulid the programm based on it , so it becomes program constrains and are tested in input 
            if(tmp1<10){dynarr[i]=tmp1;}
            else {
                 dynarr[i]=tmp1/10; //in case the stupid user forgets one space , it can't handle 2 and is not needed , just showing you what to do , you should seprate by n-1 steps 
                 i++;
                 dynarr[i]=tmp1%10;}}
        else { i++;}
    }
    dynamicarray=dynarr-1; //the array is -1 indexed , I ignored this in case you are using specfic functions , however I solved it with renaming the pointer 
 scanf("%d",&Q);
 queieres=(querie*) malloc(sizeof(querie)*Q);
   for(int i=0 ; i<Q ; i++){
        scanf("%d",&queieres[i].x); //you can use queieres[i].[0] instead , however they r exatcly the same 
        scanf("%d",&queieres[i].y);}
           for(int i=0 ; i<Q ; i++){
                //solve queire by queire
            result=solve(dynamicarray,N,queieres[i].x,queieres[i].y);
           printf("%s \n",result);
 }
 free(dynarr);free(queieres);
    return 0;
}

