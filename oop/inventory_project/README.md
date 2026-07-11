<h1>Inventory Report Program</h1>

<p>
This assignment focuses on practicing dynamic memory, pointers, and object management in C++. 
The program allows the user to enter product information for an electronics shop, stores each product 
as a dynamically allocated object, and generates a formatted inventory report.
</p>

<hr>

<h2>Overview</h2>

<p>
The project demonstrates how to:
</p>

<ul>
  <li>Allocate and deallocate objects using <code>new</code> and <code>delete</code></li>
  <li>Use an array of pointers to manage multiple objects</li>
  <li>Validate user input for strings, integers, and doubles</li>
  <li>Generate random quantities using <code>srand()</code> and <code>rand()</code></li>
  <li>Format output using <code>&lt;iomanip&gt;</code></li>
  <li>Encapsulate product data inside a dedicated <code>Product</code> class</li>
</ul>

<hr>

<h2>Files Included</h2>

<pre>
oop/week6_inventory_project/
│
├── Product.cpp
├── Product.h
├── ProductDriver.cpp
└── README.md
</pre>

<hr>

<h2>Program Flow</h2>

<ol>
  <li>User enters the name of the electronics shop.</li>
  <li>User enters how many products to record (2–5).</li>
  <li>The program dynamically allocates an array of <code>Product*</code>.</li>
  <li>For each product:
    <ul>
      <li>Prompt for name (non‑blank)</li>
      <li>Prompt for category (non‑blank)</li>
      <li>Prompt for price (100.00–1000.00)</li>
      <li>Generate a random quantity (5–10)</li>
      <li>Store the object pointer in the array</li>
    </ul>
  </li>
  <li>A formatted inventory report is displayed.</li>
  <li>Total inventory value is calculated and shown.</li>
  <li>All dynamically allocated memory is cleaned up.</li>
</ol>

<hr>

<h2>Key Concepts Demonstrated</h2>

<ul>
  <li>Dynamic memory allocation</li>
  <li>Pointers to objects</li>
  <li>Arrays of pointers</li>
  <li>Input validation functions</li>
  <li>Encapsulation and class design</li>
  <li>Random number generation</li>
  <li>Formatted console output</li>
</ul>

<hr>

<h2>Notes</h2>

<p>
This project was completed as part of CSIS 112 and follows the formatting, validation, and memory 
management requirements outlined in the assignment. It serves as preparation for later projects 
involving more advanced object‑oriented design.
</p>

