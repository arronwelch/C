/* Review Queations 4.12 */

// Suppose that you would rather use parentheses than braces in your programs. How well
// would the following work?
// #define ( {
// #defien ) }

// Solution:

// The substitutions would take place. Unfortunately, the preprocessor cannot discriminate
// between those parentheses that should be replaced with braces and those that should
// not, Therefore,

// #define ( {
// #define ) }
// int main(void)
// (
//		printf("Hello, O Great One!\n");
// )

// becomes

// int main{void}
// {
//		printf{"Hello, O Great One!\n"};
// }


