#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Function to generate a random string
void generateRandomString(char *buffer, size_t length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < length - 1; i++) {
        buffer[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    buffer[length - 1] = '\0';
}
int main(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

	int acc = 0;
	int n;
	while (acc >= 0){
		printf("acc = %d\n", acc);
		printf("Enter a number: ");

		if (scanf("%d", &n) != 1){
			puts("Error reading integer");
		} else {
			if (n < 0){
				puts("You can't enter the negative number!");
			} else {
				acc += n;
			}
		}
	}
	
    char randomString[10];  // Change the size as needed
    generateRandomString(randomString, sizeof(randomString));

    printf("You win! acc = %d\n", acc);
    printf("Flag{%s}\n", randomString);
}
