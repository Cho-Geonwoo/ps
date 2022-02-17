N = int(input())

def hanoi(n, a, b):
  if(n==0):
    return
  
  hanoi(n-1, a, 6-a-b)
  print(a, b)
  hanoi(n-1, 6-a-b, b)
print(pow(2, N) - 1)
hanoi(N, 1, 3)