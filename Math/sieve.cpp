//Sieve of Eratosthenes
//Running Time O(n.log(log n)), Memory: O(n)
vector<bool> sieve(int n){
   vector<bool> isPrime(n+1, true);
   isPrime[0] = isPrime[1] = false;
   for(int i = 2; i*i <= n; i++)
      if(isPrime[i])
         for(int j = i*i; j <= n; j += i)
            isPrime[j] = false;
   return isPrime;
}

//Return all primes in [1, n]
//Sieve as prerequisite
//Running Time O(n.log(log n)), Memory: O(n)
vector<int> primesUntilN(int n){
   vector<int> primes;
   vector<bool> isPrime = sieve(n);
   for(int i = 0; i < (int)isPrime.size(); i++)
      if(isPrime[i])
         primes.emplace_back(i);
   return primes;
}

//Return divisors quantitity of all numbers in [1, n]
//Running Time O(n.log n), Memory: O(n)
vector<int> divisorsQnt(int n){
   vector<int> divisors(n+1, 0);
   for(int i = 1; i <= n; i++)
      for(int j = i; j <= n; j += i)
         ++divisors[j];
   return divisors;
}

//Return the divisors of a number for all numbers in [1, n]
//Running Time O(n.log n), Memory: O(n)
vector<vector<int>> divisorsNumbers(int n){
   vector<vector<int>> divisors(n+1, vector<int>());
   for(int i = 1; i <= n; i++)
      for(int j = i; j <= n; j += i)
         divisors[j].emplace_back(i);
   return divisors;
}


//Return the sum of divisors for all numbers in [1, n]
//Running Time O(n.log n), Memory: O(n)
vector<int> divisorsSum(int n){
   vector<int> divisors(n+1, 0);
   for(int i = 1; i <= n; i++)
      for(int j = i; j <= n; j += i)
         divisors[j] += i;
   return divisors;
}
