/*
 * rprintmsg.c: remote version of "printmsg.c"
 *
 * Source: ?Using rpcgen?, http://www.cisco.com/en/US/docs/ios/sw_upgrades/interlink/r2_0/rpc_pr/rprpcgen.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/rpc.h>	/* always needed */
#include "msg.h"	/* need this too: msg.h will be generated by rpcgen */

static char* app = "APPEND";
static char* del = "DELETE";
static char* cnt = "COUNT";
static char* fnd = "FIND";
static char* rmv = "REMOVE";
static char* srch = "SEARCH";

int *dispatch(char *input, CLIENT *cl) {
	if (!memcmp(input, app, strlen(app))) {
		printf("appending\n");
		return append_1(&input, cl);
	}
	if (!memcmp(input, del, strlen(del))) {
		printf("deleting\n");
		return delete_1(&input, cl);
	}
	if (!memcmp(input, cnt, strlen(cnt))) {
		int *x = count_1(&input, cl);
		printf("counting %d\n", *x);
		return x;
	}
	if (!memcmp(input, fnd, strlen(fnd))) {
		char *x = find_1(&input, cl);
		int n = 0;
		printf("finding %s,   %d\n", x, strlen(x));
		
		return x;
	}
	if (!memcmp(input, srch, strlen(fnd))) {
		char *x = search_1(&input, cl);
		int n = 0;
		printf("searching %s,   %d\n", x, strlen(x));
		
		return x;
	}
	if (!memcmp(input, rmv, strlen(rmv))) {
		printf("removing\n");
		return remove_1(&input, cl);
	}
	printf("invalid fn\n");
	return NULL;
}


int main(int argc, char *argv[])
{

	CLIENT *cl;
	int *result;
	char *server;
	char *message;

	if (argc < 3) {
		fprintf(stderr, "usage: %s host message\n", argv[0]);
		exit(1);
	}

	/*
	 * Save values of command line arguments
	 */

	server = argv[1];
	message = argv[2];
	

	/*
	 * Create client "handle" used for calling MESSAGEPROG on the
	 * server designated on the command line. We tell the RPC package
	 * to use the "tcp" protocol when contacting the server.
	 */

	printf("%s\n", message);

	cl = clnt_create(server, MESSAGEPROG, MESSAGEVERS, "tcp");
	if (cl == NULL) {
		/*
		 * Couldn't establish connection with server.
		 * Print error message and die.
		 */
		clnt_pcreateerror(server);
		exit(1);
	}
	
	/*
	 * Call the remote procedure "printmessage" on the server
	 */
	result = dispatch(message, cl);
	if (result == NULL) {
		/*
		 * An error occurred while calling the server.
		 * Print error message and die.
		 */
		clnt_perror(cl, server);
		exit(1);
	}

	/*
	 * Okay, we successfully called the remote procedure.
	 */
	if (*result == 0) {
		/*
		 * Server was unable to print our message.
		 * Print error message and die.
		 */
		fprintf(stderr, "%s: %s couldn't print your message\n",
			argv[0], server);
		exit(1);
	}
	
	/*
	 * The message was output on the server
	 */
	printf("Message delivered to %s!\n", server);

	return 0;
}
