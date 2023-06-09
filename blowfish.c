#include<stdio.h>
#include<string.h>
#include<openssl/blowfish.h>
//gcc blowfish.c -o blowfish -lcrypto

static const unsigned char key[] = "0123456789abcdef";
static const unsigned char iv[]= "abcdef0123456789";

void encryptstring (const char* plaintext, char* ciphertext)
{
	BF_KEY bfkey;
	BF_set_key(&bfkey, 16, key);


	unsigned char input[9];
	unsigned char output[9];
	memset(input, 0, sizeof(input));
	memset(output, 0, sizeof(output));

	int len = strlen(plaintext);
	int numBlocks = len / 8 + 1 ;
	
	for (int i = 0; i < numBlocks; i++)
	{
	memcpy(input, plaintext + i * 8, 8);
	BF_ecb_encrypt(input, output, &bfkey, BF_ENCRYPT);
	memcpy(ciphertext + i * 8, output, 8);
	}
}

int main()
{
	const char* plaintext ="This is a string";
	char ciphertext[17];
	encryptstring(plaintext, ciphertext);
	
	printf("Plaintext: %s\n", plaintext);
	printf("Ciphertext: ");
	for (int i = 0; i < 16; i++)
	{
		printf("%02x", (unsigned char)ciphertext[i]);
	}
	printf("\n");
	return 0;
}
