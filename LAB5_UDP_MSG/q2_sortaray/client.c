#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
 #include <arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        int fd,res,n;
        int *a;
        a=(int *)malloc(5*sizeof(int));
        fd=socket(AF_INET, SOCK_DGRAM, 0);
        
        if(fd==-1)
                printf("Socket not created error\n");
        else
                printf("Socket created successfully\n");

        struct sockaddr_in server,client;
        client.sin_family=AF_INET;
        client.sin_port=ntohs(6000);
        client.sin_addr.s_addr=INADDR_ANY;
        
       // res=bind(fd,(struct sockaddr *) &server,sizeof server);
        
        if(res==-1)
                printf("Bind not created error\n");
        else
                printf("Bind created successfully\n");
                
               
        server.sin_family=AF_INET;
        server.sin_port=ntohs(6005);
        server.sin_addr.s_addr=INADDR_ANY;
        int buf;
        printf("how many elements u have : ");
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
                scanf("%d",&a[i]);
        }
        
        
        if(sendto(fd,a,n*sizeof(int),0,(struct sockaddr *)&server, sizeof server) == -1) 
        {
                perror("sendto");
                exit(1);
        }
        printf("Send Successfully\n");
        
        int t1=sizeof(server);
        recvfrom(fd, a ,n*sizeof(int), 0,(struct sockaddr*)&server, &t1);
        
//       printf(" factorial of %d--->%d\n",buf,fac);
 for (int i = 0; i < n; i++)
        {
                printf("%d ",a[i]);
        }
        

        close(fd);
}


//factorial 
// sort
//message till exit
//