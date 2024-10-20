#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

void main() {
    int cs;
    cs = socket(AF_INET, SOCK_STREAM, 0);

    // Server address
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = ntohs(8001);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(&(servaddr.sin_zero), '\0', 8);

    if (connect(cs, (struct sockaddr *)&servaddr, sizeof(struct sockaddr)) == -1) {
        printf("Couldn't connect to server.\n");
        exit(1);
    }
    printf("Connected to server.\n");

    char req_msg[100], resp_msg[100];
    int msg_len;

    while (1) {
        printf("Enter message for server (type 'exit' to quit): ");
        fgets(req_msg, 100, stdin);
        req_msg[strcspn(req_msg, "\n")] = '\0'; // Remove newline character

        send(cs, req_msg, strlen(req_msg), 0);

        if (strcmp(req_msg, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        if ((msg_len = recv(cs, resp_msg, 100, 0)) == -1) {
            printf("Message not received properly.\n");
            exit(1);
        }
        resp_msg[msg_len] = '\0';
        printf("Server response: %s\n", resp_msg);

        if (strcmp(resp_msg, "exit") == 0) {
            printf("Server requested to exit. Exiting...\n");
            break;
        }
    }

    close(cs);
}

