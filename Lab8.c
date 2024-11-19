/*vul_prog.c*/
#include<stdio.h>
#include<stdlib.h>

#define SECRET 0x44

void vulfunc(char *user_input) {
	int secret;
	int a, b, c, d; /*other variables, not used here.*/

	/*getting the secret*/
	secret = SECRET;

	printf("The variable secret’s address is 0x%8x\n", (unsigned int)&secret);
	printf("The variable secret’s value is 0x%x or %d\n", (unsigned int)secret, secret);
	
	/*Vulnerable place*/
	printf(user_input);
	printf("\n");

	/*Verify whether your attack is successful*/
	printf("The original secret: 0x%x or %d\n", SECRET, SECRET);
	printf("The new secret: 0x%x or %d\n", secret, secret);

	return;
}

int main(int argc, char*argv[]) {
    FILE *badfile;
    char str[200];

    badfile = fopen("vulfile", "rb");
    fread(str, sizeof(char), 200, badfile);
    vulfunc(str);

    return 1;
}
