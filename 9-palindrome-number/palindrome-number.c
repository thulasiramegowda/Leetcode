bool isPalindrome(int x) {
 //negitive numbers are not palindrome
 if(x<0)
 return false;
 int original=x;
 long reversed=0;
 while(x>0){
    //digit is in integer so it will consider only first number 
    int digit= x % 10;
    reversed = reversed * 10 + digit;
    x=x/10;
 } 
 if(original==reversed)
 return true;
 else
 return false;  
}