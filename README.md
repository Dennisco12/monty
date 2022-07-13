# monty
Tasks on stack and queue

**THE MONTY LANGUAGE**
Monty 0.98 is a scripting language that is first compiled into monty byte code (Just like python). It relies on a unique stack with specific instructions to manipulate it. The goal of this project is to create an intepreter for monty bytecode files

Usage: monty <filename>
The monty program runs the bytecode line by line and stops if either:
  It executed properly every line of the file,
  It finds an error on the file,
  An error occurs.
