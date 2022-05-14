/***************************************************************************
                          hl7.c  -  description
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

#include "hl7.h"
#include <string.h>

/*********************************************************************
*********************************************************************/

char *
concat(char *string1, char *string2){

  int length1, length2;    /* holds length of strings */

  /* get the length of the second string */
  length2 = strlen(string2);

  /* if the second string is empty, we are done */
  if (length2==0)
       return string1;

  /* get the length of the first string */
  length1 = strlen(string1);

  /* expand string to hold the extra characters */
  if (string1 = (char *) realloc(string1, length1 + length2 +1)){

    /* copy second string onto end of first string */
    strncpy(&string1[length1], string2, length2);
    string1[length1 + length2] = '\000';

    /* return the new string */
    return string1;

  } else {
    /* no memory, die */
    exit(1);
  }

}

/*********************************************************************
Allocate memory for a string, copy the string into the memory and
   then return the pointer to the memory.
*********************************************************************/

char *
strset (char *string)
{

  char *pointer_to_string;

  if (pointer_to_string = (char *) malloc (strlen (string)+1))
    {
      strcpy (pointer_to_string, string);
      return (pointer_to_string);
    }
  else
    {
      /* die */
      exit (1);
    }
}  /* end strset */


/*********************************************************************
*********************************************************************/

void hl7count (struct hl7_part_t *message, char *seg_location) {

}  /* end hl7count */


/*********************************************************************
*********************************************************************/

void hl7rawcount (struct hl7_part_t *message, char *location) {

}  /* end hl7rawcount */


/*********************************************************************
*********************************************************************/

void hl7delete (struct hl7_part_t *message, char *seg_location, char *string){

} /* end hl7delete */


/*********************************************************************
*********************************************************************/

void hl7insert (struct hl7_part_t *message, char *seg_location, char *string){

}  /* end hl7insert */


/*********************************************************************
*********************************************************************/

void hl7rawdelete (struct hl7_part_t *message, struct hl7_location_t *location){

}  /* end hl7rawdelete */


/*********************************************************************
*********************************************************************/

void hl7rawinsert (struct hl7_part_t *message, struct hl7_location_t *location, char *string){

}  /* end hl7rawinsert */


/*********************************************************************
*********************************************************************/

void hl7set (struct hl7_part_t *message, char *seg_location, char *string){

}  /* end hl7set */


/*********************************************************************
*********************************************************************/

void hl7get (struct hl7_part_t *message, char *seg_location){

}  /* end hl7get */


/*********************************************************************
*********************************************************************/

void hl7rawset (struct hl7_part_t *message, struct hl7_location_t *location, char *string){

  /* this one is a little harder, you have to traverse the string to the given
     location, creating missing nodes as you go and then set the final portion
     to the given string. */

}  /* end hl7rawset */


/*********************************************************************
The function hl7rawget traverses the message to the given location and
returns the string that best represents the portion of the message
structure.

hl7rawget is passed in a pointer to a message structure and a location
and returns a string that best represents the message structure at that
point.

The function works by traversing the message structure until it gets
to a NULL in the path or to the designated location.

If it reaches a NULL it will return the empty string.

Otherwise it reaches the designated location and passes the correct
parameters to join in order to retrieve the proper string.
*********************************************************************/

char *hl7rawget (struct hl7_part_t *message, struct hl7_location_t *given_location){

  struct hl7_part_t *hl7_part;
  struct hl7_location_t *location;
  char *msg_string;         /* points to the message string */
  char  separators[8];	  	/* list of separators in proper order  */
  int  i,
       depth = 0;

  /* initialize the pointer to the string that is returning the value */
  msg_string = strset("");

  /* Traverse the tree  */
  hl7_part = message->lower;
  for (location = given_location ; location->next ; location=location->next){

    /*next for the count */
    for(i=location->count; i ; i--) {
      if(hl7_part->next){
        hl7_part=hl7_part->next;
      } else {
        return msg_string;
      }
    }

    /* lower each level */
    if(hl7_part->lower){
      depth++;
      hl7_part=hl7_part->lower;
    } else {
/*
      return msg_string;
*/
    }
  }

  /* this needs to be a subroutine because we just did it twice */
  /* build the seperators string */
  separators[0] = '\n';
  separators[1] = '\n';
  separators[2] = '\r';
  separators[3] = message->lower->lower->lower->next->lower->lower->lower->data[0];
  separators[4] = message->lower->lower->lower->next->next->lower->lower->lower->data[3];
  separators[5] = message->lower->lower->lower->next->next->lower->lower->lower->data[0];
  separators[6] = message->lower->lower->lower->next->next->lower->lower->lower->data[1];
  separators[7] = '\000';

printf("The depth is >%d<\n", depth);
hl7printlocation(given_location);

  /* Call the join function,  */
  msg_string=join(hl7_part, msg_string, &separators[depth+1]);

  /* return the string that we found */
  return msg_string;

}  /* end hl7rawget */


/*********************************************************************
The function join will recursively build a string from a message using
the designated seperator characters.

join is passed a pointer to a part of a message, a list of seperator
characters, and a state and will return a pointer to a string that
contains the hl7_message.

Some special coding is in place to ensure that all segments end in a
field seperator.
*********************************************************************/

char *join (struct hl7_part_t *hl7_part, char *msg_string, char *separators){

  char current_separator[2];

  if (separators=='\000')
          exit(1);

   current_separator[0] = separators[0];
   current_separator[1] = '\000';

  if (hl7_part->data){
    msg_string = concat(msg_string, hl7_part->data);
  }

  if (hl7_part->lower){
    msg_string = join(hl7_part->lower, msg_string, &separators[1]);
  }

  if (hl7_part->next){
    msg_string = concat(msg_string, current_separator);
    msg_string = join(hl7_part->next, msg_string, separators);
  }

  return msg_string;

}  /* end join */


/*********************************************************************
The funtion hl72str will create an hl7 message string from a message
structure.

hl72str is passed a message structure and returns a pointer to a
string.

hl72str is really a wrapper around the function join.  This function
does some prep work and calls join with the proper arguments,
returning the string that is returned by join.
*********************************************************************/

char *hl72str (struct hl7_part_t *message){

  char  separators[8];	  	/* list of separators in proper order  */
  char *msg_string;         /* points to the message string */
  int  length;

  msg_string=strset("");

  /* build the seperators string */
  separators[0] = '\n';
  separators[1] = '\n';
  separators[2] = '\r';
  separators[3] = message->lower->lower->lower->next->lower->lower->lower->data[0];
  separators[4] = message->lower->lower->lower->next->next->lower->lower->lower->data[3];
  separators[5] = message->lower->lower->lower->next->next->lower->lower->lower->data[0];
  separators[6] = message->lower->lower->lower->next->next->lower->lower->lower->data[1];
  separators[7] = '\000';

  /* turn the message into a string */
  msg_string = join(message, msg_string, separators);

  /* fix the field separator field */
  length=strlen(msg_string);
  strncpy(&msg_string[4], &msg_string[6], length-5);
  if (!(msg_string=(char *) realloc(msg_string, length-2))){

    /* not enough memory, die */
    exit(1);
  }

  return msg_string;

}  /* end hl72str */


/*********************************************************************
The function split uses recursion in order to split a message based on
a set of seperators.

The function is given a pointer to an hl7 message part that needs to be
split and a pointer to a string of seperators and returns a pointer to
an the lower part of the message.
*********************************************************************/

struct hl7_part_t *split (struct hl7_part_t *hl7_part, char *separators)
{

  struct hl7_part_t *head,	/* begining of the data list */
   *current;			/* tail of the data list */

  int begin = 0,		/* start of the current string */
    scan = 0;			/* current position in string */

  /* if the list of separators is empty, we have reached a leaf, return null */
  if (separators[0] == '\000'){
    return (struct hl7_part_t *) 0;
  }

  /* setup structure for current level of operations */
  if (!(current = head = (struct hl7_part_t *) malloc (sizeof (struct hl7_part_t))))
      exit (1);

  /* initialize the structure to some sane values */
  current->data = (char *) 0;
  current->next = (struct hl7_part_t *) 0;
  current->lower = (struct hl7_part_t *) 0;


  /* start looking thru the string for current seperator */
  for (; hl7_part->data[scan]; scan++)
  {
      /* when we find the current seperator */
      if (hl7_part->data[scan] == separators[0])
	  {
		  /* replace the seperator with a NULL */
		  hl7_part->data[scan] = '\000';

		  /* set a copy of the string that we found to current data element */
		  current->data = strset (&hl7_part->data[begin]);

		  /* split the string into substrings */
		  /* this is a little tricky */
		  /* I send the seperator string starting with its _second_ element */
		  current->lower = split (current, &separators[1]);

		  /* setup for the next string that we find */
		  if (!(current->next = (struct hl7_part_t *) malloc (sizeof (struct hl7_part_t))))
			  exit (1);

		  /* move the current pointer to the node that we just created */
		  current = current->next;

		  /* initialize the data to some sane values */
		  current->data = (char *) 0;
		  current->next = (struct hl7_part_t *) 0;
		  current->lower = (struct hl7_part_t *) 0;

		  /* set the begining of the string to follow the found string */
		  begin = scan + 1;
	  }
   }

  /* We reached the end of the string without finding (another) seperator.
     But there is still a string that we need to take care of. */

  /* put a copy of the string in the current data element */
  current->data = strset (&hl7_part->data[begin]);

  /* split the data element into substrings */
  /* this is a little tricky */
  /* I send the seperator string starting with its _second_ element */
  current->lower = split (current, &separators[1]);

  /* get rid of the string from the parent, we stored it safely at this level */
  free (hl7_part->data);

  /* set the parent data element to the null pointer so that it won't be
     pointing to the place where the string used to be. */
  hl7_part->data = (char *) 0;

  /* return the list of substrings found to the parent. */
  return head;

} /* end split */


/*********************************************************************
*********************************************************************/

struct hl7_part_t *str2hl7 (char *message_string)
{

  struct hl7_part_t *message;	/* Message structure that we are working on */

  char delimiters[6],		/* list of delimiters from the message */
    separators[7],		/* list of separators in proper order */
    temp[6];			/* used to set the correct delimiters
				   in the final message structure */

  /* probably should check that the message begins with MSH
     and is longer than a minimum length... */



  if (!(message = (struct hl7_part_t *) malloc (sizeof (struct hl7_part_t)))){
      /* If we don't have enough memory, quit.
      /* This is kind of abrupt and needs to be more elegant. */
      exit (1);
  }

  /* put some sane values into the clean new structure */
  message->lower=(struct hl7_part_t *)0;
  message->next=(struct hl7_part_t *)0;

  /* put a copy of hl7_string into the proper place in the message structure */
  message->data = strset (message_string);

  /* copy the hl7 delimiters to a string to hold them for processing */
  strncpy (delimiters, &message->data[3], 5);

  /* close the end of the string with a terminator so that we don't dump core */
  delimiters[5] = '\000';

  /* reorder the delimiters into the proper order for seperation */
  separators[0] = '\n';
  separators[1] = '\r';
  separators[2] = delimiters[0];
  separators[3] = delimiters[2];
  separators[4] = delimiters[1];
  separators[5] = delimiters[4];
  separators[6] = '\000';

  /* remove the delimiters from the message so that we don't get confused */
  message->data[4] = 'X';
  message->data[5] = '|';
  message->data[6] = 'Z';
  message->data[7] = ' ';

  /* recursively call split to split the message on each seperator */
  message->lower = split (message, separators);

  /* put the delimiters into the proper place in the message structure */
  /* replace this with the hl7set as quickly as possible. */
  free (message->lower->lower->lower->next->lower->lower->lower->data);
  strncpy (temp, &delimiters[0], 1);
  temp[1] = '\000';
  message->lower->lower->lower->next->lower->lower->lower->data = strset (temp);

  free (message->lower->lower->lower->next->next->lower->lower->lower->data);
  strncpy (temp, &delimiters[1], 4);
  temp[4] = '\000';
  message->lower->lower->lower->next->next->lower->lower->lower->data = strset (temp);

  /* we are done, return the results */
  return message;

}  /* end str2hl7 */


/*********************************************************************
*********************************************************************/

void hl7printlocation(struct hl7_location_t *location){

  for(; location->next; location=location->next) {
    printf("%d", location->count);
    if (location->next->next){
      printf(".");
    }
  }

} /* end hl7printlocation */


/*********************************************************************
*********************************************************************/

void hl7rawprint(struct hl7_part_t *hl7_part, struct hl7_location_t *location,
                                              struct hl7_location_t * current, int state)
{
  /* recursively traverse the tree, keep track of where you are and print out the data */
  if (!(current->next)){
     if (!(current->next = (struct hl7_location_t *)
                                                malloc(sizeof(struct hl7_location_t)))){
       exit (1);
     }
  current->next->next  = (struct hl7_location_t *) 0;
  current->next->count      = 0;
  }

  if ((hl7_part->data) &&(strlen(hl7_part->data))){
    hl7printlocation(location);
    printf(" >%s<\n", hl7_part->data);
  }

  if (hl7_part->lower){

    hl7rawprint(hl7_part->lower, location, current->next, LOWER);
  }

  if (hl7_part->next){
    current->count++;
    hl7rawprint(hl7_part->next, location, current, NEXT);
  }

  if (state==LOWER)
    current->count=0;

  return;
} /* end hl7rawprint */


/*********************************************************************
*********************************************************************/

void hl7print (struct hl7_part_t *message)
{
  struct hl7_location_t *location;

  /* setup some data structures and call the real function */

  if (!(location = (struct hl7_location_t *) malloc(sizeof(struct hl7_location_t)))){
    exit (1);
  }

  location->count = 0;
  location->next  = (struct hl7_location_t *) 0;

  hl7rawprint(message->lower, location, location, BEGIN);
  hl7freelocation(location);
  /* need to free the memory that was allocated for the location! */

}  /* end hl7print */


/*********************************************************************
The function hl7freelocation recursively moves to the end of the
location list and then returns back to the top, deleting each node.

hl7freelocation is given a pointer to a linked list of locations and
returns nothing.
*********************************************************************/

void hl7freelocation(struct hl7_location_t *location){

  /* if we aren't at the end of the list, */
  /* move to the next element in the list */
  if(location->next)
    hl7freelocation(location->next);

  /* free the current element of the list */
  free(location);

  /* return to the previous element in the list */
  return ;

}  /* hl7freelocation */


/*********************************************************************
The function hl7free is called in order to free all the memory that
was previously allocated for a message.

hl7free is called with a pointer to a message and returns nothing.

This functions works with recursion.  If there is any data present in
any node, we free that data.  If there is a lower branch we decend
down that branch by calling hl7free with a pointer to the lower
message part. Once we have travelled all the way down and returned
back to the current node, we decend to the next message part by
calling hl7free with a pointer to the next message part. Once we have
travelled all the way down the list of next message parts and returned
to the current node, we
*********************************************************************/

void hl7free (struct hl7_part_t *hl7_part)
{

  /* free data, if it is present */
  if (hl7_part->data){
    free(hl7_part->data);
  }

  /* look in each lower branch first, if present */
  if (hl7_part->lower)
    {
      hl7free (hl7_part->lower);
    }

  /* then look in each next branch, if present */
  if (hl7_part->next)
    {
      hl7free (hl7_part->next);
    }

  /* free the current node */
  free(hl7_part);

  /* return to previous node */
  return;

}  /* end hl7free */


