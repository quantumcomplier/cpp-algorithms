<h1>Clinic Staff Report Program</h1>

<p>
A C++ project demonstrating inheritance, composition, operator overloading, and structured input validation. 
The program collects and stores information about a medical clinic, its doctor, and a team of nurses, then 
outputs a formatted personnel report.
</p>

<hr>

<h2>Overview</h2>

<ul>
  <li><strong>Clinic</strong> – stores general clinic information, a doctor, and a list of nurses</li>
  <li><strong>Doctor</strong> – inherits from Person and adds title, compensation, and ownership date</li>
  <li><strong>Nurse</strong> – inherits from Person and adds specialty, position, salary, and hire date</li>
  <li><strong>Person</strong> – base class containing shared attributes (name, city, state, birthdate)</li>
  <li><strong>Date</strong> – utility class used throughout the project for date handling</li>
</ul>

<hr>

<h2>Features</h2>

<ul>
  <li>Object‑oriented design using inheritance and composition</li>
  <li>Input validation for names, titles, dates, and numeric fields</li>
  <li>Support for realistic punctuation in names and titles</li>
  <li>Storage and sorting of multiple nurse records</li>
  <li>Formatted output using &lt;iomanip&gt;</li>
  <li>Guardrails for minimum/maximum nurse counts (3–5)</li>
  <li>Operator overloading for printing Date objects</li>
</ul>

<hr>

<h2>File Structure</h2>

<pre>
oop/clinic_project/
│
├── Person.cpp
├── Person.h
├── Doctor.cpp
├── Doctor.h
├── Nurse.cpp
├── Nurse.h
├── Clinic.cpp
├── Clinic.h
├── Date.cpp
├── Date.h
├── clinicDriver.cpp
└── README.md
</pre>

<hr>

<h2>How It Works</h2>

<ol>
  <li>The program begins by collecting general clinic information.</li>
  <li>A menu allows the user to enter doctor information, nurse information, list the full report, or exit.</li>
  <li>All input is validated to prevent invalid or blank entries.</li>
  <li>Nurse records are stored in a vector inside the Clinic class.</li>
  <li>When listing the clinic information, nurses are sorted and displayed with their details.</li>
  <li>The program enforces the requirement of at least 3 nurses before exiting.</li>
</ol>

<hr>

<h2>Concepts Demonstrated</h2>

<ul>
  <li>Class design and encapsulation</li>
  <li>Inheritance (Doctor and Nurse from Person)</li>
  <li>Composition (Clinic contains Doctor, Nurse, and Date objects)</li>
  <li>Operator overloading for formatted date output</li>
  <li>Dynamic data storage using std::vector</li>
  <li>Robust input validation</li>
  <li>Modular project structure</li>
</ul>

<hr>

<h2>Notes</h2>

<p>
This project follows the formatting and validation rules required by the course and demonstrates 
understanding of object‑oriented programming in C++.
</p>
