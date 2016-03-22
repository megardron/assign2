#include <stdio.h>
#include <string.h>

int append_l = 7;
void test (char * t) {
	//t = "not hello world\n";
	strcpy(t, "not hello world");
	return;
}

int get_next_sentence(FILE *f, char *sen) {
	if (f==NULL) return -1;
	fscanf(f, "%100c", sen);
	for (int i = 0; i<100; i++) {
		if (*(sen+i)=='\n') {
			*(sen+i) = '\0';
			return i+1;
		}
	}
	return -1;
}

char *find_word(char *word, char *sen) {
	return strstr(sen, word);
}

int search_1_svc (char **msg){
	FILE *f;
	f = fopen("output.txt", "r");
	return get_next_sentence(f, *msg);
}

void main() {
	char a[100] = "SEARCH(to)\n";
	char *s = a;
	printf("BEFORE %s\n", s);
	int x = search_1_svc(&s);
	printf("AFTER %d %s        %c\n", x, s, a[x]);
	char * t = strstr(s, "is");
	printf("%s\n", t);
}
