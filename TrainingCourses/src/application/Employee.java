/*
 * File name: 			 Employee.java
 */

package application;

public class Employee {

	private String number, name, course;// (Employee Number,Their Name,Name of the course)
	private int years;// (Years of working in the organization)
	// ---------------------------------------------------------
	// Creates two constructors one with and one without parameters.
	// ---------------------------------------------------------

	public Employee() {

	}

	public Employee(String number, String name, String course, int years) {
		this.number = number;
		this.name = name;
		this.course = course;
		this.years = years;
	}

	// ---------------------------------------------------------
	// Getter and Setter Methods
	// ---------------------------------------------------------
	public String getNumber() {
		return this.number;
	}

	public void setNumber(String number) {
		this.number = number;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getCourse() {
		return course;
	}

	public void setCourse(String course) {
		this.course = course;
	}

	public int getYears() {
		return years;
	}

	public void setYears(int years) {
		this.years = years;
	}

	public String toString() {
		return "Employee Number: " + this.number + "\n" + "Employee Name: " + this.name + "\n" + "Course Number: "
				+ this.course + "\n" + "Years of Work: " + this.years + "\n";
	}

	public boolean equals(Object obj) {
		Employee compareEmp = (Employee) obj;
		if (this.number.equals(compareEmp.getNumber())) {
			return true;
		}
		return false;
	}
}