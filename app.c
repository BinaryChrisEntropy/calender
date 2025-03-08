#include <stdio.h>
#include <stdlib.h>

int* create_month(int n_days) {
    int* c = (int*) malloc(n_days * sizeof(int));
    for(int i=0; i < n_days; i++) {
        c[i] = i + 1;
    }
    return c;
}

void print_month(int* month) {
    for(int i=0; i < 31 ; i++) {
        if(i % 7 == 0)
            printf("\n");
        if(i + 1 < 10)
            printf("%d  ", month[i]);
        else
            printf("%d ", month[i]);
    }
    printf("\n");
}


void main(void) {
    int *calender = NULL;
    int month;
    for(;;) {
        printf("%s\n", "Enter a month: 1 to 12 or 0 to quit");
        scanf("%d", &month);

        switch (month)
        {
            case 0:
                printf("\nGood Bye!");
                goto end;
            case 1:
                printf("%s", "Jan.\n");
                int* m = create_month(31);
                print_month(m);
                break;
            
            default:
                printf("Something went wrong. Check you input next time. Range: 1-12\n");
        }
    }
end:
}