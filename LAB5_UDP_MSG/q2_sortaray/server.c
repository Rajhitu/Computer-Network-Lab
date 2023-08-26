
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
            int *a,n;
                a=(int *)malloc(5*sizeof(int));
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
            
        numbytes=recvfrom(fd1, a,sizeof(int)*5, 0,(struct sockaddr*)&client, &t1);
       printf("\nArray recieved\n");
        
        
        // printf("%d is received from client\n ",buf);
        // int n= sizeof;
        
        for(int i=0;i<5-1;i++)
        {
          for (int j = 0; j < 5-i-1; j++)
          {
                if(a[j]>a[j+1])
                {
              int temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;   
                }    
          }
          
        }
        printf("\nSorting done\n");
                printf("\nreturning the sorted array\n");

        
      for (int i = 0; i < 5; i++)
        {
                printf("%d ",a[i]);
        }
        
        sendto(fd1,a,sizeof(int)*5,0,(struct sockaddr *)&client, sizeof client);
        
        close(fd1);        
}
