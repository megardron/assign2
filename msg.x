/*
 * msg.x: Remote message printing protocol
 *
 * Source: ?Using rpcgen?, http://www.cisco.com/en/US/docs/ios/sw_upgrades/interlink/r2_0/rpc_pr/rprpcgen.html
 */

program MESSAGEPROG {
	version MESSAGEVERS {
		int PRINTMESSAGE(string) = 1;
		int APPEND(string) = 2;
		int DELETE(string) = 3;
		int REMOVE(string) = 4;
		int COUNT(string) = 5;
		char FIND(string) = 6;
		char SEARCH(string) = 7;
	} = 1;
} = 0x20083001;
