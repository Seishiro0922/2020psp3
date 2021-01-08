#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";


char* ForceSearch(char text[], char key[])
{   int keylen=0;
    int textlen=0;
    int pos,pos1,i;
    for(pos=0;key[pos] != '\0';pos++)
    {keylen++;}
    for(pos=0;text[pos] != '\0';pos++)
    {textlen++;}
    pos=pos1=i=0;

    while(pos<=textlen){    
        while(pos1<=keylen){
            if(text[pos]==key[pos1]){
              pos1=pos1+1; pos=pos+1;
              if(pos1==keylen){return &text[i];}
            }else{   pos1=0;
                     i=i+1;  pos=i;
                     break;
            }
        }
    }
    return NULL;
}

char* BMSearch(char text[], char key[])
{
    int i, textlen, keylen, table[256], pos, pos1, k, j=0;
    for(i=0; key[i] != '\0';i++)
    {keylen=i;}
    for(i=0; text[i] != '\0';i++)
    {textlen=i;}
    
    for(i=0;i<=255;i++){
        table[i]=keylen+1;
    }
    
    for(i=0; key[i] != '\0';i++){
        table[(unsigned char)key[i]]=keylen-i;
    }
    
    for(i=keylen;i<=textlen;i=pos+k){
        for(pos=i;pos1!=0;pos--){ 
             pos1=keylen-j;
            if(text[pos]==key[pos1]){
            j++;
               if(j==keylen+1){
                return &text[i-keylen];
               }
               }
               else{
                j=0;
                k=table[(unsigned char)text[pos]];
                if(pos+k<=i){
                    k=i+1-pos;
               }
               break;

            }
        
      }
    }
    return NULL; 
}



int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    

    return 0;
}