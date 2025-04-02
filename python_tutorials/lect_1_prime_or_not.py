#check if the number is prime or not?


def check_prime_while(n):
    i=1
    count=0
    if n==1:
        return False
    while i<=n**0.5:
        if n%i==0:
            count=count+1
        i=i+1    
            
    if count>1:
        return False
    
    else:
        return True

n=int(input())
if n==1:
    print("neither prime nor composite")

elif check_prime_while(n):
    print("prime")
else:
    print("composite")

    
###################
# def check_prime(n):
#     i=1
# count=0
# for 
#     if n%i==0:
#         count=count+1
#     i=i+1    
        
# if count>1:
#     print("no")
    
# else:
#     print("yes")
