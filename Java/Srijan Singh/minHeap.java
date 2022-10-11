// Java Program to Implement Heaps
// by Illustrating Min Heap

// Main class (MinHeap)
class minHeap {

    // Member variables of this class
    private int[] Heap;
    private int size;
    private int maxsize;

    // Initializing front as static with unity
    private static final int FRONT = 1;

    // Constructor of this class
    public minHeap(int maxsize) {

        // This keyword refers to current object itself
        this.maxsize = maxsize;
        this.size = 0;

        Heap = new int[this.maxsize + 1];
        Heap[0] = Integer.MIN_VALUE;
    }

    // Method 1
    // Returning the position of
    // the parent for the node currently
    // at pos
    private int parent(int pos) {
        return pos / 2;
    }

    // Method 2
    // Returning the position of the
    // left child for the node currently at pos
    private int leftChild(int pos) {
        return (2 * pos);
    }

    // Method 3
    // Returning the position of
    // the right child for the node currently
    // at pos
    private int rightChild(int pos) {
        return (2 * pos) + 1;
    }

    // Method 4
    // Returning true if the passed
    // node is a leaf node
    private boolean isLeaf(int pos) {

        if (pos > (size / 2)) {
            return true;
        }

        return false;
    }

    // Method 5
    // To swap two nodes of the heap
    private void swap(int fpos, int spos) {

        int tmp;
        tmp = Heap[fpos];

        Heap[fpos] = Heap[spos];
        Heap[spos] = tmp;
    }

    // Method 6
    // To heapify the node at pos
    private void minHeapify(int pos) {
        if (!isLeaf(pos)) {
            int swapPos = pos;
            // swap with the minimum of the two children
            // to check if right child exists. Otherwise default value will be '0'
            // and that will be swapped with parent node.
            if (rightChild(pos) <= size)
                swapPos = Heap[leftChild(pos)] < Heap[rightChild(pos)] ? leftChild(pos) : rightChild(pos);
            else
                swapPos = Heap[leftChild(pos)];

            if (Heap[pos] > Heap[leftChild(pos)] || Heap[pos] > Heap[rightChild(pos)]) {
                swap(pos, swapPos);
                minHeapify(swapPos);
            }

        }
    }

    // Method 7
    // To insert a node into the heap
    public void insert(int element) {

        if (size >= maxsize) {
            return;
        }

        Heap[++size] = element;
        int current = size;

        while (Heap[current] < Heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    // Method 8
    // To print the contents of the heap
    public void print() {
        for (int i = 1; i <= size / 2; i++) {

            // Printing the parent and both childrens
            System.out.print(
                    " PARENT : " + Heap[i]
                            + " LEFT CHILD : " + Heap[2 * i]
                            + " RIGHT CHILD :" + Heap[2 * i + 1]);

            // By here new line is required
            System.out.println();
        }
    }

    // Method 9
    // To remove and return the minimum
    // element from the heap
    public int remove() {

        int popped = Heap[FRONT];
        Heap[FRONT] = Heap[size--];
        minHeapify(FRONT);

        return popped;
    }

    // Method 10
    // Main driver method
    public static void main(String[] arg) {

        // Display message
        System.out.println("The Min Heap is ");

        // Creating object opf class in main() methodn
        minHeap minHeap = new minHeap(15);

        // Inserting element to minHeap
        // using insert() method

        // Custom input entries
        minHeap.insert(5);
        minHeap.insert(3);
        minHeap.insert(17);
        minHeap.insert(10);
        minHeap.insert(84);
        minHeap.insert(19);
        minHeap.insert(6);
        minHeap.insert(22);
        minHeap.insert(9);

        // Print all elements of the heap
        minHeap.print();

        // Removing minimum value from above heap
        // and printing it
        System.out.println("The Min val is "
                + minHeap.remove());
    }
}
