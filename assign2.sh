# !/bin/bash


./client localhost "APPEND(Here is sentence number one.)"
./client localhost "APPEND(This is another sentence.)"
./client localhost "APPEND(This is to be tagged to the end of the text.)"
./client localhost "COUNT(to)"
./client localhost "DELETE(to)"
cat output.txt
#so far so good

./client localhost "FIND(2)"
./client localhost "FIND(4)"

./client localhost "SEARCH(Here)"
./client localhost "SEARCH(another)"
./client localhost "SEARCH(why)"

#./client localhost "REMOVE(This is another sentence.)"
#./client localhost "REMOVE(Here is sentence number one.)"
cat output.txt
