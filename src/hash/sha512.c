#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char *argv[])
{
	unsigned char ibuf[2048];
	unsigned char obuf[SHA512_DIGEST_LENGTH];

	if(argc < 3) {
		printf("Usage: %s <hash> <wordlist>\n", argv[0]);
		exit(EXIT_SUCCESS);
        }

	FILE *fp; char word[1024];
	fp = fopen(argv[2], "r");
	if (fp == NULL) {
		printf("[HCRACK][!] Error opening %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	printf("[HCRACK][i] Session....................: Hcrack\n");
	printf("[HCRACK][i] Hash.format(algorithmn)....: SHA512\n");
	printf("[HCRACK][i] Password.list(wordlist)....: %s\n", argv[2]);

	char outputBuffer[SHA512_DIGEST_LENGTH*2+1];

	while (fscanf(fp, "%s", word) == 1) {
		strcpy(ibuf, word);
		SHA512_CTX c;
		SHA512_Init(&c);
		SHA512_Update(&c, ibuf, strlen(ibuf));
		SHA512_Final(obuf, &c);

		for(int i = 0; i < SHA512_DIGEST_LENGTH; i++) sprintf(outputBuffer + (i * 2), "%02x", obuf[i]);
		if (strcmp(outputBuffer, argv[1]) == 0) {
			printf("\n");
			printf("[HCRACK][i] Cracked.key................: [ %s ]\n", word);
			fclose(fp);
			exit(EXIT_SUCCESS);
		}
	}

	printf("\n");
	printf("[HCRACK][i] Cracked.key................: [ KEY NOT FOUND! ]\n");

	return 0;
}
