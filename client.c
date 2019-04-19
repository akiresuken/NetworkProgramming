#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>

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

int main(int argc,char **argv){
    int sock=socket(PF_INET,SOCK_STREAM,0);
    struct sockaddr_in target;

    target.sin_family=AF_INET;
    target.sin_addr.s_addr=inet_addr("10.13.64.20");
    target.sin_port=htons(10001);

    connect(sock,(struct sockaddr*)&target,sizeof(target));

    close(sock);
    //printf("%d\n",sock);

    return 0;
}