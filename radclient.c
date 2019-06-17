#include<sys/types.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>

void main()
{
	int fd,cnt=0,bytes, bytes2;
	char buf[512],buf2[512], ch;
	struct sockaddr_in client_addr;
	struct sockaddr_in server_addr;

	if((fd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("Error");
		exit(1);
	}
	else
	{
		printf("Socket is created!\n");
		printf("\n%d",fd);
   		server_addr.sin_family=AF_INET;
		server_addr.sin_port=htons(6000);
		server_addr.sin_addr.s_addr=INADDR_ANY;  

		if(connect(fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) 
		{
			printf("connect"); 
        		exit(1);
    		}
   		else
   		{
       			printf("\nConnect successful\n");
   		}
  
		while(1)
		{
	    		printf("Enter message: ");
	    		scanf("%s",buf);
	    		//printf("%s",buf);
			
			
			bytes = send(fd,buf, sizeof(buf),0);
	   		if(bytes < 0) 
	   		{
				printf("Error");
				//exit(1);
	   		}
	  		else
	   		{
	      			//printf("sent success!\n");
	   		}
	   		
	   		if(buf[0] == 'e' && buf[1] == 'x' && buf[2] == 'i' && buf[3] == 't')
			{
				break;
			}
	   		
	   		bytes2 = recv(fd, buf2, sizeof(buf2), 0);
	   		
	   		if(bytes2>=0)
	   		{
	   			printf("Received: %s", buf2);
	   			printf("\n");
	   		}
   		}
	}

	close(fd);
}
