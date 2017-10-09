#include<stdio.h>
#include<string.h>

int isSubstring(char word[], char buffer[]){
	int i,j,flag;
	int l1 = strlen(word);
	int l2 = strlen(buffer);
	for(i=0; i<l2-l1+1; ++i){
		for(j=i; j<i+l1; ++j){
			flag=1;
			if(buffer[j]!=word[j-i]){
				flag = 0;
				break;
			}
		}
		if(flag == 1){return 1;}
	}
	return 0;
}

int main(int argc, char *argv[]){
	int i;
	char word[15],buffer[15];
	FILE *inp, *out, *queries;
	out = fopen("output.txt", "w");
	queries = fopen(argv[2],"r");
	if(out==NULL || queries == NULL){
		printf("Unable to open files\n");
		return 0;
	}
	
	while(fscanf(queries,"%s",word)==1){
		inp = fopen(argv[1],"r");
		if(inp == NULL){
			printf("Unable to open input file\n");
			return 0;
		}
		while(fscanf(inp,"%s",buffer) == 1){
			if(isSubstring(word,buffer) == 1){
				fprintf(out, "%s\n", buffer);
			}
		}
	}
	fclose(inp);
	fclose(out);
	fclose(queries);
}
