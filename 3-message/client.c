#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

#define BUF_SIZE 256
#define MONEY_DIGIT_SIZE 10

void DieWithError(char *);
int prepare_client_socket(int);
void my_scanf(char *, int);
void commun(int);

int main(int argc, char *argv[]){
    if(argc != 3)
        DieWithError("usage: ./client ip_addres port");

    int sock = prepare_client_socket(argv[1], )
}