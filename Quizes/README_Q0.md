# CS 0

Assignments/A1/Q0

@@ -1,86 +1,18 @@
#include <iostream>
#include <namespace>



for ( i=54; i == 74; i+=2 )


for ( i=100; i<=110; ++i )


for ( i=100; i>80; i-=2 )


for ( i= -100; i > -67; i+=3 )


int m = 0;
int n = 0;
for ( m = 10, n = 10; m < 20 && n > 2; m++, n-- )
    cout << " m " << m << " n " << n << endl;
cout << endl;

#include <iostream>
using namespace std;
void WhatIsHappening( int );
int main()
{
    WhatIsHappening (54321);
    cout << endl;
    system("PAUSE");
    return 1;
}
void WhatIsHappening ( int a )
{
    if ( a/10 )
        WhatIsHappening (a/10);
    cout << ( a%10 ) << "*";



}#include <iostream>
using namespace std;
void WhatIsHappening( int );
int main()
{
    WhatIsHappening (54321);
    cout << endl;
    system("PAUSE");
    return 1;
}
void WhatIsHappening ( int a )
{
    if ( a/10 )
        WhatIsHappening (a/10);
    cout << ( a%10 ) << "*";
}
5*4*3*2*1*
sh: 1: PAUSE: not found

///////

Question 1 (12.25 points) 
Saved
Which for loop will iterate exactly 11 times?

Question 1 options:
/* Quiz 0 
January 13, 2023
*/

// Question 1 (12.25 points) 
// Which for loop will iterate exactly 11 times?
for ( i=54; i == 74; i+=2 )


for ( i=100; i<=110; ++i )


for ( i=100; i>80; i-=2 )


for ( i= -100; i > -67; i+=3 )
// Answer: for ( i=100; i<=110; ++i )

Question 2 (12.25 points) S
Saved
Determine the output. Assume all code is compliable. (Make sure to write the exact answer, Case sensitive.)

// Question 2 (12.25 points) 
// Determine the output. Assume all code is compliable. (Make sure to write the exact answer, Case sensitive.)
int a = 5;
int b = 8;
int c = 7;
@@ -96,18 +28,17 @@ else if ( b == 8 )
    cout << "Soundgarden" << endl;
else
    cout << "Green Day" << endl;
Question 2 options:
Red Hot Chili Peppers
Question 3 (12.25 points) 
Saved
Determine the output. Assume all code is compliable. (Make sure to add necessary space(s) and new line(s) in your answer)
// Answer: Red Hot Chili Peppers


//Question 3 (12.25 points) 
//Determine the output. Assume all code is compliable. (Make sure to add necessary space(s) and new line(s) in your answer)
int m = 0;
int n = 0;
for ( m = 10, n = 10; m < 20 && n > 2; m++, n-- )
    cout << " m " << m << " n " << n << endl;
cout << endl;
Question 3 options:
/*Answer:
m 10 n 10
m 11 n 9
m 12 n 8
@@ -116,10 +47,11 @@ m 14 n 6
m 15 n 5
m 16 n 4
m 17 n 3
Question 4 (12.25 points) 
Saved
Determine the output. Assume all code is compilable.
*/


// Question 4 (12.25 points) 
// Determine the output. Assume all code is compilable.
#include <iostream>
using namespace std;
void WhatIsHappening( int );
@@ -136,35 +68,32 @@ void WhatIsHappening ( int a )
        WhatIsHappening (a/10);
    cout << ( a%10 ) << "*";
}
Question 4 options:
/*Answer:
5*4*3*2*1*

\n
PAUSE
Question 5 (12.25 points) 
Saved
One kibibyte equals to how many bits? (Typically used for computer memory and storage, kibibyte (KiB) is 1,024 bytes (IEC standard). One gibibyte(1 GiB) is 1,024 MiB)
*/

Just write the exact number without any suffixes or  prefixes.

Question 5 options:
1,024
Question 6 (12.25 points) 
Saved
What will be the output of this code?
/// Question 5 (12.25 points) 
One kibibyte equals to how many bits? (Typically used for computer memory and storage, kibibyte (KiB) is 1,024 bytes (IEC standard). One gibibyte(1 GiB) is 1,024 MiB)
// Answer: 8192


// Question 6 (12.25 points) 
// What will be the output of this code?
#include <iostream>
int main()
{
    int a = 2147483647;
    a++;
    std::cout << a;
}
Question 6 options:
-2147483648
Question 7 (12.25 points) 
Saved
What will be the output of this code?
// Answer: 2147483648


// Question 7 (12.25 points) 
// What will be the output of this code?
#include <iostream>
int x = 10;
int main()
@@ -176,16 +105,14 @@ int main()
        std::cout << x << ", ";
    }
    std::cout << x;
Question 7 options:
0, 1, 2, 100
Question 8 (12.25 points) 
Saved
The following code has an error. How to correct it?
// Answer: 0, 1, 2, 100


// Question 8 (12.25 points) 
// The following code has an error. How to correct it?
#include <iostream>
int main() {
    cout << "Hello, World!" ;
    return 0;
}

Test to pull and push since set to private
// Answer: using namespace std;


<br>
<hr>
<br>

/* Quiz 0 
January 13, 2023
*/

// Question 1 (12.25 points) 
// Which for loop will iterate exactly 11 times?
for ( i=54; i == 74; i+=2 )
for ( i=100; i<=110; ++i )
for ( i=100; i>80; i-=2 )
for ( i= -100; i > -67; i+=3 )
// Answer: for ( i=100; i<=110; ++i )


// Question 2 (12.25 points) 
// Determine the output. Assume all code is compliable. (Make sure to write the exact answer, Case sensitive.)
int a = 5;
int b = 8;
int c = 7;
    cout << "Soundgarden" << endl;
else
    cout << "Green Day" << endl;
// Answer: Red Hot Chili Peppers


//Question 3 (12.25 points) 
//Determine the output. Assume all code is compliable. (Make sure to add necessary space(s) and new line(s) in your answer)
int m = 0;
int n = 0;
for ( m = 10, n = 10; m < 20 && n > 2; m++, n-- )
    cout << " m " << m << " n " << n << endl;
cout << endl;
/*Answer:
m 10 n 10
m 11 n 9
m 12 n 8
m 15 n 5
m 16 n 4
m 17 n 3
*/


// Question 4 (12.25 points) 
// Determine the output. Assume all code is compilable.
#include <iostream>
using namespace std;
void WhatIsHappening( int );
        WhatIsHappening (a/10);
    cout << ( a%10 ) << "*";
}
/*Answer:
5*4*3*2*1*
\n
PAUSE
*/


/// Question 5 (12.25 points) 
One kibibyte equals to how many bits? (Typically used for computer memory and storage, kibibyte (KiB) is 1,024 bytes (IEC standard). One gibibyte(1 GiB) is 1,024 MiB)
// Answer: 8192


// Question 6 (12.25 points) 
// What will be the output of this code?
#include <iostream>
int main()
{
    int a = 2147483647;
    a++;
    std::cout << a;
}
// Answer: 2147483648


// Question 7 (12.25 points) 
// What will be the output of this code?
#include <iostream>
int x = 10;
int main()
        std::cout << x << ", ";
    }
    std::cout << x;
// Answer: 0, 1, 2, 100


// Question 8 (12.25 points) 
// The following code has an error. How to correct it?
#include <iostream>
int main() {
    cout << "Hello, World!" ;
    return 0;
}
// Answer: using namespace std;