/***************************************************************************
                          hl7.h  -  description
                             -------------------
    begin                : Mon Jan 31 2000
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

#include <stdio.h>
#include <stdlib.h>

#define		LOWER		0
#define		NEXT		1
#define		BEGIN		2

/*

the data structure is as follows

Message
  NEXT
  LOWER -> Segment
             NEXT
             LOWER -> Field
                        NEXT
                        LOWER -> Repeating Field
                                   NEXT
                                   LOWER -> Component
                                              NEXT
                                              LOWER -> Subcomponent
                                                         NEXT
                                                         DATA -> string of data
NEXT is the next element of the same type
LOWER is the first element of a list of subordinate data structures
Both NEXT and LOWER point to a structure of type hl7_part_t

*/

struct hl7_part_t {
  char *data;
  struct hl7_part_t *next;
  struct hl7_part_t *lower;
} ;


/*

The hl7_location_t is a linked list that contains a location in the hl7 message
structure.

The structure looks like this:

location --> next -----> next-----> next -----> next -----> next -----> NULL
             count=0     count=3    count=0     count=5     count=0

Where the count is the number of next links that are taken before taking a lower
link.

*/

struct hl7_location_t {
  int count;
  struct hl7_location_t *next;
} ;


/* These functions are complete */

char *strset (char *);
char *concat (char *, char *);

void hl7printlocation(struct hl7_location_t *);
void hl7freelocation(struct hl7_location_t *);

struct hl7_part_t *str2hl7 (char *);
struct hl7_part_t *split (struct hl7_part_t *, char *);

void hl7free (struct hl7_part_t *);

void hl7print (struct hl7_part_t *);
void hl7rawprint(struct hl7_part_t *, struct hl7_location_t *,
                                                 struct hl7_location_t *, int);

char * hl7rawget (struct hl7_part_t *, struct hl7_location_t *);
char * hl72str (struct hl7_part_t *);
char *join(struct hl7_part_t *, char*, char *);

/* These functions are to be written next. */

void hl7rawset (struct hl7_part_t *, struct hl7_location_t *, char *);


/* These functions are to be written later */

void hl7rawdelete (struct hl7_part_t *, struct hl7_location_t *);
void hl7rawinsert (struct hl7_part_t *, struct hl7_location_t*, char *);

void hl7count (struct hl7_part_t *, char *);
void hl7rawcount (struct hl7_part_t *, char *);

void hl7delete (struct hl7_part_t *, char *, char *);
void hl7insert (struct hl7_part_t *, char *, char *);

void hl7set (struct hl7_part_t *, char *, char *);
void  hl7get (struct hl7_part_t *, char *);



