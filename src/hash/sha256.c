#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char *argv[])
{
	unsigned char ibuf[2048];
	unsigned char obuf[SHA256_DIGEST_LENGTH];

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
	printf("[HCRACK][i] Hash.format(algorithmn)....: SHA256\n");
	printf("[HCRACK][i] Password.list(wordlist)....: %s\n", argv[2]);

	while (fscanf(fp, "%s", word) == 1) {
		strcpy(ibuf, word);
		SHA256_CTX sha256;
		SHA256_Init(&sha256);
		SHA256_Update(&sha256, ibuf, strlen(ibuf));
		SHA256_Final(obuf, &sha256);

		char outputBuffer[65];
		for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) sprintf(outputBuffer + (i * 2), "%02x", obuf[i]);
		outputBuffer[64] = 0;

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
