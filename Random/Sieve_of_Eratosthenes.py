def sieve_of_eratosthenes(n):
    i = 0
    prime = []
    while i < n:
        prime.append(i)
        i += 1
    i = 2
    while i < n:
        if prime[i] != 0:
            x = 2
            while i * x < n:
                prime[i * x] = 0
                x += 1
        i += 1
    i = 2
    while i < n:
        if prime[i] != 0:
            print(i)
        i += 1


num = int(input("Enter a number upto which you want to print prime numbers : "))
sieve_of_eratosthenes(num)
