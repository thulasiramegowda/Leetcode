char* longestCommonPrefix(char** strs, int strsSize) {
if(strsSize==0)
return "";
char* prefix=strs[0];
for(int i=0;prefix[i]!='\0';i++){
    for(int j=0;j<strsSize;j++){
        if(strs[j][i]!=prefix[i]||strs[j][i]=='\0'){
            prefix[i]='\0';
            return prefix;
        }
    }
}
return prefix;    
}