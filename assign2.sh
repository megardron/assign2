# !/bin/bash


./client localhost "APPEND(Here is sentence number one.)"
./client localhost "APPEND(This is another sentence.)"
./client localhost "APPEND(This is to be tagged to the end of the text.)"
./client localhost "COUNT(to)"
./client localhost "DELETE(to)"
./client localhost "FIND(3)"

./client localhost "REMOVE(This is another sentence.)"
cat output.txt
