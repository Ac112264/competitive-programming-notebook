import java.lang.RuntimeException;

/*
 * Binary min heap implemented using arrays
 * Since a binary heap is a complete binary-tree, it can be implemented efficiently using
 * an array without pointers and without wasting a lot of memory.
 * The root of the heap is placed at index 1, and index 0 is sacrificed to make room for simplicity.
 * Each element at index i has:
 * 	- Its children (left and right) at 2*i and 2*i+1
 * 	- Its parent at floor(i/2)
 */
public class Heap<C extends Comparable<?super C>> {
	private C[] arr;
	private int currentSize;

	public Heap(int size){
		// Size of array is N + 1, since index 0 is unused
		arr = (C[]) new Comparable[size+1];
		currentSize = 0;
	}

	public boolean isFull() { return currentSize == arr.length; }
	public boolean isEmpty() { return currentSize == 0; }

	// insert(): Add to heap
	// Precondition: Not full
	public void insert(C data) {
		// Throw exception if full
		if (isFull()) { throw new RuntimeException("Queue is full"); }

		// Taken from Weiss, Ch. 6.3
		// Percolate up
		int hole = ++currentSize; // Increment size
		// Use element 0 as scratch, since that is not used
		arr[0] = data;
		// Make the hole where the data should go, so it doesn't violate the heap order property
		while (data.compareTo(arr[hole / 2]) < 0) {
			arr[hole] = arr[hole / 2];
			hole /= 2;
		}
		// Insert data
		arr[hole] = data;
	}

	// min(): Return minimum
	// Precondition: Not empty
	public C min() {
		// Throw exception if empty
		if (isEmpty()) { throw new RuntimeException("Queue is empty"); }

		// Return root
		return arr[1];
	}

	// deleteMin(): Remove minimum and return
	// Precondition: Not empty
	public C deleteMin() {
		// Throw exception if empty
		if (isEmpty()) { throw new RuntimeException("Queue is empty"); }

		// Save minimum to return at the end
		C min = min();
		// Move last element to the root and decrement size
		arr[1] = arr[currentSize--];
		// Percolate down
		percolateDown(1, currentSize);

		return min;
	}

	// percolateDown() for Comparables
	// 1-based heap
	private void percolateDown(int start, int end) {
		int child;
		int hole = start;
		// Original hole
		C startHole = arr[hole];

		// Modified from Weiss, Ch. 6.3
		// While there is at least one chlid
		while (hole * 2 <= end) {
			child = hole * 2;
			if (child != end && arr[child+1].compareTo(arr[child]) < 0) {
				child++;
			}
			if (arr[child].compareTo(startHole) < 0) {
				// Shift the child up
				arr[hole] = arr[child];
			}
			else {
				break;
			}

			// Move hole down
			hole = child;
		}

		arr[hole] = startHole;
	}

}
