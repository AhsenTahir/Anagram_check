#include<stdio.h>
#include<strings.h>
#include<ctype.h>
int anagram(char str1[],char str2[],int check1[],int check2[]);
int main(){
	
	char str1[100];
		char str2[100];
	printf("ENTER THE STRING 1 :");
	scanf("%s",str1);
		printf("\nENTER THE STRING 2 :");
	scanf("%s",str2);
	int check1[256]={0};
	int check2[256]={0};
	int i;
	for(i=0;i<strlen(str1);i++){
		str1[i]=tolower(str1[i]);    //converting all alphabets to smaller case
	}
	for(i=0;i<strlen(str2);i++){
		str2[i]=tolower(str2[i]);
	}
	
	int result;
	result=anagram(str1,str2,check1,check2);
	if(result==1){
		printf("YES IT IS A ANAGRAM ");
	}
	if(result==0){
		printf("NO IT IS NOT A ANAGRAM ");
	}
	
	
	return 0;
}
int anagram(char str1[],char str2[],int check1[],int check2[]){
	
	int i;
	int result;
	int n1=strlen(str1);
	int n2=strlen(str2);
	for(i=0;i<n1;i++){
		
		check1[(int)str1[i]]++; //it will increment 1 to check1 array elements being used in the string1
	}
	for(i=0;i<n2;i++){
		
		check2[(int)str2[i]]++; //it will increment 1 to check2 array elements being used in the string2
	}
	for(i=0;i<256;i++){
		
	if(check1[i]==check2[i]){
		result=1;
	}
	else{
		result=0;
		break;
		}
	}
	return result;
}