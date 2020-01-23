#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
double s_array[100][2];double temp , temp2;
triangle* tem=malloc(n * sizeof(triangle));
for(int i=0; i <n ; i++){tem[i].a=tr[i].a;tem[i].b=tr[i].b;tem[i].c=tr[i].c;}
for (int i=0 ; i<n ; i++){
    s_array[i][0]=(double)(tr[i].a+tr[i].b+tr[i].c)/2;
    s_array[i][0]= s_array[i][0]*( s_array[i][0]-tr[i].a)*( s_array[i][0]-tr[i].b)*( s_array[i][0]-tr[i].c);
     s_array[i][0]= sqrt(s_array[i][0]);
    s_array[i][1]=i;
    //s_array[i][0]= (int) sqrt((double)s_array[i][0]);
}
    for (int i=0; i<n;i++){
         for (int j = 0; j < n-1; j++) {
            if(s_array[j][0] > s_array[j+1][0]){
                temp = s_array[j+1][0];
                s_array[j+1][0] = s_array[j][0];
                s_array[j][0] = temp;
                temp2=s_array[j+1][1];
                s_array[j+1][1]=s_array[j][1];
                s_array[j][1]=temp2;}}}
    for (int i=0 ; i<n ; i++){
 tr[i]=tem[(int)s_array[i][1]];
}
free(tem);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
