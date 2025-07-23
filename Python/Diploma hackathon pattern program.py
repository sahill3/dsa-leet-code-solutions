def print_pattern(n):
    size = 2 * n + 1

    matrix = [[0 for _ in range(size)] for _ in range(size)]

    for i in range(size):
        for j in range(size):
            matrix[i][j] = max(abs(i - n), abs(j - n))

    for row in matrix:
        print(' '.join(map(str, row)))

n = int(input("Enter the value of n: "))
print_pattern(n)