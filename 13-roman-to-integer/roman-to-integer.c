int value(char c) {
    if(c=='I') return 1;
    if(c=='V') return 5;
    if(c=='X') return 10;
    if(c=='L') return 50;
    if(c=='C') return 100;
    if(c=='D') return 500;
    if(c=='M') return 1000;
    return 0;
}
int romanToInt(char* s){
    int total=0;
    int i=0;
    while(s[i]!='\0'){
        int current = value(s[i]);
        int next = value(s[i+1]);
        if(current < next){
            total=total+(next-current);
            i=i+2;
        }
        else{
            total=total+current;
            i=i+1;
        }
    }
    return total;
}