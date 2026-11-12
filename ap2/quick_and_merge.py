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
  
def merge(esquerda, direita):
    resultado = []
    i = j = 0

    while i < len(esquerda) and j < len(direita):
        if esquerda[i] <= direita[j]:
            resultado.append(esquerda[i])
            i += 1
        else:
            resultado.append(direita[j])
            j += 1

    if i == len(esquerda):
        resultado.extend(direita[j:])
    if j == len(direita):
        resultado.extend(esquerda[i:])

    return resultado


def mergeSort(arr):
  
  if len(arr) <= 1:
    return arr
    
  meio = len(arr) // 2
  esquerda = arr[:meio]
  direita = arr[meio:]

  esquerda = mergeSort(esquerda)
  direita = mergeSort(direita)
  return merge(esquerda, direita)
