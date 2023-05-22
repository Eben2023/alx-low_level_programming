import ctypes

# Load the dynamic library
lib = ctypes.CDLL("./100-operations.so")

# Define the function prototypes
lib.print_primes.argtypes = (ctypes.c_int, ctypes.c_int)
lib.print_fibonacci.argtypes = (ctypes.c_int, ctypes.c_int)

# Call the functions
lib.print_primes(1, 100)
lib.print_fibonacci(1, 100)
