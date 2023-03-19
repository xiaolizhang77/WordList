import random
import string

def generate_random_string(length):
    while True:
        s = ''.join(random.choice(string.ascii_lowercase) for _ in range(length))
        if ord(s[0]) > ord(s[-1]):
            return s

unique_strings = set()

while len(unique_strings) < 100:
    random_string = generate_random_string(10)
    unique_strings.add(random_string)

result = ', '.join(f'"{s}"' for s in unique_strings)
print(result)