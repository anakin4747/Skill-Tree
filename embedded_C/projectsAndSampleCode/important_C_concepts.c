//-------------------------------------------------------------//
// Some notes I took about generally more advanced C concepts
//
// Not an actual C file
//
// I just used this as a tool to re-enforce learning
//
// I learnt this from another C tutorial on youtube but cannot
// remember where
//
//-------------------------------------------------------------//


void *p; // p is a pointer without a type

// This is beneficial for abstraction

short *short_pointer;
int *int_pointer;

short_pointer = p;
int_pointer = p;

a = *short_pointer; // a pointer of type short reads 2 Bytes
b = *int_pointer; // a pointer of type int reads 4 Bytes

// if you want to move along in memory you can increment your pointers
// the type of pointer dicates the number of bytes you increment by

short_pointer++;    // adds 2 bytes to pointer, 2 bytes = sizeof(short)
int_pointer++;      // adds 4 bytes to pointer, 4 bytes = sizeof(int)

// you cannot perform arithmetic on void pointer but you can typecast it to increment by that types size

//-------------------------------------------------------------//
// notes on malloc

// sizeof is not a function. 
printf("%d", 10);   // think about how you pass variables/values to functions

// sizeof is a part of the C language 
sizeof (float)x;    // consider the type in the brackets as a cast not a variable



double *a;

a = malloc(sizeof(float));  // how it is commonly written

a = malloc((sizeof *a) * 10); // a better way of writing it
// This says give me the sizeof whatever a is pointing at
// This is a foolproof way incase the type of a changes

// if we mistakenly write the wrong type the correct sizeof data will not be allocated

//-------------------------------------------------------------//

// Pointers and arrays are the same thing

a = x[3];

// Is equivalent to:

uint8 *p;   // 8 bit unsigned point (range 0-255)
p = x;      // copy x to the pointer
x = p + (sizeof *x) * 3;    // the address plus 8 bits (the sizeof uint8) * 3
a = *x;     // copy that value over to a

//-------------------------------------------------------------//

// Using pointers as counters

// how you would normally set an array to 0
uint i;
for(i = 0; i < 10; i++)
    p[i] = 0;   // behind the scenes what the computer is doing is p + (sizeof *p) * i

// how you could also do it using pointers
void *end;
for(end = &p[10]; p != end; p++)
    *p = 0;
// this code could actually run faster since it doesnt need to do that multiplication behind the scenes

//-------------------------------------------------------------//

// Structs are just a sizeof and a bunch of offset types

typedef struct{
    uint type;      // offset at zero
    char name[32];  
    float size;
}MyStructType;

offset = (uint)(&(((MyStructType *)NULL)->size));

/*  

    This line returns the offset of size
    The line says start at the offset zero (NULL)
    cast it to a pointer of type MyStructType
    from there go to size (->size)
    once at size you get the address with &
    then cast it to an unsigned int
    and save it to offset
    
                                                    */

//-------------------------------------------------------------//


// The first Member of a Struct has offset zero

typedef enum{
    MST_INT,
    MST_FLOAT,
    MST_COUNT
}MyStructType;

typedef struct{
    char name[32];       // <--------------------------------------
    MyStructType type;   //                                        |
}MyHeader;               // <--------------------------------------|
                         //                                        |
typedef struct{          //                                        |
    MyHeader head;       // <--------------------------------------| 
    int value;           //                                        |
}MyStructInt;            //                                        |
                         //                                        |
typedef struct{          //                                        |
    MyHeader head;       // <--------------------------------------|
    float value;         //                                        |
}MyStructFloat;          //                                        |
                         //                                        |
// a pointer to MyStructInt or MyStructFloat is also a pointer to -
// You just have to cast it accordingly to access them correctly

void my_set_value(MyHeader *h, double value){
    if(h->type == MST_INT)
        ((MyStructInt *)h)->value = (int)value;
    else
        ((MyStructFloat *)h)->value = (float)value;
}

/*  This example shows a way of using inheritance 
    Since the first item in either MyStructInt or MyStructFloat 
    is always a header and the pointer points to the first item 
    in the struct you can figure out what type of struct it is 
    and then cast it appropriately.
    
    In the above example we have a function that checks the type 
    of h. It does this by first considering it as a MyHeader 
    pointer so that you can access the offset of type correctly.
    Once we know the type we can cast h to the correct type of 
    pointer to save the correctly sized data in the correctly
    sized offset in the struct.                                 */

//-------------------------------------------------------------//

// Alignment makes things more complicated but with the right knowledge it can be utilized

typedef struct{
    uint8 a;    // 1 byte
    uint32 b;   // 4 bytes
}MyStructType;

/*  Taking the sizeof of this struct would make one suspect it will be
    5 bytes but in reality memory has a inclination to be aligned by 
    common quantities so this would actually take up 8 bytes. The space
    between a and b is filled with padding to make sure things are aligned
    
    padding
     |||
    a***bbbb

    4 bytes is 32 bits incase you forgot
    
    What you can do to not let any space go to waste is to use the padded space   */

typedef struct{
    uint8 a;
    uint8 x;
    uint8 y;
    uint8 z;
    uint32 b;
}MyStructType;

/*  Now there is no padding only data, which looks like

    axyzbbbb
            */
    
//-------------------------------------------------------------//

// Memory in hardware:

// 4k Blocks

// |------------------|------------------|------------------|------------------|------------------|

// Each block had read/write/execute flags

// Block addresses are virualized 

// Crashes only happen when you step outside of a block that isnt yours

// A nasty bug that can is very hard to catch is:

a[1] = 0; // when you really meant a[0] = 0;

// This is a nasty bug because you are overwriting the wrong value which you are totally allowed
// to do because it is in the same space within you block of code

// An even worse example of this is as follows

uint a[10], i;      // These ints are allocated all one after the other in memory

for(i = 0; i < 11; i++)  // having 11 here is the bug, this means a[10] will be set = 0
    a[i] = 0;            // and since i is right after the array in memory you will rewrite i = 0
                         // thus making the for loop an endless loop

//-------------------------------------------------------------//

// Memory is SLOW

// This may be faster:

a = a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a * a;
b = b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b;
c = c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c * c;
d = d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d * d;

// Then this:

b = *a;

/*
Rough idea of memory latency

-register 0 cycles
-Level 1 cashe 2-3 cycles
-Level 2 cashe 10-15 cycles
-Main memory 50 cycles

This has gotten worse over the last 30 years and the trend is likely to continue
*/

//-------------------------------------------------------------//

// Memory coherence is No1 optimization

typedef struct{
    void *data;
    void *next;
}LinkedList;

// Linked lists are also always consuming twice the amount of memory since you need
// a pointer to the next item instead of knowing the next item is adjacent like in arrays

// Not memory coherent

for(l = list; l != NULL; l = l->next)
    do_something(l);

    // With linked lists you bounce all over memory to find the pieces that are together
    // This means your memory is not close together causing delays when accessing related memory

// Memory coherent

for(i = 0; i < array_length; i++)
    do_something(&array[i]);

    // Arrays have contiguous memory so accessing each item is fast as they are close to each other

// Realloc rarely when adding

if(array_length == array_allocated){
    array_allocated += 16;
    array = realloc(array, (sizeof *array) * array_allocated);
}
array[array_length] = value;
array_length++;

// remove

array[i] = array[--array_length];

// Backwards remove is faster than linked lists

for(i = array_length; i !=0;){
    i--;
    if(array[i] == the_one_you_want_to_remove)
        break;
    last = save;
    save = array[i];
    array[i] = last;
}

//-------------------------------------------------------------//

// Bad programming:

typedef struct{
    float width;
    float length;
    float area;
}MyPlane;

// This is bad because you can calculate area from width and length
// This means if you change either of those variables you always need
// to update area as well or else your data will be inaccurate
// You are also storing extra data which doesnt need to be taking up memory

// It would be better to just calculate area
// remember that math is insanely fast so calculating area could get you
// the data faster than accessing area in memory

// The only time it would be worth it is if computing area is massively slow
// In that situation it would be better to do as follows:

typedef void MyPlain;

void my_plain_width_set(MyPlain *plain, float width);
float my_plain_width_get(MyPlain *plain);
void my_plain_length_set(MyPlain *plain, float length);
float my_plain_length_get(MyPlain *plain);
float my_plain_area_get(MyPlain *plain);

// With this it is gauranteed that you will have consistant data
// You make functions which will always update all dependant data
// ensuring data consistency 

//-------------------------------------------------------------//

// Fewer allocations means better packing
    // This code is to store an array and its length
typedef struct{
    uint length;
    uint8 *data;
}MyArrayOfBytes;

MyArrayOfBytes *array;
array = malloc(sizeof *array);  // Allocating the array
array->length = length;
array->data = malloc((sizeof *array->data) * array->length);  // Allocating the data of the array

for(i = 0; i < length; i++)
    array->data[i] = 0;

// Since there are 2 malloc calls this means they have 2 blocks of memory that may not 
// necessarily be close to each other this could be slow

// Better:

typedef struct{
    uint length;
    uint8 data[1];
}MyArrayOfBytes;

MyArrayOfBytes *array;
array = malloc((sizeof *array) + sizeof(uint8) * (length - 1)); // Only 1 malloc call means more tightly packed data == faster
array->length = length;

for(i = 0; i < length; i++)
    array->data[i] = 0;

//-------------------------------------------------------------//

typedef struct{
    uint64 a;
    float b;
}MyStructA;

typedef struct{
    float x;
    uint8 y;
    double z;
}MyStructB;

MyStructA *a;
MyStructB *b;

a = malloc(sizeof(MyStructA) + sizeof(MyStructB));
b = (MyStructB *)&a[1]; // This line forces b to be adjacent to a therefore making it quicker to access both pieces of memory

// This line is saying at the array element adjacent to a, a[1], take the address of that, &a[1], and cast it to a 
// MyStructB pointer and assign it to b 

// This makes sure b is right after a

// This can be dangerous if your structs are not aligned correctly so be smart when trying something like this

//-------------------------------------------------------------//

// Stride

void rgb_color_count(uint8 *rgb_pixels, uint pixel_count); // This can do RGB buffers only

void rgb_color_count(uint8 *rgb_pixels, uint pixel_count, uint stride); // This can do any buffer
// Adding stride tells the function how long the struct is which means you can use it for code with larger structs
// in this case rgba which has an added variable which describes the opacity of a pixel

// RGBA

rgb_color_correct(rgba, pixel_count, sizeof(uint8) * 4); // Here you can pass items which are 4 values for RGBA or 3 for RGB

// Structs

typedef struct{
    float size;
    uint8 color[3];
    char name[16];
}Thing;

Thing t[10];

rgb_color_correct(t[0].color, 10, sizeof *t);

// The stride variable makes that function a lot more versatile

//-------------------------------------------------------------//

// Architecture

// Find your primitives!

// When you are creating an application you have to first conisder the architecture of your design
// Start off with finding the primitive objects that you are basing the program on 

// The smaller your primitive the easier your application is gunna be to write

//-------------------------------------------------------------//

// Most UI libraries work like this

void button_func(void *user){
    printf("Button Press");
}

void init_ui(){
    element = element_create();
    element_button_add(element, x, y, "hello", button_func, NULL);
    element_surface_add(element, x, y, size);
}

main_loop(){
    element_run(element);
}

// What if we want to move the button?

void button_func(void *user){
    printf("Button Press");
}

void init_ui(){
    element = element_create();
    id = element_button_add(element, x, y, "hello", button_func, NULL);
    element_surface_add(element, x, y, size);
}

main_loop(){
    element_move(element, id, sin(time), cos(time));
    element_run(element);
}

// The added ID and extra complexity makes this code a lot hard to work with

// Why cant we just do this

main_loop(){
    if(draw_button_add(id1, sin(time), cos(time), "Hello"))
        printf("button press");
    draw_surface(id2, x, y, size);
}

// the id is a pointer and can be pointing to anything
