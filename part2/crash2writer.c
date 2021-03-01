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

/* JAC: Why is this included? */
#include <time.h>

struct this_gift_card examplegc;
struct gift_card_data examplegcd;
struct gift_card_record_data examplegcrd;
// struct gift_card_amount_change examplegcac;
struct gift_card_program examplegcp;
char str[6] = "leeks";
char str2[6] = "hello";

struct gift_card_record_data examplegcrd2;
struct gift_card_program examplegcp2;

// Break it up so that we don't have long functions!  Good programming style!
//  (JAC: This is so wrong.  Global variable use / initialization is a 
//  terrible thing to do.)
void setupgc() {
// 	examplegc.num_bytes = 664;
// 	examplegc.num_bytes = 2,147,483,647;

	examplegc.num_bytes = 368;

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
	
	/* JAC: Something seems fishy... */
	examplegcd.gift_card_record_data = (void *)malloc(1*sizeof(void*));
	/* JAC: here too! */
	examplegcd.gift_card_record_data[0] = (void *) &examplegcrd;
	examplegcrd.record_size_in_bytes = 44;
	examplegcrd.type_of_record = 2; // JAC: Should be enum!  amount_change
	examplegcrd.actual_record = (void *) &examplegcp;
// 	char str[6];
// 	str[5] = 'z';
// 	str[4] = 's';
// 	str[3] = 'k';
// 	str[2] = 'e';
// 	str[1] = 'e';
// 	str[0] = 'l';
	
	
// 	char str[6] = "leeks";
// 	str = "leeks";
// 	examplegcp.message = "leeks";
// 	examplegcp.*message[6] = "z";
	
// 	char str[] = {"l","e","e","k","s"};
// 	char str[] = "leeks";
// 	str[5] = 'z';
// 	examplegcp.message = {"l","e","e","k","s","\0"};

	str[5] = 126;
	examplegcp.message = str;
	
	unsigned char uc = 255;
	examplegcp.program = &uc;
	
	
	
	
	
	
	
	
// 	examplegcd.gift_card_record_data[1] = (void *) &examplegcrd2;
// 	examplegcrd2.record_size_in_bytes = 44;
// 	examplegcrd2.type_of_record = 2; // JAC: Should be enum!  amount_change
// 	examplegcrd2.actual_record = (void *) &examplegcp2;
// 	str2[5] = 126;
// 	examplegcp2.message = str2;
// 	unsigned char uc2 = 255;
// 	examplegcp2.program = &uc2;
	
	
}




// moved into separate files to avoid erroenous style checker error...
/* JAC: opening and writing a fixed filename using a global is terrible style.
 *     the style checker was right!  This code is terrible   
 */
void writegc() {
	FILE *fd1;
	// JAC: Why don't any of these check for error return codes?!?
	fd1 = fopen("crash2.gft","w");
	fwrite(&examplegc.num_bytes,4,1,fd1);
	fwrite(examplegcd.merchant_id,32,1,fd1);
	fwrite(examplegcd.customer_id,32,1,fd1);
	fwrite(&examplegcd.number_of_gift_card_records,4,1,fd1);
// 	fwrite(examplegcd.gift_card_record_data,16,1,fd1);

	
	
	fwrite(&examplegcrd.record_size_in_bytes,4,1,fd1);
	fwrite(&examplegcrd.type_of_record,4,1,fd1);
	fwrite(examplegcp.message,32,1,fd1);
	fwrite(examplegcp.program,256,1,fd1);
	
	
	
	
// 	fwrite(&examplegcrd2.record_size_in_bytes,4,1,fd1);
// 	fwrite(&examplegcrd2.type_of_record,4,1,fd1);
// 	fwrite(examplegcp2.message,32,1,fd1);
// 	fwrite(examplegcp2.program,256,1,fd1);	
	
	
	fclose(fd1);
}

/* JAC: No args and return -1 for no reason!?! */
int main(void) {

	setupgc();
	writegc();
	return -1;
}
