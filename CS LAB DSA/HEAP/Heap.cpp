#include<bits/stdc++.h>
using namespace std;
class MinHeap{
    int *harr;
    int capacity;
    int heap_size;
public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        heap_size = 0;
        harr = new int[capacity];
    }

    void minHeapify(int s);

    void insertKey(int val);

    void deleteKey(int i);

    int extractMin();

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    int getMin()
    {
        return harr[0];
    }

    void decreaseKey(int i, int new_val);

};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void MinHeap::minHeapify(int s)
{
    int l = left(s);
    int r = right(s);
    int smallest = s;
    if(l < heap_size && harr[l] < harr[smallest])
        smallest = l;
    if(r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if(smallest != s)
    {
        swap(&harr[smallest], &harr[s]);
        minHeapify(smallest);
    }
}

void MinHeap::insertKey(int val)
{
    if(heap_size == capacity)
    {
        cout << "\nOverflow" << endl;
        return;
    }

    harr[heap_size++] = val;
    int i = heap_size - 1;
    while(i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int k)
{
    decreaseKey(k, INT_MIN);
    extractMin();
}

void MinHeap::decreaseKey(int k, int new_val)
{
    harr[k] = new_val;
    int i = k;
    while(i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin()
{
    if(heap_size <= 0)
        return INT_MAX;
    if(heap_size == 1)
        return harr[--heap_size];
    int root = harr[0];
    harr[0] = harr[--heap_size];
    minHeapify(0);
    return root;
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}

