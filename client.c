#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define BUF_SIZE 256
/*ヘッダで定義されている構造体の中身
struct in_addr{
    unsigned longs_addr;
};

struct sockaddr_in{
    unsigned short sin_family;
    unsigned short sin_port;
    struct in_addrsin_addr;
    char sin_zero[8];
};*/
void DieWithError(char *errorMessage){
    perror(errorMessage);
    exit(1);
}
void commun(int sock){
    char buf[BUF_SIZE];
    int len_r;
    char *message="古戦場から逃げるな";
    if(send(sock,message,strlen(message),0)!=strlen(message)){
        DieWithError("send()sent a message of unexpected bytes");
    }
    
    if((len_r=recv(sock,buf,BUF_SIZE,0))<=0){
        DieWithError("recv() failed");
    }
    buf[len_r]='\0';
    printf("%s\n",buf); 
}



int main(int argc,char **argv){
    if(argc!=3){
        DieWithError("arguments is not available");
    }
    char *server_ipaddr=argv[1];//"10.13.64.20"ipaddress
    int server_port=atoi(argv[2]);//10001
    
    int sock=socket(PF_INET,SOCK_STREAM,0);
	
	if(sock<0){DieWithError("socket()failed");}
    
    struct sockaddr_in target;

    target.sin_family=AF_INET;
    target.sin_addr.s_addr=inet_addr(server_ipaddr);
    target.sin_port=htons(server_port);
    if(connect(sock,(struct sockaddr *)&target,sizeof(target))<0){
        DieWithError("connect() failed"); //0以上成功 -1エラー
    }

    commun(sock);

    close(sock);
    //printf("%d\n",sock);

    return 0;
}