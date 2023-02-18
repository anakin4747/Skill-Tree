
#include <stdio.h>

int main(int argc, char **argv){

	// One of the first things you'll call
	// when making a connections
	struct addrinfo{
		int		ai_flags; // either AI_PASSIVE or AI_CANONNAME, etc
		int		ai_family; // AF_INET for IPv4, AF_INET6 for IPv6, AF_UNSPEC
		int		ai_socktype; // SOCK_STREAM for TCP, SOCK_DGRAM for UDP
		int		ai_protocal; // use 0 for any
		size_t 	ai_addrlen; // size of ai_addr in bytes
		struct sockaddr *ai_addr; // struct sockaddr_in or _in6
		char 	*ai_canonname; // full canonical hostname

		struct addrinfo *ai_next; // linked list, next node
	};

	// a pointer to a struct sockaddr_in can be cast to a pointer to a struct sockaddr

	struct sockaddr{
		unsigned short sa_family; // address family, AF_INET, AF_INET6, AF_UNSPEC
		char sa_date[14]; // 14 Bytes of protocol address
		// sa_data contains a destination address and port number for the socket
	};

	struct in_addr{
		uint32_t s_addr; // thats a 32-bit int (4 bytes)
	};

	struct sockaddr_in{
		short int	sin_family; // Address family, AF_INET
		unsigned short int sin_port; // Port number
		struct in_addr	sin_addr; // Internet address
		unsigned char	sin_zero[8]; // Same size as struct sockaddr
	};

	struct in6_addr{
		unsigned char s6_addr[16]; // IPv6 address
	};

	struct sockaddr_in6{
		u_int16_t sin6_family; // address family, AF_INET6
		u_int16_t sin6_port; // port number, Network Byte Order
		u_int32_t sin6_flowinfo; // IPv6 flow information
		struct in6_addr sin6_addr; // IPv6 address
		u_int32_t sin6_scope_id; // Scope ID
	};

	struct sockaddr_storage{
		sa_family_t ss_family; // address family
		// all this is padding, implementation specific, ignore it
		char _ss_pad1[_SS_PAD1SIZE];
		int64_t _ss_align;
		char _ss_pad2[_SS_PAD2SIZE];
	};
	
	struct sockaddr_in sa; // IPv4
	struct sockaddr_in6 sa6; // IPv6

	inet_pton(AF_INET, "192.0.2.1", &(sa.sin_addr)); // IPv4
	inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr)); // IPv6
	// pton converts the dot notations of IP addresses to a struct in_addr or in6_addr
	// pton stands for presentation to network
	// you can think of it as printable to network
	// They should be used with error checking

	// IPv4
	char ip4[INET_ADDRSTRLEN]; // space to hold the IPv4 string
	struct sockaddr_in sa; // pretend this is loaded with something
	inet_ntop(AF_NET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);
	printf("The IPv4 address is %s\n", ip4);
	
	// IPv6
	char ip6[INET6_ADDRSTRLEN]; // space to hold the IPv6 string
	struct sockaddr_in6 sa6; 

	inet_ntop(AF_INET6, &(sa6.sin6_addr), ip6, INET6_ADDRSTRLEN);
	
	printf("The IPv6 address is %s\n", ip6);

    return 0;
}
