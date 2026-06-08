char* addBinary(char* a, char* b) {
    int lenA=strlen(a);
    int lenB=strlen(b);
    int i=lenA-1;
    int j=lenB-1;
    int carry=0;
    char*result=malloc((lenA+lenB+2)*sizeof(char));
    int k=0;
    while(i>=0 || j>=0 || carry){
        int sum = carry;
        if(i>=0){
            sum += a[i]-'0';
            i--;
        }
        if(j>=0){
            sum +=b[j]-'0';
            j--;
        }
        result[k++]=(sum % 2)+'0';
        carry = sum/2;
    }
    result[k]='\0';
    for(int start=0,end = k-1;start <end;start++,end--){
        char temp=result[start];
        result[start]=result[end];
        result[end]=temp;
    }
    return result;
}