def prime_checker(p):
    if p < 1:
        return False
    elif p > 1:
        if p == 2:
            return True
        for i in range(2, int(p**0.5) + 1):
            if p % i == 0:
                return False
        return True
        
def prime_factors(n):
    factors = []
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def primitive_check(g, p):
    factors = prime_factors(p - 1)
    for q in factors:
        if pow(g, (p - 1) // q, p) == 1:
            return False
    return True

P = int(input("Enter P (prime number): "))

# while True:
#     P = int(input("Enter P (prime number): "))
#     if not prime_checker(P):
#         print("Number is not prime, please enter again!")
#         continue
#     break

primitive_roots = []
for g in range(1, P):
    if primitive_check(g, P):
        primitive_roots.append(g)

if not primitive_roots:
    print(f"No primitive roots found for {P}")
else:
    print(f"Primitive roots for {P} are: {primitive_roots}")

while True:
    G = int(input(f"Choose one of the primitive roots for {P}: "))
    if G not in primitive_roots:
        print(f"{G} is not a primitive root of {P}, Please Try Again!")
        continue
    break

x1, x2 = int(input("Enter The Private Key Of User 1 : ")), int(input("Enter The Private Key Of User 2 : "))

y1, y2 = pow(G, x1) % P, pow(G, x2) % P

k1, k2 = pow(y2, x1) % P, pow(y1, x2) % P

print(f"\nSecret Key For User 1 Is {k1}\nSecret Key For User 2 Is {k2}\n")

if k1 == k2:
    print("Keys Have Been Exchanged Successfully")
else:
    print("Keys Have Not Been Exchanged Successfully")
