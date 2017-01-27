#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NBLANGUE 4
#define NBLETTRE 26

int main(int argc, char *argv[]){
	FILE *f;
	char c;
	//char prec=' ';
	int mot=1;
	int lettre=0;
	double comptage[NBLANGUE][NBLETTRE]; //iniatilsiere à 0
	/*int Bigramme[26][26];
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			Bigramme[i][j]=1;
		}
	}*/
	for(int i=0;i<NBLANGUE;i++){
		for(int j=0;j<NBLETTRE;j++){
			comptage[i][j]=1;
		}
	}
	if(argc!=NBLANGUE+1)return 1;
	for(int i=0;i<NBLANGUE;i++){	
		f=fopen(argv[i+1],"r");
		c=getc(f);
		while(c!=EOF){

			if (isalpha(c)){
				/*if(prec!=' '){
					Bigramme[c-'a'][prec-'a']++;
				}*/
				comptage[i][c-'a']++;
				lettre++;
				//prec = c;
			}else{
				mot++;
			}

			c=getc(f);
		}
		printf("%s", argv[i+1]);
		printf("\n");
		for(int j=0;j<26;j++)comptage[i][j]=((comptage[i][j])/(double)(lettre+NBLETTRE));
		for(int j=0;j<26;j++)printf("Nombre de %c : %f\n",j+'a',comptage[i][j]);
	/*for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			printf("Nombre de %c précédé de %c : %d\n ",i+'a', j+ 'a', Bigramme[i][j]);
		}
	}*/
	//printf("\t");
	/*/for(int i=0; i<26; i++) {
		printf("%c\t", i+'a');
	}
	for(int i=0;i<26;i++){
		printf("\n%c \t", i+'a');
		for(int j=0;j<26;j++){
			printf("%d\t", Bigramme[i][j]);
		}
	}*/
		printf("\n");printf("\n");printf("\n");
		fclose(f);
	}
	return 0;
}