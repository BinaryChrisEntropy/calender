#include <stdio.h>
#include <stdlib.h>

struct month {
    char *name;
    int n_days;
    void (*print)(char *, int);
};


typedef struct month Month;
char *names[] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dez"};
int n_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void print_month(char* name, int n_days) {
    printf("%s", name);
    for(int i=0; i < n_days; i++) {
        if(i %7 == 0)
            printf("%s", "\n");
        if(i < 9)
            printf("%d  ", i+1);
        else
            printf("%d ", i+1);
    }
    printf("%s", "\n");
}

void init_calender(Month cal[]) {
    for(int i=0; i < 12; i++) {
        Month m = {.name = names[i] + '\0', .n_days = n_days[i], .print = print_month};
        cal[i] = m; 
    }
}

void print(Month cal[], int month) {
    cal[month].print(cal[month].name, cal[month].n_days);
}



void main(void) {
    Month calender[12];
    init_calender(calender);
    
    int val;
    for(;;) {
        printf("%s\n", "Enter a month: 1 to 12 or 0 to quit");
        scanf("\n%d", &val);
        while(getchar() != '\n'); 
        
        if(val < 1 || val > 12) {
            printf("%s", "Error, check your input!!!");
        } else {
            print(calender, val-1);
       }
    }
end:
}



