#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
 #include <arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
        int fd,res;
        fd=socket(AF_INET, SOCK_DGRAM, 0);
        
        if(fd==-1)
                printf("Socket not created error\n");
        else
                printf("Socket created successfully\n");

        struct sockaddr_in x;
        x.sin_family=AF_INET;
        x.sin_port=ntohs(6000);
        x.sin_addr.s_addr=INADDR_ANY;
        
        res=bind(fd,(struct sockaddr *) &x,sizeof x);
        
        if(res==-1)
                printf("Bind not created error\n");
        else
                printf("Bind created successfully\n");
                
                struct sockaddr_in y;
        y.sin_family=AF_INET;
        y.sin_port=ntohs(6005);
        y.sin_addr.s_addr=INADDR_ANY;
        char buf[100];
        printf("Enter a message--->");
        scanf("%s",buf);
        
        
        if(sendto(fd,buf,strlen(buf),0,(struct sockaddr *)&y, sizeof y) == -1) 
        {
                perror("sendto");
                exit(1);
        }
        //printf("Send Successfully");
        int t1=sizeof(y);
        recvfrom(fd, buf,sizeof(buf), 0,(struct sockaddr*)&y, &t1);
        printf("%s   from server \n",buf);
        
        close(fd);
}
