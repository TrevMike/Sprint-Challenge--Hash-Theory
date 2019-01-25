#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"
// key = source = starting Location 
// value = destination
// the ith location in the route can be found by checking the hash table for the i-1th location.

char **reconstruct_trip(Ticket **tickets, int length)
{
  // making the tickets. 
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *)); 
  // make a loop to go through the array to insert each ticket
  for (int i=0; i<length; i++){
    // we have hashtable, key, and value. 
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }
  // hashtable and key
  // 
  route[0] = hash_table_retrieve(ht, 0);
  // route[i] = hash_table_retrieve(ht, route[i-1]);

  // this is to loop and get the i th location before to be able to link from 1 location/destination. 
  for (int k=1; k<length; k++){
    // the ith location in the route can be found by checking the hash table for the i-1th location
    route[k] = hash_table_retrieve(ht, route[k-1]);
  }
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}



#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE"; /* this is the key */
  ticket_1->destination = "PDX"; /* this is the value */
  tickets[0] = ticket_1; /* potition/index in the array */

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX"; /* this is the key */
  ticket_2->destination = "DCA"; /* this is the value */
  tickets[1] = ticket_2; /* potition/index in the array */

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA"; /* this is the key */
  ticket_3->destination = "NONE"; /* this is the value */
  tickets[2] = ticket_3; /* potition/index in the array */

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
