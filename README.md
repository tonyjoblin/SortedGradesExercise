# SortedGradesExercise

A c++ console app that
* Takes as a parameter a string that represents a text file containing a list of names, and their scores.
* Orders the names by their score. If scores are the same, order by their last name followed by first name.
* Creates a new text file called <input-file-name>-graded.txt with the list of sorted score and names.
 
For example, if the input file contains
BUNDY, TERESSA, 88
SMITH, ALLAN, 70
KING, MADISON, 88
SMITH, FRANCIS, 85
 
Then the output file would be
BUNDY, TERESSA, 88
KING, MADISON, 88
SMITH, FRANCIS, 85
SMITH, ALLAN, 70

## Notes
* allows fractional/decimal grades like 88.5
* scores must be non negative
* ignores text after the grade 
* ignores empty lines
* lines of input must have first and last name and a score.
* missing first or last name not allowed.

## Dependencies
* requires boost, for now assumed to be C:\boost_1_60_0

