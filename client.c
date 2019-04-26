#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>

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

void commun(int sock){
    char buf[256];
    int len_r;
    char *message="売られた喧嘩を買った場合は有休を使い放題とす";
    send(sock,message,strlen(message),0);
   
    len_r=recv(sock,buf,256,0);
    buf[len_r]='\0';
    printf("%s\n",buf); 
}

int main(int argc,char **argv){
    int sock=socket(PF_INET,SOCK_STREAM,0);
    struct sockaddr_in target;

    target.sin_family=AF_INET;
    target.sin_addr.s_addr=inet_addr("10.13.64.20");
    target.sin_port=htons(10001);

    connect(sock,(struct sockaddr*)&target,sizeof(target));

    commun(sock);

    close(sock);
    //printf("%d\n",sock);

    return 0;
}