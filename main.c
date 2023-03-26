#include <arpa/inet.h>
#include <stdio.h>

int main() {
    const char *ip = "192.168.0.1";
    struct in_addr ip_addr;
    
    if (inet_aton(ip, &ip_addr)) {
        printf("Indirizzo IP in formato binario: %x\n", ip_addr.s_addr);
    } else {
        printf("Indirizzo IP non valido\n");
    }

  uint16_t host_short = 0x1234;
    uint16_t net_short = htons(host_short);
    printf("Valore intero a 16 bit nel formato di rete: %x\n", net_short);

  printf("git\n");
    return 0;
}