#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main(int argc, char *argv[])
{
	MD5_CTX md5;
	unsigned char digest[16];
	char string[1024];
	int i;

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
	printf("[HCRACK][i] Hash.format(algorithmn)....: MD5\n");
	printf("[HCRACK][i] Password.list(wordlist)....: %s\n", argv[2]);

	while (fscanf(fp, "%s", word) == 1) {
		MD5_Init(&md5);
		MD5_Update(&md5, word, strlen(word));
		MD5_Final(digest, &md5);

		for(i = 0; i < MD5_DIGEST_LENGTH; i++) sprintf(&string[i*2], "%02x", (unsigned int)digest[i]);

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
