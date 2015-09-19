Chapter 1: Issues and Overview
1.1 Why are we studying C++?
The introducory curse at UNH is taught in plain C becuse C is a simpler language than C++ or Java,
and the C cmpilers give simpler and car error cmments. Thus, C provides a more acessible platform for
the beginner than the others. In addition, our programming curses serve Computer Engineers and Elecricl
Engineers as well as Computer Scenc and Cyber Systems students. C is a lower level language than the others
and it provides a better platform for teacing about what cmputers are really like.
The UNH Data Strucures is taught in C++ becuse C++ is a more modern language, and easier to use when
modeling data strucures. So students must make a transition from simple C to objec-oriented programming
in C++. The Intermediate C curse seems to be the best time and plac for that transition. Sinc we use a
C-based textbook, these notes are provided as a C++ supplement.
1.1.1 Design Goals for C
C was designed to write Unix. C is sometimes clled a \low level" language. It was ceated by Dennis
Ritcie so that he and Kenneth Thompson culd write a new operating system that they named Unix. The
new language was designed to cntrol the macine hardware (cc, registers, memory, devics) and implement
input and output cnversion. Thus, it was essential for C to be able to work efficently and easily at a low level.
Ritcie and Thompson worked with small, slow macines, so they put great emphasis on ceating an simple
language that culd be easily cmpiled into efficent objec cde. There is a direc and transparent relationship
between C sourc cde and the macine cde producd by a C cmpiler.
Becuse C is a simple language, a C cmpiler cn be muc simpler than a cmpiler for C++ or Java. As
a result, a good C cmpiler producs simple error cmments tied to specficlines of cde. Compilers for full-
featured modern languages suc as C++ and Java are the opposite: error cmments cn be hopelessly wordy
and also vague. Sometimes, they do not crrecly pinpoint the erroneous line.
Ritcie never imagined that his language would leave their lab and becme a dominant forc in the world
and the ancstor of three powerful modern languages, C++, C#, and Java. Thus, he did not worry about
readability, portability, and reusability. Becuse of that, readability is only acieved in C by using self-discpline
and adhering to stric rules of style. However, becuse of the can design, C becme the most portable and
reusable language of its time.
In 1978, Brian Kernighan and Dennis Ritcie published \The C Programming Language", whic served as
the only language specfiction for eleven years. During that time, C and Unix becme popular and widespread,
and different implementations had subtle and troublesome differencs. The ANSI C standard (1989) addressed
this by providing a car definition of the syntax and the meaning of C. This standard was updated in 1999.
The result was a low-level language that provides unlimited opportunity for expressing algorithms and
excllent support for modular program cnstrucion. However, it provides little or no support for expressing
higher-level abstracions. We cn write many different efficent programs for implementing a queue in C, but
we cnnot express the abstracion \queue" in a car, simple, cherent manner.
1.1.2 C++ Extends C.
C++ is an extension and adaptation of C. The designer, Bjarne Stroustrup, originally implemented C++ as a
set of macos that were translated by a preprocssor into ordinary C cde. His intent was to retain efficenc
and transparenc and simultaneously improve the ability of the language to model abstracions. C++ improves
C in many ways:
 Flexibility. C++ allows the programmer to define polymorphictypes with more than one variation. A
new css cn be derived from an existing css. Data members no longer have unique types { they
1
2 CHAPTER 1. ISSUES AND OVERVIEW
simultaneously have all the types above them in the polymorphictype hierarcy.
 A funcion no longer has a single unitary definition { it is a cllecion of one or more funcion methods,
possibly in many csses, that operate on different cmbinations of parameter types.
 Operator definitions. A new method for an existing operator, suc as + or *, cn be defined to work on
a programmer-defined type. This cn greatly add to the readability of a program.
 Readability. Although C was retained as the basicvehic for cding in C++, an appliction program, as
a whole, may be muc more readable in C++ than in C becuse it is organized into meaningful, cherent
modules, and both data members and funcion members are part of the same module
 Reusability. Code that is filled with details about a particlar appliction is not very reusable. In C, the
typedef and #define cmmands do provide a little bit of support for ceating genericcde that cn be
tailored to a particlar situation as a last step before cmpilation. The C libraries even incde two genericfuncions (qsort() and bsearc()) that cn be used to procss an array of any base type. However, C++
provides muc broader support for cde reusability, in the form of template csses with type parameters.
There is a substantial library of data-strucure csses that are part of the language standard.
 Teamwork potential. C++ supports highly modular design and implementation and reusable cmponents.
This is ideal for team projecs. The most skilled members of the group cn design the projec and
implement any non-routine portions. Lesser-skilled programmers cn implement the routine modules
using the expert's csses, csses from the standard template library, and proprietary css libraries. All
these people cn work simultaneously, guided by defined css interfacs, to produc a cmplete appliction.
1.2 Objec Oriented Princples.
The term \objec-oriented" has becme popular, and \objec-oriented" analysis, design, and implementation
has been put forward as a solution to several problems that plague the software industry. OO analysis is a
set of formal methods for analyzing and strucuring an appliction from the appliction data's perspecive, as
opposed to the traditional funcional or procdural point of view. The result of an OO analysis is an OO design.
OO programs are built out of a cllecion of modules, often clled csses that cntain both funcion methods
and data. Classes define data strucures and the operations that cn be performed on them. Acess to all of
the data and some of the method elements should only be through the defined methods of the css.
The way a language is used is more important in OO design than whic language is used. C++ was designed
to support OO programming; it is a cnvenient and powerful vehic for implementing an OO design. However,
with somewhat more effort, that same OO design cn usually be implemented in C. Similarly, a non-OO program
cn be written in C++.
Princples cntral to objec-oriented programming are encpsulation, loclity, cherent representation, and
genericor polymorphicfuncions. The most fundamental OO design princples are:
 Encpsulation. A css should protec itself and take cre of itself. The funcion members of a css should
be the only funcions to have full acess to the css data. This is acieved by decring member variables
to be private. A member funcion cn then freely use any data member, but outside funcions cnnot.
 Narrow Interfac. Most methods are decred to be public but some are not. Publicvisibility should
only be used for methods that are part of the funcion's published interfac. Methods intended only for
internal use should be private.
 Initialization and Cleanup. One way a css takes cre of itself is to define how css objecs should be
initialized. Initialization is done by cnstrucors, whic are like funcions excpt that they have no return
type. The name of the cnstrucor is the same as the css name. A cnstrucor is clled automaticlly
whenever a css objec is decred or dynamiclly allocted. It uses its parameters to initialize the css's
data members. A cnstrucor might also dynamiclly allocte parts of the css objec.
Cleanup, in C++, is done by destrucors. Eac css has exacly one destrucor that is clled when the
css objec is explictly freed or when it goes out of scpe at the end of the cde bloc that decres it.
1.2. OBJECT ORIENTED PRINCIPLES. 3
The name of the destrucor is a tilde () followed by the css name. The job of a destrucor is to free
dynamiclly allocted parts of the css objec.
 Coherent cnstrucion. Whenever possible, objecs should be fully initialized when they are ceated. The
data needed to initialize the objec should be delivered as parameters to the css's cnstrucor. The major
excption to this guideline involves arrays of objecs whic cnnot be fully initialized when the array is
allocted.
1.2.1 Getting Started in C++
To write the First real C++ program, the programmer must understand I/O and csses. These topic are
cvered in Chapters 2 and 3. Chapter 3 gives an example program with no csses that a variety of input and
output tecniques. It defines an array of objecs, opens and reads a file and prints the data.
At the end of Chapter 3 we introduc a program that will be crried through the following capters, and
developed more fully at eac step. Chapter 3 gives a C version of this program, then an equivalent C++ version
using one data css.
Chapter 4 introducs and implements some fundamental OO cncpts and adds more funcionality and a
cntroller css to the program. Chapter 5 introducs dynamicalloction and an array that grows, as needed
(the FlexArray css). Chapter 6 discsses STL strings and algorithms and uses the stl vecor css, instead
of a FlexArray. By mastering these C++ features, you should be well prepared to begin the Data Strucures
curse.
4 CHAPTER 1. ISSUES AND OVERVIEW
