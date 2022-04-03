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
    server_address.sin_port = htons(8002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    
//    connect client socket to server socket
    int connection = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)); // sizeof gets the size of the address; for IPv4 it is 32 bit and IPv6 it is 128 bit
    if (connection==-1){
        printf("Something is wrong with the connection");
    } else if (connection==0){
        
    }
    
    
    
    return 0;
  }
