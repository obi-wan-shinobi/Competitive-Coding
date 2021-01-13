#sieve[i] = 0 -> Prime
#sieve[i] = 1 -> Not prime
sieve = [0]*(100000+2)
sieve[0] = 1
sieve[1] = 1

def getPrime(n):
    buildSieve(n);
    result = []
    for i in range(n):
        if not sieve[i]:
            result.append(i)

    return result


def buildSieve(n):
    for i in range(2, n):
        if(sieve[i] == 0):
            j = 2
            while(i*j <= n):
                sieve[i*j] = 1
                j+=1

result = getPrime(25)
print(result)
