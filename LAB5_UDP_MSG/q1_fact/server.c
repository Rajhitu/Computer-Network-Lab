
#include<stdio.h>
 #include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
 #include <arpa/inet.h>
#include<stdlib.h>
#include <unistd.h>
int main()
{
        int fd1,res1,numbytes,t1;
        int buf,fac=1;
        fd1=socket(AF_INET, SOCK_DGRAM, 0);

        if(fd1==-1)
                printf("Socket not created error\n");
        else
                printf("Socket created successfully\n");

        struct sockaddr_in server,client;
        server.sin_family=AF_INET;
        server.sin_port=ntohs(6005);
        server.sin_addr.s_addr=INADDR_ANY;

        res1=bind(fd1,(struct sockaddr *) &server,sizeof server);
        if(res1==-1)
                printf("Bind not created error\n");
        else
                printf("Bind created successfully\n");
                
                t1=sizeof(client);
        numbytes=recvfrom(fd1, &buf, sizeof(buf), 0,(struct sockaddr*)&client, &t1);
       // printf("1");
        
        
        printf("%d is received from client\n ",buf);
        
        
        for(int i=1;i<=buf;i++)
        {
           fac=fac*i;
        }
        
        printf("returning factorial of %d--->%d\n",buf,fac);
        
        sendto(fd1,&fac,sizeof(fac),0,(struct sockaddr *)&client, sizeof client);
        
        close(fd1);        
}
