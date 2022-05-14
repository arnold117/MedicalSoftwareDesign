/***************************************************************************
                          main.c  -  description
                             -------------------
    begin                : Mon Jan 31 05:32:15 PST 2000
    copyright            : (C) 2000 by James M. Rogers
    email                : jrogers@visnetinc.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/



#include "hl7.h"

int main ()
{
  struct hl7_part_t *msgs;
  struct hl7_location_t *location;
  struct hl7_location_t *current;
  char s[16000];
  char *s2, *s3, *s4;
  FILE *stream;
  int i;

  if (!(current = location = (struct hl7_location_t *)malloc(sizeof(struct hl7_location_t)))){exit (1);}
  current->next  = (struct hl7_location_t *) 0;
  current->count = 0;

  for(i=0 ; i<3 ; i++){
    if (!(current->next = (struct hl7_location_t *)malloc(sizeof(struct hl7_location_t)))){exit (1);}
    current        = current->next;
    current->next  = (struct hl7_location_t *) 0;
    current->count = 0;
  }

  location->count=0;
  location->next->count=1;
  location->next->next->count=5;
/*  location->next->next->next->count=0;
  location->next->next->next->next->count=0;
  location->next->next->next->next->next->count=0;
*/

    if((stream = fopen ("msgs.hl7", "r")) != (FILE *)0) {
		fgets(s, 16000, stream);

         msgs = str2hl7 (s);
         s2=hl72str(msgs);
		 printf("%s",s2);

         //s3=hl7rawget(msgs, location);
         //printf("\n\n\n >%s<\n\n\n\n", s3);

         hl7print (msgs);

         //hl7free(msgs);
         //free(s2);
         //free(s3);

/*       printf("\n\n>%s<\n\n", s);
         hl7print (msgs);  */
       
    } else {
         exit(1);
    }

  exit (0);

}  /* end main */