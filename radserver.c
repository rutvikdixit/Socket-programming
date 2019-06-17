#include<sys/types.h>
#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>

void main()
{
	int fd,newfd,bytes, bytes2;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	char buf[512], buf2[512];
	int client_len =sizeof(client_addr); 
 	
 	if((fd=socket(AF_INET,SOCK_STREAM,0))<0)
 	{
   		printf("Error");
   		exit(1);
 	}
 	else
 	{
   		printf("Socket is created");
   		printf("\n%d",fd);
   		server_addr.sin_family=AF_INET;
   		server_addr.sin_port=htons(6000);
   		server_addr.sin_addr.s_addr=INADDR_ANY;
   		bzero(&(server_addr.sin_zero),8);

   		if(bind(fd,(struct sockaddr*) &server_addr,sizeof(server_addr)) < 0 )
   		{
      			printf("\nError binding\n");
      			exit(1);
   		}
   		else
   		{
    			printf("\nbind succeeesful\n");
   		}
   
  		if(listen(fd, 5) < 0) 
    		{
			printf("error");
			exit(1);
    		}
  		else
   		{
  
     			printf("\nlisten successful\n");
   		}
		newfd= accept(fd, (struct sockaddr*) &client_addr, &client_len);  

  		if(newfd < 0) 
   		{
			printf("Error");
	
		}
  		else
  		{
  			printf("\naccept successful\n");
 
  		}
		
		while(1)
		{
		

	 		bytes = recv(newfd, buf, sizeof(buf),0);

	  		if(bytes >= 0) 
	   		{
				printf("Received: %s", buf);
				printf("\n"); 
				//printf("%s",buf);
				//exit(1); 
				if(buf[0] == 'e' && buf[1] == 'x' && buf[2] == 'i' && buf[3] == 't')
				{
					break;
				}
	   		}
	   		
	   		//Sending Response
	   		printf("Enter message: ");
	   		scanf("%s", buf);
	   		

	   		bytes2 = send(newfd, buf, sizeof(buf), 0);
	   		if(bytes < 0) 
	   		{
				printf("Error");
				//exit(1);
	   		}
	  		else
	   		{
	      			//printf("sent success:");
	   		}
   		}
                     
   
	}
	close(newfd);
	close(fd);
}
