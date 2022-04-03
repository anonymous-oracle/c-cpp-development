#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
    int server_sock;
    char server_message[256] = "Message from the server!!!";
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    int bindint = bind(server_sock, (struct sockaddr *) &server_address, sizeof(server_address)); // binds the server process on this address and port
    
    listen(server_sock, 5);
    
    int client_socket;
    
    client_socket = accept(server_sock, NULL, NULL); // since the client addr struct is not known and the connection is open for any address, it is declared as NULL
    
    send(client_socket, server_message , sizeof(server_message), 0);
    close(server_sock);
    
    
    return 0;
}
