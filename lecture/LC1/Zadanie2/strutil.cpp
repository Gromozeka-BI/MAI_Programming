
#include <string.h>
int srtConteins(char* a, char* str){
	int delta = strlen(str) - strlen(a);
	int n = 0;
	while (n != delta + 1){
		for (int i = 0; i < strlen(a); i++){
			if (a[i] == str[n + i]){
				if (i == strlen(a) - 1){
					return n;
				}
			}
		}
		n++;
	}
	return -1;
}