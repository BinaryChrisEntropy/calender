#include <stdio.h>


void main(void) {
    char *calender = NULL;
    int month;
    for(;;) {
        printf("%s\n", "Enter a month: 1 to 12 or 0 to quit");
        scanf("%d", &month);

        switch (month)
        {
            case 0:
                printf("\n Good Bye!");
                goto end;
            case 1:
                printf("%s", "Jan.\n");
                break;
            
            default:
                printf("Something went wrong. Check you input next time. Range: 1-12\n");
        }
    }
end:
}