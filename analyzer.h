from stringdata import get_data
import time
from numpy import float64 as double


def linear_search(element:str, container: tuple): # Basic Linear search algorithm
    idx = -1
    for i in range(len(container)):
        if container[i] == element:
            idx = i
            break
    return idx

def binary_search(element:str, container:tuple): # Container could be sorted here, but I sort it later
    high, low = len(container) - 1, 0
    while low <= high:
        mid = (low + high) // 2 # Standard iterative binary earch algo, since recursion is banned :(
        if container[mid] == element:
            return mid
        elif container[mid] < element:
            low = mid + 1
        else:
            high = mid - 1
    return -1 # If element is not found


def compare(s,string_data):
    print(f'\n\nLooking for: {s}\n')
    lin_now = double(time.perf_counter()) #perf_counter is needed for accuracy 
    lin_idx = linear_search(s, string_data)
    print(f'Linear Search Time: {double(time.perf_counter()) - lin_now} seconds')
    print(f'Linear Search Index: {lin_idx}\n')
    print('Sorting data...')
    string_data = sorted(string_data)
    print('Data sorted\n')
    bin_now = double(time.perf_counter())
    bin_idx = binary_search(s,string_data)
    print(f'Binary Search Time: {double(time.perf_counter()) - bin_now} seconds')
    print(f'Binary Search Index: {bin_idx}') # Debug info to compare both algos

def main(): # Test cases
    d= get_data()
    compare('not_here',d)
    compare('mzzzz',d)
    compare('aaaaa',d)

if __name__ == '__main__':
    main()