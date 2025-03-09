#include <stdio.h>
#include <stdlib.h>

struct month {
    char *name;
    int n_days;
    void (*print)(int);
};


typedef struct month Month;
const char *names[] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dez"};
const int n_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void print_month(int n_days) {
    printf("\n%d\n", n_days);
}

void init_calender(Month cal[]) {
    for(int i=0; i < 12; i++) {
        Month m = {.name = names[i] + '\0', .n_days = n_days[i], .print = print_month};
        cal[i] = m; 
    }
}

void print(Month cal[], int month) {
    cal[month].print(cal[month].n_days);
}



void main(void) {
    const Month calender[12];
    init_calender(calender);
    
    int val;
    for(;;) {
        printf("%s\n", "Enter a month: 1 to 12 or 0 to quit");
        scanf("%d", &val);

        switch (val)
        {
            case 0:
                goto end;
            case 1:
                print(calender, val-1);
                break;
            case 2:
                print(calender, val-1);
                break;
            case 3:
                print(calender, val-1);
                break;
            case 4:
                print(calender, val-1);
                break;
            default:
                printf("Something went wrong. Check you input next time. Range: 1-12\n");
        }
    }
end:
}