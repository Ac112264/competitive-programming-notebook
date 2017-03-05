public class HeapSort {
	public static <C extends Comparable<?super C>> void heapSort(C[] arr) {
		// Modified from Weiss, Ch. 7.5
		// Heapify: build the heap, starting from the middle
		for (int i = arr.length / 2 - 1; i >= 0; i--) {
			percolateDown(arr, i, arr.length);
		}
		for (int i = arr.length - 1; i > 0; i--) {
			// Delete min by swapping arr[0] and arr[i]
			C tmp = arr[0];
			arr[0] = arr[i];
			arr[i] = tmp;

			percolateDown(arr, 0, i);
		}

	}

	// percolateDown()
	// 0-based heap
	private static <C extends Comparable<?super C>> void percolateDown(C[] arr, int start, int end) {
		int child;
		int hole = start;
		// Original hole
		C startHole = arr[hole];

		// Modified from textbook
		// While there is at least one child (just check left child)
		while ((hole * 2 + 1) < end) {
			child = hole * 2 + 1; // left child
			if ((child != end - 1) && (arr[child+1].compareTo(arr[child]) < 0)) {
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
