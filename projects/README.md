<h1>Hotel Room Availability & Management Program</h1>

<p>
This project implements a menu‑driven hotel management system that allows a manager to 
enter hotel information, update room details, validate input, and generate a formatted 
room availability report. The program demonstrates object composition, structured data 
handling, and menu‑based user interaction.
</p>

<hr>

<h2>Overview</h2>

<p>
The application uses two primary classes:
</p>

<ul>
  <li><strong>Hotel</strong> – stores hotel information and manages a collection of rooms</li>
  <li><strong>Room</strong> – represents individual rooms with number, capacity, type, status, and rate</li>
</ul>

<p>
The manager can update rooms, list all rooms, and view a formatted availability report. 
Input validation ensures correct room numbers, capacities, types, statuses, and rates.
</p>

<hr>

<h2>Files Included</h2>

<pre>
projects/hotel_manager/
│
├── Hotel.h
├── Hotel.cpp
├── Room.h
├── Room.cpp
├── MiscCommon.h
├── SecretJournalDriver.cpp   (main program file)
└── README.md
</pre>

<hr>

<h2>Program Flow</h2>

<ol>
  <li>Manager enters hotel information:
    <ul>
      <li>Hotel name</li>
      <li>Opening date (validated MM/DD/YYYY)</li>
      <li>Minimum number of rooms (3–5)</li>
      <li>City and state</li>
    </ul>
  </li>

  <li>The manager menu provides:
    <ul>
      <li><strong>I</strong> – Update a room</li>
      <li><strong>R</strong> – List all rooms</li>
      <li><strong>E</strong> – Exit</li>
    </ul>
  </li>

  <li>Room updates include:
    <ul>
      <li>Room number (validated ranges: 101–199, 201–299, 301–399)</li>
      <li>Capacity (1–4)</li>
      <li>Type (Single, Double, Suite)</li>
      <li>Status (Available, Reserved, Occupied)</li>
      <li>Rate (199, 101, or 268)</li>
    </ul>
  </li>

  <li>Rooms are stored in a vector inside the <code>Hotel</code> object.</li>
  <li>Rooms are sorted by room number before listing.</li>
  <li>A formatted report displays hotel information and all room details.</li>
</ol>

<hr>

<h2>Key Concepts Demonstrated</h2>

<ul>
  <li>Object composition (Hotel contains Room objects)</li>
  <li>Vectors of objects</li>
  <li>Sorting with lambda expressions</li>
  <li>Input validation for numeric and string fields</li>
  <li>Menu‑driven program design</li>
  <li>Formatted console output using <code>&lt;iomanip&gt;</code></li>
</ul>

<hr>

<h2>Notes</h2>

<p>
This project was completed as part of CSIS 112 and demonstrates structured object 
composition, validation, and formatted reporting. It serves as a practical example 
of building a menu‑based application using multiple classes.
</p>

