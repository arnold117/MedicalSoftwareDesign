#include "hl7.h"

int main()
{
    struct hl7_part_t* msgs;
    struct hl7_location_t* location;
    struct hl7_location_t* current;
    char s[16000];
    char* s2, * s3, * s4;
    FILE* stream;
    int i;

    if (!(current = location = (struct hl7_location_t*)malloc(sizeof(struct hl7_location_t)))) { exit(1); }
    current->next = (struct hl7_location_t*)0;
    current->count = 0;

    for (i = 0; i < 3; i++) {
        if (!(current->next = (struct hl7_location_t*)malloc(sizeof(struct hl7_location_t)))) { exit(1); }
        current = current->next;
        current->next = (struct hl7_location_t*)0;
        current->count = 0;
    }

    location->count = 0;
    location->next->count = 1;
    location->next->next->count = 5;
    /*  location->next->next->next->count=0;
      location->next->next->next->next->count=0;
      location->next->next->next->next->next->count=0;
    */

    if ((stream = fopen("msgs.hl7", "r")) != (FILE*)0) {
        fgets(s, 16000, stream);

        msgs = str2hl7(s);
        s2 = hl72str(msgs);
        printf("%s", s2);

        //s3=hl7rawget(msgs, location);
        //printf("\n\n\n >%s<\n\n\n\n", s3);

        hl7print(msgs);

        //hl7free(msgs);
        //free(s2);
        //free(s3);

/*       printf("\n\n>%s<\n\n", s);
         hl7print (msgs);  */

    }
    else {
        exit(1);
    }

    exit(0);

}