#include <stdio.h>
#include <string.h>
#include <openssl/md4.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	MD4_CTX md4;
	int i;
	unsigned char digest[MD4_DIGEST_LENGTH];
	char string[1024];

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
	printf("[HCRACK][i] Hash.format(algorithmn)....: MD4\n");
	printf("[HCRACK][i] Password.list(wordlist)....: %s\n", argv[2]);

	while (fscanf(fp, "%s", word) == 1) {
		MD4_Init(&md4);
		MD4_Update(&md4, word, strlen(word));
		MD4_Final(digest, &md4);

		for(i = 0; i < MD4_DIGEST_LENGTH; i++) sprintf(&string[i*2], "%02x", (unsigned int)digest[i]);

		if (strcmp(string, argv[1]) == 0) {
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
