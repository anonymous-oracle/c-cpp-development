#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main() {
//    create a socket
    int network_socket;
//    socket(address domain, TCP/UDP socket, protocol
    network_socket = socket(AF_INET, SOCK_STREAM, 0); // 0 is used to determine the type of protocol when using raw sockets
    
    
//    specify address for the server socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000); // the server port to connect; converts host byte order to network byte order
    server_address.sin_addr.s_addr = INADDR_ANY; // the server address to connect
    
    
//    connect client socket to server socket
    int connection = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)); // sizeof gets the size of the address; for IPv4 it is 32 bit and IPv6 it is 128 bit
    if (connection==-1){
        printf("Something is wrong with the connection\n");
    } else{
//        receive data from the server
        char server_data[256];
        recv(network_socket, server_data, sizeof(server_data), 0);
        printf("SERVER RESPONSE: %s\n\n", server_data);
    }
    
//    close socket in the end
    close(network_socket);
    
    return 0;
  }
