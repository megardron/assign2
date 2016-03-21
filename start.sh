# !/bin/bash

touch output.txt
rm output.txt
rpcgen msg.x
gcc rprintmsg.c msg_clnt.c -o client

gcc msg_proc.c msg_svc.c -o server

./server
