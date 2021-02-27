/*
 * Gift Card Example Writer
 * Original Author: Shoddycorp's Cut-Rate Contracting
 * Maintainer: ???
 * Comments added by Justin Cappos (JAC)
 * Modification Date: 8 July 2020
 */

#include <stdio.h>
#include <math.h> 
#include <limits.h> 
#include "giftcard.h"

struct this_gift_card examplegc;
struct gift_card_data examplegcd;
struct gift_card_record_data examplegcrd;
// struct gift_card_amount_change examplegcac;
struct gift_card_program examplegcp;
char str[6] = "leeks";

struct gift_card_record_data examplegcrd2;
struct gift_card_program examplegcp2;
// unsigned char test[256];
// try signed char next if this does not work;
unsigned char test[3];

// unsigned char final;

unsigned char x;

// Break it up so that we don't have long functions!  Good programming style!
//  (JAC: This is so wrong.  Global variable use / initialization is a 
//  terrible thing to do.)
void setupgc() {
	examplegc.num_bytes = 664;
// 	examplegc.num_bytes = 2,147,483,647;
// 	examplegc.num_bytes = 368;
	examplegc.gift_card_data = (void *) &examplegcd;
	examplegcd.merchant_id = "Infinite8.com                   ";
	examplegcd.customer_id = "DuaneGreenes Infin ite8         ";
	//float totalrec = 1.0/0.0;
	//float totalrec = NAN;
	//int x = INT_MAX;
	//examplegcd.number_of_gift_card_records = NAN;
	//try this below then if not then try it with minus one;
	//examplegcd.number_of_gift_card_records = CHAR_MAX;
	examplegcd.number_of_gift_card_records = 1;
	
	examplegcd.gift_card_record_data = (void *)malloc(1*sizeof(void*));
	examplegcd.gift_card_record_data[0] = (void *) &examplegcrd;
	examplegcrd.record_size_in_bytes = 44;
	examplegcrd.type_of_record = 3; // JAC: Should be enum!  amount_change
	examplegcrd.actual_record = (void *) &examplegcp;
	
// 	char str[6] = "leeks";
// 	str = "leeks";
// 	examplegcp.message = "leeks";
// 	examplegcp.*message[6] = "z";
// 	char str[] = {"l","e","e","k","s"};
// 	char str[] = "leeks";
// 	str[5] = 'z';
// 	examplegcp.message = {"l","e","e","k","s","\0"};
// 	str[5] = 126;
	examplegcp.message = str;
// 	test = NULL;
// 	unsigned char uc = 0;
// 	examplegcp.program = test;
	
	
	
	
// 	for(int i=0; i<256; i++) {
// 		test[i] = 0;
// 	}
	
	
	test[0] = 9;
	test[1] = -3;
	test[2] = -3;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
// 	unsigned char foo = 254;
// 	test = &foo;
// 	test = 253;
	
// 	x = NULL;
// 	test[0] = 255;
	
// 	final = test;
// 	*final = 127;
// 	x = 255;
	
}


// moved into separate files to avoid erroenous style checker error...
/* JAC: opening and writing a fixed filename using a global is terrible style.
 *     the style checker was right!  This code is terrible   
 */
void writegc() {
	FILE *fd1;
	// JAC: Why don't any of these check for error return codes?!?
	fd1 = fopen("loo.gft","w");
	fwrite(&examplegc.num_bytes,4,1,fd1);
	fwrite(examplegcd.merchant_id,32,1,fd1);
	fwrite(examplegcd.customer_id,32,1,fd1);
	fwrite(&examplegcd.number_of_gift_card_records,4,1,fd1);
	
	fwrite(&examplegcrd.record_size_in_bytes,4,1,fd1);
	fwrite(&examplegcrd.type_of_record,4,1,fd1);
	fwrite(examplegcp.message,32,1,fd1);
// 	fwrite(examplegcp.program,256,1,fd1);
	fwrite(test,256,1,fd1);
// 	fwrite(&final,256,1,fd1);
	fclose(fd1);
}

/* JAC: No args and return -1 for no reason!?! */
int main(void) {

	setupgc();
	writegc();
	return -1;
}
