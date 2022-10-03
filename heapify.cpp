#include<bits/stdc++.h>
using namespace std;

void build_heap(int arr[], int N) {
    int swap_end_node_index = ((N - 2) >> 1);
    int largest_index = 0, left_index, right_index;
    
    for(int i = swap_end_node_index; i >= 0; --i){
        largest_index = i;
        left_index = (i << 1) + 1;
        right_index = left_index  + 1;

        if((left_index < N) && (arr[largest_index] < arr[left_index])) {
            largest_index = left_index;
        }

        if((right_index < N) && (arr[largest_index] < arr[right_index])) {
            largest_index = right_index;
        }

        if (largest_index != i) {
            arr[i] ^= arr[largest_index] ^= arr[i] ^= arr[largest_index];
            int j = largest_index;
            while(j <= swap_end_node_index) {
                largest_index = j;
                left_index = (j * 2) + 1;
                right_index = left_index  + 1;

                if((left_index < N) && (arr[largest_index] < arr[left_index])) {
                    largest_index = left_index;
                }

                if((right_index < N) && (arr[largest_index] < arr[right_index])) {
                    largest_index = right_index;
                }
                if (largest_index != j) {
                    arr[j] ^= arr[largest_index] ^= arr[j] ^= arr[largest_index];
                    j = largest_index;
                } else {
                    break;
                }
            }
        }
    }
}

void heapify_v1(int arr[], int N, int i) {
    int left_child_index = (i << 1) + 1;
    int right_child_index = left_child_index + 1;
    int largest_element_index = i;
    if((left_child_index < N) && (arr[largest_element_index] < arr[left_child_index])) {
        largest_element_index = left_child_index;
    }

    if((right_child_index < N) && (arr[largest_element_index] < arr[right_child_index])) {
        largest_element_index = right_child_index;
    }

    if (largest_element_index != i) {
        arr[largest_element_index] ^= arr[i] ^= arr[largest_element_index] ^= arr[i];
        if(largest_element_index <= ((N - 2) >> 1)) {
            heapify_v1(arr, N, largest_element_index);
        }
    }
}

void buildheap(int arr[], int N) {
    int swap_end_node_index = ((N - 2) >> 1);
    for(int i = swap_end_node_index; i >= 0; --i) {
        heapify_v1(arr, N, i);
    }
}

int main() {
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int N = sizeof(arr)/(sizeof(int));
    // heapify(arr, N);

    buildheap(arr, N);

    for(int i = 0; i < N; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "done\n";
    return 0;
}
