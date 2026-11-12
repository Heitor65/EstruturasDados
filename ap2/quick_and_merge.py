import random

def partition(arr, left, right):
  pivoIdx = random.randint(left, right)
  arr[right], arr[pivoIdx] = arr[pivoIdx], arr[right]

  pivo = arr[right]

  i = left - 1;

  for j in range(left, right):
    if(arr[j] <= pivo):
      i = i + 1
      arr[j], arr[i] = arr[i], arr[j]

  arr[i+1], arr[right] = arr[right], arr[i+1]
  return i+1

def quicksort(arr, left, right):
  if(right < left):
    return
  pivo = partition(arr, left, right)
  quicksort(arr, left, pivo-1)
  quicksort(arr, pivo+1, right)
  
