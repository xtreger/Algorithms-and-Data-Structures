/*
 * File name: 			 LinearNode.java      
 */

package dataStructures;

public interface LinkedListADT<T> {
	// Adds one element to the start or end of this list
	public void add(T element);

	// Removes and returns the first element from this list
	public T remove();

	// Returns true if this list contains no elements
	public boolean isEmpty();

	// Returns the number of elements in this list
	public int size();

	// Returns a string representation of this list
	public String toString();

}
