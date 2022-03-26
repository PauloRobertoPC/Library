//return false if 'n' is not prime and true otherwise
//Based in the follow theorem: All composite numbers...
//have a divisor <= sqrt(n)
//Running time O(sqrt(n)), memory O(1)
bool isPrime(int n){
   if(n <= 1) return false; 
   if(n==2) return true;
   if((n&1) == 0) return false;
   for(int i = 3; i*i <= n; i+=2)
      if(n%i == 0)
         return false;
   return true;
}
