<h1>Pet Polymorphism Demonstration</h1>

<p>
This project is a proof‑of‑concept demonstration of inheritance and polymorphism in C++. 
The program allows the user to select three different pet types, dynamically allocates 
each pet using a base‑class pointer, and displays basic information about each pet. 
Constructor and destructor messages are printed to clearly show polymorphic behavior 
and object lifetime.
</p>

<hr>

<h2>Overview</h2>

<p>
The application uses a simple class hierarchy:
</p>

<ul>
  <li><strong>Pet</strong> – base class containing shared fields (name, birth year, weight)</li>
  <li><strong>Dog</strong> – derived class</li>
  <li><strong>Cat</strong> – derived class</li>
  <li><strong>Bird</strong> – derived class</li>
  <li><strong>Fish</strong> – derived class</li>
  <li><strong>Hamster</strong> – derived class</li>
</ul>

<p>
Each derived class overrides the <code>displayPetInfo()</code> function and prints constructor 
and destructor messages to illustrate polymorphic behavior.
</p>

<hr>

<h2>Files Included</h2>

<pre>
projects/pet_records/
│
├── Pet.h
├── Pet.cpp
├── Dog.h
├── Dog.cpp
├── Cat.h
├── Cat.cpp
├── Bird.h
├── Bird.cpp
├── Fish.h
├── Fish.cpp
├── Hamster.h
├── Hamster.cpp
├── PetRecordsDriver.cpp
└── README.md
</pre>

<hr>

<h2>Program Flow</h2>

<ol>
  <li>User selects three different pet types from a menu.</li>
  <li>For each pet:
    <ul>
      <li>Name is entered manually.</li>
      <li>Birth year is validated within a species‑specific range.</li>
      <li>Weight is randomly generated based on pet type.</li>
    </ul>
  </li>
  <li>The program dynamically allocates the correct derived object using <code>new</code>.</li>
  <li>Constructor messages print automatically, demonstrating object creation.</li>
  <li>After all three pets are selected, the program displays:
    <ul>
      <li>Name</li>
      <li>Type</li>
      <li>Weight</li>
      <li>Birth year</li>
      <li>Calculated age</li>
    </ul>
  </li>
  <li>Objects are deleted at the end of the program, triggering polymorphic destructors.</li>
</ol>

<hr>

<h2>Key Concepts Demonstrated</h2>

<ul>
  <li>Inheritance and derived classes</li>
  <li>Polymorphism using base‑class pointers</li>
  <li>Virtual destructors ensuring correct cleanup</li>
  <li>Constructor and destructor call order</li>
  <li>Dynamic memory allocation with <code>new</code> and <code>delete</code></li>
  <li>Basic virtual function structure (<code>displayPetInfo()</code>)</li>
  <li>Menu‑driven input and validation</li>
</ul>

<hr>

<h2>Notes</h2>

<p>
This project was completed as part of CSIS 112 and is intentionally designed as a 
lightweight demonstration of polymorphism rather than a full record‑keeping system. 
Its primary purpose is to show how derived objects behave when accessed through 
base‑class pointers and how constructors and destructors fire in a polymorphic hierarchy.
</p>
