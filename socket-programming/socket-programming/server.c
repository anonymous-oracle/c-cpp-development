#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
    char message_for_client[256] = "This is the message from the server";
    
    //    create a socket
    int network_socket;
    //    socket(address domain, TCP/UDP socket, protocol
    network_socket = socket(AF_INET, SOCK_STREAM, 0); // 0 is used to determine the type of protocol when using raw sockets
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; // address over which the server runs
    server_address.sin_port = htons(8000); // port on which the server runs on
    
    //    bind the server socket to the address and the port
    bind(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    
    
    
    //    listen for connections
    listen(network_socket, 5);
    
    //    client connection
    struct sockaddr_in client_address;
    int client_socket=0;
   
    //    printf("===CLIENT DETAILS===\n");
    //    printf("CLIENT ADDRESS: %d\n", client_address.sin_addr.s_addr);
    //    printf("CLIENT PORT: %d\n", htons(client_address.sin_port));
    //    printf("CLIENT ADDRESS FAMILY: %d\n", server_address.sin_family);
    //    send data
    
 
    
    send(client_socket, message_for_client, sizeof(message_for_client), 0);
    
    //    close the socket
    close(network_socket);
    client_socket = 0;
            
    return 0;
}
