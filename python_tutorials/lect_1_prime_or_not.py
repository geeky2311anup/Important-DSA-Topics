# Function to check whether a number is prime or not
def check_prime_while(n):

    # Start checking divisors from 1
    i = 1

    # Count how many divisors exist
    count = 0

    # 1 is neither prime nor composite
    if n == 1:
        return False

    # Check divisors only till square root of n
    while i <= n ** 0.5:

        # If n is divisible by i
        if n % i == 0:
            count = count + 1

        # Move to next number
        i = i + 1

    # If more than 1 divisor found in range,
    # number is composite
    if count > 1:
        return False

    # Otherwise number is prime
    else:
        return True


# Take input from user
n = int(input())

# Special case for 1
if n == 1:
    print("neither prime nor composite")

# Check if prime
elif check_prime_while(n):
    print("prime")

# Otherwise composite
else:
    print("composite")


###################

# Alternative logic using for loop

# def check_prime(n):
#
#     # Initialize divisor count
#     count = 0
#
#     # Loop through numbers
#     for i in range(1, int(n ** 0.5) + 1):
#
#         # Check divisibility
#         if n % i == 0:
#             count += 1
#
#     # More than 1 divisor pair means composite
#     if count > 1:
#         print("no")
#
#     # Otherwise prime
#     else:
#         print("yes")
