/*
    * File name: 			 TrainingCourses.java      
    * Author:				 Mihai Carare
    * Description of class: Represents a node in a linked list using generics.
    */
package application;

import java.util.*;

import dataStructures.LinkedList;

public class TrainingCourses {
	Employee temp = new Employee();
	LinkedList<Employee> employeeList = new LinkedList<Employee>();

	public TrainingCourses() {
		// 1. Allow User to input employees with error checking
		addEmployees();
		// 2. Display all employee details
		displayEmployees();
		// 3. Remove an employee from a training course depending on their employee
		// number
		removeEmployee();
		// 4. Display all employees on training courses
		displayEmpOnCourses();
		// .5 Delete All employees from a specified course
		deleteEmpFromCourse();
		// 6. Display the remaining employees
		displayEmployees();
	}

	public void addEmployees() {

		Scanner sc = new Scanner(System.in);

		int employees = 0;
		System.out.println("How many employees would you like to input? You can only input up to 10.");
		do {
			while (!sc.hasNextInt()) {
				System.out.println("Please enter a number!");
				sc.nextLine();
			}
			employees = sc.nextInt();
			sc.nextLine();
			if (employees > 10 || employees < 1) {
				System.out.println("The number must be between 1 and 10!");
			}

		} while (employees > 10 || employees < 1);

		String number, name, course;
		int years;

		for (int x = 0; x < employees; x++) {
			System.out.println("Please enter details of the employee number " + (x + 1) + ".");
			System.out.println("Employee Number:");
			number = sc.nextLine();
			System.out.println("Name:");
			name = sc.nextLine();
			System.out.println("Years of working in the organisation:");
			years = sc.nextInt();
			sc.nextLine();
			while (years < 5) {
				System.out.println("Employee Must have over 5 years of experience to be allowed on the course!");
				years = sc.nextInt();
				sc.nextLine();
			}

			System.out.println("Name of the course:");
			course = sc.nextLine();
			if (!course.substring(0, 4).equalsIgnoreCase("food")) {
				course = "ERROR";
				System.out.println("You have entered an invalid course name and its been set to error!");
			}

			temp = new Employee(number, name, course, years);

			employeeList.add(temp);

		}
	}

	public void displayEmployees() {
		System.out.println(employeeList.toString());

	}

	public void removeEmployee() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Please choose the employee you would like to remove by entering their Employee Number.");
		String empNum = "";
		empNum = sc.nextLine();
		sc.close();
		for (int i = 0; i < employeeList.size(); i++) {
			if (employeeList.get(i).getNumber().equals(empNum)) {
				employeeList.remove(employeeList.get(i));
				break;
			}
		}

	}

	public void displayEmpOnCourses() {
		System.out.println("Employees on training courses are:");
		for (int i = 0; i < employeeList.size(); i++) {
			if (!employeeList.get(i).getCourse().equals("ERROR")) {
				System.out.println(employeeList.get(i).toString());
			}
		}
	}

	public void deleteEmpFromCourse() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Please enter the Course from which you would like to delete all employees from.");
		String course = "";
		course = sc.nextLine();
		for (int x = 0; x < employeeList.size(); x++) {
			for (int i = 0; i < employeeList.size(); i++) {
				sc.close();
				if (employeeList.get(i).getCourse().equals(course)) {
					employeeList.remove(employeeList.get(i));
				}
			}
		}
	}

	public static void main(String[] args) {
		new TrainingCourses();
	}
}
