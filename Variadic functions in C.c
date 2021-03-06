#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>



int sum(int count, ...){
int acc=0;
va_list sumptr; //starting a pointer to a va_list ( implementation built in GNU compiler )
va_start (sumptr,count); //assigning the pointer to the first address of the argument list
for ( int i=0 ; i<count; i++){acc+=va_arg(sumptr,int);} //note that every call to the va_arg increases the sumptr by 1 , and this implementation doesn't allow to access back arg elements , however you can save va_list in a dynamic array
va_end(sumptr); // free the pointer to re-use 
return acc;}

int min(int count, ...){
int minm, temp;
va_list sumptr;
va_start (sumptr,count);
minm=va_arg(sumptr,int); //as mentioned above this element[0]
for ( int i=0 ; i<count; i++){
        temp=va_arg(sumptr,int);
        if (minm>temp){minm=temp;}}
va_end(sumptr);
return minm;}
int max(int count, ...){
int maxm, temp;
va_list sumptr;
va_start (sumptr,count);
maxm=va_arg(sumptr,int);
for ( int i=0 ; i<count; i++){
        temp=va_arg(sumptr,int);
        if (maxm<temp){maxm=temp;}}
va_end(sumptr);
return maxm;}
int test_implementations_by_sending_three_elements(void) {
    srand(time(NULL));

    int elements[3];

    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

    fprintf(stderr, "Sending following three elements:\n");
    for (int i = 0; i < 3; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }

    int elements_sum = sum(3, elements[0], elements[1], elements[2]);
    int minimum_element = min(3, elements[0], elements[1], elements[2]);
    int maximum_element = max(3, elements[0], elements[1], elements[2]);

    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);

    int expected_elements_sum = 0;
    for (int i = 0; i < 3; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }

        if (elements[i] > maximum_element) {
            return 0;
        }

        expected_elements_sum += elements[i];
    }

    return elements_sum == expected_elements_sum;
}

int test_implementations_by_sending_five_elements(void) {
    srand(time(NULL));

    int elements[5];

    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

    fprintf(stderr, "Sending following five elements:\n");
    for (int i = 0; i < 5; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }

    int elements_sum = sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    int minimum_element = min(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    int maximum_element = max(5, elements[0], elements[1], elements[2], elements[3], elements[4]);

    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);

    int expected_elements_sum = 0;
    for (int i = 0; i < 5; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }

        if (elements[i] > maximum_element) {
            return 0;
        }

        expected_elements_sum += elements[i];
    }

    return elements_sum == expected_elements_sum;
}

int test_implementations_by_sending_ten_elements(void) {
    srand(time(NULL));

    int elements[10];

    elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[5] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[6] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[7] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[8] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
    elements[9] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

    fprintf(stderr, "Sending following ten elements:\n");
    for (int i = 0; i < 10; i++) {
        fprintf(stderr, "%d\n", elements[i]);
    }

    int elements_sum = sum(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    int minimum_element = min(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);
    int maximum_element = max(10, elements[0], elements[1], elements[2], elements[3], elements[4],
                           elements[5], elements[6], elements[7], elements[8], elements[9]);

    fprintf(stderr, "Your output is:\n");
    fprintf(stderr, "Elements sum is %d\n", elements_sum);
    fprintf(stderr, "Minimum element is %d\n", minimum_element);
    fprintf(stderr, "Maximum element is %d\n\n", maximum_element);

    int expected_elements_sum = 0;
    for (int i = 0; i < 10; i++) {
        if (elements[i] < minimum_element) {
            return 0;
        }

        if (elements[i] > maximum_element) {
            return 0;
        }

        expected_elements_sum += elements[i];
    }

    return elements_sum == expected_elements_sum;
}

int main (void)
{
    int number_of_test_cases;
    scanf("%d", &number_of_test_cases);

    while (number_of_test_cases--) {
        if (test_implementations_by_sending_three_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }

        if (test_implementations_by_sending_five_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }

        if (test_implementations_by_sending_ten_elements()) {
            printf("Correct Answer\n");
        } else {
            printf("Wrong Answer\n");
        }
    }

    return 0;
}
