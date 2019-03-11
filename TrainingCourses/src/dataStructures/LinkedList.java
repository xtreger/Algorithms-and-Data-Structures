/*
    * File name: 			 LinkedList.java      
    */
package dataStructures;

//This class implements the ADT definition of a linked list using the same signatures. Note that we can add extra methods
//here once all of the methods listed in the ADT interface are included.

public class LinkedList<T> implements LinkedListADT<T> {

	private int count; // the current number of elements in the list
	private LinearNode<T> list; // pointer to the first element
	private LinearNode<T> last; // pointer to the last element

	// -----------------------------------------------------------------
	// Creates an empty list.
	// -----------------------------------------------------------------
	public LinkedList() {
		this.count = 0;
		this.last = null;
		this.list = null;
	}

	// 1
	// Adds one element to the end of this list
	public void add(T element) {
		LinearNode<T> node = new LinearNode<T>(element);

		if (size() == 0) {
			this.last = node; // This is the last and the
			this.list = node; // first node
			this.count++;
		} // end if
		else {
			last.setNext(node); // add node to the end of the list
			last = node; // now make this the new last node.
			count++;
		}
	}

	// 2
	// method to add a node into a specific index in the list
	public void add(T element, int index) {
		LinearNode<T> cur = this.list;
		LinearNode<T> pre = null;
		// if the index is 0 add node to the start of the list set the initial first
		// element to current
		// then create another node which stores element then link the new first element
		// to current
		if (index - 1 == 0) {
			this.list = new LinearNode<>(element);
			this.list.setNext(cur);
			count++;
			return;
		}
		// if the index is not 0
		// similar to the one above but also link the new previous number to the current
		// added node
		for (LinearNode<T> current = this.list; current != null; current = current.getNext()) {
			if (index - 1 == 0) {
				cur = current;
				current = new LinearNode<>(element);
				current.setNext(cur);
				pre.setNext(current);
				count++;
				return;
			}

			pre = current;
			index--;
		}
	}

	// 3
	// Removes and returns the first element from this list
	public T remove() {
		T result = null;
		if (isEmpty()) {
			System.out.println("There are no nodes in the list");
		} // end if
		else {
			result = this.list.getElement();
			this.list = this.list.getNext();
			count--;
		} // end else
		return result;

	}

	// 3
	public void remove(T elementToBeRemoved) {
		LinearNode<T> index = null;

		for (LinearNode<T> current = this.list; current != null; current = current.getNext()) {
			if (current.getElement().equals(elementToBeRemoved)) { // if the node to be removed is found check whether
																	// its first last or in the middle

				if (index == null) { // first
					this.list = this.list.getNext(); // set first element to current first element +1
					count--;
					return;
				}

				if (current.getNext() == null) { // last
					this.last = index; // set the last element to current last element -1
					index.setNext(null);
					count--;
					return;
				}

				index.setNext(current.getNext()); // middle
				count--;
			}

			else // node moves to next
				index = current;

		} // end for
	}

	// 8
	// Returns true if this list contains no elements
	public boolean isEmpty() {
		if (this.list == null)
			return true;
		else
			return false;
	}

	// Returns the number of elements in this list
	public int size() {
		return this.count;
	}

	// Returns a string representation of this list
	// 4
	public String toString() {
		LinearNode<T> current = this.list;
		String fullList = "";

		for (current = this.list; current != null; current = current.getNext()) {
			fullList = fullList + "\n" + current.getElement().toString();
		} // end for

		return fullList + "\n";
	}

	// Extra method in the linked list to return the element depending on their
	// position in the list
	// useful for accessing the nodes easier
	public T get(int x) {

		LinearNode<T> index = this.list;
		int pos = 0;
		T elementToBeReturned = null;

		while (index != null) {

			if (pos == x) {
				elementToBeReturned = index.getElement();
				break;
			}

			pos++;
			index = index.getNext();

		}

		if (elementToBeReturned == null) {
			System.out.println("Object doesn't exist");
		}
		return elementToBeReturned;
	}

	// 9
	// Check if this list already contains an generic object
	public boolean contains(T cont) {
		LinearNode<T> index;

		for (index = this.list; index != null; index = index.getNext()) {
			if (index.getElement().equals(cont)) {
				return true;
			}
		}
		return false;
	}

	// 5
	// Return the first generic object in the list
	public T returnFirst() {
		return this.list.getElement();
	}

	// 6
	// Return the last generic object in the list
	public T returnLast() {
		return this.last.getElement();
	}

	// 7
	// Return the next generic object where the current object is passed as
	// parameter
	public T next(T nextOfThisElem) {
		T next = null;
		for (LinearNode<T> index = this.list; index != null; index = index.getNext()) {
			if (index.getElement().equals(nextOfThisElem) && index.getNext() != null) {
				next = index.getNext().getElement();
			}
		}
		return next;
	}

}
