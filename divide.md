#Divide

Divide is used to calculate which index plates (and how many holes are needed to
move by) when using a dividing head or index plates with a rotary table.

Usage:

```./divide <divisions> <ratio> [hole-pattern-file]```

`<divisions>` is the number of divisions you wish to divide, such as 30 if you
wanted to cut a 30T gear, or 6 if you wanted to mill a hex shape on some round
material.

`<ratio>` is the reduction ratio, typically this is '40', '60' or '90', but some
low cost rotary tables are '36'.

`[hole-pattern-file]` is an optional input to provide a file containing a list
of hole patterns available. They are specified as just a list of numbers. If the
file is not specified, the program looks for 'divide-holes.txt'. Common plates
for Browne and Sharpe and Cincinnati dividing heads have been included. These
files can be edited or new ones created if you make your own plates.

## Example Usage 1:

Keith wishes to create a 96T gear for a clock wheel, and has a Cincinnati
dividing head available with a 40:1 ratio:

```
$ ./divide 96 40 divide-holes-cincinnati.txt
divisions: (96), ratio: (40), input-file: (divide-holes-cincinnati.txt)
(40 * 24) / 96 = 10 | Use 24 plate and index 10 holes at a time
$
```

Keith can use the 24 hole pattern, and set the sector arms to 10 holes.

## Example Usage 2

Adam has a 40:1 import rotary table with both B&S and Cincinnati plates, and
wishes to cut 150 graduations for a new handwheel for his lathe:
```
$$ ./divide 150 40
divisions: (150), ratio: (40), input-file: (divide-holes.txt)
(40 * 15) / 150 = 4 | Use 15 plate and index 4 holes at a time
$
$ ./divide 150 40 divide-holes-cincinnati.txt
divisions: (150), ratio: (40), input-file: (divide-holes-cincinnati.txt)
(40 * 30) / 150 = 8 | Use 30 plate and index 8 holes at a time
$
```

Adam can choose either the 15 hole pattern and index 4 holes with the sector
arms, or the 30 hole pattern and index 8 holes. He thanks Stefan for the
inspiration.

## Example Usage 3 - the tricky case:

Emma has a 36:1 import rotary table with both the B&S plates as well as
Cincinnati and wants to make an orrery that needs a 133T wheel:
```
$ ./divide 133 36 divide-holes-cincinnati.txt
divisions: (133), ratio: (36), input-file: (divide-holes-cincinnati.txt)
$
```
The Cincinnati plates aren't capable of producing this division with this
ratio, so Emma tries the B&S plates:
```
$ ./divide 133 36
divisions: (133), ratio: (36), input-file: (divide-holes.txt)
$
```
Unfortunately the B&S plates are also not capable for this division. Fortunately
Adam offers to machine a custom plate. Emma throws a few numbers into a file:

divide-holes-custom.txt
```
100
127
133
147
169
```
and tries again:
```
$ ./divide 133 36 divide-holes-custom.txt
divisions: (133), ratio: (36), input-file: (divide-holes-custom.txt)
(36 * 133) / 133 = 36 | Use 133 plate and index 36 holes at a time
$
```
Success! She has a few other hole patterns that don't fit standard plates, so
Adam makes them all on the one plate and Emma keeps this in her custom file.
