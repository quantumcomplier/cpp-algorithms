<h1>Secret Journal Encryption/Decryption Program</h1>

<p>
This project implements a Vigenère-style cipher to encrypt and decrypt text files. 
The program loads journal entries from a file, processes them using a user-provided key, and 
saves the encrypted or decrypted results to an output file.
</p>

<hr>

<h2>Overview</h2>

<p>
The project demonstrates:
</p>

<ul>
  <li>File input/output using <code>ifstream</code> and <code>ofstream</code></li>
  <li>String trimming, whitespace handling, and quote stripping</li>
  <li>Tokenizing text using <code>strtok_s</code></li>
  <li>Validating encryption keys (alphabetic only)</li>
  <li>Using the <code>ProcessJournal</code> class to manage journal entries</li>
  <li>Using the <code>CypherVigenere</code> class to perform encryption/decryption</li>
  <li>Displaying processed text and word counts</li>
</ul>

<hr>

<h2>Files Included</h2>

<pre>
week5_secret_journal/
│
├── SecretJournalDriver.cpp
├── ProcessJournal.cpp
├── ProcessJournal.h
├── CypherVigenere.cpp
├── CypherVigenere.h
└── README.md
</pre>

<hr>

<h2>Program Flow</h2>

<ol>
  <li>User enters an alphabetic encryption/decryption key.</li>
  <li>Main menu options:
    <ul>
      <li><strong>E</strong> – Encrypt and save</li>
      <li><strong>D</strong> – Decrypt and save</li>
      <li><strong>C</strong> – Close journal</li>
    </ul>
  </li>
  <li>Program loads a text file into memory.</li>
  <li>Text is copied into a character buffer and tokenized.</li>
  <li><code>ProcessJournal</code> encrypts or decrypts the buffer using <code>CypherVigenere</code>.</li>
  <li>Processed text is displayed and saved to an output file.</li>
  <li>Word count is calculated and shown.</li>
</ol>

<hr>

<h2>Key Concepts Demonstrated</h2>

<ul>
  <li>File processing</li>
  <li>String manipulation</li>
  <li>Character buffer handling</li>
  <li>Tokenizing with <code>strtok_s</code></li>
  <li>Basic encryption/decryption logic</li>
  <li>Menu-driven program design</li>
</ul>

<hr>

<h2>Notes</h2>

<p>
This project was completed as part of CSIS 112 and follows the formatting, validation, and 
processing requirements outlined in the assignment. It serves as preparation for later projects 
involving dynamic memory and object-oriented programming.
</p>

