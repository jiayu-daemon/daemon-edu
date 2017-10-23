#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

//出错函数
#define err_exit(m)\
{\
    perror(m);\
    exit(EXIT_FAILURE);\
}

//最大连接数
#define LISTENQ 1024

//服务器端口号
#define SERV_PORT 9877

//接收和发送的缓冲区大小
#define BUFSIZE 4096

//处理客户端请求函数
void str_echo(int confd);

int main(int argc, char **argv)
{
    int confd, listenfd;
    struct sockaddr_in cliaddr, servaddr;
    pid_t childpid;
    socklen_t clilen;
    int status;
    char buff[BUFSIZE];

    //设置协议地址结构内容
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);//创建套接字
    if (listenfd == -1)
        err_exit("socket");
    status = bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));//将协议、IP地址、端口绑定到套接字
    if (status == -1)
        err_exit("bind");
    status = listen(listenfd, LISTENQ);//使套接字变为监听套接字
    if (status == -1)
        err_exit("listen");
    while (1)
    {
        clilen = sizeof(cliaddr);//这一步最容易忘记
        confd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);//等待连接完成
        if (status == -1)
            err_exit("accept");
        if ((childpid = fork()) == 0)//并发服务器，fork一个子进程来处理客户端请求
        {
            printf("connection from %s, port %d\n",
                    inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
                    ntohs(cliaddr.sin_port));
            close(listenfd);//子进程不需要监听套接字
            str_echo(confd);//子进程处理客户端请求
            close(confd);//处理结束，关闭连接套接字
            exit(0);//处理结束，关闭子进程
        }
        close(confd);//父进程不需要连接套接字
    }
}

void str_echo(int confd)
{
    ssize_t n;
    char buf[BUFSIZE];
    while ((n = read(confd, buf, BUFSIZE)) > 0)
        write(confd, buf, n);
}
